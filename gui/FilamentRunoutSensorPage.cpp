/*!
 * \file FilamentRunoutSensorPage.cpp
/// \brief The FilamentRunoutSensorPage class represents the filament runout sensor page
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

#include "FilamentRunoutSensorPage.h"
#include "./ui_FilamentRunoutSensorPage.h"
#include "HelperFunctions.h"

FilamentRunoutSensorPage::FilamentRunoutSensorPage(QWidget *pParent) :
    AbstractPage(FILAMENT_RUNOUT_SENSOR_TEMPLATE_PATH, pParent),
    mUi(new Ui::FilamentRunoutSensorPage)
{
    mUi->setupUi(this);
}

FilamentRunoutSensorPage::~FilamentRunoutSensorPage()
{
    delete mUi;
}

void FilamentRunoutSensorPage::ConnectGuiSignalsAndSlots()
{
    QObject::connect(mUi->uDocumentationButton, &QPushButton::clicked, this, [&]()
    {
        OpenMarlinDocumentation("filament-runout-sensor");
    });

    AbstractPage::ConnectGuiSignalsAndSlots();
}

void FilamentRunoutSensorPage::ResetValues()
{
    mIsLoading = true;

    mUi->uFilamentRunoutSensorBox->setChecked(defaults::FILAMENT_RUNOUT_SENSOR);
    mUi->uFilRunoutEnabledDefaultDropdown->setCurrentText(defaults::FIL_RUNOUT_ENABLED_DEFAULT);
    mUi->uNumRunoutSensorsDropdown->setCurrentText(defaults::NUM_RUNOUT_SENSORS);
    mUi->uFilRunoutStateDropdown->setCurrentText(defaults::FIL_RUNOUT_STATE);
    mUi->uFilRunoutPullupBox->setChecked(defaults::FIL_RUNOUT_PULLUP);
    mUi->uFilRunoutPulldownBox->setChecked(defaults::FIL_RUNOUT_PULLDOWN);
    mUi->uWatchAllRunoutSensorsBox->setChecked(defaults::WATCH_ALL_RUNOUT_SENSORS);
    mUi->uFilRunout1StateDropdown->setCurrentText(defaults::FIL_RUNOUT1_STATE);
    mUi->uFilRunout1StateBox->setChecked(defaults::ENABLE_FIL_RUNOUT1_STATE);
    mUi->uFilRunout1PullupBox->setChecked(defaults::FIL_RUNOUT1_PULLUP);
    mUi->uFilRunout1PulldownBox->setChecked(defaults::FIL_RUNOUT1_PULLDOWN);
    mUi->uFilRunout2StateDropdown->setCurrentText(defaults::FIL_RUNOUT2_STATE);
    mUi->uFilRunout2StateBox->setChecked(defaults::ENABLE_FIL_RUNOUT2_STATE);
    mUi->uFilRunout2PullupBox->setChecked(defaults::FIL_RUNOUT2_PULLUP);
    mUi->uFilRunout2PulldownBox->setChecked(defaults::FIL_RUNOUT2_PULLDOWN);
    mUi->uFilRunout3StateDropdown->setCurrentText(defaults::FIL_RUNOUT3_STATE);
    mUi->uFilRunout3StateBox->setChecked(defaults::ENABLE_FIL_RUNOUT3_STATE);
    mUi->uFilRunout3PullupBox->setChecked(defaults::FIL_RUNOUT3_PULLUP);
    mUi->uFilRunout3PulldownBox->setChecked(defaults::FIL_RUNOUT3_PULLDOWN);
    mUi->uFilRunout4StateDropdown->setCurrentText(defaults::FIL_RUNOUT4_STATE);
    mUi->uFilRunout4StateBox->setChecked(defaults::ENABLE_FIL_RUNOUT4_STATE);
    mUi->uFilRunout4PullupBox->setChecked(defaults::FIL_RUNOUT4_PULLUP);
    mUi->uFilRunout4PulldownBox->setChecked(defaults::FIL_RUNOUT4_PULLDOWN);
    mUi->uFilRunout5StateDropdown->setCurrentText(defaults::FIL_RUNOUT5_STATE);
    mUi->uFilRunout5StateBox->setChecked(defaults::ENABLE_FIL_RUNOUT5_STATE);
    mUi->uFilRunout5PullupBox->setChecked(defaults::FIL_RUNOUT5_PULLUP);
    mUi->uFilRunout5PulldownBox->setChecked(defaults::FIL_RUNOUT5_PULLDOWN);
    mUi->uFilRunout6StateDropdown->setCurrentText(defaults::FIL_RUNOUT6_STATE);
    mUi->uFilRunout6StateBox->setChecked(defaults::ENABLE_FIL_RUNOUT6_STATE);
    mUi->uFilRunout6PullupBox->setChecked(defaults::FIL_RUNOUT6_PULLUP);
    mUi->uFilRunout6PulldownBox->setChecked(defaults::FIL_RUNOUT6_PULLDOWN);
    mUi->uFilRunout7StateDropdown->setCurrentText(defaults::FIL_RUNOUT7_STATE);
    mUi->uFilRunout7StateBox->setChecked(defaults::ENABLE_FIL_RUNOUT7_STATE);
    mUi->uFilRunout7PullupBox->setChecked(defaults::FIL_RUNOUT7_PULLUP);
    mUi->uFilRunout7PulldownBox->setChecked(defaults::FIL_RUNOUT7_PULLDOWN);
    mUi->uFilRunout8StateDropdown->setCurrentText(defaults::FIL_RUNOUT8_STATE);
    mUi->uFilRunout8StateBox->setChecked(defaults::ENABLE_FIL_RUNOUT8_STATE);
    mUi->uFilRunout8PullupBox->setChecked(defaults::FIL_RUNOUT8_PULLUP);
    mUi->uFilRunout8PulldownBox->setChecked(defaults::FIL_RUNOUT8_PULLDOWN);
    mUi->uFilamentRunoutScriptEdit->setText(defaults::FILAMENT_RUNOUT_SCRIPT);
    mUi->uFilamentRunoutDistanceMmSpinBox->setValue(defaults::FILAMENT_RUNOUT_DISTANCE_MM);
    mUi->uFilamentRunoutDistanceMmBox->setChecked(defaults::ENABLE_FILAMENT_RUNOUT_DISTANCE_MM);
    mUi->uFilamentMotionSensorBox->setChecked(defaults::FILAMENT_MOTION_SENSOR);

    mUi->uIndividualSensorsTabWidget->setCurrentIndex(0);

    mIsLoading = false;
}

bool FilamentRunoutSensorPage::LoadFromJson(const QJsonObject &pJson)
{
    bool success = true;
    mIsLoading = true;

    success &= LoadConfig(mUi->uFilamentRunoutSensorBox, pJson, "FILAMENT_RUNOUT_SENSOR");
    success &= LoadConfig(mUi->uFilRunoutEnabledDefaultDropdown, pJson, "FIL_RUNOUT_ENABLED_DEFAULT");
    success &= LoadConfig(mUi->uNumRunoutSensorsDropdown, pJson, "NUM_RUNOUT_SENSORS");
    success &= LoadConfig(mUi->uFilRunoutStateDropdown, pJson, "FIL_RUNOUT_STATE");
    success &= LoadConfig(mUi->uFilRunoutPullupBox, pJson, "FIL_RUNOUT_PULLUP");
    success &= LoadConfig(mUi->uFilRunoutPulldownBox, pJson, "FIL_RUNOUT_PULLDOWN");
    success &= LoadConfig(mUi->uWatchAllRunoutSensorsBox, pJson, "WATCH_ALL_RUNOUT_SENSORS");
    success &= LoadConfig(mUi->uFilRunout1StateDropdown, pJson, "FIL_RUNOUT1_STATE");
    success &= LoadConfig(mUi->uFilRunout1StateBox, pJson, "ENABLE_FIL_RUNOUT1_STATE");
    success &= LoadConfig(mUi->uFilRunout1PullupBox, pJson, "FIL_RUNOUT1_PULLUP");
    success &= LoadConfig(mUi->uFilRunout1PulldownBox, pJson, "FIL_RUNOUT1_PULLDOWN");
    success &= LoadConfig(mUi->uFilRunout2StateDropdown, pJson, "FIL_RUNOUT2_STATE");
    success &= LoadConfig(mUi->uFilRunout2StateBox, pJson, "ENABLE_FIL_RUNOUT2_STATE");
    success &= LoadConfig(mUi->uFilRunout2PullupBox, pJson, "FIL_RUNOUT2_PULLUP");
    success &= LoadConfig(mUi->uFilRunout2PulldownBox, pJson, "FIL_RUNOUT2_PULLDOWN");
    success &= LoadConfig(mUi->uFilRunout3StateDropdown, pJson, "FIL_RUNOUT3_STATE");
    success &= LoadConfig(mUi->uFilRunout3StateBox, pJson, "ENABLE_FIL_RUNOUT3_STATE");
    success &= LoadConfig(mUi->uFilRunout3PullupBox, pJson, "FIL_RUNOUT3_PULLUP");
    success &= LoadConfig(mUi->uFilRunout3PulldownBox, pJson, "FIL_RUNOUT3_PULLDOWN");
    success &= LoadConfig(mUi->uFilRunout4StateDropdown, pJson, "FIL_RUNOUT4_STATE");
    success &= LoadConfig(mUi->uFilRunout4StateBox, pJson, "ENABLE_FIL_RUNOUT4_STATE");
    success &= LoadConfig(mUi->uFilRunout4PullupBox, pJson, "FIL_RUNOUT4_PULLUP");
    success &= LoadConfig(mUi->uFilRunout4PulldownBox, pJson, "FIL_RUNOUT4_PULLDOWN");
    success &= LoadConfig(mUi->uFilRunout5StateDropdown, pJson, "FIL_RUNOUT5_STATE");
    success &= LoadConfig(mUi->uFilRunout5StateBox, pJson, "ENABLE_FIL_RUNOUT5_STATE");
    success &= LoadConfig(mUi->uFilRunout5PullupBox, pJson, "FIL_RUNOUT5_PULLUP");
    success &= LoadConfig(mUi->uFilRunout5PulldownBox, pJson, "FIL_RUNOUT5_PULLDOWN");
    success &= LoadConfig(mUi->uFilRunout6StateDropdown, pJson, "FIL_RUNOUT6_STATE");
    success &= LoadConfig(mUi->uFilRunout6StateBox, pJson, "ENABLE_FIL_RUNOUT6_STATE");
    success &= LoadConfig(mUi->uFilRunout6PullupBox, pJson, "FIL_RUNOUT6_PULLUP");
    success &= LoadConfig(mUi->uFilRunout6PulldownBox, pJson, "FIL_RUNOUT6_PULLDOWN");
    success &= LoadConfig(mUi->uFilRunout7StateDropdown, pJson, "FIL_RUNOUT7_STATE");
    success &= LoadConfig(mUi->uFilRunout7StateBox, pJson, "ENABLE_FIL_RUNOUT7_STATE");
    success &= LoadConfig(mUi->uFilRunout7PullupBox, pJson, "FIL_RUNOUT7_PULLUP");
    success &= LoadConfig(mUi->uFilRunout7PulldownBox, pJson, "FIL_RUNOUT7_PULLDOWN");
    success &= LoadConfig(mUi->uFilRunout8StateDropdown, pJson, "FIL_RUNOUT8_STATE");
    success &= LoadConfig(mUi->uFilRunout8StateBox, pJson, "ENABLE_FIL_RUNOUT8_STATE");
    success &= LoadConfig(mUi->uFilRunout8PullupBox, pJson, "FIL_RUNOUT8_PULLUP");
    success &= LoadConfig(mUi->uFilRunout8PulldownBox, pJson, "FIL_RUNOUT8_PULLDOWN");
    success &= LoadConfig(mUi->uFilamentRunoutScriptEdit, pJson, "FILAMENT_RUNOUT_SCRIPT");
    success &= LoadConfig(mUi->uFilamentRunoutDistanceMmSpinBox, pJson, "FILAMENT_RUNOUT_DISTANCE_MM");
    success &= LoadConfig(mUi->uFilamentRunoutDistanceMmBox, pJson, "ENABLE_FILAMENT_RUNOUT_DISTANCE_MM");
    success &= LoadConfig(mUi->uFilamentMotionSensorBox, pJson, "FILAMENT_MOTION_SENSOR");

    mIsLoading = false;
    return success;
}

void FilamentRunoutSensorPage::FetchConfiguration(Configuration& pConfig)
{
    SetConfig(pConfig.filamentRunoutSensor.FILAMENT_RUNOUT_SENSOR, mUi->uFilamentRunoutSensorBox);
    SetConfig(pConfig.filamentRunoutSensor.FIL_RUNOUT_ENABLED_DEFAULT, mUi->uFilRunoutEnabledDefaultDropdown);
    SetConfig(pConfig.filamentRunoutSensor.NUM_RUNOUT_SENSORS, mUi->uNumRunoutSensorsDropdown);
    SetConfig(pConfig.filamentRunoutSensor.FIL_RUNOUT_STATE, mUi->uFilRunoutStateDropdown);
    SetConfig(pConfig.filamentRunoutSensor.FIL_RUNOUT_PULLUP, mUi->uFilRunoutPullupBox);
    SetConfig(pConfig.filamentRunoutSensor.FIL_RUNOUT_PULLDOWN, mUi->uFilRunoutPulldownBox);
    SetConfig(pConfig.filamentRunoutSensor.WATCH_ALL_RUNOUT_SENSORS, mUi->uWatchAllRunoutSensorsBox);
    SetConfig(pConfig.filamentRunoutSensor.FIL_RUNOUT1_STATE, mUi->uFilRunout1StateDropdown);
    SetConfig(pConfig.filamentRunoutSensor.ENABLE_FIL_RUNOUT1_STATE, mUi->uFilRunout1StateBox);
    SetConfig(pConfig.filamentRunoutSensor.FIL_RUNOUT1_PULLUP, mUi->uFilRunout1PullupBox);
    SetConfig(pConfig.filamentRunoutSensor.FIL_RUNOUT1_PULLDOWN, mUi->uFilRunout1PulldownBox);
    SetConfig(pConfig.filamentRunoutSensor.FIL_RUNOUT2_STATE, mUi->uFilRunout2StateDropdown);
    SetConfig(pConfig.filamentRunoutSensor.ENABLE_FIL_RUNOUT2_STATE, mUi->uFilRunout2StateBox);
    SetConfig(pConfig.filamentRunoutSensor.FIL_RUNOUT2_PULLUP, mUi->uFilRunout2PullupBox);
    SetConfig(pConfig.filamentRunoutSensor.FIL_RUNOUT2_PULLDOWN, mUi->uFilRunout2PulldownBox);
    SetConfig(pConfig.filamentRunoutSensor.FIL_RUNOUT3_STATE, mUi->uFilRunout3StateDropdown);
    SetConfig(pConfig.filamentRunoutSensor.ENABLE_FIL_RUNOUT3_STATE, mUi->uFilRunout3StateBox);
    SetConfig(pConfig.filamentRunoutSensor.FIL_RUNOUT3_PULLUP, mUi->uFilRunout3PullupBox);
    SetConfig(pConfig.filamentRunoutSensor.FIL_RUNOUT3_PULLDOWN, mUi->uFilRunout3PulldownBox);
    SetConfig(pConfig.filamentRunoutSensor.FIL_RUNOUT4_STATE, mUi->uFilRunout4StateDropdown);
    SetConfig(pConfig.filamentRunoutSensor.ENABLE_FIL_RUNOUT4_STATE, mUi->uFilRunout4StateBox);
    SetConfig(pConfig.filamentRunoutSensor.FIL_RUNOUT4_PULLUP, mUi->uFilRunout4PullupBox);
    SetConfig(pConfig.filamentRunoutSensor.FIL_RUNOUT4_PULLDOWN, mUi->uFilRunout4PulldownBox);
    SetConfig(pConfig.filamentRunoutSensor.FIL_RUNOUT5_STATE, mUi->uFilRunout5StateDropdown);
    SetConfig(pConfig.filamentRunoutSensor.ENABLE_FIL_RUNOUT5_STATE, mUi->uFilRunout5StateBox);
    SetConfig(pConfig.filamentRunoutSensor.FIL_RUNOUT5_PULLUP, mUi->uFilRunout5PullupBox);
    SetConfig(pConfig.filamentRunoutSensor.FIL_RUNOUT5_PULLDOWN, mUi->uFilRunout5PulldownBox);
    SetConfig(pConfig.filamentRunoutSensor.FIL_RUNOUT6_STATE, mUi->uFilRunout6StateDropdown);
    SetConfig(pConfig.filamentRunoutSensor.ENABLE_FIL_RUNOUT6_STATE, mUi->uFilRunout6StateBox);
    SetConfig(pConfig.filamentRunoutSensor.FIL_RUNOUT6_PULLUP, mUi->uFilRunout6PullupBox);
    SetConfig(pConfig.filamentRunoutSensor.FIL_RUNOUT6_PULLDOWN, mUi->uFilRunout6PulldownBox);
    SetConfig(pConfig.filamentRunoutSensor.FIL_RUNOUT7_STATE, mUi->uFilRunout7StateDropdown);
    SetConfig(pConfig.filamentRunoutSensor.ENABLE_FIL_RUNOUT7_STATE, mUi->uFilRunout7StateBox);
    SetConfig(pConfig.filamentRunoutSensor.FIL_RUNOUT7_PULLUP, mUi->uFilRunout7PullupBox);
    SetConfig(pConfig.filamentRunoutSensor.FIL_RUNOUT7_PULLDOWN, mUi->uFilRunout7PulldownBox);
    SetConfig(pConfig.filamentRunoutSensor.FIL_RUNOUT8_STATE, mUi->uFilRunout8StateDropdown);
    SetConfig(pConfig.filamentRunoutSensor.ENABLE_FIL_RUNOUT8_STATE, mUi->uFilRunout8StateBox);
    SetConfig(pConfig.filamentRunoutSensor.FIL_RUNOUT8_PULLUP, mUi->uFilRunout8PullupBox);
    SetConfig(pConfig.filamentRunoutSensor.FIL_RUNOUT8_PULLDOWN, mUi->uFilRunout8PulldownBox);
    SetConfig(pConfig.filamentRunoutSensor.FILAMENT_RUNOUT_SCRIPT, mUi->uFilamentRunoutScriptEdit);
    SetConfig(pConfig.filamentRunoutSensor.FILAMENT_RUNOUT_DISTANCE_MM, mUi->uFilamentRunoutDistanceMmSpinBox);
    SetConfig(pConfig.filamentRunoutSensor.ENABLE_FILAMENT_RUNOUT_DISTANCE_MM, mUi->uFilamentRunoutDistanceMmBox);
    SetConfig(pConfig.filamentRunoutSensor.FILAMENT_MOTION_SENSOR, mUi->uFilamentMotionSensorBox);
}

void FilamentRunoutSensorPage::ReplaceTags(QStringList& pOutput)
{
    ReplaceTag(pOutput, "#{FILAMENT_RUNOUT_SENSOR}", mUi->uFilamentRunoutSensorBox, "FILAMENT_RUNOUT_SENSOR");
    ReplaceTag(pOutput, "#{FIL_RUNOUT_ENABLED_DEFAULT}", mUi->uFilRunoutEnabledDefaultDropdown, false, "FIL_RUNOUT_ENABLED_DEFAULT");
    ReplaceTag(pOutput, "#{NUM_RUNOUT_SENSORS}", mUi->uNumRunoutSensorsDropdown, false, "NUM_RUNOUT_SENSORS");
    ReplaceTag(pOutput, "#{FIL_RUNOUT_STATE}", mUi->uFilRunoutStateDropdown, false, "FIL_RUNOUT_STATE");
    ReplaceTag(pOutput, "#{FIL_RUNOUT_PULLUP}", mUi->uFilRunoutPullupBox, "FIL_RUNOUT_PULLUP");
    ReplaceTag(pOutput, "#{FIL_RUNOUT_PULLDOWN}", mUi->uFilRunoutPulldownBox, "FIL_RUNOUT_PULLDOWN");
    ReplaceTag(pOutput, "#{WATCH_ALL_RUNOUT_SENSORS}", mUi->uWatchAllRunoutSensorsBox, "WATCH_ALL_RUNOUT_SENSORS");
    ReplaceTag(pOutput, "#{FIL_RUNOUT1_STATE}", mUi->uFilRunout1StateDropdown, !mUi->uFilRunout1StateBox->isChecked(), "FIL_RUNOUT1_STATE");
    ReplaceTag(pOutput, "#{FIL_RUNOUT1_PULLUP}", mUi->uFilRunout1PullupBox, "FIL_RUNOUT1_PULLUP");
    ReplaceTag(pOutput, "#{FIL_RUNOUT1_PULLDOWN}", mUi->uFilRunout1PulldownBox, "FIL_RUNOUT1_PULLDOWN");
    ReplaceTag(pOutput, "#{FIL_RUNOUT2_STATE}", mUi->uFilRunout2StateDropdown, !mUi->uFilRunout2StateBox->isChecked(), "FIL_RUNOUT2_STATE");
    ReplaceTag(pOutput, "#{FIL_RUNOUT2_PULLUP}", mUi->uFilRunout2PullupBox, "FIL_RUNOUT2_PULLUP");
    ReplaceTag(pOutput, "#{FIL_RUNOUT2_PULLDOWN}", mUi->uFilRunout2PulldownBox, "FIL_RUNOUT2_PULLDOWN");
    ReplaceTag(pOutput, "#{FIL_RUNOUT3_STATE}", mUi->uFilRunout3StateDropdown, !mUi->uFilRunout3StateBox->isChecked(), "FIL_RUNOUT3_STATE");
    ReplaceTag(pOutput, "#{FIL_RUNOUT3_PULLUP}", mUi->uFilRunout3PullupBox, "FIL_RUNOUT3_PULLUP");
    ReplaceTag(pOutput, "#{FIL_RUNOUT3_PULLDOWN}", mUi->uFilRunout3PulldownBox, "FIL_RUNOUT3_PULLDOWN");
    ReplaceTag(pOutput, "#{FIL_RUNOUT4_STATE}", mUi->uFilRunout4StateDropdown, !mUi->uFilRunout4StateBox->isChecked(), "FIL_RUNOUT4_STATE");
    ReplaceTag(pOutput, "#{FIL_RUNOUT4_PULLUP}", mUi->uFilRunout4PullupBox, "FIL_RUNOUT4_PULLUP");
    ReplaceTag(pOutput, "#{FIL_RUNOUT4_PULLDOWN}", mUi->uFilRunout4PulldownBox, "FIL_RUNOUT4_PULLDOWN");
    ReplaceTag(pOutput, "#{FIL_RUNOUT5_STATE}", mUi->uFilRunout5StateDropdown, !mUi->uFilRunout5StateBox->isChecked(), "FIL_RUNOUT5_STATE");
    ReplaceTag(pOutput, "#{FIL_RUNOUT5_PULLUP}", mUi->uFilRunout5PullupBox, "FIL_RUNOUT5_PULLUP");
    ReplaceTag(pOutput, "#{FIL_RUNOUT5_PULLDOWN}", mUi->uFilRunout5PulldownBox, "FIL_RUNOUT5_PULLDOWN");
    ReplaceTag(pOutput, "#{FIL_RUNOUT6_STATE}", mUi->uFilRunout6StateDropdown, !mUi->uFilRunout6StateBox->isChecked(), "FIL_RUNOUT6_STATE");
    ReplaceTag(pOutput, "#{FIL_RUNOUT6_PULLUP}", mUi->uFilRunout6PullupBox, "FIL_RUNOUT6_PULLUP");
    ReplaceTag(pOutput, "#{FIL_RUNOUT6_PULLDOWN}", mUi->uFilRunout6PulldownBox, "FIL_RUNOUT6_PULLDOWN");
    ReplaceTag(pOutput, "#{FIL_RUNOUT7_STATE}", mUi->uFilRunout7StateDropdown, !mUi->uFilRunout7StateBox->isChecked(), "FIL_RUNOUT7_STATE");
    ReplaceTag(pOutput, "#{FIL_RUNOUT7_PULLUP}", mUi->uFilRunout7PullupBox, "FIL_RUNOUT7_PULLUP");
    ReplaceTag(pOutput, "#{FIL_RUNOUT7_PULLDOWN}", mUi->uFilRunout7PulldownBox, "FIL_RUNOUT7_PULLDOWN");
    ReplaceTag(pOutput, "#{FIL_RUNOUT8_STATE}", mUi->uFilRunout8StateDropdown, !mUi->uFilRunout8StateBox->isChecked(), "FIL_RUNOUT8_STATE");
    ReplaceTag(pOutput, "#{FIL_RUNOUT8_PULLUP}", mUi->uFilRunout8PullupBox, "FIL_RUNOUT8_PULLUP");
    ReplaceTag(pOutput, "#{FIL_RUNOUT8_PULLDOWN}", mUi->uFilRunout8PulldownBox, "FIL_RUNOUT8_PULLDOWN");
    ReplaceTag(pOutput, "#{FILAMENT_RUNOUT_SCRIPT}", mUi->uFilamentRunoutScriptEdit, false, "FILAMENT_RUNOUT_SCRIPT", true);
    ReplaceTag(pOutput, "#{FILAMENT_RUNOUT_DISTANCE_MM}", mUi->uFilamentRunoutDistanceMmSpinBox, !mUi->uFilamentRunoutDistanceMmBox->isChecked(), "FILAMENT_RUNOUT_DISTANCE_MM");
    ReplaceTag(pOutput, "#{FILAMENT_MOTION_SENSOR}", mUi->uFilamentMotionSensorBox, "FILAMENT_MOTION_SENSOR");
}
