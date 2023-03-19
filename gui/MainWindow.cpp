/*!
 * \file MainWindow.cpp
 * \brief The MainWindow class represents the main window of the software
 * \author Simon Buchholz
 * \copyright Copyright (c) 2023, Simon Buchholz
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include <QFileDialog>
#include <QDateTime>
#include <QDesktopServices>
#include <QTimer>
#include <QTabBar>
#include <QScrollBar>
#include <QMessageBox>
#include <QClipboard>
#include <QTextDocumentFragment>

MainWindow::MainWindow(QWidget *pParent)
    : QMainWindow(pParent)
    , mUi(new Ui::MainWindow)
    , mAboutDialog(this)
    , mStatusLabel("Workspace: none")
    , mMarlinVersionLabel(QString("Marlin Version: v%0").arg(MARLIN_VERSION))
{
    mUi->setupUi(this);

    setWindowTitle(QString("iMC - iLOOP Marlin Configurator v%0").arg(SW_VERSION));

    // Initialize dock widgets
    constexpr auto dockHeight = 200;

    tabifyDockWidget(mUi->uConsoleDock, mUi->uCompilerOutputsDock);
    tabifyDockWidget(mUi->uCompilerOutputsDock, mUi->uCodePreviewDock);
    resizeDocks(QList{static_cast<QDockWidget*>(mUi->uConsoleDock),
                      static_cast<QDockWidget*>(mUi->uCompilerOutputsDock),
                      static_cast<QDockWidget*>(mUi->uCodePreviewDock)},
                QList{dockHeight, dockHeight, dockHeight}, Qt::Vertical);

    // Add dock widget view actions to menu
    mUi->menuView->addAction(mUi->uNavigationDock->toggleViewAction());
    mUi->menuView->addAction(mUi->uConsoleDock->toggleViewAction());
    mUi->menuView->addAction(mUi->uCompilerOutputsDock->toggleViewAction());
    mUi->menuView->addAction(mUi->uCodePreviewDock->toggleViewAction());

    mUi->menuView->actions().at(2)->setShortcut(QKeySequence("Alt+N"));
    mUi->menuView->actions().at(3)->setShortcut(QKeySequence("Alt+O"));
    mUi->menuView->actions().at(4)->setShortcut(QKeySequence("Alt+C"));
    mUi->menuView->actions().at(5)->setShortcut(QKeySequence("Alt+P"));

    for (auto&& page : findChildren<AbstractPage*>())
    {
        mConfigPages.push_back(page);
        page->Init();
    }

    // Set console tab as current
    auto&& tabBar = this->findChild<QTabBar*>();
    if (nullptr != tabBar)
    {
        tabBar->setCurrentIndex(0);
    }

    // Initialize status bar
    mUi->statusBar->setSizeGripEnabled(false);
    mUi->statusBar->addWidget(&mStatusLabel);
    mUi->statusBar->addPermanentWidget(&mMarlinVersionLabel);

    uint8_t nextId = 0;
    for (auto& button : mUi->buttonGroup->buttons())
    {
        mUi->buttonGroup->setId(button, nextId++);
    }

    ConnectGuiSignalsAndSlots();

    mUi->stackedWidget->setCurrentIndex(0);
    UpdateActiveTabButtonColor();

    for (auto&& page : mConfigPages)
    {
        page->setEnabled(false);
    }

    OnUpdatePreview(QStringList()); // Set to placeholder text

    mUi->uCancelButton->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete mUi;
}

void MainWindow::ConnectGuiSignalsAndSlots()
{
    QObject::connect(mUi->stackedWidget, &QStackedWidget::currentChanged, this, [&]()
    {
        UpdateActiveTabButtonColor();

         mUi->uResetCurrentPageAction->setEnabled(mUi->stackedWidget->currentIndex() > 0);

        // Update code preview on tab change
        auto&& page = mUi->stackedWidget->currentWidget()->findChild<AbstractPage*>();
        if (nullptr != page)
        {
            mUi->uPreviewEdit->verticalScrollBar()->setSliderPosition(0);
            page->OnUpdatePreview();
        }
        else
        {
            OnUpdatePreview(QStringList()); // Set to placeholder text
        }
    });

    QObject::connect(mUi->uCloseAction, &QAction::triggered, this, &QMainWindow::close);
    QObject::connect(mUi->uAboutAction, &QAction::triggered, &mAboutDialog, &AboutDialog::show);
    QObject::connect(mUi->uCloseWorkspaceAction, &QAction::triggered, this, &MainWindow::OnCloseWorkspace);
    QObject::connect(mUi->uCloseWorkspaceButton, &QPushButton::pressed, this, &MainWindow::OnCloseWorkspace);

    QObject::connect(mUi->uWelcomePage, &WelcomePage::OpenWorkspaceSignal, this, &MainWindow::OnOpenWorkspace);

    // Connects for code preview
    for (auto&& page : findChildren<AbstractPage*>())
    {
        QObject::connect(page, &AbstractPage::UpdatePreviewSignal, this, &MainWindow::OnUpdatePreview);
    }

    QObject::connect(mUi->uSaveWorkspaceAction, &QAction::triggered, this, &MainWindow::SaveProjectSignal);
    QObject::connect(mUi->uSaveWorkspaceButton, &QPushButton::pressed, this, &MainWindow::SaveProjectSignal);
    QObject::connect(mUi->uOpenWorkspaceAction, &QAction::triggered, this, &MainWindow::OnOpenWorkspace);
    QObject::connect(mUi->uOpenWorkspaceButton, &QPushButton::pressed, this, &MainWindow::OnOpenWorkspace);
    QObject::connect(mUi->uResetConfigurationAction, &QAction::triggered, this, &MainWindow::OnResetConfiguration);
    QObject::connect(mUi->uResetConfigurationButton, &QPushButton::pressed, this, &MainWindow::OnResetConfiguration);
    QObject::connect(mUi->uResetCurrentPageAction, &QAction::triggered, this, &MainWindow::OnResetCurrentPage);

    QObject::connect(mUi->uResetViewportAction, &QAction::triggered, this, &MainWindow::OnResetViewport);

    QObject::connect(mUi->uActionConfigure, &QAction::triggered, this, &MainWindow::ConfigureSignal);

    QObject::connect(mUi->uActionBuild, &QAction::triggered, this, [&](){
        mUi->uCompilerOutputsDock->raise();

        emit BuildMarlinSignal();
    });

    QObject::connect(mUi->uActionRebuild, &QAction::triggered, this, [&](){
        mUi->uCompilerOutputsDock->raise();

        emit RebuildMarlinSignal();
    });

    QObject::connect(mUi->uActionClean, &QAction::triggered, this, [&](){
        mUi->uCompilerOutputsDock->raise();

        emit CleanSignal();
    });

    QObject::connect(mUi->uActionUpload, &QAction::triggered, this, [&](){
        mUi->uCompilerOutputsDock->raise();

        emit UploadSignal();
    });

    QObject::connect(mUi->uConfigureButton, &QPushButton::pressed, this, &MainWindow::ConfigureSignal);

    QObject::connect(mUi->uBuildButton, &QPushButton::pressed, this, [&](){
        mUi->uCompilerOutputsDock->raise();

        emit BuildMarlinSignal();
    });

    QObject::connect(mUi->uRebuildButton, &QPushButton::pressed, this, [&](){
        mUi->uCompilerOutputsDock->raise();

        emit RebuildMarlinSignal();
    });

    QObject::connect(mUi->uCleanButton, &QPushButton::pressed, this, [&](){
        mUi->uCompilerOutputsDock->raise();

        emit CleanSignal();
    });

    QObject::connect(mUi->uUploadButton, &QPushButton::pressed, this, [&](){
        mUi->uCompilerOutputsDock->raise();

        emit UploadSignal();
    });

    QObject::connect(mUi->uCancelButton, &QPushButton::pressed, this, [&](){
        mBuildCanceled = true;
    });

    QObject::connect(mUi->uClearGeneralOutputsButton, &QPushButton::pressed, mUi->uLogConsole, &QTextBrowser::clear);
    QObject::connect(mUi->uClearCompilerOutputsButton, &QPushButton::pressed, mUi->uCompilerConsole, &QTextBrowser::clear);
    QObject::connect(mUi->uCopyAllCodePreviewButton, &QPushButton::pressed, this, [&](){
        QApplication::clipboard()->setText(mUi->uPreviewEdit->toPlainText());
    });
    QObject::connect(mUi->uCopySelectionCodePreviewButton, &QPushButton::pressed, this, [&](){
        QApplication::clipboard()->setText(mUi->uPreviewEdit->textCursor().selection().toPlainText());
    });

    QObject::connect(mUi->uActionOpenMarlinHomepage, &QAction::triggered, this, [&](){
        QDesktopServices::openUrl(QUrl("https://marlinfw.org/"));
    });

    QObject::connect(mUi->uActionOpenAutoBuildMarlin, &QAction::triggered, this, [&](){
        QDesktopServices::openUrl(QUrl("https://marlinfw.org/docs/basics/auto_build_marlin.html"));
    });

    QObject::connect(mUi->uActionOpenMarlinConfiguration, &QAction::triggered, this, [&](){
        QDesktopServices::openUrl(QUrl("https://marlinfw.org/docs/configuration/configuration.html"));
    });

    QObject::connect(mUi->uActionOpenGitHub, &QAction::triggered, this, [&](){
        QDesktopServices::openUrl(QUrl("https://github.com/SimonBuxx/iloop-marlin-configurator/"));
    });

    QObject::connect(mUi->uActionOpenErigEv, &QAction::triggered, this, [&](){
        QDesktopServices::openUrl(QUrl("https://er-ig.de/"));
    });

    QObject::connect(mUi->uWelcomeTabButton, &QPushButton::clicked, this, [&](){
        mUi->stackedWidget->setCurrentIndex(0);
    });

    QObject::connect(mUi->uFirmwareTabButton, &QPushButton::clicked, this, [&](){
        mUi->stackedWidget->setCurrentIndex(1);
    });

    QObject::connect(mUi->uHardwareTabButton, &QPushButton::clicked, this, [&](){
        mUi->stackedWidget->setCurrentIndex(2);
    });

    QObject::connect(mUi->uExtruderTabButton, &QPushButton::clicked, this, [&](){
        mUi->stackedWidget->setCurrentIndex(3);
    });

    QObject::connect(mUi->uPowerSupplyButton, &QPushButton::clicked, this, [&](){
        mUi->stackedWidget->setCurrentIndex(4);
    });

    QObject::connect(mUi->uThermalSettingsButton, &QPushButton::clicked, this, [&](){
        mUi->stackedWidget->setCurrentIndex(5);
    });

    QObject::connect(mUi->uKinematicsTabButton, &QPushButton::clicked, this, [&](){
        mUi->stackedWidget->setCurrentIndex(6);
    });

    QObject::connect(mUi->uEndstopsTabButton, &QPushButton::clicked, this, [&](){
        mUi->stackedWidget->setCurrentIndex(7);
    });

    QObject::connect(mUi->uMovementTabButton, &QPushButton::clicked, this, [&](){
        mUi->stackedWidget->setCurrentIndex(8);
    });

    QObject::connect(mUi->uZProbeOptionsTabButton, &QPushButton::clicked, this, [&](){
        mUi->stackedWidget->setCurrentIndex(9);
    });

    QObject::connect(mUi->uStepperDriversTabButton, &QPushButton::clicked, this, [&](){
        mUi->stackedWidget->setCurrentIndex(10);
    });

    QObject::connect(mUi->uHomingAndBoundsTabButton, &QPushButton::clicked, this, [&](){
        mUi->stackedWidget->setCurrentIndex(11);
    });

    QObject::connect(mUi->uFilamentRunoutSensorTabButton, &QPushButton::clicked, this, [&](){
        mUi->stackedWidget->setCurrentIndex(12);
    });

    QObject::connect(mUi->uBedLevelingTabButton, &QPushButton::clicked, this, [&](){
        mUi->stackedWidget->setCurrentIndex(13);
    });

    QObject::connect(mUi->uHomingOptionsTabButton, &QPushButton::clicked, this, [&](){
        mUi->stackedWidget->setCurrentIndex(14);
    });

    QObject::connect(mUi->uAdditionalFeaturesTabButton, &QPushButton::clicked, this, [&](){
        mUi->stackedWidget->setCurrentIndex(15);
    });

    QObject::connect(mUi->uUserInterfaceLanguageTabButton, &QPushButton::clicked, this, [&](){
        mUi->stackedWidget->setCurrentIndex(16);
    });

    QObject::connect(mUi->uSDCardTabButton, &QPushButton::clicked, this, [&](){
        mUi->stackedWidget->setCurrentIndex(17);
    });

    QObject::connect(mUi->uLCDMenuItemsTabButton, &QPushButton::clicked, this, [&](){
        mUi->stackedWidget->setCurrentIndex(18);
    });

    QObject::connect(mUi->uEncoderTabButton, &QPushButton::clicked, this, [&](){
        mUi->stackedWidget->setCurrentIndex(19);
    });

    QObject::connect(mUi->uSpeakerTabButton, &QPushButton::clicked, this, [&](){
        mUi->stackedWidget->setCurrentIndex(20);
    });

    QObject::connect(mUi->uLCDControllerTabButton, &QPushButton::clicked, this, [&](){
        mUi->stackedWidget->setCurrentIndex(21);
    });

    QObject::connect(mUi->uExtraFeaturesTabButton, &QPushButton::clicked, this, [&](){
        mUi->stackedWidget->setCurrentIndex(22);
    });
}

void MainWindow::UpdateActiveTabButtonColor()
{
    if (mLastCheckedButton >= 0)
    {
        Q_ASSERT(nullptr != mUi->buttonGroup->button(mLastCheckedButton));

        auto icon = mUi->buttonGroup->button(mLastCheckedButton)->icon();
        auto img = QImage(icon.pixmap(20, 20).toImage());
        img.invertPixels();
        mUi->buttonGroup->button(mLastCheckedButton)->setIcon(QIcon(QPixmap::fromImage(img)));
    }

    if (mUi->buttonGroup->checkedId() >= 0)
    {
        Q_ASSERT(nullptr != mUi->buttonGroup->checkedButton());

        auto icon = mUi->buttonGroup->checkedButton()->icon();
        auto img = QImage(icon.pixmap(20, 20).toImage());
        img.invertPixels();
        mUi->buttonGroup->checkedButton()->setIcon(QIcon(QPixmap::fromImage(img)));
    }

    mLastCheckedButton = mUi->buttonGroup->checkedId();
}

void MainWindow::OnUpdatePreview(const QStringList& pPreviewCode)
{
    const auto& val = mUi->uPreviewEdit->verticalScrollBar()->value();
    mUi->uPreviewEdit->setPlainText(pPreviewCode.join('\n'));
    mUi->uPreviewEdit->verticalScrollBar()->setValue(val);

    if (pPreviewCode.empty())
    {
        mUi->uPreviewEdit->setStyleSheet("QTextEdit {font-family: \"Source Code Pro\";selection-background-color: rgb(63, 65, 77);color: rgb(100, 100, 100);}");
    }
    else
    {
        mUi->uPreviewEdit->setStyleSheet("QTextEdit {font-family: \"Source Code Pro\";selection-background-color: rgb(63, 65, 77);color: white;}");
    }
}

QString MainWindow::GetEnvironment() const
{
    return mUi->uHardwarePage->GetEnvironment();
}

void MainWindow::ActivateCancelButton()
{
    mUi->uConfigureButton->setEnabled(false);
    mUi->uBuildButton->setEnabled(false);
    mUi->uCleanButton->setEnabled(false);
    mUi->uUploadButton->setEnabled(false);
    mUi->uRebuildButton->setEnabled(false);

    mUi->uActionConfigure->setEnabled(false);
    mUi->uActionBuild->setEnabled(false);
    mUi->uActionRebuild->setEnabled(false);
    mUi->uActionClean->setEnabled(false);
    mUi->uActionUpload->setEnabled(false);

    mUi->uOpenWorkspaceAction->setEnabled(false);
    mUi->uSaveWorkspaceAction->setEnabled(false);
    mUi->uCloseWorkspaceAction->setEnabled(false);
    mUi->uResetConfigurationAction->setEnabled(false);

    mUi->uOpenWorkspaceButton->setEnabled(false);
    mUi->uSaveWorkspaceButton->setEnabled(false);
    mUi->uCloseWorkspaceButton->setEnabled(false);
    mUi->uResetConfigurationButton->setEnabled(false);

    mUi->uCancelButton->setVisible(true);
    mBuildCanceled = false;
}

void MainWindow::DeactivateCancelButton()
{
    // Note: Re-enabling here is only okay as long as it is ensured that all buttons should be enabled after cancel
    mUi->uConfigureButton->setEnabled(true);
    mUi->uBuildButton->setEnabled(true);
    mUi->uCleanButton->setEnabled(true);
    mUi->uUploadButton->setEnabled(true);
    mUi->uRebuildButton->setEnabled(true);

    mUi->uActionConfigure->setEnabled(true);
    mUi->uActionBuild->setEnabled(true);
    mUi->uActionRebuild->setEnabled(true);
    mUi->uActionClean->setEnabled(true);
    mUi->uActionUpload->setEnabled(true);

    mUi->uOpenWorkspaceAction->setEnabled(true);
    mUi->uSaveWorkspaceAction->setEnabled(true);
    mUi->uCloseWorkspaceAction->setEnabled(true);
    mUi->uResetConfigurationAction->setEnabled(true);

    mUi->uOpenWorkspaceButton->setEnabled(true);
    mUi->uSaveWorkspaceButton->setEnabled(true);
    mUi->uCloseWorkspaceButton->setEnabled(true);
    mUi->uResetConfigurationButton->setEnabled(true);

    mUi->uCancelButton->setVisible(false);
    mBuildCanceled = false;
}

bool MainWindow::IsBuildCanceled() const
{
    return mBuildCanceled;
}

void MainWindow::ResetValues()
{
    for (auto&& page : mConfigPages)
    {
        page->ResetValues();
    }
}

void MainWindow::JumpToFirstConfigTab()
{
    mUi->uFirmwareTabButton->click();
}

void MainWindow::OnCloseWorkspace()
{
    ResetValues();

    mUi->uWelcomeTabButton->click();
    SetWorkspace(std::nullopt);

    mUi->uSaveWorkspaceAction->setEnabled(false);
    mUi->uActionConfigure->setEnabled(false);
    mUi->uActionBuild->setEnabled(false);
    mUi->uActionRebuild->setEnabled(false);
    mUi->uActionClean->setEnabled(false);
    mUi->uActionUpload->setEnabled(false);
    mUi->uCloseWorkspaceAction->setEnabled(false);

    mUi->uSaveWorkspaceButton->setEnabled(false);
    mUi->uConfigureButton->setEnabled(false);
    mUi->uBuildButton->setEnabled(false);
    mUi->uRebuildButton->setEnabled(false);
    mUi->uCleanButton->setEnabled(false);
    mUi->uUploadButton->setEnabled(false);
    mUi->uCloseWorkspaceButton->setEnabled(false);

    for (auto&& page : mConfigPages)
    {
        page->setEnabled(false);
    }

    emit CloseWorkspaceSignal();
}

void MainWindow::OnOpenWorkspace()
{
    emit OpenWorkspaceSignal();
}

void MainWindow::OnWorkspaceOpened()
{
    mUi->uSaveWorkspaceAction->setEnabled(true);
    mUi->uActionConfigure->setEnabled(true);
    mUi->uActionBuild->setEnabled(true);
    mUi->uActionRebuild->setEnabled(true);
    mUi->uActionClean->setEnabled(true);
    mUi->uActionUpload->setEnabled(true);
    mUi->uCloseWorkspaceAction->setEnabled(true);

    mUi->uSaveWorkspaceButton->setEnabled(true);
    mUi->uConfigureButton->setEnabled(true);
    mUi->uBuildButton->setEnabled(true);
    mUi->uRebuildButton->setEnabled(true);
    mUi->uCleanButton->setEnabled(true);
    mUi->uUploadButton->setEnabled(true);
    mUi->uCloseWorkspaceButton->setEnabled(true);

    for (auto&& page : mConfigPages)
    {
        page->setEnabled(true);
    }
}

void MainWindow::OnResetConfiguration()
{
    QMessageBox msgBox;
    msgBox.setText("Do you really want to reset the workspace configuration?");
    msgBox.setInformativeText("Reset only affects the displayed values, the workspace files are not updated until explicitly saved.");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setIcon(QMessageBox::Question);
    if (msgBox.exec() == QMessageBox::No)
    {
        return;
    }

    ResetValues();
    Log("Workspace configuration resetted.", "rgb(249, 154, 0)");
}

void MainWindow::OnResetCurrentPage()
{
    QMessageBox msgBox;
    msgBox.setText("Do you really want to reset the current page configuration?");
    msgBox.setInformativeText("Reset only affects the displayed values, the workspace files are not updated until explicitly saved.");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setIcon(QMessageBox::Question);
    if (msgBox.exec() == QMessageBox::No)
    {
        return;
    }

    if (nullptr != dynamic_cast<AbstractPage*>(mUi->stackedWidget->currentWidget()->findChild<AbstractPage*>()))
    {
        auto&& page = static_cast<AbstractPage*>(mUi->stackedWidget->currentWidget()->findChild<AbstractPage*>());
        page->ResetValues();
        Log("Current page configuration resetted.", "rgb(249, 154, 0)");
    }
    else
    {
        Log("Could not reset the current page configuration.", "red");
    }
}

void MainWindow::OnResetViewport()
{
    removeDockWidget(mUi->uConsoleDock);
    removeDockWidget(mUi->uCompilerOutputsDock);
    removeDockWidget(mUi->uCodePreviewDock);
    removeDockWidget(mUi->uNavigationDock);

    addDockWidget(Qt::BottomDockWidgetArea, mUi->uConsoleDock);
    addDockWidget(Qt::BottomDockWidgetArea, mUi->uCompilerOutputsDock);
    addDockWidget(Qt::BottomDockWidgetArea, mUi->uCodePreviewDock);
    addDockWidget(Qt::LeftDockWidgetArea, mUi->uNavigationDock);

    constexpr auto dockHeight = 200;

    tabifyDockWidget(mUi->uConsoleDock, mUi->uCompilerOutputsDock);
    tabifyDockWidget(mUi->uCompilerOutputsDock, mUi->uCodePreviewDock);
    resizeDocks(QList{static_cast<QDockWidget*>(mUi->uConsoleDock),
                      static_cast<QDockWidget*>(mUi->uCompilerOutputsDock),
                      static_cast<QDockWidget*>(mUi->uCodePreviewDock)},
                QList{dockHeight, dockHeight, dockHeight}, Qt::Vertical);

    mUi->uCodePreviewDock->setVisible(true);
    mUi->uCompilerOutputsDock->setVisible(true);
    mUi->uConsoleDock->setVisible(true);
    mUi->uNavigationDock->setVisible(true);

    mUi->uConsoleDock->raise();
}

Configuration MainWindow::FetchConfiguration()
{
    Configuration config;

    for (auto&& page : mConfigPages)
    {
        page->FetchConfiguration(config);
    }

    return config;
}

void MainWindow::ReplaceTags(QStringList& pOutput)
{
    for (auto&& page : mConfigPages)
    {
        page->ReplaceTags(pOutput);
    }
}

void MainWindow::SetWorkspace(const std::optional<QString>& pName)
{
    mStatusLabel.setText(QString("Workspace: %0").arg(pName.value_or("none")));
    setWindowTitle(QString("%0iMC - iLOOP Marlin Configurator v%1").arg(pName.has_value() ? pName.value() + " - " : "", SW_VERSION));
}

bool MainWindow::LoadConfigurationFromJson(const QJsonObject& pJson)
{
    ResetValues();

    bool success = true;

    if (pJson.contains("firmware") && pJson["firmware"].isObject())
    {
        success &= mUi->uFirmwarePage->LoadFromJson(pJson["firmware"].toObject());
    }
    else
    {
        success = false;
    }

    if (pJson.contains("hardware") && pJson["hardware"].isObject())
    {
        success &= mUi->uHardwarePage->LoadFromJson(pJson["hardware"].toObject());
    }
    else
    {
        success = false;
    }

    if (pJson.contains("extruder") && pJson["extruder"].isObject())
    {
        success &= mUi->uExtruderPage->LoadFromJson(pJson["extruder"].toObject());
    }
    else
    {
        success = false;
    }

    if (pJson.contains("powerSupply") && pJson["powerSupply"].isObject())
    {
        success &= mUi->uPowerSupplyPage->LoadFromJson(pJson["powerSupply"].toObject());
    }
    else
    {
        success = false;
    }

    if (pJson.contains("thermalSettings") && pJson["thermalSettings"].isObject())
    {
        success &= mUi->uThermalSettingsPage->LoadFromJson(pJson["thermalSettings"].toObject());
    }
    else
    {
        success = false;
    }

    if (pJson.contains("endstops") && pJson["endstops"].isObject())
    {
        success &= mUi->uEndstopsPage->LoadFromJson(pJson["endstops"].toObject());
    }
    else
    {
        success = false;
    }

    if (pJson.contains("filamentRunoutSensor") && pJson["filamentRunoutSensor"].isObject())
    {
        success &= mUi->uFilamentRunoutSensorPage->LoadFromJson(pJson["filamentRunoutSensor"].toObject());
    }
    else
    {
        success = false;
    }

    if (pJson.contains("homingOptions") && pJson["homingOptions"].isObject())
    {
        success &= mUi->uHomingOptionsPage->LoadFromJson(pJson["homingOptions"].toObject());
    }
    else
    {
        success = false;
    }

    if (pJson.contains("userInterfaceLanguage") && pJson["userInterfaceLanguage"].isObject())
    {
        success &= mUi->uUserInterfaceLanguagePage->LoadFromJson(pJson["userInterfaceLanguage"].toObject());
    }
    else
    {
        success = false;
    }

    if (pJson.contains("sdCard") && pJson["sdCard"].isObject())
    {
        success &= mUi->uSDCardPage->LoadFromJson(pJson["sdCard"].toObject());
    }
    else
    {
        success = false;
    }

    if (pJson.contains("lcdMenuItems") && pJson["lcdMenuItems"].isObject())
    {
        success &= mUi->uLCDMenuItemsPage->LoadFromJson(pJson["lcdMenuItems"].toObject());
    }
    else
    {
        success = false;
    }

    if (pJson.contains("encoder") && pJson["encoder"].isObject())
    {
        success &= mUi->uEncoderPage->LoadFromJson(pJson["encoder"].toObject());
    }
    else
    {
        success = false;
    }

    if (pJson.contains("speaker") && pJson["speaker"].isObject())
    {
        success &= mUi->uSpeakerPage->LoadFromJson(pJson["speaker"].toObject());
    }
    else
    {
        success = false;
    }

#warning add remaining pages

    return success;
}

void MainWindow::Log(const QString& pText, const QString& pColorString)
{
    const auto timestamp = QDateTime::currentDateTime().toString(Qt::DateFormat::ISODate).replace('T', ' ');

    mUi->uLogConsole->append(QString("<span style=\"color: rgb(100, 100, 100);\">[%0]</span> <span style=\"color: %1;\">%2</span>").arg(timestamp, pColorString, pText));
}

void MainWindow::CompilerLog(const std::optional<QString>& pPath, const QString& pText, const QString& pColorString)
{
    if (pText.contains("exit") || pText.contains("cd ") || pText.contains("Microsoft Windows") || pText.contains("Microsoft Corporation"))
    {
        return;
    }

    if (false == pPath.has_value())
    {
        mUi->uCompilerConsole->append(QString("<span style=\"color: %0;\">%1</span>").arg(pColorString, pText));
    }
    else
    {
        mUi->uCompilerConsole->append(QString("<span style=\"color: rgb(100, 100, 100);\">%0</span> <span style=\"color: %1;\">%2</span>").arg(pPath.value(), pColorString, pText));
    }
}
