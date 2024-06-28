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
}
