/*!
 * \file SpeakerPage.cpp
/// \brief The SpeakerPage class represents the speaker page
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

#include "SpeakerPage.h"
#include "./ui_SpeakerPage.h"
#include "HelperFunctions.h"

SpeakerPage::SpeakerPage(QWidget *pParent) :
    AbstractPage(SPEAKER_TEMPLATE_PATH, pParent),
    mUi(new Ui::SpeakerPage)
{
    mUi->setupUi(this);
}

SpeakerPage::~SpeakerPage()
{
    delete mUi;
}

void SpeakerPage::ConnectGuiSignalsAndSlots()
{
    QObject::connect(mUi->uDocumentationButton, &QPushButton::clicked, this, [&]()
    {
        OpenMarlinDocumentation("speaker");
    });

    AbstractPage::ConnectGuiSignalsAndSlots();
}

void SpeakerPage::ResetValues()
{
    mIsLoading = true;

    mUi->uSpeakerBox->setChecked(defaults::SPEAKER);
    mUi->uLcdFeedbackFrequencyDurationMsSpinBox->setValue(defaults::LCD_FEEDBACK_FREQUENCY_DURATION_MS);
    mUi->uLcdFeedbackFrequencyDurationMsBox->setChecked(defaults::ENABLE_LCD_FEEDBACK_FREQUENCY_DURATION_MS);
    mUi->uLcdFeedbackFrequencyHzSpinBox->setValue(defaults::LCD_FEEDBACK_FREQUENCY_HZ);
    mUi->uLcdFeedbackFrequencyHzBox->setChecked(defaults::ENABLE_LCD_FEEDBACK_FREQUENCY_HZ);

    mIsLoading = false;
}

bool SpeakerPage::LoadFromJson(const QJsonObject &pJson)
{
    bool success = true;
    mIsLoading = true;

    success &= LoadConfig(mUi->uSpeakerBox, pJson, "SPEAKER");
    success &= LoadConfig(mUi->uLcdFeedbackFrequencyDurationMsSpinBox, pJson, "LCD_FEEDBACK_FREQUENCY_DURATION_MS");
    success &= LoadConfig(mUi->uLcdFeedbackFrequencyDurationMsBox, pJson, "ENABLE_LCD_FEEDBACK_FREQUENCY_DURATION_MS");
    success &= LoadConfig(mUi->uLcdFeedbackFrequencyHzSpinBox, pJson, "LCD_FEEDBACK_FREQUENCY_HZ");
    success &= LoadConfig(mUi->uLcdFeedbackFrequencyHzBox, pJson, "ENABLE_LCD_FEEDBACK_FREQUENCY_HZ");

    mIsLoading = false;
    return success;
}

void SpeakerPage::FetchConfiguration(Configuration& pConfig)
{
    SetConfig(pConfig.speaker.SPEAKER, mUi->uSpeakerBox);
    SetConfig(pConfig.speaker.LCD_FEEDBACK_FREQUENCY_DURATION_MS, mUi->uLcdFeedbackFrequencyDurationMsSpinBox);
    SetConfig(pConfig.speaker.ENABLE_LCD_FEEDBACK_FREQUENCY_DURATION_MS, mUi->uLcdFeedbackFrequencyDurationMsBox);
    SetConfig(pConfig.speaker.LCD_FEEDBACK_FREQUENCY_HZ, mUi->uLcdFeedbackFrequencyHzSpinBox);
    SetConfig(pConfig.speaker.ENABLE_LCD_FEEDBACK_FREQUENCY_HZ, mUi->uLcdFeedbackFrequencyHzBox);
}

void SpeakerPage::ReplaceTags(QStringList& pOutput)
{
    ReplaceTag(pOutput, "#{SPEAKER}", mUi->uSpeakerBox, "SPEAKER");
    ReplaceTag(pOutput, "#{LCD_FEEDBACK_FREQUENCY_DURATION_MS}", mUi->uLcdFeedbackFrequencyDurationMsSpinBox, !mUi->uLcdFeedbackFrequencyDurationMsBox->isChecked(), "LCD_FEEDBACK_FREQUENCY_DURATION_MS");
    ReplaceTag(pOutput, "#{LCD_FEEDBACK_FREQUENCY_HZ}", mUi->uLcdFeedbackFrequencyHzSpinBox, !mUi->uLcdFeedbackFrequencyHzBox->isChecked(), "LCD_FEEDBACK_FREQUENCY_HZ");
}
