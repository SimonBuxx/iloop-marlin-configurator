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
    QObject::connect(mUi->uExtrudersBox, &QSpinBox::valueChanged, this, [&](auto pValue)
    {
       mUi->uSwitchingExtruderE23ServoNrBox->setEnabled(pValue > 3);
    });

    AbstractPage::ConnectGuiSignalsAndSlots();
}

void ExtruderPage::ResetValues()
{
    mUi->uExtrudersBox->setValue(defaults::EXTRUDERS);
    mUi->uDefaultNominalFilamentDiaBox->setValue(defaults::DEFAULT_NOMINAL_FILAMENT_DIA);
    mUi->uSingleNozzleBox->setChecked(defaults::SINGLENOZZLE);
    mUi->uSingleNozzleStandbyTempBox->setChecked(defaults::SINGLENOZZLE_STANDBY_TEMP);
    mUi->uSingleNozzleStandbyFanBox->setChecked(defaults::SINGLENOZZLE_STANDBY_FAN);
    mUi->uMmuModelBox->setChecked(defaults::ENABLE_MMU_MODEL);
    mUi->uMmuModelComboBox->setCurrentText(defaults::MMU_MODEL);
    mUi->uSwitchingExtruderBox->setChecked(defaults::SWITCHING_EXTRUDER);
    mUi->uSwitchingExtruderServoNrBox->setValue(defaults::SWITCHING_EXTRUDER_SEVRO_NR);
    mUi->uSwitchingExtruderServoAnglesE0SpinBox->setValue(defaults::SWITCHING_EXTRUDER_SERVO_ANGLES_E0);
    mUi->uSwitchingExtruderServoAnglesE1SpinBox->setValue(defaults::SWITCHING_EXTRUDER_SERVO_ANGLES_E1);
    mUi->uSwitchingExtruderServoAnglesE2SpinBox->setValue(defaults::SWITCHING_EXTRUDER_SERVO_ANGLES_E2);
    mUi->uSwitchingExtruderServoAnglesE23Box->setChecked(defaults::ENABLE_SWITCHING_EXTRUDER_SERVO_ANGLES_E23);
    mUi->uSwitchingExtruderServoAnglesE3SpinBox->setValue(defaults::SWITCHING_EXTRUDER_SERVO_ANGLES_E3);
    mUi->uSwitchingExtruderE23ServoNrSpinBox->setValue(defaults::SWITCHING_EXTRUDER_E23_SERVO_NR);
    mUi->uSwitchingNozzleBox->setChecked(defaults::SWITCHING_NOZZLE);
    mUi->uSwitchingNozzleServoNrBox->setValue(defaults::SWITCHING_NOZZLE_SERVO_NR);
    mUi->uSwitchingNozzleE1ServoNrSpinBox->setValue(defaults::SWITCHING_NOZZLE_E1_SERVO_NR);
    mUi->uSwitchingNozzleE1ServoNrBox->setChecked(defaults::ENABLE_SWITCHING_NOZZLE_E1_SERVO_NR);
    mUi->uSwitchingNozzleServoAnglesE0Box->setValue(defaults::SWITCHING_NOZZLE_SERVO_ANGLES_E0);
    mUi->uSwitchingNozzleServoAnglesE1Box->setValue(defaults::SWITCHING_NOZZLE_SERVO_ANGLES_E1);
    mUi->uSwitchingNozzleServoDwellBox->setValue(defaults::SWITCHING_NOZZLE_SERVO_DWELL);
}

