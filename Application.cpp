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

#include <QApplication>
#include <QFileDialog>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFontDatabase>

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

    mMainWindow.Log("Reading Configuration.h template...");
    mTemplate = ReadConfigurationTemplateFromFile(QFileInfo(TEMPLATE_PATH));

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

std::optional<QStringList> Application::ReadConfigurationTemplateFromFile(const QFileInfo& pFileInfo)
{
    QStringList stringList;
    QFile file(pFileInfo.filePath());

    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        return std::nullopt;
    }

    QTextStream textStream(&file);
    while (true)
    {
        QString line = textStream.readLine();
        if (line.isNull())
        {
            break;
        }
        else
        {
            stringList.append(line);
        }
    }

    file.close();

    return stringList;
}

void Application::OnExportConfiguration(const QFileInfo& pFileInfo, const Configuration& pConfig)
{
    mMainWindow.Log(QString("Export of output file %0 started...").arg(pFileInfo.filePath()));
    QCoreApplication::processEvents();

    const auto&& stringList = GenerateConfigurationContent(pConfig);

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

void Application::OnSaveProject(const Configuration& pConfig, bool pForceSaveAs)
{
    QFileInfo fileInfo;

    if (mOpenFileInfo.has_value() && !pForceSaveAs)
    {
        fileInfo = mOpenFileInfo.value();
    }
    else
    {
        const QString name = QString("\\%0.json").arg(pConfig.hardware.CUSTOM_MACHINE_NAME.isEmpty() ? "unnamed" : pConfig.hardware.CUSTOM_MACHINE_NAME);

        QString fileName = QFileDialog::getSaveFileName(&mMainWindow, tr("Save Project As..."), QDir::homePath() + name, tr("JSON document (*.json)"));

        if (fileName.isEmpty())
        {
            return;
        }

        fileInfo = QFileInfo(fileName);
    }

    const auto json = pConfig.ToJson();

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
    mMainWindow.JumpToFirstConfigTab();
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

std::optional<QStringList> Application::GenerateConfigurationContent(const Configuration& pConfig)
{
    if (mTemplate.has_value())
    {
        QStringList output = mTemplate.value();

        mMainWindow.ReplaceTags(output);
        return output;
    }

    return std::nullopt;
}
