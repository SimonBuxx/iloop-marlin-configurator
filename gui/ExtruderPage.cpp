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

#include "ExtruderPage.h"
#include "./ui_ExtruderPage.h"
#include "HelperFunctions.h"

ExtruderPage::ExtruderPage(QWidget *pParent) :
    AbstractPage(EXTRUDER_TEMPLATE_PATH, pParent),
    mUi(new Ui::ExtruderPage)
{
    mUi->setupUi(this);
}

ExtruderPage::~ExtruderPage()
{
    delete mUi;
}

void ExtruderPage::ConnectGuiSignalsAndSlots()
{
    QObject::connect(mUi->uDocumentationButton, &QPushButton::clicked, this, [&]()
    {
        OpenMarlinDocumentation("extruder-info");
    });

    // Only enable SWITCHING_EXTRUDER_E23_SERVO_NR for EXTRUDERS > 3 as per file
    QObject::connect(mUi->uExtrudersSpinBox, &QSpinBox::valueChanged, this, [&](auto pValue)
    {
       mUi->uSwitchingExtruderE23ServoNrBox->setEnabled(pValue > 3);
    });

    QObject::connect(mUi->uParkingExtruderBox, &QGroupBox::toggled, this, [&](auto pState)
    {
        mUi->uParkingExtruderParkingXBox->setEnabled((pState || mUi->uMagneticParkingExtruderBox->isChecked()));
        mUi->uParkingExtruderGrabDistanceBox->setEnabled((pState || mUi->uMagneticParkingExtruderBox->isChecked()));
    });

    QObject::connect(mUi->uMagneticParkingExtruderBox, &QGroupBox::toggled, this, [&](auto pState)
    {
        mUi->uParkingExtruderParkingXBox->setEnabled((pState || mUi->uParkingExtruderBox->isChecked()));
        mUi->uParkingExtruderGrabDistanceBox->setEnabled((pState || mUi->uParkingExtruderBox->isChecked()));
    });

    QObject::connect(mUi->uSwitchingToolheadBox, &QGroupBox::toggled, this, [&](auto pState)
    {
        mUi->uSwitchingToolheadYPosBox->setEnabled((pState || mUi->uMagneticSwitchingToolheadBox->isChecked() || mUi->uElectromagneticSwitchingToolheadBox->isChecked()));
        mUi->uSwitchingToolheadYSecurityBox->setEnabled((pState || mUi->uMagneticSwitchingToolheadBox->isChecked() || mUi->uElectromagneticSwitchingToolheadBox->isChecked()));
        mUi->uSwitchingToolheadYClearBox->setEnabled((pState || mUi->uMagneticSwitchingToolheadBox->isChecked() || mUi->uElectromagneticSwitchingToolheadBox->isChecked()));
        mUi->uSwitchingToolheadXPosBox->setEnabled((pState || mUi->uMagneticSwitchingToolheadBox->isChecked() || mUi->uElectromagneticSwitchingToolheadBox->isChecked()));
    });

    QObject::connect(mUi->uMagneticSwitchingToolheadBox, &QGroupBox::toggled, this, [&](auto pState)
    {
        mUi->uSwitchingToolheadYPosBox->setEnabled((pState || mUi->uSwitchingToolheadBox->isChecked() || mUi->uElectromagneticSwitchingToolheadBox->isChecked()));
        mUi->uSwitchingToolheadYSecurityBox->setEnabled((pState || mUi->uSwitchingToolheadBox->isChecked() || mUi->uElectromagneticSwitchingToolheadBox->isChecked()));
        mUi->uSwitchingToolheadYClearBox->setEnabled((pState || mUi->uSwitchingToolheadBox->isChecked() || mUi->uElectromagneticSwitchingToolheadBox->isChecked()));
        mUi->uSwitchingToolheadXPosBox->setEnabled((pState || mUi->uSwitchingToolheadBox->isChecked() || mUi->uElectromagneticSwitchingToolheadBox->isChecked()));
    });

    QObject::connect(mUi->uElectromagneticSwitchingToolheadBox, &QGroupBox::toggled, this, [&](auto pState)
    {
        mUi->uSwitchingToolheadYPosBox->setEnabled((pState || mUi->uMagneticSwitchingToolheadBox->isChecked() || mUi->uSwitchingToolheadBox->isChecked()));
        mUi->uSwitchingToolheadYSecurityBox->setEnabled((pState || mUi->uMagneticSwitchingToolheadBox->isChecked() || mUi->uSwitchingToolheadBox->isChecked()));
        mUi->uSwitchingToolheadYClearBox->setEnabled((pState || mUi->uMagneticSwitchingToolheadBox->isChecked() || mUi->uSwitchingToolheadBox->isChecked()));
        mUi->uSwitchingToolheadXPosBox->setEnabled((pState || mUi->uMagneticSwitchingToolheadBox->isChecked() || mUi->uSwitchingToolheadBox->isChecked()));
    });

    AbstractPage::ConnectGuiSignalsAndSlots();
}

