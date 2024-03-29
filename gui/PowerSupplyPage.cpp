/*!
 * \file PowerSupplyPage.cpp
 * \brief The PowerSupplyPage class represents the power supply page
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


#include "PowerSupplyPage.h"
#include "./ui_PowerSupplyPage.h"
#include "HelperFunctions.h"

PowerSupplyPage::PowerSupplyPage(QWidget *pParent) :
    AbstractPage(POWERSUPPLY_TEMPLATE_PATH, pParent),
    mUi(new Ui::PowerSupplyPage)
{
    mUi->setupUi(this);
}

PowerSupplyPage::~PowerSupplyPage()
{
    delete mUi;
}

void PowerSupplyPage::ConnectGuiSignalsAndSlots()
{
    QObject::connect(mUi->uDocumentationButton, &QPushButton::clicked, this, [&]()
    {
        OpenMarlinDocumentation("power-supply");
    });

    QObject::connect(mUi->uAutoPowerControlBox, &QGroupBox::toggled, this, [&](auto pState)
    {
        mUi->uAutoPowerETempBox->setEnabled((pState || mUi->uPowerOffWaitForCooldownBox->isChecked()));
        mUi->uAutoPowerChamberTempBox->setEnabled((pState || mUi->uPowerOffWaitForCooldownBox->isChecked()));
        mUi->uAutoPowerCoolerTempBox->setEnabled((pState || mUi->uPowerOffWaitForCooldownBox->isChecked()));
    });

    QObject::connect(mUi->uPowerOffWaitForCooldownBox, &QGroupBox::toggled, this, [&](auto pState)
    {
         mUi->uAutoPowerETempBox->setEnabled((pState || mUi->uAutoPowerControlBox->isChecked()));
         mUi->uAutoPowerChamberTempBox->setEnabled((pState || mUi->uAutoPowerControlBox->isChecked()));
         mUi->uAutoPowerCoolerTempBox->setEnabled((pState || mUi->uAutoPowerControlBox->isChecked()));
    });

    AbstractPage::ConnectGuiSignalsAndSlots();
}

void PowerSupplyPage::ResetValues()
{
    mIsLoading = true;

    mUi->uPsuControlBox->setChecked(defaults::PSU_CONTROL);
    mUi->uPsuNameEdit->setText(defaults::PSU_NAME);
    mUi->uMksPwcBox->setChecked(defaults::MKS_PWC);
    mUi->uPsOffConfirmBox->setChecked(defaults::PS_OFF_CONFIRM);
    mUi->uPsOffSoundBox->setChecked(defaults::PS_OFF_SOUND);
    mUi->uPsuActiveStateDropdown->Reset(defaults::PSU_ACTIVE_STATE);
    mUi->uPsuDefaultOffBox->setChecked(defaults::PSU_DEFAULT_OFF);
    mUi->uPsuPowerupDelaySpinBox->setValue(defaults::PSU_POWERUP_DELAY);
    mUi->uLedPoweroffTimeoutSpinBox->setValue(defaults::LED_POWEROFF_TIMEOUT);
    mUi->uPowerOffTimerBox->setChecked(defaults::POWER_OFF_TIMER);
    mUi->uPowerOffWaitForCooldownBox->setChecked(defaults::POWER_OFF_WAIT_FOR_COOLDOWN);
    mUi->uPsuPowerupGcodeEdit->setText(defaults::PSU_POWERUP_GCODE);
    mUi->uPsuPoweroffGcodeEdit->setText(defaults::PSU_POWEROFF_GCODE);
    mUi->uAutoPowerControlBox->setChecked(defaults::AUTO_POWER_CONTROL);
    mUi->uAutoPowerFansBox->setChecked(defaults::AUTO_POWER_FANS);
    mUi->uAutoPowerEFansBox->setChecked(defaults::AUTO_POWER_E_FANS);
    mUi->uAutoPowerControllerfanBox->setChecked(defaults::AUTO_POWER_CONTROLLERFAN);
    mUi->uAutoPowerChamberFanBox->setChecked(defaults::AUTO_POWER_CHAMBER_FAN);
    mUi->uAutoPowerCoolerFanBox->setChecked(defaults::AUTO_POWER_COOLER_FAN);
    mUi->uPowerTimeoutSpinBox->setValue(defaults::POWER_TIMEOUT);
    mUi->uPowerOffDelaySpinBox->setValue(defaults::POWER_OFF_DELAY);
    mUi->uAutoPowerETempSpinBox->setValue(defaults::AUTO_POWER_E_TEMP);
    mUi->uAutoPowerChamberTempSpinBox->setValue(defaults::AUTO_POWER_CHAMBER_TEMP);
    mUi->uAutoPowerCoolerTempSpinBox->setValue(defaults::AUTO_POWER_COOLER_TEMP);
    mUi->uPsuNameBox->setChecked(defaults::ENABLE_PSU_NAME);
    mUi->uPsuPowerupDelayBox->setChecked(defaults::ENABLE_PSU_POWERUP_DELAY);
    mUi->uLedPoweroffTimeoutBox->setChecked(defaults::ENABLE_LED_POWEROFF_TIMEOUT);
    mUi->uPsuPowerupGcodeBox->setChecked(defaults::ENABLE_PSU_POWERUP_GCODE);
    mUi->uPsuPoweroffGcodeBox->setChecked(defaults::ENABLE_PSU_POWEROFF_GCODE);
    mUi->uPowerTimeoutBox->setChecked(defaults::ENABLE_POWER_TIMEOUT);
    mUi->uPowerOffDelayBox->setChecked(defaults::ENABLE_POWER_OFF_DELAY);
    mUi->uAutoPowerETempBox->setChecked(defaults::ENABLE_AUTO_POWER_E_TEMP);
    mUi->uAutoPowerChamberTempBox->setChecked(defaults::ENABLE_AUTO_POWER_CHAMBER_TEMP);
    mUi->uAutoPowerCoolerTempBox->setChecked(defaults::ENABLE_AUTO_POWER_COOLER_TEMP);

    mIsLoading = false;
}

bool PowerSupplyPage::LoadFromJson(const QJsonObject &pJson)
{
    bool success = true;
    mIsLoading = true;

    success &= LoadConfig(mUi->uPsuControlBox, pJson, "PSU_CONTROL");
    success &= LoadConfig(mUi->uPsuNameEdit, pJson, "PSU_NAME");
    success &= LoadConfig(mUi->uMksPwcBox, pJson, "MKS_PWC");
    success &= LoadConfig(mUi->uPsOffConfirmBox, pJson, "PS_OFF_CONFIRM");
    success &= LoadConfig(mUi->uPsOffSoundBox, pJson, "PS_OFF_SOUND");
    success &= LoadConfig(mUi->uPsuActiveStateDropdown, pJson, "PSU_ACTIVE_STATE");
    success &= LoadConfig(mUi->uPsuDefaultOffBox, pJson, "PSU_DEFAULT_OFF");
    success &= LoadConfig(mUi->uPsuPowerupDelaySpinBox, pJson, "PSU_POWERUP_DELAY");
    success &= LoadConfig(mUi->uLedPoweroffTimeoutSpinBox, pJson, "LED_POWEROFF_TIMEOUT");
    success &= LoadConfig(mUi->uPowerOffTimerBox, pJson, "POWER_OFF_TIMER");
    success &= LoadConfig(mUi->uPowerOffWaitForCooldownBox, pJson, "POWER_OFF_WAIT_FOR_COOLDOWN");
    success &= LoadConfig(mUi->uPsuPowerupGcodeEdit, pJson, "PSU_POWERUP_GCODE");
    success &= LoadConfig(mUi->uPsuPoweroffGcodeEdit, pJson, "PSU_POWEROFF_GCODE");
    success &= LoadConfig(mUi->uAutoPowerControlBox, pJson, "AUTO_POWER_CONTROL");
    success &= LoadConfig(mUi->uAutoPowerFansBox, pJson, "AUTO_POWER_FANS");
    success &= LoadConfig(mUi->uAutoPowerEFansBox, pJson, "AUTO_POWER_E_FANS");
    success &= LoadConfig(mUi->uAutoPowerControllerfanBox, pJson, "AUTO_POWER_CONTROLLERFAN");
    success &= LoadConfig(mUi->uAutoPowerChamberFanBox, pJson, "AUTO_POWER_CHAMBER_FAN");
    success &= LoadConfig(mUi->uAutoPowerCoolerFanBox, pJson, "AUTO_POWER_COOLER_FAN");
    success &= LoadConfig(mUi->uPowerTimeoutSpinBox, pJson, "POWER_TIMEOUT");
    success &= LoadConfig(mUi->uPowerOffDelaySpinBox, pJson, "POWER_OFF_DELAY");
    success &= LoadConfig(mUi->uAutoPowerETempSpinBox, pJson, "AUTO_POWER_E_TEMP");
    success &= LoadConfig(mUi->uAutoPowerChamberTempSpinBox, pJson, "AUTO_POWER_CHAMBER_TEMP");
    success &= LoadConfig(mUi->uAutoPowerCoolerTempSpinBox, pJson, "AUTO_POWER_COOLER_TEMP");
    success &= LoadConfig(mUi->uPsuNameBox, pJson, "ENABLE_PSU_NAME");
    success &= LoadConfig(mUi->uPsuPowerupDelayBox, pJson, "ENABLE_PSU_POWERUP_DELAY");
    success &= LoadConfig(mUi->uLedPoweroffTimeoutBox, pJson, "ENABLE_LED_POWEROFF_TIMEOUT");
    success &= LoadConfig(mUi->uPsuPowerupGcodeBox, pJson, "ENABLE_PSU_POWERUP_GCODE");
    success &= LoadConfig(mUi->uPsuPoweroffGcodeBox, pJson, "ENABLE_PSU_POWEROFF_GCODE");
    success &= LoadConfig(mUi->uPowerTimeoutBox, pJson, "ENABLE_POWER_TIMEOUT");
    success &= LoadConfig(mUi->uPowerOffDelayBox, pJson, "ENABLE_POWER_OFF_DELAY");
    success &= LoadConfig(mUi->uAutoPowerETempBox, pJson, "ENABLE_AUTO_POWER_E_TEMP");
    success &= LoadConfig(mUi->uAutoPowerChamberTempBox, pJson, "ENABLE_AUTO_POWER_CHAMBER_TEMP");
    success &= LoadConfig(mUi->uAutoPowerCoolerTempBox, pJson, "ENABLE_AUTO_POWER_COOLER_TEMP");

    mIsLoading = false;
    return success;
}

void PowerSupplyPage::FetchConfiguration(Configuration& pConfig)
{
    SetConfig(pConfig.powerSupply.PSU_CONTROL, mUi->uPsuControlBox);
    SetConfig(pConfig.powerSupply.PSU_NAME, mUi->uPsuNameEdit);
    SetConfig(pConfig.powerSupply.MKS_PWC, mUi->uMksPwcBox);
    SetConfig(pConfig.powerSupply.PS_OFF_CONFIRM, mUi->uPsOffConfirmBox);
    SetConfig(pConfig.powerSupply.PS_OFF_SOUND, mUi->uPsOffSoundBox);
    SetConfig(pConfig.powerSupply.PSU_ACTIVE_STATE, mUi->uPsuActiveStateDropdown);
    SetConfig(pConfig.powerSupply.PSU_DEFAULT_OFF, mUi->uPsuDefaultOffBox);
    SetConfig(pConfig.powerSupply.PSU_POWERUP_DELAY, mUi->uPsuPowerupDelaySpinBox);
    SetConfig(pConfig.powerSupply.LED_POWEROFF_TIMEOUT, mUi->uLedPoweroffTimeoutSpinBox);
    SetConfig(pConfig.powerSupply.POWER_OFF_TIMER, mUi->uPowerOffTimerBox);
    SetConfig(pConfig.powerSupply.POWER_OFF_WAIT_FOR_COOLDOWN, mUi->uPowerOffWaitForCooldownBox);
    SetConfig(pConfig.powerSupply.PSU_POWERUP_GCODE, mUi->uPsuPowerupGcodeEdit);
    SetConfig(pConfig.powerSupply.PSU_POWEROFF_GCODE, mUi->uPsuPoweroffGcodeEdit);
    SetConfig(pConfig.powerSupply.AUTO_POWER_CONTROL, mUi->uAutoPowerControlBox);
    SetConfig(pConfig.powerSupply.AUTO_POWER_FANS, mUi->uAutoPowerFansBox);
    SetConfig(pConfig.powerSupply.AUTO_POWER_E_FANS, mUi->uAutoPowerEFansBox);
    SetConfig(pConfig.powerSupply.AUTO_POWER_CONTROLLERFAN, mUi->uAutoPowerControllerfanBox);
    SetConfig(pConfig.powerSupply.AUTO_POWER_CHAMBER_FAN, mUi->uAutoPowerChamberFanBox);
    SetConfig(pConfig.powerSupply.AUTO_POWER_COOLER_FAN, mUi->uAutoPowerCoolerFanBox);
    SetConfig(pConfig.powerSupply.POWER_TIMEOUT, mUi->uPowerTimeoutSpinBox);
    SetConfig(pConfig.powerSupply.POWER_OFF_DELAY, mUi->uPowerOffDelaySpinBox);
    SetConfig(pConfig.powerSupply.AUTO_POWER_E_TEMP, mUi->uAutoPowerETempSpinBox);
    SetConfig(pConfig.powerSupply.AUTO_POWER_CHAMBER_TEMP, mUi->uAutoPowerChamberTempSpinBox);
    SetConfig(pConfig.powerSupply.AUTO_POWER_COOLER_TEMP, mUi->uAutoPowerCoolerTempSpinBox);
    SetConfig(pConfig.powerSupply.ENABLE_PSU_NAME, mUi->uPsuNameBox);
    SetConfig(pConfig.powerSupply.ENABLE_PSU_POWERUP_DELAY, mUi->uPsuPowerupDelayBox);
    SetConfig(pConfig.powerSupply.ENABLE_LED_POWEROFF_TIMEOUT, mUi->uLedPoweroffTimeoutBox);
    SetConfig(pConfig.powerSupply.ENABLE_PSU_POWERUP_GCODE, mUi->uPsuPowerupGcodeBox);
    SetConfig(pConfig.powerSupply.ENABLE_PSU_POWEROFF_GCODE, mUi->uPsuPoweroffGcodeBox);
    SetConfig(pConfig.powerSupply.ENABLE_POWER_TIMEOUT, mUi->uPowerTimeoutBox);
    SetConfig(pConfig.powerSupply.ENABLE_POWER_OFF_DELAY, mUi->uPowerOffDelayBox);
    SetConfig(pConfig.powerSupply.ENABLE_AUTO_POWER_E_TEMP, mUi->uAutoPowerETempBox);
    SetConfig(pConfig.powerSupply.ENABLE_AUTO_POWER_CHAMBER_TEMP, mUi->uAutoPowerChamberTempBox);
    SetConfig(pConfig.powerSupply.ENABLE_AUTO_POWER_COOLER_TEMP, mUi->uAutoPowerCoolerTempBox);
}

void PowerSupplyPage::ReplaceTags(QStringList& pOutput)
{
    ReplaceTag(pOutput, "#{PSU_CONTROL}", mUi->uPsuControlBox, "PSU_CONTROL");
    ReplaceTag(pOutput, "#{PSU_NAME}", mUi->uPsuNameEdit, !mUi->uPsuNameBox->isChecked(), "PSU_NAME", true);
    ReplaceTag(pOutput, "#{MKS_PWC}", mUi->uMksPwcBox, "MKS_PWC");
    ReplaceTag(pOutput, "#{PS_OFF_CONFIRM}", mUi->uPsOffConfirmBox, "PS_OFF_CONFIRM");
    ReplaceTag(pOutput, "#{PS_OFF_SOUND}", mUi->uPsOffSoundBox, "PS_OFF_SOUND");
    ReplaceTag(pOutput, "#{PSU_ACTIVE_STATE}", mUi->uPsuActiveStateDropdown, false, "PSU_ACTIVE_STATE");
    ReplaceTag(pOutput, "#{PSU_DEFAULT_OFF}", mUi->uPsuDefaultOffBox, "PSU_DEFAULT_OFF");
    ReplaceTag(pOutput, "#{PSU_POWERUP_DELAY}", mUi->uPsuPowerupDelaySpinBox, !mUi->uPsuPowerupDelayBox->isChecked(), "PSU_POWERUP_DELAY");
    ReplaceTag(pOutput, "#{LED_POWEROFF_TIMEOUT}", mUi->uLedPoweroffTimeoutSpinBox, !mUi->uLedPoweroffTimeoutBox->isChecked(), "LED_POWEROFF_TIMEOUT");
    ReplaceTag(pOutput, "#{POWER_OFF_TIMER}", mUi->uPowerOffTimerBox, "POWER_OFF_TIMER");
    ReplaceTag(pOutput, "#{POWER_OFF_WAIT_FOR_COOLDOWN}", mUi->uPowerOffWaitForCooldownBox, "POWER_OFF_WAIT_FOR_COOLDOWN");
    ReplaceTag(pOutput, "#{PSU_POWERUP_GCODE}", mUi->uPsuPowerupGcodeEdit, !mUi->uPsuPowerupGcodeBox->isChecked(), "PSU_POWERUP_GCODE", true);
    ReplaceTag(pOutput, "#{PSU_POWEROFF_GCODE}", mUi->uPsuPoweroffGcodeEdit, !mUi->uPsuPoweroffGcodeBox->isChecked(), "PSU_POWEROFF_GCODE", true);
    ReplaceTag(pOutput, "#{AUTO_POWER_CONTROL}", mUi->uAutoPowerControlBox, "AUTO_POWER_CONTROL");
    ReplaceTag(pOutput, "#{AUTO_POWER_FANS}", mUi->uAutoPowerFansBox, "AUTO_POWER_FANS");
    ReplaceTag(pOutput, "#{AUTO_POWER_E_FANS}", mUi->uAutoPowerEFansBox, "AUTO_POWER_E_FANS");
    ReplaceTag(pOutput, "#{AUTO_POWER_CONTROLLERFAN}", mUi->uAutoPowerControllerfanBox, "AUTO_POWER_CONTROLLERFAN");
    ReplaceTag(pOutput, "#{AUTO_POWER_CHAMBER_FAN}", mUi->uAutoPowerChamberFanBox, "AUTO_POWER_CHAMBER_FAN");
    ReplaceTag(pOutput, "#{AUTO_POWER_COOLER_FAN}", mUi->uAutoPowerCoolerFanBox, "AUTO_POWER_COOLER_FAN");
#warning Is POWER_TIMEOUT optional or always needed when AUTO_POWER_CONTROL is active?
    ReplaceTag(pOutput, "#{POWER_TIMEOUT}", mUi->uPowerTimeoutSpinBox, !mUi->uPowerTimeoutBox->isChecked(), "POWER_TIMEOUT");
    ReplaceTag(pOutput, "#{POWER_OFF_DELAY}", mUi->uPowerOffDelaySpinBox, !mUi->uPowerOffDelayBox->isChecked(), "POWER_OFF_DELAY");
    ReplaceTag(pOutput, "#{AUTO_POWER_E_TEMP}", mUi->uAutoPowerETempSpinBox, !mUi->uAutoPowerETempBox->isChecked(), "AUTO_POWER_E_TEMP");
    ReplaceTag(pOutput, "#{AUTO_POWER_CHAMBER_TEMP}", mUi->uAutoPowerChamberTempSpinBox, !mUi->uAutoPowerChamberTempBox->isChecked(), "AUTO_POWER_CHAMBER_TEMP");
    ReplaceTag(pOutput, "#{AUTO_POWER_COOLER_TEMP}", mUi->uAutoPowerCoolerTempSpinBox, !mUi->uAutoPowerCoolerTempBox->isChecked(), "AUTO_POWER_COOLER_TEMP");
}

