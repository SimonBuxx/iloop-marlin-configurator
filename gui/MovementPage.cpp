/*!
 * \file MovementPage.cpp
/// \brief The MovementPage class represents the movement page
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

#include "MovementPage.h"
#include "./ui_MovementPage.h"
#include "HelperFunctions.h"

MovementPage::MovementPage(QWidget *pParent) :
    AbstractPage(MOVEMENT_TEMPLATE_PATH, pParent),
    mUi(new Ui::MovementPage)
{
    mUi->setupUi(this);
}

MovementPage::~MovementPage()
{
    delete mUi;
}

void MovementPage::ConnectGuiSignalsAndSlots()
{
    QObject::connect(mUi->uDocumentationButton, &QPushButton::clicked, this, [&]()
    {
        OpenMarlinDocumentation("movement");
    });

    QObject::connect(mUi->uClassicJerkBox, &QGroupBox::toggled, this, [&](auto pChecked){
        mUi->uJunctionDeviationMmBox->setEnabled(!pChecked);
        mUi->uJdHandleSmallSegmentsBox->setEnabled(!pChecked);
    });

    AbstractPage::ConnectGuiSignalsAndSlots();
}

void MovementPage::ResetValues()
{
    mIsLoading = true;

    mUi->uDistinctEFactorsBox->setChecked(defaults::DISTINCT_E_FACTORS);
    mUi->uDefaultAxisStepsPerUnitEdit->setText(defaults::DEFAULT_AXIS_STEPS_PER_UNIT);
    mUi->uDefaultMaxFeedrateEdit->setText(defaults::DEFAULT_MAX_FEEDRATE);
    mUi->uLimitedMaxFrEditingBox->setChecked(defaults::LIMITED_MAX_FR_EDITING);
    mUi->uMaxFeedrateEditValuesEdit->setText(defaults::MAX_FEEDRATE_EDIT_VALUES);
    mUi->uDefaultMaxAccelerationEdit->setText(defaults::DEFAULT_MAX_ACCELERATION);
    mUi->uLimitedMaxAccelEditingBox->setChecked(defaults::LIMITED_MAX_ACCEL_EDITING);
    mUi->uMaxAccelEditValuesEdit->setText(defaults::MAX_ACCEL_EDIT_VALUES);
    mUi->uDefaultAccelerationSpinBox->setValue(defaults::DEFAULT_ACCELERATION);
    mUi->uDefaultRetractAccelerationSpinBox->setValue(defaults::DEFAULT_RETRACT_ACCELERATION);
    mUi->uDefaultTravelAccelerationSpinBox->setValue(defaults::DEFAULT_TRAVEL_ACCELERATION);
    mUi->uClassicJerkBox->setChecked(defaults::CLASSIC_JERK);
    mUi->uDefaultXjerkSpinBox->setValue(defaults::DEFAULT_XJERK);
    mUi->uDefaultYjerkSpinBox->setValue(defaults::DEFAULT_YJERK);
    mUi->uDefaultZjerkSpinBox->setValue(defaults::DEFAULT_ZJERK);
    mUi->uDefaultIjerkSpinBox->setValue(defaults::DEFAULT_IJERK);
    mUi->uDefaultJjerkSpinBox->setValue(defaults::DEFAULT_JJERK);
    mUi->uDefaultKjerkSpinBox->setValue(defaults::DEFAULT_KJERK);
    mUi->uDefaultUjerkSpinBox->setValue(defaults::DEFAULT_UJERK);
    mUi->uDefaultVjerkSpinBox->setValue(defaults::DEFAULT_VJERK);
    mUi->uDefaultWjerkSpinBox->setValue(defaults::DEFAULT_WJERK);
    mUi->uTravelExtraXyjerkSpinBox->setValue(defaults::TRAVEL_EXTRA_XYJERK);
    mUi->uTravelExtraXyjerkBox->setChecked(defaults::ENABLE_TRAVEL_EXTRA_XYJERK);
    mUi->uLimitedJerkEditingBox->setChecked(defaults::LIMITED_JERK_EDITING);
    mUi->uMaxJerkEditValuesEdit->setText(defaults::MAX_JERK_EDIT_VALUES);
    mUi->uDefaultEjerkSpinBox->setValue(defaults::DEFAULT_EJERK);
    mUi->uJunctionDeviationMmSpinBox->setValue(defaults::JUNCTION_DEVIATION_MM);
    mUi->uJdHandleSmallSegmentsBox->setChecked(defaults::JD_HANDLE_SMALL_SEGMENTS);
    mUi->uSCurveAccelerationBox->setChecked(defaults::S_CURVE_ACCELERATION);
    mUi->uDefaultXjerkBox->setChecked(defaults::ENABLE_DEFAULT_XJERK);
    mUi->uDefaultYjerkBox->setChecked(defaults::ENABLE_DEFAULT_YJERK);
    mUi->uDefaultZjerkBox->setChecked(defaults::ENABLE_DEFAULT_ZJERK);
    mUi->uDefaultIjerkBox->setChecked(defaults::ENABLE_DEFAULT_IJERK);
    mUi->uDefaultJjerkBox->setChecked(defaults::ENABLE_DEFAULT_JJERK);
    mUi->uDefaultKjerkBox->setChecked(defaults::ENABLE_DEFAULT_KJERK);
    mUi->uDefaultUjerkBox->setChecked(defaults::ENABLE_DEFAULT_UJERK);
    mUi->uDefaultVjerkBox->setChecked(defaults::ENABLE_DEFAULT_VJERK);
    mUi->uDefaultWjerkBox->setChecked(defaults::ENABLE_DEFAULT_WJERK);

    mIsLoading = false;
}

bool MovementPage::LoadFromJson(const QJsonObject &pJson)
{
    bool success = true;
    mIsLoading = true;

    success &= LoadConfig(mUi->uDistinctEFactorsBox, pJson, "DISTINCT_E_FACTORS");
    success &= LoadConfig(mUi->uDefaultAxisStepsPerUnitEdit, pJson, "DEFAULT_AXIS_STEPS_PER_UNIT");
    success &= LoadConfig(mUi->uDefaultMaxFeedrateEdit, pJson, "DEFAULT_MAX_FEEDRATE");
    success &= LoadConfig(mUi->uLimitedMaxFrEditingBox, pJson, "LIMITED_MAX_FR_EDITING");
    success &= LoadConfig(mUi->uMaxFeedrateEditValuesEdit, pJson, "MAX_FEEDRATE_EDIT_VALUES");
    success &= LoadConfig(mUi->uDefaultMaxAccelerationEdit, pJson, "DEFAULT_MAX_ACCELERATION");
    success &= LoadConfig(mUi->uLimitedMaxAccelEditingBox, pJson, "LIMITED_MAX_ACCEL_EDITING");
    success &= LoadConfig(mUi->uMaxAccelEditValuesEdit, pJson, "MAX_ACCEL_EDIT_VALUES");
    success &= LoadConfig(mUi->uDefaultAccelerationSpinBox, pJson, "DEFAULT_ACCELERATION");
    success &= LoadConfig(mUi->uDefaultRetractAccelerationSpinBox, pJson, "DEFAULT_RETRACT_ACCELERATION");
    success &= LoadConfig(mUi->uDefaultTravelAccelerationSpinBox, pJson, "DEFAULT_TRAVEL_ACCELERATION");
    success &= LoadConfig(mUi->uClassicJerkBox, pJson, "CLASSIC_JERK");
    success &= LoadConfig(mUi->uDefaultXjerkSpinBox, pJson, "DEFAULT_XJERK");
    success &= LoadConfig(mUi->uDefaultYjerkSpinBox, pJson, "DEFAULT_YJERK");
    success &= LoadConfig(mUi->uDefaultZjerkSpinBox, pJson, "DEFAULT_ZJERK");
    success &= LoadConfig(mUi->uDefaultIjerkSpinBox, pJson, "DEFAULT_IJERK");
    success &= LoadConfig(mUi->uDefaultJjerkSpinBox, pJson, "DEFAULT_JJERK");
    success &= LoadConfig(mUi->uDefaultKjerkSpinBox, pJson, "DEFAULT_KJERK");
    success &= LoadConfig(mUi->uDefaultUjerkSpinBox, pJson, "DEFAULT_UJERK");
    success &= LoadConfig(mUi->uDefaultVjerkSpinBox, pJson, "DEFAULT_VJERK");
    success &= LoadConfig(mUi->uDefaultWjerkSpinBox, pJson, "DEFAULT_WJERK");
    success &= LoadConfig(mUi->uTravelExtraXyjerkSpinBox, pJson, "TRAVEL_EXTRA_XYJERK");
    success &= LoadConfig(mUi->uTravelExtraXyjerkBox, pJson, "ENABLE_TRAVEL_EXTRA_XYJERK");
    success &= LoadConfig(mUi->uLimitedJerkEditingBox, pJson, "LIMITED_JERK_EDITING");
    success &= LoadConfig(mUi->uMaxJerkEditValuesEdit, pJson, "MAX_JERK_EDIT_VALUES");
    success &= LoadConfig(mUi->uDefaultEjerkSpinBox, pJson, "DEFAULT_EJERK");
    success &= LoadConfig(mUi->uJunctionDeviationMmSpinBox, pJson, "JUNCTION_DEVIATION_MM");
    success &= LoadConfig(mUi->uJdHandleSmallSegmentsBox, pJson, "JD_HANDLE_SMALL_SEGMENTS");
    success &= LoadConfig(mUi->uSCurveAccelerationBox, pJson, "S_CURVE_ACCELERATION");
    success &= LoadConfig(mUi->uDefaultXjerkBox, pJson, "ENABLE_DEFAULT_XJERK");
    success &= LoadConfig(mUi->uDefaultYjerkBox, pJson, "ENABLE_DEFAULT_YJERK");
    success &= LoadConfig(mUi->uDefaultZjerkBox, pJson, "ENABLE_DEFAULT_ZJERK");
    success &= LoadConfig(mUi->uDefaultIjerkBox, pJson, "ENABLE_DEFAULT_IJERK");
    success &= LoadConfig(mUi->uDefaultJjerkBox, pJson, "ENABLE_DEFAULT_JJERK");
    success &= LoadConfig(mUi->uDefaultKjerkBox, pJson, "ENABLE_DEFAULT_KJERK");
    success &= LoadConfig(mUi->uDefaultUjerkBox, pJson, "ENABLE_DEFAULT_UJERK");
    success &= LoadConfig(mUi->uDefaultVjerkBox, pJson, "ENABLE_DEFAULT_VJERK");
    success &= LoadConfig(mUi->uDefaultWjerkBox, pJson, "ENABLE_DEFAULT_WJERK");

    mIsLoading = false;
    return success;
}

void MovementPage::FetchConfiguration(Configuration& pConfig)
{
    SetConfig(pConfig.movement.DISTINCT_E_FACTORS, mUi->uDistinctEFactorsBox);
    SetConfig(pConfig.movement.DEFAULT_AXIS_STEPS_PER_UNIT, mUi->uDefaultAxisStepsPerUnitEdit);
    SetConfig(pConfig.movement.DEFAULT_MAX_FEEDRATE, mUi->uDefaultMaxFeedrateEdit);
    SetConfig(pConfig.movement.LIMITED_MAX_FR_EDITING, mUi->uLimitedMaxFrEditingBox);
    SetConfig(pConfig.movement.MAX_FEEDRATE_EDIT_VALUES, mUi->uMaxFeedrateEditValuesEdit);
    SetConfig(pConfig.movement.DEFAULT_MAX_ACCELERATION, mUi->uDefaultMaxAccelerationEdit);
    SetConfig(pConfig.movement.LIMITED_MAX_ACCEL_EDITING, mUi->uLimitedMaxAccelEditingBox);
    SetConfig(pConfig.movement.MAX_ACCEL_EDIT_VALUES, mUi->uMaxAccelEditValuesEdit);
    SetConfig(pConfig.movement.DEFAULT_ACCELERATION, mUi->uDefaultAccelerationSpinBox);
    SetConfig(pConfig.movement.DEFAULT_RETRACT_ACCELERATION, mUi->uDefaultRetractAccelerationSpinBox);
    SetConfig(pConfig.movement.DEFAULT_TRAVEL_ACCELERATION, mUi->uDefaultTravelAccelerationSpinBox);
    SetConfig(pConfig.movement.CLASSIC_JERK, mUi->uClassicJerkBox);
    SetConfig(pConfig.movement.DEFAULT_XJERK, mUi->uDefaultXjerkSpinBox);
    SetConfig(pConfig.movement.DEFAULT_YJERK, mUi->uDefaultYjerkSpinBox);
    SetConfig(pConfig.movement.DEFAULT_ZJERK, mUi->uDefaultZjerkSpinBox);
    SetConfig(pConfig.movement.DEFAULT_IJERK, mUi->uDefaultIjerkSpinBox);
    SetConfig(pConfig.movement.DEFAULT_JJERK, mUi->uDefaultJjerkSpinBox);
    SetConfig(pConfig.movement.DEFAULT_KJERK, mUi->uDefaultKjerkSpinBox);
    SetConfig(pConfig.movement.DEFAULT_UJERK, mUi->uDefaultUjerkSpinBox);
    SetConfig(pConfig.movement.DEFAULT_VJERK, mUi->uDefaultVjerkSpinBox);
    SetConfig(pConfig.movement.DEFAULT_WJERK, mUi->uDefaultWjerkSpinBox);
    SetConfig(pConfig.movement.TRAVEL_EXTRA_XYJERK, mUi->uTravelExtraXyjerkSpinBox);
    SetConfig(pConfig.movement.ENABLE_TRAVEL_EXTRA_XYJERK, mUi->uTravelExtraXyjerkBox);
    SetConfig(pConfig.movement.LIMITED_JERK_EDITING, mUi->uLimitedJerkEditingBox);
    SetConfig(pConfig.movement.MAX_JERK_EDIT_VALUES, mUi->uMaxJerkEditValuesEdit);
    SetConfig(pConfig.movement.DEFAULT_EJERK, mUi->uDefaultEjerkSpinBox);
    SetConfig(pConfig.movement.JUNCTION_DEVIATION_MM, mUi->uJunctionDeviationMmSpinBox);
    SetConfig(pConfig.movement.JD_HANDLE_SMALL_SEGMENTS, mUi->uJdHandleSmallSegmentsBox);
    SetConfig(pConfig.movement.S_CURVE_ACCELERATION, mUi->uSCurveAccelerationBox);
    SetConfig(pConfig.movement.ENABLE_DEFAULT_XJERK, mUi->uDefaultXjerkBox);
    SetConfig(pConfig.movement.ENABLE_DEFAULT_YJERK, mUi->uDefaultYjerkBox);
    SetConfig(pConfig.movement.ENABLE_DEFAULT_ZJERK, mUi->uDefaultZjerkBox);
    SetConfig(pConfig.movement.ENABLE_DEFAULT_IJERK, mUi->uDefaultIjerkBox);
    SetConfig(pConfig.movement.ENABLE_DEFAULT_JJERK, mUi->uDefaultJjerkBox);
    SetConfig(pConfig.movement.ENABLE_DEFAULT_KJERK, mUi->uDefaultKjerkBox);
    SetConfig(pConfig.movement.ENABLE_DEFAULT_UJERK, mUi->uDefaultUjerkBox);
    SetConfig(pConfig.movement.ENABLE_DEFAULT_VJERK, mUi->uDefaultVjerkBox);
    SetConfig(pConfig.movement.ENABLE_DEFAULT_WJERK, mUi->uDefaultWjerkBox);
}

void MovementPage::ReplaceTags(QStringList& pOutput)
{
    ReplaceTag(pOutput, "#{DISTINCT_E_FACTORS}", mUi->uDistinctEFactorsBox, "DISTINCT_E_FACTORS");
    ReplaceTag(pOutput, "#{DEFAULT_AXIS_STEPS_PER_UNIT}", mUi->uDefaultAxisStepsPerUnitEdit, false, "DEFAULT_AXIS_STEPS_PER_UNIT");
    ReplaceTag(pOutput, "#{DEFAULT_MAX_FEEDRATE}", mUi->uDefaultMaxFeedrateEdit, false, "DEFAULT_MAX_FEEDRATE");
    ReplaceTag(pOutput, "#{LIMITED_MAX_FR_EDITING}", mUi->uLimitedMaxFrEditingBox, "LIMITED_MAX_FR_EDITING");
    ReplaceTag(pOutput, "#{MAX_FEEDRATE_EDIT_VALUES}", mUi->uMaxFeedrateEditValuesEdit, false, "MAX_FEEDRATE_EDIT_VALUES");
    ReplaceTag(pOutput, "#{DEFAULT_MAX_ACCELERATION}", mUi->uDefaultMaxAccelerationEdit, false, "DEFAULT_MAX_ACCELERATION");
    ReplaceTag(pOutput, "#{LIMITED_MAX_ACCEL_EDITING}", mUi->uLimitedMaxAccelEditingBox, "LIMITED_MAX_ACCEL_EDITING");
    ReplaceTag(pOutput, "#{MAX_ACCEL_EDIT_VALUES}", mUi->uMaxAccelEditValuesEdit, false, "MAX_ACCEL_EDIT_VALUES");
    ReplaceTag(pOutput, "#{DEFAULT_ACCELERATION}", mUi->uDefaultAccelerationSpinBox, false, "DEFAULT_ACCELERATION");
    ReplaceTag(pOutput, "#{DEFAULT_RETRACT_ACCELERATION}", mUi->uDefaultRetractAccelerationSpinBox, false, "DEFAULT_RETRACT_ACCELERATION");
    ReplaceTag(pOutput, "#{DEFAULT_TRAVEL_ACCELERATION}", mUi->uDefaultTravelAccelerationSpinBox, false, "DEFAULT_TRAVEL_ACCELERATION");
    ReplaceTag(pOutput, "#{CLASSIC_JERK}", mUi->uClassicJerkBox, "CLASSIC_JERK");
    ReplaceTag(pOutput, "#{DEFAULT_XJERK}", mUi->uDefaultXjerkSpinBox, !mUi->uDefaultXjerkBox->isChecked(), "DEFAULT_XJERK", 1);
    ReplaceTag(pOutput, "#{DEFAULT_YJERK}", mUi->uDefaultYjerkSpinBox, !mUi->uDefaultYjerkBox->isChecked(), "DEFAULT_YJERK", 1);
    ReplaceTag(pOutput, "#{DEFAULT_ZJERK}", mUi->uDefaultZjerkSpinBox, !mUi->uDefaultZjerkBox->isChecked(), "DEFAULT_ZJERK", 1);
    ReplaceTag(pOutput, "#{DEFAULT_IJERK}", mUi->uDefaultIjerkSpinBox, !mUi->uDefaultIjerkBox->isChecked(), "DEFAULT_IJERK", 1);
    ReplaceTag(pOutput, "#{DEFAULT_JJERK}", mUi->uDefaultJjerkSpinBox, !mUi->uDefaultJjerkBox->isChecked(), "DEFAULT_JJERK", 1);
    ReplaceTag(pOutput, "#{DEFAULT_KJERK}", mUi->uDefaultKjerkSpinBox, !mUi->uDefaultKjerkBox->isChecked(), "DEFAULT_KJERK", 1);
    ReplaceTag(pOutput, "#{DEFAULT_UJERK}", mUi->uDefaultUjerkSpinBox, !mUi->uDefaultUjerkBox->isChecked(), "DEFAULT_UJERK", 1);
    ReplaceTag(pOutput, "#{DEFAULT_VJERK}", mUi->uDefaultVjerkSpinBox, !mUi->uDefaultVjerkBox->isChecked(), "DEFAULT_VJERK", 1);
    ReplaceTag(pOutput, "#{DEFAULT_WJERK}", mUi->uDefaultWjerkSpinBox, !mUi->uDefaultWjerkBox->isChecked(), "DEFAULT_WJERK", 1);
    ReplaceTag(pOutput, "#{TRAVEL_EXTRA_XYJERK}", mUi->uTravelExtraXyjerkSpinBox, !mUi->uTravelExtraXyjerkBox->isChecked(), "TRAVEL_EXTRA_XYJERK", 1);
    ReplaceTag(pOutput, "#{LIMITED_JERK_EDITING}", mUi->uLimitedJerkEditingBox, "LIMITED_JERK_EDITING");
    ReplaceTag(pOutput, "#{MAX_JERK_EDIT_VALUES}", mUi->uMaxJerkEditValuesEdit, false, "MAX_JERK_EDIT_VALUES");
    ReplaceTag(pOutput, "#{DEFAULT_EJERK}", mUi->uDefaultEjerkSpinBox, false, "DEFAULT_EJERK", 1);
    ReplaceTag(pOutput, "#{JUNCTION_DEVIATION_MM}", mUi->uJunctionDeviationMmSpinBox, false, "JUNCTION_DEVIATION_MM", 3);
    ReplaceTag(pOutput, "#{JD_HANDLE_SMALL_SEGMENTS}", mUi->uJdHandleSmallSegmentsBox, "JD_HANDLE_SMALL_SEGMENTS");
    ReplaceTag(pOutput, "#{S_CURVE_ACCELERATION}", mUi->uSCurveAccelerationBox, "S_CURVE_ACCELERATION");
}