void ExtruderPage::ResetValues()
{
    mIsLoading = true;

    mUi->uExtrudersSpinBox->setValue(defaults::EXTRUDERS);
    mUi->uDefaultNominalFilamentDiaSpinBox->setValue(defaults::DEFAULT_NOMINAL_FILAMENT_DIA);
    mUi->uSinglenozzleBox->setChecked(defaults::SINGLENOZZLE);
    mUi->uSinglenozzleStandbyTempBox->setChecked(defaults::SINGLENOZZLE_STANDBY_TEMP);
    mUi->uSinglenozzleStandbyFanBox->setChecked(defaults::SINGLENOZZLE_STANDBY_FAN);
    mUi->uMmuModelDropdown->setCurrentText(defaults::MMU_MODEL);
    mUi->uSwitchingExtruderBox->setChecked(defaults::SWITCHING_EXTRUDER);
    mUi->uSwitchingExtruderServoNrSpinBox->setValue(defaults::SWITCHING_EXTRUDER_SERVO_NR);
    mUi->uSwitchingExtruderServoAnglesE0SpinBox->setValue(defaults::SWITCHING_EXTRUDER_SERVO_ANGLES_E0);
    mUi->uSwitchingExtruderServoAnglesE1SpinBox->setValue(defaults::SWITCHING_EXTRUDER_SERVO_ANGLES_E1);
    mUi->uSwitchingExtruderServoAnglesE2SpinBox->setValue(defaults::SWITCHING_EXTRUDER_SERVO_ANGLES_E2);
    mUi->uSwitchingExtruderServoAnglesE3SpinBox->setValue(defaults::SWITCHING_EXTRUDER_SERVO_ANGLES_E3);
    mUi->uSwitchingExtruderE23ServoNrSpinBox->setValue(defaults::SWITCHING_EXTRUDER_E23_SERVO_NR);
    mUi->uSwitchingNozzleBox->setChecked(defaults::SWITCHING_NOZZLE);
    mUi->uSwitchingNozzleServoNrSpinBox->setValue(defaults::SWITCHING_NOZZLE_SERVO_NR);
    mUi->uSwitchingNozzleE1ServoNrSpinBox->setValue(defaults::SWITCHING_NOZZLE_E1_SERVO_NR);
    mUi->uSwitchingNozzleServoAnglesE0SpinBox->setValue(defaults::SWITCHING_NOZZLE_SERVO_ANGLES_E0);
    mUi->uSwitchingNozzleServoAnglesE1SpinBox->setValue(defaults::SWITCHING_NOZZLE_SERVO_ANGLES_E1);
    mUi->uSwitchingNozzleServoDwellSpinBox->setValue(defaults::SWITCHING_NOZZLE_SERVO_DWELL);
    mUi->uParkingExtruderBox->setChecked(defaults::PARKING_EXTRUDER);
    mUi->uMagneticParkingExtruderBox->setChecked(defaults::MAGNETIC_PARKING_EXTRUDER);
    mUi->uParkingExtruderParkingX0SpinBox->setValue(defaults::PARKING_EXTRUDER_PARKING_X_0);
    mUi->uParkingExtruderParkingX1SpinBox->setValue(defaults::PARKING_EXTRUDER_PARKING_X_1);
    mUi->uParkingExtruderGrabDistanceSpinBox->setValue(defaults::PARKING_EXTRUDER_GRAB_DISTANCE);
    mUi->uParkingExtruderSolenoidsInvertBox->setChecked(defaults::PARKING_EXTRUDER_SOLENOIDS_INVERT);
    mUi->uParkingExtruderSolenoidsPinsActiveDropdown->setCurrentText(defaults::PARKING_EXTRUDER_SOLENOIDS_PINS_ACTIVE);
    mUi->uParkingExtruderSolenoidsDelaySpinBox->setValue(defaults::PARKING_EXTRUDER_SOLENOIDS_DELAY);
    mUi->uManualSolenoidControlBox->setChecked(defaults::MANUAL_SOLENOID_CONTROL);
    mUi->uMpeFastSpeedSpinBox->setValue(defaults::MPE_FAST_SPEED);
    mUi->uMpeSlowSpeedSpinBox->setValue(defaults::MPE_SLOW_SPEED);
    mUi->uMpeTravelDistanceSpinBox->setValue(defaults::MPE_TRAVEL_DISTANCE);
    mUi->uMpeCompensationDropdown->setCurrentText(defaults::MPE_COMPENSATION);
    mUi->uSwitchingToolheadBox->setChecked(defaults::SWITCHING_TOOLHEAD);
    mUi->uMagneticSwitchingToolheadBox->setChecked(defaults::MAGNETIC_SWITCHING_TOOLHEAD);
    mUi->uElectromagneticSwitchingToolheadBox->setChecked(defaults::ELECTROMAGNETIC_SWITCHING_TOOLHEAD);
    mUi->uMmuModelBox->setChecked(defaults::ENABLE_MMU_MODEL);
    mUi->uSwitchingExtruderServoAnglesE23Box->setChecked(defaults::ENABLE_SWITCHING_EXTRUDER_SERVO_ANGLES_E23);
    mUi->uSwitchingNozzleE1ServoNrBox->setChecked(defaults::ENABLE_SWITCHING_NOZZLE_E1_SERVO_NR);
    mUi->uParkingExtruderSolenoidsDelayBox->setChecked(defaults::ENABLE_PARKING_EXTRUDER_SOLENOIDS_DELAY);
    mUi->uSwitchingToolheadYPosSpinBox->setValue(defaults::SWITCHING_TOOLHEAD_Y_POS);
    mUi->uSwitchingToolheadYSecuritySpinBox->setValue(defaults::SWITCHING_TOOLHEAD_Y_SECURITY);
    mUi->uSwitchingToolheadYClearSpinBox->setValue(defaults::SWITCHING_TOOLHEAD_Y_CLEAR);
    mUi->uSwitchingToolheadXPos0SpinBox->setValue(defaults::SWITCHING_TOOLHEAD_X_POS0);
    mUi->uSwitchingToolheadXPos1SpinBox->setValue(defaults::SWITCHING_TOOLHEAD_X_POS1);
    mUi->uSwitchingToolheadServoNrSpinBox->setValue(defaults::SWITCHING_TOOLHEAD_SERVO_NR);
    mUi->uSwitchingToolheadServoAngles0SpinBox->setValue(defaults::SWITCHING_TOOLHEAD_SERVO_ANGLES0);
    mUi->uSwitchingToolheadServoAngles1SpinBox->setValue(defaults::SWITCHING_TOOLHEAD_SERVO_ANGLES1);
    mUi->uSwitchingToolheadYReleaseSpinBox->setValue(defaults::SWITCHING_TOOLHEAD_Y_RELEASE);
    mUi->uSwitchingToolheadXSecurityT0SpinBox->setValue(defaults::SWITCHING_TOOLHEAD_X_SECURITY_T0);
    mUi->uSwitchingToolheadXSecurityT1SpinBox->setValue(defaults::SWITCHING_TOOLHEAD_X_SECURITY_T1);
    mUi->uPrimeBeforeRemoveBox->setChecked(defaults::PRIME_BEFORE_REMOVE);
    mUi->uSwitchingToolheadPrimeMmSpinBox->setValue(defaults::SWITCHING_TOOLHEAD_PRIME_MM);
    mUi->uSwitchingToolheadRetractMmSpinBox->setValue(defaults::SWITCHING_TOOLHEAD_RETRACT_MM);
    mUi->uSwitchingToolheadPrimeFeedrateSpinBox->setValue(defaults::SWITCHING_TOOLHEAD_PRIME_FEEDRATE);
    mUi->uSwitchingToolheadRetractFeedrateSpinBox->setValue(defaults::SWITCHING_TOOLHEAD_RETRACT_FEEDRATE);
    mUi->uSwitchingToolheadZHopSpinBox->setValue(defaults::SWITCHING_TOOLHEAD_Z_HOP);
    mUi->uMixingExtruderBox->setChecked(defaults::MIXING_EXTRUDER);
    mUi->uMixingSteppersSpinBox->setValue(defaults::MIXING_STEPPERS);
    mUi->uMixingVirtualToolsSpinBox->setValue(defaults::MIXING_VIRTUAL_TOOLS);
    mUi->uDirectMixingInG1Box->setChecked(defaults::DIRECT_MIXING_IN_G1);
    mUi->uGradientMixBox->setChecked(defaults::GRADIENT_MIX);
    mUi->uMixingPresetsBox->setChecked(defaults::MIXING_PRESETS);
    mUi->uGradientVtoolBox->setChecked(defaults::GRADIENT_VTOOL);
    mUi->uHotendOffsetXEdit->setText(defaults::HOTEND_OFFSET_X);
    mUi->uHotendOffsetYEdit->setText(defaults::HOTEND_OFFSET_Y);
    mUi->uHotendOffsetZEdit->setText(defaults::HOTEND_OFFSET_Z);
    mUi->uHotendOffsetXBox->setChecked(defaults::ENABLE_HOTEND_OFFSET_X);
    mUi->uHotendOffsetYBox->setChecked(defaults::ENABLE_HOTEND_OFFSET_Y);
    mUi->uHotendOffsetZBox->setChecked(defaults::ENABLE_HOTEND_OFFSET_Z);

    mUi->uSwitchingTabWidget->setCurrentIndex(0);
    mUi->uParkingTabWidget->setCurrentIndex(0);
    mUi->uSwitchingToolheadsTabWidget->setCurrentIndex(0);

    mIsLoading = false;
}