bool ExtruderPage::LoadFromJson(const QJsonObject &pJson)
{
    bool success = true;

    success &= LoadConfig(mUi->uExtrudersBox, pJson, "EXTRUDERS");
    success &= LoadConfig(mUi->uDefaultNominalFilamentDiaBox, pJson, "DEFAULT_NOMINAL_FILAMENT_DIA");
    success &= LoadConfig(mUi->uSingleNozzleBox, pJson, "SINGLENOZZLE");
    success &= LoadConfig(mUi->uSingleNozzleStandbyTempBox, pJson, "SINGLENOZZLE_STANDBY_TEMP");
    success &= LoadConfig(mUi->uSingleNozzleStandbyFanBox, pJson, "SINGLENOZZLE_STANDBY_FAN");
    success &= LoadConfig(mUi->uMmuModelBox, pJson, "ENABLE_MMU_MODEL");
    success &= LoadConfig(mUi->uMmuModelComboBox, pJson, "MMU_MODEL");
    success &= LoadConfig(mUi->uSwitchingExtruderBox, pJson, "SWITCHING_EXTRUDER");
    success &= LoadConfig(mUi->uSwitchingExtruderServoNrBox, pJson, "SWITCHING_EXTRUDER_SEVRO_NR");
    success &= LoadConfig(mUi->uSwitchingExtruderServoAnglesE0SpinBox, pJson, "SWITCHING_EXTRUDER_SERVO_ANGLES_E0");
    success &= LoadConfig(mUi->uSwitchingExtruderServoAnglesE1SpinBox, pJson, "SWITCHING_EXTRUDER_SERVO_ANGLES_E1");
    success &= LoadConfig(mUi->uSwitchingExtruderServoAnglesE2SpinBox, pJson, "SWITCHING_EXTRUDER_SERVO_ANGLES_E2");
    success &= LoadConfig(mUi->uSwitchingExtruderServoAnglesE23Box, pJson, "ENABLE_SWITCHING_EXTRUDER_SERVO_ANGLES_E23");
    success &= LoadConfig(mUi->uSwitchingExtruderServoAnglesE3SpinBox, pJson, "SWITCHING_EXTRUDER_SERVO_ANGLES_E3");
    success &= LoadConfig(mUi->uSwitchingExtruderE23ServoNrSpinBox, pJson, "SWITCHING_EXTRUDER_E23_SERVO_NR");
    success &= LoadConfig(mUi->uSwitchingNozzleBox, pJson, "SWITCHING_NOZZLE");
    success &= LoadConfig(mUi->uSwitchingNozzleServoNrBox, pJson, "SWITCHING_NOZZLE_SERVO_NR");
    success &= LoadConfig(mUi->uSwitchingNozzleE1ServoNrSpinBox, pJson, "SWITCHING_NOZZLE_E1_SERVO_NR");
    success &= LoadConfig(mUi->uSwitchingNozzleE1ServoNrBox, pJson, "ENABLE_SWITCHING_NOZZLE_E1_SERVO_NR");
    success &= LoadConfig(mUi->uSwitchingNozzleServoAnglesE0Box, pJson, "SWITCHING_NOZZLE_SERVO_ANGLES_E0");
    success &= LoadConfig(mUi->uSwitchingNozzleServoAnglesE1Box, pJson, "SWITCHING_NOZZLE_SERVO_ANGLES_E1");
    success &= LoadConfig(mUi->uSwitchingNozzleServoDwellBox, pJson, "SWITCHING_NOZZLE_SERVO_DWELL");

    return success;
}

void ExtruderPage::FetchConfiguration(Configuration& pConfig)
{
    SetConfig(pConfig.extruder.EXTRUDERS, mUi->uExtrudersBox);
    SetConfig(pConfig.extruder.DEFAULT_NOMINAL_FILAMENT_DIA, mUi->uDefaultNominalFilamentDiaBox);
    SetConfig(pConfig.extruder.SINGLENOZZLE, mUi->uSingleNozzleBox);
    SetConfig(pConfig.extruder.SINGLENOZZLE_STANDBY_TEMP, mUi->uSingleNozzleStandbyTempBox);
    SetConfig(pConfig.extruder.SINGLENOZZLE_STANDBY_FAN, mUi->uSingleNozzleStandbyFanBox);
    SetConfig(pConfig.extruder.ENABLE_MMU_MODEL, mUi->uMmuModelBox);
    SetConfig(pConfig.extruder.MMU_MODEL, mUi->uMmuModelComboBox);
    SetConfig(pConfig.extruder.SWITCHING_EXTRUDER, mUi->uSwitchingExtruderBox);
    SetConfig(pConfig.extruder.SWITCHING_EXTRUDER_SEVRO_NR, mUi->uSwitchingExtruderServoNrBox);
    SetConfig(pConfig.extruder.SWITCHING_EXTRUDER_SERVO_ANGLES_E0, mUi->uSwitchingExtruderServoAnglesE0SpinBox);
    SetConfig(pConfig.extruder.SWITCHING_EXTRUDER_SERVO_ANGLES_E1, mUi->uSwitchingExtruderServoAnglesE1SpinBox);
    SetConfig(pConfig.extruder.SWITCHING_EXTRUDER_SERVO_ANGLES_E2, mUi->uSwitchingExtruderServoAnglesE2SpinBox);
    SetConfig(pConfig.extruder.ENABLE_SWITCHING_EXTRUDER_SERVO_ANGLES_E23, mUi->uSwitchingExtruderServoAnglesE23Box);
    SetConfig(pConfig.extruder.SWITCHING_EXTRUDER_SERVO_ANGLES_E3, mUi->uSwitchingExtruderServoAnglesE3SpinBox);
    SetConfig(pConfig.extruder.SWITCHING_EXTRUDER_E23_SERVO_NR, mUi->uSwitchingExtruderE23ServoNrSpinBox);
    SetConfig(pConfig.extruder.SWITCHING_NOZZLE, mUi->uSwitchingNozzleBox);
    SetConfig(pConfig.extruder.SWITCHING_NOZZLE_SERVO_NR, mUi->uSwitchingNozzleServoNrBox);
    SetConfig(pConfig.extruder.SWITCHING_NOZZLE_E1_SERVO_NR, mUi->uSwitchingNozzleE1ServoNrSpinBox);
    SetConfig(pConfig.extruder.ENABLE_SWITCHING_NOZZLE_E1_SERVO_NR, mUi->uSwitchingNozzleE1ServoNrBox);
    SetConfig(pConfig.extruder.SWITCHING_NOZZLE_SERVO_ANGLES_E0, mUi->uSwitchingNozzleServoAnglesE0Box);
    SetConfig(pConfig.extruder.SWITCHING_NOZZLE_SERVO_ANGLES_E1, mUi->uSwitchingNozzleServoAnglesE1Box);
    SetConfig(pConfig.extruder.SWITCHING_NOZZLE_SERVO_DWELL, mUi->uSwitchingNozzleServoDwellBox);
}

