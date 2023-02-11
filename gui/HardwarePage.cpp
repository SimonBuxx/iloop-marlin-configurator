/*!
 * \file HardwarePage.cpp
 * \brief The HardwarePage class represents the hardware page
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

#include "HardwarePage.h"
#include "./ui_HardwarePage.h"
#include "HelperFunctions.h"

HardwarePage::HardwarePage(QWidget *pParent) :
    QWidget(pParent),
    mUi(new Ui::HardwarePage)
{
    mUi->setupUi(this);

    ConnectGuiSignalsAndSlots();
    ResetValues();
}

HardwarePage::~HardwarePage()
{
    delete mUi;
}

void HardwarePage::ConnectGuiSignalsAndSlots()
{
    QObject::connect(mUi->uDocumentationButton, &QPushButton::clicked, this, [&]()
    {
        OpenMarlinDocumentation("hardware-info");
    });
}

void HardwarePage::ResetValues()
{
    mUi->uMotherboardComboBox->setCurrentText(defaults::MOTHERBOARD);
    mUi->uSerialPortComboBox->setCurrentText(defaults::SERIAL_PORT);
    mUi->uBaudrateComboBox->setCurrentText(defaults::BAUDRATE);
    mUi->uBaudRateGCodeBox->setChecked(defaults::BAUD_RATE_GCODE);
    mUi->uSerialPort2ComboBox->setCurrentText(defaults::SERIAL_PORT_2);
    mUi->uBaudRate2ComboBox->setCurrentText(defaults::BAUDRATE_2);
    mUi->uSerialPort3ComboBox->setCurrentText(defaults::SERIAL_PORT_3);
    mUi->uBaudRate3ComboBox->setCurrentText(defaults::BAUDRATE_3);
    mUi->uBluetoothBox->setChecked(defaults::BLUETOOTH);
    mUi->uPrinterNameEdit->setText(defaults::CUSTOM_MACHINE_NAME);
    mUi->uMachineUuidEdit->setText(defaults::MACHINE_UUID);

    mUi->uSerialPort2Box->setChecked(defaults::ENABLE_SERIAL_PORT_2);
    mUi->uBaudRate2Box->setChecked(defaults::ENABLE_BAUDRATE_2);
    mUi->uSerialPort3Box->setChecked(defaults::ENABLE_SERIAL_PORT_3);
    mUi->uBaudRate3Box->setChecked(defaults::ENABLE_BAUDRATE_3);
    mUi->uCustomMachineNameBox->setChecked(defaults::ENABLE_CUSTOM_MACHINE_NAME);
    mUi->uMachineUuidBox->setChecked(defaults::ENABLE_MACHINE_UUID);
}

bool HardwarePage::LoadFromJson(const QJsonObject &pJson)
{
    bool success = true;

    success &= LoadConfig(mUi->uMotherboardComboBox, pJson, "MOTHERBOARD", true);
    success &= LoadConfig(mUi->uSerialPortComboBox, pJson, "SERIAL_PORT");
    success &= LoadConfig(mUi->uBaudrateComboBox, pJson, "BAUDRATE");
    success &= LoadConfig(mUi->uBaudRateGCodeBox, pJson, "BAUD_RATE_GCODE");
    success &= LoadConfig(mUi->uSerialPort2ComboBox, pJson, "SERIAL_PORT_2");
    success &= LoadConfig(mUi->uBaudRate2ComboBox, pJson, "BAUDRATE_2");
    success &= LoadConfig(mUi->uSerialPort3ComboBox, pJson, "SERIAL_PORT_3");
    success &= LoadConfig(mUi->uBaudRate3ComboBox, pJson, "BAUDRATE_3");
    success &= LoadConfig(mUi->uBluetoothBox, pJson, "BLUETOOTH");
    success &= LoadConfig(mUi->uPrinterNameEdit, pJson, "CUSTOM_MACHINE_NAME");
    success &= LoadConfig(mUi->uMachineUuidEdit, pJson, "MACHINE_UUID");

    success &= LoadConfig(mUi->uSerialPort2Box, pJson, "ENABLE_SERIAL_PORT_2");
    success &= LoadConfig(mUi->uBaudRate2Box, pJson, "ENABLE_BAUDRATE_2");
    success &= LoadConfig(mUi->uSerialPort3Box, pJson, "ENABLE_SERIAL_PORT_3");
    success &= LoadConfig(mUi->uBaudRate3Box, pJson, "ENABLE_BAUDRATE_3");
    success &= LoadConfig(mUi->uCustomMachineNameBox, pJson, "ENABLE_CUSTOM_MACHINE_NAME");
    success &= LoadConfig(mUi->uMachineUuidBox, pJson, "ENABLE_MACHINE_UUID");

    return success;
}

HardwareConfiguration HardwarePage::FetchConfiguration()
{
    HardwareConfiguration config;

    SetConfig(config.MOTHERBOARD, mUi->uMotherboardComboBox, true);
    SetConfig(config.SERIAL_PORT, mUi->uSerialPortComboBox);
    SetConfig(config.BAUDRATE, mUi->uBaudrateComboBox);
    SetConfig(config.BAUD_RATE_GCODE, mUi->uBaudRateGCodeBox);
    SetConfig(config.SERIAL_PORT_2, mUi->uSerialPort2ComboBox);
    SetConfig(config.BAUDRATE_2, mUi->uBaudRate2ComboBox);
    SetConfig(config.SERIAL_PORT_3, mUi->uSerialPort3ComboBox);
    SetConfig(config.BAUDRATE_3, mUi->uBaudRate3ComboBox);
    SetConfig(config.BLUETOOTH, mUi->uBluetoothBox);
    SetConfig(config.CUSTOM_MACHINE_NAME, mUi->uPrinterNameEdit);
    SetConfig(config.MACHINE_UUID, mUi->uMachineUuidEdit);

    SetConfig(config.ENABLE_SERIAL_PORT_2, mUi->uSerialPort2Box);
    SetConfig(config.ENABLE_BAUDRATE_2, mUi->uBaudRate2Box);
    SetConfig(config.ENABLE_SERIAL_PORT_3, mUi->uSerialPort3Box);
    SetConfig(config.ENABLE_BAUDRATE_3, mUi->uBaudRate3Box);
    SetConfig(config.ENABLE_CUSTOM_MACHINE_NAME, mUi->uCustomMachineNameBox);
    SetConfig(config.ENABLE_MACHINE_UUID, mUi->uMachineUuidBox);

    return config;
}

void HardwarePage::ReplaceTags(QStringList& pOutput)
{
    ReplaceTag(pOutput, "#{MOTHERBOARD}", mUi->uMotherboardComboBox, false, "MOTHERBOARD", true);
    ReplaceTag(pOutput, "#{SERIAL_PORT}", mUi->uSerialPortComboBox, false, "SERIAL_PORT");
    ReplaceTag(pOutput, "#{BAUDRATE}", mUi->uBaudrateComboBox, false, "BAUDRATE");
    ReplaceTag(pOutput, "#{BAUD_RATE_GCODE}", mUi->uBaudRateGCodeBox, "BAUD_RATE_GCODE");
    ReplaceTag(pOutput, "#{SERIAL_PORT_2}", mUi->uSerialPort2ComboBox, !mUi->uSerialPort2Box->isChecked(), "SERIAL_PORT_2");
    ReplaceTag(pOutput, "#{BAUDRATE_2}", mUi->uBaudRate2ComboBox, !mUi->uBaudRate2Box->isChecked(), "BAUDRATE_2");
    ReplaceTag(pOutput, "#{SERIAL_PORT_3}", mUi->uSerialPort3ComboBox, !mUi->uSerialPort3Box->isChecked(), "SERIAL_PORT_3");
    ReplaceTag(pOutput, "#{BAUDRATE_3}", mUi->uBaudRate3ComboBox, !mUi->uBaudRate3Box->isChecked(), "BAUDRATE_3");
    ReplaceTag(pOutput, "#{BLUETOOTH}", mUi->uBluetoothBox, "BLUETOOTH");
    ReplaceTag(pOutput, "#{CUSTOM_MACHINE_NAME}", mUi->uPrinterNameEdit, !mUi->uCustomMachineNameBox->isChecked(), "CUSTOM_MACHINE_NAME", true);
    ReplaceTag(pOutput, "#{MACHINE_UUID}", mUi->uMachineUuidEdit, !mUi->uMachineUuidBox->isChecked(), "MACHINE_UUID", true);
}
