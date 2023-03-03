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

    mUi->uSwitchingTabWidget->setCurrentIndex(0);
    mUi->uParkingTabWidget->setCurrentIndex(0);

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
            ReplaceArrayTag(pOutput, "#{SWITCHING_EXTRUDER_SERVO_ANGLES}", !mUi->uSwitchingExtruderBox->isChecked(), "SWITCHING_EXTRUDER_SERVO_ANGLES_E0", std::vector<int32_t>{e0, e1, e2, e3});
        }
        else
        {
            ReplaceArrayTag(pOutput, "#{SWITCHING_EXTRUDER_SERVO_ANGLES}", !mUi->uSwitchingExtruderBox->isChecked(), "SWITCHING_EXTRUDER_SERVO_ANGLES_E0", std::vector<int32_t>{e0, e1});
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
        ReplaceArrayTag(pOutput, "#{SWITCHING_NOZZLE_SERVO_ANGLES}", !mUi->uSwitchingNozzleBox->isChecked(), "SWITCHING_NOZZLE_SERVO_ANGLES", std::vector<int32_t>{e0, e1});
    }
    ReplaceTag(pOutput, "#{SWITCHING_NOZZLE_SERVO_DWELL}", mUi->uSwitchingNozzleServoDwellSpinBox, !mUi->uSwitchingNozzleBox->isChecked(), "SWITCHING_NOZZLE_SERVO_DWELL");
}
