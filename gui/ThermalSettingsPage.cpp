/*!
 * \file ThermalSettingsPage.cpp
/// \brief The ThermalSettingsPage class represents the thermal settings page
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

#include "ThermalSettingsPage.h"
#include "./ui_ThermalSettingsPage.h"
#include "HelperFunctions.h"

ThermalSettingsPage::ThermalSettingsPage(QWidget *pParent) :
    AbstractPage(THERMALSETTINGS_TEMPLATE_PATH, pParent),
    mUi(new Ui::ThermalSettingsPage)
{
    mUi->setupUi(this);
}

ThermalSettingsPage::~ThermalSettingsPage()
{
    delete mUi;
}

void ThermalSettingsPage::ConnectGuiSignalsAndSlots()
{
    QObject::connect(mUi->uDocumentationButton, &QPushButton::clicked, this, [&]()
    {
        OpenMarlinDocumentation("thermal-settings");
    });

    QObject::connect(mUi->uTempSensor0Dropdown, &Dropdown::currentIndexChanged, this, [&](auto pIndex)
    {
        mUi->uMax31865SensorOhms0Box->setEnabled(pIndex <= 2);
        mUi->uMax31865CalibrationOhms0Box->setEnabled(pIndex <= 2);
    });

    QObject::connect(mUi->uTempSensor1Dropdown, &Dropdown::currentIndexChanged, this, [&](auto pIndex)
    {
        mUi->uMax31865SensorOhms1Box->setEnabled(pIndex <= 2);
        mUi->uMax31865CalibrationOhms1Box->setEnabled(pIndex <= 2);
    });

    QObject::connect(mUi->uTempSensor2Dropdown, &Dropdown::currentIndexChanged, this, [&](auto pIndex)
    {
        mUi->uMax31865SensorOhms2Box->setEnabled(pIndex <= 2);
        mUi->uMax31865CalibrationOhms2Box->setEnabled(pIndex <= 2);
    });

    QObject::connect(mUi->uTempSensor0Dropdown, &Dropdown::currentIndexChanged, this, [&]()
    {
        const bool hasETempSensor = (mUi->uTempSensor0Dropdown->currentIndex() != 53 || mUi->uTempSensor1Dropdown->currentIndex() != 53 || mUi->uTempSensor2Dropdown->currentIndex() != 53 || mUi->uTempSensor3Dropdown->currentIndex() != 53 &&
                                     mUi->uTempSensor4Dropdown->currentIndex() != 53 || mUi->uTempSensor5Dropdown->currentIndex() != 53 || mUi->uTempSensor6Dropdown->currentIndex() != 53 || mUi->uTempSensor7Dropdown->currentIndex() != 53);
        mUi->uTempResidencyTimeBox->setEnabled(hasETempSensor);
        mUi->uTempWindowBox->setEnabled(hasETempSensor);
        mUi->uTempHysteresisBox->setEnabled(hasETempSensor);
    });

    QObject::connect(mUi->uTempSensor1Dropdown, &Dropdown::currentIndexChanged, this, [&]()
    {
        const bool hasETempSensor = (mUi->uTempSensor0Dropdown->currentIndex() != 53 || mUi->uTempSensor1Dropdown->currentIndex() != 53 || mUi->uTempSensor2Dropdown->currentIndex() != 53 || mUi->uTempSensor3Dropdown->currentIndex() != 53 &&
                                     mUi->uTempSensor4Dropdown->currentIndex() != 53 || mUi->uTempSensor5Dropdown->currentIndex() != 53 || mUi->uTempSensor6Dropdown->currentIndex() != 53 || mUi->uTempSensor7Dropdown->currentIndex() != 53);
        mUi->uTempResidencyTimeBox->setEnabled(hasETempSensor);
        mUi->uTempWindowBox->setEnabled(hasETempSensor);
        mUi->uTempHysteresisBox->setEnabled(hasETempSensor);
    });

    QObject::connect(mUi->uTempSensor2Dropdown, &Dropdown::currentIndexChanged, this, [&]()
    {
        const bool hasETempSensor = (mUi->uTempSensor0Dropdown->currentIndex() != 53 || mUi->uTempSensor1Dropdown->currentIndex() != 53 || mUi->uTempSensor2Dropdown->currentIndex() != 53 || mUi->uTempSensor3Dropdown->currentIndex() != 53 &&
                                     mUi->uTempSensor4Dropdown->currentIndex() != 53 || mUi->uTempSensor5Dropdown->currentIndex() != 53 || mUi->uTempSensor6Dropdown->currentIndex() != 53 || mUi->uTempSensor7Dropdown->currentIndex() != 53);
        mUi->uTempResidencyTimeBox->setEnabled(hasETempSensor);
        mUi->uTempWindowBox->setEnabled(hasETempSensor);
        mUi->uTempHysteresisBox->setEnabled(hasETempSensor);
    });

    QObject::connect(mUi->uTempSensor3Dropdown, &Dropdown::currentIndexChanged, this, [&]()
    {
        const bool hasETempSensor = (mUi->uTempSensor0Dropdown->currentIndex() != 53 || mUi->uTempSensor1Dropdown->currentIndex() != 53 || mUi->uTempSensor2Dropdown->currentIndex() != 53 || mUi->uTempSensor3Dropdown->currentIndex() != 53 &&
                                     mUi->uTempSensor4Dropdown->currentIndex() != 53 || mUi->uTempSensor5Dropdown->currentIndex() != 53 || mUi->uTempSensor6Dropdown->currentIndex() != 53 || mUi->uTempSensor7Dropdown->currentIndex() != 53);
        mUi->uTempResidencyTimeBox->setEnabled(hasETempSensor);
        mUi->uTempWindowBox->setEnabled(hasETempSensor);
        mUi->uTempHysteresisBox->setEnabled(hasETempSensor);
});

    QObject::connect(mUi->uTempSensor4Dropdown, &Dropdown::currentIndexChanged, this, [&]()
    {
        const bool hasETempSensor = (mUi->uTempSensor0Dropdown->currentIndex() != 53 || mUi->uTempSensor1Dropdown->currentIndex() != 53 || mUi->uTempSensor2Dropdown->currentIndex() != 53 || mUi->uTempSensor3Dropdown->currentIndex() != 53 &&
                                     mUi->uTempSensor4Dropdown->currentIndex() != 53 || mUi->uTempSensor5Dropdown->currentIndex() != 53 || mUi->uTempSensor6Dropdown->currentIndex() != 53 || mUi->uTempSensor7Dropdown->currentIndex() != 53);
            mUi->uTempResidencyTimeBox->setEnabled(hasETempSensor);
            mUi->uTempWindowBox->setEnabled(hasETempSensor);
            mUi->uTempHysteresisBox->setEnabled(hasETempSensor);
    });

    QObject::connect(mUi->uTempSensor5Dropdown, &Dropdown::currentIndexChanged, this, [&]()
    {
        const bool hasETempSensor = (mUi->uTempSensor0Dropdown->currentIndex() != 53 || mUi->uTempSensor1Dropdown->currentIndex() != 53 || mUi->uTempSensor2Dropdown->currentIndex() != 53 || mUi->uTempSensor3Dropdown->currentIndex() != 53 &&
                                     mUi->uTempSensor4Dropdown->currentIndex() != 53 || mUi->uTempSensor5Dropdown->currentIndex() != 53 || mUi->uTempSensor6Dropdown->currentIndex() != 53 || mUi->uTempSensor7Dropdown->currentIndex() != 53);
        mUi->uTempResidencyTimeBox->setEnabled(hasETempSensor);
        mUi->uTempWindowBox->setEnabled(hasETempSensor);
        mUi->uTempHysteresisBox->setEnabled(hasETempSensor);
    });

    QObject::connect(mUi->uTempSensor6Dropdown, &Dropdown::currentIndexChanged, this, [&]()
    {
        const bool hasETempSensor = (mUi->uTempSensor0Dropdown->currentIndex() != 53 || mUi->uTempSensor1Dropdown->currentIndex() != 53 || mUi->uTempSensor2Dropdown->currentIndex() != 53 || mUi->uTempSensor3Dropdown->currentIndex() != 53 &&
                                     mUi->uTempSensor4Dropdown->currentIndex() != 53 || mUi->uTempSensor5Dropdown->currentIndex() != 53 || mUi->uTempSensor6Dropdown->currentIndex() != 53 || mUi->uTempSensor7Dropdown->currentIndex() != 53);
        mUi->uTempResidencyTimeBox->setEnabled(hasETempSensor);
        mUi->uTempWindowBox->setEnabled(hasETempSensor);
        mUi->uTempHysteresisBox->setEnabled(hasETempSensor);
    });

    QObject::connect(mUi->uTempSensor7Dropdown, &Dropdown::currentIndexChanged, this, [&]()
    {
        const bool hasETempSensor = (mUi->uTempSensor0Dropdown->currentIndex() != 53 || mUi->uTempSensor1Dropdown->currentIndex() != 53 || mUi->uTempSensor2Dropdown->currentIndex() != 53 || mUi->uTempSensor3Dropdown->currentIndex() != 53 &&
                                     mUi->uTempSensor4Dropdown->currentIndex() != 53 || mUi->uTempSensor5Dropdown->currentIndex() != 53 || mUi->uTempSensor6Dropdown->currentIndex() != 53 || mUi->uTempSensor7Dropdown->currentIndex() != 53);
        mUi->uTempResidencyTimeBox->setEnabled(hasETempSensor);
        mUi->uTempWindowBox->setEnabled(hasETempSensor);
        mUi->uTempHysteresisBox->setEnabled(hasETempSensor);
    });

    QObject::connect(mUi->uTempSensorBedDropdown, &Dropdown::currentIndexChanged, this, [&](auto pIndex)
    {
        mUi->uTempBedResidencyTimeBox->setEnabled(pIndex != 53);
        mUi->uTempBedWindowBox->setEnabled(pIndex != 53);
        mUi->uTempBedHysteresisBox->setEnabled(pIndex != 53);
    });

    QObject::connect(mUi->uTempSensorChamberDropdown, &Dropdown::currentIndexChanged, this, [&](auto pIndex)
    {
        mUi->uTempChamberResidencyTimeBox->setEnabled(pIndex != 53);
        mUi->uTempChamberWindowBox->setEnabled(pIndex != 53);
        mUi->uTempChamberHysteresisBox->setEnabled(pIndex != 53);
    });

    QObject::connect(mUi->uTempSensorRedundantDropdown, &Dropdown::currentIndexChanged, this, [&](auto pIndex)
    {
        mUi->uTempSensorRedundantSourceBox->setEnabled(pIndex != 53);
        mUi->uTempSensorRedundantTargetBox->setEnabled(pIndex != 53);
        mUi->uTempSensorRedundantMaxDiffBox->setEnabled(pIndex != 53);
    });

    QObject::connect(mUi->uPidParamsPerHotendBox, &QGroupBox::toggled, this, [&](auto pChecked)
    {
        mUi->uDefaultKpBox->setEnabled(!pChecked);
        mUi->uDefaultKiBox->setEnabled(!pChecked);
        mUi->uDefaultKdBox->setEnabled(!pChecked);
    });

    QObject::connect(mUi->uPidtempBox, &QGroupBox::toggled, this, [&](auto pChecked)
    {
        mUi->uPidOpenloopBox->setEnabled(pChecked || mUi->uPidtempbedBox->isChecked() || mUi->uPidtempchamberBox->isChecked());
        mUi->uSlowPwmHeatersBox->setEnabled(pChecked || mUi->uPidtempbedBox->isChecked() || mUi->uPidtempchamberBox->isChecked());
        mUi->uPidFunctionalRangeSpinBox->setEnabled(pChecked || mUi->uPidtempbedBox->isChecked() || mUi->uPidtempchamberBox->isChecked());
        mUi->uPidEditMenuBox->setEnabled(pChecked || mUi->uPidtempbedBox->isChecked() || mUi->uPidtempchamberBox->isChecked());
        mUi->uPidAutotuneMenuBox->setEnabled(pChecked || mUi->uPidtempbedBox->isChecked() || mUi->uPidtempchamberBox->isChecked());
    });

    QObject::connect(mUi->uPidtempbedBox, &QGroupBox::toggled, this, [&](auto pChecked)
    {
        mUi->uPidOpenloopBox->setEnabled(pChecked || mUi->uPidtempBox->isChecked() || mUi->uPidtempchamberBox->isChecked());
        mUi->uSlowPwmHeatersBox->setEnabled(pChecked || mUi->uPidtempBox->isChecked() || mUi->uPidtempchamberBox->isChecked());
        mUi->uPidFunctionalRangeSpinBox->setEnabled(pChecked || mUi->uPidtempBox->isChecked() || mUi->uPidtempchamberBox->isChecked());
        mUi->uPidEditMenuBox->setEnabled(pChecked || mUi->uPidtempBox->isChecked() || mUi->uPidtempchamberBox->isChecked());
        mUi->uPidAutotuneMenuBox->setEnabled(pChecked || mUi->uPidtempBox->isChecked() || mUi->uPidtempchamberBox->isChecked());
    });

    QObject::connect(mUi->uPidtempchamberBox, &QGroupBox::toggled, this, [&](auto pChecked)
    {
        mUi->uPidOpenloopBox->setEnabled(pChecked || mUi->uPidtempbedBox->isChecked() || mUi->uPidtempBox->isChecked());
        mUi->uSlowPwmHeatersBox->setEnabled(pChecked || mUi->uPidtempbedBox->isChecked() || mUi->uPidtempBox->isChecked());
        mUi->uPidFunctionalRangeSpinBox->setEnabled(pChecked || mUi->uPidtempbedBox->isChecked() || mUi->uPidtempBox->isChecked());
        mUi->uPidEditMenuBox->setEnabled(pChecked || mUi->uPidtempbedBox->isChecked() || mUi->uPidtempBox->isChecked());
        mUi->uPidAutotuneMenuBox->setEnabled(pChecked || mUi->uPidtempbedBox->isChecked() || mUi->uPidtempBox->isChecked());
    });

    AbstractPage::ConnectGuiSignalsAndSlots();
}

void ThermalSettingsPage::ResetValues()
{
    mIsLoading = true;

    mUi->uTempSensor0Dropdown->setCurrentText(defaults::TEMP_SENSOR_0);
    mUi->uTempSensor1Dropdown->setCurrentText(defaults::TEMP_SENSOR_1);
    mUi->uTempSensor2Dropdown->setCurrentText(defaults::TEMP_SENSOR_2);
    mUi->uTempSensor3Dropdown->setCurrentText(defaults::TEMP_SENSOR_3);
    mUi->uTempSensor4Dropdown->setCurrentText(defaults::TEMP_SENSOR_4);
    mUi->uTempSensor5Dropdown->setCurrentText(defaults::TEMP_SENSOR_5);
    mUi->uTempSensor6Dropdown->setCurrentText(defaults::TEMP_SENSOR_6);
    mUi->uTempSensor7Dropdown->setCurrentText(defaults::TEMP_SENSOR_7);
    mUi->uTempSensorBedDropdown->setCurrentText(defaults::TEMP_SENSOR_BED);
    mUi->uTempSensorProbeDropdown->setCurrentText(defaults::TEMP_SENSOR_PROBE);
    mUi->uTempSensorChamberDropdown->setCurrentText(defaults::TEMP_SENSOR_CHAMBER);
    mUi->uTempSensorCoolerDropdown->setCurrentText(defaults::TEMP_SENSOR_COOLER);
    mUi->uTempSensorBoardDropdown->setCurrentText(defaults::TEMP_SENSOR_BOARD);
    mUi->uTempSensorRedundantDropdown->setCurrentText(defaults::TEMP_SENSOR_REDUNDANT);
    mUi->uDummyThermistor998ValueSpinBox->setValue(defaults::DUMMY_THERMISTOR_998_VALUE);
    mUi->uDummyThermistor999ValueSpinBox->setValue(defaults::DUMMY_THERMISTOR_999_VALUE);
    mUi->uMax31865SensorOhms0SpinBox->setValue(defaults::MAX31865_SENSOR_OHMS_0);
    mUi->uMax31865CalibrationOhms0SpinBox->setValue(defaults::MAX31865_CALIBRATION_OHMS_0);
    mUi->uMax31865SensorOhms1SpinBox->setValue(defaults::MAX31865_SENSOR_OHMS_1);
    mUi->uMax31865CalibrationOhms1SpinBox->setValue(defaults::MAX31865_CALIBRATION_OHMS_1);
    mUi->uMax31865SensorOhms2SpinBox->setValue(defaults::MAX31865_SENSOR_OHMS_2);
    mUi->uMax31865CalibrationOhms2SpinBox->setValue(defaults::MAX31865_CALIBRATION_OHMS_2);
    mUi->uTempResidencyTimeSpinBox->setValue(defaults::TEMP_RESIDENCY_TIME);
    mUi->uTempWindowSpinBox->setValue(defaults::TEMP_WINDOW);
    mUi->uTempHysteresisSpinBox->setValue(defaults::TEMP_HYSTERESIS);
    mUi->uTempBedResidencyTimeSpinBox->setValue(defaults::TEMP_BED_RESIDENCY_TIME);
    mUi->uTempBedWindowSpinBox->setValue(defaults::TEMP_BED_WINDOW);
    mUi->uTempBedHysteresisSpinBox->setValue(defaults::TEMP_BED_HYSTERESIS);
    mUi->uTempChamberResidencyTimeSpinBox->setValue(defaults::TEMP_CHAMBER_RESIDENCY_TIME);
    mUi->uTempChamberWindowSpinBox->setValue(defaults::TEMP_CHAMBER_WINDOW);
    mUi->uTempChamberHysteresisSpinBox->setValue(defaults::TEMP_CHAMBER_HYSTERESIS);
    mUi->uTempSensorRedundantSourceDropdown->setCurrentText(defaults::TEMP_SENSOR_REDUNDANT_SOURCE);
    mUi->uTempSensorRedundantTargetDropdown->setCurrentText(defaults::TEMP_SENSOR_REDUNDANT_TARGET);
    mUi->uTempSensorRedundantMaxDiffSpinBox->setValue(defaults::TEMP_SENSOR_REDUNDANT_MAX_DIFF);
    mUi->uHeater0MintempSpinBox->setValue(defaults::HEATER_0_MINTEMP);
    mUi->uHeater1MintempSpinBox->setValue(defaults::HEATER_1_MINTEMP);
    mUi->uHeater2MintempSpinBox->setValue(defaults::HEATER_2_MINTEMP);
    mUi->uHeater3MintempSpinBox->setValue(defaults::HEATER_3_MINTEMP);
    mUi->uHeater4MintempSpinBox->setValue(defaults::HEATER_4_MINTEMP);
    mUi->uHeater5MintempSpinBox->setValue(defaults::HEATER_5_MINTEMP);
    mUi->uHeater6MintempSpinBox->setValue(defaults::HEATER_6_MINTEMP);
    mUi->uHeater7MintempSpinBox->setValue(defaults::HEATER_7_MINTEMP);
    mUi->uBedMintempSpinBox->setValue(defaults::BED_MINTEMP);
    mUi->uChamberMintempSpinBox->setValue(defaults::CHAMBER_MINTEMP);
    mUi->uHeater0MaxtempSpinBox->setValue(defaults::HEATER_0_MAXTEMP);
    mUi->uHeater1MaxtempSpinBox->setValue(defaults::HEATER_1_MAXTEMP);
    mUi->uHeater2MaxtempSpinBox->setValue(defaults::HEATER_2_MAXTEMP);
    mUi->uHeater3MaxtempSpinBox->setValue(defaults::HEATER_3_MAXTEMP);
    mUi->uHeater4MaxtempSpinBox->setValue(defaults::HEATER_4_MAXTEMP);
    mUi->uHeater5MaxtempSpinBox->setValue(defaults::HEATER_5_MAXTEMP);
    mUi->uHeater6MaxtempSpinBox->setValue(defaults::HEATER_6_MAXTEMP);
    mUi->uHeater7MaxtempSpinBox->setValue(defaults::HEATER_7_MAXTEMP);
    mUi->uBedMaxtempSpinBox->setValue(defaults::BED_MAXTEMP);
    mUi->uChamberMaxtempSpinBox->setValue(defaults::CHAMBER_MAXTEMP);
    mUi->uHotendOvershootSpinBox->setValue(defaults::HOTEND_OVERSHOOT);
    mUi->uBedOvershootSpinBox->setValue(defaults::BED_OVERSHOOT);
    mUi->uCoolerOvershootSpinBox->setValue(defaults::COOLER_OVERSHOOT);
    mUi->uPidtempBox->setChecked(defaults::PIDTEMP);
    mUi->uMpctempBox->setChecked(defaults::MPCTEMP);
    mUi->uBangMaxSpinBox->setValue(defaults::BANG_MAX);
    mUi->uPidMaxSpinBox->setValue(defaults::PID_MAX);
    mUi->uPidK1SpinBox->setValue(defaults::PID_K1);
    mUi->uPidDebugBox->setChecked(defaults::PID_DEBUG);
    mUi->uPidParamsPerHotendBox->setChecked(defaults::PID_PARAMS_PER_HOTEND);
    mUi->uDefaultKpListEdit->setText(defaults::DEFAULT_Kp_LIST);
    mUi->uDefaultKiListEdit->setText(defaults::DEFAULT_Ki_LIST);
    mUi->uDefaultKdListEdit->setText(defaults::DEFAULT_Kd_LIST);
    mUi->uDefaultKpSpinBox->setValue(defaults::DEFAULT_Kp);
    mUi->uDefaultKiSpinBox->setValue(defaults::DEFAULT_Ki);
    mUi->uDefaultKdSpinBox->setValue(defaults::DEFAULT_Kd);
    mUi->uMpcEditMenuBox->setChecked(defaults::MPC_EDIT_MENU);
    mUi->uMpcAutotuneMenuBox->setChecked(defaults::MPC_AUTOTUNE_MENU);
    mUi->uMpcMaxSpinBox->setValue(defaults::MPC_MAX);
    mUi->uMpcHeaterPowerEdit->setText(defaults::MPC_HEATER_POWER);
    mUi->uMpcIncludeFanBox->setChecked(defaults::MPC_INCLUDE_FAN);
    mUi->uMpcBlockHeatCapacityEdit->setText(defaults::MPC_BLOCK_HEAT_CAPACITY);
    mUi->uMpcSensorResponsivenessEdit->setText(defaults::MPC_SENSOR_RESPONSIVENESS);
    mUi->uMpcAmbientXferCoeffEdit->setText(defaults::MPC_AMBIENT_XFER_COEFF);
    mUi->uMpcAmbientXferCoeffFan255Edit->setText(defaults::MPC_AMBIENT_XFER_COEFF_FAN255);
    mUi->uMpcFan0AllHotendsBox->setChecked(defaults::MPC_FAN_0_ALL_HOTENDS);
    mUi->uMpcFan0ActiveHotendBox->setChecked(defaults::MPC_FAN_0_ACTIVE_HOTEND);
    mUi->uFilamentHeatCapacityPermmEdit->setText(defaults::FILAMENT_HEAT_CAPACITY_PERMM);
    mUi->uMpcSmoothingFactorSpinBox->setValue(defaults::MPC_SMOOTHING_FACTOR);
    mUi->uMpcMinAmbientChangeSpinBox->setValue(defaults::MPC_MIN_AMBIENT_CHANGE);
    mUi->uMpcSteadystateSpinBox->setValue(defaults::MPC_STEADYSTATE);
    mUi->uMpcTuningPosEdit->setText(defaults::MPC_TUNING_POS);
    mUi->uMpcTuningEndZSpinBox->setValue(defaults::MPC_TUNING_END_Z);
    mUi->uPidtempbedBox->setChecked(defaults::PIDTEMPBED);
    mUi->uBedLimitSwitchingBox->setChecked(defaults::BED_LIMIT_SWITCHING);
    mUi->uMaxBedPowerSpinBox->setValue(defaults::MAX_BED_POWER);
    mUi->uMinBedPowerSpinBox->setValue(defaults::MIN_BED_POWER);
    mUi->uMinBedPowerBox->setChecked(defaults::ENABLE_MIN_BED_POWER);
    mUi->uPidBedDebugBox->setChecked(defaults::PID_BED_DEBUG);
    mUi->uDefaultBedkpSpinBox->setValue(defaults::DEFAULT_bedKp);
    mUi->uDefaultBedkiSpinBox->setValue(defaults::DEFAULT_bedKi);
    mUi->uDefaultBedkdSpinBox->setValue(defaults::DEFAULT_bedKd);
    mUi->uPidtempchamberBox->setChecked(defaults::PIDTEMPCHAMBER);
    mUi->uChamberLimitSwitchingBox->setChecked(defaults::CHAMBER_LIMIT_SWITCHING);
    mUi->uMaxChamberPowerSpinBox->setValue(defaults::MAX_CHAMBER_POWER);
    mUi->uMinChamberPowerSpinBox->setValue(defaults::MIN_CHAMBER_POWER);
    mUi->uMinChamberPowerBox->setChecked(defaults::ENABLE_MIN_CHAMBER_POWER);
    mUi->uPidChamberDebugBox->setChecked(defaults::PID_CHAMBER_DEBUG);
    mUi->uDefaultChamberkpSpinBox->setValue(defaults::DEFAULT_chamberKp);
    mUi->uDefaultChamberkiSpinBox->setValue(defaults::DEFAULT_chamberKi);
    mUi->uDefaultChamberkdSpinBox->setValue(defaults::DEFAULT_chamberKd);
    mUi->uPidOpenloopBox->setChecked(defaults::PID_OPENLOOP);
    mUi->uSlowPwmHeatersBox->setChecked(defaults::SLOW_PWM_HEATERS);
    mUi->uPidFunctionalRangeSpinBox->setValue(defaults::PID_FUNCTIONAL_RANGE);
    mUi->uPidEditMenuBox->setChecked(defaults::PID_EDIT_MENU);
    mUi->uPidAutotuneMenuBox->setChecked(defaults::PID_AUTOTUNE_MENU);
    mUi->uPreventColdExtrusionBox->setChecked(defaults::PREVENT_COLD_EXTRUSION);
    mUi->uExtrudeMintempSpinBox->setValue(defaults::EXTRUDE_MINTEMP);
    mUi->uPreventLengthyExtrudeBox->setChecked(defaults::PREVENT_LENGTHY_EXTRUDE);
    mUi->uExtrudeMaxlengthSpinBox->setValue(defaults::EXTRUDE_MAXLENGTH);
    mUi->uThermalProtectionHotendsBox->setChecked(defaults::THERMAL_PROTECTION_HOTENDS);
    mUi->uThermalProtectionBedBox->setChecked(defaults::THERMAL_PROTECTION_BED);
    mUi->uThermalProtectionChamberBox->setChecked(defaults::THERMAL_PROTECTION_CHAMBER);
    mUi->uThermalProtectionCoolerBox->setChecked(defaults::THERMAL_PROTECTION_COOLER);

    mUi->uSensorTabWidget->setCurrentIndex(0);
    mUi->uLimitsTabWidget->setCurrentIndex(0);

    mIsLoading = false;
}

bool ThermalSettingsPage::LoadFromJson(const QJsonObject &pJson)
{
    bool success = true;
    mIsLoading = true;

    success &= LoadConfig(mUi->uTempSensor0Dropdown, pJson, "TEMP_SENSOR_0");
    success &= LoadConfig(mUi->uTempSensor1Dropdown, pJson, "TEMP_SENSOR_1");
    success &= LoadConfig(mUi->uTempSensor2Dropdown, pJson, "TEMP_SENSOR_2");
    success &= LoadConfig(mUi->uTempSensor3Dropdown, pJson, "TEMP_SENSOR_3");
    success &= LoadConfig(mUi->uTempSensor4Dropdown, pJson, "TEMP_SENSOR_4");
    success &= LoadConfig(mUi->uTempSensor5Dropdown, pJson, "TEMP_SENSOR_5");
    success &= LoadConfig(mUi->uTempSensor6Dropdown, pJson, "TEMP_SENSOR_6");
    success &= LoadConfig(mUi->uTempSensor7Dropdown, pJson, "TEMP_SENSOR_7");
    success &= LoadConfig(mUi->uTempSensorBedDropdown, pJson, "TEMP_SENSOR_BED");
    success &= LoadConfig(mUi->uTempSensorProbeDropdown, pJson, "TEMP_SENSOR_PROBE");
    success &= LoadConfig(mUi->uTempSensorChamberDropdown, pJson, "TEMP_SENSOR_CHAMBER");
    success &= LoadConfig(mUi->uTempSensorCoolerDropdown, pJson, "TEMP_SENSOR_COOLER");
    success &= LoadConfig(mUi->uTempSensorBoardDropdown, pJson, "TEMP_SENSOR_BOARD");
    success &= LoadConfig(mUi->uTempSensorRedundantDropdown, pJson, "TEMP_SENSOR_REDUNDANT");
    success &= LoadConfig(mUi->uDummyThermistor998ValueSpinBox, pJson, "DUMMY_THERMISTOR_998_VALUE");
    success &= LoadConfig(mUi->uDummyThermistor999ValueSpinBox, pJson, "DUMMY_THERMISTOR_999_VALUE");
    success &= LoadConfig(mUi->uMax31865SensorOhms0SpinBox, pJson, "MAX31865_SENSOR_OHMS_0");
    success &= LoadConfig(mUi->uMax31865CalibrationOhms0SpinBox, pJson, "MAX31865_CALIBRATION_OHMS_0");
    success &= LoadConfig(mUi->uMax31865SensorOhms1SpinBox, pJson, "MAX31865_SENSOR_OHMS_1");
    success &= LoadConfig(mUi->uMax31865CalibrationOhms1SpinBox, pJson, "MAX31865_CALIBRATION_OHMS_1");
    success &= LoadConfig(mUi->uMax31865SensorOhms2SpinBox, pJson, "MAX31865_SENSOR_OHMS_2");
    success &= LoadConfig(mUi->uMax31865CalibrationOhms2SpinBox, pJson, "MAX31865_CALIBRATION_OHMS_2");
    success &= LoadConfig(mUi->uTempResidencyTimeSpinBox, pJson, "TEMP_RESIDENCY_TIME");
    success &= LoadConfig(mUi->uTempWindowSpinBox, pJson, "TEMP_WINDOW");
    success &= LoadConfig(mUi->uTempHysteresisSpinBox, pJson, "TEMP_HYSTERESIS");
    success &= LoadConfig(mUi->uTempBedResidencyTimeSpinBox, pJson, "TEMP_BED_RESIDENCY_TIME");
    success &= LoadConfig(mUi->uTempBedWindowSpinBox, pJson, "TEMP_BED_WINDOW");
    success &= LoadConfig(mUi->uTempBedHysteresisSpinBox, pJson, "TEMP_BED_HYSTERESIS");
    success &= LoadConfig(mUi->uTempChamberResidencyTimeSpinBox, pJson, "TEMP_CHAMBER_RESIDENCY_TIME");
    success &= LoadConfig(mUi->uTempChamberWindowSpinBox, pJson, "TEMP_CHAMBER_WINDOW");
    success &= LoadConfig(mUi->uTempChamberHysteresisSpinBox, pJson, "TEMP_CHAMBER_HYSTERESIS");
    success &= LoadConfig(mUi->uTempSensorRedundantSourceDropdown, pJson, "TEMP_SENSOR_REDUNDANT_SOURCE");
    success &= LoadConfig(mUi->uTempSensorRedundantTargetDropdown, pJson, "TEMP_SENSOR_REDUNDANT_TARGET");
    success &= LoadConfig(mUi->uTempSensorRedundantMaxDiffSpinBox, pJson, "TEMP_SENSOR_REDUNDANT_MAX_DIFF");
    success &= LoadConfig(mUi->uHeater0MintempSpinBox, pJson, "HEATER_0_MINTEMP");
    success &= LoadConfig(mUi->uHeater1MintempSpinBox, pJson, "HEATER_1_MINTEMP");
    success &= LoadConfig(mUi->uHeater2MintempSpinBox, pJson, "HEATER_2_MINTEMP");
    success &= LoadConfig(mUi->uHeater3MintempSpinBox, pJson, "HEATER_3_MINTEMP");
    success &= LoadConfig(mUi->uHeater4MintempSpinBox, pJson, "HEATER_4_MINTEMP");
    success &= LoadConfig(mUi->uHeater5MintempSpinBox, pJson, "HEATER_5_MINTEMP");
    success &= LoadConfig(mUi->uHeater6MintempSpinBox, pJson, "HEATER_6_MINTEMP");
    success &= LoadConfig(mUi->uHeater7MintempSpinBox, pJson, "HEATER_7_MINTEMP");
    success &= LoadConfig(mUi->uBedMintempSpinBox, pJson, "BED_MINTEMP");
    success &= LoadConfig(mUi->uChamberMintempSpinBox, pJson, "CHAMBER_MINTEMP");
    success &= LoadConfig(mUi->uHeater0MaxtempSpinBox, pJson, "HEATER_0_MAXTEMP");
    success &= LoadConfig(mUi->uHeater1MaxtempSpinBox, pJson, "HEATER_1_MAXTEMP");
    success &= LoadConfig(mUi->uHeater2MaxtempSpinBox, pJson, "HEATER_2_MAXTEMP");
    success &= LoadConfig(mUi->uHeater3MaxtempSpinBox, pJson, "HEATER_3_MAXTEMP");
    success &= LoadConfig(mUi->uHeater4MaxtempSpinBox, pJson, "HEATER_4_MAXTEMP");
    success &= LoadConfig(mUi->uHeater5MaxtempSpinBox, pJson, "HEATER_5_MAXTEMP");
    success &= LoadConfig(mUi->uHeater6MaxtempSpinBox, pJson, "HEATER_6_MAXTEMP");
    success &= LoadConfig(mUi->uHeater7MaxtempSpinBox, pJson, "HEATER_7_MAXTEMP");
    success &= LoadConfig(mUi->uBedMaxtempSpinBox, pJson, "BED_MAXTEMP");
    success &= LoadConfig(mUi->uChamberMaxtempSpinBox, pJson, "CHAMBER_MAXTEMP");
    success &= LoadConfig(mUi->uHotendOvershootSpinBox, pJson, "HOTEND_OVERSHOOT");
    success &= LoadConfig(mUi->uBedOvershootSpinBox, pJson, "BED_OVERSHOOT");
    success &= LoadConfig(mUi->uCoolerOvershootSpinBox, pJson, "COOLER_OVERSHOOT");
    success &= LoadConfig(mUi->uPidtempBox, pJson, "PIDTEMP");
    success &= LoadConfig(mUi->uMpctempBox, pJson, "MPCTEMP");
    success &= LoadConfig(mUi->uBangMaxSpinBox, pJson, "BANG_MAX");
    success &= LoadConfig(mUi->uPidMaxSpinBox, pJson, "PID_MAX");
    success &= LoadConfig(mUi->uPidK1SpinBox, pJson, "PID_K1");
    success &= LoadConfig(mUi->uPidDebugBox, pJson, "PID_DEBUG");
    success &= LoadConfig(mUi->uPidParamsPerHotendBox, pJson, "PID_PARAMS_PER_HOTEND");
    success &= LoadConfig(mUi->uDefaultKpListEdit, pJson, "DEFAULT_Kp_LIST");
    success &= LoadConfig(mUi->uDefaultKiListEdit, pJson, "DEFAULT_Ki_LIST");
    success &= LoadConfig(mUi->uDefaultKdListEdit, pJson, "DEFAULT_Kd_LIST");
    success &= LoadConfig(mUi->uDefaultKpSpinBox, pJson, "DEFAULT_Kp");
    success &= LoadConfig(mUi->uDefaultKiSpinBox, pJson, "DEFAULT_Ki");
    success &= LoadConfig(mUi->uDefaultKdSpinBox, pJson, "DEFAULT_Kd");
    success &= LoadConfig(mUi->uMpcEditMenuBox, pJson, "MPC_EDIT_MENU");
    success &= LoadConfig(mUi->uMpcAutotuneMenuBox, pJson, "MPC_AUTOTUNE_MENU");
    success &= LoadConfig(mUi->uMpcMaxSpinBox, pJson, "MPC_MAX");
    success &= LoadConfig(mUi->uMpcHeaterPowerEdit, pJson, "MPC_HEATER_POWER");
    success &= LoadConfig(mUi->uMpcIncludeFanBox, pJson, "MPC_INCLUDE_FAN");
    success &= LoadConfig(mUi->uMpcBlockHeatCapacityEdit, pJson, "MPC_BLOCK_HEAT_CAPACITY");
    success &= LoadConfig(mUi->uMpcSensorResponsivenessEdit, pJson, "MPC_SENSOR_RESPONSIVENESS");
    success &= LoadConfig(mUi->uMpcAmbientXferCoeffEdit, pJson, "MPC_AMBIENT_XFER_COEFF");
    success &= LoadConfig(mUi->uMpcAmbientXferCoeffFan255Edit, pJson, "MPC_AMBIENT_XFER_COEFF_FAN255");
    success &= LoadConfig(mUi->uMpcFan0AllHotendsBox, pJson, "MPC_FAN_0_ALL_HOTENDS");
    success &= LoadConfig(mUi->uMpcFan0ActiveHotendBox, pJson, "MPC_FAN_0_ACTIVE_HOTEND");
    success &= LoadConfig(mUi->uFilamentHeatCapacityPermmEdit, pJson, "FILAMENT_HEAT_CAPACITY_PERMM");
    success &= LoadConfig(mUi->uMpcSmoothingFactorSpinBox, pJson, "MPC_SMOOTHING_FACTOR");
    success &= LoadConfig(mUi->uMpcMinAmbientChangeSpinBox, pJson, "MPC_MIN_AMBIENT_CHANGE");
    success &= LoadConfig(mUi->uMpcSteadystateSpinBox, pJson, "MPC_STEADYSTATE");
    success &= LoadConfig(mUi->uMpcTuningPosEdit, pJson, "MPC_TUNING_POS");
    success &= LoadConfig(mUi->uMpcTuningEndZSpinBox, pJson, "MPC_TUNING_END_Z");
    success &= LoadConfig(mUi->uPidtempbedBox, pJson, "PIDTEMPBED");
    success &= LoadConfig(mUi->uBedLimitSwitchingBox, pJson, "BED_LIMIT_SWITCHING");
    success &= LoadConfig(mUi->uMaxBedPowerSpinBox, pJson, "MAX_BED_POWER");
    success &= LoadConfig(mUi->uMinBedPowerSpinBox, pJson, "MIN_BED_POWER");
    success &= LoadConfig(mUi->uMinBedPowerBox, pJson, "ENABLE_MIN_BED_POWER");
    success &= LoadConfig(mUi->uPidBedDebugBox, pJson, "PID_BED_DEBUG");
    success &= LoadConfig(mUi->uDefaultBedkpSpinBox, pJson, "DEFAULT_bedKp");
    success &= LoadConfig(mUi->uDefaultBedkiSpinBox, pJson, "DEFAULT_bedKi");
    success &= LoadConfig(mUi->uDefaultBedkdSpinBox, pJson, "DEFAULT_bedKd");
    success &= LoadConfig(mUi->uPidtempchamberBox, pJson, "PIDTEMPCHAMBER");
    success &= LoadConfig(mUi->uChamberLimitSwitchingBox, pJson, "CHAMBER_LIMIT_SWITCHING");
    success &= LoadConfig(mUi->uMaxChamberPowerSpinBox, pJson, "MAX_CHAMBER_POWER");
    success &= LoadConfig(mUi->uMinChamberPowerSpinBox, pJson, "MIN_CHAMBER_POWER");
    success &= LoadConfig(mUi->uMinChamberPowerBox, pJson, "ENABLE_MIN_CHAMBER_POWER");
    success &= LoadConfig(mUi->uPidChamberDebugBox, pJson, "PID_CHAMBER_DEBUG");
    success &= LoadConfig(mUi->uDefaultChamberkpSpinBox, pJson, "DEFAULT_chamberKp");
    success &= LoadConfig(mUi->uDefaultChamberkiSpinBox, pJson, "DEFAULT_chamberKi");
    success &= LoadConfig(mUi->uDefaultChamberkdSpinBox, pJson, "DEFAULT_chamberKd");
    success &= LoadConfig(mUi->uPidOpenloopBox, pJson, "PID_OPENLOOP");
    success &= LoadConfig(mUi->uSlowPwmHeatersBox, pJson, "SLOW_PWM_HEATERS");
    success &= LoadConfig(mUi->uPidFunctionalRangeSpinBox, pJson, "PID_FUNCTIONAL_RANGE");
    success &= LoadConfig(mUi->uPidEditMenuBox, pJson, "PID_EDIT_MENU");
    success &= LoadConfig(mUi->uPidAutotuneMenuBox, pJson, "PID_AUTOTUNE_MENU");
    success &= LoadConfig(mUi->uPreventColdExtrusionBox, pJson, "PREVENT_COLD_EXTRUSION");
    success &= LoadConfig(mUi->uExtrudeMintempSpinBox, pJson, "EXTRUDE_MINTEMP");
    success &= LoadConfig(mUi->uPreventLengthyExtrudeBox, pJson, "PREVENT_LENGTHY_EXTRUDE");
    success &= LoadConfig(mUi->uExtrudeMaxlengthSpinBox, pJson, "EXTRUDE_MAXLENGTH");
    success &= LoadConfig(mUi->uThermalProtectionHotendsBox, pJson, "THERMAL_PROTECTION_HOTENDS");
    success &= LoadConfig(mUi->uThermalProtectionBedBox, pJson, "THERMAL_PROTECTION_BED");
    success &= LoadConfig(mUi->uThermalProtectionChamberBox, pJson, "THERMAL_PROTECTION_CHAMBER");
    success &= LoadConfig(mUi->uThermalProtectionCoolerBox, pJson, "THERMAL_PROTECTION_COOLER");

    mIsLoading = false;
    return success;
}

void ThermalSettingsPage::FetchConfiguration(Configuration& pConfig)
{
    SetConfig(pConfig.thermalSettings.TEMP_SENSOR_0, mUi->uTempSensor0Dropdown);
    SetConfig(pConfig.thermalSettings.TEMP_SENSOR_1, mUi->uTempSensor1Dropdown);
    SetConfig(pConfig.thermalSettings.TEMP_SENSOR_2, mUi->uTempSensor2Dropdown);
    SetConfig(pConfig.thermalSettings.TEMP_SENSOR_3, mUi->uTempSensor3Dropdown);
    SetConfig(pConfig.thermalSettings.TEMP_SENSOR_4, mUi->uTempSensor4Dropdown);
    SetConfig(pConfig.thermalSettings.TEMP_SENSOR_5, mUi->uTempSensor5Dropdown);
    SetConfig(pConfig.thermalSettings.TEMP_SENSOR_6, mUi->uTempSensor6Dropdown);
    SetConfig(pConfig.thermalSettings.TEMP_SENSOR_7, mUi->uTempSensor7Dropdown);
    SetConfig(pConfig.thermalSettings.TEMP_SENSOR_BED, mUi->uTempSensorBedDropdown);
    SetConfig(pConfig.thermalSettings.TEMP_SENSOR_PROBE, mUi->uTempSensorProbeDropdown);
    SetConfig(pConfig.thermalSettings.TEMP_SENSOR_CHAMBER, mUi->uTempSensorChamberDropdown);
    SetConfig(pConfig.thermalSettings.TEMP_SENSOR_COOLER, mUi->uTempSensorCoolerDropdown);
    SetConfig(pConfig.thermalSettings.TEMP_SENSOR_BOARD, mUi->uTempSensorBoardDropdown);
    SetConfig(pConfig.thermalSettings.TEMP_SENSOR_REDUNDANT, mUi->uTempSensorRedundantDropdown);
    SetConfig(pConfig.thermalSettings.DUMMY_THERMISTOR_998_VALUE, mUi->uDummyThermistor998ValueSpinBox);
    SetConfig(pConfig.thermalSettings.DUMMY_THERMISTOR_999_VALUE, mUi->uDummyThermistor999ValueSpinBox);
    SetConfig(pConfig.thermalSettings.MAX31865_SENSOR_OHMS_0, mUi->uMax31865SensorOhms0SpinBox);
    SetConfig(pConfig.thermalSettings.MAX31865_CALIBRATION_OHMS_0, mUi->uMax31865CalibrationOhms0SpinBox);
    SetConfig(pConfig.thermalSettings.MAX31865_SENSOR_OHMS_1, mUi->uMax31865SensorOhms1SpinBox);
    SetConfig(pConfig.thermalSettings.MAX31865_CALIBRATION_OHMS_1, mUi->uMax31865CalibrationOhms1SpinBox);
    SetConfig(pConfig.thermalSettings.MAX31865_SENSOR_OHMS_2, mUi->uMax31865SensorOhms2SpinBox);
    SetConfig(pConfig.thermalSettings.MAX31865_CALIBRATION_OHMS_2, mUi->uMax31865CalibrationOhms2SpinBox);
    SetConfig(pConfig.thermalSettings.TEMP_RESIDENCY_TIME, mUi->uTempResidencyTimeSpinBox);
    SetConfig(pConfig.thermalSettings.TEMP_WINDOW, mUi->uTempWindowSpinBox);
    SetConfig(pConfig.thermalSettings.TEMP_HYSTERESIS, mUi->uTempHysteresisSpinBox);
    SetConfig(pConfig.thermalSettings.TEMP_BED_RESIDENCY_TIME, mUi->uTempBedResidencyTimeSpinBox);
    SetConfig(pConfig.thermalSettings.TEMP_BED_WINDOW, mUi->uTempBedWindowSpinBox);
    SetConfig(pConfig.thermalSettings.TEMP_BED_HYSTERESIS, mUi->uTempBedHysteresisSpinBox);
    SetConfig(pConfig.thermalSettings.TEMP_CHAMBER_RESIDENCY_TIME, mUi->uTempChamberResidencyTimeSpinBox);
    SetConfig(pConfig.thermalSettings.TEMP_CHAMBER_WINDOW, mUi->uTempChamberWindowSpinBox);
    SetConfig(pConfig.thermalSettings.TEMP_CHAMBER_HYSTERESIS, mUi->uTempChamberHysteresisSpinBox);
    SetConfig(pConfig.thermalSettings.TEMP_SENSOR_REDUNDANT_SOURCE, mUi->uTempSensorRedundantSourceDropdown);
    SetConfig(pConfig.thermalSettings.TEMP_SENSOR_REDUNDANT_TARGET, mUi->uTempSensorRedundantTargetDropdown);
    SetConfig(pConfig.thermalSettings.TEMP_SENSOR_REDUNDANT_MAX_DIFF, mUi->uTempSensorRedundantMaxDiffSpinBox);
    SetConfig(pConfig.thermalSettings.HEATER_0_MINTEMP, mUi->uHeater0MintempSpinBox);
    SetConfig(pConfig.thermalSettings.HEATER_1_MINTEMP, mUi->uHeater1MintempSpinBox);
    SetConfig(pConfig.thermalSettings.HEATER_2_MINTEMP, mUi->uHeater2MintempSpinBox);
    SetConfig(pConfig.thermalSettings.HEATER_3_MINTEMP, mUi->uHeater3MintempSpinBox);
    SetConfig(pConfig.thermalSettings.HEATER_4_MINTEMP, mUi->uHeater4MintempSpinBox);
    SetConfig(pConfig.thermalSettings.HEATER_5_MINTEMP, mUi->uHeater5MintempSpinBox);
    SetConfig(pConfig.thermalSettings.HEATER_6_MINTEMP, mUi->uHeater6MintempSpinBox);
    SetConfig(pConfig.thermalSettings.HEATER_7_MINTEMP, mUi->uHeater7MintempSpinBox);
    SetConfig(pConfig.thermalSettings.BED_MINTEMP, mUi->uBedMintempSpinBox);
    SetConfig(pConfig.thermalSettings.CHAMBER_MINTEMP, mUi->uChamberMintempSpinBox);
    SetConfig(pConfig.thermalSettings.HEATER_0_MAXTEMP, mUi->uHeater0MaxtempSpinBox);
    SetConfig(pConfig.thermalSettings.HEATER_1_MAXTEMP, mUi->uHeater1MaxtempSpinBox);
    SetConfig(pConfig.thermalSettings.HEATER_2_MAXTEMP, mUi->uHeater2MaxtempSpinBox);
    SetConfig(pConfig.thermalSettings.HEATER_3_MAXTEMP, mUi->uHeater3MaxtempSpinBox);
    SetConfig(pConfig.thermalSettings.HEATER_4_MAXTEMP, mUi->uHeater4MaxtempSpinBox);
    SetConfig(pConfig.thermalSettings.HEATER_5_MAXTEMP, mUi->uHeater5MaxtempSpinBox);
    SetConfig(pConfig.thermalSettings.HEATER_6_MAXTEMP, mUi->uHeater6MaxtempSpinBox);
    SetConfig(pConfig.thermalSettings.HEATER_7_MAXTEMP, mUi->uHeater7MaxtempSpinBox);
    SetConfig(pConfig.thermalSettings.BED_MAXTEMP, mUi->uBedMaxtempSpinBox);
    SetConfig(pConfig.thermalSettings.CHAMBER_MAXTEMP, mUi->uChamberMaxtempSpinBox);
    SetConfig(pConfig.thermalSettings.HOTEND_OVERSHOOT, mUi->uHotendOvershootSpinBox);
    SetConfig(pConfig.thermalSettings.BED_OVERSHOOT, mUi->uBedOvershootSpinBox);
    SetConfig(pConfig.thermalSettings.COOLER_OVERSHOOT, mUi->uCoolerOvershootSpinBox);
    SetConfig(pConfig.thermalSettings.PIDTEMP, mUi->uPidtempBox);
    SetConfig(pConfig.thermalSettings.MPCTEMP, mUi->uMpctempBox);
    SetConfig(pConfig.thermalSettings.BANG_MAX, mUi->uBangMaxSpinBox);
    SetConfig(pConfig.thermalSettings.PID_MAX, mUi->uPidMaxSpinBox);
    SetConfig(pConfig.thermalSettings.PID_K1, mUi->uPidK1SpinBox);
    SetConfig(pConfig.thermalSettings.PID_DEBUG, mUi->uPidDebugBox);
    SetConfig(pConfig.thermalSettings.PID_PARAMS_PER_HOTEND, mUi->uPidParamsPerHotendBox);
    SetConfig(pConfig.thermalSettings.DEFAULT_Kp_LIST, mUi->uDefaultKpListEdit);
    SetConfig(pConfig.thermalSettings.DEFAULT_Ki_LIST, mUi->uDefaultKiListEdit);
    SetConfig(pConfig.thermalSettings.DEFAULT_Kd_LIST, mUi->uDefaultKdListEdit);
    SetConfig(pConfig.thermalSettings.DEFAULT_Kp, mUi->uDefaultKpSpinBox);
    SetConfig(pConfig.thermalSettings.DEFAULT_Ki, mUi->uDefaultKiSpinBox);
    SetConfig(pConfig.thermalSettings.DEFAULT_Kd, mUi->uDefaultKdSpinBox);
    SetConfig(pConfig.thermalSettings.MPC_EDIT_MENU, mUi->uMpcEditMenuBox);
    SetConfig(pConfig.thermalSettings.MPC_AUTOTUNE_MENU, mUi->uMpcAutotuneMenuBox);
    SetConfig(pConfig.thermalSettings.MPC_MAX, mUi->uMpcMaxSpinBox);
    SetConfig(pConfig.thermalSettings.MPC_HEATER_POWER, mUi->uMpcHeaterPowerEdit);
    SetConfig(pConfig.thermalSettings.MPC_INCLUDE_FAN, mUi->uMpcIncludeFanBox);
    SetConfig(pConfig.thermalSettings.MPC_BLOCK_HEAT_CAPACITY, mUi->uMpcBlockHeatCapacityEdit);
    SetConfig(pConfig.thermalSettings.MPC_SENSOR_RESPONSIVENESS, mUi->uMpcSensorResponsivenessEdit);
    SetConfig(pConfig.thermalSettings.MPC_AMBIENT_XFER_COEFF, mUi->uMpcAmbientXferCoeffEdit);
    SetConfig(pConfig.thermalSettings.MPC_AMBIENT_XFER_COEFF_FAN255, mUi->uMpcAmbientXferCoeffFan255Edit);
    SetConfig(pConfig.thermalSettings.MPC_FAN_0_ALL_HOTENDS, mUi->uMpcFan0AllHotendsBox);
    SetConfig(pConfig.thermalSettings.MPC_FAN_0_ACTIVE_HOTEND, mUi->uMpcFan0ActiveHotendBox);
    SetConfig(pConfig.thermalSettings.FILAMENT_HEAT_CAPACITY_PERMM, mUi->uFilamentHeatCapacityPermmEdit);
    SetConfig(pConfig.thermalSettings.MPC_SMOOTHING_FACTOR, mUi->uMpcSmoothingFactorSpinBox);
    SetConfig(pConfig.thermalSettings.MPC_MIN_AMBIENT_CHANGE, mUi->uMpcMinAmbientChangeSpinBox);
    SetConfig(pConfig.thermalSettings.MPC_STEADYSTATE, mUi->uMpcSteadystateSpinBox);
    SetConfig(pConfig.thermalSettings.MPC_TUNING_POS, mUi->uMpcTuningPosEdit);
    SetConfig(pConfig.thermalSettings.MPC_TUNING_END_Z, mUi->uMpcTuningEndZSpinBox);
    SetConfig(pConfig.thermalSettings.PIDTEMPBED, mUi->uPidtempbedBox);
    SetConfig(pConfig.thermalSettings.BED_LIMIT_SWITCHING, mUi->uBedLimitSwitchingBox);
    SetConfig(pConfig.thermalSettings.MAX_BED_POWER, mUi->uMaxBedPowerSpinBox);
    SetConfig(pConfig.thermalSettings.MIN_BED_POWER, mUi->uMinBedPowerSpinBox);
    SetConfig(pConfig.thermalSettings.ENABLE_MIN_BED_POWER, mUi->uMinBedPowerBox);
    SetConfig(pConfig.thermalSettings.PID_BED_DEBUG, mUi->uPidBedDebugBox);
    SetConfig(pConfig.thermalSettings.DEFAULT_bedKp, mUi->uDefaultBedkpSpinBox);
    SetConfig(pConfig.thermalSettings.DEFAULT_bedKi, mUi->uDefaultBedkiSpinBox);
    SetConfig(pConfig.thermalSettings.DEFAULT_bedKd, mUi->uDefaultBedkdSpinBox);
    SetConfig(pConfig.thermalSettings.PIDTEMPCHAMBER, mUi->uPidtempchamberBox);
    SetConfig(pConfig.thermalSettings.CHAMBER_LIMIT_SWITCHING, mUi->uChamberLimitSwitchingBox);
    SetConfig(pConfig.thermalSettings.MAX_CHAMBER_POWER, mUi->uMaxChamberPowerSpinBox);
    SetConfig(pConfig.thermalSettings.MIN_CHAMBER_POWER, mUi->uMinChamberPowerSpinBox);
    SetConfig(pConfig.thermalSettings.ENABLE_MIN_CHAMBER_POWER, mUi->uMinChamberPowerBox);
    SetConfig(pConfig.thermalSettings.PID_CHAMBER_DEBUG, mUi->uPidChamberDebugBox);
    SetConfig(pConfig.thermalSettings.DEFAULT_chamberKp, mUi->uDefaultChamberkpSpinBox);
    SetConfig(pConfig.thermalSettings.DEFAULT_chamberKi, mUi->uDefaultChamberkiSpinBox);
    SetConfig(pConfig.thermalSettings.DEFAULT_chamberKd, mUi->uDefaultChamberkdSpinBox);
    SetConfig(pConfig.thermalSettings.PID_OPENLOOP, mUi->uPidOpenloopBox);
    SetConfig(pConfig.thermalSettings.SLOW_PWM_HEATERS, mUi->uSlowPwmHeatersBox);
    SetConfig(pConfig.thermalSettings.PID_FUNCTIONAL_RANGE, mUi->uPidFunctionalRangeSpinBox);
    SetConfig(pConfig.thermalSettings.PID_EDIT_MENU, mUi->uPidEditMenuBox);
    SetConfig(pConfig.thermalSettings.PID_AUTOTUNE_MENU, mUi->uPidAutotuneMenuBox);
    SetConfig(pConfig.thermalSettings.PREVENT_COLD_EXTRUSION, mUi->uPreventColdExtrusionBox);
    SetConfig(pConfig.thermalSettings.EXTRUDE_MINTEMP, mUi->uExtrudeMintempSpinBox);
    SetConfig(pConfig.thermalSettings.PREVENT_LENGTHY_EXTRUDE, mUi->uPreventLengthyExtrudeBox);
    SetConfig(pConfig.thermalSettings.EXTRUDE_MAXLENGTH, mUi->uExtrudeMaxlengthSpinBox);
    SetConfig(pConfig.thermalSettings.THERMAL_PROTECTION_HOTENDS, mUi->uThermalProtectionHotendsBox);
    SetConfig(pConfig.thermalSettings.THERMAL_PROTECTION_BED, mUi->uThermalProtectionBedBox);
    SetConfig(pConfig.thermalSettings.THERMAL_PROTECTION_CHAMBER, mUi->uThermalProtectionChamberBox);
    SetConfig(pConfig.thermalSettings.THERMAL_PROTECTION_COOLER, mUi->uThermalProtectionCoolerBox);
}

void ThermalSettingsPage::ReplaceTags(QStringList& pOutput)
{
    const bool hasETempSensor = (mUi->uTempSensor0Dropdown->currentIndex() != 53 || mUi->uTempSensor1Dropdown->currentIndex() != 53 || mUi->uTempSensor2Dropdown->currentIndex() != 53 || mUi->uTempSensor3Dropdown->currentIndex() != 53 &&
                                 mUi->uTempSensor4Dropdown->currentIndex() != 53 || mUi->uTempSensor5Dropdown->currentIndex() != 53 || mUi->uTempSensor6Dropdown->currentIndex() != 53 || mUi->uTempSensor7Dropdown->currentIndex() != 53);

    ReplaceTag(pOutput, "#{TEMP_SENSOR_0}", mUi->uTempSensor0Dropdown, false, "TEMP_SENSOR_0", true);
    ReplaceTag(pOutput, "#{TEMP_SENSOR_1}", mUi->uTempSensor1Dropdown, false, "TEMP_SENSOR_1", true);
    ReplaceTag(pOutput, "#{TEMP_SENSOR_2}", mUi->uTempSensor2Dropdown, false, "TEMP_SENSOR_2", true);
    ReplaceTag(pOutput, "#{TEMP_SENSOR_3}", mUi->uTempSensor3Dropdown, false, "TEMP_SENSOR_3", true);
    ReplaceTag(pOutput, "#{TEMP_SENSOR_4}", mUi->uTempSensor4Dropdown, false, "TEMP_SENSOR_4", true);
    ReplaceTag(pOutput, "#{TEMP_SENSOR_5}", mUi->uTempSensor5Dropdown, false, "TEMP_SENSOR_5", true);
    ReplaceTag(pOutput, "#{TEMP_SENSOR_6}", mUi->uTempSensor6Dropdown, false, "TEMP_SENSOR_6", true);
    ReplaceTag(pOutput, "#{TEMP_SENSOR_7}", mUi->uTempSensor7Dropdown, false, "TEMP_SENSOR_7", true);
    ReplaceTag(pOutput, "#{TEMP_SENSOR_BED}", mUi->uTempSensorBedDropdown, false, "TEMP_SENSOR_BED", true);
    ReplaceTag(pOutput, "#{TEMP_SENSOR_PROBE}", mUi->uTempSensorProbeDropdown, false, "TEMP_SENSOR_PROBE", true);
    ReplaceTag(pOutput, "#{TEMP_SENSOR_CHAMBER}", mUi->uTempSensorChamberDropdown, false, "TEMP_SENSOR_CHAMBER", true);
    ReplaceTag(pOutput, "#{TEMP_SENSOR_COOLER}", mUi->uTempSensorCoolerDropdown, false, "TEMP_SENSOR_COOLER", true);
    ReplaceTag(pOutput, "#{TEMP_SENSOR_BOARD}", mUi->uTempSensorBoardDropdown, false, "TEMP_SENSOR_BOARD", true);
    ReplaceTag(pOutput, "#{TEMP_SENSOR_REDUNDANT}", mUi->uTempSensorRedundantDropdown, false, "TEMP_SENSOR_REDUNDANT", true);
    ReplaceTag(pOutput, "#{DUMMY_THERMISTOR_998_VALUE}", mUi->uDummyThermistor998ValueSpinBox, false, "DUMMY_THERMISTOR_998_VALUE");
    ReplaceTag(pOutput, "#{DUMMY_THERMISTOR_999_VALUE}", mUi->uDummyThermistor999ValueSpinBox, false, "DUMMY_THERMISTOR_999_VALUE");
    ReplaceTag(pOutput, "#{MAX31865_SENSOR_OHMS_0}", mUi->uMax31865SensorOhms0SpinBox, mUi->uTempSensor0Dropdown->currentIndex() > 2, "MAX31865_SENSOR_OHMS_0");
    ReplaceTag(pOutput, "#{MAX31865_CALIBRATION_OHMS_0}", mUi->uMax31865CalibrationOhms0SpinBox, mUi->uTempSensor0Dropdown->currentIndex() > 2, "MAX31865_CALIBRATION_OHMS_0");
    ReplaceTag(pOutput, "#{MAX31865_SENSOR_OHMS_1}", mUi->uMax31865SensorOhms1SpinBox, mUi->uTempSensor1Dropdown->currentIndex() > 2, "MAX31865_SENSOR_OHMS_1");
    ReplaceTag(pOutput, "#{MAX31865_CALIBRATION_OHMS_1}", mUi->uMax31865CalibrationOhms1SpinBox, mUi->uTempSensor1Dropdown->currentIndex() > 2, "MAX31865_CALIBRATION_OHMS_1");
    ReplaceTag(pOutput, "#{MAX31865_SENSOR_OHMS_2}", mUi->uMax31865SensorOhms2SpinBox, mUi->uTempSensor2Dropdown->currentIndex() > 2, "MAX31865_SENSOR_OHMS_2");
    ReplaceTag(pOutput, "#{MAX31865_CALIBRATION_OHMS_2}", mUi->uMax31865CalibrationOhms2SpinBox, mUi->uTempSensor2Dropdown->currentIndex() > 2, "MAX31865_CALIBRATION_OHMS_2");
    ReplaceTag(pOutput, "#{TEMP_RESIDENCY_TIME}", mUi->uTempResidencyTimeSpinBox, !hasETempSensor, "TEMP_RESIDENCY_TIME");
    ReplaceTag(pOutput, "#{TEMP_WINDOW}", mUi->uTempWindowSpinBox, !hasETempSensor, "TEMP_WINDOW");
    ReplaceTag(pOutput, "#{TEMP_HYSTERESIS}", mUi->uTempHysteresisSpinBox, !hasETempSensor, "TEMP_HYSTERESIS");
    ReplaceTag(pOutput, "#{TEMP_BED_RESIDENCY_TIME}", mUi->uTempBedResidencyTimeSpinBox, mUi->uTempSensorBedDropdown->currentIndex() == 53, "TEMP_BED_RESIDENCY_TIME");
    ReplaceTag(pOutput, "#{TEMP_BED_WINDOW}", mUi->uTempBedWindowSpinBox, mUi->uTempSensorBedDropdown->currentIndex() == 53, "TEMP_BED_WINDOW");
    ReplaceTag(pOutput, "#{TEMP_BED_HYSTERESIS}", mUi->uTempBedHysteresisSpinBox, mUi->uTempSensorBedDropdown->currentIndex() == 53, "TEMP_BED_HYSTERESIS");
    ReplaceTag(pOutput, "#{TEMP_CHAMBER_RESIDENCY_TIME}", mUi->uTempChamberResidencyTimeSpinBox, mUi->uTempSensorChamberDropdown->currentIndex() == 53, "TEMP_CHAMBER_RESIDENCY_TIME");
    ReplaceTag(pOutput, "#{TEMP_CHAMBER_WINDOW}", mUi->uTempChamberWindowSpinBox, mUi->uTempSensorChamberDropdown->currentIndex() == 53, "TEMP_CHAMBER_WINDOW");
    ReplaceTag(pOutput, "#{TEMP_CHAMBER_HYSTERESIS}", mUi->uTempChamberHysteresisSpinBox, mUi->uTempSensorChamberDropdown->currentIndex() == 53, "TEMP_CHAMBER_HYSTERESIS");
    ReplaceTag(pOutput, "#{TEMP_SENSOR_REDUNDANT_SOURCE}", mUi->uTempSensorRedundantSourceDropdown, mUi->uTempSensorRedundantDropdown->currentIndex() == 53, "TEMP_SENSOR_REDUNDANT_SOURCE", false);
    ReplaceTag(pOutput, "#{TEMP_SENSOR_REDUNDANT_TARGET}", mUi->uTempSensorRedundantTargetDropdown, mUi->uTempSensorRedundantDropdown->currentIndex() == 53, "TEMP_SENSOR_REDUNDANT_TARGET", false);
    ReplaceTag(pOutput, "#{TEMP_SENSOR_REDUNDANT_MAX_DIFF}", mUi->uTempSensorRedundantMaxDiffSpinBox, mUi->uTempSensorRedundantDropdown->currentIndex() == 53, "TEMP_SENSOR_REDUNDANT_MAX_DIFF");
    ReplaceTag(pOutput, "#{HEATER_0_MINTEMP}", mUi->uHeater0MintempSpinBox, false, "HEATER_0_MINTEMP");
    ReplaceTag(pOutput, "#{HEATER_1_MINTEMP}", mUi->uHeater1MintempSpinBox, false, "HEATER_1_MINTEMP");
    ReplaceTag(pOutput, "#{HEATER_2_MINTEMP}", mUi->uHeater2MintempSpinBox, false, "HEATER_2_MINTEMP");
    ReplaceTag(pOutput, "#{HEATER_3_MINTEMP}", mUi->uHeater3MintempSpinBox, false, "HEATER_3_MINTEMP");
    ReplaceTag(pOutput, "#{HEATER_4_MINTEMP}", mUi->uHeater4MintempSpinBox, false, "HEATER_4_MINTEMP");
    ReplaceTag(pOutput, "#{HEATER_5_MINTEMP}", mUi->uHeater5MintempSpinBox, false, "HEATER_5_MINTEMP");
    ReplaceTag(pOutput, "#{HEATER_6_MINTEMP}", mUi->uHeater6MintempSpinBox, false, "HEATER_6_MINTEMP");
    ReplaceTag(pOutput, "#{HEATER_7_MINTEMP}", mUi->uHeater7MintempSpinBox, false, "HEATER_7_MINTEMP");
    ReplaceTag(pOutput, "#{BED_MINTEMP}", mUi->uBedMintempSpinBox, false, "BED_MINTEMP");
    ReplaceTag(pOutput, "#{CHAMBER_MINTEMP}", mUi->uChamberMintempSpinBox, false, "CHAMBER_MINTEMP");
    ReplaceTag(pOutput, "#{HEATER_0_MAXTEMP}", mUi->uHeater0MaxtempSpinBox, false, "HEATER_0_MAXTEMP");
    ReplaceTag(pOutput, "#{HEATER_1_MAXTEMP}", mUi->uHeater1MaxtempSpinBox, false, "HEATER_1_MAXTEMP");
    ReplaceTag(pOutput, "#{HEATER_2_MAXTEMP}", mUi->uHeater2MaxtempSpinBox, false, "HEATER_2_MAXTEMP");
    ReplaceTag(pOutput, "#{HEATER_3_MAXTEMP}", mUi->uHeater3MaxtempSpinBox, false, "HEATER_3_MAXTEMP");
    ReplaceTag(pOutput, "#{HEATER_4_MAXTEMP}", mUi->uHeater4MaxtempSpinBox, false, "HEATER_4_MAXTEMP");
    ReplaceTag(pOutput, "#{HEATER_5_MAXTEMP}", mUi->uHeater5MaxtempSpinBox, false, "HEATER_5_MAXTEMP");
    ReplaceTag(pOutput, "#{HEATER_6_MAXTEMP}", mUi->uHeater6MaxtempSpinBox, false, "HEATER_6_MAXTEMP");
    ReplaceTag(pOutput, "#{HEATER_7_MAXTEMP}", mUi->uHeater7MaxtempSpinBox, false, "HEATER_7_MAXTEMP");
    ReplaceTag(pOutput, "#{BED_MAXTEMP}", mUi->uBedMaxtempSpinBox, false, "BED_MAXTEMP");
    ReplaceTag(pOutput, "#{CHAMBER_MAXTEMP}", mUi->uChamberMaxtempSpinBox, false, "CHAMBER_MAXTEMP");
    ReplaceTag(pOutput, "#{HOTEND_OVERSHOOT}", mUi->uHotendOvershootSpinBox, false, "HOTEND_OVERSHOOT");
    ReplaceTag(pOutput, "#{BED_OVERSHOOT}", mUi->uBedOvershootSpinBox, false, "BED_OVERSHOOT");
    ReplaceTag(pOutput, "#{COOLER_OVERSHOOT}", mUi->uCoolerOvershootSpinBox, false, "COOLER_OVERSHOOT");
    ReplaceTag(pOutput, "#{PIDTEMP}", mUi->uPidtempBox, "PIDTEMP");
    ReplaceTag(pOutput, "#{MPCTEMP}", mUi->uMpctempBox, "MPCTEMP");
    ReplaceTag(pOutput, "#{BANG_MAX}", mUi->uBangMaxSpinBox, false, "BANG_MAX");
    ReplaceTag(pOutput, "#{PID_MAX}", mUi->uPidMaxSpinBox, false, "PID_MAX");
    ReplaceTag(pOutput, "#{PID_K1}", mUi->uPidK1SpinBox, false, "PID_K1");
    ReplaceTag(pOutput, "#{PID_DEBUG}", mUi->uPidDebugBox, "PID_DEBUG");
    ReplaceTag(pOutput, "#{PID_PARAMS_PER_HOTEND}", mUi->uPidParamsPerHotendBox, "PID_PARAMS_PER_HOTEND");
    ReplaceTag(pOutput, "#{DEFAULT_Kp_LIST}", mUi->uDefaultKpListEdit, false, "DEFAULT_Kp_LIST");
    ReplaceTag(pOutput, "#{DEFAULT_Ki_LIST}", mUi->uDefaultKiListEdit, false, "DEFAULT_Ki_LIST");
    ReplaceTag(pOutput, "#{DEFAULT_Kd_LIST}", mUi->uDefaultKdListEdit, false, "DEFAULT_Kd_LIST");
    ReplaceTag(pOutput, "#{DEFAULT_Kp}", mUi->uDefaultKpSpinBox, mUi->uPidParamsPerHotendBox->isChecked(), "DEFAULT_Kp");
    ReplaceTag(pOutput, "#{DEFAULT_Ki}", mUi->uDefaultKiSpinBox, mUi->uPidParamsPerHotendBox->isChecked(), "DEFAULT_Ki");
    ReplaceTag(pOutput, "#{DEFAULT_Kd}", mUi->uDefaultKdSpinBox, mUi->uPidParamsPerHotendBox->isChecked(), "DEFAULT_Kd");
    ReplaceTag(pOutput, "#{MPC_EDIT_MENU}", mUi->uMpcEditMenuBox, "MPC_EDIT_MENU");
    ReplaceTag(pOutput, "#{MPC_AUTOTUNE_MENU}", mUi->uMpcAutotuneMenuBox, "MPC_AUTOTUNE_MENU");
    ReplaceTag(pOutput, "#{MPC_MAX}", mUi->uMpcMaxSpinBox, false, "MPC_MAX");
    ReplaceTag(pOutput, "#{MPC_HEATER_POWER}", mUi->uMpcHeaterPowerEdit, false, "MPC_HEATER_POWER");
    ReplaceTag(pOutput, "#{MPC_INCLUDE_FAN}", mUi->uMpcIncludeFanBox, "MPC_INCLUDE_FAN");
    ReplaceTag(pOutput, "#{MPC_BLOCK_HEAT_CAPACITY}", mUi->uMpcBlockHeatCapacityEdit, false, "MPC_BLOCK_HEAT_CAPACITY");
    ReplaceTag(pOutput, "#{MPC_SENSOR_RESPONSIVENESS}", mUi->uMpcSensorResponsivenessEdit, false, "MPC_SENSOR_RESPONSIVENESS");
    ReplaceTag(pOutput, "#{MPC_AMBIENT_XFER_COEFF}", mUi->uMpcAmbientXferCoeffEdit, false, "MPC_AMBIENT_XFER_COEFF");
    ReplaceTag(pOutput, "#{MPC_AMBIENT_XFER_COEFF_FAN255}", mUi->uMpcAmbientXferCoeffFan255Edit, false, "MPC_AMBIENT_XFER_COEFF_FAN255");
    ReplaceTag(pOutput, "#{MPC_FAN_0_ALL_HOTENDS}", mUi->uMpcFan0AllHotendsBox, "MPC_FAN_0_ALL_HOTENDS");
    ReplaceTag(pOutput, "#{MPC_FAN_0_ACTIVE_HOTEND}", mUi->uMpcFan0ActiveHotendBox, "MPC_FAN_0_ACTIVE_HOTEND");
    ReplaceTag(pOutput, "#{FILAMENT_HEAT_CAPACITY_PERMM}", mUi->uFilamentHeatCapacityPermmEdit, false, "FILAMENT_HEAT_CAPACITY_PERMM");
    ReplaceTag(pOutput, "#{MPC_SMOOTHING_FACTOR}", mUi->uMpcSmoothingFactorSpinBox, false, "MPC_SMOOTHING_FACTOR", 1, true);
    ReplaceTag(pOutput, "#{MPC_MIN_AMBIENT_CHANGE}", mUi->uMpcMinAmbientChangeSpinBox, false, "MPC_MIN_AMBIENT_CHANGE", 1, true);
    ReplaceTag(pOutput, "#{MPC_STEADYSTATE}", mUi->uMpcSteadystateSpinBox, false, "MPC_STEADYSTATE", 1, true);
    ReplaceTag(pOutput, "#{MPC_TUNING_POS}", mUi->uMpcTuningPosEdit, false, "MPC_TUNING_POS");
    ReplaceTag(pOutput, "#{MPC_TUNING_END_Z}", mUi->uMpcTuningEndZSpinBox, false, "MPC_TUNING_END_Z", 1, true);
    ReplaceTag(pOutput, "#{PREVENT_COLD_EXTRUSION}", mUi->uPreventColdExtrusionBox, "PREVENT_COLD_EXTRUSION");
    ReplaceTag(pOutput, "#{EXTRUDE_MINTEMP}", mUi->uExtrudeMintempSpinBox, false, "EXTRUDE_MINTEMP");
    ReplaceTag(pOutput, "#{PREVENT_LENGTHY_EXTRUDE}", mUi->uPreventLengthyExtrudeBox, "PREVENT_LENGTHY_EXTRUDE");
    ReplaceTag(pOutput, "#{EXTRUDE_MAXLENGTH}", mUi->uExtrudeMaxlengthSpinBox, false, "EXTRUDE_MAXLENGTH");
    ReplaceTag(pOutput, "#{THERMAL_PROTECTION_HOTENDS}", mUi->uThermalProtectionHotendsBox, "THERMAL_PROTECTION_HOTENDS");
    ReplaceTag(pOutput, "#{THERMAL_PROTECTION_BED}", mUi->uThermalProtectionBedBox, "THERMAL_PROTECTION_BED");
    ReplaceTag(pOutput, "#{THERMAL_PROTECTION_CHAMBER}", mUi->uThermalProtectionChamberBox, "THERMAL_PROTECTION_CHAMBER");
    ReplaceTag(pOutput, "#{THERMAL_PROTECTION_COOLER}", mUi->uThermalProtectionCoolerBox, "THERMAL_PROTECTION_COOLER");
    ReplaceTag(pOutput, "#{PIDTEMPBED}", mUi->uPidtempbedBox, "PIDTEMPBED");
    ReplaceTag(pOutput, "#{BED_LIMIT_SWITCHING}", mUi->uBedLimitSwitchingBox, "BED_LIMIT_SWITCHING");
    ReplaceTag(pOutput, "#{MAX_BED_POWER}", mUi->uMaxBedPowerSpinBox, false, "MAX_BED_POWER");
    ReplaceTag(pOutput, "#{MIN_BED_POWER}", mUi->uMinBedPowerSpinBox, !mUi->uMinBedPowerBox->isChecked(), "MIN_BED_POWER");
    ReplaceTag(pOutput, "#{PID_BED_DEBUG}", mUi->uPidBedDebugBox, "PID_BED_DEBUG");
    ReplaceTag(pOutput, "#{DEFAULT_bedKp}", mUi->uDefaultBedkpSpinBox, false, "DEFAULT_bedKp", 3);
    ReplaceTag(pOutput, "#{DEFAULT_bedKi}", mUi->uDefaultBedkiSpinBox, false, "DEFAULT_bedKi", 3);
    ReplaceTag(pOutput, "#{DEFAULT_bedKd}", mUi->uDefaultBedkdSpinBox, false, "DEFAULT_bedKd", 3);
    ReplaceTag(pOutput, "#{PIDTEMPCHAMBER}", mUi->uPidtempchamberBox, "PIDTEMPCHAMBER");
    ReplaceTag(pOutput, "#{CHAMBER_LIMIT_SWITCHING}", mUi->uChamberLimitSwitchingBox, "CHAMBER_LIMIT_SWITCHING");
    ReplaceTag(pOutput, "#{MAX_CHAMBER_POWER}", mUi->uMaxChamberPowerSpinBox, false, "MAX_CHAMBER_POWER");
    ReplaceTag(pOutput, "#{MIN_CHAMBER_POWER}", mUi->uMinChamberPowerSpinBox, !mUi->uMinChamberPowerBox->isChecked(), "MIN_CHAMBER_POWER");
    ReplaceTag(pOutput, "#{PID_CHAMBER_DEBUG}", mUi->uPidChamberDebugBox, "PID_CHAMBER_DEBUG");
    ReplaceTag(pOutput, "#{DEFAULT_chamberKp}", mUi->uDefaultChamberkpSpinBox, false, "DEFAULT_chamberKp", 3);
    ReplaceTag(pOutput, "#{DEFAULT_chamberKi}", mUi->uDefaultChamberkiSpinBox, false, "DEFAULT_chamberKi", 3);
    ReplaceTag(pOutput, "#{DEFAULT_chamberKd}", mUi->uDefaultChamberkdSpinBox, false, "DEFAULT_chamberKd", 3);
    ReplaceTag(pOutput, "#{PID_OPENLOOP}", mUi->uPidOpenloopBox, "PID_OPENLOOP");
    ReplaceTag(pOutput, "#{SLOW_PWM_HEATERS}", mUi->uSlowPwmHeatersBox, "SLOW_PWM_HEATERS");
    ReplaceTag(pOutput, "#{PID_FUNCTIONAL_RANGE}", mUi->uPidFunctionalRangeSpinBox, false, "PID_FUNCTIONAL_RANGE");
    ReplaceTag(pOutput, "#{PID_EDIT_MENU}", mUi->uPidEditMenuBox, "PID_EDIT_MENU");
    ReplaceTag(pOutput, "#{PID_AUTOTUNE_MENU}", mUi->uPidAutotuneMenuBox, "PID_AUTOTUNE_MENU");
}
