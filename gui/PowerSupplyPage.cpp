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
    QWidget(pParent),
    mUi(new Ui::PowerSupplyPage)
{
    mUi->setupUi(this);

    ConnectGuiSignalsAndSlots();
    ResetValues();
}

PowerSupplyPage::~PowerSupplyPage()
{
    delete mUi;
}

void PowerSupplyPage::ConnectGuiSignalsAndSlots()
{
    QObject::connect(mUi->uPsuControlCheckBox, &QCheckBox::stateChanged, this, [&](auto pState)
    {
        mUi->uMksPwcCheckBox->setEnabled(pState > 0);
        mUi->uPsOffConfirmCheckBox->setEnabled(pState > 0);
        mUi->uPsOffSoundCheckBox->setEnabled(pState > 0);
        mUi->uPsuActiveStateComboBox->setEnabled(pState > 0);
        mUi->uPsuDefaultOffCheckBox->setEnabled(pState > 0);
        mUi->uPsuPowerUpDelayEdit->setEnabled(pState > 0);
        mUi->uLedPowerOffTimeoutEdit->setEnabled(pState > 0);
        mUi->uPowerOffTimerCheckBox->setEnabled(pState > 0);
        mUi->uPowerOffWaitForCooldownCheckBox->setEnabled(pState > 0);
        mUi->uPsuPowerUpCodeEdit->setEnabled(pState > 0);
        mUi->uPsuPowerOffCodeEdit->setEnabled(pState > 0);
        mUi->uAutoPowerControlCheckBox->setEnabled(pState > 0);

        mUi->uAutoPowerFansCheckBox->setEnabled(pState > 0 && mUi->uAutoPowerControlCheckBox->isChecked());
        mUi->uAutoPowerEFansCheckBox->setEnabled(pState > 0 && mUi->uAutoPowerControlCheckBox->isChecked());
        mUi->uAutoPowerControllerFanCheckBox->setEnabled(pState > 0 && mUi->uAutoPowerControlCheckBox->isChecked());
        mUi->uAutoPowerChamberFanCheckBox->setEnabled(pState > 0 && mUi->uAutoPowerControlCheckBox->isChecked());
        mUi->uAutoPowerCoolerFanCheckBox->setEnabled(pState > 0 && mUi->uAutoPowerControlCheckBox->isChecked());
        mUi->uPowerTimeoutEdit->setEnabled(pState > 0 && mUi->uAutoPowerControlCheckBox->isChecked());
        mUi->uPowerOffDelayEdit->setEnabled(pState > 0 && mUi->uAutoPowerControlCheckBox->isChecked());

        mUi->uAutoPowerETempEdit->setEnabled(pState > 0 && (mUi->uAutoPowerControlCheckBox->isChecked() || mUi->uPowerOffWaitForCooldownCheckBox->isChecked()));
        mUi->uAutoPowerChamberTempEdit->setEnabled(pState > 0 && (mUi->uAutoPowerControlCheckBox->isChecked() || mUi->uPowerOffWaitForCooldownCheckBox->isChecked()));
        mUi->uAutoPowerCoolerTempEdit->setEnabled(pState > 0 && (mUi->uAutoPowerControlCheckBox->isChecked() || mUi->uPowerOffWaitForCooldownCheckBox->isChecked()));
    });

    QObject::connect(mUi->uAutoPowerControlCheckBox, &QCheckBox::stateChanged, this, [&](auto pState)
    {
        mUi->uAutoPowerFansCheckBox->setEnabled(pState > 0);
        mUi->uAutoPowerEFansCheckBox->setEnabled(pState > 0);
        mUi->uAutoPowerControllerFanCheckBox->setEnabled(pState > 0);
        mUi->uAutoPowerChamberFanCheckBox->setEnabled(pState > 0);
        mUi->uAutoPowerCoolerFanCheckBox->setEnabled(pState > 0);
        mUi->uPowerTimeoutEdit->setEnabled(pState > 0);
        mUi->uPowerOffDelayEdit->setEnabled(pState > 0);

        mUi->uAutoPowerETempEdit->setEnabled(pState > 0 || mUi->uPowerOffWaitForCooldownCheckBox->isChecked());
        mUi->uAutoPowerChamberTempEdit->setEnabled(pState > 0 || mUi->uPowerOffWaitForCooldownCheckBox->isChecked());
        mUi->uAutoPowerCoolerTempEdit->setEnabled(pState > 0 || mUi->uPowerOffWaitForCooldownCheckBox->isChecked());
    });

    QObject::connect(mUi->uPowerOffWaitForCooldownCheckBox, &QCheckBox::stateChanged, this, [&](auto pState)
    {
        mUi->uAutoPowerETempEdit->setEnabled(pState > 0 || mUi->uAutoPowerControlCheckBox->isChecked());
        mUi->uAutoPowerChamberTempEdit->setEnabled(pState > 0 || mUi->uAutoPowerControlCheckBox->isChecked());
        mUi->uAutoPowerCoolerTempEdit->setEnabled(pState > 0 || mUi->uAutoPowerControlCheckBox->isChecked());
    });
}