void ExtruderPage::ReplaceTags(QStringList& pOutput)
{
    ReplaceTag(pOutput, "#{EXTRUDERS}", mUi->uExtrudersBox, false, "EXTRUDERS");
    ReplaceTag(pOutput, "#{DEFAULT_NOMINAL_FILAMENT_DIA}", mUi->uDefaultNominalFilamentDiaBox, false, "DEFAULT_NOMINAL_FILAMENT_DIA");
    ReplaceTag(pOutput, "#{SINGLENOZZLE}", mUi->uSingleNozzleBox, "SINGLENOZZLE");
    ReplaceTag(pOutput, "#{SINGLENOZZLE_STANDBY_TEMP}", mUi->uSingleNozzleStandbyTempBox, "SINGLENOZZLE_STANDBY_TEMP");
    ReplaceTag(pOutput, "#{SINGLENOZZLE_STANDBY_FAN}", mUi->uSingleNozzleStandbyFanBox, "SINGLENOZZLE_STANDBY_FAN");
    ReplaceTag(pOutput, "#{MMU_MODEL}", mUi->uMmuModelComboBox, !mUi->uMmuModelBox->isChecked(), "MMU_MODEL", true);
    ReplaceTag(pOutput, "#{SWITCHING_EXTRUDER}", mUi->uSwitchingExtruderBox, "SWITCHING_EXTRUDER");
    ReplaceTag(pOutput, "#{SWITCHING_EXTRUDER_SERVO_NR}", mUi->uSwitchingExtruderServoNrBox, !mUi->uSwitchingExtruderBox->isChecked(), "SWITCHING_EXTRUDER_SEVRO_NR");

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
    ReplaceTag(pOutput, "#{SWITCHING_EXTRUDER_E23_SERVO_NR}", mUi->uSwitchingExtruderE23ServoNrSpinBox, !mUi->uSwitchingExtruderBox->isChecked() || (mUi->uExtrudersBox->value() <= 3), "SWITCHING_EXTRUDER_E23_SERVO_NR");
    ReplaceTag(pOutput, "#{SWITCHING_NOZZLE}", mUi->uSwitchingNozzleBox, "SWITCHING_NOZZLE");
    ReplaceTag(pOutput, "#{SWITCHING_NOZZLE_SERVO_NR}", mUi->uSwitchingNozzleServoNrBox, !mUi->uSwitchingNozzleBox->isChecked(), "SWITCHING_NOZZLE_SERVO_NR");
    ReplaceTag(pOutput, "#{SWITCHING_NOZZLE_E1_SERVO_NR}", mUi->uSwitchingNozzleE1ServoNrSpinBox,  !mUi->uSwitchingNozzleBox->isChecked() || !mUi->uSwitchingNozzleE1ServoNrBox->isChecked(), "SWITCHING_NOZZLE_E1_SERVO_NR");
    {
        const auto& e0 = mUi->uSwitchingNozzleServoAnglesE0Box->value();
        const auto& e1 = mUi->uSwitchingNozzleServoAnglesE1Box->value();
        ReplaceArrayTag(pOutput, "#{SWITCHING_NOZZLE_SERVO_ANGLES}", !mUi->uSwitchingNozzleBox->isChecked(), "SWITCHING_NOZZLE_SERVO_ANGLES", std::vector<int32_t>{e0, e1});
    }
    ReplaceTag(pOutput, "#{SWITCHING_NOZZLE_SERVO_DWELL}", mUi->uSwitchingNozzleServoDwellBox, !mUi->uSwitchingNozzleBox->isChecked(), "SWITCHING_NOZZLE_SERVO_DWELL");
}
