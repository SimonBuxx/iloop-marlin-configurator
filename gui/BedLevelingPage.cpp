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

        mUi->uMeshBedLevelingTab->setEnabled(pChecked);
    });

    QObject::connect(mUi->uAutoBedLevelingBilinearBox, &QGroupBox::toggled, this, [&](auto pChecked){
        mUi->uEnableLevelingFadeHeightBox->setEnabled(pChecked || mUi->uMeshBedLevelingBox->isChecked() || mUi->uAutoBedLevelingUblBox->isChecked());
        mUi->uSegmentLeveledMovesBox->setEnabled(pChecked || mUi->uMeshBedLevelingBox->isChecked() || mUi->uAutoBedLevelingUblBox->isChecked());
        mUi->uLeveledSegmentLengthBox->setEnabled(pChecked || mUi->uMeshBedLevelingBox->isChecked() || mUi->uAutoBedLevelingUblBox->isChecked());
        mUi->uG26MeshValidationBox->setEnabled(pChecked || mUi->uMeshBedLevelingBox->isChecked() || mUi->uAutoBedLevelingUblBox->isChecked());

        mUi->uLinearBilinearBedLevelingTab->setEnabled(pChecked || mUi->uAutoBedLevelingLinearBox->isChecked());
        mUi->uExtrapolateBeyondGridBox->setEnabled(pChecked);
        mUi->uAblBilinearSubdivisionBox->setEnabled(pChecked);
    });

    QObject::connect(mUi->uAutoBedLevelingLinearBox, &QGroupBox::toggled, this, [&](auto pChecked){
        mUi->uLinearBilinearBedLevelingTab->setEnabled(pChecked || mUi->uAutoBedLevelingBilinearBox->isChecked());
    });

    QObject::connect(mUi->uAutoBedLevelingUblBox, &QGroupBox::toggled, this, [&](auto pChecked){
        mUi->uEnableLevelingFadeHeightBox->setEnabled(pChecked || mUi->uAutoBedLevelingBilinearBox->isChecked() || mUi->uMeshBedLevelingBox->isChecked());
        mUi->uSegmentLeveledMovesBox->setEnabled(pChecked || mUi->uAutoBedLevelingBilinearBox->isChecked() || mUi->uMeshBedLevelingBox->isChecked());
        mUi->uLeveledSegmentLengthBox->setEnabled(pChecked || mUi->uAutoBedLevelingBilinearBox->isChecked() || mUi->uMeshBedLevelingBox->isChecked());
        mUi->uG26MeshValidationBox->setEnabled(pChecked || mUi->uAutoBedLevelingBilinearBox->isChecked() || mUi->uMeshBedLevelingBox->isChecked());

        mUi->uUnifiedBedLevelingTab->setEnabled(pChecked);
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
    mUi->uGridMaxPointsXSpinBox->setValue(defaults::GRID_MAX_POINTS_X);
    mUi->uGridMaxPointsYSpinBox->setValue(defaults::GRID_MAX_POINTS_Y);
    mUi->uProbeYFirstBox->setChecked(defaults::PROBE_Y_FIRST);
    mUi->uExtrapolateBeyondGridBox->setChecked(defaults::EXTRAPOLATE_BEYOND_GRID);
    mUi->uAblBilinearSubdivisionBox->setChecked(defaults::ABL_BILINEAR_SUBDIVISION);
    mUi->uBilinearSubdivisionsSpinBox->setValue(defaults::BILINEAR_SUBDIVISIONS);
    mUi->uMeshEditGfxOverlayBox->setChecked(defaults::MESH_EDIT_GFX_OVERLAY);
    mUi->uMeshInsetSpinBox->setValue(defaults::MESH_INSET);
    mUi->uGridMaxPointsXSpinBox_2->setValue(defaults::GRID_MAX_POINTS_X_2);
    mUi->uGridMaxPointsYSpinBox_2->setValue(defaults::GRID_MAX_POINTS_Y_2);
    mUi->uUblHilbertCurveBox->setChecked(defaults::UBL_HILBERT_CURVE);
    mUi->uUblMeshEditMovesZBox->setChecked(defaults::UBL_MESH_EDIT_MOVES_Z);
    mUi->uUblSaveActiveOnM500Box->setChecked(defaults::UBL_SAVE_ACTIVE_ON_M500);
    mUi->uUblZRaiseWhenOffMeshSpinBox->setValue(defaults::UBL_Z_RAISE_WHEN_OFF_MESH);
    mUi->uUblZRaiseWhenOffMeshBox->setChecked(defaults::ENABLE_UBL_Z_RAISE_WHEN_OFF_MESH);
    mUi->uUblMeshWizardBox->setChecked(defaults::UBL_MESH_WIZARD);
    mUi->uMeshInsetSpinBox_2->setValue(defaults::MESH_INSET_2);
    mUi->uGridMaxPointsXSpinBox_3->setValue(defaults::GRID_MAX_POINTS_X_3);
    mUi->uGridMaxPointsYSpinBox_3->setValue(defaults::GRID_MAX_POINTS_Y_3);
    mUi->uMeshG28RestOriginBox->setChecked(defaults::MESH_G28_REST_ORIGIN);

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
    success &= LoadConfig(mUi->uGridMaxPointsXSpinBox, pJson, "GRID_MAX_POINTS_X");
    success &= LoadConfig(mUi->uGridMaxPointsYSpinBox, pJson, "GRID_MAX_POINTS_Y");
    success &= LoadConfig(mUi->uProbeYFirstBox, pJson, "PROBE_Y_FIRST");
    success &= LoadConfig(mUi->uExtrapolateBeyondGridBox, pJson, "EXTRAPOLATE_BEYOND_GRID");
    success &= LoadConfig(mUi->uAblBilinearSubdivisionBox, pJson, "ABL_BILINEAR_SUBDIVISION");
    success &= LoadConfig(mUi->uBilinearSubdivisionsSpinBox, pJson, "BILINEAR_SUBDIVISIONS");
    success &= LoadConfig(mUi->uMeshEditGfxOverlayBox, pJson, "MESH_EDIT_GFX_OVERLAY");
    success &= LoadConfig(mUi->uMeshInsetSpinBox, pJson, "MESH_INSET");
    success &= LoadConfig(mUi->uGridMaxPointsXSpinBox_2, pJson, "GRID_MAX_POINTS_X_2");
    success &= LoadConfig(mUi->uGridMaxPointsYSpinBox_2, pJson, "GRID_MAX_POINTS_Y_2");
    success &= LoadConfig(mUi->uUblHilbertCurveBox, pJson, "UBL_HILBERT_CURVE");
    success &= LoadConfig(mUi->uUblMeshEditMovesZBox, pJson, "UBL_MESH_EDIT_MOVES_Z");
    success &= LoadConfig(mUi->uUblSaveActiveOnM500Box, pJson, "UBL_SAVE_ACTIVE_ON_M500");
    success &= LoadConfig(mUi->uUblZRaiseWhenOffMeshSpinBox, pJson, "UBL_Z_RAISE_WHEN_OFF_MESH");
    success &= LoadConfig(mUi->uUblZRaiseWhenOffMeshBox, pJson, "ENABLE_UBL_Z_RAISE_WHEN_OFF_MESH");
    success &= LoadConfig(mUi->uUblMeshWizardBox, pJson, "UBL_MESH_WIZARD");
    success &= LoadConfig(mUi->uMeshInsetSpinBox_2, pJson, "MESH_INSET_2");
    success &= LoadConfig(mUi->uGridMaxPointsXSpinBox_3, pJson, "GRID_MAX_POINTS_X_3");
    success &= LoadConfig(mUi->uGridMaxPointsYSpinBox_3, pJson, "GRID_MAX_POINTS_Y_3");
    success &= LoadConfig(mUi->uMeshG28RestOriginBox, pJson, "MESH_G28_REST_ORIGIN");

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
    SetConfig(pConfig.bedLeveling.GRID_MAX_POINTS_X, mUi->uGridMaxPointsXSpinBox);
    SetConfig(pConfig.bedLeveling.GRID_MAX_POINTS_Y, mUi->uGridMaxPointsYSpinBox);
    SetConfig(pConfig.bedLeveling.PROBE_Y_FIRST, mUi->uProbeYFirstBox);
    SetConfig(pConfig.bedLeveling.EXTRAPOLATE_BEYOND_GRID, mUi->uExtrapolateBeyondGridBox);
    SetConfig(pConfig.bedLeveling.ABL_BILINEAR_SUBDIVISION, mUi->uAblBilinearSubdivisionBox);
    SetConfig(pConfig.bedLeveling.BILINEAR_SUBDIVISIONS, mUi->uBilinearSubdivisionsSpinBox);
    SetConfig(pConfig.bedLeveling.MESH_EDIT_GFX_OVERLAY, mUi->uMeshEditGfxOverlayBox);
    SetConfig(pConfig.bedLeveling.MESH_INSET, mUi->uMeshInsetSpinBox);
    SetConfig(pConfig.bedLeveling.GRID_MAX_POINTS_X_2, mUi->uGridMaxPointsXSpinBox_2);
    SetConfig(pConfig.bedLeveling.GRID_MAX_POINTS_Y_2, mUi->uGridMaxPointsYSpinBox_2);
    SetConfig(pConfig.bedLeveling.UBL_HILBERT_CURVE, mUi->uUblHilbertCurveBox);
    SetConfig(pConfig.bedLeveling.UBL_MESH_EDIT_MOVES_Z, mUi->uUblMeshEditMovesZBox);
    SetConfig(pConfig.bedLeveling.UBL_SAVE_ACTIVE_ON_M500, mUi->uUblSaveActiveOnM500Box);
    SetConfig(pConfig.bedLeveling.UBL_Z_RAISE_WHEN_OFF_MESH, mUi->uUblZRaiseWhenOffMeshSpinBox);
    SetConfig(pConfig.bedLeveling.ENABLE_UBL_Z_RAISE_WHEN_OFF_MESH, mUi->uUblZRaiseWhenOffMeshBox);
    SetConfig(pConfig.bedLeveling.UBL_MESH_WIZARD, mUi->uUblMeshWizardBox);
    SetConfig(pConfig.bedLeveling.MESH_INSET_2, mUi->uMeshInsetSpinBox_2);
    SetConfig(pConfig.bedLeveling.GRID_MAX_POINTS_X_3, mUi->uGridMaxPointsXSpinBox_3);
    SetConfig(pConfig.bedLeveling.GRID_MAX_POINTS_Y_3, mUi->uGridMaxPointsYSpinBox_3);
    SetConfig(pConfig.bedLeveling.MESH_G28_REST_ORIGIN, mUi->uMeshG28RestOriginBox);
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
    ReplaceTag(pOutput, "#{GRID_MAX_POINTS_X}", mUi->uGridMaxPointsXSpinBox, false, "GRID_MAX_POINTS_X");
    ReplaceTag(pOutput, "#{GRID_MAX_POINTS_Y}", mUi->uGridMaxPointsYSpinBox, false, "GRID_MAX_POINTS_Y");
    ReplaceTag(pOutput, "#{PROBE_Y_FIRST}", mUi->uProbeYFirstBox, "PROBE_Y_FIRST");
    ReplaceTag(pOutput, "#{EXTRAPOLATE_BEYOND_GRID}", mUi->uExtrapolateBeyondGridBox, "EXTRAPOLATE_BEYOND_GRID");
    ReplaceTag(pOutput, "#{ABL_BILINEAR_SUBDIVISION}", mUi->uAblBilinearSubdivisionBox, "ABL_BILINEAR_SUBDIVISION");
    ReplaceTag(pOutput, "#{BILINEAR_SUBDIVISIONS}", mUi->uBilinearSubdivisionsSpinBox, false, "BILINEAR_SUBDIVISIONS");
    ReplaceTag(pOutput, "#{MESH_EDIT_GFX_OVERLAY}", mUi->uMeshEditGfxOverlayBox, "MESH_EDIT_GFX_OVERLAY");
    ReplaceTag(pOutput, "#{MESH_INSET}", mUi->uMeshInsetSpinBox, false, "MESH_INSET");
    ReplaceTag(pOutput, "#{GRID_MAX_POINTS_X_2}", mUi->uGridMaxPointsXSpinBox_2, false, "GRID_MAX_POINTS_X");
    ReplaceTag(pOutput, "#{GRID_MAX_POINTS_Y_2}", mUi->uGridMaxPointsYSpinBox_2, false, "GRID_MAX_POINTS_Y");
    ReplaceTag(pOutput, "#{UBL_HILBERT_CURVE}", mUi->uUblHilbertCurveBox, "UBL_HILBERT_CURVE");
    ReplaceTag(pOutput, "#{UBL_MESH_EDIT_MOVES_Z}", mUi->uUblMeshEditMovesZBox, "UBL_MESH_EDIT_MOVES_Z");
    ReplaceTag(pOutput, "#{UBL_SAVE_ACTIVE_ON_M500}", mUi->uUblSaveActiveOnM500Box, "UBL_SAVE_ACTIVE_ON_M500");
    ReplaceTag(pOutput, "#{UBL_Z_RAISE_WHEN_OFF_MESH}", mUi->uUblZRaiseWhenOffMeshSpinBox, !mUi->uUblZRaiseWhenOffMeshBox->isChecked(), "UBL_Z_RAISE_WHEN_OFF_MESH", 1);
    ReplaceTag(pOutput, "#{ENABLE_UBL_Z_RAISE_WHEN_OFF_MESH}", mUi->uUblZRaiseWhenOffMeshBox, "ENABLE_UBL_Z_RAISE_WHEN_OFF_MESH");
    ReplaceTag(pOutput, "#{UBL_MESH_WIZARD}", mUi->uUblMeshWizardBox, "UBL_MESH_WIZARD");
    ReplaceTag(pOutput, "#{MESH_INSET_2}", mUi->uMeshInsetSpinBox_2, false, "MESH_INSET");
    ReplaceTag(pOutput, "#{GRID_MAX_POINTS_X_3}", mUi->uGridMaxPointsXSpinBox_3, false, "GRID_MAX_POINTS_X");
    ReplaceTag(pOutput, "#{GRID_MAX_POINTS_Y_3}", mUi->uGridMaxPointsYSpinBox_3, false, "GRID_MAX_POINTS_Y");
    ReplaceTag(pOutput, "#{MESH_G28_REST_ORIGIN}", mUi->uMeshG28RestOriginBox, "MESH_G28_REST_ORIGIN");
}