void PowerSupplyPage::ResetValues()
{
    mUi->uPsuControlCheckBox->setChecked(defaults::PSU_CONTROL);
    mUi->uPsuNameEdit->setText(defaults::PSU_NAME);
    mUi->uMksPwcCheckBox->setChecked(defaults::MKS_PWC);
    mUi->uPsOffConfirmCheckBox->setChecked(defaults::PS_OFF_CONFIRM);
    mUi->uPsOffSoundCheckBox->setChecked(defaults::PS_OFF_SOUND);
    mUi->uPsuActiveStateComboBox->setCurrentText(defaults::PSU_ACTIVE_STATE);
    mUi->uPsuDefaultOffCheckBox->setChecked(defaults::PSU_DEFAULT_OFF);
    mUi->uPsuPowerUpDelayEdit->setValue(defaults::PSU_POWERUP_DELAY);
    mUi->uLedPowerOffTimeoutEdit->setValue(defaults::LED_POWEROFF_TIMEOUT);
    mUi->uPowerOffTimerCheckBox->setChecked(defaults::POWER_OFF_TIMER);
    mUi->uPowerOffWaitForCooldownCheckBox->setChecked(defaults::POWER_OFF_WAIT_FOR_COOLDOWN);
    mUi->uPsuPowerUpCodeEdit->setText(defaults::PSU_POWERUP_GCODE);
    mUi->uPsuPowerOffCodeEdit->setText(defaults::PSU_POWEROFF_GCODE);
    mUi->uAutoPowerControlCheckBox->setChecked(defaults::AUTO_POWER_CONTROL);
    mUi->uAutoPowerFansCheckBox->setChecked(defaults::AUTO_POWER_FANS);
    mUi->uAutoPowerEFansCheckBox->setChecked(defaults::AUTO_POWER_E_FANS);
    mUi->uAutoPowerControllerFanCheckBox->setChecked(defaults::AUTO_POWER_CONTROLLERFAN);
    mUi->uAutoPowerChamberFanCheckBox->setChecked(defaults::AUTO_POWER_CHAMBER_FAN);
    mUi->uAutoPowerCoolerFanCheckBox->setChecked(defaults::AUTO_POWER_COOLER_FAN);
    mUi->uPowerTimeoutEdit->setValue(defaults::POWER_TIMEOUT);
    mUi->uPowerOffDelayEdit->setValue(defaults::POWER_OFF_DELAY);
    mUi->uAutoPowerETempEdit->setValue(defaults::AUTO_POWER_E_TEMP);
    mUi->uAutoPowerChamberTempEdit->setValue(defaults::AUTO_POWER_CHAMBER_TEMP);
    mUi->uAutoPowerCoolerTempEdit->setValue(defaults::AUTO_POWER_COOLER_TEMP);
}

bool PowerSupplyPage::LoadFromJson(const QJsonObject &pJson)
{
    bool success = true;

    success &= LoadConfig(mUi->uPsuControlCheckBox, pJson, "PSU_CONTROL");
    success &= LoadConfig(mUi->uPsuNameEdit, pJson, "PSU_NAME");
    success &= LoadConfig(mUi->uMksPwcCheckBox, pJson, "MKS_PWC");
    success &= LoadConfig(mUi->uPsOffConfirmCheckBox, pJson, "PS_OFF_CONFIRM");
    success &= LoadConfig(mUi->uPsOffSoundCheckBox, pJson, "PS_OFF_SOUND");
    success &= LoadConfig(mUi->uPsuActiveStateComboBox, pJson, "PSU_ACTIVE_STATE");
    success &= LoadConfig(mUi->uPsuDefaultOffCheckBox, pJson, "PSU_DEFAULT_OFF");
    success &= LoadConfig(mUi->uPsuPowerUpDelayEdit, pJson, "PSU_POWERUP_DELAY");
    success &= LoadConfig(mUi->uLedPowerOffTimeoutEdit, pJson, "LED_POWEROFF_TIMEOUT");
    success &= LoadConfig(mUi->uPowerOffTimerCheckBox, pJson, "POWER_OFF_TIMER");
    success &= LoadConfig(mUi->uPowerOffWaitForCooldownCheckBox, pJson, "POWER_OFF_WAIT_FOR_COOLDOWN");
    success &= LoadConfig(mUi->uPsuPowerUpCodeEdit, pJson, "PSU_POWERUP_GCODE");
    success &= LoadConfig(mUi->uPsuPowerOffCodeEdit, pJson, "PSU_POWEROFF_GCODE");
    success &= LoadConfig(mUi->uAutoPowerControlCheckBox, pJson, "AUTO_POWER_CONTROL");
    success &= LoadConfig(mUi->uAutoPowerFansCheckBox, pJson, "AUTO_POWER_FANS");
    success &= LoadConfig(mUi->uAutoPowerEFansCheckBox, pJson, "AUTO_POWER_E_FANS");
    success &= LoadConfig(mUi->uAutoPowerControllerFanCheckBox, pJson, "AUTO_POWER_CONTROLLERFAN");
    success &= LoadConfig(mUi->uAutoPowerChamberFanCheckBox, pJson, "AUTO_POWER_CHAMBER_FAN");
    success &= LoadConfig(mUi->uAutoPowerCoolerFanCheckBox, pJson, "AUTO_POWER_COOLER_FAN");
    success &= LoadConfig(mUi->uPowerTimeoutEdit, pJson, "POWER_TIMEOUT");
    success &= LoadConfig(mUi->uPowerOffDelayEdit, pJson, "POWER_OFF_DELAY");
    success &= LoadConfig(mUi->uAutoPowerETempEdit, pJson, "AUTO_POWER_E_TEMP");
    success &= LoadConfig(mUi->uAutoPowerChamberTempEdit, pJson, "AUTO_POWER_CHAMBER_TEMP");
    success &= LoadConfig(mUi->uAutoPowerCoolerTempEdit, pJson, "AUTO_POWER_COOLER_TEMP");

    return success;
}

