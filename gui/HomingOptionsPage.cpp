/*!
 * \file HomingOptionsPage.cpp
/// \brief The HomingOptionsPage class represents the homing options page
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

#include "HomingOptionsPage.h"
#include "./ui_HomingOptionsPage.h"
#include "HelperFunctions.h"

HomingOptionsPage::HomingOptionsPage(QWidget *pParent) :
    AbstractPage(HOMING_OPTIONS_TEMPLATE_PATH, pParent),
    mUi(new Ui::HomingOptionsPage)
{
    mUi->setupUi(this);
}

HomingOptionsPage::~HomingOptionsPage()
{
    delete mUi;
}

void HomingOptionsPage::ConnectGuiSignalsAndSlots()
{
    QObject::connect(mUi->uDocumentationButton, &QPushButton::clicked, this, [&]()
    {
        OpenMarlinDocumentation("homing-options");
    });

    AbstractPage::ConnectGuiSignalsAndSlots();
}

void HomingOptionsPage::ResetValues()
{
    mIsLoading = true;

    mUi->uBedCenterAt00Box->setChecked(defaults::BED_CENTER_AT_0_0);
    mUi->uManualXHomePosSpinBox->setValue(defaults::MANUAL_X_HOME_POS);
    mUi->uManualYHomePosSpinBox->setValue(defaults::MANUAL_Y_HOME_POS);
    mUi->uManualZHomePosSpinBox->setValue(defaults::MANUAL_Z_HOME_POS);
    mUi->uManualIHomePosSpinBox->setValue(defaults::MANUAL_I_HOME_POS);
    mUi->uManualJHomePosSpinBox->setValue(defaults::MANUAL_J_HOME_POS);
    mUi->uManualKHomePosSpinBox->setValue(defaults::MANUAL_K_HOME_POS);
    mUi->uManualUHomePosSpinBox->setValue(defaults::MANUAL_U_HOME_POS);
    mUi->uManualVHomePosSpinBox->setValue(defaults::MANUAL_V_HOME_POS);
    mUi->uManualWHomePosSpinBox->setValue(defaults::MANUAL_W_HOME_POS);
    mUi->uManualXHomePosBox->setChecked(defaults::ENABLE_MANUAL_X_HOME_POS);
    mUi->uManualYHomePosBox->setChecked(defaults::ENABLE_MANUAL_Y_HOME_POS);
    mUi->uManualZHomePosBox->setChecked(defaults::ENABLE_MANUAL_Z_HOME_POS);
    mUi->uManualIHomePosBox->setChecked(defaults::ENABLE_MANUAL_I_HOME_POS);
    mUi->uManualJHomePosBox->setChecked(defaults::ENABLE_MANUAL_J_HOME_POS);
    mUi->uManualKHomePosBox->setChecked(defaults::ENABLE_MANUAL_K_HOME_POS);
    mUi->uManualUHomePosBox->setChecked(defaults::ENABLE_MANUAL_U_HOME_POS);
    mUi->uManualVHomePosBox->setChecked(defaults::ENABLE_MANUAL_V_HOME_POS);
    mUi->uManualWHomePosBox->setChecked(defaults::ENABLE_MANUAL_W_HOME_POS);
    mUi->uZSafeHomingBox->setChecked(defaults::Z_SAFE_HOMING);
    mUi->uZSafeHomingXPointSpinBox->setValue(defaults::Z_SAFE_HOMING_X_POINT);
    mUi->uZSafeHomingYPointSpinBox->setValue(defaults::Z_SAFE_HOMING_Y_POINT);
    mUi->uZSafeHomingXPointBox->setChecked(defaults::ENABLE_Z_SAFE_HOMING_X_POINT);
    mUi->uZSafeHomingYPointBox->setChecked(defaults::ENABLE_Z_SAFE_HOMING_Y_POINT);
    mUi->uHomingFeedrateMmMEdit->setText(defaults::HOMING_FEEDRATE_MM_M);
    mUi->uValidateHomingEndstopsBox->setChecked(defaults::VALIDATE_HOMING_ENDSTOPS);
    mUi->uSkewCorrectionBox->setChecked(defaults::SKEW_CORRECTION);
    mUi->uXyDiagAcSpinBox->setValue(defaults::XY_DIAG_AC);
    mUi->uXyDiagBdSpinBox->setValue(defaults::XY_DIAG_BD);
    mUi->uXySideAdSpinBox->setValue(defaults::XY_SIDE_AD);
    mUi->uXySkewFactorSpinBox->setValue(defaults::XY_SKEW_FACTOR);
    mUi->uXySkewFactorBox->setChecked(defaults::ENABLE_XY_SKEW_FACTOR);
    mUi->uSkewCorrectionForZBox->setChecked(defaults::SKEW_CORRECTION_FOR_Z);
    mUi->uXzDiagAcSpinBox->setValue(defaults::XZ_DIAG_AC);
    mUi->uXzDiagBdSpinBox->setValue(defaults::XZ_DIAG_BD);
    mUi->uYzDiagAcSpinBox->setValue(defaults::YZ_DIAG_AC);
    mUi->uYzDiagBdSpinBox->setValue(defaults::YZ_DIAG_BD);
    mUi->uYzSideAdSpinBox->setValue(defaults::YZ_SIDE_AD);
    mUi->uXzSkewFactorSpinBox->setValue(defaults::XZ_SKEW_FACTOR);
    mUi->uYzSkewFactorSpinBox->setValue(defaults::YZ_SKEW_FACTOR);
    mUi->uXzSkewFactorBox->setChecked(defaults::ENABLE_XZ_SKEW_FACTOR);
    mUi->uYzSkewFactorBox->setChecked(defaults::ENABLE_YZ_SKEW_FACTOR);
    mUi->uSkewCorrectionGcodeBox->setChecked(defaults::SKEW_CORRECTION_GCODE);

    mUi->uManualHomingPositionTabWidget->setCurrentIndex(0);

    mIsLoading = false;
}

bool HomingOptionsPage::LoadFromJson(const QJsonObject &pJson)
{
    bool success = true;
    mIsLoading = true;

    success &= LoadConfig(mUi->uBedCenterAt00Box, pJson, "BED_CENTER_AT_0_0");
    success &= LoadConfig(mUi->uManualXHomePosSpinBox, pJson, "MANUAL_X_HOME_POS");
    success &= LoadConfig(mUi->uManualYHomePosSpinBox, pJson, "MANUAL_Y_HOME_POS");
    success &= LoadConfig(mUi->uManualZHomePosSpinBox, pJson, "MANUAL_Z_HOME_POS");
    success &= LoadConfig(mUi->uManualIHomePosSpinBox, pJson, "MANUAL_I_HOME_POS");
    success &= LoadConfig(mUi->uManualJHomePosSpinBox, pJson, "MANUAL_J_HOME_POS");
    success &= LoadConfig(mUi->uManualKHomePosSpinBox, pJson, "MANUAL_K_HOME_POS");
    success &= LoadConfig(mUi->uManualUHomePosSpinBox, pJson, "MANUAL_U_HOME_POS");
    success &= LoadConfig(mUi->uManualVHomePosSpinBox, pJson, "MANUAL_V_HOME_POS");
    success &= LoadConfig(mUi->uManualWHomePosSpinBox, pJson, "MANUAL_W_HOME_POS");
    success &= LoadConfig(mUi->uManualXHomePosBox, pJson, "ENABLE_MANUAL_X_HOME_POS");
    success &= LoadConfig(mUi->uManualYHomePosBox, pJson, "ENABLE_MANUAL_Y_HOME_POS");
    success &= LoadConfig(mUi->uManualZHomePosBox, pJson, "ENABLE_MANUAL_Z_HOME_POS");
    success &= LoadConfig(mUi->uManualIHomePosBox, pJson, "ENABLE_MANUAL_I_HOME_POS");
    success &= LoadConfig(mUi->uManualJHomePosBox, pJson, "ENABLE_MANUAL_J_HOME_POS");
    success &= LoadConfig(mUi->uManualKHomePosBox, pJson, "ENABLE_MANUAL_K_HOME_POS");
    success &= LoadConfig(mUi->uManualUHomePosBox, pJson, "ENABLE_MANUAL_U_HOME_POS");
    success &= LoadConfig(mUi->uManualVHomePosBox, pJson, "ENABLE_MANUAL_V_HOME_POS");
    success &= LoadConfig(mUi->uManualWHomePosBox, pJson, "ENABLE_MANUAL_W_HOME_POS");
    success &= LoadConfig(mUi->uZSafeHomingBox, pJson, "Z_SAFE_HOMING");
    success &= LoadConfig(mUi->uZSafeHomingXPointSpinBox, pJson, "Z_SAFE_HOMING_X_POINT");
    success &= LoadConfig(mUi->uZSafeHomingYPointSpinBox, pJson, "Z_SAFE_HOMING_Y_POINT");
    success &= LoadConfig(mUi->uZSafeHomingXPointBox, pJson, "ENABLE_Z_SAFE_HOMING_X_POINT");
    success &= LoadConfig(mUi->uZSafeHomingYPointBox, pJson, "ENABLE_Z_SAFE_HOMING_Y_POINT");
    success &= LoadConfig(mUi->uHomingFeedrateMmMEdit, pJson, "HOMING_FEEDRATE_MM_M");
    success &= LoadConfig(mUi->uValidateHomingEndstopsBox, pJson, "VALIDATE_HOMING_ENDSTOPS");
    success &= LoadConfig(mUi->uSkewCorrectionBox, pJson, "SKEW_CORRECTION");
    success &= LoadConfig(mUi->uXyDiagAcSpinBox, pJson, "XY_DIAG_AC");
    success &= LoadConfig(mUi->uXyDiagBdSpinBox, pJson, "XY_DIAG_BD");
    success &= LoadConfig(mUi->uXySideAdSpinBox, pJson, "XY_SIDE_AD");
    success &= LoadConfig(mUi->uXySkewFactorSpinBox, pJson, "XY_SKEW_FACTOR");
    success &= LoadConfig(mUi->uXySkewFactorBox, pJson, "ENABLE_XY_SKEW_FACTOR");
    success &= LoadConfig(mUi->uSkewCorrectionForZBox, pJson, "SKEW_CORRECTION_FOR_Z");
    success &= LoadConfig(mUi->uXzDiagAcSpinBox, pJson, "XZ_DIAG_AC");
    success &= LoadConfig(mUi->uXzDiagBdSpinBox, pJson, "XZ_DIAG_BD");
    success &= LoadConfig(mUi->uYzDiagAcSpinBox, pJson, "YZ_DIAG_AC");
    success &= LoadConfig(mUi->uYzDiagBdSpinBox, pJson, "YZ_DIAG_BD");
    success &= LoadConfig(mUi->uYzSideAdSpinBox, pJson, "YZ_SIDE_AD");
    success &= LoadConfig(mUi->uXzSkewFactorSpinBox, pJson, "XZ_SKEW_FACTOR");
    success &= LoadConfig(mUi->uYzSkewFactorSpinBox, pJson, "YZ_SKEW_FACTOR");
    success &= LoadConfig(mUi->uXzSkewFactorBox, pJson, "ENABLE_XZ_SKEW_FACTOR");
    success &= LoadConfig(mUi->uYzSkewFactorBox, pJson, "ENABLE_YZ_SKEW_FACTOR");
    success &= LoadConfig(mUi->uSkewCorrectionGcodeBox, pJson, "SKEW_CORRECTION_GCODE");

    mIsLoading = false;
    return success;
}

void HomingOptionsPage::FetchConfiguration(Configuration& pConfig)
{
    SetConfig(pConfig.homingOptions.BED_CENTER_AT_0_0, mUi->uBedCenterAt00Box);
    SetConfig(pConfig.homingOptions.MANUAL_X_HOME_POS, mUi->uManualXHomePosSpinBox);
    SetConfig(pConfig.homingOptions.MANUAL_Y_HOME_POS, mUi->uManualYHomePosSpinBox);
    SetConfig(pConfig.homingOptions.MANUAL_Z_HOME_POS, mUi->uManualZHomePosSpinBox);
    SetConfig(pConfig.homingOptions.MANUAL_I_HOME_POS, mUi->uManualIHomePosSpinBox);
    SetConfig(pConfig.homingOptions.MANUAL_J_HOME_POS, mUi->uManualJHomePosSpinBox);
    SetConfig(pConfig.homingOptions.MANUAL_K_HOME_POS, mUi->uManualKHomePosSpinBox);
    SetConfig(pConfig.homingOptions.MANUAL_U_HOME_POS, mUi->uManualUHomePosSpinBox);
    SetConfig(pConfig.homingOptions.MANUAL_V_HOME_POS, mUi->uManualVHomePosSpinBox);
    SetConfig(pConfig.homingOptions.MANUAL_W_HOME_POS, mUi->uManualWHomePosSpinBox);
    SetConfig(pConfig.homingOptions.ENABLE_MANUAL_X_HOME_POS, mUi->uManualXHomePosBox);
    SetConfig(pConfig.homingOptions.ENABLE_MANUAL_Y_HOME_POS, mUi->uManualYHomePosBox);
    SetConfig(pConfig.homingOptions.ENABLE_MANUAL_Z_HOME_POS, mUi->uManualZHomePosBox);
    SetConfig(pConfig.homingOptions.ENABLE_MANUAL_I_HOME_POS, mUi->uManualIHomePosBox);
    SetConfig(pConfig.homingOptions.ENABLE_MANUAL_J_HOME_POS, mUi->uManualJHomePosBox);
    SetConfig(pConfig.homingOptions.ENABLE_MANUAL_K_HOME_POS, mUi->uManualKHomePosBox);
    SetConfig(pConfig.homingOptions.ENABLE_MANUAL_U_HOME_POS, mUi->uManualUHomePosBox);
    SetConfig(pConfig.homingOptions.ENABLE_MANUAL_V_HOME_POS, mUi->uManualVHomePosBox);
    SetConfig(pConfig.homingOptions.ENABLE_MANUAL_W_HOME_POS, mUi->uManualWHomePosBox);
    SetConfig(pConfig.homingOptions.Z_SAFE_HOMING, mUi->uZSafeHomingBox);
    SetConfig(pConfig.homingOptions.Z_SAFE_HOMING_X_POINT, mUi->uZSafeHomingXPointSpinBox);
    SetConfig(pConfig.homingOptions.Z_SAFE_HOMING_Y_POINT, mUi->uZSafeHomingYPointSpinBox);
    SetConfig(pConfig.homingOptions.ENABLE_Z_SAFE_HOMING_X_POINT, mUi->uZSafeHomingXPointBox);
    SetConfig(pConfig.homingOptions.ENABLE_Z_SAFE_HOMING_Y_POINT, mUi->uZSafeHomingYPointBox);
    SetConfig(pConfig.homingOptions.HOMING_FEEDRATE_MM_M, mUi->uHomingFeedrateMmMEdit);
    SetConfig(pConfig.homingOptions.VALIDATE_HOMING_ENDSTOPS, mUi->uValidateHomingEndstopsBox);
    SetConfig(pConfig.homingOptions.SKEW_CORRECTION, mUi->uSkewCorrectionBox);
    SetConfig(pConfig.homingOptions.XY_DIAG_AC, mUi->uXyDiagAcSpinBox);
    SetConfig(pConfig.homingOptions.XY_DIAG_BD, mUi->uXyDiagBdSpinBox);
    SetConfig(pConfig.homingOptions.XY_SIDE_AD, mUi->uXySideAdSpinBox);
    SetConfig(pConfig.homingOptions.XY_SKEW_FACTOR, mUi->uXySkewFactorSpinBox);
    SetConfig(pConfig.homingOptions.ENABLE_XY_SKEW_FACTOR, mUi->uXySkewFactorBox);
    SetConfig(pConfig.homingOptions.SKEW_CORRECTION_FOR_Z, mUi->uSkewCorrectionForZBox);
    SetConfig(pConfig.homingOptions.XZ_DIAG_AC, mUi->uXzDiagAcSpinBox);
    SetConfig(pConfig.homingOptions.XZ_DIAG_BD, mUi->uXzDiagBdSpinBox);
    SetConfig(pConfig.homingOptions.YZ_DIAG_AC, mUi->uYzDiagAcSpinBox);
    SetConfig(pConfig.homingOptions.YZ_DIAG_BD, mUi->uYzDiagBdSpinBox);
    SetConfig(pConfig.homingOptions.YZ_SIDE_AD, mUi->uYzSideAdSpinBox);
    SetConfig(pConfig.homingOptions.XZ_SKEW_FACTOR, mUi->uXzSkewFactorSpinBox);
    SetConfig(pConfig.homingOptions.YZ_SKEW_FACTOR, mUi->uYzSkewFactorSpinBox);
    SetConfig(pConfig.homingOptions.ENABLE_XZ_SKEW_FACTOR, mUi->uXzSkewFactorBox);
    SetConfig(pConfig.homingOptions.ENABLE_YZ_SKEW_FACTOR, mUi->uYzSkewFactorBox);
    SetConfig(pConfig.homingOptions.SKEW_CORRECTION_GCODE, mUi->uSkewCorrectionGcodeBox);
}

void HomingOptionsPage::ReplaceTags(QStringList& pOutput)
{
    ReplaceTag(pOutput, "#{BED_CENTER_AT_0_0}", mUi->uBedCenterAt00Box, "BED_CENTER_AT_0_0");
    ReplaceTag(pOutput, "#{MANUAL_X_HOME_POS}", mUi->uManualXHomePosSpinBox, !mUi->uManualXHomePosBox->isChecked(), "MANUAL_X_HOME_POS");
    ReplaceTag(pOutput, "#{MANUAL_Y_HOME_POS}", mUi->uManualYHomePosSpinBox, !mUi->uManualYHomePosBox->isChecked(), "MANUAL_Y_HOME_POS");
    ReplaceTag(pOutput, "#{MANUAL_Z_HOME_POS}", mUi->uManualZHomePosSpinBox, !mUi->uManualZHomePosBox->isChecked(), "MANUAL_Z_HOME_POS");
    ReplaceTag(pOutput, "#{MANUAL_I_HOME_POS}", mUi->uManualIHomePosSpinBox, !mUi->uManualIHomePosBox->isChecked(), "MANUAL_I_HOME_POS");
    ReplaceTag(pOutput, "#{MANUAL_J_HOME_POS}", mUi->uManualJHomePosSpinBox, !mUi->uManualJHomePosBox->isChecked(), "MANUAL_J_HOME_POS");
    ReplaceTag(pOutput, "#{MANUAL_K_HOME_POS}", mUi->uManualKHomePosSpinBox, !mUi->uManualKHomePosBox->isChecked(), "MANUAL_K_HOME_POS");
    ReplaceTag(pOutput, "#{MANUAL_U_HOME_POS}", mUi->uManualUHomePosSpinBox, !mUi->uManualUHomePosBox->isChecked(), "MANUAL_U_HOME_POS");
    ReplaceTag(pOutput, "#{MANUAL_V_HOME_POS}", mUi->uManualVHomePosSpinBox, !mUi->uManualVHomePosBox->isChecked(), "MANUAL_V_HOME_POS");
    ReplaceTag(pOutput, "#{MANUAL_W_HOME_POS}", mUi->uManualWHomePosSpinBox, !mUi->uManualWHomePosBox->isChecked(), "MANUAL_W_HOME_POS");
    ReplaceTag(pOutput, "#{Z_SAFE_HOMING}", mUi->uZSafeHomingBox, "Z_SAFE_HOMING");
    if (mUi->uZSafeHomingXPointBox->isEnabled())
    {
        pOutput.replaceInStrings("#{Z_SAFE_HOMING_X_POINT}", QString("%0#define %1 %2").arg("", "Z_SAFE_HOMING_X_POINT", !mUi->uZSafeHomingXPointBox->isChecked() ? "X_CENTER" : QString::number(mUi->uZSafeHomingXPointSpinBox->value())));
    }
    else
    {
        pOutput.replaceInStrings("#{Z_SAFE_HOMING_X_POINT}", QString("%0#define %1 %2").arg("//", "Z_SAFE_HOMING_X_POINT", ""));
    }
    if (mUi->uZSafeHomingYPointBox->isEnabled())
    {
        pOutput.replaceInStrings("#{Z_SAFE_HOMING_Y_POINT}", QString("%0#define %1 %2").arg("", "Z_SAFE_HOMING_Y_POINT", !mUi->uZSafeHomingYPointBox->isChecked() ? "Y_CENTER" : QString::number(mUi->uZSafeHomingYPointSpinBox->value())));
    }
    else
    {
        pOutput.replaceInStrings("#{Z_SAFE_HOMING_Y_POINT}", QString("%0#define %1 %2").arg("//", "Z_SAFE_HOMING_Y_POINT", ""));
    }
    ReplaceTag(pOutput, "#{HOMING_FEEDRATE_MM_M}", mUi->uHomingFeedrateMmMEdit, false, "HOMING_FEEDRATE_MM_M");
    ReplaceTag(pOutput, "#{VALIDATE_HOMING_ENDSTOPS}", mUi->uValidateHomingEndstopsBox, "VALIDATE_HOMING_ENDSTOPS");
    ReplaceTag(pOutput, "#{SKEW_CORRECTION}", mUi->uSkewCorrectionBox, "SKEW_CORRECTION");
    ReplaceTag(pOutput, "#{XY_DIAG_AC}", mUi->uXyDiagAcSpinBox, false, "XY_DIAG_AC", 6);
    ReplaceTag(pOutput, "#{XY_DIAG_BD}", mUi->uXyDiagBdSpinBox, false, "XY_DIAG_BD", 6);
    ReplaceTag(pOutput, "#{XY_SIDE_AD}", mUi->uXySideAdSpinBox, false, "XY_SIDE_AD", 6);
    ReplaceTag(pOutput, "#{XY_SKEW_FACTOR}", mUi->uXySkewFactorSpinBox, !mUi->uXySkewFactorBox->isChecked(), "XY_SKEW_FACTOR");
    ReplaceTag(pOutput, "#{SKEW_CORRECTION_FOR_Z}", mUi->uSkewCorrectionForZBox, "SKEW_CORRECTION_FOR_Z");
    ReplaceTag(pOutput, "#{XZ_DIAG_AC}", mUi->uXzDiagAcSpinBox, false, "XZ_DIAG_AC", 6);
    ReplaceTag(pOutput, "#{XZ_DIAG_BD}", mUi->uXzDiagBdSpinBox, false, "XZ_DIAG_BD", 6);
    ReplaceTag(pOutput, "#{YZ_DIAG_AC}", mUi->uYzDiagAcSpinBox, false, "YZ_DIAG_AC", 6);
    ReplaceTag(pOutput, "#{YZ_DIAG_BD}", mUi->uYzDiagBdSpinBox, false, "YZ_DIAG_BD", 6);
    ReplaceTag(pOutput, "#{YZ_SIDE_AD}", mUi->uYzSideAdSpinBox, false, "YZ_SIDE_AD", 6);
    ReplaceTag(pOutput, "#{XZ_SKEW_FACTOR}", mUi->uXzSkewFactorSpinBox, !mUi->uXzSkewFactorBox->isChecked(), "XZ_SKEW_FACTOR");
    ReplaceTag(pOutput, "#{YZ_SKEW_FACTOR}", mUi->uYzSkewFactorSpinBox, !mUi->uYzSkewFactorBox->isChecked(), "YZ_SKEW_FACTOR");
    ReplaceTag(pOutput, "#{SKEW_CORRECTION_GCODE}", mUi->uSkewCorrectionGcodeBox, "SKEW_CORRECTION_GCODE");
}
