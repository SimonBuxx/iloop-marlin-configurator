/*!
 * \file EncoderPage.cpp
/// \brief The EncoderPage class represents the encoder page
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

#include "EncoderPage.h"
#include "./ui_EncoderPage.h"
#include "HelperFunctions.h"

EncoderPage::EncoderPage(QWidget *pParent) :
    AbstractPage(ENCODER_TEMPLATE_PATH, pParent),
    mUi(new Ui::EncoderPage)
{
    mUi->setupUi(this);
}

EncoderPage::~EncoderPage()
{
    delete mUi;
}

void EncoderPage::ConnectGuiSignalsAndSlots()
{
    QObject::connect(mUi->uDocumentationButton, &QPushButton::clicked, this, [&]()
    {
        OpenMarlinDocumentation("encoder");
    });

    AbstractPage::ConnectGuiSignalsAndSlots();
}

void EncoderPage::ResetValues()
{
    mIsLoading = true;

    mUi->uEncoderPulsesPerStepSpinBox->setValue(defaults::ENCODER_PULSES_PER_STEP);
    mUi->uEncoderPulsesPerStepBox->setChecked(defaults::ENABLE_ENCODER_PULSES_PER_STEP);
    mUi->uEncoderStepsPerMenuItemSpinBox->setValue(defaults::ENCODER_STEPS_PER_MENU_ITEM);
    mUi->uEncoderStepsPerMenuItemBox->setChecked(defaults::ENABLE_ENCODER_STEPS_PER_MENU_ITEM);
    mUi->uReverseEncoderDirectionBox->setChecked(defaults::REVERSE_ENCODER_DIRECTION);
    mUi->uReverseMenuDirectionBox->setChecked(defaults::REVERSE_MENU_DIRECTION);
    mUi->uReverseSelectDirectionBox->setChecked(defaults::REVERSE_SELECT_DIRECTION);
    mUi->uEncoderNoiseFilterBox->setChecked(defaults::ENCODER_NOISE_FILTER);
    mUi->uEncoderSamplesSpinBox->setValue(defaults::ENCODER_SAMPLES);
    mUi->uIndividualAxisHomingMenuBox->setChecked(defaults::INDIVIDUAL_AXIS_HOMING_MENU);
    mUi->uIndividualAxisHomingSubmenuBox->setChecked(defaults::INDIVIDUAL_AXIS_HOMING_SUBMENU);

    mIsLoading = false;
}

bool EncoderPage::LoadFromJson(const QJsonObject &pJson)
{
    bool success = true;
    mIsLoading = true;

    success &= LoadConfig(mUi->uEncoderPulsesPerStepSpinBox, pJson, "ENCODER_PULSES_PER_STEP");
    success &= LoadConfig(mUi->uEncoderPulsesPerStepBox, pJson, "ENABLE_ENCODER_PULSES_PER_STEP");
    success &= LoadConfig(mUi->uEncoderStepsPerMenuItemSpinBox, pJson, "ENCODER_STEPS_PER_MENU_ITEM");
    success &= LoadConfig(mUi->uEncoderStepsPerMenuItemBox, pJson, "ENABLE_ENCODER_STEPS_PER_MENU_ITEM");
    success &= LoadConfig(mUi->uReverseEncoderDirectionBox, pJson, "REVERSE_ENCODER_DIRECTION");
    success &= LoadConfig(mUi->uReverseMenuDirectionBox, pJson, "REVERSE_MENU_DIRECTION");
    success &= LoadConfig(mUi->uReverseSelectDirectionBox, pJson, "REVERSE_SELECT_DIRECTION");
    success &= LoadConfig(mUi->uEncoderNoiseFilterBox, pJson, "ENCODER_NOISE_FILTER");
    success &= LoadConfig(mUi->uEncoderSamplesSpinBox, pJson, "ENCODER_SAMPLES");
    success &= LoadConfig(mUi->uIndividualAxisHomingMenuBox, pJson, "INDIVIDUAL_AXIS_HOMING_MENU");
    success &= LoadConfig(mUi->uIndividualAxisHomingSubmenuBox, pJson, "INDIVIDUAL_AXIS_HOMING_SUBMENU");

    mIsLoading = false;
    return success;
}

void EncoderPage::FetchConfiguration(Configuration& pConfig)
{
    SetConfig(pConfig.encoder.ENCODER_PULSES_PER_STEP, mUi->uEncoderPulsesPerStepSpinBox);
    SetConfig(pConfig.encoder.ENABLE_ENCODER_PULSES_PER_STEP, mUi->uEncoderPulsesPerStepBox);
    SetConfig(pConfig.encoder.ENCODER_STEPS_PER_MENU_ITEM, mUi->uEncoderStepsPerMenuItemSpinBox);
    SetConfig(pConfig.encoder.ENABLE_ENCODER_STEPS_PER_MENU_ITEM, mUi->uEncoderStepsPerMenuItemBox);
    SetConfig(pConfig.encoder.REVERSE_ENCODER_DIRECTION, mUi->uReverseEncoderDirectionBox);
    SetConfig(pConfig.encoder.REVERSE_MENU_DIRECTION, mUi->uReverseMenuDirectionBox);
    SetConfig(pConfig.encoder.REVERSE_SELECT_DIRECTION, mUi->uReverseSelectDirectionBox);
    SetConfig(pConfig.encoder.ENCODER_NOISE_FILTER, mUi->uEncoderNoiseFilterBox);
    SetConfig(pConfig.encoder.ENCODER_SAMPLES, mUi->uEncoderSamplesSpinBox);
    SetConfig(pConfig.encoder.INDIVIDUAL_AXIS_HOMING_MENU, mUi->uIndividualAxisHomingMenuBox);
    SetConfig(pConfig.encoder.INDIVIDUAL_AXIS_HOMING_SUBMENU, mUi->uIndividualAxisHomingSubmenuBox);
}

void EncoderPage::ReplaceTags(QStringList& pOutput)
{
    ReplaceTag(pOutput, "#{ENCODER_PULSES_PER_STEP}", mUi->uEncoderPulsesPerStepSpinBox, !mUi->uEncoderPulsesPerStepBox->isChecked(), "ENCODER_PULSES_PER_STEP");
    ReplaceTag(pOutput, "#{ENCODER_STEPS_PER_MENU_ITEM}", mUi->uEncoderStepsPerMenuItemSpinBox, !mUi->uEncoderStepsPerMenuItemBox->isChecked(), "ENCODER_STEPS_PER_MENU_ITEM");
    ReplaceTag(pOutput, "#{REVERSE_ENCODER_DIRECTION}", mUi->uReverseEncoderDirectionBox, "REVERSE_ENCODER_DIRECTION");
    ReplaceTag(pOutput, "#{REVERSE_MENU_DIRECTION}", mUi->uReverseMenuDirectionBox, "REVERSE_MENU_DIRECTION");
    ReplaceTag(pOutput, "#{REVERSE_SELECT_DIRECTION}", mUi->uReverseSelectDirectionBox, "REVERSE_SELECT_DIRECTION");
    ReplaceTag(pOutput, "#{ENCODER_NOISE_FILTER}", mUi->uEncoderNoiseFilterBox, "ENCODER_NOISE_FILTER");
    ReplaceTag(pOutput, "#{ENCODER_SAMPLES}", mUi->uEncoderSamplesSpinBox, false, "ENCODER_SAMPLES");
    ReplaceTag(pOutput, "#{INDIVIDUAL_AXIS_HOMING_MENU}", mUi->uIndividualAxisHomingMenuBox, "INDIVIDUAL_AXIS_HOMING_MENU");
    ReplaceTag(pOutput, "#{INDIVIDUAL_AXIS_HOMING_SUBMENU}", mUi->uIndividualAxisHomingSubmenuBox, "INDIVIDUAL_AXIS_HOMING_SUBMENU");
}
