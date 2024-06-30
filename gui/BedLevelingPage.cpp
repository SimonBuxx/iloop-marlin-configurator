/*!
 * \file BedLevelingPage.cpp
/// \brief The BedLevelingPage class represents the bed leveling page
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

#include "BedLevelingPage.h"
#include "./ui_BedLevelingPage.h"
#include "HelperFunctions.h"

BedLevelingPage::BedLevelingPage(QWidget *pParent) :
    AbstractPage(BED_LEVELING_TEMPLATE_PATH, pParent),
    mUi(new Ui::BedLevelingPage)
{
    mUi->setupUi(this);
}

BedLevelingPage::~BedLevelingPage()
{
    delete mUi;
}

void BedLevelingPage::ConnectGuiSignalsAndSlots()
{
    QObject::connect(mUi->uDocumentationButton, &QPushButton::clicked, this, [&]()
    {
        OpenMarlinDocumentation("bed-leveling");
    });

    QObject::connect(mUi->uMeshBedLevelingBox, &QGroupBox::toggled, this, [&](auto pChecked){
        mUi->uEnableLevelingFadeHeightBox->setEnabled(pChecked || mUi->uAutoBedLevelingBilinearBox->isChecked() || mUi->uAutoBedLevelingUblBox->isChecked());
        mUi->uSegmentLeveledMovesBox->setEnabled(pChecked || mUi->uAutoBedLevelingBilinearBox->isChecked() || mUi->uAutoBedLevelingUblBox->isChecked());
        mUi->uLeveledSegmentLengthBox->setEnabled(pChecked || mUi->uAutoBedLevelingBilinearBox->isChecked() || mUi->uAutoBedLevelingUblBox->isChecked());
        mUi->uG26MeshValidationBox->setEnabled(pChecked || mUi->uAutoBedLevelingBilinearBox->isChecked() || mUi->uAutoBedLevelingUblBox->isChecked());
    });

    QObject::connect(mUi->uAutoBedLevelingBilinearBox, &QGroupBox::toggled, this, [&](auto pChecked){
        mUi->uEnableLevelingFadeHeightBox->setEnabled(pChecked || mUi->uMeshBedLevelingBox->isChecked() || mUi->uAutoBedLevelingUblBox->isChecked());
        mUi->uSegmentLeveledMovesBox->setEnabled(pChecked || mUi->uMeshBedLevelingBox->isChecked() || mUi->uAutoBedLevelingUblBox->isChecked());
        mUi->uLeveledSegmentLengthBox->setEnabled(pChecked || mUi->uMeshBedLevelingBox->isChecked() || mUi->uAutoBedLevelingUblBox->isChecked());
        mUi->uG26MeshValidationBox->setEnabled(pChecked || mUi->uMeshBedLevelingBox->isChecked() || mUi->uAutoBedLevelingUblBox->isChecked());
    });

    QObject::connect(mUi->uAutoBedLevelingUblBox, &QGroupBox::toggled, this, [&](auto pChecked){
        mUi->uEnableLevelingFadeHeightBox->setEnabled(pChecked || mUi->uAutoBedLevelingBilinearBox->isChecked() || mUi->uMeshBedLevelingBox->isChecked());
        mUi->uSegmentLeveledMovesBox->setEnabled(pChecked || mUi->uAutoBedLevelingBilinearBox->isChecked() || mUi->uMeshBedLevelingBox->isChecked());
        mUi->uLeveledSegmentLengthBox->setEnabled(pChecked || mUi->uAutoBedLevelingBilinearBox->isChecked() || mUi->uMeshBedLevelingBox->isChecked());
        mUi->uG26MeshValidationBox->setEnabled(pChecked || mUi->uAutoBedLevelingBilinearBox->isChecked() || mUi->uMeshBedLevelingBox->isChecked());
    });

    AbstractPage::ConnectGuiSignalsAndSlots();
}

void BedLevelingPage::ResetValues()
{
    mIsLoading = true;

    mUi->uAutoBedLeveling3pointBox->setChecked(defaults::AUTO_BED_LEVELING_3POINT);
    mUi->uAutoBedLevelingLinearBox->setChecked(defaults::AUTO_BED_LEVELING_LINEAR);
    mUi->uAutoBedLevelingBilinearBox->setChecked(defaults::AUTO_BED_LEVELING_BILINEAR);
    mUi->uAutoBedLevelingUblBox->setChecked(defaults::AUTO_BED_LEVELING_UBL);
    mUi->uMeshBedLevelingBox->setChecked(defaults::MESH_BED_LEVELING);
    mUi->uRestoreLevelingAfterG28Box->setChecked(defaults::RESTORE_LEVELING_AFTER_G28);
    mUi->uEnableLevelingAfterG28Box->setChecked(defaults::ENABLE_LEVELING_AFTER_G28);
    mUi->uLevelingNozzleTempSpinBox->setValue(defaults::LEVELING_NOZZLE_TEMP);
    mUi->uLevelingBedTempSpinBox->setValue(defaults::LEVELING_BED_TEMP);
    mUi->uBdSensorBox->setChecked(defaults::BD_SENSOR);
    mUi->uDebugLevelingFeatureBox->setChecked(defaults::DEBUG_LEVELING_FEATURE);
    mUi->uManualProbeStartZSpinBox->setValue(defaults::MANUAL_PROBE_START_Z);
    mUi->uManualProbeStartZBox->setChecked(defaults::ENABLE_MANUAL_PROBE_START_Z);
    mUi->uEnableLevelingFadeHeightBox->setChecked(defaults::ENABLE_LEVELING_FADE_HEIGHT);
    mUi->uDefaultLevelingFadeHeightSpinBox->setValue(defaults::DEFAULT_LEVELING_FADE_HEIGHT);
    mUi->uSegmentLeveledMovesBox->setChecked(defaults::SEGMENT_LEVELED_MOVES);
    mUi->uLeveledSegmentLengthSpinBox->setValue(defaults::LEVELED_SEGMENT_LENGTH);
    mUi->uG26MeshValidationBox->setChecked(defaults::G26_MESH_VALIDATION);
    mUi->uMeshTestNozzleSizeSpinBox->setValue(defaults::MESH_TEST_NOZZLE_SIZE);
    mUi->uMeshTestLayerHeightSpinBox->setValue(defaults::MESH_TEST_LAYER_HEIGHT);
    mUi->uMeshTestHotendTempSpinBox->setValue(defaults::MESH_TEST_HOTEND_TEMP);
    mUi->uMeshTestBedTempSpinBox->setValue(defaults::MESH_TEST_BED_TEMP);
    mUi->uG26XyFeedrateSpinBox->setValue(defaults::G26_XY_FEEDRATE);
    mUi->uG26XyFeedrateTravelSpinBox->setValue(defaults::G26_XY_FEEDRATE_TRAVEL);
    mUi->uG26RetractMultiplierSpinBox->setValue(defaults::G26_RETRACT_MULTIPLIER);
    mUi->uPreheatBeforeLevelingBox->setChecked(defaults::PREHEAT_BEFORE_LEVELING);

    mIsLoading = false;
}

bool BedLevelingPage::LoadFromJson(const QJsonObject &pJson)
{
    bool success = true;
    mIsLoading = true;

    success &= LoadConfig(mUi->uAutoBedLeveling3pointBox, pJson, "AUTO_BED_LEVELING_3POINT");
    success &= LoadConfig(mUi->uAutoBedLevelingLinearBox, pJson, "AUTO_BED_LEVELING_LINEAR");
    success &= LoadConfig(mUi->uAutoBedLevelingBilinearBox, pJson, "AUTO_BED_LEVELING_BILINEAR");
    success &= LoadConfig(mUi->uAutoBedLevelingUblBox, pJson, "AUTO_BED_LEVELING_UBL");
    success &= LoadConfig(mUi->uMeshBedLevelingBox, pJson, "MESH_BED_LEVELING");
    success &= LoadConfig(mUi->uRestoreLevelingAfterG28Box, pJson, "RESTORE_LEVELING_AFTER_G28");
    success &= LoadConfig(mUi->uEnableLevelingAfterG28Box, pJson, "ENABLE_LEVELING_AFTER_G28");
    success &= LoadConfig(mUi->uLevelingNozzleTempSpinBox, pJson, "LEVELING_NOZZLE_TEMP");
    success &= LoadConfig(mUi->uLevelingBedTempSpinBox, pJson, "LEVELING_BED_TEMP");
    success &= LoadConfig(mUi->uBdSensorBox, pJson, "BD_SENSOR");
    success &= LoadConfig(mUi->uDebugLevelingFeatureBox, pJson, "DEBUG_LEVELING_FEATURE");
    success &= LoadConfig(mUi->uManualProbeStartZSpinBox, pJson, "MANUAL_PROBE_START_Z");
    success &= LoadConfig(mUi->uManualProbeStartZBox, pJson, "ENABLE_MANUAL_PROBE_START_Z");
    success &= LoadConfig(mUi->uEnableLevelingFadeHeightBox, pJson, "ENABLE_LEVELING_FADE_HEIGHT");
    success &= LoadConfig(mUi->uDefaultLevelingFadeHeightSpinBox, pJson, "DEFAULT_LEVELING_FADE_HEIGHT");
    success &= LoadConfig(mUi->uSegmentLeveledMovesBox, pJson, "SEGMENT_LEVELED_MOVES");
    success &= LoadConfig(mUi->uLeveledSegmentLengthSpinBox, pJson, "LEVELED_SEGMENT_LENGTH");
    success &= LoadConfig(mUi->uG26MeshValidationBox, pJson, "G26_MESH_VALIDATION");
    success &= LoadConfig(mUi->uMeshTestNozzleSizeSpinBox, pJson, "MESH_TEST_NOZZLE_SIZE");
    success &= LoadConfig(mUi->uMeshTestLayerHeightSpinBox, pJson, "MESH_TEST_LAYER_HEIGHT");
    success &= LoadConfig(mUi->uMeshTestHotendTempSpinBox, pJson, "MESH_TEST_HOTEND_TEMP");
    success &= LoadConfig(mUi->uMeshTestBedTempSpinBox, pJson, "MESH_TEST_BED_TEMP");
    success &= LoadConfig(mUi->uG26XyFeedrateSpinBox, pJson, "G26_XY_FEEDRATE");
    success &= LoadConfig(mUi->uG26XyFeedrateTravelSpinBox, pJson, "G26_XY_FEEDRATE_TRAVEL");
    success &= LoadConfig(mUi->uG26RetractMultiplierSpinBox, pJson, "G26_RETRACT_MULTIPLIER");
    success &= LoadConfig(mUi->uPreheatBeforeLevelingBox, pJson, "PREHEAT_BEFORE_LEVELING");

    mIsLoading = false;
    return success;
}

void BedLevelingPage::FetchConfiguration(Configuration& pConfig)
{
    SetConfig(pConfig.bedLeveling.AUTO_BED_LEVELING_3POINT, mUi->uAutoBedLeveling3pointBox);
    SetConfig(pConfig.bedLeveling.AUTO_BED_LEVELING_LINEAR, mUi->uAutoBedLevelingLinearBox);
    SetConfig(pConfig.bedLeveling.AUTO_BED_LEVELING_BILINEAR, mUi->uAutoBedLevelingBilinearBox);
    SetConfig(pConfig.bedLeveling.AUTO_BED_LEVELING_UBL, mUi->uAutoBedLevelingUblBox);
    SetConfig(pConfig.bedLeveling.MESH_BED_LEVELING, mUi->uMeshBedLevelingBox);
    SetConfig(pConfig.bedLeveling.RESTORE_LEVELING_AFTER_G28, mUi->uRestoreLevelingAfterG28Box);
    SetConfig(pConfig.bedLeveling.ENABLE_LEVELING_AFTER_G28, mUi->uEnableLevelingAfterG28Box);
    SetConfig(pConfig.bedLeveling.LEVELING_NOZZLE_TEMP, mUi->uLevelingNozzleTempSpinBox);
    SetConfig(pConfig.bedLeveling.LEVELING_BED_TEMP, mUi->uLevelingBedTempSpinBox);
    SetConfig(pConfig.bedLeveling.BD_SENSOR, mUi->uBdSensorBox);
    SetConfig(pConfig.bedLeveling.DEBUG_LEVELING_FEATURE, mUi->uDebugLevelingFeatureBox);
    SetConfig(pConfig.bedLeveling.MANUAL_PROBE_START_Z, mUi->uManualProbeStartZSpinBox);
    SetConfig(pConfig.bedLeveling.ENABLE_MANUAL_PROBE_START_Z, mUi->uManualProbeStartZBox);
    SetConfig(pConfig.bedLeveling.ENABLE_LEVELING_FADE_HEIGHT, mUi->uEnableLevelingFadeHeightBox);
    SetConfig(pConfig.bedLeveling.DEFAULT_LEVELING_FADE_HEIGHT, mUi->uDefaultLevelingFadeHeightSpinBox);
    SetConfig(pConfig.bedLeveling.SEGMENT_LEVELED_MOVES, mUi->uSegmentLeveledMovesBox);
    SetConfig(pConfig.bedLeveling.LEVELED_SEGMENT_LENGTH, mUi->uLeveledSegmentLengthSpinBox);
    SetConfig(pConfig.bedLeveling.G26_MESH_VALIDATION, mUi->uG26MeshValidationBox);
    SetConfig(pConfig.bedLeveling.MESH_TEST_NOZZLE_SIZE, mUi->uMeshTestNozzleSizeSpinBox);
    SetConfig(pConfig.bedLeveling.MESH_TEST_LAYER_HEIGHT, mUi->uMeshTestLayerHeightSpinBox);
    SetConfig(pConfig.bedLeveling.MESH_TEST_HOTEND_TEMP, mUi->uMeshTestHotendTempSpinBox);
    SetConfig(pConfig.bedLeveling.MESH_TEST_BED_TEMP, mUi->uMeshTestBedTempSpinBox);
    SetConfig(pConfig.bedLeveling.G26_XY_FEEDRATE, mUi->uG26XyFeedrateSpinBox);
    SetConfig(pConfig.bedLeveling.G26_XY_FEEDRATE_TRAVEL, mUi->uG26XyFeedrateTravelSpinBox);
    SetConfig(pConfig.bedLeveling.G26_RETRACT_MULTIPLIER, mUi->uG26RetractMultiplierSpinBox);
    SetConfig(pConfig.bedLeveling.PREHEAT_BEFORE_LEVELING, mUi->uPreheatBeforeLevelingBox);
}

void BedLevelingPage::ReplaceTags(QStringList& pOutput)
{
    ReplaceTag(pOutput, "#{AUTO_BED_LEVELING_3POINT}", mUi->uAutoBedLeveling3pointBox, "AUTO_BED_LEVELING_3POINT");
    ReplaceTag(pOutput, "#{AUTO_BED_LEVELING_LINEAR}", mUi->uAutoBedLevelingLinearBox, "AUTO_BED_LEVELING_LINEAR");
    ReplaceTag(pOutput, "#{AUTO_BED_LEVELING_BILINEAR}", mUi->uAutoBedLevelingBilinearBox, "AUTO_BED_LEVELING_BILINEAR");
    ReplaceTag(pOutput, "#{AUTO_BED_LEVELING_UBL}", mUi->uAutoBedLevelingUblBox, "AUTO_BED_LEVELING_UBL");
    ReplaceTag(pOutput, "#{MESH_BED_LEVELING}", mUi->uMeshBedLevelingBox, "MESH_BED_LEVELING");
    ReplaceTag(pOutput, "#{RESTORE_LEVELING_AFTER_G28}", mUi->uRestoreLevelingAfterG28Box, "RESTORE_LEVELING_AFTER_G28");
    ReplaceTag(pOutput, "#{ENABLE_LEVELING_AFTER_G28}", mUi->uEnableLevelingAfterG28Box, "ENABLE_LEVELING_AFTER_G28");
    ReplaceTag(pOutput, "#{LEVELING_NOZZLE_TEMP}", mUi->uLevelingNozzleTempSpinBox, false, "LEVELING_NOZZLE_TEMP");
    ReplaceTag(pOutput, "#{LEVELING_BED_TEMP}", mUi->uLevelingBedTempSpinBox, false, "LEVELING_BED_TEMP");
    ReplaceTag(pOutput, "#{BD_SENSOR}", mUi->uBdSensorBox, "BD_SENSOR");
    ReplaceTag(pOutput, "#{DEBUG_LEVELING_FEATURE}", mUi->uDebugLevelingFeatureBox, "DEBUG_LEVELING_FEATURE");
    ReplaceTag(pOutput, "#{MANUAL_PROBE_START_Z}", mUi->uManualProbeStartZSpinBox, !mUi->uManualProbeStartZBox->isChecked(), "MANUAL_PROBE_START_Z", 1);
    ReplaceTag(pOutput, "#{ENABLE_LEVELING_FADE_HEIGHT}", mUi->uEnableLevelingFadeHeightBox, "ENABLE_LEVELING_FADE_HEIGHT");
    ReplaceTag(pOutput, "#{DEFAULT_LEVELING_FADE_HEIGHT}", mUi->uDefaultLevelingFadeHeightSpinBox, false, "DEFAULT_LEVELING_FADE_HEIGHT", 1);
    ReplaceTag(pOutput, "#{SEGMENT_LEVELED_MOVES}", mUi->uSegmentLeveledMovesBox, "SEGMENT_LEVELED_MOVES");
    ReplaceTag(pOutput, "#{LEVELED_SEGMENT_LENGTH}", mUi->uLeveledSegmentLengthSpinBox, false, "LEVELED_SEGMENT_LENGTH", 1);
    ReplaceTag(pOutput, "#{G26_MESH_VALIDATION}", mUi->uG26MeshValidationBox, "G26_MESH_VALIDATION");
    ReplaceTag(pOutput, "#{MESH_TEST_NOZZLE_SIZE}", mUi->uMeshTestNozzleSizeSpinBox, false, "MESH_TEST_NOZZLE_SIZE", 1);
    ReplaceTag(pOutput, "#{MESH_TEST_LAYER_HEIGHT}", mUi->uMeshTestLayerHeightSpinBox, false, "MESH_TEST_LAYER_HEIGHT", 1);
    ReplaceTag(pOutput, "#{MESH_TEST_HOTEND_TEMP}", mUi->uMeshTestHotendTempSpinBox, false, "MESH_TEST_HOTEND_TEMP");
    ReplaceTag(pOutput, "#{MESH_TEST_BED_TEMP}", mUi->uMeshTestBedTempSpinBox, false, "MESH_TEST_BED_TEMP");
    ReplaceTag(pOutput, "#{G26_XY_FEEDRATE}", mUi->uG26XyFeedrateSpinBox, false, "G26_XY_FEEDRATE");
    ReplaceTag(pOutput, "#{G26_XY_FEEDRATE_TRAVEL}", mUi->uG26XyFeedrateTravelSpinBox, false, "G26_XY_FEEDRATE_TRAVEL");
    ReplaceTag(pOutput, "#{G26_RETRACT_MULTIPLIER}", mUi->uG26RetractMultiplierSpinBox, false, "G26_RETRACT_MULTIPLIER", 1);
    ReplaceTag(pOutput, "#{PREHEAT_BEFORE_LEVELING}", mUi->uPreheatBeforeLevelingBox, "PREHEAT_BEFORE_LEVELING");
}
