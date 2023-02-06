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

void HardwarePage::FetchConfiguration(Configuration& pConfig)
{
    SetConfig(pConfig.hardware.MOTHERBOARD, mUi->uMotherboardBox, true);
    SetConfig(pConfig.hardware.SERIAL_PORT, mUi->uSerialPortBox);
    SetConfig(pConfig.hardware.BAUDRATE, mUi->uBaudrateBox);
    SetConfig(pConfig.hardware.BAUD_RATE_GCODE, mUi->uBaudRateGCodeCheckBox);
    SetConfig(pConfig.hardware.SERIAL_PORT_2, mUi->uSerialPort2ComboBox);
    SetConfig(pConfig.hardware.BAUDRATE_2, mUi->uBaudRate2ComboBox);
    SetConfig(pConfig.hardware.SERIAL_PORT_3, mUi->uSerialPort3ComboBox);
    SetConfig(pConfig.hardware.BAUDRATE_3, mUi->uBaudRate3ComboBox);
    SetConfig(pConfig.hardware.BLUETOOTH, mUi->uBluetoothCheckBox);
    SetConfig(pConfig.hardware.CUSTOM_MACHINE_NAME, mUi->uPrinterNameEdit);
    SetConfig(pConfig.hardware.MACHINE_UUID, mUi->uMachineUuidEdit);
}
