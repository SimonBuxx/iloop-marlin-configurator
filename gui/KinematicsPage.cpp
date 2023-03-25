/*!
 * \file KinematicsPage.cpp
/// \brief The KinematicsPage class represents the kinematics page
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

#include "KinematicsPage.h"
#include "./ui_KinematicsPage.h"
#include "HelperFunctions.h"

KinematicsPage::KinematicsPage(QWidget *pParent) :
    AbstractPage(KINEMATICS_TEMPLATE_PATH, pParent),
    mUi(new Ui::KinematicsPage)
{
    mUi->setupUi(this);
}

KinematicsPage::~KinematicsPage()
{
    delete mUi;
}

void KinematicsPage::ConnectGuiSignalsAndSlots()
{
    QObject::connect(mUi->uDocumentationButton, &QPushButton::clicked, this, [&]()
    {
        OpenMarlinDocumentation("kinematics");
    });

    QObject::connect(mUi->uDeltaAutoCalibrationBox, &QGroupBox::toggled, this, [&](auto pChecked){
        mUi->uProbeManuallyStepBox->setEnabled(pChecked || mUi->uDeltaCalibrationMenuBox->isChecked());
    });

    QObject::connect(mUi->uDeltaCalibrationMenuBox, &QGroupBox::toggled, this, [&](auto pChecked){
        mUi->uProbeManuallyStepBox->setEnabled(pChecked || mUi->uDeltaAutoCalibrationBox->isChecked());
    });

    QObject::connect(mUi->uPolargraphBox, &QGroupBox::toggled, this, [&](auto pChecked){
        mUi->uDefaultSegmentsPerSecondBox->setEnabled(pChecked || mUi->uMorganScaraBox->isChecked() || mUi->uMpScaraBox->isChecked() || mUi->uAxelTparaBox->isChecked() || mUi->uDeltaBox->isChecked());
    });

    QObject::connect(mUi->uDeltaBox, &QGroupBox::toggled, this, [&](auto pChecked){
        mUi->uDefaultSegmentsPerSecondBox->setEnabled(pChecked || mUi->uMorganScaraBox->isChecked() || mUi->uMpScaraBox->isChecked() || mUi->uAxelTparaBox->isChecked() || mUi->uPolargraphBox->isChecked());
    });

    QObject::connect(mUi->uMorganScaraBox, &QGroupBox::toggled, this, [&](auto pChecked){
        mUi->uDefaultSegmentsPerSecondBox->setEnabled(pChecked || mUi->uDeltaBox->isChecked() || mUi->uMpScaraBox->isChecked() || mUi->uAxelTparaBox->isChecked() || mUi->uPolargraphBox->isChecked());
        mUi->uMiddleDeadZoneRBox->setEnabled(pChecked || mUi->uAxelTparaBox->isChecked());
        mUi->uScaraFeedrateScalingBox->setEnabled(pChecked || mUi->uAxelTparaBox->isChecked());
        mUi->uThetaHomingOffsetBox->setEnabled(pChecked || mUi->uAxelTparaBox->isChecked());
        mUi->uPsiHomingOffsetBox->setEnabled(pChecked || mUi->uAxelTparaBox->isChecked());
        mUi->uScaraOffsetXBox->setEnabled(pChecked || mUi->uMpScaraBox->isChecked());
        mUi->uScaraOffsetYBox->setEnabled(pChecked || mUi->uMpScaraBox->isChecked());
        mUi->uScaraLinkage1Box->setEnabled(pChecked || mUi->uMpScaraBox->isChecked());
        mUi->uScaraLinkage2Box->setEnabled(pChecked || mUi->uMpScaraBox->isChecked());
    });

    QObject::connect(mUi->uMpScaraBox, &QGroupBox::toggled, this, [&](auto pChecked){
        mUi->uDefaultSegmentsPerSecondBox->setEnabled(pChecked || mUi->uDeltaBox->isChecked() || mUi->uMorganScaraBox->isChecked() || mUi->uAxelTparaBox->isChecked() || mUi->uPolargraphBox->isChecked());
        mUi->uScaraOffsetXBox->setEnabled(pChecked || mUi->uMorganScaraBox->isChecked());
        mUi->uScaraOffsetYBox->setEnabled(pChecked || mUi->uMorganScaraBox->isChecked());
        mUi->uScaraLinkage1Box->setEnabled(pChecked || mUi->uMorganScaraBox->isChecked());
        mUi->uScaraLinkage2Box->setEnabled(pChecked || mUi->uMorganScaraBox->isChecked());
    });

    QObject::connect(mUi->uAxelTparaBox, &QGroupBox::toggled, this, [&](auto pChecked){
        mUi->uDefaultSegmentsPerSecondBox->setEnabled(pChecked || mUi->uDeltaBox->isChecked() || mUi->uMorganScaraBox->isChecked() || mUi->uMpScaraBox->isChecked() || mUi->uPolargraphBox->isChecked());
        mUi->uMiddleDeadZoneRBox->setEnabled(pChecked || mUi->uMorganScaraBox->isChecked());
        mUi->uScaraFeedrateScalingBox->setEnabled(pChecked || mUi->uMorganScaraBox->isChecked());
        mUi->uThetaHomingOffsetBox->setEnabled(pChecked || mUi->uMorganScaraBox->isChecked());
        mUi->uPsiHomingOffsetBox->setEnabled(pChecked || mUi->uMorganScaraBox->isChecked());
    });

    AbstractPage::ConnectGuiSignalsAndSlots();
}

void KinematicsPage::ResetValues()
{
    mIsLoading = true;

    mUi->uCorexyBox->setChecked(defaults::COREXY);
    mUi->uCorexzBox->setChecked(defaults::COREXZ);
    mUi->uCoreyzBox->setChecked(defaults::COREYZ);
    mUi->uCoreyxBox->setChecked(defaults::COREYX);
    mUi->uCorezxBox->setChecked(defaults::COREZX);
    mUi->uCorezyBox->setChecked(defaults::COREZY);
    mUi->uMarkforgedXyBox->setChecked(defaults::MARKFORGED_XY);
    mUi->uMarkforgedYxBox->setChecked(defaults::MARKFORGED_YX);
    mUi->uBeltprinterBox->setChecked(defaults::BELTPRINTER);
    mUi->uPolargraphBox->setChecked(defaults::POLARGRAPH);
    mUi->uPolargraphMaxBeltLenSpinBox->setValue(defaults::POLARGRAPH_MAX_BELT_LEN);
    mUi->uDefaultSegmentsPerSecondSpinBox->setValue(defaults::DEFAULT_SEGMENTS_PER_SECOND);
    mUi->uDeltaBox->setChecked(defaults::DELTA);
    mUi->uDeltaHomeToSafeZoneBox->setChecked(defaults::DELTA_HOME_TO_SAFE_ZONE);
    mUi->uDeltaCalibrationMenuBox->setChecked(defaults::DELTA_CALIBRATION_MENU);
    mUi->uDeltaAutoCalibrationBox->setChecked(defaults::DELTA_AUTO_CALIBRATION);
    mUi->uDeltaCalibrationDefaultPointsSpinBox->setValue(defaults::DELTA_CALIBRATION_DEFAULT_POINTS);
    mUi->uProbeManuallyStepSpinBox->setValue(defaults::PROBE_MANUALLY_STEP);
    mUi->uDeltaPrintableRadiusSpinBox->setValue(defaults::DELTA_PRINTABLE_RADIUS);
    mUi->uDeltaMaxRadiusSpinBox->setValue(defaults::DELTA_MAX_RADIUS);
    mUi->uDeltaDiagonalRodSpinBox->setValue(defaults::DELTA_DIAGONAL_ROD);
    mUi->uDeltaHeightSpinBox->setValue(defaults::DELTA_HEIGHT);
    mUi->uDeltaEndstopAdjEdit->setText(defaults::DELTA_ENDSTOP_ADJ);
    mUi->uDeltaRadiusSpinBox->setValue(defaults::DELTA_RADIUS);
    mUi->uDeltaTowerAngleTrimEdit->setText(defaults::DELTA_TOWER_ANGLE_TRIM);
    mUi->uDeltaRadiusTrimTowerEdit->setText(defaults::DELTA_RADIUS_TRIM_TOWER);
    mUi->uDeltaDiagonalRodTrimTowerEdit->setText(defaults::DELTA_DIAGONAL_ROD_TRIM_TOWER);
    mUi->uDeltaRadiusTrimTowerBox->setChecked(defaults::ENABLE_DELTA_RADIUS_TRIM_TOWER);
    mUi->uDeltaDiagonalRodTrimTowerBox->setChecked(defaults::ENABLE_DELTA_DIAGONAL_ROD_TRIM_TOWER);
    mUi->uMorganScaraBox->setChecked(defaults::MORGAN_SCARA);
    mUi->uMpScaraBox->setChecked(defaults::MP_SCARA);
    mUi->uScaraLinkage1SpinBox->setValue(defaults::SCARA_LINKAGE_1);
    mUi->uScaraLinkage2SpinBox->setValue(defaults::SCARA_LINKAGE_2);
    mUi->uScaraOffsetXSpinBox->setValue(defaults::SCARA_OFFSET_X);
    mUi->uScaraOffsetYSpinBox->setValue(defaults::SCARA_OFFSET_Y);
    mUi->uDebugScaraKinematicsBox->setChecked(defaults::DEBUG_SCARA_KINEMATICS);
    mUi->uScaraFeedrateScalingBox->setChecked(defaults::SCARA_FEEDRATE_SCALING);
    mUi->uMiddleDeadZoneRSpinBox->setValue(defaults::MIDDLE_DEAD_ZONE_R);
    mUi->uThetaHomingOffsetSpinBox->setValue(defaults::THETA_HOMING_OFFSET);
    mUi->uPsiHomingOffsetSpinBox->setValue(defaults::PSI_HOMING_OFFSET);
    mUi->uScaraOffsetTheta1SpinBox->setValue(defaults::SCARA_OFFSET_THETA1);
    mUi->uScaraOffsetTheta2SpinBox->setValue(defaults::SCARA_OFFSET_THETA2);
    mUi->uAxelTparaBox->setChecked(defaults::AXEL_TPARA);
    mUi->uDebugTparaKinematicsBox->setChecked(defaults::DEBUG_TPARA_KINEMATICS);
    mUi->uTparaLinkage1SpinBox->setValue(defaults::TPARA_LINKAGE_1);
    mUi->uTparaLinkage2SpinBox->setValue(defaults::TPARA_LINKAGE_2);
    mUi->uTparaOffsetXSpinBox->setValue(defaults::TPARA_OFFSET_X);
    mUi->uTparaOffsetYSpinBox->setValue(defaults::TPARA_OFFSET_Y);
    mUi->uTparaOffsetZSpinBox->setValue(defaults::TPARA_OFFSET_Z);
    mUi->uArticulatedRobotArmBox->setChecked(defaults::ARTICULATED_ROBOT_ARM);
    mUi->uFoamcutterXyuvBox->setChecked(defaults::FOAMCUTTER_XYUV);

    mUi->uKinematicsTabWidget->setCurrentIndex(0);

    mIsLoading = false;
}

bool KinematicsPage::LoadFromJson(const QJsonObject &pJson)
{
    bool success = true;
    mIsLoading = true;

    success &= LoadConfig(mUi->uCorexyBox, pJson, "COREXY");
    success &= LoadConfig(mUi->uCorexzBox, pJson, "COREXZ");
    success &= LoadConfig(mUi->uCoreyzBox, pJson, "COREYZ");
    success &= LoadConfig(mUi->uCoreyxBox, pJson, "COREYX");
    success &= LoadConfig(mUi->uCorezxBox, pJson, "COREZX");
    success &= LoadConfig(mUi->uCorezyBox, pJson, "COREZY");
    success &= LoadConfig(mUi->uMarkforgedXyBox, pJson, "MARKFORGED_XY");
    success &= LoadConfig(mUi->uMarkforgedYxBox, pJson, "MARKFORGED_YX");
    success &= LoadConfig(mUi->uBeltprinterBox, pJson, "BELTPRINTER");
    success &= LoadConfig(mUi->uPolargraphBox, pJson, "POLARGRAPH");
    success &= LoadConfig(mUi->uPolargraphMaxBeltLenSpinBox, pJson, "POLARGRAPH_MAX_BELT_LEN");
    success &= LoadConfig(mUi->uDefaultSegmentsPerSecondSpinBox, pJson, "DEFAULT_SEGMENTS_PER_SECOND");
    success &= LoadConfig(mUi->uDeltaBox, pJson, "DELTA");
    success &= LoadConfig(mUi->uDeltaHomeToSafeZoneBox, pJson, "DELTA_HOME_TO_SAFE_ZONE");
    success &= LoadConfig(mUi->uDeltaCalibrationMenuBox, pJson, "DELTA_CALIBRATION_MENU");
    success &= LoadConfig(mUi->uDeltaAutoCalibrationBox, pJson, "DELTA_AUTO_CALIBRATION");
    success &= LoadConfig(mUi->uDeltaCalibrationDefaultPointsSpinBox, pJson, "DELTA_CALIBRATION_DEFAULT_POINTS");
    success &= LoadConfig(mUi->uProbeManuallyStepSpinBox, pJson, "PROBE_MANUALLY_STEP");
    success &= LoadConfig(mUi->uDeltaPrintableRadiusSpinBox, pJson, "DELTA_PRINTABLE_RADIUS");
    success &= LoadConfig(mUi->uDeltaMaxRadiusSpinBox, pJson, "DELTA_MAX_RADIUS");
    success &= LoadConfig(mUi->uDeltaDiagonalRodSpinBox, pJson, "DELTA_DIAGONAL_ROD");
    success &= LoadConfig(mUi->uDeltaHeightSpinBox, pJson, "DELTA_HEIGHT");
    success &= LoadConfig(mUi->uDeltaEndstopAdjEdit, pJson, "DELTA_ENDSTOP_ADJ");
    success &= LoadConfig(mUi->uDeltaRadiusSpinBox, pJson, "DELTA_RADIUS");
    success &= LoadConfig(mUi->uDeltaTowerAngleTrimEdit, pJson, "DELTA_TOWER_ANGLE_TRIM");
    success &= LoadConfig(mUi->uDeltaRadiusTrimTowerEdit, pJson, "DELTA_RADIUS_TRIM_TOWER");
    success &= LoadConfig(mUi->uDeltaDiagonalRodTrimTowerEdit, pJson, "DELTA_DIAGONAL_ROD_TRIM_TOWER");
    success &= LoadConfig(mUi->uDeltaRadiusTrimTowerBox, pJson, "ENABLE_DELTA_RADIUS_TRIM_TOWER");
    success &= LoadConfig(mUi->uDeltaDiagonalRodTrimTowerBox, pJson, "ENABLE_DELTA_DIAGONAL_ROD_TRIM_TOWER");
    success &= LoadConfig(mUi->uMorganScaraBox, pJson, "MORGAN_SCARA");
    success &= LoadConfig(mUi->uMpScaraBox, pJson, "MP_SCARA");
    success &= LoadConfig(mUi->uScaraLinkage1SpinBox, pJson, "SCARA_LINKAGE_1");
    success &= LoadConfig(mUi->uScaraLinkage2SpinBox, pJson, "SCARA_LINKAGE_2");
    success &= LoadConfig(mUi->uScaraOffsetXSpinBox, pJson, "SCARA_OFFSET_X");
    success &= LoadConfig(mUi->uScaraOffsetYSpinBox, pJson, "SCARA_OFFSET_Y");
    success &= LoadConfig(mUi->uDebugScaraKinematicsBox, pJson, "DEBUG_SCARA_KINEMATICS");
    success &= LoadConfig(mUi->uScaraFeedrateScalingBox, pJson, "SCARA_FEEDRATE_SCALING");
    success &= LoadConfig(mUi->uMiddleDeadZoneRSpinBox, pJson, "MIDDLE_DEAD_ZONE_R");
    success &= LoadConfig(mUi->uThetaHomingOffsetSpinBox, pJson, "THETA_HOMING_OFFSET");
    success &= LoadConfig(mUi->uPsiHomingOffsetSpinBox, pJson, "PSI_HOMING_OFFSET");
    success &= LoadConfig(mUi->uScaraOffsetTheta1SpinBox, pJson, "SCARA_OFFSET_THETA1");
    success &= LoadConfig(mUi->uScaraOffsetTheta2SpinBox, pJson, "SCARA_OFFSET_THETA2");
    success &= LoadConfig(mUi->uAxelTparaBox, pJson, "AXEL_TPARA");
    success &= LoadConfig(mUi->uDebugTparaKinematicsBox, pJson, "DEBUG_TPARA_KINEMATICS");
    success &= LoadConfig(mUi->uTparaLinkage1SpinBox, pJson, "TPARA_LINKAGE_1");
    success &= LoadConfig(mUi->uTparaLinkage2SpinBox, pJson, "TPARA_LINKAGE_2");
    success &= LoadConfig(mUi->uTparaOffsetXSpinBox, pJson, "TPARA_OFFSET_X");
    success &= LoadConfig(mUi->uTparaOffsetYSpinBox, pJson, "TPARA_OFFSET_Y");
    success &= LoadConfig(mUi->uTparaOffsetZSpinBox, pJson, "TPARA_OFFSET_Z");
    success &= LoadConfig(mUi->uArticulatedRobotArmBox, pJson, "ARTICULATED_ROBOT_ARM");
    success &= LoadConfig(mUi->uFoamcutterXyuvBox, pJson, "FOAMCUTTER_XYUV");

    mIsLoading = false;
    return success;
}

void KinematicsPage::FetchConfiguration(Configuration& pConfig)
{
    SetConfig(pConfig.kinematics.COREXY, mUi->uCorexyBox);
    SetConfig(pConfig.kinematics.COREXZ, mUi->uCorexzBox);
    SetConfig(pConfig.kinematics.COREYZ, mUi->uCoreyzBox);
    SetConfig(pConfig.kinematics.COREYX, mUi->uCoreyxBox);
    SetConfig(pConfig.kinematics.COREZX, mUi->uCorezxBox);
    SetConfig(pConfig.kinematics.COREZY, mUi->uCorezyBox);
    SetConfig(pConfig.kinematics.MARKFORGED_XY, mUi->uMarkforgedXyBox);
    SetConfig(pConfig.kinematics.MARKFORGED_YX, mUi->uMarkforgedYxBox);
    SetConfig(pConfig.kinematics.BELTPRINTER, mUi->uBeltprinterBox);
    SetConfig(pConfig.kinematics.POLARGRAPH, mUi->uPolargraphBox);
    SetConfig(pConfig.kinematics.POLARGRAPH_MAX_BELT_LEN, mUi->uPolargraphMaxBeltLenSpinBox);
    SetConfig(pConfig.kinematics.DEFAULT_SEGMENTS_PER_SECOND, mUi->uDefaultSegmentsPerSecondSpinBox);
    SetConfig(pConfig.kinematics.DELTA, mUi->uDeltaBox);
    SetConfig(pConfig.kinematics.DELTA_HOME_TO_SAFE_ZONE, mUi->uDeltaHomeToSafeZoneBox);
    SetConfig(pConfig.kinematics.DELTA_CALIBRATION_MENU, mUi->uDeltaCalibrationMenuBox);
    SetConfig(pConfig.kinematics.DELTA_AUTO_CALIBRATION, mUi->uDeltaAutoCalibrationBox);
    SetConfig(pConfig.kinematics.DELTA_CALIBRATION_DEFAULT_POINTS, mUi->uDeltaCalibrationDefaultPointsSpinBox);
    SetConfig(pConfig.kinematics.PROBE_MANUALLY_STEP, mUi->uProbeManuallyStepSpinBox);
    SetConfig(pConfig.kinematics.DELTA_PRINTABLE_RADIUS, mUi->uDeltaPrintableRadiusSpinBox);
    SetConfig(pConfig.kinematics.DELTA_MAX_RADIUS, mUi->uDeltaMaxRadiusSpinBox);
    SetConfig(pConfig.kinematics.DELTA_DIAGONAL_ROD, mUi->uDeltaDiagonalRodSpinBox);
    SetConfig(pConfig.kinematics.DELTA_HEIGHT, mUi->uDeltaHeightSpinBox);
    SetConfig(pConfig.kinematics.DELTA_ENDSTOP_ADJ, mUi->uDeltaEndstopAdjEdit);
    SetConfig(pConfig.kinematics.DELTA_RADIUS, mUi->uDeltaRadiusSpinBox);
    SetConfig(pConfig.kinematics.DELTA_TOWER_ANGLE_TRIM, mUi->uDeltaTowerAngleTrimEdit);
    SetConfig(pConfig.kinematics.DELTA_RADIUS_TRIM_TOWER, mUi->uDeltaRadiusTrimTowerEdit);
    SetConfig(pConfig.kinematics.DELTA_DIAGONAL_ROD_TRIM_TOWER, mUi->uDeltaDiagonalRodTrimTowerEdit);
    SetConfig(pConfig.kinematics.ENABLE_DELTA_RADIUS_TRIM_TOWER, mUi->uDeltaRadiusTrimTowerBox);
    SetConfig(pConfig.kinematics.ENABLE_DELTA_DIAGONAL_ROD_TRIM_TOWER, mUi->uDeltaDiagonalRodTrimTowerBox);
    SetConfig(pConfig.kinematics.MORGAN_SCARA, mUi->uMorganScaraBox);
    SetConfig(pConfig.kinematics.MP_SCARA, mUi->uMpScaraBox);
    SetConfig(pConfig.kinematics.SCARA_LINKAGE_1, mUi->uScaraLinkage1SpinBox);
    SetConfig(pConfig.kinematics.SCARA_LINKAGE_2, mUi->uScaraLinkage2SpinBox);
    SetConfig(pConfig.kinematics.SCARA_OFFSET_X, mUi->uScaraOffsetXSpinBox);
    SetConfig(pConfig.kinematics.SCARA_OFFSET_Y, mUi->uScaraOffsetYSpinBox);
    SetConfig(pConfig.kinematics.DEBUG_SCARA_KINEMATICS, mUi->uDebugScaraKinematicsBox);
    SetConfig(pConfig.kinematics.SCARA_FEEDRATE_SCALING, mUi->uScaraFeedrateScalingBox);
    SetConfig(pConfig.kinematics.MIDDLE_DEAD_ZONE_R, mUi->uMiddleDeadZoneRSpinBox);
    SetConfig(pConfig.kinematics.THETA_HOMING_OFFSET, mUi->uThetaHomingOffsetSpinBox);
    SetConfig(pConfig.kinematics.PSI_HOMING_OFFSET, mUi->uPsiHomingOffsetSpinBox);
    SetConfig(pConfig.kinematics.SCARA_OFFSET_THETA1, mUi->uScaraOffsetTheta1SpinBox);
    SetConfig(pConfig.kinematics.SCARA_OFFSET_THETA2, mUi->uScaraOffsetTheta2SpinBox);
    SetConfig(pConfig.kinematics.AXEL_TPARA, mUi->uAxelTparaBox);
    SetConfig(pConfig.kinematics.DEBUG_TPARA_KINEMATICS, mUi->uDebugTparaKinematicsBox);
    SetConfig(pConfig.kinematics.TPARA_LINKAGE_1, mUi->uTparaLinkage1SpinBox);
    SetConfig(pConfig.kinematics.TPARA_LINKAGE_2, mUi->uTparaLinkage2SpinBox);
    SetConfig(pConfig.kinematics.TPARA_OFFSET_X, mUi->uTparaOffsetXSpinBox);
    SetConfig(pConfig.kinematics.TPARA_OFFSET_Y, mUi->uTparaOffsetYSpinBox);
    SetConfig(pConfig.kinematics.TPARA_OFFSET_Z, mUi->uTparaOffsetZSpinBox);
    SetConfig(pConfig.kinematics.ARTICULATED_ROBOT_ARM, mUi->uArticulatedRobotArmBox);
    SetConfig(pConfig.kinematics.FOAMCUTTER_XYUV, mUi->uFoamcutterXyuvBox);
}

void KinematicsPage::ReplaceTags(QStringList& pOutput)
{
    ReplaceTag(pOutput, "#{COREXY}", mUi->uCorexyBox, "COREXY");
    ReplaceTag(pOutput, "#{COREXZ}", mUi->uCorexzBox, "COREXZ");
    ReplaceTag(pOutput, "#{COREYZ}", mUi->uCoreyzBox, "COREYZ");
    ReplaceTag(pOutput, "#{COREYX}", mUi->uCoreyxBox, "COREYX");
    ReplaceTag(pOutput, "#{COREZX}", mUi->uCorezxBox, "COREZX");
    ReplaceTag(pOutput, "#{COREZY}", mUi->uCorezyBox, "COREZY");
    ReplaceTag(pOutput, "#{MARKFORGED_XY}", mUi->uMarkforgedXyBox, "MARKFORGED_XY");
    ReplaceTag(pOutput, "#{MARKFORGED_YX}", mUi->uMarkforgedYxBox, "MARKFORGED_YX");
    ReplaceTag(pOutput, "#{BELTPRINTER}", mUi->uBeltprinterBox, "BELTPRINTER");
    ReplaceTag(pOutput, "#{POLARGRAPH}", mUi->uPolargraphBox, "POLARGRAPH");
    ReplaceTag(pOutput, "#{POLARGRAPH_MAX_BELT_LEN}", mUi->uPolargraphMaxBeltLenSpinBox, false, "POLARGRAPH_MAX_BELT_LEN", 1);
    ReplaceTag(pOutput, "#{DEFAULT_SEGMENTS_PER_SECOND}", mUi->uDefaultSegmentsPerSecondSpinBox,
               !(mUi->uPolargraphBox->isChecked() || mUi->uDeltaBox->isChecked() || mUi->uMorganScaraBox->isChecked() || mUi->uMpScaraBox->isChecked() || mUi->uAxelTparaBox->isChecked()), "DEFAULT_SEGMENTS_PER_SECOND");
    ReplaceTag(pOutput, "#{DELTA}", mUi->uDeltaBox, "DELTA");
    ReplaceTag(pOutput, "#{DELTA_HOME_TO_SAFE_ZONE}", mUi->uDeltaHomeToSafeZoneBox, "DELTA_HOME_TO_SAFE_ZONE");
    ReplaceTag(pOutput, "#{DELTA_CALIBRATION_MENU}", mUi->uDeltaCalibrationMenuBox, "DELTA_CALIBRATION_MENU");
    ReplaceTag(pOutput, "#{DELTA_AUTO_CALIBRATION}", mUi->uDeltaAutoCalibrationBox, "DELTA_AUTO_CALIBRATION");
    ReplaceTag(pOutput, "#{DELTA_CALIBRATION_DEFAULT_POINTS}", mUi->uDeltaCalibrationDefaultPointsSpinBox, false, "DELTA_CALIBRATION_DEFAULT_POINTS");
    ReplaceTag(pOutput, "#{PROBE_MANUALLY_STEP}", mUi->uProbeManuallyStepSpinBox, !(mUi->uDeltaAutoCalibrationBox->isChecked() || mUi->uDeltaCalibrationMenuBox->isChecked()), "PROBE_MANUALLY_STEP");
    ReplaceTag(pOutput, "#{DELTA_PRINTABLE_RADIUS}", mUi->uDeltaPrintableRadiusSpinBox, false, "DELTA_PRINTABLE_RADIUS", 1);
    ReplaceTag(pOutput, "#{DELTA_MAX_RADIUS}", mUi->uDeltaMaxRadiusSpinBox, false, "DELTA_MAX_RADIUS", 1);
    ReplaceTag(pOutput, "#{DELTA_DIAGONAL_ROD}", mUi->uDeltaDiagonalRodSpinBox, false, "DELTA_DIAGONAL_ROD", 1);
    ReplaceTag(pOutput, "#{DELTA_HEIGHT}", mUi->uDeltaHeightSpinBox, false, "DELTA_HEIGHT");
    ReplaceTag(pOutput, "#{DELTA_ENDSTOP_ADJ}", mUi->uDeltaEndstopAdjEdit, false, "DELTA_ENDSTOP_ADJ");
    ReplaceTag(pOutput, "#{DELTA_RADIUS}", mUi->uDeltaRadiusSpinBox, false, "DELTA_RADIUS", 1);
    ReplaceTag(pOutput, "#{DELTA_TOWER_ANGLE_TRIM}", mUi->uDeltaTowerAngleTrimEdit, false, "DELTA_TOWER_ANGLE_TRIM");
    ReplaceTag(pOutput, "#{DELTA_RADIUS_TRIM_TOWER}", mUi->uDeltaRadiusTrimTowerEdit, !mUi->uDeltaRadiusTrimTowerBox->isChecked(), "DELTA_RADIUS_TRIM_TOWER");
    ReplaceTag(pOutput, "#{DELTA_DIAGONAL_ROD_TRIM_TOWER}", mUi->uDeltaDiagonalRodTrimTowerEdit, !mUi->uDeltaDiagonalRodTrimTowerBox->isChecked(), "DELTA_DIAGONAL_ROD_TRIM_TOWER");
    ReplaceTag(pOutput, "#{MORGAN_SCARA}", mUi->uMorganScaraBox, "MORGAN_SCARA");
    ReplaceTag(pOutput, "#{MP_SCARA}", mUi->uMpScaraBox, "MP_SCARA");
    ReplaceTag(pOutput, "#{SCARA_LINKAGE_1}", mUi->uScaraLinkage1SpinBox, false, "SCARA_LINKAGE_1");
    ReplaceTag(pOutput, "#{SCARA_LINKAGE_2}", mUi->uScaraLinkage2SpinBox, false, "SCARA_LINKAGE_2");
    ReplaceTag(pOutput, "#{SCARA_OFFSET_X}", mUi->uScaraOffsetXSpinBox, false, "SCARA_OFFSET_X");
    ReplaceTag(pOutput, "#{SCARA_OFFSET_Y}", mUi->uScaraOffsetYSpinBox, false, "SCARA_OFFSET_Y");
    ReplaceTag(pOutput, "#{DEBUG_SCARA_KINEMATICS}", mUi->uDebugScaraKinematicsBox, "DEBUG_SCARA_KINEMATICS");
    ReplaceTag(pOutput, "#{SCARA_FEEDRATE_SCALING}", mUi->uScaraFeedrateScalingBox, "SCARA_FEEDRATE_SCALING");
    ReplaceTag(pOutput, "#{MIDDLE_DEAD_ZONE_R}", mUi->uMiddleDeadZoneRSpinBox, !(mUi->uMorganScaraBox->isChecked() || mUi->uAxelTparaBox->isChecked()), "MIDDLE_DEAD_ZONE_R");
    ReplaceTag(pOutput, "#{THETA_HOMING_OFFSET}", mUi->uThetaHomingOffsetSpinBox, !(mUi->uMorganScaraBox->isChecked() || mUi->uAxelTparaBox->isChecked()), "THETA_HOMING_OFFSET");
    ReplaceTag(pOutput, "#{PSI_HOMING_OFFSET}", mUi->uPsiHomingOffsetSpinBox, !(mUi->uMorganScaraBox->isChecked() || mUi->uAxelTparaBox->isChecked()), "PSI_HOMING_OFFSET");
    ReplaceTag(pOutput, "#{SCARA_OFFSET_THETA1}", mUi->uScaraOffsetTheta1SpinBox, false, "SCARA_OFFSET_THETA1");
    ReplaceTag(pOutput, "#{SCARA_OFFSET_THETA2}", mUi->uScaraOffsetTheta2SpinBox, false, "SCARA_OFFSET_THETA2");
    ReplaceTag(pOutput, "#{AXEL_TPARA}", mUi->uAxelTparaBox, "AXEL_TPARA");
    ReplaceTag(pOutput, "#{DEBUG_TPARA_KINEMATICS}", mUi->uDebugTparaKinematicsBox, "DEBUG_TPARA_KINEMATICS");
    ReplaceTag(pOutput, "#{TPARA_LINKAGE_1}", mUi->uTparaLinkage1SpinBox, false, "TPARA_LINKAGE_1");
    ReplaceTag(pOutput, "#{TPARA_LINKAGE_2}", mUi->uTparaLinkage2SpinBox, false, "TPARA_LINKAGE_2");
    ReplaceTag(pOutput, "#{TPARA_OFFSET_X}", mUi->uTparaOffsetXSpinBox, false, "TPARA_OFFSET_X");
    ReplaceTag(pOutput, "#{TPARA_OFFSET_Y}", mUi->uTparaOffsetYSpinBox, false, "TPARA_OFFSET_Y");
    ReplaceTag(pOutput, "#{TPARA_OFFSET_Z}", mUi->uTparaOffsetZSpinBox, false, "TPARA_OFFSET_Z");
    ReplaceTag(pOutput, "#{ARTICULATED_ROBOT_ARM}", mUi->uArticulatedRobotArmBox, "ARTICULATED_ROBOT_ARM");
    ReplaceTag(pOutput, "#{FOAMCUTTER_XYUV}", mUi->uFoamcutterXyuvBox, "FOAMCUTTER_XYUV");
}
