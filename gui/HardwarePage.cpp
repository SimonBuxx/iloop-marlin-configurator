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

    QObject::connect(mUi->uSerialPort2ComboBox, &QComboBox::currentIndexChanged, this, [&](auto pIndex)
    {
        mUi->uBaudRate2ComboBox->setEnabled(pIndex > 0);
    });

    QObject::connect(mUi->uSerialPort3ComboBox, &QComboBox::currentIndexChanged, this, [&](auto pIndex)
    {
        mUi->uBaudRate3ComboBox->setEnabled(pIndex > 0);
    });
}

void HardwarePage::ResetValues()
{
    mUi->uMotherboardBox->setCurrentText(defaults::MOTHERBOARD);
    mUi->uSerialPortBox->setCurrentText(defaults::SERIAL_PORT);
    mUi->uBaudrateBox->setCurrentText(defaults::BAUDRATE);
    mUi->uBaudRateGCodeCheckBox->setChecked(defaults::BAUD_RATE_GCODE);
    mUi->uSerialPort2ComboBox->setCurrentText(defaults::SERIAL_PORT_2);
    mUi->uBaudRate2ComboBox->setCurrentText(defaults::BAUDRATE_2);
    mUi->uSerialPort3ComboBox->setCurrentText(defaults::SERIAL_PORT_3);
    mUi->uBaudRate3ComboBox->setCurrentText(defaults::BAUDRATE_3);
    mUi->uBluetoothCheckBox->setChecked(defaults::BLUETOOTH);
    mUi->uPrinterNameEdit->setText(defaults::CUSTOM_MACHINE_NAME);
    mUi->uMachineUuidEdit->setText(defaults::MACHINE_UUID);
}

bool HardwarePage::LoadFromJson(const QJsonObject &pJson)
{
    bool success = true;

    success &= LoadConfig(mUi->uMotherboardBox, pJson, "MOTHERBOARD", true);
    success &= LoadConfig(mUi->uSerialPortBox, pJson, "SERIAL_PORT");
    success &= LoadConfig(mUi->uBaudrateBox, pJson, "BAUDRATE");
    success &= LoadConfig(mUi->uBaudRateGCodeCheckBox, pJson, "BAUD_RATE_GCODE");
    success &= LoadConfig(mUi->uSerialPort2ComboBox, pJson, "SERIAL_PORT_2");
    success &= LoadConfig(mUi->uBaudRate2ComboBox, pJson, "BAUDRATE_2");
    success &= LoadConfig(mUi->uSerialPort3ComboBox, pJson, "SERIAL_PORT_3");
    success &= LoadConfig(mUi->uBaudRate3ComboBox, pJson, "BAUDRATE_3");
    success &= LoadConfig(mUi->uBluetoothCheckBox, pJson, "BLUETOOTH");
    success &= LoadConfig(mUi->uPrinterNameEdit, pJson, "CUSTOM_MACHINE_NAME");
    success &= LoadConfig(mUi->uMachineUuidEdit, pJson, "MACHINE_UUID");

    return success;
}

HardwareConfiguration HardwarePage::FetchConfiguration()
{
    HardwareConfiguration config;

    SetConfig(config.MOTHERBOARD, mUi->uMotherboardBox, true);
    SetConfig(config.SERIAL_PORT, mUi->uSerialPortBox);
    SetConfig(config.BAUDRATE, mUi->uBaudrateBox);
    SetConfig(config.BAUD_RATE_GCODE, mUi->uBaudRateGCodeCheckBox);
    SetConfig(config.SERIAL_PORT_2, mUi->uSerialPort2ComboBox);
    SetConfig(config.BAUDRATE_2, mUi->uBaudRate2ComboBox);
    SetConfig(config.SERIAL_PORT_3, mUi->uSerialPort3ComboBox);
    SetConfig(config.BAUDRATE_3, mUi->uBaudRate3ComboBox);
    SetConfig(config.BLUETOOTH, mUi->uBluetoothCheckBox);
    SetConfig(config.CUSTOM_MACHINE_NAME, mUi->uPrinterNameEdit);
    SetConfig(config.MACHINE_UUID, mUi->uMachineUuidEdit);

    return config;
}

void HardwarePage::ReplaceTags(QStringList& pOutput)
{
    ReplaceTag(pOutput, "#{MOTHERBOARD}", mUi->uMotherboardBox, false, "MOTHERBOARD", true);
    ReplaceTag(pOutput, "#{SERIAL_PORT}", mUi->uSerialPortBox, false, "SERIAL_PORT");
    ReplaceTag(pOutput, "#{BAUDRATE}", mUi->uBaudrateBox, false, "BAUDRATE");
    ReplaceTag(pOutput, "#{BAUD_RATE_GCODE}", mUi->uBaudRateGCodeCheckBox, "BAUD_RATE_GCODE");
    ReplaceTag(pOutput, "#{SERIAL_PORT_2}", mUi->uSerialPort2ComboBox, mUi->uSerialPort2ComboBox->currentText() == disabled_values::SERIAL_PORT_2, "SERIAL_PORT_2");
    ReplaceTag(pOutput, "#{BAUDRATE_2}", mUi->uBaudRate2ComboBox, mUi->uBaudRate2ComboBox->currentText() == disabled_values::BAUDRATE_2, "BAUDRATE_2");
    ReplaceTag(pOutput, "#{SERIAL_PORT_3}", mUi->uSerialPort3ComboBox, mUi->uSerialPort3ComboBox->currentText() == disabled_values::SERIAL_PORT_3, "SERIAL_PORT_3");
    ReplaceTag(pOutput, "#{BAUDRATE_3}", mUi->uBaudRate3ComboBox, mUi->uBaudRate3ComboBox->currentText() == disabled_values::BAUDRATE_3, "BAUDRATE_3");
    ReplaceTag(pOutput, "#{BLUETOOTH}", mUi->uBluetoothCheckBox, "BLUETOOTH");
    ReplaceTag(pOutput, "#{CUSTOM_MACHINE_NAME}", mUi->uPrinterNameEdit, mUi->uPrinterNameEdit->text().isEmpty(), "CUSTOM_MACHINE_NAME", true);
    ReplaceTag(pOutput, "#{MACHINE_UUID}", mUi->uMachineUuidEdit, mUi->uMachineUuidEdit->text().isEmpty(), "MACHINE_UUID", true);
}