bool ExtruderPage::LoadFromJson(const QJsonObject &pJson)
{
    bool success = true;
    mIsLoading = true;

    success &= LoadConfig(mUi->uExtrudersSpinBox, pJson, "EXTRUDERS");
    success &= LoadConfig(mUi->uDefaultNominalFilamentDiaSpinBox, pJson, "DEFAULT_NOMINAL_FILAMENT_DIA");
    success &= LoadConfig(mUi->uSinglenozzleBox, pJson, "SINGLENOZZLE");
    success &= LoadConfig(mUi->uSinglenozzleStandbyTempBox, pJson, "SINGLENOZZLE_STANDBY_TEMP");
    success &= LoadConfig(mUi->uSinglenozzleStandbyFanBox, pJson, "SINGLENOZZLE_STANDBY_FAN");
    success &= LoadConfig(mUi->uMmuModelDropdown, pJson, "MMU_MODEL");
    success &= LoadConfig(mUi->uSwitchingExtruderBox, pJson, "SWITCHING_EXTRUDER");
    success &= LoadConfig(mUi->uSwitchingExtruderServoNrSpinBox, pJson, "SWITCHING_EXTRUDER_SERVO_NR");
    success &= LoadConfig(mUi->uSwitchingExtruderServoAnglesE0SpinBox, pJson, "SWITCHING_EXTRUDER_SERVO_ANGLES_E0");
    success &= LoadConfig(mUi->uSwitchingExtruderServoAnglesE1SpinBox, pJson, "SWITCHING_EXTRUDER_SERVO_ANGLES_E1");
    success &= LoadConfig(mUi->uSwitchingExtruderServoAnglesE2SpinBox, pJson, "SWITCHING_EXTRUDER_SERVO_ANGLES_E2");
    success &= LoadConfig(mUi->uSwitchingExtruderServoAnglesE3SpinBox, pJson, "SWITCHING_EXTRUDER_SERVO_ANGLES_E3");
    success &= LoadConfig(mUi->uSwitchingExtruderE23ServoNrSpinBox, pJson, "SWITCHING_EXTRUDER_E23_SERVO_NR");
    success &= LoadConfig(mUi->uSwitchingNozzleBox, pJson, "SWITCHING_NOZZLE");
    success &= LoadConfig(mUi->uSwitchingNozzleServoNrSpinBox, pJson, "SWITCHING_NOZZLE_SERVO_NR");
    success &= LoadConfig(mUi->uSwitchingNozzleE1ServoNrSpinBox, pJson, "SWITCHING_NOZZLE_E1_SERVO_NR");
    success &= LoadConfig(mUi->uSwitchingNozzleServoAnglesE0SpinBox, pJson, "SWITCHING_NOZZLE_SERVO_ANGLES_E0");
    success &= LoadConfig(mUi->uSwitchingNozzleServoAnglesE1SpinBox, pJson, "SWITCHING_NOZZLE_SERVO_ANGLES_E1");
    success &= LoadConfig(mUi->uSwitchingNozzleServoDwellSpinBox, pJson, "SWITCHING_NOZZLE_SERVO_DWELL");
    success &= LoadConfig(mUi->uParkingExtruderBox, pJson, "PARKING_EXTRUDER");
    success &= LoadConfig(mUi->uMagneticParkingExtruderBox, pJson, "MAGNETIC_PARKING_EXTRUDER");
    success &= LoadConfig(mUi->uParkingExtruderParkingX0SpinBox, pJson, "PARKING_EXTRUDER_PARKING_X_0");
    success &= LoadConfig(mUi->uParkingExtruderParkingX1SpinBox, pJson, "PARKING_EXTRUDER_PARKING_X_1");
    success &= LoadConfig(mUi->uParkingExtruderGrabDistanceSpinBox, pJson, "PARKING_EXTRUDER_GRAB_DISTANCE");
    success &= LoadConfig(mUi->uParkingExtruderSolenoidsInvertBox, pJson, "PARKING_EXTRUDER_SOLENOIDS_INVERT");
    success &= LoadConfig(mUi->uParkingExtruderSolenoidsPinsActiveDropdown, pJson, "PARKING_EXTRUDER_SOLENOIDS_PINS_ACTIVE");
    success &= LoadConfig(mUi->uParkingExtruderSolenoidsDelaySpinBox, pJson, "PARKING_EXTRUDER_SOLENOIDS_DELAY");
    success &= LoadConfig(mUi->uManualSolenoidControlBox, pJson, "MANUAL_SOLENOID_CONTROL");
    success &= LoadConfig(mUi->uMpeFastSpeedSpinBox, pJson, "MPE_FAST_SPEED");
    success &= LoadConfig(mUi->uMpeSlowSpeedSpinBox, pJson, "MPE_SLOW_SPEED");
    success &= LoadConfig(mUi->uMpeTravelDistanceSpinBox, pJson, "MPE_TRAVEL_DISTANCE");
    success &= LoadConfig(mUi->uMpeCompensationDropdown, pJson, "MPE_COMPENSATION");
    success &= LoadConfig(mUi->uSwitchingToolheadBox, pJson, "SWITCHING_TOOLHEAD");
    success &= LoadConfig(mUi->uMagneticSwitchingToolheadBox, pJson, "MAGNETIC_SWITCHING_TOOLHEAD");
    success &= LoadConfig(mUi->uElectromagneticSwitchingToolheadBox, pJson, "ELECTROMAGNETIC_SWITCHING_TOOLHEAD");
    success &= LoadConfig(mUi->uMmuModelBox, pJson, "ENABLE_MMU_MODEL");
    success &= LoadConfig(mUi->uSwitchingExtruderServoAnglesE23Box, pJson, "ENABLE_SWITCHING_EXTRUDER_SERVO_ANGLES_E23");
    success &= LoadConfig(mUi->uSwitchingNozzleE1ServoNrBox, pJson, "ENABLE_SWITCHING_NOZZLE_E1_SERVO_NR");
    success &= LoadConfig(mUi->uParkingExtruderSolenoidsDelayBox, pJson, "ENABLE_PARKING_EXTRUDER_SOLENOIDS_DELAY");
    success &= LoadConfig(mUi->uSwitchingToolheadYPosSpinBox, pJson, "SWITCHING_TOOLHEAD_Y_POS");
    success &= LoadConfig(mUi->uSwitchingToolheadYSecuritySpinBox, pJson, "SWITCHING_TOOLHEAD_Y_SECURITY");
    success &= LoadConfig(mUi->uSwitchingToolheadYClearSpinBox, pJson, "SWITCHING_TOOLHEAD_Y_CLEAR");
    success &= LoadConfig(mUi->uSwitchingToolheadXPos0SpinBox, pJson, "SWITCHING_TOOLHEAD_X_POS0");
    success &= LoadConfig(mUi->uSwitchingToolheadXPos1SpinBox, pJson, "SWITCHING_TOOLHEAD_X_POS1");
    success &= LoadConfig(mUi->uSwitchingToolheadServoNrSpinBox, pJson, "SWITCHING_TOOLHEAD_SERVO_NR");
    success &= LoadConfig(mUi->uSwitchingToolheadServoAngles0SpinBox, pJson, "SWITCHING_TOOLHEAD_SERVO_ANGLES0");
    success &= LoadConfig(mUi->uSwitchingToolheadServoAngles1SpinBox, pJson, "SWITCHING_TOOLHEAD_SERVO_ANGLES1");
    success &= LoadConfig(mUi->uSwitchingToolheadYReleaseSpinBox, pJson, "SWITCHING_TOOLHEAD_Y_RELEASE");
    success &= LoadConfig(mUi->uSwitchingToolheadXSecurityT0SpinBox, pJson, "SWITCHING_TOOLHEAD_X_SECURITY_T0");
    success &= LoadConfig(mUi->uSwitchingToolheadXSecurityT1SpinBox, pJson, "SWITCHING_TOOLHEAD_X_SECURITY_T1");
    success &= LoadConfig(mUi->uPrimeBeforeRemoveBox, pJson, "PRIME_BEFORE_REMOVE");
    success &= LoadConfig(mUi->uSwitchingToolheadPrimeMmSpinBox, pJson, "SWITCHING_TOOLHEAD_PRIME_MM");
    success &= LoadConfig(mUi->uSwitchingToolheadRetractMmSpinBox, pJson, "SWITCHING_TOOLHEAD_RETRACT_MM");
    success &= LoadConfig(mUi->uSwitchingToolheadPrimeFeedrateSpinBox, pJson, "SWITCHING_TOOLHEAD_PRIME_FEEDRATE");
    success &= LoadConfig(mUi->uSwitchingToolheadRetractFeedrateSpinBox, pJson, "SWITCHING_TOOLHEAD_RETRACT_FEEDRATE");
    success &= LoadConfig(mUi->uSwitchingToolheadZHopSpinBox, pJson, "SWITCHING_TOOLHEAD_Z_HOP");
    success &= LoadConfig(mUi->uMixingExtruderBox, pJson, "MIXING_EXTRUDER");
    success &= LoadConfig(mUi->uMixingSteppersSpinBox, pJson, "MIXING_STEPPERS");
    success &= LoadConfig(mUi->uMixingVirtualToolsSpinBox, pJson, "MIXING_VIRTUAL_TOOLS");
    success &= LoadConfig(mUi->uDirectMixingInG1Box, pJson, "DIRECT_MIXING_IN_G1");
    success &= LoadConfig(mUi->uGradientMixBox, pJson, "GRADIENT_MIX");
    success &= LoadConfig(mUi->uMixingPresetsBox, pJson, "MIXING_PRESETS");
    success &= LoadConfig(mUi->uGradientVtoolBox, pJson, "GRADIENT_VTOOL");
    success &= LoadConfig(mUi->uHotendOffsetXEdit, pJson, "HOTEND_OFFSET_X");
    success &= LoadConfig(mUi->uHotendOffsetYEdit, pJson, "HOTEND_OFFSET_Y");
    success &= LoadConfig(mUi->uHotendOffsetZEdit, pJson, "HOTEND_OFFSET_Z");
    success &= LoadConfig(mUi->uHotendOffsetXBox, pJson, "ENABLE_HOTEND_OFFSET_X");
    success &= LoadConfig(mUi->uHotendOffsetYBox, pJson, "ENABLE_HOTEND_OFFSET_Y");
    success &= LoadConfig(mUi->uHotendOffsetZBox, pJson, "ENABLE_HOTEND_OFFSET_Z");

    mIsLoading = false;
    return success;
}

