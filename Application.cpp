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

Application::Application(QObject *parent)
    : QObject(parent)
{   
    QFontDatabase::addApplicationFont(":/SourceCodePro-Italic.ttf");
    QFontDatabase::addApplicationFont(":/SourceCodePro-Regular.ttf");
    QFontDatabase::addApplicationFont(":/SourceSansPro-Light.ttf");
    QFontDatabase::addApplicationFont(":/SourceSansPro-LightItalic.ttf");
    QFontDatabase::addApplicationFont(":/SourceSansPro-Regular.ttf");

    QObject::connect(&mMainWindow, &MainWindow::ExportConfigurationSignal, this, &Application::OnExportConfiguration);
    QObject::connect(&mMainWindow, &MainWindow::SaveProjectSignal, this, &Application::OnSaveProject);
    QObject::connect(&mMainWindow, &MainWindow::NewProjectSignal, this, &Application::OnNewProject);
    QObject::connect(&mMainWindow, &MainWindow::OpenProjectSignal, this, &Application::OnOpenProject);
    QObject::connect(&mMainWindow, &MainWindow::OpenFolderSignal, this, &Application::OnOpenFolder);
    QObject::connect(&mMainWindow, &MainWindow::BuildMarlinSignal, this, [&](){
#warning make environment dynamic
        OnBuildMarlin("mega2560");
    });
    QObject::connect(&mMainWindow, &MainWindow::CleanSignal, this, [&](){
#warning make environment dynamic
        OnClean("mega2560");
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

void Application::OnExportConfiguration(const QFileInfo& pFileInfo)
{
    mMainWindow.Log(QString("Export of output file %0 started...").arg(pFileInfo.filePath()));
    QCoreApplication::processEvents(); // to ensure that the message is printed before the GUI freezes

    const auto&& stringList = GenerateCode();

    if (!stringList.has_value())
    {
        mMainWindow.Log("Could not generate output file: no file template loaded.", "red");
        return;
    }

    QFile file(pFileInfo.filePath());

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
        mMainWindow.Log(QString("Could not open output file %0").arg(pFileInfo.filePath()), "red");
        return;
    }

    file.close();

    mMainWindow.Log(QString("Generation of output file %0 successful.").arg(pFileInfo.filePath()));
}

void Application::OnSaveProject(bool pForceSaveAs)
{
    QFileInfo fileInfo;

    const auto& config = mMainWindow.FetchConfiguration();

    if (mOpenFileInfo.has_value() && !pForceSaveAs)
    {
        fileInfo = mOpenFileInfo.value();
    }
    else
    {
        const QString name = QString("\\%0.json").arg(config.hardware.CUSTOM_MACHINE_NAME.isEmpty() ? "unnamed" : config.hardware.CUSTOM_MACHINE_NAME);

        QString fileName = QFileDialog::getSaveFileName(&mMainWindow, tr("Save Project As..."), QDir::homePath() + name, tr("JSON document (*.json)"));

        if (fileName.isEmpty())
        {
            return;
        }

        fileInfo = QFileInfo(fileName);
    }

    const auto& json = config.ToJson();

    QFile file(fileInfo.filePath());

    if (!file.open(QIODevice::WriteOnly))
    {
        mMainWindow.Log(QString("Could not open save file %0").arg(fileInfo.filePath()), "red");
        return;
    }

    file.write(QJsonDocument(json).toJson());

    file.close();

    mMainWindow.Log(QString("Saved project as %0").arg(fileInfo.filePath()));

    mOpenFileInfo = fileInfo;
    mMainWindow.SetProjectName(fileInfo.baseName());
}

void Application::OnNewProject()
{
    mOpenFileInfo = std::nullopt;
}

void Application::OnOpenProject()
{
    QFileInfo fileInfo;

    QString fileName = QFileDialog::getOpenFileName(&mMainWindow, tr("Open Project..."), QDir::homePath(), tr("JSON document (*.json)"));

    if (fileName.isEmpty())
    {
        return;
    }

    fileInfo = QFileInfo(fileName);

    QFile file(fileInfo.filePath());

    if (!file.open(QIODevice::ReadOnly))
    {
        mMainWindow.Log(QString("Could not open file %0").arg(fileInfo.filePath()), "red");
        return;
    }

    auto bytes = file.readAll();

    file.close();

    QJsonParseError jsonError;
    QJsonDocument document = QJsonDocument::fromJson(bytes, &jsonError);
    if (jsonError.error != QJsonParseError::NoError || !document.isObject())
    {
        mMainWindow.Log(QString("Could not open file %0").arg(fileInfo.filePath()), "red");
        return;
    }

    if (!mMainWindow.LoadProject(document.object()))
    {
        mMainWindow.Log(QString("Content of file %0 incomplete, proceed with caution.").arg(fileInfo.filePath()), "red");
    }

    mMainWindow.Log(QString("Opened project %0").arg(fileInfo.filePath()));

    mOpenFileInfo = fileInfo;
    mMainWindow.SetProjectName(fileInfo.baseName());
    mMainWindow.JumpToFirstConfigTab();
}

void Application::OnOpenFolder()
{
    QFileInfo folderInfo;

    QString folderName = QFileDialog::getExistingDirectory(&mMainWindow, tr("Open Folder..."), QDir::homePath());

    if (folderName.isEmpty())
    {
        return;
    }

    folderInfo = QFileInfo(folderName);

    mMainWindow.Log(QString("Opened folder %0").arg(folderInfo.filePath()));

    mFolderInfo = folderInfo;
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
