#include "Application.h"

#include <QApplication>
#include <QFileDialog>
#include <QJsonDocument>
#include <QJsonObject>

Application::Application(QObject *parent)
    : QObject(parent)
{
    QObject::connect(&mMainWindow, &MainWindow::ExportConfigurationSignal, this, &Application::OnExportConfiguration);
    QObject::connect(&mMainWindow, &MainWindow::SaveProjectSignal, this, &Application::OnSaveProject);
    QObject::connect(&mMainWindow, &MainWindow::NewProjectSignal, this, &Application::OnNewProject);

    mMainWindow.Log("Reading Configuration.h template...");
    mTemplate = ReadConfigurationTemplateFromFile(QFileInfo(TEMPLATE_PATH));

    mMainWindow.show();

    if (!mTemplate.has_value())
    {
        mMainWindow.Log("Could not load the Configuration.h template.", "red");
        return;
    }

    mMainWindow.Log("Initialization successful.", "green");
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

    mMainWindow.Log(QString("Generation of output file %0 successful.").arg(pFileInfo.filePath()), "green");
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
        const QString name = QString("\\%0.json").arg(pConfig.CUSTOM_MACHINE_NAME.isEmpty() ? "unnamed" : pConfig.CUSTOM_MACHINE_NAME);

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

    mMainWindow.Log(QString("Saved project as %0").arg(fileInfo.filePath()), "green");

    mOpenFileInfo = fileInfo;
    mMainWindow.SetProjectName(fileInfo.baseName());
}

void Application::OnNewProject()
{
    mOpenFileInfo = std::nullopt;
}

std::optional<QStringList> Application::GenerateConfigurationContent(const Configuration& pConfig)
{
    if (!mTemplate.has_value())
    {
        return std::nullopt;
    }

    QStringList output = mTemplate.value();

    output.replaceInStrings("#{SHOW_BOOTSCREEN}", QString("%0#define SHOW_BOOTSCREEN").arg(pConfig.SHOW_BOOTSCREEN ? "" : "//"));
    output.replaceInStrings("#{MOTHERBOARD}", pConfig.MOTHERBOARD);
    output.replaceInStrings("#{SERIAL_PORT}", QString::number(pConfig.SERIAL_PORT));
    output.replaceInStrings("#{BAUDRATE}", QString::number(pConfig.BAUDRATE));
    output.replaceInStrings("#{STRING_CONFIG_H_AUTHOR}", pConfig.STRING_CONFIG_H_AUTHOR);
    output.replaceInStrings("#{CUSTOM_MACHINE_NAME}", pConfig.CUSTOM_MACHINE_NAME);

    return output;
}