void ExtruderPage::FetchConfiguration(Configuration& pConfig)
{
    SetConfig(pConfig.extruder.EXTRUDERS, mUi->uExtrudersSpinBox);
    SetConfig(pConfig.extruder.DEFAULT_NOMINAL_FILAMENT_DIA, mUi->uDefaultNominalFilamentDiaSpinBox);
    SetConfig(pConfig.extruder.SINGLENOZZLE, mUi->uSinglenozzleBox);
    SetConfig(pConfig.extruder.SINGLENOZZLE_STANDBY_TEMP, mUi->uSinglenozzleStandbyTempBox);
    SetConfig(pConfig.extruder.SINGLENOZZLE_STANDBY_FAN, mUi->uSinglenozzleStandbyFanBox);
    SetConfig(pConfig.extruder.MMU_MODEL, mUi->uMmuModelDropdown);
    SetConfig(pConfig.extruder.SWITCHING_EXTRUDER, mUi->uSwitchingExtruderBox);
    SetConfig(pConfig.extruder.SWITCHING_EXTRUDER_SERVO_NR, mUi->uSwitchingExtruderServoNrSpinBox);
    SetConfig(pConfig.extruder.SWITCHING_EXTRUDER_SERVO_ANGLES_E0, mUi->uSwitchingExtruderServoAnglesE0SpinBox);
    SetConfig(pConfig.extruder.SWITCHING_EXTRUDER_SERVO_ANGLES_E1, mUi->uSwitchingExtruderServoAnglesE1SpinBox);
    SetConfig(pConfig.extruder.SWITCHING_EXTRUDER_SERVO_ANGLES_E2, mUi->uSwitchingExtruderServoAnglesE2SpinBox);
    SetConfig(pConfig.extruder.SWITCHING_EXTRUDER_SERVO_ANGLES_E3, mUi->uSwitchingExtruderServoAnglesE3SpinBox);
    SetConfig(pConfig.extruder.SWITCHING_EXTRUDER_E23_SERVO_NR, mUi->uSwitchingExtruderE23ServoNrSpinBox);
    SetConfig(pConfig.extruder.SWITCHING_NOZZLE, mUi->uSwitchingNozzleBox);
    SetConfig(pConfig.extruder.SWITCHING_NOZZLE_SERVO_NR, mUi->uSwitchingNozzleServoNrSpinBox);
    SetConfig(pConfig.extruder.SWITCHING_NOZZLE_E1_SERVO_NR, mUi->uSwitchingNozzleE1ServoNrSpinBox);
    SetConfig(pConfig.extruder.SWITCHING_NOZZLE_SERVO_ANGLES_E0, mUi->uSwitchingNozzleServoAnglesE0SpinBox);
    SetConfig(pConfig.extruder.SWITCHING_NOZZLE_SERVO_ANGLES_E1, mUi->uSwitchingNozzleServoAnglesE1SpinBox);
    SetConfig(pConfig.extruder.SWITCHING_NOZZLE_SERVO_DWELL, mUi->uSwitchingNozzleServoDwellSpinBox);
    SetConfig(pConfig.extruder.PARKING_EXTRUDER, mUi->uParkingExtruderBox);
    SetConfig(pConfig.extruder.MAGNETIC_PARKING_EXTRUDER, mUi->uMagneticParkingExtruderBox);
    SetConfig(pConfig.extruder.PARKING_EXTRUDER_PARKING_X_0, mUi->uParkingExtruderParkingX0SpinBox);
    SetConfig(pConfig.extruder.PARKING_EXTRUDER_PARKING_X_1, mUi->uParkingExtruderParkingX1SpinBox);
    SetConfig(pConfig.extruder.PARKING_EXTRUDER_GRAB_DISTANCE, mUi->uParkingExtruderGrabDistanceSpinBox);
    SetConfig(pConfig.extruder.PARKING_EXTRUDER_SOLENOIDS_INVERT, mUi->uParkingExtruderSolenoidsInvertBox);
    SetConfig(pConfig.extruder.PARKING_EXTRUDER_SOLENOIDS_PINS_ACTIVE, mUi->uParkingExtruderSolenoidsPinsActiveDropdown);
    SetConfig(pConfig.extruder.PARKING_EXTRUDER_SOLENOIDS_DELAY, mUi->uParkingExtruderSolenoidsDelaySpinBox);
    SetConfig(pConfig.extruder.MANUAL_SOLENOID_CONTROL, mUi->uManualSolenoidControlBox);
    SetConfig(pConfig.extruder.MPE_FAST_SPEED, mUi->uMpeFastSpeedSpinBox);
    SetConfig(pConfig.extruder.MPE_SLOW_SPEED, mUi->uMpeSlowSpeedSpinBox);
    SetConfig(pConfig.extruder.MPE_TRAVEL_DISTANCE, mUi->uMpeTravelDistanceSpinBox);
    SetConfig(pConfig.extruder.MPE_COMPENSATION, mUi->uMpeCompensationDropdown);
    SetConfig(pConfig.extruder.SWITCHING_TOOLHEAD, mUi->uSwitchingToolheadBox);
    SetConfig(pConfig.extruder.MAGNETIC_SWITCHING_TOOLHEAD, mUi->uMagneticSwitchingToolheadBox);
    SetConfig(pConfig.extruder.ELECTROMAGNETIC_SWITCHING_TOOLHEAD, mUi->uElectromagneticSwitchingToolheadBox);
    SetConfig(pConfig.extruder.ENABLE_MMU_MODEL, mUi->uMmuModelBox);
    SetConfig(pConfig.extruder.ENABLE_SWITCHING_EXTRUDER_SERVO_ANGLES_E23, mUi->uSwitchingExtruderServoAnglesE23Box);
    SetConfig(pConfig.extruder.ENABLE_SWITCHING_NOZZLE_E1_SERVO_NR, mUi->uSwitchingNozzleE1ServoNrBox);
    SetConfig(pConfig.extruder.ENABLE_PARKING_EXTRUDER_SOLENOIDS_DELAY, mUi->uParkingExtruderSolenoidsDelayBox);
    SetConfig(pConfig.extruder.SWITCHING_TOOLHEAD_Y_POS, mUi->uSwitchingToolheadYPosSpinBox);
    SetConfig(pConfig.extruder.SWITCHING_TOOLHEAD_Y_SECURITY, mUi->uSwitchingToolheadYSecuritySpinBox);
    SetConfig(pConfig.extruder.SWITCHING_TOOLHEAD_Y_CLEAR, mUi->uSwitchingToolheadYClearSpinBox);
    SetConfig(pConfig.extruder.SWITCHING_TOOLHEAD_X_POS0, mUi->uSwitchingToolheadXPos0SpinBox);
    SetConfig(pConfig.extruder.SWITCHING_TOOLHEAD_X_POS1, mUi->uSwitchingToolheadXPos1SpinBox);
    SetConfig(pConfig.extruder.SWITCHING_TOOLHEAD_SERVO_NR, mUi->uSwitchingToolheadServoNrSpinBox);
    SetConfig(pConfig.extruder.SWITCHING_TOOLHEAD_SERVO_ANGLES0, mUi->uSwitchingToolheadServoAngles0SpinBox);
    SetConfig(pConfig.extruder.SWITCHING_TOOLHEAD_SERVO_ANGLES1, mUi->uSwitchingToolheadServoAngles1SpinBox);
    SetConfig(pConfig.extruder.SWITCHING_TOOLHEAD_Y_RELEASE, mUi->uSwitchingToolheadYReleaseSpinBox);
    SetConfig(pConfig.extruder.SWITCHING_TOOLHEAD_X_SECURITY_T0, mUi->uSwitchingToolheadXSecurityT0SpinBox);
    SetConfig(pConfig.extruder.SWITCHING_TOOLHEAD_X_SECURITY_T1, mUi->uSwitchingToolheadXSecurityT1SpinBox);
    SetConfig(pConfig.extruder.PRIME_BEFORE_REMOVE, mUi->uPrimeBeforeRemoveBox);
    SetConfig(pConfig.extruder.SWITCHING_TOOLHEAD_PRIME_MM, mUi->uSwitchingToolheadPrimeMmSpinBox);
    SetConfig(pConfig.extruder.SWITCHING_TOOLHEAD_RETRACT_MM, mUi->uSwitchingToolheadRetractMmSpinBox);
    SetConfig(pConfig.extruder.SWITCHING_TOOLHEAD_PRIME_FEEDRATE, mUi->uSwitchingToolheadPrimeFeedrateSpinBox);
    SetConfig(pConfig.extruder.SWITCHING_TOOLHEAD_RETRACT_FEEDRATE, mUi->uSwitchingToolheadRetractFeedrateSpinBox);
    SetConfig(pConfig.extruder.SWITCHING_TOOLHEAD_Z_HOP, mUi->uSwitchingToolheadZHopSpinBox);
    SetConfig(pConfig.extruder.MIXING_EXTRUDER, mUi->uMixingExtruderBox);
    SetConfig(pConfig.extruder.MIXING_STEPPERS, mUi->uMixingSteppersSpinBox);
    SetConfig(pConfig.extruder.MIXING_VIRTUAL_TOOLS, mUi->uMixingVirtualToolsSpinBox);
    SetConfig(pConfig.extruder.DIRECT_MIXING_IN_G1, mUi->uDirectMixingInG1Box);
    SetConfig(pConfig.extruder.GRADIENT_MIX, mUi->uGradientMixBox);
    SetConfig(pConfig.extruder.MIXING_PRESETS, mUi->uMixingPresetsBox);
    SetConfig(pConfig.extruder.GRADIENT_VTOOL, mUi->uGradientVtoolBox);
    SetConfig(pConfig.extruder.HOTEND_OFFSET_X, mUi->uHotendOffsetXEdit);
    SetConfig(pConfig.extruder.HOTEND_OFFSET_Y, mUi->uHotendOffsetYEdit);
    SetConfig(pConfig.extruder.HOTEND_OFFSET_Z, mUi->uHotendOffsetZEdit);
    SetConfig(pConfig.extruder.ENABLE_HOTEND_OFFSET_X, mUi->uHotendOffsetXBox);
    SetConfig(pConfig.extruder.ENABLE_HOTEND_OFFSET_Y, mUi->uHotendOffsetYBox);
    SetConfig(pConfig.extruder.ENABLE_HOTEND_OFFSET_Z, mUi->uHotendOffsetZBox);
}

