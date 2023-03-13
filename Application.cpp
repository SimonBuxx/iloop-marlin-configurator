/*!
 * \file Application.cpp
 * \brief The Application class represents the application
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

#include "Application.h"
#include "HelperFunctions.h"

#include <QApplication>
#include <QFileDialog>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFontDatabase>
#include <QProcess>
#include <QMessageBox>

Application::Application(QObject *parent)
    : QObject(parent)
{   
    QFontDatabase::addApplicationFont(":/SourceCodePro-Italic.ttf");
    QFontDatabase::addApplicationFont(":/SourceCodePro-Regular.ttf");
    QFontDatabase::addApplicationFont(":/SourceSansPro-Light.ttf");
    QFontDatabase::addApplicationFont(":/SourceSansPro-LightItalic.ttf");
    QFontDatabase::addApplicationFont(":/SourceSansPro-Regular.ttf");

    QObject::connect(&mMainWindow, &MainWindow::ConfigureSignal, this, &Application::OnConfigure);
    QObject::connect(&mMainWindow, &MainWindow::SaveProjectSignal, this, &Application::OnSaveProject);
    QObject::connect(&mMainWindow, &MainWindow::CloseWorkspaceSignal, this, &Application::OnCloseWorkspace);
    QObject::connect(&mMainWindow, &MainWindow::OpenWorkspaceSignal, this, &Application::OnOpenFolder);
    QObject::connect(&mMainWindow, &MainWindow::BuildMarlinSignal, this, [&](){
        OnBuildMarlin(mMainWindow.GetEnvironment());
    });
    QObject::connect(&mMainWindow, &MainWindow::CleanSignal, this, [&](){
        OnClean(mMainWindow.GetEnvironment());
    });
    QObject::connect(&mMainWindow, &MainWindow::RebuildMarlinSignal, this, [&](){
        OnClean(mMainWindow.GetEnvironment());
        OnBuildMarlin(mMainWindow.GetEnvironment());
    });

    mMainWindow.Log("Reading Configuration.h template...");
    mTemplate = ReadTemplateFromFile(QFileInfo(TEMPLATE_PATH));

    mMainWindow.show();

    if (!mTemplate.has_value())
    {
        mMainWindow.Log("Could not load the Configuration.h template.", "red");
        return;
    }

    mMainWindow.Log("Initialization successful.", "rgb(249, 154, 0)");
}

Application::~Application()
{}

void Application::OnConfigure()
{
#warning [ENHANCEMENT] disable actions when no workspace is open
    if (!mFolderInfo.has_value())
    {
        mMainWindow.Log(QString("Configuration failed: No Marlin workspace opened."), "red");
        return;
    }

    if (!QDir(mFolderInfo.value().filePath() + "/Marlin").exists())
    {
        mMainWindow.Log(QString("Configuration failed: Subfolder %0 does not exist.").arg(mFolderInfo.value().filePath() + "/Marlin"), "red");
        return;
    }

    if (mNewWorkspace)
    {
        QMessageBox msgBox;
        msgBox.setText("This workspace is not yet configured for use with iMC.");
        msgBox.setInformativeText("There is no configuration.json file present in this workspace. Please make sure not to loose existing configuration data before continuing.");
        msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        msgBox.setIcon(QMessageBox::Warning);
        if (msgBox.exec() == QMessageBox::Cancel)
        {
            return;
        }
        mNewWorkspace = false;
    }

    const auto filePath = mFolderInfo.value().filePath() + "/Marlin/Configuration.h";

    mMainWindow.Log(QString("Generation of configuration file %0 started...").arg(filePath));
    QCoreApplication::processEvents(); // to ensure that the message is printed before the GUI freezes

    const auto&& stringList = GenerateCode();

    if (!stringList.has_value())
    {
        mMainWindow.Log(QString("Could not generate file %0: no file template loaded.").arg(filePath), "red");
        return;
    }

    QFile file(filePath);

    if (file.open(QFile::WriteOnly | QFile::Text))
    {
        QTextStream textStream(&file);
        for (const auto& line : stringList.value())
        {
            textStream << line << '\n';
        }
    }
    else
    {
        mMainWindow.Log(QString("Could not open configuration file %0").arg(filePath), "red");
        return;
    }

    file.close();

    mMainWindow.Log(QString("Generation of configuration file %0 successful.").arg(filePath), "rgb(249, 154, 0)");
}

void Application::OnSaveProject()
{
    if (!mFolderInfo.has_value())
    {
        mMainWindow.Log(QString("Saving workspace configuration failed: No Marlin workspace opened."), "red");
        return;
    }

    QFileInfo fileInfo{mFolderInfo.value().filePath() + "/configuration.json"};

    const auto& config = mMainWindow.FetchConfiguration();
    const auto& json = config.ToJson();

    QFile file(fileInfo.filePath());

    if (!file.open(QIODevice::WriteOnly))
    {
        mMainWindow.Log(QString("Could not open workspace configuration file %0").arg(fileInfo.filePath()), "red");
        return;
    }

    file.write(QJsonDocument(json).toJson());

    file.close();

    mMainWindow.Log(QString("Saved workspace configuration as %0").arg(fileInfo.filePath()));

    mOpenFileInfo = fileInfo;
    mNewWorkspace = false;
}

void Application::OnCloseWorkspace()
{
    if (!mFolderInfo.has_value())
    {
        mMainWindow.Log("Could not close workspace: No Marlin workspace opened.", "red");
        return;
    }

    mMainWindow.Log(QString("Workspace %0 has been closed.").arg(mFolderInfo.value().filePath()));
    mFolderInfo = std::nullopt;
    mNewWorkspace = false;
}

void Application::OpenConfigurationJson(const QFileInfo& pFilePath)
{
    QFile file(pFilePath.filePath());

    if (!file.open(QIODevice::ReadOnly))
    {
        mMainWindow.Log(QString("Could not open file %0").arg(pFilePath.filePath()), "red");
        return;
    }

    auto bytes = file.readAll();

    file.close();

    QJsonParseError jsonError;
    QJsonDocument document = QJsonDocument::fromJson(bytes, &jsonError);
    if (jsonError.error != QJsonParseError::NoError || !document.isObject())
    {
        mMainWindow.Log(QString("Could not open file %0").arg(pFilePath.filePath()), "red");
        return;
    }

    if (!mMainWindow.LoadConfigurationFromJson(document.object()))
    {
        mMainWindow.Log(QString("Content of file %0 incomplete, proceed with caution.").arg(pFilePath.filePath()), "red");
    }

    mMainWindow.Log(QString("Fetched configuration from file %0").arg(pFilePath.filePath()));

    mMainWindow.JumpToFirstConfigTab();
}

void Application::OnOpenFolder()
{
    QFileInfo folderInfo;

    QString folderName = QFileDialog::getExistingDirectory(&mMainWindow, tr("Open Workspace..."), QDir::homePath());

    if (folderName.isEmpty())
    {
        return;
    }

    folderInfo = QFileInfo(folderName);

    if (!QFile(folderInfo.filePath() + "/platformio.ini").exists())
    {
        mMainWindow.Log("Opening failed: The folder provided is not a Marlin base folder.", "red");
        return;
    }

    if (!QFile(folderInfo.filePath() + "/configuration.json").exists())
    {
        mMainWindow.Log("This workspace is not yet configured for use with iMC. Workspace configuration is set to default. Please make sure not to loose existing configuration data.", "red");
        mNewWorkspace = true;
    }
    else
    {
        OpenConfigurationJson(QFileInfo(folderInfo.filePath() + "/configuration.json"));
    }

    mMainWindow.Log(QString("Opened Marlin workspace %0").arg(folderInfo.filePath()));

    mFolderInfo = folderInfo;

    mMainWindow.SetWorkspace(folderInfo.filePath());
}

std::optional<QStringList> Application::GenerateCode()
{
    if (mTemplate.has_value())
    {
        QStringList output = mTemplate.value();

        mMainWindow.ReplaceTags(output);
        return output;
    }

    return std::nullopt;
}

void Application::OnBuildMarlin(const QString& pEnvironment)
{
    if (!mFolderInfo.has_value())
    {
        mMainWindow.Log("Could not start build: No Marlin workspace opened.", "red");
        return;
    }

    mBuildSuccess = false;

    QProcess process;
    process.start("C:\\Windows\\system32\\cmd.exe");

    if (false == process.waitForStarted())
    {
        return;
    }

    process.write(QString("cd %0\n").arg(mFolderInfo.value().filePath()).toLocal8Bit());

    QObject::connect(&process, &QProcess::readyReadStandardOutput, this, [&](){
        auto stream = QTextStream(process.readAllStandardOutput());
        while (!stream.atEnd())
        {
            const auto& line = stream.readLine();

            if (line.size() <= 2)
            {
                continue;
            }

            if (line.endsWith(">"))
            {
                mCurrent = line;
                continue;
            }

            if (line.contains(">platformio"))
            {
                auto list = line.split(">");
                mMainWindow.CompilerLog(list[0] + ">", list[1]);

                continue;
            }

            if  (line.contains("1 succeeded"))
            {
                mBuildSuccess = true;
            }

            mMainWindow.CompilerLog(mCurrent, line);
            mCurrent.clear();
        }
    });

    QObject::connect(&process, &QProcess::readyReadStandardError, this, [&](){
        auto stream = QTextStream(process.readAllStandardError());
        while (!stream.atEnd())
        {
            mMainWindow.CompilerLog(std::nullopt, stream.readLine(), "red");
        }
    });

    mMainWindow.Log(QString("Starting build for environment %0...").arg(pEnvironment));

    process.write(QString("platformio run -e %0\n").arg(pEnvironment).toLocal8Bit());

    process.write("exit\n");

    while(process.state() == QProcess::ProcessState::Running)
    {
        QCoreApplication::processEvents();
    }

    process.waitForFinished();
    process.close();

    mMainWindow.CompilerLog(std::nullopt, "");
    if (mBuildSuccess)
    {
        mMainWindow.Log("Build successful.", "rgb(249, 154, 0)");
    }
    else
    {
        mMainWindow.Log("Build failed. See compiler outputs for more details.", "red");
    }
}

void Application::OnClean(const QString& pEnvironment)
{
    if (!mFolderInfo.has_value())
    {
        mMainWindow.Log("Could not start cleaning: No Marlin workspace opened.", "red");
        return;
    }

    mBuildSuccess = false;

    QProcess process;
    process.start("C:\\Windows\\system32\\cmd.exe");

    if (false == process.waitForStarted())
    {
        return;
    }

    if (mFolderInfo.has_value())
    {
        process.write(QString("cd %0\n").arg(mFolderInfo.value().filePath()).toLocal8Bit());
    }

    QObject::connect(&process, &QProcess::readyReadStandardOutput, this, [&](){
        auto stream = QTextStream(process.readAllStandardOutput());
        while (!stream.atEnd())
        {
            const auto& line = stream.readLine();

            if (line.size() <= 2)
            {
                continue;
            }

            if (line.endsWith(">"))
            {
                mCurrent = line;
                continue;
            }

            if (line.contains(">platformio"))
            {
                auto list = line.split(">");
                mMainWindow.CompilerLog(list[0] + ">", list[1]);

                continue;
            }

            if  (line.contains("1 succeeded"))
            {
                mBuildSuccess = true;
            }

            mMainWindow.CompilerLog(mCurrent, line);
            mCurrent.clear();
        }
    });

    QObject::connect(&process, &QProcess::readyReadStandardError, this, [&](){
        auto stream = QTextStream(process.readAllStandardError());
        while (!stream.atEnd())
        {
            mMainWindow.CompilerLog(std::nullopt, stream.readLine(), "red");
        }
    });

    mMainWindow.Log(QString("Starting cleaning of environment %0...").arg(pEnvironment));

    process.write(QString("platformio run --target clean -e %0\n").arg(pEnvironment).toLocal8Bit());

    process.write("exit\n");

    while(process.state() == QProcess::ProcessState::Running)
    {
        QCoreApplication::processEvents();
    }

    process.waitForFinished();
    process.close();

    mMainWindow.CompilerLog(std::nullopt, "");
    if (mBuildSuccess)
    {
        mMainWindow.Log("Cleaning successful.", "rgb(249, 154, 0)");
    }
    else
    {
        mMainWindow.Log("Cleaning failed. See compiler outputs for more details.", "red");
    }
}
