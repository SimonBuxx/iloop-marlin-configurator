/*!
 * \file SDCardPage.cpp
/// \brief The SDCardPage class represents the SD card page
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

#include "SDCardPage.h"
#include "./ui_SDCardPage.h"
#include "HelperFunctions.h"

SDCardPage::SDCardPage(QWidget *pParent) :
    AbstractPage(SD_CARD_TEMPLATE_PATH, pParent),
    mUi(new Ui::SDCardPage)
{
    mUi->setupUi(this);
}

SDCardPage::~SDCardPage()
{
    delete mUi;
}

void SDCardPage::ConnectGuiSignalsAndSlots()
{
    QObject::connect(mUi->uDocumentationButton, &QPushButton::clicked, this, [&]()
    {
        OpenMarlinDocumentation("sd-card");
    });

    AbstractPage::ConnectGuiSignalsAndSlots();
}

void SDCardPage::ResetValues()
{
    mIsLoading = true;

    mUi->uSdsupportBox->setChecked(defaults::SDSUPPORT);
    mUi->uSdCheckAndRetryBox->setChecked(defaults::SD_CHECK_AND_RETRY);

    mIsLoading = false;
}

bool SDCardPage::LoadFromJson(const QJsonObject &pJson)
{
    bool success = true;
    mIsLoading = true;

    success &= LoadConfig(mUi->uSdsupportBox, pJson, "SDSUPPORT");
    success &= LoadConfig(mUi->uSdCheckAndRetryBox, pJson, "SD_CHECK_AND_RETRY");

    mIsLoading = false;
    return success;
}

void SDCardPage::FetchConfiguration(Configuration& pConfig)
{
    SetConfig(pConfig.sdCard.SDSUPPORT, mUi->uSdsupportBox);
    SetConfig(pConfig.sdCard.SD_CHECK_AND_RETRY, mUi->uSdCheckAndRetryBox);
}

void SDCardPage::ReplaceTags(QStringList& pOutput)
{
    ReplaceTag(pOutput, "#{SDSUPPORT}", mUi->uSdsupportBox, "SDSUPPORT");
    ReplaceTag(pOutput, "#{SD_CHECK_AND_RETRY}", mUi->uSdCheckAndRetryBox, "SD_CHECK_AND_RETRY");
}
