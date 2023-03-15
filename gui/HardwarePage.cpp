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

#include <QToolButton>

HardwarePage::HardwarePage(QWidget *pParent) :
    AbstractPage(HARDWARE_TEMPLATE_PATH, pParent),
    mUi(new Ui::HardwarePage)
{
    mUi->setupUi(this);

    // Set the clear button icons of the search boxes
    mUi->uMotherBoardSearchBox->findChild<QToolButton*>()->setIcon(QIcon(":/close_FILL0_wght100_GRAD0_opsz20_white.svg"));
    mUi->uEnvironmentSearchBox->findChild<QToolButton*>()->setIcon(QIcon(":/close_FILL0_wght100_GRAD0_opsz20_white.svg"));

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

    QObject::connect(mUi->uMotherBoardSearchBox, &QLineEdit::textChanged, this, [&](const QString& pText)
    {
        const auto& index = mUi->uMotherboardDropdown->findText(pText, Qt::MatchFlag::MatchContains);
        if (index >= 0 && !pText.isEmpty())
        {
            mUi->uMotherboardDropdown->setCurrentIndex(index);
        }
    });

    QObject::connect(mUi->uEnvironmentSearchBox, &QLineEdit::textChanged, this, [&](const QString& pText)
    {
        const auto& index = mUi->uEnvironmentDropdown->findText(pText, Qt::MatchFlag::MatchContains);
        if (index >= 0 && !pText.isEmpty())
        {
            mUi->uEnvironmentDropdown->setCurrentIndex(index);
        }
    });

    QObject::connect(mUi->uGenerateUuidButton, &QPushButton::clicked, this, [&]()
    {
        mUi->uMachineUuidEdit->setText(QUuid::createUuid().toString(QUuid::WithoutBraces));
    });

    AbstractPage::ConnectGuiSignalsAndSlots();
}

void HardwarePage::ResetValues()
{
    mIsLoading = true;

    mUi->uEnvironmentDropdown->Reset(defaults::ENVIRONMENT);
    mUi->uMotherboardDropdown->Reset(defaults::MOTHERBOARD);
    mUi->uSerialPortDropdown->Reset(defaults::SERIAL_PORT);
    mUi->uBaudrateDropdown->Reset(defaults::BAUDRATE);
    mUi->uBaudRateGcodeBox->setChecked(defaults::BAUD_RATE_GCODE);
    mUi->uSerialPort2Dropdown->Reset(defaults::SERIAL_PORT_2);
    mUi->uBaudrate2Dropdown->Reset(defaults::BAUDRATE_2);
    mUi->uSerialPort3Dropdown->Reset(defaults::SERIAL_PORT_3);
    mUi->uBaudrate3Dropdown->Reset(defaults::BAUDRATE_3);
    mUi->uBluetoothBox->setChecked(defaults::BLUETOOTH);
    mUi->uCustomMachineNameEdit->setText(defaults::CUSTOM_MACHINE_NAME);
    mUi->uMachineUuidEdit->setText(defaults::MACHINE_UUID);
    mUi->uSerialPort2Box->setChecked(defaults::ENABLE_SERIAL_PORT_2);
    mUi->uBaudrate2Box->setChecked(defaults::ENABLE_BAUDRATE_2);
    mUi->uSerialPort3Box->setChecked(defaults::ENABLE_SERIAL_PORT_3);
    mUi->uBaudrate3Box->setChecked(defaults::ENABLE_BAUDRATE_3);
    mUi->uCustomMachineNameBox->setChecked(defaults::ENABLE_CUSTOM_MACHINE_NAME);
    mUi->uMachineUuidBox->setChecked(defaults::ENABLE_MACHINE_UUID);

    mUi->uMotherBoardSearchBox->clear();
    mUi->uEnvironmentSearchBox->clear();

    mIsLoading = false;
}

bool HardwarePage::LoadFromJson(const QJsonObject &pJson)
{
    bool success = true;
    mIsLoading = true;

    success &= LoadConfig(mUi->uEnvironmentDropdown, pJson, "ENVIRONMENT");
    success &= LoadConfig(mUi->uMotherboardDropdown, pJson, "MOTHERBOARD");
    success &= LoadConfig(mUi->uSerialPortDropdown, pJson, "SERIAL_PORT");
    success &= LoadConfig(mUi->uBaudrateDropdown, pJson, "BAUDRATE");
    success &= LoadConfig(mUi->uBaudRateGcodeBox, pJson, "BAUD_RATE_GCODE");
    success &= LoadConfig(mUi->uSerialPort2Dropdown, pJson, "SERIAL_PORT_2");
    success &= LoadConfig(mUi->uBaudrate2Dropdown, pJson, "BAUDRATE_2");
    success &= LoadConfig(mUi->uSerialPort3Dropdown, pJson, "SERIAL_PORT_3");
    success &= LoadConfig(mUi->uBaudrate3Dropdown, pJson, "BAUDRATE_3");
    success &= LoadConfig(mUi->uBluetoothBox, pJson, "BLUETOOTH");
    success &= LoadConfig(mUi->uCustomMachineNameEdit, pJson, "CUSTOM_MACHINE_NAME");
    success &= LoadConfig(mUi->uMachineUuidEdit, pJson, "MACHINE_UUID");
    success &= LoadConfig(mUi->uSerialPort2Box, pJson, "ENABLE_SERIAL_PORT_2");
    success &= LoadConfig(mUi->uBaudrate2Box, pJson, "ENABLE_BAUDRATE_2");
    success &= LoadConfig(mUi->uSerialPort3Box, pJson, "ENABLE_SERIAL_PORT_3");
    success &= LoadConfig(mUi->uBaudrate3Box, pJson, "ENABLE_BAUDRATE_3");
    success &= LoadConfig(mUi->uCustomMachineNameBox, pJson, "ENABLE_CUSTOM_MACHINE_NAME");
    success &= LoadConfig(mUi->uMachineUuidBox, pJson, "ENABLE_MACHINE_UUID");

    mIsLoading = false;
    return success;
}

