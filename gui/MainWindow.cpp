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

MainWindow::MainWindow(QWidget *pParent)
    : QMainWindow(pParent)
    , mUi(new Ui::MainWindow)
    , mAboutDialog(this)
    , mStatusLabel("Project: -")
    , mMarlinVersionLabel(QString("Marlin Version: v%0").arg(MARLIN_VERSION))
{
    mUi->setupUi(this);

    setWindowTitle(QString("iMC - iLOOP Marlin Configurator v%0").arg(SW_VERSION));

    // Initialize dock widgets
    constexpr auto dockHeight = 200;

    tabifyDockWidget(mUi->uConsoleDock, mUi->uCodePreviewDock);
    tabifyDockWidget(mUi->uCodePreviewDock, mUi->uCompilerOutputsDock);
    resizeDocks(QList{static_cast<QDockWidget*>(mUi->uConsoleDock),
                      static_cast<QDockWidget*>(mUi->uCodePreviewDock),
                      static_cast<QDockWidget*>(mUi->uCompilerOutputsDock)},
                QList{dockHeight, dockHeight, dockHeight}, Qt::Vertical);

    // Add dock widget view actions to menu
    mUi->menuView->addAction(mUi->uNavigationDock->toggleViewAction());
    mUi->menuView->addAction(mUi->uConsoleDock->toggleViewAction());
    mUi->menuView->addAction(mUi->uCodePreviewDock->toggleViewAction());
    mUi->menuView->addAction(mUi->uCompilerOutputsDock->toggleViewAction());

    mUi->menuView->actions().at(0)->setShortcut(QKeySequence("Alt+N"));
    mUi->menuView->actions().at(1)->setShortcut(QKeySequence("Alt+O"));
    mUi->menuView->actions().at(2)->setShortcut(QKeySequence("Alt+P"));
    mUi->menuView->actions().at(3)->setShortcut(QKeySequence("Alt+C"));

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

    OnUpdatePreview(QStringList("Preview not available."));
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

        // Update code preview on tab change
        auto&& page = mUi->stackedWidget->currentWidget()->findChild<AbstractPage*>();
        if (nullptr != page)
        {
            mUi->uPreviewEdit->verticalScrollBar()->setSliderPosition(0);
            page->OnUpdatePreview();
        }
        else
        {
            OnUpdatePreview(QStringList("Preview not available."));
        }
    });

    QObject::connect(mUi->uCloseAction, &QAction::triggered, this, &QMainWindow::close);
    QObject::connect(mUi->uAboutAction, &QAction::triggered, &mAboutDialog, &AboutDialog::show);
    QObject::connect(mUi->uNewProjectAction, &QAction::triggered, this, &MainWindow::OnNewProject);

    QObject::connect(mUi->uWelcomePage, &WelcomePage::NewProjectSignal, this, &MainWindow::OnNewProject);
    QObject::connect(mUi->uWelcomePage, &WelcomePage::OpenProjectSignal, this, &MainWindow::OpenProjectSignal);

    // Connects for code preview
    for (auto&& page : findChildren<AbstractPage*>())
    {
        QObject::connect(page, &AbstractPage::UpdatePreviewSignal, this, &MainWindow::OnUpdatePreview);
    }

    QObject::connect(mUi->uExportAction, &QAction::triggered, this, [&]()
    {
        QString fileName = QFileDialog::getSaveFileName(this, tr("Export as..."), QDir::homePath() + "/Configuration.h", tr("C++ header (*.h)"));

        if (fileName.isEmpty())
        {
            return;
        }

        emit ExportConfigurationSignal(QFileInfo(fileName));
    });

    QObject::connect(mUi->uSaveProjectAction, &QAction::triggered, this, [&]()
    {
        emit SaveProjectSignal();
    });

    QObject::connect(mUi->uSaveProjectAsAction, &QAction::triggered, this, [&]()
    {
        emit SaveProjectSignal(true);
    });

    QObject::connect(mUi->uOpenProjectAction, &QAction::triggered, this, &MainWindow::OpenProjectSignal);

    QObject::connect(mUi->uOpenFolderAction, &QAction::triggered, this, &MainWindow::OpenFolderSignal);

