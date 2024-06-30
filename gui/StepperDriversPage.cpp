/*!
 * \file StepperDriversPage.cpp
/// \brief The StepperDriversPage class represents the stepper drivers page
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

#include "StepperDriversPage.h"
#include "./ui_StepperDriversPage.h"
#include "HelperFunctions.h"

StepperDriversPage::StepperDriversPage(QWidget *pParent) :
    AbstractPage(STEPPER_DRIVERS_TEMPLATE_PATH, pParent),
    mUi(new Ui::StepperDriversPage)
{
    mUi->setupUi(this);
}

StepperDriversPage::~StepperDriversPage()
{
    delete mUi;
}

void StepperDriversPage::ConnectGuiSignalsAndSlots()
{
    QObject::connect(mUi->uDocumentationButton, &QPushButton::clicked, this, [&]()
    {
        OpenMarlinDocumentation("stepper-drivers");
    });

    AbstractPage::ConnectGuiSignalsAndSlots();
}

void StepperDriversPage::ResetValues()
{
    mIsLoading = true;

    mUi->uXDriverTypeDropdown->setCurrentText(defaults::X_DRIVER_TYPE);
    mUi->uYDriverTypeDropdown->setCurrentText(defaults::Y_DRIVER_TYPE);
    mUi->uZDriverTypeDropdown->setCurrentText(defaults::Z_DRIVER_TYPE);
    mUi->uX2DriverTypeDropdown->setCurrentText(defaults::X2_DRIVER_TYPE);
    mUi->uY2DriverTypeDropdown->setCurrentText(defaults::Y2_DRIVER_TYPE);
    mUi->uZ2DriverTypeDropdown->setCurrentText(defaults::Z2_DRIVER_TYPE);
    mUi->uZ3DriverTypeDropdown->setCurrentText(defaults::Z3_DRIVER_TYPE);
    mUi->uZ4DriverTypeDropdown->setCurrentText(defaults::Z4_DRIVER_TYPE);
    mUi->uXDriverTypeBox->setChecked(defaults::ENABLE_X_DRIVER_TYPE);
    mUi->uYDriverTypeBox->setChecked(defaults::ENABLE_Y_DRIVER_TYPE);
    mUi->uZDriverTypeBox->setChecked(defaults::ENABLE_Z_DRIVER_TYPE);
    mUi->uX2DriverTypeBox->setChecked(defaults::ENABLE_X2_DRIVER_TYPE);
    mUi->uY2DriverTypeBox->setChecked(defaults::ENABLE_Y2_DRIVER_TYPE);
    mUi->uZ2DriverTypeBox->setChecked(defaults::ENABLE_Z2_DRIVER_TYPE);
    mUi->uZ3DriverTypeBox->setChecked(defaults::ENABLE_Z3_DRIVER_TYPE);
    mUi->uZ4DriverTypeBox->setChecked(defaults::ENABLE_Z4_DRIVER_TYPE);
    mUi->uIDriverTypeDropdown->setCurrentText(defaults::I_DRIVER_TYPE);
    mUi->uJDriverTypeDropdown->setCurrentText(defaults::J_DRIVER_TYPE);
    mUi->uKDriverTypeDropdown->setCurrentText(defaults::K_DRIVER_TYPE);
    mUi->uIDriverTypeBox->setChecked(defaults::ENABLE_I_DRIVER_TYPE);
    mUi->uJDriverTypeBox->setChecked(defaults::ENABLE_J_DRIVER_TYPE);
    mUi->uKDriverTypeBox->setChecked(defaults::ENABLE_K_DRIVER_TYPE);
    mUi->uUDriverTypeDropdown->setCurrentText(defaults::U_DRIVER_TYPE);
    mUi->uVDriverTypeDropdown->setCurrentText(defaults::V_DRIVER_TYPE);
    mUi->uWDriverTypeDropdown->setCurrentText(defaults::W_DRIVER_TYPE);
    mUi->uUDriverTypeBox->setChecked(defaults::ENABLE_U_DRIVER_TYPE);
    mUi->uVDriverTypeBox->setChecked(defaults::ENABLE_V_DRIVER_TYPE);
    mUi->uWDriverTypeBox->setChecked(defaults::ENABLE_W_DRIVER_TYPE);
    mUi->uE0DriverTypeDropdown->setCurrentText(defaults::E0_DRIVER_TYPE);
    mUi->uE1DriverTypeDropdown->setCurrentText(defaults::E1_DRIVER_TYPE);
    mUi->uE2DriverTypeDropdown->setCurrentText(defaults::E2_DRIVER_TYPE);
    mUi->uE3DriverTypeDropdown->setCurrentText(defaults::E3_DRIVER_TYPE);
    mUi->uE4DriverTypeDropdown->setCurrentText(defaults::E4_DRIVER_TYPE);
    mUi->uE5DriverTypeDropdown->setCurrentText(defaults::E5_DRIVER_TYPE);
    mUi->uE6DriverTypeDropdown->setCurrentText(defaults::E6_DRIVER_TYPE);
    mUi->uE7DriverTypeDropdown->setCurrentText(defaults::E7_DRIVER_TYPE);
    mUi->uE0DriverTypeBox->setChecked(defaults::ENABLE_E0_DRIVER_TYPE);
    mUi->uE1DriverTypeBox->setChecked(defaults::ENABLE_E1_DRIVER_TYPE);
    mUi->uE2DriverTypeBox->setChecked(defaults::ENABLE_E2_DRIVER_TYPE);
    mUi->uE3DriverTypeBox->setChecked(defaults::ENABLE_E3_DRIVER_TYPE);
    mUi->uE4DriverTypeBox->setChecked(defaults::ENABLE_E4_DRIVER_TYPE);
    mUi->uE5DriverTypeBox->setChecked(defaults::ENABLE_E5_DRIVER_TYPE);
    mUi->uE6DriverTypeBox->setChecked(defaults::ENABLE_E6_DRIVER_TYPE);
    mUi->uE7DriverTypeBox->setChecked(defaults::ENABLE_E7_DRIVER_TYPE);
    mUi->uAxis4NameDropdown->setCurrentText(defaults::AXIS4_NAME);
    mUi->uAxis5NameDropdown->setCurrentText(defaults::AXIS5_NAME);
    mUi->uAxis6NameDropdown->setCurrentText(defaults::AXIS6_NAME);
    mUi->uAxis4RotatesBox->setChecked(defaults::AXIS4_ROTATES);
    mUi->uAxis5RotatesBox->setChecked(defaults::AXIS5_ROTATES);
    mUi->uAxis6RotatesBox->setChecked(defaults::AXIS6_ROTATES);
    mUi->uAxis7NameDropdown->setCurrentText(defaults::AXIS7_NAME);
    mUi->uAxis8NameDropdown->setCurrentText(defaults::AXIS8_NAME);
    mUi->uAxis9NameDropdown->setCurrentText(defaults::AXIS9_NAME);
    mUi->uAxis7RotatesBox->setChecked(defaults::AXIS7_ROTATES);
    mUi->uAxis8RotatesBox->setChecked(defaults::AXIS8_ROTATES);
    mUi->uAxis9RotatesBox->setChecked(defaults::AXIS9_ROTATES);
    mUi->uXEnableOnDropdown->setCurrentText(defaults::X_ENABLE_ON);
    mUi->uYEnableOnDropdown->setCurrentText(defaults::Y_ENABLE_ON);
    mUi->uZEnableOnDropdown->setCurrentText(defaults::Z_ENABLE_ON);
    mUi->uEEnableOnDropdown->setCurrentText(defaults::E_ENABLE_ON);
    mUi->uIEnableOnDropdown->setCurrentText(defaults::I_ENABLE_ON);
    mUi->uJEnableOnDropdown->setCurrentText(defaults::J_ENABLE_ON);
    mUi->uKEnableOnDropdown->setCurrentText(defaults::K_ENABLE_ON);
    mUi->uUEnableOnDropdown->setCurrentText(defaults::U_ENABLE_ON);
    mUi->uVEnableOnDropdown->setCurrentText(defaults::V_ENABLE_ON);
    mUi->uWEnableOnDropdown->setCurrentText(defaults::W_ENABLE_ON);
    mUi->uXEnableOnBox->setChecked(defaults::ENABLE_X_ENABLE_ON);
    mUi->uYEnableOnBox->setChecked(defaults::ENABLE_Y_ENABLE_ON);
    mUi->uZEnableOnBox->setChecked(defaults::ENABLE_Z_ENABLE_ON);
    mUi->uEEnableOnBox->setChecked(defaults::ENABLE_E_ENABLE_ON);
    mUi->uIEnableOnBox->setChecked(defaults::ENABLE_I_ENABLE_ON);
    mUi->uJEnableOnBox->setChecked(defaults::ENABLE_J_ENABLE_ON);
    mUi->uKEnableOnBox->setChecked(defaults::ENABLE_K_ENABLE_ON);
    mUi->uUEnableOnBox->setChecked(defaults::ENABLE_U_ENABLE_ON);
    mUi->uVEnableOnBox->setChecked(defaults::ENABLE_V_ENABLE_ON);
    mUi->uWEnableOnBox->setChecked(defaults::ENABLE_W_ENABLE_ON);
    mUi->uDisableXDropdown->setCurrentText(defaults::DISABLE_X);
    mUi->uDisableYDropdown->setCurrentText(defaults::DISABLE_Y);
    mUi->uDisableZDropdown->setCurrentText(defaults::DISABLE_Z);
    mUi->uDisableEDropdown->setCurrentText(defaults::DISABLE_E);
    mUi->uDisableIDropdown->setCurrentText(defaults::DISABLE_I);
    mUi->uDisableJDropdown->setCurrentText(defaults::DISABLE_J);
    mUi->uDisableKDropdown->setCurrentText(defaults::DISABLE_K);
    mUi->uDisableUDropdown->setCurrentText(defaults::DISABLE_U);
    mUi->uDisableVDropdown->setCurrentText(defaults::DISABLE_V);
    mUi->uDisableWDropdown->setCurrentText(defaults::DISABLE_W);
    mUi->uDisableXBox->setChecked(defaults::ENABLE_DISABLE_X);
    mUi->uDisableYBox->setChecked(defaults::ENABLE_DISABLE_Y);
    mUi->uDisableZBox->setChecked(defaults::ENABLE_DISABLE_Z);
    mUi->uDisableIBox->setChecked(defaults::ENABLE_DISABLE_I);
    mUi->uDisableJBox->setChecked(defaults::ENABLE_DISABLE_J);
    mUi->uDisableKBox->setChecked(defaults::ENABLE_DISABLE_K);
    mUi->uDisableUBox->setChecked(defaults::ENABLE_DISABLE_U);
    mUi->uDisableVBox->setChecked(defaults::ENABLE_DISABLE_V);
    mUi->uDisableWBox->setChecked(defaults::ENABLE_DISABLE_W);
    mUi->uDisableInactiveExtruderBox->setChecked(defaults::DISABLE_INACTIVE_EXTRUDER);
    mUi->uInvertXDirDropdown->setCurrentText(defaults::INVERT_X_DIR);
    mUi->uInvertYDirDropdown->setCurrentText(defaults::INVERT_Y_DIR);
    mUi->uInvertZDirDropdown->setCurrentText(defaults::INVERT_Z_DIR);
    mUi->uInvertIDirDropdown->setCurrentText(defaults::INVERT_I_DIR);
    mUi->uInvertJDirDropdown->setCurrentText(defaults::INVERT_J_DIR);
    mUi->uInvertKDirDropdown->setCurrentText(defaults::INVERT_K_DIR);
    mUi->uInvertUDirDropdown->setCurrentText(defaults::INVERT_U_DIR);
    mUi->uInvertVDirDropdown->setCurrentText(defaults::INVERT_V_DIR);
    mUi->uInvertWDirDropdown->setCurrentText(defaults::INVERT_W_DIR);
    mUi->uInvertXDirBox->setChecked(defaults::ENABLE_INVERT_X_DIR);
    mUi->uInvertYDirBox->setChecked(defaults::ENABLE_INVERT_Y_DIR);
    mUi->uInvertZDirBox->setChecked(defaults::ENABLE_INVERT_Z_DIR);
    mUi->uInvertIDirBox->setChecked(defaults::ENABLE_INVERT_I_DIR);
    mUi->uInvertJDirBox->setChecked(defaults::ENABLE_INVERT_J_DIR);
    mUi->uInvertKDirBox->setChecked(defaults::ENABLE_INVERT_K_DIR);
    mUi->uInvertUDirBox->setChecked(defaults::ENABLE_INVERT_U_DIR);
    mUi->uInvertVDirBox->setChecked(defaults::ENABLE_INVERT_V_DIR);
    mUi->uInvertWDirBox->setChecked(defaults::ENABLE_INVERT_W_DIR);
    mUi->uInvertE0DirDropdown->setCurrentText(defaults::INVERT_E0_DIR);
    mUi->uInvertE1DirDropdown->setCurrentText(defaults::INVERT_E1_DIR);
    mUi->uInvertE2DirDropdown->setCurrentText(defaults::INVERT_E2_DIR);
    mUi->uInvertE3DirDropdown->setCurrentText(defaults::INVERT_E3_DIR);
    mUi->uInvertE4DirDropdown->setCurrentText(defaults::INVERT_E4_DIR);
    mUi->uInvertE5DirDropdown->setCurrentText(defaults::INVERT_E5_DIR);
    mUi->uInvertE6DirDropdown->setCurrentText(defaults::INVERT_E6_DIR);
    mUi->uInvertE7DirDropdown->setCurrentText(defaults::INVERT_E7_DIR);
    mUi->uDisableReducedAccuracyWarningBox->setChecked(defaults::DISABLE_REDUCED_ACCURACY_WARNING);

    mIsLoading = false;
}

bool StepperDriversPage::LoadFromJson(const QJsonObject &pJson)
{
    bool success = true;
    mIsLoading = true;

    success &= LoadConfig(mUi->uXDriverTypeDropdown, pJson, "X_DRIVER_TYPE");
    success &= LoadConfig(mUi->uYDriverTypeDropdown, pJson, "Y_DRIVER_TYPE");
    success &= LoadConfig(mUi->uZDriverTypeDropdown, pJson, "Z_DRIVER_TYPE");
    success &= LoadConfig(mUi->uX2DriverTypeDropdown, pJson, "X2_DRIVER_TYPE");
    success &= LoadConfig(mUi->uY2DriverTypeDropdown, pJson, "Y2_DRIVER_TYPE");
    success &= LoadConfig(mUi->uZ2DriverTypeDropdown, pJson, "Z2_DRIVER_TYPE");
    success &= LoadConfig(mUi->uZ3DriverTypeDropdown, pJson, "Z3_DRIVER_TYPE");
    success &= LoadConfig(mUi->uZ4DriverTypeDropdown, pJson, "Z4_DRIVER_TYPE");
    success &= LoadConfig(mUi->uXDriverTypeBox, pJson, "ENABLE_X_DRIVER_TYPE");
    success &= LoadConfig(mUi->uYDriverTypeBox, pJson, "ENABLE_Y_DRIVER_TYPE");
    success &= LoadConfig(mUi->uZDriverTypeBox, pJson, "ENABLE_Z_DRIVER_TYPE");
    success &= LoadConfig(mUi->uX2DriverTypeBox, pJson, "ENABLE_X2_DRIVER_TYPE");
    success &= LoadConfig(mUi->uY2DriverTypeBox, pJson, "ENABLE_Y2_DRIVER_TYPE");
    success &= LoadConfig(mUi->uZ2DriverTypeBox, pJson, "ENABLE_Z2_DRIVER_TYPE");
    success &= LoadConfig(mUi->uZ3DriverTypeBox, pJson, "ENABLE_Z3_DRIVER_TYPE");
    success &= LoadConfig(mUi->uZ4DriverTypeBox, pJson, "ENABLE_Z4_DRIVER_TYPE");
    success &= LoadConfig(mUi->uIDriverTypeDropdown, pJson, "I_DRIVER_TYPE");
    success &= LoadConfig(mUi->uJDriverTypeDropdown, pJson, "J_DRIVER_TYPE");
    success &= LoadConfig(mUi->uKDriverTypeDropdown, pJson, "K_DRIVER_TYPE");
    success &= LoadConfig(mUi->uIDriverTypeBox, pJson, "ENABLE_I_DRIVER_TYPE");
    success &= LoadConfig(mUi->uJDriverTypeBox, pJson, "ENABLE_J_DRIVER_TYPE");
    success &= LoadConfig(mUi->uKDriverTypeBox, pJson, "ENABLE_K_DRIVER_TYPE");
    success &= LoadConfig(mUi->uUDriverTypeDropdown, pJson, "U_DRIVER_TYPE");
    success &= LoadConfig(mUi->uVDriverTypeDropdown, pJson, "V_DRIVER_TYPE");
    success &= LoadConfig(mUi->uWDriverTypeDropdown, pJson, "W_DRIVER_TYPE");
    success &= LoadConfig(mUi->uUDriverTypeBox, pJson, "ENABLE_U_DRIVER_TYPE");
    success &= LoadConfig(mUi->uVDriverTypeBox, pJson, "ENABLE_V_DRIVER_TYPE");
    success &= LoadConfig(mUi->uWDriverTypeBox, pJson, "ENABLE_W_DRIVER_TYPE");
    success &= LoadConfig(mUi->uE0DriverTypeDropdown, pJson, "E0_DRIVER_TYPE");
    success &= LoadConfig(mUi->uE1DriverTypeDropdown, pJson, "E1_DRIVER_TYPE");
    success &= LoadConfig(mUi->uE2DriverTypeDropdown, pJson, "E2_DRIVER_TYPE");
    success &= LoadConfig(mUi->uE3DriverTypeDropdown, pJson, "E3_DRIVER_TYPE");
    success &= LoadConfig(mUi->uE4DriverTypeDropdown, pJson, "E4_DRIVER_TYPE");
    success &= LoadConfig(mUi->uE5DriverTypeDropdown, pJson, "E5_DRIVER_TYPE");
    success &= LoadConfig(mUi->uE6DriverTypeDropdown, pJson, "E6_DRIVER_TYPE");
    success &= LoadConfig(mUi->uE7DriverTypeDropdown, pJson, "E7_DRIVER_TYPE");
    success &= LoadConfig(mUi->uE0DriverTypeBox, pJson, "ENABLE_E0_DRIVER_TYPE");
    success &= LoadConfig(mUi->uE1DriverTypeBox, pJson, "ENABLE_E1_DRIVER_TYPE");
    success &= LoadConfig(mUi->uE2DriverTypeBox, pJson, "ENABLE_E2_DRIVER_TYPE");
    success &= LoadConfig(mUi->uE3DriverTypeBox, pJson, "ENABLE_E3_DRIVER_TYPE");
    success &= LoadConfig(mUi->uE4DriverTypeBox, pJson, "ENABLE_E4_DRIVER_TYPE");
    success &= LoadConfig(mUi->uE5DriverTypeBox, pJson, "ENABLE_E5_DRIVER_TYPE");
    success &= LoadConfig(mUi->uE6DriverTypeBox, pJson, "ENABLE_E6_DRIVER_TYPE");
    success &= LoadConfig(mUi->uE7DriverTypeBox, pJson, "ENABLE_E7_DRIVER_TYPE");
    success &= LoadConfig(mUi->uAxis4NameDropdown, pJson, "AXIS4_NAME");
    success &= LoadConfig(mUi->uAxis5NameDropdown, pJson, "AXIS5_NAME");
    success &= LoadConfig(mUi->uAxis6NameDropdown, pJson, "AXIS6_NAME");
    success &= LoadConfig(mUi->uAxis4RotatesBox, pJson, "AXIS4_ROTATES");
    success &= LoadConfig(mUi->uAxis5RotatesBox, pJson, "AXIS5_ROTATES");
    success &= LoadConfig(mUi->uAxis6RotatesBox, pJson, "AXIS6_ROTATES");
    success &= LoadConfig(mUi->uAxis7NameDropdown, pJson, "AXIS7_NAME");
    success &= LoadConfig(mUi->uAxis8NameDropdown, pJson, "AXIS8_NAME");
    success &= LoadConfig(mUi->uAxis9NameDropdown, pJson, "AXIS9_NAME");
    success &= LoadConfig(mUi->uAxis7RotatesBox, pJson, "AXIS7_ROTATES");
    success &= LoadConfig(mUi->uAxis8RotatesBox, pJson, "AXIS8_ROTATES");
    success &= LoadConfig(mUi->uAxis9RotatesBox, pJson, "AXIS9_ROTATES");
    success &= LoadConfig(mUi->uXEnableOnDropdown, pJson, "X_ENABLE_ON");
    success &= LoadConfig(mUi->uYEnableOnDropdown, pJson, "Y_ENABLE_ON");
    success &= LoadConfig(mUi->uZEnableOnDropdown, pJson, "Z_ENABLE_ON");
    success &= LoadConfig(mUi->uEEnableOnDropdown, pJson, "E_ENABLE_ON");
    success &= LoadConfig(mUi->uIEnableOnDropdown, pJson, "I_ENABLE_ON");
    success &= LoadConfig(mUi->uJEnableOnDropdown, pJson, "J_ENABLE_ON");
    success &= LoadConfig(mUi->uKEnableOnDropdown, pJson, "K_ENABLE_ON");
    success &= LoadConfig(mUi->uUEnableOnDropdown, pJson, "U_ENABLE_ON");
    success &= LoadConfig(mUi->uVEnableOnDropdown, pJson, "V_ENABLE_ON");
    success &= LoadConfig(mUi->uWEnableOnDropdown, pJson, "W_ENABLE_ON");
    success &= LoadConfig(mUi->uXEnableOnBox, pJson, "ENABLE_X_ENABLE_ON");
    success &= LoadConfig(mUi->uYEnableOnBox, pJson, "ENABLE_Y_ENABLE_ON");
    success &= LoadConfig(mUi->uZEnableOnBox, pJson, "ENABLE_Z_ENABLE_ON");
    success &= LoadConfig(mUi->uEEnableOnBox, pJson, "ENABLE_E_ENABLE_ON");
    success &= LoadConfig(mUi->uIEnableOnBox, pJson, "ENABLE_I_ENABLE_ON");
    success &= LoadConfig(mUi->uJEnableOnBox, pJson, "ENABLE_J_ENABLE_ON");
    success &= LoadConfig(mUi->uKEnableOnBox, pJson, "ENABLE_K_ENABLE_ON");
    success &= LoadConfig(mUi->uUEnableOnBox, pJson, "ENABLE_U_ENABLE_ON");
    success &= LoadConfig(mUi->uVEnableOnBox, pJson, "ENABLE_V_ENABLE_ON");
    success &= LoadConfig(mUi->uWEnableOnBox, pJson, "ENABLE_W_ENABLE_ON");
    success &= LoadConfig(mUi->uDisableXDropdown, pJson, "DISABLE_X");
    success &= LoadConfig(mUi->uDisableYDropdown, pJson, "DISABLE_Y");
    success &= LoadConfig(mUi->uDisableZDropdown, pJson, "DISABLE_Z");
    success &= LoadConfig(mUi->uDisableEDropdown, pJson, "DISABLE_E");
    success &= LoadConfig(mUi->uDisableIDropdown, pJson, "DISABLE_I");
    success &= LoadConfig(mUi->uDisableJDropdown, pJson, "DISABLE_J");
    success &= LoadConfig(mUi->uDisableKDropdown, pJson, "DISABLE_K");
    success &= LoadConfig(mUi->uDisableUDropdown, pJson, "DISABLE_U");
    success &= LoadConfig(mUi->uDisableVDropdown, pJson, "DISABLE_V");
    success &= LoadConfig(mUi->uDisableWDropdown, pJson, "DISABLE_W");
    success &= LoadConfig(mUi->uDisableXBox, pJson, "ENABLE_DISABLE_X");
    success &= LoadConfig(mUi->uDisableYBox, pJson, "ENABLE_DISABLE_Y");
    success &= LoadConfig(mUi->uDisableZBox, pJson, "ENABLE_DISABLE_Z");
    success &= LoadConfig(mUi->uDisableIBox, pJson, "ENABLE_DISABLE_I");
    success &= LoadConfig(mUi->uDisableJBox, pJson, "ENABLE_DISABLE_J");
    success &= LoadConfig(mUi->uDisableKBox, pJson, "ENABLE_DISABLE_K");
    success &= LoadConfig(mUi->uDisableUBox, pJson, "ENABLE_DISABLE_U");
    success &= LoadConfig(mUi->uDisableVBox, pJson, "ENABLE_DISABLE_V");
    success &= LoadConfig(mUi->uDisableWBox, pJson, "ENABLE_DISABLE_W");
    success &= LoadConfig(mUi->uDisableInactiveExtruderBox, pJson, "DISABLE_INACTIVE_EXTRUDER");
    success &= LoadConfig(mUi->uInvertXDirDropdown, pJson, "INVERT_X_DIR");
    success &= LoadConfig(mUi->uInvertYDirDropdown, pJson, "INVERT_Y_DIR");
    success &= LoadConfig(mUi->uInvertZDirDropdown, pJson, "INVERT_Z_DIR");
    success &= LoadConfig(mUi->uInvertIDirDropdown, pJson, "INVERT_I_DIR");
    success &= LoadConfig(mUi->uInvertJDirDropdown, pJson, "INVERT_J_DIR");
    success &= LoadConfig(mUi->uInvertKDirDropdown, pJson, "INVERT_K_DIR");
    success &= LoadConfig(mUi->uInvertUDirDropdown, pJson, "INVERT_U_DIR");
    success &= LoadConfig(mUi->uInvertVDirDropdown, pJson, "INVERT_V_DIR");
    success &= LoadConfig(mUi->uInvertWDirDropdown, pJson, "INVERT_W_DIR");
    success &= LoadConfig(mUi->uInvertXDirBox, pJson, "ENABLE_INVERT_X_DIR");
    success &= LoadConfig(mUi->uInvertYDirBox, pJson, "ENABLE_INVERT_Y_DIR");
    success &= LoadConfig(mUi->uInvertZDirBox, pJson, "ENABLE_INVERT_Z_DIR");
    success &= LoadConfig(mUi->uInvertIDirBox, pJson, "ENABLE_INVERT_I_DIR");
    success &= LoadConfig(mUi->uInvertJDirBox, pJson, "ENABLE_INVERT_J_DIR");
    success &= LoadConfig(mUi->uInvertKDirBox, pJson, "ENABLE_INVERT_K_DIR");
    success &= LoadConfig(mUi->uInvertUDirBox, pJson, "ENABLE_INVERT_U_DIR");
    success &= LoadConfig(mUi->uInvertVDirBox, pJson, "ENABLE_INVERT_V_DIR");
    success &= LoadConfig(mUi->uInvertWDirBox, pJson, "ENABLE_INVERT_W_DIR");
    success &= LoadConfig(mUi->uInvertE0DirDropdown, pJson, "INVERT_E0_DIR");
    success &= LoadConfig(mUi->uInvertE1DirDropdown, pJson, "INVERT_E1_DIR");
    success &= LoadConfig(mUi->uInvertE2DirDropdown, pJson, "INVERT_E2_DIR");
    success &= LoadConfig(mUi->uInvertE3DirDropdown, pJson, "INVERT_E3_DIR");
    success &= LoadConfig(mUi->uInvertE4DirDropdown, pJson, "INVERT_E4_DIR");
    success &= LoadConfig(mUi->uInvertE5DirDropdown, pJson, "INVERT_E5_DIR");
    success &= LoadConfig(mUi->uInvertE6DirDropdown, pJson, "INVERT_E6_DIR");
    success &= LoadConfig(mUi->uInvertE7DirDropdown, pJson, "INVERT_E7_DIR");
    success &= LoadConfig(mUi->uDisableReducedAccuracyWarningBox, pJson, "DISABLE_REDUCED_ACCURACY_WARNING");

    mIsLoading = false;
    return success;
}

void StepperDriversPage::FetchConfiguration(Configuration& pConfig)
{
    SetConfig(pConfig.stepperDrivers.X_DRIVER_TYPE, mUi->uXDriverTypeDropdown);
    SetConfig(pConfig.stepperDrivers.Y_DRIVER_TYPE, mUi->uYDriverTypeDropdown);
    SetConfig(pConfig.stepperDrivers.Z_DRIVER_TYPE, mUi->uZDriverTypeDropdown);
    SetConfig(pConfig.stepperDrivers.X2_DRIVER_TYPE, mUi->uX2DriverTypeDropdown);
    SetConfig(pConfig.stepperDrivers.Y2_DRIVER_TYPE, mUi->uY2DriverTypeDropdown);
    SetConfig(pConfig.stepperDrivers.Z2_DRIVER_TYPE, mUi->uZ2DriverTypeDropdown);
    SetConfig(pConfig.stepperDrivers.Z3_DRIVER_TYPE, mUi->uZ3DriverTypeDropdown);
    SetConfig(pConfig.stepperDrivers.Z4_DRIVER_TYPE, mUi->uZ4DriverTypeDropdown);
    SetConfig(pConfig.stepperDrivers.ENABLE_X_DRIVER_TYPE, mUi->uXDriverTypeBox);
    SetConfig(pConfig.stepperDrivers.ENABLE_Y_DRIVER_TYPE, mUi->uYDriverTypeBox);
    SetConfig(pConfig.stepperDrivers.ENABLE_Z_DRIVER_TYPE, mUi->uZDriverTypeBox);
    SetConfig(pConfig.stepperDrivers.ENABLE_X2_DRIVER_TYPE, mUi->uX2DriverTypeBox);
    SetConfig(pConfig.stepperDrivers.ENABLE_Y2_DRIVER_TYPE, mUi->uY2DriverTypeBox);
    SetConfig(pConfig.stepperDrivers.ENABLE_Z2_DRIVER_TYPE, mUi->uZ2DriverTypeBox);
    SetConfig(pConfig.stepperDrivers.ENABLE_Z3_DRIVER_TYPE, mUi->uZ3DriverTypeBox);
    SetConfig(pConfig.stepperDrivers.ENABLE_Z4_DRIVER_TYPE, mUi->uZ4DriverTypeBox);
    SetConfig(pConfig.stepperDrivers.I_DRIVER_TYPE, mUi->uIDriverTypeDropdown);
    SetConfig(pConfig.stepperDrivers.J_DRIVER_TYPE, mUi->uJDriverTypeDropdown);
    SetConfig(pConfig.stepperDrivers.K_DRIVER_TYPE, mUi->uKDriverTypeDropdown);
    SetConfig(pConfig.stepperDrivers.ENABLE_I_DRIVER_TYPE, mUi->uIDriverTypeBox);
    SetConfig(pConfig.stepperDrivers.ENABLE_J_DRIVER_TYPE, mUi->uJDriverTypeBox);
    SetConfig(pConfig.stepperDrivers.ENABLE_K_DRIVER_TYPE, mUi->uKDriverTypeBox);
    SetConfig(pConfig.stepperDrivers.U_DRIVER_TYPE, mUi->uUDriverTypeDropdown);
    SetConfig(pConfig.stepperDrivers.V_DRIVER_TYPE, mUi->uVDriverTypeDropdown);
    SetConfig(pConfig.stepperDrivers.W_DRIVER_TYPE, mUi->uWDriverTypeDropdown);
    SetConfig(pConfig.stepperDrivers.ENABLE_U_DRIVER_TYPE, mUi->uUDriverTypeBox);
    SetConfig(pConfig.stepperDrivers.ENABLE_V_DRIVER_TYPE, mUi->uVDriverTypeBox);
    SetConfig(pConfig.stepperDrivers.ENABLE_W_DRIVER_TYPE, mUi->uWDriverTypeBox);
    SetConfig(pConfig.stepperDrivers.E0_DRIVER_TYPE, mUi->uE0DriverTypeDropdown);
    SetConfig(pConfig.stepperDrivers.E1_DRIVER_TYPE, mUi->uE1DriverTypeDropdown);
    SetConfig(pConfig.stepperDrivers.E2_DRIVER_TYPE, mUi->uE2DriverTypeDropdown);
    SetConfig(pConfig.stepperDrivers.E3_DRIVER_TYPE, mUi->uE3DriverTypeDropdown);
    SetConfig(pConfig.stepperDrivers.E4_DRIVER_TYPE, mUi->uE4DriverTypeDropdown);
    SetConfig(pConfig.stepperDrivers.E5_DRIVER_TYPE, mUi->uE5DriverTypeDropdown);
    SetConfig(pConfig.stepperDrivers.E6_DRIVER_TYPE, mUi->uE6DriverTypeDropdown);
    SetConfig(pConfig.stepperDrivers.E7_DRIVER_TYPE, mUi->uE7DriverTypeDropdown);
    SetConfig(pConfig.stepperDrivers.ENABLE_E0_DRIVER_TYPE, mUi->uE0DriverTypeBox);
    SetConfig(pConfig.stepperDrivers.ENABLE_E1_DRIVER_TYPE, mUi->uE1DriverTypeBox);
    SetConfig(pConfig.stepperDrivers.ENABLE_E2_DRIVER_TYPE, mUi->uE2DriverTypeBox);
    SetConfig(pConfig.stepperDrivers.ENABLE_E3_DRIVER_TYPE, mUi->uE3DriverTypeBox);
    SetConfig(pConfig.stepperDrivers.ENABLE_E4_DRIVER_TYPE, mUi->uE4DriverTypeBox);
    SetConfig(pConfig.stepperDrivers.ENABLE_E5_DRIVER_TYPE, mUi->uE5DriverTypeBox);
    SetConfig(pConfig.stepperDrivers.ENABLE_E6_DRIVER_TYPE, mUi->uE6DriverTypeBox);
    SetConfig(pConfig.stepperDrivers.ENABLE_E7_DRIVER_TYPE, mUi->uE7DriverTypeBox);
    SetConfig(pConfig.stepperDrivers.AXIS4_NAME, mUi->uAxis4NameDropdown);
    SetConfig(pConfig.stepperDrivers.AXIS5_NAME, mUi->uAxis5NameDropdown);
    SetConfig(pConfig.stepperDrivers.AXIS6_NAME, mUi->uAxis6NameDropdown);
    SetConfig(pConfig.stepperDrivers.AXIS4_ROTATES, mUi->uAxis4RotatesBox);
    SetConfig(pConfig.stepperDrivers.AXIS5_ROTATES, mUi->uAxis5RotatesBox);
    SetConfig(pConfig.stepperDrivers.AXIS6_ROTATES, mUi->uAxis6RotatesBox);
    SetConfig(pConfig.stepperDrivers.AXIS7_NAME, mUi->uAxis7NameDropdown);
    SetConfig(pConfig.stepperDrivers.AXIS8_NAME, mUi->uAxis8NameDropdown);
    SetConfig(pConfig.stepperDrivers.AXIS9_NAME, mUi->uAxis9NameDropdown);
    SetConfig(pConfig.stepperDrivers.AXIS7_ROTATES, mUi->uAxis7RotatesBox);
    SetConfig(pConfig.stepperDrivers.AXIS8_ROTATES, mUi->uAxis8RotatesBox);
    SetConfig(pConfig.stepperDrivers.AXIS9_ROTATES, mUi->uAxis9RotatesBox);
    SetConfig(pConfig.stepperDrivers.X_ENABLE_ON, mUi->uXEnableOnDropdown);
    SetConfig(pConfig.stepperDrivers.Y_ENABLE_ON, mUi->uYEnableOnDropdown);
    SetConfig(pConfig.stepperDrivers.Z_ENABLE_ON, mUi->uZEnableOnDropdown);
    SetConfig(pConfig.stepperDrivers.E_ENABLE_ON, mUi->uEEnableOnDropdown);
    SetConfig(pConfig.stepperDrivers.I_ENABLE_ON, mUi->uIEnableOnDropdown);
    SetConfig(pConfig.stepperDrivers.J_ENABLE_ON, mUi->uJEnableOnDropdown);
    SetConfig(pConfig.stepperDrivers.K_ENABLE_ON, mUi->uKEnableOnDropdown);
    SetConfig(pConfig.stepperDrivers.U_ENABLE_ON, mUi->uUEnableOnDropdown);
    SetConfig(pConfig.stepperDrivers.V_ENABLE_ON, mUi->uVEnableOnDropdown);
    SetConfig(pConfig.stepperDrivers.W_ENABLE_ON, mUi->uWEnableOnDropdown);
    SetConfig(pConfig.stepperDrivers.ENABLE_X_ENABLE_ON, mUi->uXEnableOnBox);
    SetConfig(pConfig.stepperDrivers.ENABLE_Y_ENABLE_ON, mUi->uYEnableOnBox);
    SetConfig(pConfig.stepperDrivers.ENABLE_Z_ENABLE_ON, mUi->uZEnableOnBox);
    SetConfig(pConfig.stepperDrivers.ENABLE_E_ENABLE_ON, mUi->uEEnableOnBox);
    SetConfig(pConfig.stepperDrivers.ENABLE_I_ENABLE_ON, mUi->uIEnableOnBox);
    SetConfig(pConfig.stepperDrivers.ENABLE_J_ENABLE_ON, mUi->uJEnableOnBox);
    SetConfig(pConfig.stepperDrivers.ENABLE_K_ENABLE_ON, mUi->uKEnableOnBox);
    SetConfig(pConfig.stepperDrivers.ENABLE_U_ENABLE_ON, mUi->uUEnableOnBox);
    SetConfig(pConfig.stepperDrivers.ENABLE_V_ENABLE_ON, mUi->uVEnableOnBox);
    SetConfig(pConfig.stepperDrivers.ENABLE_W_ENABLE_ON, mUi->uWEnableOnBox);
    SetConfig(pConfig.stepperDrivers.DISABLE_X, mUi->uDisableXDropdown);
    SetConfig(pConfig.stepperDrivers.DISABLE_Y, mUi->uDisableYDropdown);
    SetConfig(pConfig.stepperDrivers.DISABLE_Z, mUi->uDisableZDropdown);
    SetConfig(pConfig.stepperDrivers.DISABLE_E, mUi->uDisableEDropdown);
    SetConfig(pConfig.stepperDrivers.DISABLE_I, mUi->uDisableIDropdown);
    SetConfig(pConfig.stepperDrivers.DISABLE_J, mUi->uDisableJDropdown);
    SetConfig(pConfig.stepperDrivers.DISABLE_K, mUi->uDisableKDropdown);
    SetConfig(pConfig.stepperDrivers.DISABLE_U, mUi->uDisableUDropdown);
    SetConfig(pConfig.stepperDrivers.DISABLE_V, mUi->uDisableVDropdown);
    SetConfig(pConfig.stepperDrivers.DISABLE_W, mUi->uDisableWDropdown);
    SetConfig(pConfig.stepperDrivers.ENABLE_DISABLE_X, mUi->uDisableXBox);
    SetConfig(pConfig.stepperDrivers.ENABLE_DISABLE_Y, mUi->uDisableYBox);
    SetConfig(pConfig.stepperDrivers.ENABLE_DISABLE_Z, mUi->uDisableZBox);
    SetConfig(pConfig.stepperDrivers.ENABLE_DISABLE_I, mUi->uDisableIBox);
    SetConfig(pConfig.stepperDrivers.ENABLE_DISABLE_J, mUi->uDisableJBox);
    SetConfig(pConfig.stepperDrivers.ENABLE_DISABLE_K, mUi->uDisableKBox);
    SetConfig(pConfig.stepperDrivers.ENABLE_DISABLE_U, mUi->uDisableUBox);
    SetConfig(pConfig.stepperDrivers.ENABLE_DISABLE_V, mUi->uDisableVBox);
    SetConfig(pConfig.stepperDrivers.ENABLE_DISABLE_W, mUi->uDisableWBox);
    SetConfig(pConfig.stepperDrivers.DISABLE_INACTIVE_EXTRUDER, mUi->uDisableInactiveExtruderBox);
    SetConfig(pConfig.stepperDrivers.INVERT_X_DIR, mUi->uInvertXDirDropdown);
    SetConfig(pConfig.stepperDrivers.INVERT_Y_DIR, mUi->uInvertYDirDropdown);
    SetConfig(pConfig.stepperDrivers.INVERT_Z_DIR, mUi->uInvertZDirDropdown);
    SetConfig(pConfig.stepperDrivers.INVERT_I_DIR, mUi->uInvertIDirDropdown);
    SetConfig(pConfig.stepperDrivers.INVERT_J_DIR, mUi->uInvertJDirDropdown);
    SetConfig(pConfig.stepperDrivers.INVERT_K_DIR, mUi->uInvertKDirDropdown);
    SetConfig(pConfig.stepperDrivers.INVERT_U_DIR, mUi->uInvertUDirDropdown);
    SetConfig(pConfig.stepperDrivers.INVERT_V_DIR, mUi->uInvertVDirDropdown);
    SetConfig(pConfig.stepperDrivers.INVERT_W_DIR, mUi->uInvertWDirDropdown);
    SetConfig(pConfig.stepperDrivers.ENABLE_INVERT_X_DIR, mUi->uInvertXDirBox);
    SetConfig(pConfig.stepperDrivers.ENABLE_INVERT_Y_DIR, mUi->uInvertYDirBox);
    SetConfig(pConfig.stepperDrivers.ENABLE_INVERT_Z_DIR, mUi->uInvertZDirBox);
    SetConfig(pConfig.stepperDrivers.ENABLE_INVERT_I_DIR, mUi->uInvertIDirBox);
    SetConfig(pConfig.stepperDrivers.ENABLE_INVERT_J_DIR, mUi->uInvertJDirBox);
    SetConfig(pConfig.stepperDrivers.ENABLE_INVERT_K_DIR, mUi->uInvertKDirBox);
    SetConfig(pConfig.stepperDrivers.ENABLE_INVERT_U_DIR, mUi->uInvertUDirBox);
    SetConfig(pConfig.stepperDrivers.ENABLE_INVERT_V_DIR, mUi->uInvertVDirBox);
    SetConfig(pConfig.stepperDrivers.ENABLE_INVERT_W_DIR, mUi->uInvertWDirBox);
    SetConfig(pConfig.stepperDrivers.INVERT_E0_DIR, mUi->uInvertE0DirDropdown);
    SetConfig(pConfig.stepperDrivers.INVERT_E1_DIR, mUi->uInvertE1DirDropdown);
    SetConfig(pConfig.stepperDrivers.INVERT_E2_DIR, mUi->uInvertE2DirDropdown);
    SetConfig(pConfig.stepperDrivers.INVERT_E3_DIR, mUi->uInvertE3DirDropdown);
    SetConfig(pConfig.stepperDrivers.INVERT_E4_DIR, mUi->uInvertE4DirDropdown);
    SetConfig(pConfig.stepperDrivers.INVERT_E5_DIR, mUi->uInvertE5DirDropdown);
    SetConfig(pConfig.stepperDrivers.INVERT_E6_DIR, mUi->uInvertE6DirDropdown);
    SetConfig(pConfig.stepperDrivers.INVERT_E7_DIR, mUi->uInvertE7DirDropdown);
    SetConfig(pConfig.stepperDrivers.DISABLE_REDUCED_ACCURACY_WARNING, mUi->uDisableReducedAccuracyWarningBox);
}

void StepperDriversPage::ReplaceTags(QStringList& pOutput)
{
    ReplaceTag(pOutput, "#{X_DRIVER_TYPE}", mUi->uXDriverTypeDropdown, !mUi->uXDriverTypeBox->isChecked(), "X_DRIVER_TYPE");
    ReplaceTag(pOutput, "#{Y_DRIVER_TYPE}", mUi->uYDriverTypeDropdown, !mUi->uYDriverTypeBox->isChecked(), "Y_DRIVER_TYPE");
    ReplaceTag(pOutput, "#{Z_DRIVER_TYPE}", mUi->uZDriverTypeDropdown, !mUi->uZDriverTypeBox->isChecked(), "Z_DRIVER_TYPE");
    ReplaceTag(pOutput, "#{X2_DRIVER_TYPE}", mUi->uX2DriverTypeDropdown, !mUi->uX2DriverTypeBox->isChecked(), "X2_DRIVER_TYPE");
    ReplaceTag(pOutput, "#{Y2_DRIVER_TYPE}", mUi->uY2DriverTypeDropdown, !mUi->uY2DriverTypeBox->isChecked(), "Y2_DRIVER_TYPE");
    ReplaceTag(pOutput, "#{Z2_DRIVER_TYPE}", mUi->uZ2DriverTypeDropdown, !mUi->uZ2DriverTypeBox->isChecked(), "Z2_DRIVER_TYPE");
    ReplaceTag(pOutput, "#{Z3_DRIVER_TYPE}", mUi->uZ3DriverTypeDropdown, !mUi->uZ3DriverTypeBox->isChecked(), "Z3_DRIVER_TYPE");
    ReplaceTag(pOutput, "#{Z4_DRIVER_TYPE}", mUi->uZ4DriverTypeDropdown, !mUi->uZ4DriverTypeBox->isChecked(), "Z4_DRIVER_TYPE");
    ReplaceTag(pOutput, "#{I_DRIVER_TYPE}", mUi->uIDriverTypeDropdown, !mUi->uIDriverTypeBox->isChecked(), "I_DRIVER_TYPE");
    ReplaceTag(pOutput, "#{J_DRIVER_TYPE}", mUi->uJDriverTypeDropdown, !mUi->uJDriverTypeBox->isChecked(), "J_DRIVER_TYPE");
    ReplaceTag(pOutput, "#{K_DRIVER_TYPE}", mUi->uKDriverTypeDropdown, !mUi->uKDriverTypeBox->isChecked(), "K_DRIVER_TYPE");
    ReplaceTag(pOutput, "#{U_DRIVER_TYPE}", mUi->uUDriverTypeDropdown, !mUi->uUDriverTypeBox->isChecked(), "U_DRIVER_TYPE");
    ReplaceTag(pOutput, "#{V_DRIVER_TYPE}", mUi->uVDriverTypeDropdown, !mUi->uVDriverTypeBox->isChecked(), "V_DRIVER_TYPE");
    ReplaceTag(pOutput, "#{W_DRIVER_TYPE}", mUi->uWDriverTypeDropdown, !mUi->uWDriverTypeBox->isChecked(), "W_DRIVER_TYPE");
    ReplaceTag(pOutput, "#{E0_DRIVER_TYPE}", mUi->uE0DriverTypeDropdown, !mUi->uE0DriverTypeBox->isChecked(), "E0_DRIVER_TYPE");
    ReplaceTag(pOutput, "#{E1_DRIVER_TYPE}", mUi->uE1DriverTypeDropdown, !mUi->uE1DriverTypeBox->isChecked(), "E1_DRIVER_TYPE");
    ReplaceTag(pOutput, "#{E2_DRIVER_TYPE}", mUi->uE2DriverTypeDropdown, !mUi->uE2DriverTypeBox->isChecked(), "E2_DRIVER_TYPE");
    ReplaceTag(pOutput, "#{E3_DRIVER_TYPE}", mUi->uE3DriverTypeDropdown, !mUi->uE3DriverTypeBox->isChecked(), "E3_DRIVER_TYPE");
    ReplaceTag(pOutput, "#{E4_DRIVER_TYPE}", mUi->uE4DriverTypeDropdown, !mUi->uE4DriverTypeBox->isChecked(), "E4_DRIVER_TYPE");
    ReplaceTag(pOutput, "#{E5_DRIVER_TYPE}", mUi->uE5DriverTypeDropdown, !mUi->uE5DriverTypeBox->isChecked(), "E5_DRIVER_TYPE");
    ReplaceTag(pOutput, "#{E6_DRIVER_TYPE}", mUi->uE6DriverTypeDropdown, !mUi->uE6DriverTypeBox->isChecked(), "E6_DRIVER_TYPE");
    ReplaceTag(pOutput, "#{E7_DRIVER_TYPE}", mUi->uE7DriverTypeDropdown, !mUi->uE7DriverTypeBox->isChecked(), "E7_DRIVER_TYPE");
    ReplaceTag(pOutput, "#{AXIS4_NAME}", mUi->uAxis4NameDropdown, false, "AXIS4_NAME", false, true);
    ReplaceTag(pOutput, "#{AXIS5_NAME}", mUi->uAxis5NameDropdown, false, "AXIS5_NAME", false, true);
    ReplaceTag(pOutput, "#{AXIS6_NAME}", mUi->uAxis6NameDropdown, false, "AXIS6_NAME", false, true);
    ReplaceTag(pOutput, "#{AXIS4_ROTATES}", mUi->uAxis4RotatesBox, "AXIS4_ROTATES");
    ReplaceTag(pOutput, "#{AXIS5_ROTATES}", mUi->uAxis5RotatesBox, "AXIS5_ROTATES");
    ReplaceTag(pOutput, "#{AXIS6_ROTATES}", mUi->uAxis6RotatesBox, "AXIS6_ROTATES");
    ReplaceTag(pOutput, "#{AXIS7_NAME}", mUi->uAxis7NameDropdown, false, "AXIS7_NAME", false, true);
    ReplaceTag(pOutput, "#{AXIS8_NAME}", mUi->uAxis8NameDropdown, false, "AXIS8_NAME", false, true);
    ReplaceTag(pOutput, "#{AXIS9_NAME}", mUi->uAxis9NameDropdown, false, "AXIS9_NAME", false, true);
    ReplaceTag(pOutput, "#{AXIS7_ROTATES}", mUi->uAxis7RotatesBox, "AXIS7_ROTATES");
    ReplaceTag(pOutput, "#{AXIS8_ROTATES}", mUi->uAxis8RotatesBox, "AXIS8_ROTATES");
    ReplaceTag(pOutput, "#{AXIS9_ROTATES}", mUi->uAxis9RotatesBox, "AXIS9_ROTATES");
    ReplaceTag(pOutput, "#{X_ENABLE_ON}", mUi->uXEnableOnDropdown, !mUi->uXEnableOnBox->isChecked(), "X_ENABLE_ON");
    ReplaceTag(pOutput, "#{Y_ENABLE_ON}", mUi->uYEnableOnDropdown, !mUi->uYEnableOnBox->isChecked(), "Y_ENABLE_ON");
    ReplaceTag(pOutput, "#{Z_ENABLE_ON}", mUi->uZEnableOnDropdown, !mUi->uZEnableOnBox->isChecked(), "Z_ENABLE_ON");
    ReplaceTag(pOutput, "#{E_ENABLE_ON}", mUi->uEEnableOnDropdown, !mUi->uEEnableOnBox->isChecked(), "E_ENABLE_ON");
    ReplaceTag(pOutput, "#{I_ENABLE_ON}", mUi->uIEnableOnDropdown, !mUi->uIEnableOnBox->isChecked(), "I_ENABLE_ON");
    ReplaceTag(pOutput, "#{J_ENABLE_ON}", mUi->uJEnableOnDropdown, !mUi->uJEnableOnBox->isChecked(), "J_ENABLE_ON");
    ReplaceTag(pOutput, "#{K_ENABLE_ON}", mUi->uKEnableOnDropdown, !mUi->uKEnableOnBox->isChecked(), "K_ENABLE_ON");
    ReplaceTag(pOutput, "#{U_ENABLE_ON}", mUi->uUEnableOnDropdown, !mUi->uUEnableOnBox->isChecked(), "U_ENABLE_ON");
    ReplaceTag(pOutput, "#{V_ENABLE_ON}", mUi->uVEnableOnDropdown, !mUi->uVEnableOnBox->isChecked(), "V_ENABLE_ON");
    ReplaceTag(pOutput, "#{W_ENABLE_ON}", mUi->uWEnableOnDropdown, !mUi->uWEnableOnBox->isChecked(), "W_ENABLE_ON");
    ReplaceTag(pOutput, "#{DISABLE_X}", mUi->uDisableXDropdown, !mUi->uDisableXBox->isChecked(), "DISABLE_X");
    ReplaceTag(pOutput, "#{DISABLE_Y}", mUi->uDisableYDropdown, !mUi->uDisableYBox->isChecked(), "DISABLE_Y");
    ReplaceTag(pOutput, "#{DISABLE_Z}", mUi->uDisableZDropdown, !mUi->uDisableZBox->isChecked(), "DISABLE_Z");
    ReplaceTag(pOutput, "#{DISABLE_E}", mUi->uDisableEDropdown, false, "DISABLE_E");
    ReplaceTag(pOutput, "#{DISABLE_I}", mUi->uDisableIDropdown, !mUi->uDisableIBox->isChecked(), "DISABLE_I");
    ReplaceTag(pOutput, "#{DISABLE_J}", mUi->uDisableJDropdown, !mUi->uDisableJBox->isChecked(), "DISABLE_J");
    ReplaceTag(pOutput, "#{DISABLE_K}", mUi->uDisableKDropdown, !mUi->uDisableKBox->isChecked(), "DISABLE_K");
    ReplaceTag(pOutput, "#{DISABLE_U}", mUi->uDisableUDropdown, !mUi->uDisableUBox->isChecked(), "DISABLE_U");
    ReplaceTag(pOutput, "#{DISABLE_V}", mUi->uDisableVDropdown, !mUi->uDisableVBox->isChecked(), "DISABLE_V");
    ReplaceTag(pOutput, "#{DISABLE_W}", mUi->uDisableWDropdown, !mUi->uDisableWBox->isChecked(), "DISABLE_W");
    ReplaceTag(pOutput, "#{DISABLE_INACTIVE_EXTRUDER}", mUi->uDisableInactiveExtruderBox, "DISABLE_INACTIVE_EXTRUDER");
    ReplaceTag(pOutput, "#{INVERT_X_DIR}", mUi->uInvertXDirDropdown, !mUi->uInvertXDirBox->isChecked(), "INVERT_X_DIR");
    ReplaceTag(pOutput, "#{INVERT_Y_DIR}", mUi->uInvertYDirDropdown, !mUi->uInvertYDirBox->isChecked(), "INVERT_Y_DIR");
    ReplaceTag(pOutput, "#{INVERT_Z_DIR}", mUi->uInvertZDirDropdown, !mUi->uInvertZDirBox->isChecked(), "INVERT_Z_DIR");
    ReplaceTag(pOutput, "#{INVERT_I_DIR}", mUi->uInvertIDirDropdown, !mUi->uInvertIDirBox->isChecked(), "INVERT_I_DIR");
    ReplaceTag(pOutput, "#{INVERT_J_DIR}", mUi->uInvertJDirDropdown, !mUi->uInvertJDirBox->isChecked(), "INVERT_J_DIR");
    ReplaceTag(pOutput, "#{INVERT_K_DIR}", mUi->uInvertKDirDropdown, !mUi->uInvertKDirBox->isChecked(), "INVERT_K_DIR");
    ReplaceTag(pOutput, "#{INVERT_U_DIR}", mUi->uInvertUDirDropdown, !mUi->uInvertUDirBox->isChecked(), "INVERT_U_DIR");
    ReplaceTag(pOutput, "#{INVERT_V_DIR}", mUi->uInvertVDirDropdown, !mUi->uInvertVDirBox->isChecked(), "INVERT_V_DIR");
    ReplaceTag(pOutput, "#{INVERT_W_DIR}", mUi->uInvertWDirDropdown, !mUi->uInvertWDirBox->isChecked(), "INVERT_W_DIR");
    ReplaceTag(pOutput, "#{INVERT_E0_DIR}", mUi->uInvertE0DirDropdown, !mUi->uInvertE0DirBox->isChecked(), "INVERT_E0_DIR");
    ReplaceTag(pOutput, "#{INVERT_E1_DIR}", mUi->uInvertE1DirDropdown, !mUi->uInvertE1DirBox->isChecked(), "INVERT_E1_DIR");
    ReplaceTag(pOutput, "#{INVERT_E2_DIR}", mUi->uInvertE2DirDropdown, !mUi->uInvertE2DirBox->isChecked(), "INVERT_E2_DIR");
    ReplaceTag(pOutput, "#{INVERT_E3_DIR}", mUi->uInvertE3DirDropdown, !mUi->uInvertE3DirBox->isChecked(), "INVERT_E3_DIR");
    ReplaceTag(pOutput, "#{INVERT_E4_DIR}", mUi->uInvertE4DirDropdown, !mUi->uInvertE4DirBox->isChecked(), "INVERT_E4_DIR");
    ReplaceTag(pOutput, "#{INVERT_E5_DIR}", mUi->uInvertE5DirDropdown, !mUi->uInvertE5DirBox->isChecked(), "INVERT_E5_DIR");
    ReplaceTag(pOutput, "#{INVERT_E6_DIR}", mUi->uInvertE6DirDropdown, !mUi->uInvertE6DirBox->isChecked(), "INVERT_E6_DIR");
    ReplaceTag(pOutput, "#{INVERT_E7_DIR}", mUi->uInvertE7DirDropdown, !mUi->uInvertE7DirBox->isChecked(), "INVERT_E7_DIR");
    ReplaceTag(pOutput, "#{DISABLE_REDUCED_ACCURACY_WARNING}", mUi->uDisableReducedAccuracyWarningBox, "DISABLE_REDUCED_ACCURACY_WARNING");
}