void PowerSupplyPage::FetchConfiguration(Configuration& pConfig)
{
    SetConfig(pConfig.powerSupply.PSU_CONTROL, mUi->uPsuControlCheckBox);
    SetConfig(pConfig.powerSupply.PSU_NAME, mUi->uPsuNameEdit);
    SetConfig(pConfig.powerSupply.MKS_PWC, mUi->uMksPwcCheckBox);
    SetConfig(pConfig.powerSupply.PS_OFF_CONFIRM, mUi->uPsOffConfirmCheckBox);
    SetConfig(pConfig.powerSupply.PS_OFF_SOUND, mUi->uPsOffSoundCheckBox);
    SetConfig(pConfig.powerSupply.PSU_ACTIVE_STATE, mUi->uPsuActiveStateComboBox);
    SetConfig(pConfig.powerSupply.PSU_DEFAULT_OFF, mUi->uPsuDefaultOffCheckBox);
    SetConfig(pConfig.powerSupply.PSU_POWERUP_DELAY, mUi->uPsuPowerUpDelayEdit);
    SetConfig(pConfig.powerSupply.LED_POWEROFF_TIMEOUT, mUi->uLedPowerOffTimeoutEdit);
    SetConfig(pConfig.powerSupply.POWER_OFF_TIMER, mUi->uPowerOffTimerCheckBox);
    SetConfig(pConfig.powerSupply.POWER_OFF_WAIT_FOR_COOLDOWN, mUi->uPowerOffWaitForCooldownCheckBox);
    SetConfig(pConfig.powerSupply.PSU_POWERUP_GCODE, mUi->uPsuPowerUpCodeEdit);
    SetConfig(pConfig.powerSupply.PSU_POWEROFF_GCODE, mUi->uPsuPowerOffCodeEdit);
    SetConfig(pConfig.powerSupply.AUTO_POWER_CONTROL, mUi->uAutoPowerControlCheckBox);
    SetConfig(pConfig.powerSupply.AUTO_POWER_FANS, mUi->uAutoPowerFansCheckBox);
    SetConfig(pConfig.powerSupply.AUTO_POWER_E_FANS, mUi->uAutoPowerEFansCheckBox);
    SetConfig(pConfig.powerSupply.AUTO_POWER_CONTROLLERFAN, mUi->uAutoPowerControllerFanCheckBox);
    SetConfig(pConfig.powerSupply.AUTO_POWER_CHAMBER_FAN, mUi->uAutoPowerChamberFanCheckBox);
    SetConfig(pConfig.powerSupply.AUTO_POWER_COOLER_FAN, mUi->uAutoPowerCoolerFanCheckBox);
    SetConfig(pConfig.powerSupply.POWER_TIMEOUT, mUi->uPowerTimeoutEdit);
    SetConfig(pConfig.powerSupply.POWER_OFF_DELAY, mUi->uPowerOffDelayEdit);
    SetConfig(pConfig.powerSupply.AUTO_POWER_E_TEMP, mUi->uAutoPowerETempEdit);
    SetConfig(pConfig.powerSupply.AUTO_POWER_CHAMBER_TEMP, mUi->uAutoPowerChamberTempEdit);
    SetConfig(pConfig.powerSupply.AUTO_POWER_COOLER_TEMP, mUi->uAutoPowerCoolerTempEdit);
}
