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

MainWindow::MainWindow(QWidget *pParent)
    : QMainWindow(pParent)
    , mUi(new Ui::MainWindow)
    , mAboutDialog(this)
{
    mUi->setupUi(this);

    ConnectGuiSignalsAndSlots();

    mUi->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete mUi;
}

void MainWindow::ConnectGuiSignalsAndSlots()
{
    QObject::connect(mUi->uCloseAction, &QAction::triggered, this, &QMainWindow::close);
    QObject::connect(mUi->uAboutAction, &QAction::triggered, &mAboutDialog, &AboutDialog::show);
    QObject::connect(mUi->uNewProjectAction, &QAction::triggered, this, &MainWindow::OnNewProject);

    QObject::connect(mUi->uWelcomePage, &WelcomePage::NewProjectSignal, this, &MainWindow::OnNewProject);
    QObject::connect(mUi->uWelcomePage, &WelcomePage::OpenProjectSignal, this, &MainWindow::OpenProjectSignal);

    QObject::connect(mUi->uExportAction, &QAction::triggered, this, [&]()
    {
        QString fileName = QFileDialog::getSaveFileName(this, tr("Export as..."), QDir::homePath() + "/Configuration.h", tr("C++ header (*.h)"));

        if (fileName.isEmpty())
        {
            return;
        }

        const auto config = FetchConfiguration();

        emit ExportConfigurationSignal(QFileInfo(fileName), config);
    });

    QObject::connect(mUi->uSaveProjectAction, &QAction::triggered, this, [&]()
    {
        const auto&& config = FetchConfiguration();
        emit SaveProjectSignal(config);
    });

    QObject::connect(mUi->uSaveProjectAsAction, &QAction::triggered, this, [&]()
    {
        const auto&& config = FetchConfiguration();
        emit SaveProjectSignal(config, true);
    });

    QObject::connect(mUi->uOpenProjectAction, &QAction::triggered, this, &MainWindow::OpenProjectSignal);

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
}

void MainWindow::JumpToFirstConfigTab()
{
    mUi->uFirmwareTabButton->click();
}

void MainWindow::OnNewProject()
{
    mUi->uFirmwarePage->ResetValues();
    mUi->uHardwarePage->ResetValues();
    mUi->uExtruderPage->ResetValues();
    mUi->uPowerSupplyPage->ResetValues();

    SetProjectName(std::nullopt);
    Log("New project initialized.");

    emit NewProjectSignal();
}

Configuration MainWindow::FetchConfiguration()
{
    Configuration config;

    config.firmware = mUi->uFirmwarePage->FetchConfiguration();
    config.hardware = mUi->uHardwarePage->FetchConfiguration();
    config.extruder = mUi->uExtruderPage->FetchConfiguration();
    config.powerSupply = mUi->uPowerSupplyPage->FetchConfiguration();

    return config;
}

void MainWindow::ReplaceTags(QStringList& pOutput)
{
    mUi->uFirmwarePage->ReplaceTags(pOutput);
    mUi->uHardwarePage->ReplaceTags(pOutput);
    mUi->uExtruderPage->ReplaceTags(pOutput);
    mUi->uPowerSupplyPage->ReplaceTags(pOutput);
}

void MainWindow::SetProjectName(const std::optional<QString>& pName)
{
    mUi->uProjectLabel->setText(QString("Project: %0").arg(pName.value_or("-")));

    setWindowTitle(QString("%0iMC - iLOOP Marlin Configurator v0.1.0").arg(pName.has_value() ? pName.value() + " - " : ""));
}

bool MainWindow::LoadProject(const QJsonObject& pJson)
{
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

    return success;
}

void MainWindow::Log(const QString& pText, const QString& pColorString)
{
    const auto timestamp = QDateTime::currentDateTime().toString(Qt::DateFormat::ISODate).replace('T', ' ');

    mUi->uLogConsole->append(QString("<span style=\"color: rgb(100, 100, 100);\">[%0]</span> <span style=\"color: %1;\">%2</span>").arg(timestamp, pColorString, pText));
}