void HardwarePage::FetchConfiguration(Configuration& pConfig)
{
    SetConfig(pConfig.hardware.ENVIRONMENT, mUi->uEnvironmentDropdown);
    SetConfig(pConfig.hardware.MOTHERBOARD, mUi->uMotherboardDropdown);
    SetConfig(pConfig.hardware.SERIAL_PORT, mUi->uSerialPortDropdown);
    SetConfig(pConfig.hardware.BAUDRATE, mUi->uBaudrateDropdown);
    SetConfig(pConfig.hardware.BAUD_RATE_GCODE, mUi->uBaudRateGcodeBox);
    SetConfig(pConfig.hardware.SERIAL_PORT_2, mUi->uSerialPort2Dropdown);
    SetConfig(pConfig.hardware.BAUDRATE_2, mUi->uBaudrate2Dropdown);
    SetConfig(pConfig.hardware.SERIAL_PORT_3, mUi->uSerialPort3Dropdown);
    SetConfig(pConfig.hardware.BAUDRATE_3, mUi->uBaudrate3Dropdown);
    SetConfig(pConfig.hardware.BLUETOOTH, mUi->uBluetoothBox);
    SetConfig(pConfig.hardware.CUSTOM_MACHINE_NAME, mUi->uCustomMachineNameEdit);
    SetConfig(pConfig.hardware.MACHINE_UUID, mUi->uMachineUuidEdit);
    SetConfig(pConfig.hardware.ENABLE_SERIAL_PORT_2, mUi->uSerialPort2Box);
    SetConfig(pConfig.hardware.ENABLE_BAUDRATE_2, mUi->uBaudrate2Box);
    SetConfig(pConfig.hardware.ENABLE_SERIAL_PORT_3, mUi->uSerialPort3Box);
    SetConfig(pConfig.hardware.ENABLE_BAUDRATE_3, mUi->uBaudrate3Box);
    SetConfig(pConfig.hardware.ENABLE_CUSTOM_MACHINE_NAME, mUi->uCustomMachineNameBox);
    SetConfig(pConfig.hardware.ENABLE_MACHINE_UUID, mUi->uMachineUuidBox);
}

void HardwarePage::ReplaceTags(QStringList& pOutput)
{
    ReplaceTag(pOutput, "#{MOTHERBOARD}", mUi->uMotherboardDropdown, false, "MOTHERBOARD", true);
    ReplaceTag(pOutput, "#{SERIAL_PORT}", mUi->uSerialPortDropdown, false, "SERIAL_PORT");
    ReplaceTag(pOutput, "#{BAUDRATE}", mUi->uBaudrateDropdown, false, "BAUDRATE");
    ReplaceTag(pOutput, "#{BAUD_RATE_GCODE}", mUi->uBaudRateGcodeBox, "BAUD_RATE_GCODE");
    ReplaceTag(pOutput, "#{SERIAL_PORT_2}", mUi->uSerialPort2Dropdown, !mUi->uSerialPort2Box->isChecked(), "SERIAL_PORT_2");
    ReplaceTag(pOutput, "#{BAUDRATE_2}", mUi->uBaudrate2Dropdown, !mUi->uBaudrate2Box->isChecked() || !mUi->uBaudrate2Box->isEnabled(), "BAUDRATE_2");
    ReplaceTag(pOutput, "#{SERIAL_PORT_3}", mUi->uSerialPort3Dropdown, !mUi->uSerialPort3Box->isChecked(), "SERIAL_PORT_3");
    ReplaceTag(pOutput, "#{BAUDRATE_3}", mUi->uBaudrate3Dropdown, !mUi->uBaudrate3Box->isChecked() || !mUi->uBaudrate3Box->isEnabled(), "BAUDRATE_3");
    ReplaceTag(pOutput, "#{BLUETOOTH}", mUi->uBluetoothBox, "BLUETOOTH");
    ReplaceTag(pOutput, "#{CUSTOM_MACHINE_NAME}", mUi->uCustomMachineNameEdit, !mUi->uCustomMachineNameBox->isChecked(), "CUSTOM_MACHINE_NAME", true);
    ReplaceTag(pOutput, "#{MACHINE_UUID}", mUi->uMachineUuidEdit, !mUi->uMachineUuidBox->isChecked(), "MACHINE_UUID", true);
}

QString HardwarePage::GetEnvironment(void) const
{
    return mUi->uEnvironmentDropdown->currentText();
}
