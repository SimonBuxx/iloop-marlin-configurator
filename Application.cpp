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

inline QString OptionalParameter(bool pCondition, const QString& pAttributeName)
{
    return QString("%0#define %1").arg(pCondition ? "" : "//", pAttributeName);
}

inline QString OptionalParameter(bool pCondition, const QString& pAttributeValue, const QString& pAttributeName, bool pUseParentheses = false)
{
    return QString(pUseParentheses ? "%0#define %1 \"%2\"" : "%0#define %1 %2").arg(pCondition ? "" : "//", pAttributeName, pAttributeValue);
}

Application::Application(QObject *parent)
    : QObject(parent)
{
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

    mMainWindow.Log(QString("Saved project as %0").arg(fileInfo.filePath()), "green");

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

    mMainWindow.Log(QString("Opened project %0").arg(fileInfo.filePath()), "green");

    mOpenFileInfo = fileInfo;
    mMainWindow.SetProjectName(fileInfo.baseName());
}

std::optional<QStringList> Application::GenerateConfigurationContent(const Configuration& pConfig)
{
    if (!mTemplate.has_value())
    {
        return std::nullopt;
    }

    QStringList output = mTemplate.value();

    // Firmware
    output.replaceInStrings("#{STRING_CONFIG_H_AUTHOR}", pConfig.firmware.STRING_CONFIG_H_AUTHOR);
    output.replaceInStrings("#{CUSTOM_VERSION_FILE}", OptionalParameter(!pConfig.firmware.CUSTOM_VERSION_FILE.isEmpty(), pConfig.firmware.CUSTOM_VERSION_FILE, "CUSTOM_VERSION_FILE"));
    output.replaceInStrings("#{SHOW_BOOTSCREEN}", OptionalParameter(pConfig.firmware.SHOW_BOOTSCREEN, "SHOW_BOOTSCREEN"));
    output.replaceInStrings("#{SHOW_CUSTOM_BOOTSCREEN}", OptionalParameter(pConfig.firmware.SHOW_CUSTOM_BOOTSCREEN, "SHOW_CUSTOM_BOOTSCREEN"));
    output.replaceInStrings("#{CUSTOM_STATUS_SCREEN_IMAGE}", OptionalParameter(pConfig.firmware.CUSTOM_STATUS_SCREEN_IMAGE, "CUSTOM_STATUS_SCREEN_IMAGE"));

    // Hardware
    output.replaceInStrings("#{MOTHERBOARD}", pConfig.hardware.MOTHERBOARD);
    output.replaceInStrings("#{SERIAL_PORT}", pConfig.hardware.SERIAL_PORT);
    output.replaceInStrings("#{BAUDRATE}", pConfig.hardware.BAUDRATE);
    output.replaceInStrings("#{BAUD_RATE_GCODE}", OptionalParameter(pConfig.hardware.BAUD_RATE_GCODE, "BAUD_RATE_GCODE"));
    output.replaceInStrings("#{SERIAL_PORT_2}", OptionalParameter(pConfig.hardware.SERIAL_PORT_2 != disabled_values::SERIAL_PORT_2, pConfig.hardware.SERIAL_PORT_2, "SERIAL_PORT_2"));
    output.replaceInStrings("#{BAUDRATE_2}", OptionalParameter(pConfig.hardware.BAUDRATE_2 != disabled_values::BAUDRATE_2, pConfig.hardware.BAUDRATE_2, "BAUDRATE_2"));
    output.replaceInStrings("#{SERIAL_PORT_3}", OptionalParameter(pConfig.hardware.SERIAL_PORT_3 != disabled_values::SERIAL_PORT_3, pConfig.hardware.SERIAL_PORT_3, "SERIAL_PORT_3"));
    output.replaceInStrings("#{BAUDRATE_3}", OptionalParameter(pConfig.hardware.BAUDRATE_3 != disabled_values::BAUDRATE_3, pConfig.hardware.BAUDRATE_3, "BAUDRATE_3"));
    output.replaceInStrings("#{BLUETOOTH}", OptionalParameter(pConfig.hardware.BLUETOOTH, "BLUETOOTH"));
    output.replaceInStrings("#{CUSTOM_MACHINE_NAME}", OptionalParameter(!pConfig.hardware.CUSTOM_MACHINE_NAME.isEmpty(), pConfig.hardware.CUSTOM_MACHINE_NAME, "CUSTOM_MACHINE_NAME", true));
    output.replaceInStrings("#{MACHINE_UUID}", OptionalParameter(!pConfig.hardware.MACHINE_UUID.isEmpty(), pConfig.hardware.MACHINE_UUID, "MACHINE_UUID", true));

    // Power Supply
    output.replaceInStrings("#{PSU_CONTROL}", OptionalParameter(pConfig.powerSupply.PSU_CONTROL, "PSU_CONTROL"));
    output.replaceInStrings("#{PSU_NAME}", OptionalParameter(!pConfig.powerSupply.PSU_NAME.isEmpty(), pConfig.powerSupply.PSU_NAME, "PSU_NAME", true));
    output.replaceInStrings("#{MKS_PWC}", OptionalParameter(pConfig.powerSupply.MKS_PWC, "MKS_PWC"));
    output.replaceInStrings("#{PS_OFF_CONFIRM}", OptionalParameter(pConfig.powerSupply.PS_OFF_CONFIRM, "PS_OFF_CONFIRM"));
    output.replaceInStrings("#{PS_OFF_SOUND}", OptionalParameter(pConfig.powerSupply.PS_OFF_SOUND, "PS_OFF_SOUND"));
    output.replaceInStrings("#{PSU_ACTIVE_STATE}", pConfig.powerSupply.PSU_ACTIVE_STATE.startsWith("LOW") ? "LOW" : "HIGH");
    output.replaceInStrings("#{PSU_DEFAULT_OFF}", OptionalParameter(pConfig.powerSupply.PSU_DEFAULT_OFF, "PSU_DEFAULT_OFF"));
    output.replaceInStrings("#{PSU_POWERUP_DELAY}", OptionalParameter(pConfig.powerSupply.PSU_POWERUP_DELAY > 0, QString::number(pConfig.powerSupply.PSU_POWERUP_DELAY), "PSU_POWERUP_DELAY"));
    output.replaceInStrings("#{LED_POWEROFF_TIMEOUT}", OptionalParameter(pConfig.powerSupply.LED_POWEROFF_TIMEOUT > 0, QString::number(pConfig.powerSupply.LED_POWEROFF_TIMEOUT), "LED_POWEROFF_TIMEOUT"));
    output.replaceInStrings("#{POWER_OFF_TIMER}", OptionalParameter(pConfig.powerSupply.POWER_OFF_TIMER, "POWER_OFF_TIMER"));
    output.replaceInStrings("#{POWER_OFF_WAIT_FOR_COOLDOWN}", OptionalParameter(pConfig.powerSupply.POWER_OFF_WAIT_FOR_COOLDOWN, "POWER_OFF_WAIT_FOR_COOLDOWN"));
    output.replaceInStrings("#{PSU_POWERUP_GCODE}", OptionalParameter(!pConfig.powerSupply.PSU_POWERUP_GCODE.isEmpty(), pConfig.powerSupply.PSU_POWERUP_GCODE, "PSU_POWERUP_GCODE", true));
    output.replaceInStrings("#{PSU_POWEROFF_GCODE}", OptionalParameter(!pConfig.powerSupply.PSU_POWEROFF_GCODE.isEmpty(), pConfig.powerSupply.PSU_POWEROFF_GCODE, "PSU_POWEROFF_GCODE", true));
    output.replaceInStrings("#{AUTO_POWER_CONTROL}", OptionalParameter(pConfig.powerSupply.AUTO_POWER_CONTROL, "AUTO_POWER_CONTROL"));
    output.replaceInStrings("#{AUTO_POWER_FANS}", OptionalParameter(pConfig.powerSupply.AUTO_POWER_FANS, "AUTO_POWER_FANS"));
    output.replaceInStrings("#{AUTO_POWER_E_FANS}", OptionalParameter(pConfig.powerSupply.AUTO_POWER_E_FANS, "AUTO_POWER_E_FANS"));
    output.replaceInStrings("#{AUTO_POWER_CONTROLLERFAN}", OptionalParameter(pConfig.powerSupply.AUTO_POWER_CONTROLLERFAN, "AUTO_POWER_CONTROLLERFAN"));
    output.replaceInStrings("#{AUTO_POWER_CHAMBER_FAN}", OptionalParameter(pConfig.powerSupply.AUTO_POWER_CHAMBER_FAN, "AUTO_POWER_CHAMBER_FAN"));
    output.replaceInStrings("#{AUTO_POWER_COOLER_FAN}", OptionalParameter(pConfig.powerSupply.AUTO_POWER_COOLER_FAN, "AUTO_POWER_COOLER_FAN"));

    const bool powerSupplyConditionsMet1 = pConfig.powerSupply.AUTO_POWER_CONTROL;
#warning Is POWER_TIMEOUT optional or always needed when AUTO_POWER_CONTROL is active?
    output.replaceInStrings("#{POWER_TIMEOUT}", OptionalParameter(pConfig.powerSupply.POWER_TIMEOUT > 0 && powerSupplyConditionsMet1, QString::number(pConfig.powerSupply.POWER_TIMEOUT), "POWER_TIMEOUT"));
#warning Make parameters below optional (besides setting to zero)
    output.replaceInStrings("#{POWER_OFF_DELAY}", OptionalParameter(pConfig.powerSupply.POWER_OFF_DELAY > 0 && powerSupplyConditionsMet1, QString::number(pConfig.powerSupply.POWER_OFF_DELAY), "POWER_OFF_DELAY"));

    const bool powerSupplyConditionsMet2 = pConfig.powerSupply.AUTO_POWER_CONTROL || pConfig.powerSupply.POWER_OFF_WAIT_FOR_COOLDOWN;
    output.replaceInStrings("#{AUTO_POWER_E_TEMP}", OptionalParameter(pConfig.powerSupply.AUTO_POWER_E_TEMP > 0 && powerSupplyConditionsMet2, QString::number(pConfig.powerSupply.AUTO_POWER_E_TEMP), "AUTO_POWER_E_TEMP"));
    output.replaceInStrings("#{AUTO_POWER_CHAMBER_TEMP}", OptionalParameter(pConfig.powerSupply.AUTO_POWER_CHAMBER_TEMP > 0 && powerSupplyConditionsMet2, QString::number(pConfig.powerSupply.AUTO_POWER_CHAMBER_TEMP), "AUTO_POWER_CHAMBER_TEMP"));
    output.replaceInStrings("#{AUTO_POWER_COOLER_TEMP}", OptionalParameter(pConfig.powerSupply.AUTO_POWER_COOLER_TEMP > 0 && powerSupplyConditionsMet2, QString::number(pConfig.powerSupply.AUTO_POWER_COOLER_TEMP), "AUTO_POWER_COOLER_TEMP"));

    return output;
}