void ExtruderPage::ReplaceTags(QStringList& pOutput)
{
    ReplaceTag(pOutput, "#{EXTRUDERS}", mUi->uExtrudersSpinBox, false, "EXTRUDERS");
    ReplaceTag(pOutput, "#{DEFAULT_NOMINAL_FILAMENT_DIA}", mUi->uDefaultNominalFilamentDiaSpinBox, false, "DEFAULT_NOMINAL_FILAMENT_DIA");
    ReplaceTag(pOutput, "#{SINGLENOZZLE}", mUi->uSinglenozzleBox, "SINGLENOZZLE");
    ReplaceTag(pOutput, "#{SINGLENOZZLE_STANDBY_TEMP}", mUi->uSinglenozzleStandbyTempBox, "SINGLENOZZLE_STANDBY_TEMP");
    ReplaceTag(pOutput, "#{SINGLENOZZLE_STANDBY_FAN}", mUi->uSinglenozzleStandbyFanBox, "SINGLENOZZLE_STANDBY_FAN");
    ReplaceTag(pOutput, "#{MMU_MODEL}", mUi->uMmuModelDropdown, !mUi->uMmuModelBox->isChecked(), "MMU_MODEL", true);
    ReplaceTag(pOutput, "#{SWITCHING_EXTRUDER}", mUi->uSwitchingExtruderBox, "SWITCHING_EXTRUDER");
    ReplaceTag(pOutput, "#{SWITCHING_EXTRUDER_SERVO_NR}", mUi->uSwitchingExtruderServoNrSpinBox, !mUi->uSwitchingExtruderBox->isChecked(), "SWITCHING_EXTRUDER_SEVRO_NR");
    {
        const auto& e0 = mUi->uSwitchingExtruderServoAnglesE0SpinBox->value();
        const auto& e1 = mUi->uSwitchingExtruderServoAnglesE1SpinBox->value();
        const auto& e2 = mUi->uSwitchingExtruderServoAnglesE2SpinBox->value();
        const auto& e3 = mUi->uSwitchingExtruderServoAnglesE3SpinBox->value();
        if (mUi->uSwitchingExtruderServoAnglesE23Box->isChecked())
        {
            ReplaceArrayTag(pOutput, "#{SWITCHING_EXTRUDER_SERVO_ANGLES}", !mUi->uSwitchingExtruderBox->isChecked(), "SWITCHING_EXTRUDER_SERVO_ANGLES_E0", std::vector<int32_t>{e0, e1, e2, e3}, mUi->uSwitchingExtruderServoAnglesE23Box->isEnabled());
        }
        else
        {
            ReplaceArrayTag(pOutput, "#{SWITCHING_EXTRUDER_SERVO_ANGLES}", !mUi->uSwitchingExtruderBox->isChecked(), "SWITCHING_EXTRUDER_SERVO_ANGLES_E0", std::vector<int32_t>{e0, e1}, mUi->uSwitchingExtruderServoAnglesE23Box->isEnabled());
        }
    }
    ReplaceTag(pOutput, "#{SWITCHING_EXTRUDER_SERVO_ANGLES_E1}", mUi->uSwitchingExtruderServoAnglesE1SpinBox, !mUi->uSwitchingExtruderBox->isChecked(), "SWITCHING_EXTRUDER_SERVO_ANGLES_E1");
    ReplaceTag(pOutput, "#{SWITCHING_EXTRUDER_SERVO_ANGLES_E2}", mUi->uSwitchingExtruderServoAnglesE2SpinBox, !mUi->uSwitchingExtruderBox->isChecked(), "SWITCHING_EXTRUDER_SERVO_ANGLES_E2");
    ReplaceTag(pOutput, "#{SWITCHING_EXTRUDER_SERVO_ANGLES_E3}", mUi->uSwitchingExtruderServoAnglesE3SpinBox, !mUi->uSwitchingExtruderBox->isChecked(), "SWITCHING_EXTRUDER_SERVO_ANGLES_E3");
    ReplaceTag(pOutput, "#{SWITCHING_EXTRUDER_E23_SERVO_NR}", mUi->uSwitchingExtruderE23ServoNrSpinBox, !mUi->uSwitchingExtruderBox->isChecked() || (mUi->uExtrudersSpinBox->value() <= 3), "SWITCHING_EXTRUDER_E23_SERVO_NR");
    ReplaceTag(pOutput, "#{SWITCHING_NOZZLE}", mUi->uSwitchingNozzleBox, "SWITCHING_NOZZLE");
    ReplaceTag(pOutput, "#{SWITCHING_NOZZLE_SERVO_NR}", mUi->uSwitchingNozzleServoNrSpinBox, !mUi->uSwitchingNozzleBox->isChecked(), "SWITCHING_NOZZLE_SERVO_NR");
    ReplaceTag(pOutput, "#{SWITCHING_NOZZLE_E1_SERVO_NR}", mUi->uSwitchingNozzleE1ServoNrSpinBox,  !mUi->uSwitchingNozzleBox->isChecked() || !mUi->uSwitchingNozzleE1ServoNrBox->isChecked(), "SWITCHING_NOZZLE_E1_SERVO_NR");
    {
        const auto& e0 = mUi->uSwitchingNozzleServoAnglesE0SpinBox->value();
        const auto& e1 = mUi->uSwitchingNozzleServoAnglesE1SpinBox->value();
        ReplaceArrayTag(pOutput, "#{SWITCHING_NOZZLE_SERVO_ANGLES}", !mUi->uSwitchingNozzleBox->isChecked(), "SWITCHING_NOZZLE_SERVO_ANGLES", std::vector<int32_t>{e0, e1}, mUi->uSwitchingNozzleBox->isEnabled());
    }
    ReplaceTag(pOutput, "#{SWITCHING_NOZZLE_SERVO_DWELL}", mUi->uSwitchingNozzleServoDwellSpinBox, !mUi->uSwitchingNozzleBox->isChecked(), "SWITCHING_NOZZLE_SERVO_DWELL");
    ReplaceTag(pOutput, "#{PARKING_EXTRUDER}", mUi->uParkingExtruderBox, "PARKING_EXTRUDER");
    ReplaceTag(pOutput, "#{MAGNETIC_PARKING_EXTRUDER}", mUi->uMagneticParkingExtruderBox, "MAGNETIC_PARKING_EXTRUDER");
    {
        const auto& x0 = mUi->uParkingExtruderParkingX0SpinBox->value();
        const auto& x1 = mUi->uParkingExtruderParkingX1SpinBox->value();
        ReplaceArrayTag(pOutput, "#{PARKING_EXTRUDER_PARKING_X}", !mUi->uParkingExtruderBox->isChecked() && !mUi->uMagneticParkingExtruderBox->isChecked(), "PARKING_EXTRUDER_PARKING_X", std::vector<int32_t>{x0, x1}, mUi->uParkingExtruderParkingXBox->isEnabled());
    }
    ReplaceTag(pOutput, "#{PARKING_EXTRUDER_GRAB_DISTANCE}", mUi->uParkingExtruderGrabDistanceSpinBox, !mUi->uParkingExtruderBox->isChecked() && !mUi->uMagneticParkingExtruderBox->isChecked(), "PARKING_EXTRUDER_GRAB_DISTANCE");
    ReplaceTag(pOutput, "#{PARKING_EXTRUDER_SOLENOIDS_INVERT}", mUi->uParkingExtruderSolenoidsInvertBox, "PARKING_EXTRUDER_SOLENOIDS_INVERT");
    ReplaceTag(pOutput, "#{PARKING_EXTRUDER_SOLENOIDS_PINS_ACTIVE}", mUi->uParkingExtruderSolenoidsPinsActiveDropdown, false, "PARKING_EXTRUDER_SOLENOIDS_PINS_ACTIVE");
    ReplaceTag(pOutput, "#{PARKING_EXTRUDER_SOLENOIDS_DELAY}", mUi->uParkingExtruderSolenoidsDelaySpinBox, false, "PARKING_EXTRUDER_SOLENOIDS_DELAY");
    ReplaceTag(pOutput, "#{MANUAL_SOLENOID_CONTROL}", mUi->uManualSolenoidControlBox, "MANUAL_SOLENOID_CONTROL");
    ReplaceTag(pOutput, "#{MPE_FAST_SPEED}", mUi->uMpeFastSpeedSpinBox, false, "MPE_FAST_SPEED");
    ReplaceTag(pOutput, "#{MPE_SLOW_SPEED}", mUi->uMpeSlowSpeedSpinBox, false, "MPE_SLOW_SPEED");
    ReplaceTag(pOutput, "#{MPE_TRAVEL_DISTANCE}", mUi->uMpeTravelDistanceSpinBox, false, "MPE_TRAVEL_DISTANCE");
    ReplaceTag(pOutput, "#{MPE_COMPENSATION}", mUi->uMpeCompensationDropdown, false, "MPE_COMPENSATION");
    ReplaceTag(pOutput, "#{SWITCHING_TOOLHEAD}", mUi->uSwitchingToolheadBox, "SWITCHING_TOOLHEAD");
    ReplaceTag(pOutput, "#{MAGNETIC_SWITCHING_TOOLHEAD}", mUi->uMagneticSwitchingToolheadBox, "MAGNETIC_SWITCHING_TOOLHEAD");
    ReplaceTag(pOutput, "#{ELECTROMAGNETIC_SWITCHING_TOOLHEAD}", mUi->uElectromagneticSwitchingToolheadBox, "ELECTROMAGNETIC_SWITCHING_TOOLHEAD");
    ReplaceTag(pOutput, "#{SWITCHING_TOOLHEAD_Y_POS}", mUi->uSwitchingToolheadYPosSpinBox, !mUi->uSwitchingToolheadBox->isChecked() && !mUi->uMagneticSwitchingToolheadBox->isChecked() &&
                                                                                           !mUi->uElectromagneticSwitchingToolheadBox->isChecked(), "SWITCHING_TOOLHEAD_Y_POS");
    ReplaceTag(pOutput, "#{SWITCHING_TOOLHEAD_Y_CLEAR}", mUi->uSwitchingToolheadYClearSpinBox, !mUi->uSwitchingToolheadBox->isChecked() && !mUi->uMagneticSwitchingToolheadBox->isChecked() &&
                                                                                               !mUi->uElectromagneticSwitchingToolheadBox->isChecked(), "SWITCHING_TOOLHEAD_Y_CLEAR");
    ReplaceTag(pOutput, "#{SWITCHING_TOOLHEAD_Y_SECURITY}", mUi->uSwitchingToolheadYSecuritySpinBox, !mUi->uSwitchingToolheadBox->isChecked() && !mUi->uMagneticSwitchingToolheadBox->isChecked() &&
                                                                                                   !mUi->uElectromagneticSwitchingToolheadBox->isChecked(), "SWITCHING_TOOLHEAD_Y_SECURITY");
    {
        const auto& x0 = mUi->uSwitchingToolheadXPos0SpinBox->value();
        const auto& x1 = mUi->uSwitchingToolheadXPos1SpinBox->value();
        ReplaceArrayTag(pOutput, "#{SWITCHING_TOOLHEAD_X_POS}", !mUi->uSwitchingToolheadBox->isChecked() && !mUi->uMagneticSwitchingToolheadBox->isChecked() &&
                                                                    !mUi->uElectromagneticSwitchingToolheadBox->isChecked(), "SWITCHING_TOOLHEAD_X_POS", std::vector<int32_t>{x0, x1}, mUi->uSwitchingToolheadXPosBox->isEnabled());
    }
    ReplaceTag(pOutput, "#{SWITCHING_TOOLHEAD_SERVO_NR}", mUi->uSwitchingToolheadServoNrSpinBox, false, "SWITCHING_TOOLHEAD_SERVO_NR");
    {
        const auto& x0 = mUi->uSwitchingToolheadServoAngles0SpinBox->value();
        const auto& x1 = mUi->uSwitchingToolheadServoAngles1SpinBox->value();
        ReplaceArrayTag(pOutput, "#{SWITCHING_TOOLHEAD_SERVO_ANGLES}", false, "SWITCHING_TOOLHEAD_SERVO_ANGLES", std::vector<int32_t>{x0, x1}, mUi->uSwitchingToolheadServoAnglesBox->isEnabled());
    }
    ReplaceTag(pOutput, "#{SWITCHING_TOOLHEAD_Y_RELEASE}", mUi->uSwitchingToolheadYReleaseSpinBox, false, "SWITCHING_TOOLHEAD_Y_RELEASE");
    {
        const auto& t0 = mUi->uSwitchingToolheadXSecurityT0SpinBox->value();
        const auto& t1 = mUi->uSwitchingToolheadXSecurityT1SpinBox->value();
        ReplaceArrayTag(pOutput, "#{SWITCHING_TOOLHEAD_X_SECURITY}", false, "SWITCHING_TOOLHEAD_X_SECURITY", std::vector<int32_t>{t0, t1}, mUi->uSwitchingToolheadXSecurityBox->isEnabled());
    }
    ReplaceTag(pOutput, "#{PRIME_BEFORE_REMOVE}", mUi->uPrimeBeforeRemoveBox, "PRIME_BEFORE_REMOVE");
    ReplaceTag(pOutput, "#{SWITCHING_TOOLHEAD_PRIME_MM}", mUi->uSwitchingToolheadPrimeMmSpinBox, false, "SWITCHING_TOOLHEAD_PRIME_MM");
    ReplaceTag(pOutput, "#{SWITCHING_TOOLHEAD_RETRACT_MM}", mUi->uSwitchingToolheadRetractMmSpinBox, false, "SWITCHING_TOOLHEAD_RETRACT_MM");
    ReplaceTag(pOutput, "#{SWITCHING_TOOLHEAD_PRIME_FEEDRATE}", mUi->uSwitchingToolheadPrimeFeedrateSpinBox, false, "SWITCHING_TOOLHEAD_PRIME_FEEDRATE");
    ReplaceTag(pOutput, "#{SWITCHING_TOOLHEAD_RETRACT_FEEDRATE}", mUi->uSwitchingToolheadRetractFeedrateSpinBox, false, "SWITCHING_TOOLHEAD_RETRACT_FEEDRATE");
    ReplaceTag(pOutput, "#{SWITCHING_TOOLHEAD_Z_HOP}", mUi->uSwitchingToolheadZHopSpinBox, false, "SWITCHING_TOOLHEAD_Z_HOP");
    ReplaceTag(pOutput, "#{MIXING_EXTRUDER}", mUi->uMixingExtruderBox, "MIXING_EXTRUDER");
    ReplaceTag(pOutput, "#{MIXING_STEPPERS}", mUi->uMixingSteppersSpinBox, false, "MIXING_STEPPERS");
    ReplaceTag(pOutput, "#{MIXING_VIRTUAL_TOOLS}", mUi->uMixingVirtualToolsSpinBox, false, "MIXING_VIRTUAL_TOOLS");
    ReplaceTag(pOutput, "#{DIRECT_MIXING_IN_G1}", mUi->uDirectMixingInG1Box, "DIRECT_MIXING_IN_G1");
    ReplaceTag(pOutput, "#{GRADIENT_MIX}", mUi->uGradientMixBox, "GRADIENT_MIX");
    ReplaceTag(pOutput, "#{MIXING_PRESETS}", mUi->uMixingPresetsBox, "MIXING_PRESETS");
    ReplaceTag(pOutput, "#{GRADIENT_VTOOL}", mUi->uGradientVtoolBox, "GRADIENT_VTOOL");
    ReplaceTag(pOutput, "#{HOTEND_OFFSET_X}", mUi->uHotendOffsetXEdit, !mUi->uHotendOffsetXBox->isEnabled(), "HOTEND_OFFSET_X");
    ReplaceTag(pOutput, "#{HOTEND_OFFSET_Y}", mUi->uHotendOffsetYEdit, !mUi->uHotendOffsetYBox->isEnabled(), "HOTEND_OFFSET_Y");
    ReplaceTag(pOutput, "#{HOTEND_OFFSET_Z}", mUi->uHotendOffsetZEdit, !mUi->uHotendOffsetZBox->isEnabled(), "HOTEND_OFFSET_Z");
}
