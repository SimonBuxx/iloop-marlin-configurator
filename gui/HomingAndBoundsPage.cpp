/*!
 * \file HomingAndBoundsPage.cpp
/// \brief The HomingAndBoundsPage class represents the homing and bounds page
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

#include "HomingAndBoundsPage.h"
#include "./ui_HomingAndBoundsPage.h"
#include "HelperFunctions.h"

HomingAndBoundsPage::HomingAndBoundsPage(QWidget *pParent) :
    AbstractPage(HOMING_AND_BOUNDS_TEMPLATE_PATH, pParent),
    mUi(new Ui::HomingAndBoundsPage)
{
    mUi->setupUi(this);
}

HomingAndBoundsPage::~HomingAndBoundsPage()
{
    delete mUi;
}

void HomingAndBoundsPage::ConnectGuiSignalsAndSlots()
{
    QObject::connect(mUi->uDocumentationButton, &QPushButton::clicked, this, [&]()
    {
        OpenMarlinDocumentation("homing-and-bounds");
    });

    QObject::connect(mUi->uMinSoftwareEndstopsBox, &QGroupBox::toggled, this, [&](auto pChecked){
        mUi->uSoftEndstopsMenuItemBox->setEnabled(pChecked || mUi->uMaxSoftwareEndstopsBox->isChecked());
    });

    QObject::connect(mUi->uMaxSoftwareEndstopsBox, &QGroupBox::toggled, this, [&](auto pChecked){
        mUi->uSoftEndstopsMenuItemBox->setEnabled(pChecked || mUi->uMinSoftwareEndstopsBox->isChecked());
    });

    AbstractPage::ConnectGuiSignalsAndSlots();
}

void HomingAndBoundsPage::ResetValues()
{
    mIsLoading = true;

    mUi->uNoMotionBeforeHomingBox->setChecked(defaults::NO_MOTION_BEFORE_HOMING);
    mUi->uHomeAfterDeactivateBox->setChecked(defaults::HOME_AFTER_DEACTIVATE);
    mUi->uZIdleHeightSpinBox->setValue(defaults::Z_IDLE_HEIGHT);
    mUi->uZHomingHeightSpinBox->setValue(defaults::Z_HOMING_HEIGHT);
    mUi->uZAfterHomingSpinBox->setValue(defaults::Z_AFTER_HOMING);
    mUi->uZIdleHeightBox->setChecked(defaults::ENABLE_Z_IDLE_HEIGHT);
    mUi->uZHomingHeightBox->setChecked(defaults::ENABLE_Z_HOMING_HEIGHT);
    mUi->uZAfterHomingBox->setChecked(defaults::ENABLE_Z_AFTER_HOMING);
    mUi->uXHomeDirDropdown->setCurrentText(defaults::X_HOME_DIR);
    mUi->uYHomeDirDropdown->setCurrentText(defaults::Y_HOME_DIR);
    mUi->uZHomeDirDropdown->setCurrentText(defaults::Z_HOME_DIR);
    mUi->uIHomeDirDropdown->setCurrentText(defaults::I_HOME_DIR);
    mUi->uJHomeDirDropdown->setCurrentText(defaults::J_HOME_DIR);
    mUi->uKHomeDirDropdown->setCurrentText(defaults::K_HOME_DIR);
    mUi->uUHomeDirDropdown->setCurrentText(defaults::U_HOME_DIR);
    mUi->uVHomeDirDropdown->setCurrentText(defaults::V_HOME_DIR);
    mUi->uWHomeDirDropdown->setCurrentText(defaults::W_HOME_DIR);
    mUi->uXHomeDirBox->setChecked(defaults::ENABLE_X_HOME_DIR);
    mUi->uYHomeDirBox->setChecked(defaults::ENABLE_Y_HOME_DIR);
    mUi->uZHomeDirBox->setChecked(defaults::ENABLE_Z_HOME_DIR);
    mUi->uIHomeDirBox->setChecked(defaults::ENABLE_I_HOME_DIR);
    mUi->uJHomeDirBox->setChecked(defaults::ENABLE_J_HOME_DIR);
    mUi->uKHomeDirBox->setChecked(defaults::ENABLE_K_HOME_DIR);
    mUi->uUHomeDirBox->setChecked(defaults::ENABLE_U_HOME_DIR);
    mUi->uVHomeDirBox->setChecked(defaults::ENABLE_V_HOME_DIR);
    mUi->uWHomeDirBox->setChecked(defaults::ENABLE_W_HOME_DIR);
    mUi->uXBedSizeSpinBox->setValue(defaults::X_BED_SIZE);
    mUi->uYBedSizeSpinBox->setValue(defaults::Y_BED_SIZE);
    mUi->uXMinPosSpinBox->setValue(defaults::X_MIN_POS);
    mUi->uYMinPosSpinBox->setValue(defaults::Y_MIN_POS);
    mUi->uZMinPosSpinBox->setValue(defaults::Z_MIN_POS);
    mUi->uXMaxPosSpinBox->setValue(defaults::X_MAX_POS);
    mUi->uYMaxPosSpinBox->setValue(defaults::Y_MAX_POS);
    mUi->uZMaxPosSpinBox->setValue(defaults::Z_MAX_POS);
    mUi->uXMinPosBox->setChecked(defaults::ENABLE_X_MIN_POS);
    mUi->uYMinPosBox->setChecked(defaults::ENABLE_Y_MIN_POS);
    mUi->uZMinPosBox->setChecked(defaults::ENABLE_Z_MIN_POS);
    mUi->uXMaxPosBox->setChecked(defaults::ENABLE_X_MAX_POS);
    mUi->uYMaxPosBox->setChecked(defaults::ENABLE_Y_MAX_POS);
    mUi->uZMaxPosBox->setChecked(defaults::ENABLE_Z_MAX_POS);
    mUi->uIMinPosSpinBox->setValue(defaults::I_MIN_POS);
    mUi->uJMinPosSpinBox->setValue(defaults::J_MIN_POS);
    mUi->uKMinPosSpinBox->setValue(defaults::K_MIN_POS);
    mUi->uIMaxPosSpinBox->setValue(defaults::I_MAX_POS);
    mUi->uJMaxPosSpinBox->setValue(defaults::J_MAX_POS);
    mUi->uKMaxPosSpinBox->setValue(defaults::K_MAX_POS);
    mUi->uIMinPosBox->setChecked(defaults::ENABLE_I_MIN_POS);
    mUi->uJMinPosBox->setChecked(defaults::ENABLE_J_MIN_POS);
    mUi->uKMinPosBox->setChecked(defaults::ENABLE_K_MIN_POS);
    mUi->uIMaxPosBox->setChecked(defaults::ENABLE_I_MAX_POS);
    mUi->uJMaxPosBox->setChecked(defaults::ENABLE_J_MAX_POS);
    mUi->uKMaxPosBox->setChecked(defaults::ENABLE_K_MAX_POS);
    mUi->uUMinPosSpinBox->setValue(defaults::U_MIN_POS);
    mUi->uVMinPosSpinBox->setValue(defaults::V_MIN_POS);
    mUi->uWMinPosSpinBox->setValue(defaults::W_MIN_POS);
    mUi->uUMaxPosSpinBox->setValue(defaults::U_MAX_POS);
    mUi->uVMaxPosSpinBox->setValue(defaults::V_MAX_POS);
    mUi->uWMaxPosSpinBox->setValue(defaults::W_MAX_POS);
    mUi->uUMinPosBox->setChecked(defaults::ENABLE_U_MIN_POS);
    mUi->uVMinPosBox->setChecked(defaults::ENABLE_V_MIN_POS);
    mUi->uWMinPosBox->setChecked(defaults::ENABLE_W_MIN_POS);
    mUi->uUMaxPosBox->setChecked(defaults::ENABLE_U_MAX_POS);
    mUi->uVMaxPosBox->setChecked(defaults::ENABLE_V_MAX_POS);
    mUi->uWMaxPosBox->setChecked(defaults::ENABLE_W_MAX_POS);
    mUi->uMinSoftwareEndstopsBox->setChecked(defaults::MIN_SOFTWARE_ENDSTOPS);
    mUi->uMinSoftwareEndstopXBox->setChecked(defaults::MIN_SOFTWARE_ENDSTOP_X);
    mUi->uMinSoftwareEndstopYBox->setChecked(defaults::MIN_SOFTWARE_ENDSTOP_Y);
    mUi->uMinSoftwareEndstopZBox->setChecked(defaults::MIN_SOFTWARE_ENDSTOP_Z);
    mUi->uMinSoftwareEndstopIBox->setChecked(defaults::MIN_SOFTWARE_ENDSTOP_I);
    mUi->uMinSoftwareEndstopJBox->setChecked(defaults::MIN_SOFTWARE_ENDSTOP_J);
    mUi->uMinSoftwareEndstopKBox->setChecked(defaults::MIN_SOFTWARE_ENDSTOP_K);
    mUi->uMinSoftwareEndstopUBox->setChecked(defaults::MIN_SOFTWARE_ENDSTOP_U);
    mUi->uMinSoftwareEndstopVBox->setChecked(defaults::MIN_SOFTWARE_ENDSTOP_V);
    mUi->uMinSoftwareEndstopWBox->setChecked(defaults::MIN_SOFTWARE_ENDSTOP_W);
    mUi->uMaxSoftwareEndstopsBox->setChecked(defaults::MAX_SOFTWARE_ENDSTOPS);
    mUi->uMaxSoftwareEndstopXBox->setChecked(defaults::MAX_SOFTWARE_ENDSTOP_X);
    mUi->uMaxSoftwareEndstopYBox->setChecked(defaults::MAX_SOFTWARE_ENDSTOP_Y);
    mUi->uMaxSoftwareEndstopZBox->setChecked(defaults::MAX_SOFTWARE_ENDSTOP_Z);
    mUi->uMaxSoftwareEndstopIBox->setChecked(defaults::MAX_SOFTWARE_ENDSTOP_I);
    mUi->uMaxSoftwareEndstopJBox->setChecked(defaults::MAX_SOFTWARE_ENDSTOP_J);
    mUi->uMaxSoftwareEndstopKBox->setChecked(defaults::MAX_SOFTWARE_ENDSTOP_K);
    mUi->uMaxSoftwareEndstopUBox->setChecked(defaults::MAX_SOFTWARE_ENDSTOP_U);
    mUi->uMaxSoftwareEndstopVBox->setChecked(defaults::MAX_SOFTWARE_ENDSTOP_V);
    mUi->uMaxSoftwareEndstopWBox->setChecked(defaults::MAX_SOFTWARE_ENDSTOP_W);
    mUi->uSoftEndstopsMenuItemBox->setChecked(defaults::SOFT_ENDSTOPS_MENU_ITEM);

    mUi->uHomeDirectionsTabWidget->setCurrentIndex(0);
    mUi->uTravelLimitsTabWidget->setCurrentIndex(0);
    mUi->uMinSoftwareEndstopsTabWidget->setCurrentIndex(0);
    mUi->uMaxSoftwareEndstopsTabWidget->setCurrentIndex(0);

    mIsLoading = false;
}

bool HomingAndBoundsPage::LoadFromJson(const QJsonObject &pJson)
{
    bool success = true;
    mIsLoading = true;

    success &= LoadConfig(mUi->uNoMotionBeforeHomingBox, pJson, "NO_MOTION_BEFORE_HOMING");
    success &= LoadConfig(mUi->uHomeAfterDeactivateBox, pJson, "HOME_AFTER_DEACTIVATE");
    success &= LoadConfig(mUi->uZIdleHeightSpinBox, pJson, "Z_IDLE_HEIGHT");
    success &= LoadConfig(mUi->uZHomingHeightSpinBox, pJson, "Z_HOMING_HEIGHT");
    success &= LoadConfig(mUi->uZAfterHomingSpinBox, pJson, "Z_AFTER_HOMING");
    success &= LoadConfig(mUi->uZIdleHeightBox, pJson, "ENABLE_Z_IDLE_HEIGHT");
    success &= LoadConfig(mUi->uZHomingHeightBox, pJson, "ENABLE_Z_HOMING_HEIGHT");
    success &= LoadConfig(mUi->uZAfterHomingBox, pJson, "ENABLE_Z_AFTER_HOMING");
    success &= LoadConfig(mUi->uXHomeDirDropdown, pJson, "X_HOME_DIR");
    success &= LoadConfig(mUi->uYHomeDirDropdown, pJson, "Y_HOME_DIR");
    success &= LoadConfig(mUi->uZHomeDirDropdown, pJson, "Z_HOME_DIR");
    success &= LoadConfig(mUi->uIHomeDirDropdown, pJson, "I_HOME_DIR");
    success &= LoadConfig(mUi->uJHomeDirDropdown, pJson, "J_HOME_DIR");
    success &= LoadConfig(mUi->uKHomeDirDropdown, pJson, "K_HOME_DIR");
    success &= LoadConfig(mUi->uUHomeDirDropdown, pJson, "U_HOME_DIR");
    success &= LoadConfig(mUi->uVHomeDirDropdown, pJson, "V_HOME_DIR");
    success &= LoadConfig(mUi->uWHomeDirDropdown, pJson, "W_HOME_DIR");
    success &= LoadConfig(mUi->uXHomeDirBox, pJson, "ENABLE_X_HOME_DIR");
    success &= LoadConfig(mUi->uYHomeDirBox, pJson, "ENABLE_Y_HOME_DIR");
    success &= LoadConfig(mUi->uZHomeDirBox, pJson, "ENABLE_Z_HOME_DIR");
    success &= LoadConfig(mUi->uIHomeDirBox, pJson, "ENABLE_I_HOME_DIR");
    success &= LoadConfig(mUi->uJHomeDirBox, pJson, "ENABLE_J_HOME_DIR");
    success &= LoadConfig(mUi->uKHomeDirBox, pJson, "ENABLE_K_HOME_DIR");
    success &= LoadConfig(mUi->uUHomeDirBox, pJson, "ENABLE_U_HOME_DIR");
    success &= LoadConfig(mUi->uVHomeDirBox, pJson, "ENABLE_V_HOME_DIR");
    success &= LoadConfig(mUi->uWHomeDirBox, pJson, "ENABLE_W_HOME_DIR");
    success &= LoadConfig(mUi->uXBedSizeSpinBox, pJson, "X_BED_SIZE");
    success &= LoadConfig(mUi->uYBedSizeSpinBox, pJson, "Y_BED_SIZE");
    success &= LoadConfig(mUi->uXMinPosSpinBox, pJson, "X_MIN_POS");
    success &= LoadConfig(mUi->uYMinPosSpinBox, pJson, "Y_MIN_POS");
    success &= LoadConfig(mUi->uZMinPosSpinBox, pJson, "Z_MIN_POS");
    success &= LoadConfig(mUi->uXMaxPosSpinBox, pJson, "X_MAX_POS");
    success &= LoadConfig(mUi->uYMaxPosSpinBox, pJson, "Y_MAX_POS");
    success &= LoadConfig(mUi->uZMaxPosSpinBox, pJson, "Z_MAX_POS");
    success &= LoadConfig(mUi->uXMinPosBox, pJson, "ENABLE_X_MIN_POS");
    success &= LoadConfig(mUi->uYMinPosBox, pJson, "ENABLE_Y_MIN_POS");
    success &= LoadConfig(mUi->uZMinPosBox, pJson, "ENABLE_Z_MIN_POS");
    success &= LoadConfig(mUi->uXMaxPosBox, pJson, "ENABLE_X_MAX_POS");
    success &= LoadConfig(mUi->uYMaxPosBox, pJson, "ENABLE_Y_MAX_POS");
    success &= LoadConfig(mUi->uZMaxPosBox, pJson, "ENABLE_Z_MAX_POS");
    success &= LoadConfig(mUi->uIMinPosSpinBox, pJson, "I_MIN_POS");
    success &= LoadConfig(mUi->uJMinPosSpinBox, pJson, "J_MIN_POS");
    success &= LoadConfig(mUi->uKMinPosSpinBox, pJson, "K_MIN_POS");
    success &= LoadConfig(mUi->uIMaxPosSpinBox, pJson, "I_MAX_POS");
    success &= LoadConfig(mUi->uJMaxPosSpinBox, pJson, "J_MAX_POS");
    success &= LoadConfig(mUi->uKMaxPosSpinBox, pJson, "K_MAX_POS");
    success &= LoadConfig(mUi->uIMinPosBox, pJson, "ENABLE_I_MIN_POS");
    success &= LoadConfig(mUi->uJMinPosBox, pJson, "ENABLE_J_MIN_POS");
    success &= LoadConfig(mUi->uKMinPosBox, pJson, "ENABLE_K_MIN_POS");
    success &= LoadConfig(mUi->uIMaxPosBox, pJson, "ENABLE_I_MAX_POS");
    success &= LoadConfig(mUi->uJMaxPosBox, pJson, "ENABLE_J_MAX_POS");
    success &= LoadConfig(mUi->uKMaxPosBox, pJson, "ENABLE_K_MAX_POS");
    success &= LoadConfig(mUi->uUMinPosSpinBox, pJson, "U_MIN_POS");
    success &= LoadConfig(mUi->uVMinPosSpinBox, pJson, "V_MIN_POS");
    success &= LoadConfig(mUi->uWMinPosSpinBox, pJson, "W_MIN_POS");
    success &= LoadConfig(mUi->uUMaxPosSpinBox, pJson, "U_MAX_POS");
    success &= LoadConfig(mUi->uVMaxPosSpinBox, pJson, "V_MAX_POS");
    success &= LoadConfig(mUi->uWMaxPosSpinBox, pJson, "W_MAX_POS");
    success &= LoadConfig(mUi->uUMinPosBox, pJson, "ENABLE_U_MIN_POS");
    success &= LoadConfig(mUi->uVMinPosBox, pJson, "ENABLE_V_MIN_POS");
    success &= LoadConfig(mUi->uWMinPosBox, pJson, "ENABLE_W_MIN_POS");
    success &= LoadConfig(mUi->uUMaxPosBox, pJson, "ENABLE_U_MAX_POS");
    success &= LoadConfig(mUi->uVMaxPosBox, pJson, "ENABLE_V_MAX_POS");
    success &= LoadConfig(mUi->uWMaxPosBox, pJson, "ENABLE_W_MAX_POS");
    success &= LoadConfig(mUi->uMinSoftwareEndstopsBox, pJson, "MIN_SOFTWARE_ENDSTOPS");
    success &= LoadConfig(mUi->uMinSoftwareEndstopXBox, pJson, "MIN_SOFTWARE_ENDSTOP_X");
    success &= LoadConfig(mUi->uMinSoftwareEndstopYBox, pJson, "MIN_SOFTWARE_ENDSTOP_Y");
    success &= LoadConfig(mUi->uMinSoftwareEndstopZBox, pJson, "MIN_SOFTWARE_ENDSTOP_Z");
    success &= LoadConfig(mUi->uMinSoftwareEndstopIBox, pJson, "MIN_SOFTWARE_ENDSTOP_I");
    success &= LoadConfig(mUi->uMinSoftwareEndstopJBox, pJson, "MIN_SOFTWARE_ENDSTOP_J");
    success &= LoadConfig(mUi->uMinSoftwareEndstopKBox, pJson, "MIN_SOFTWARE_ENDSTOP_K");
    success &= LoadConfig(mUi->uMinSoftwareEndstopUBox, pJson, "MIN_SOFTWARE_ENDSTOP_U");
    success &= LoadConfig(mUi->uMinSoftwareEndstopVBox, pJson, "MIN_SOFTWARE_ENDSTOP_V");
    success &= LoadConfig(mUi->uMinSoftwareEndstopWBox, pJson, "MIN_SOFTWARE_ENDSTOP_W");
    success &= LoadConfig(mUi->uMaxSoftwareEndstopsBox, pJson, "MAX_SOFTWARE_ENDSTOPS");
    success &= LoadConfig(mUi->uMaxSoftwareEndstopXBox, pJson, "MAX_SOFTWARE_ENDSTOP_X");
    success &= LoadConfig(mUi->uMaxSoftwareEndstopYBox, pJson, "MAX_SOFTWARE_ENDSTOP_Y");
    success &= LoadConfig(mUi->uMaxSoftwareEndstopZBox, pJson, "MAX_SOFTWARE_ENDSTOP_Z");
    success &= LoadConfig(mUi->uMaxSoftwareEndstopIBox, pJson, "MAX_SOFTWARE_ENDSTOP_I");
    success &= LoadConfig(mUi->uMaxSoftwareEndstopJBox, pJson, "MAX_SOFTWARE_ENDSTOP_J");
    success &= LoadConfig(mUi->uMaxSoftwareEndstopKBox, pJson, "MAX_SOFTWARE_ENDSTOP_K");
    success &= LoadConfig(mUi->uMaxSoftwareEndstopUBox, pJson, "MAX_SOFTWARE_ENDSTOP_U");
    success &= LoadConfig(mUi->uMaxSoftwareEndstopVBox, pJson, "MAX_SOFTWARE_ENDSTOP_V");
    success &= LoadConfig(mUi->uMaxSoftwareEndstopWBox, pJson, "MAX_SOFTWARE_ENDSTOP_W");
    success &= LoadConfig(mUi->uSoftEndstopsMenuItemBox, pJson, "SOFT_ENDSTOPS_MENU_ITEM");

    mIsLoading = false;
    return success;
}

void HomingAndBoundsPage::FetchConfiguration(Configuration& pConfig)
{
    SetConfig(pConfig.homingAndBounds.NO_MOTION_BEFORE_HOMING, mUi->uNoMotionBeforeHomingBox);
    SetConfig(pConfig.homingAndBounds.HOME_AFTER_DEACTIVATE, mUi->uHomeAfterDeactivateBox);
    SetConfig(pConfig.homingAndBounds.Z_IDLE_HEIGHT, mUi->uZIdleHeightSpinBox);
    SetConfig(pConfig.homingAndBounds.Z_HOMING_HEIGHT, mUi->uZHomingHeightSpinBox);
    SetConfig(pConfig.homingAndBounds.Z_AFTER_HOMING, mUi->uZAfterHomingSpinBox);
    SetConfig(pConfig.homingAndBounds.ENABLE_Z_IDLE_HEIGHT, mUi->uZIdleHeightBox);
    SetConfig(pConfig.homingAndBounds.ENABLE_Z_HOMING_HEIGHT, mUi->uZHomingHeightBox);
    SetConfig(pConfig.homingAndBounds.ENABLE_Z_AFTER_HOMING, mUi->uZAfterHomingBox);
    SetConfig(pConfig.homingAndBounds.X_HOME_DIR, mUi->uXHomeDirDropdown);
    SetConfig(pConfig.homingAndBounds.Y_HOME_DIR, mUi->uYHomeDirDropdown);
    SetConfig(pConfig.homingAndBounds.Z_HOME_DIR, mUi->uZHomeDirDropdown);
    SetConfig(pConfig.homingAndBounds.I_HOME_DIR, mUi->uIHomeDirDropdown);
    SetConfig(pConfig.homingAndBounds.J_HOME_DIR, mUi->uJHomeDirDropdown);
    SetConfig(pConfig.homingAndBounds.K_HOME_DIR, mUi->uKHomeDirDropdown);
    SetConfig(pConfig.homingAndBounds.U_HOME_DIR, mUi->uUHomeDirDropdown);
    SetConfig(pConfig.homingAndBounds.V_HOME_DIR, mUi->uVHomeDirDropdown);
    SetConfig(pConfig.homingAndBounds.W_HOME_DIR, mUi->uWHomeDirDropdown);
    SetConfig(pConfig.homingAndBounds.ENABLE_X_HOME_DIR, mUi->uXHomeDirBox);
    SetConfig(pConfig.homingAndBounds.ENABLE_Y_HOME_DIR, mUi->uYHomeDirBox);
    SetConfig(pConfig.homingAndBounds.ENABLE_Z_HOME_DIR, mUi->uZHomeDirBox);
    SetConfig(pConfig.homingAndBounds.ENABLE_I_HOME_DIR, mUi->uIHomeDirBox);
    SetConfig(pConfig.homingAndBounds.ENABLE_J_HOME_DIR, mUi->uJHomeDirBox);
    SetConfig(pConfig.homingAndBounds.ENABLE_K_HOME_DIR, mUi->uKHomeDirBox);
    SetConfig(pConfig.homingAndBounds.ENABLE_U_HOME_DIR, mUi->uUHomeDirBox);
    SetConfig(pConfig.homingAndBounds.ENABLE_V_HOME_DIR, mUi->uVHomeDirBox);
    SetConfig(pConfig.homingAndBounds.ENABLE_W_HOME_DIR, mUi->uWHomeDirBox);
    SetConfig(pConfig.homingAndBounds.X_BED_SIZE, mUi->uXBedSizeSpinBox);
    SetConfig(pConfig.homingAndBounds.Y_BED_SIZE, mUi->uYBedSizeSpinBox);
    SetConfig(pConfig.homingAndBounds.X_MIN_POS, mUi->uXMinPosSpinBox);
    SetConfig(pConfig.homingAndBounds.Y_MIN_POS, mUi->uYMinPosSpinBox);
    SetConfig(pConfig.homingAndBounds.Z_MIN_POS, mUi->uZMinPosSpinBox);
    SetConfig(pConfig.homingAndBounds.X_MAX_POS, mUi->uXMaxPosSpinBox);
    SetConfig(pConfig.homingAndBounds.Y_MAX_POS, mUi->uYMaxPosSpinBox);
    SetConfig(pConfig.homingAndBounds.Z_MAX_POS, mUi->uZMaxPosSpinBox);
    SetConfig(pConfig.homingAndBounds.ENABLE_X_MIN_POS, mUi->uXMinPosBox);
    SetConfig(pConfig.homingAndBounds.ENABLE_Y_MIN_POS, mUi->uYMinPosBox);
    SetConfig(pConfig.homingAndBounds.ENABLE_Z_MIN_POS, mUi->uZMinPosBox);
    SetConfig(pConfig.homingAndBounds.ENABLE_X_MAX_POS, mUi->uXMaxPosBox);
    SetConfig(pConfig.homingAndBounds.ENABLE_Y_MAX_POS, mUi->uYMaxPosBox);
    SetConfig(pConfig.homingAndBounds.ENABLE_Z_MAX_POS, mUi->uZMaxPosBox);
    SetConfig(pConfig.homingAndBounds.I_MIN_POS, mUi->uIMinPosSpinBox);
    SetConfig(pConfig.homingAndBounds.J_MIN_POS, mUi->uJMinPosSpinBox);
    SetConfig(pConfig.homingAndBounds.K_MIN_POS, mUi->uKMinPosSpinBox);
    SetConfig(pConfig.homingAndBounds.I_MAX_POS, mUi->uIMaxPosSpinBox);
    SetConfig(pConfig.homingAndBounds.J_MAX_POS, mUi->uJMaxPosSpinBox);
    SetConfig(pConfig.homingAndBounds.K_MAX_POS, mUi->uKMaxPosSpinBox);
    SetConfig(pConfig.homingAndBounds.ENABLE_I_MIN_POS, mUi->uIMinPosBox);
    SetConfig(pConfig.homingAndBounds.ENABLE_J_MIN_POS, mUi->uJMinPosBox);
    SetConfig(pConfig.homingAndBounds.ENABLE_K_MIN_POS, mUi->uKMinPosBox);
    SetConfig(pConfig.homingAndBounds.ENABLE_I_MAX_POS, mUi->uIMaxPosBox);
    SetConfig(pConfig.homingAndBounds.ENABLE_J_MAX_POS, mUi->uJMaxPosBox);
    SetConfig(pConfig.homingAndBounds.ENABLE_K_MAX_POS, mUi->uKMaxPosBox);
    SetConfig(pConfig.homingAndBounds.U_MIN_POS, mUi->uUMinPosSpinBox);
    SetConfig(pConfig.homingAndBounds.V_MIN_POS, mUi->uVMinPosSpinBox);
    SetConfig(pConfig.homingAndBounds.W_MIN_POS, mUi->uWMinPosSpinBox);
    SetConfig(pConfig.homingAndBounds.U_MAX_POS, mUi->uUMaxPosSpinBox);
    SetConfig(pConfig.homingAndBounds.V_MAX_POS, mUi->uVMaxPosSpinBox);
    SetConfig(pConfig.homingAndBounds.W_MAX_POS, mUi->uWMaxPosSpinBox);
    SetConfig(pConfig.homingAndBounds.ENABLE_U_MIN_POS, mUi->uUMinPosBox);
    SetConfig(pConfig.homingAndBounds.ENABLE_V_MIN_POS, mUi->uVMinPosBox);
    SetConfig(pConfig.homingAndBounds.ENABLE_W_MIN_POS, mUi->uWMinPosBox);
    SetConfig(pConfig.homingAndBounds.ENABLE_U_MAX_POS, mUi->uUMaxPosBox);
    SetConfig(pConfig.homingAndBounds.ENABLE_V_MAX_POS, mUi->uVMaxPosBox);
    SetConfig(pConfig.homingAndBounds.ENABLE_W_MAX_POS, mUi->uWMaxPosBox);
    SetConfig(pConfig.homingAndBounds.MIN_SOFTWARE_ENDSTOPS, mUi->uMinSoftwareEndstopsBox);
    SetConfig(pConfig.homingAndBounds.MIN_SOFTWARE_ENDSTOP_X, mUi->uMinSoftwareEndstopXBox);
    SetConfig(pConfig.homingAndBounds.MIN_SOFTWARE_ENDSTOP_Y, mUi->uMinSoftwareEndstopYBox);
    SetConfig(pConfig.homingAndBounds.MIN_SOFTWARE_ENDSTOP_Z, mUi->uMinSoftwareEndstopZBox);
    SetConfig(pConfig.homingAndBounds.MIN_SOFTWARE_ENDSTOP_I, mUi->uMinSoftwareEndstopIBox);
    SetConfig(pConfig.homingAndBounds.MIN_SOFTWARE_ENDSTOP_J, mUi->uMinSoftwareEndstopJBox);
    SetConfig(pConfig.homingAndBounds.MIN_SOFTWARE_ENDSTOP_K, mUi->uMinSoftwareEndstopKBox);
    SetConfig(pConfig.homingAndBounds.MIN_SOFTWARE_ENDSTOP_U, mUi->uMinSoftwareEndstopUBox);
    SetConfig(pConfig.homingAndBounds.MIN_SOFTWARE_ENDSTOP_V, mUi->uMinSoftwareEndstopVBox);
    SetConfig(pConfig.homingAndBounds.MIN_SOFTWARE_ENDSTOP_W, mUi->uMinSoftwareEndstopWBox);
    SetConfig(pConfig.homingAndBounds.MAX_SOFTWARE_ENDSTOPS, mUi->uMaxSoftwareEndstopsBox);
    SetConfig(pConfig.homingAndBounds.MAX_SOFTWARE_ENDSTOP_X, mUi->uMaxSoftwareEndstopXBox);
    SetConfig(pConfig.homingAndBounds.MAX_SOFTWARE_ENDSTOP_Y, mUi->uMaxSoftwareEndstopYBox);
    SetConfig(pConfig.homingAndBounds.MAX_SOFTWARE_ENDSTOP_Z, mUi->uMaxSoftwareEndstopZBox);
    SetConfig(pConfig.homingAndBounds.MAX_SOFTWARE_ENDSTOP_I, mUi->uMaxSoftwareEndstopIBox);
    SetConfig(pConfig.homingAndBounds.MAX_SOFTWARE_ENDSTOP_J, mUi->uMaxSoftwareEndstopJBox);
    SetConfig(pConfig.homingAndBounds.MAX_SOFTWARE_ENDSTOP_K, mUi->uMaxSoftwareEndstopKBox);
    SetConfig(pConfig.homingAndBounds.MAX_SOFTWARE_ENDSTOP_U, mUi->uMaxSoftwareEndstopUBox);
    SetConfig(pConfig.homingAndBounds.MAX_SOFTWARE_ENDSTOP_V, mUi->uMaxSoftwareEndstopVBox);
    SetConfig(pConfig.homingAndBounds.MAX_SOFTWARE_ENDSTOP_W, mUi->uMaxSoftwareEndstopWBox);
    SetConfig(pConfig.homingAndBounds.SOFT_ENDSTOPS_MENU_ITEM, mUi->uSoftEndstopsMenuItemBox);
}

void HomingAndBoundsPage::ReplaceTags(QStringList& pOutput)
{
    ReplaceTag(pOutput, "#{NO_MOTION_BEFORE_HOMING}", mUi->uNoMotionBeforeHomingBox, "NO_MOTION_BEFORE_HOMING");
    ReplaceTag(pOutput, "#{HOME_AFTER_DEACTIVATE}", mUi->uHomeAfterDeactivateBox, "HOME_AFTER_DEACTIVATE");
    ReplaceTag(pOutput, "#{Z_IDLE_HEIGHT}", mUi->uZIdleHeightSpinBox, !mUi->uZIdleHeightBox->isChecked(), "Z_IDLE_HEIGHT");
    ReplaceTag(pOutput, "#{Z_HOMING_HEIGHT}", mUi->uZHomingHeightSpinBox, !mUi->uZHomingHeightBox->isChecked(), "Z_HOMING_HEIGHT");
    ReplaceTag(pOutput, "#{Z_AFTER_HOMING}", mUi->uZAfterHomingSpinBox, !mUi->uZAfterHomingBox->isChecked(), "Z_AFTER_HOMING");
    ReplaceTag(pOutput, "#{X_HOME_DIR}", mUi->uXHomeDirDropdown, !mUi->uXHomeDirBox->isChecked(), "X_HOME_DIR", true);
    ReplaceTag(pOutput, "#{Y_HOME_DIR}", mUi->uYHomeDirDropdown, !mUi->uYHomeDirBox->isChecked(), "Y_HOME_DIR", true);
    ReplaceTag(pOutput, "#{Z_HOME_DIR}", mUi->uZHomeDirDropdown, !mUi->uZHomeDirBox->isChecked(), "Z_HOME_DIR", true);
    ReplaceTag(pOutput, "#{I_HOME_DIR}", mUi->uIHomeDirDropdown, !mUi->uIHomeDirBox->isChecked(), "I_HOME_DIR", true);
    ReplaceTag(pOutput, "#{J_HOME_DIR}", mUi->uJHomeDirDropdown, !mUi->uJHomeDirBox->isChecked(), "J_HOME_DIR", true);
    ReplaceTag(pOutput, "#{K_HOME_DIR}", mUi->uKHomeDirDropdown, !mUi->uKHomeDirBox->isChecked(), "K_HOME_DIR", true);
    ReplaceTag(pOutput, "#{U_HOME_DIR}", mUi->uUHomeDirDropdown, !mUi->uUHomeDirBox->isChecked(), "U_HOME_DIR", true);
    ReplaceTag(pOutput, "#{V_HOME_DIR}", mUi->uVHomeDirDropdown, !mUi->uVHomeDirBox->isChecked(), "V_HOME_DIR", true);
    ReplaceTag(pOutput, "#{W_HOME_DIR}", mUi->uWHomeDirDropdown, !mUi->uWHomeDirBox->isChecked(), "W_HOME_DIR", true);
    ReplaceTag(pOutput, "#{X_BED_SIZE}", mUi->uXBedSizeSpinBox, false, "X_BED_SIZE");
    ReplaceTag(pOutput, "#{Y_BED_SIZE}", mUi->uYBedSizeSpinBox, false, "Y_BED_SIZE");
    ReplaceTag(pOutput, "#{X_MIN_POS}", mUi->uXMinPosSpinBox, !mUi->uXMinPosBox->isChecked(), "X_MIN_POS");
    ReplaceTag(pOutput, "#{Y_MIN_POS}", mUi->uYMinPosSpinBox, !mUi->uYMinPosBox->isChecked(), "Y_MIN_POS");
    ReplaceTag(pOutput, "#{Z_MIN_POS}", mUi->uZMinPosSpinBox, !mUi->uZMinPosBox->isChecked(), "Z_MIN_POS");
    ReplaceTag(pOutput, "#{X_MAX_POS}", mUi->uXMaxPosSpinBox, !mUi->uXMaxPosBox->isChecked(), "X_MAX_POS");
    ReplaceTag(pOutput, "#{Y_MAX_POS}", mUi->uYMaxPosSpinBox, !mUi->uYMaxPosBox->isChecked(), "Y_MAX_POS");
    ReplaceTag(pOutput, "#{Z_MAX_POS}", mUi->uZMaxPosSpinBox, !mUi->uZMaxPosBox->isChecked(), "Z_MAX_POS");
    ReplaceTag(pOutput, "#{I_MIN_POS}", mUi->uIMinPosSpinBox, !mUi->uIMinPosBox->isChecked(), "I_MIN_POS");
    ReplaceTag(pOutput, "#{J_MIN_POS}", mUi->uJMinPosSpinBox, !mUi->uJMinPosBox->isChecked(), "J_MIN_POS");
    ReplaceTag(pOutput, "#{K_MIN_POS}", mUi->uKMinPosSpinBox, !mUi->uKMinPosBox->isChecked(), "K_MIN_POS");
    ReplaceTag(pOutput, "#{I_MAX_POS}", mUi->uIMaxPosSpinBox, !mUi->uIMaxPosBox->isChecked(), "I_MAX_POS");
    ReplaceTag(pOutput, "#{J_MAX_POS}", mUi->uJMaxPosSpinBox, !mUi->uJMaxPosBox->isChecked(), "J_MAX_POS");
    ReplaceTag(pOutput, "#{K_MAX_POS}", mUi->uKMaxPosSpinBox, !mUi->uKMaxPosBox->isChecked(), "K_MAX_POS");
    ReplaceTag(pOutput, "#{U_MIN_POS}", mUi->uUMinPosSpinBox, !mUi->uUMinPosBox->isChecked(), "U_MIN_POS");
    ReplaceTag(pOutput, "#{V_MIN_POS}", mUi->uVMinPosSpinBox, !mUi->uVMinPosBox->isChecked(), "V_MIN_POS");
    ReplaceTag(pOutput, "#{W_MIN_POS}", mUi->uWMinPosSpinBox, !mUi->uWMinPosBox->isChecked(), "W_MIN_POS");
    ReplaceTag(pOutput, "#{U_MAX_POS}", mUi->uUMaxPosSpinBox, !mUi->uUMaxPosBox->isChecked(), "U_MAX_POS");
    ReplaceTag(pOutput, "#{V_MAX_POS}", mUi->uVMaxPosSpinBox, !mUi->uVMaxPosBox->isChecked(), "V_MAX_POS");
    ReplaceTag(pOutput, "#{W_MAX_POS}", mUi->uWMaxPosSpinBox, !mUi->uWMaxPosBox->isChecked(), "W_MAX_POS");
    ReplaceTag(pOutput, "#{MIN_SOFTWARE_ENDSTOPS}", mUi->uMinSoftwareEndstopsBox, "MIN_SOFTWARE_ENDSTOPS");
    ReplaceTag(pOutput, "#{MIN_SOFTWARE_ENDSTOP_X}", mUi->uMinSoftwareEndstopXBox, "MIN_SOFTWARE_ENDSTOP_X");
    ReplaceTag(pOutput, "#{MIN_SOFTWARE_ENDSTOP_Y}", mUi->uMinSoftwareEndstopYBox, "MIN_SOFTWARE_ENDSTOP_Y");
    ReplaceTag(pOutput, "#{MIN_SOFTWARE_ENDSTOP_Z}", mUi->uMinSoftwareEndstopZBox, "MIN_SOFTWARE_ENDSTOP_Z");
    ReplaceTag(pOutput, "#{MIN_SOFTWARE_ENDSTOP_I}", mUi->uMinSoftwareEndstopIBox, "MIN_SOFTWARE_ENDSTOP_I");
    ReplaceTag(pOutput, "#{MIN_SOFTWARE_ENDSTOP_J}", mUi->uMinSoftwareEndstopJBox, "MIN_SOFTWARE_ENDSTOP_J");
    ReplaceTag(pOutput, "#{MIN_SOFTWARE_ENDSTOP_K}", mUi->uMinSoftwareEndstopKBox, "MIN_SOFTWARE_ENDSTOP_K");
    ReplaceTag(pOutput, "#{MIN_SOFTWARE_ENDSTOP_U}", mUi->uMinSoftwareEndstopUBox, "MIN_SOFTWARE_ENDSTOP_U");
    ReplaceTag(pOutput, "#{MIN_SOFTWARE_ENDSTOP_V}", mUi->uMinSoftwareEndstopVBox, "MIN_SOFTWARE_ENDSTOP_V");
    ReplaceTag(pOutput, "#{MIN_SOFTWARE_ENDSTOP_W}", mUi->uMinSoftwareEndstopWBox, "MIN_SOFTWARE_ENDSTOP_W");
    ReplaceTag(pOutput, "#{MAX_SOFTWARE_ENDSTOPS}", mUi->uMaxSoftwareEndstopsBox, "MAX_SOFTWARE_ENDSTOPS");
    ReplaceTag(pOutput, "#{MAX_SOFTWARE_ENDSTOP_X}", mUi->uMaxSoftwareEndstopXBox, "MAX_SOFTWARE_ENDSTOP_X");
    ReplaceTag(pOutput, "#{MAX_SOFTWARE_ENDSTOP_Y}", mUi->uMaxSoftwareEndstopYBox, "MAX_SOFTWARE_ENDSTOP_Y");
    ReplaceTag(pOutput, "#{MAX_SOFTWARE_ENDSTOP_Z}", mUi->uMaxSoftwareEndstopZBox, "MAX_SOFTWARE_ENDSTOP_Z");
    ReplaceTag(pOutput, "#{MAX_SOFTWARE_ENDSTOP_I}", mUi->uMaxSoftwareEndstopIBox, "MAX_SOFTWARE_ENDSTOP_I");
    ReplaceTag(pOutput, "#{MAX_SOFTWARE_ENDSTOP_J}", mUi->uMaxSoftwareEndstopJBox, "MAX_SOFTWARE_ENDSTOP_J");
    ReplaceTag(pOutput, "#{MAX_SOFTWARE_ENDSTOP_K}", mUi->uMaxSoftwareEndstopKBox, "MAX_SOFTWARE_ENDSTOP_K");
    ReplaceTag(pOutput, "#{MAX_SOFTWARE_ENDSTOP_U}", mUi->uMaxSoftwareEndstopUBox, "MAX_SOFTWARE_ENDSTOP_U");
    ReplaceTag(pOutput, "#{MAX_SOFTWARE_ENDSTOP_V}", mUi->uMaxSoftwareEndstopVBox, "MAX_SOFTWARE_ENDSTOP_V");
    ReplaceTag(pOutput, "#{MAX_SOFTWARE_ENDSTOP_W}", mUi->uMaxSoftwareEndstopWBox, "MAX_SOFTWARE_ENDSTOP_W");
    ReplaceTag(pOutput, "#{SOFT_ENDSTOPS_MENU_ITEM}", mUi->uSoftEndstopsMenuItemBox, "SOFT_ENDSTOPS_MENU_ITEM");
}