#warning disable actions while building/cleaning/uploading
    QObject::connect(mUi->uActionBuild, &QAction::triggered, this, [&](){
        mUi->uCompilerOutputsDock->raise();

        emit BuildMarlinSignal();
    });

    QObject::connect(mUi->uActionClean, &QAction::triggered, this, [&](){
        mUi->uCompilerOutputsDock->raise();

        emit CleanSignal();
    });

    QObject::connect(mUi->uActionOpenMarlinHomepage, &QAction::triggered, this, [&]()
    {
        QDesktopServices::openUrl(QUrl("https://marlinfw.org/"));
    });

    QObject::connect(mUi->uActionOpenAutoBuildMarlin, &QAction::triggered, this, [&]()
    {
        QDesktopServices::openUrl(QUrl("https://marlinfw.org/docs/basics/auto_build_marlin.html"));
    });

    QObject::connect(mUi->uActionOpenMarlinConfiguration, &QAction::triggered, this, [&]()
    {
        QDesktopServices::openUrl(QUrl("https://marlinfw.org/docs/configuration/configuration.html"));
    });

    QObject::connect(mUi->uActionOpenGitHub, &QAction::triggered, this, [&]()
    {
        QDesktopServices::openUrl(QUrl("https://github.com/SimonBuxx/iloop-marlin-configurator/"));
    });

    QObject::connect(mUi->uActionOpenErigEv, &QAction::triggered, this, [&]()
    {
        QDesktopServices::openUrl(QUrl("https://er-ig.de/"));
    });

    QObject::connect(mUi->uWelcomeTabButton, &QPushButton::clicked, this, [&]()
    {
        mUi->stackedWidget->setCurrentIndex(0);
    });

    QObject::connect(mUi->uFirmwareTabButton, &QPushButton::clicked, this, [&]()
    {
        mUi->stackedWidget->setCurrentIndex(1);
    });

    QObject::connect(mUi->uHardwareTabButton, &QPushButton::clicked, this, [&]()
    {
        mUi->stackedWidget->setCurrentIndex(2);
    });

    QObject::connect(mUi->uExtruderTabButton, &QPushButton::clicked, this, [&]()
    {
        mUi->stackedWidget->setCurrentIndex(3);
    });

    QObject::connect(mUi->uPowerSupplyButton, &QPushButton::clicked, this, [&]()
    {
        mUi->stackedWidget->setCurrentIndex(4);
    });

    QObject::connect(mUi->uThermalSettingsButton, &QPushButton::clicked, this, [&]()
    {
        mUi->stackedWidget->setCurrentIndex(5);
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

void MainWindow::OnNewProject()
{
    ResetValues();

    JumpToFirstConfigTab();
    SetProjectName(std::nullopt);
    Log("New project initialized.", "rgb(249, 154, 0)");

    emit NewProjectSignal();
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

void MainWindow::SetProjectName(const std::optional<QString>& pName)
{

    mStatusLabel.setText(QString("Project: %0").arg(pName.value_or("-")));
    setWindowTitle(QString("%0iMC - iLOOP Marlin Configurator v%1").arg(pName.has_value() ? pName.value() + " - " : "", SW_VERSION));
}

bool MainWindow::LoadProject(const QJsonObject& pJson)
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

    return success;
}

void MainWindow::Log(const QString& pText, const QString& pColorString)
{
    const auto timestamp = QDateTime::currentDateTime().toString(Qt::DateFormat::ISODate).replace('T', ' ');

    mUi->uLogConsole->append(QString("<span style=\"color: rgb(100, 100, 100);\">[%0]</span> <span style=\"color: %1;\">%2</span>").arg(timestamp, pColorString, pText));
}

void MainWindow::CompilerLog(const std::optional<QString>& pPath, const QString& pText, const QString& pColorString)
{
    if (pText.contains("exit") || pText.contains("cd ") || pText.contains("Microsoft Windows") || pText.contains("(c) Microsoft Corporation"))
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
