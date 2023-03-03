/*!
 * \file FirmwarePage.cpp
/// \brief The FirmwarePage class represents the firmware page
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

#include "FirmwarePage.h"
#include "./ui_FirmwarePage.h"
#include "HelperFunctions.h"

FirmwarePage::FirmwarePage(QWidget *pParent) :
    AbstractPage(FIRMWARE_TEMPLATE_PATH, pParent),
    mUi(new Ui::FirmwarePage)
{
    mUi->setupUi(this);
}

FirmwarePage::~FirmwarePage()
{
    delete mUi;
}

void FirmwarePage::ConnectGuiSignalsAndSlots()
{
    QObject::connect(mUi->uDocumentationButton, &QPushButton::clicked, this, [&]()
    {
        OpenMarlinDocumentation("firmware-info");
    });

    AbstractPage::ConnectGuiSignalsAndSlots();
}

void FirmwarePage::ResetValues()
{
    mIsLoading = true;

    mUi->uAuthorNameEdit->setText(defaults::STRING_CONFIG_H_AUTHOR);
    mUi->uCustomVersionFileEdit->setText(defaults::CUSTOM_VERSION_FILE);
    mUi->uShowBootscreenBox->setChecked(defaults::SHOW_BOOTSCREEN);
    mUi->uShowCustomBootscreenBox->setChecked(defaults::SHOW_CUSTOM_BOOTSCREEN);
    mUi->uCustomStatusScreenImageBox->setChecked(defaults::CUSTOM_STATUS_SCREEN_IMAGE);

    mUi->uStringConfigHAuthorBox->setChecked(defaults::ENABLE_STRING_CONFIG_H_AUTHOR);
    mUi->uCustomVersionFileBox->setChecked(defaults::ENABLE_CUSTOM_VERSION_FILE);

    mIsLoading = false;
}

bool FirmwarePage::LoadFromJson(const QJsonObject &pJson)
{
    bool success = true;
    mIsLoading = true;

    success &= LoadConfig(mUi->uAuthorNameEdit, pJson, "STRING_CONFIG_H_AUTHOR");
    success &= LoadConfig(mUi->uCustomVersionFileEdit, pJson, "CUSTOM_VERSION_FILE");
    success &= LoadConfig(mUi->uShowBootscreenBox, pJson, "SHOW_BOOTSCREEN");
    success &= LoadConfig(mUi->uShowCustomBootscreenBox, pJson, "SHOW_CUSTOM_BOOTSCREEN");
    success &= LoadConfig(mUi->uCustomStatusScreenImageBox, pJson, "CUSTOM_STATUS_SCREEN_IMAGE");

    success &= LoadConfig(mUi->uStringConfigHAuthorBox, pJson, "ENABLE_STRING_CONFIG_H_AUTHOR");
    success &= LoadConfig(mUi->uCustomVersionFileBox, pJson, "ENABLE_CUSTOM_VERSION_FILE");

    mIsLoading = false;
    return success;
}

void FirmwarePage::FetchConfiguration(Configuration& pConfig)
{
    SetConfig(pConfig.firmware.STRING_CONFIG_H_AUTHOR, mUi->uAuthorNameEdit);
    SetConfig(pConfig.firmware.CUSTOM_VERSION_FILE, mUi->uCustomVersionFileEdit);
    SetConfig(pConfig.firmware.SHOW_BOOTSCREEN, mUi->uShowBootscreenBox);
    SetConfig(pConfig.firmware.SHOW_CUSTOM_BOOTSCREEN, mUi->uShowCustomBootscreenBox);
    SetConfig(pConfig.firmware.CUSTOM_STATUS_SCREEN_IMAGE, mUi->uCustomStatusScreenImageBox);

    SetConfig(pConfig.firmware.ENABLE_STRING_CONFIG_H_AUTHOR, mUi->uStringConfigHAuthorBox);
    SetConfig(pConfig.firmware.ENABLE_CUSTOM_VERSION_FILE, mUi->uCustomVersionFileBox);
}

void FirmwarePage::ReplaceTags(QStringList& pOutput)
{
    ReplaceTag(pOutput, "#{STRING_CONFIG_H_AUTHOR}", mUi->uAuthorNameEdit, !mUi->uStringConfigHAuthorBox->isChecked(), "STRING_CONFIG_H_AUTHOR", true);
    ReplaceTag(pOutput, "#{CUSTOM_VERSION_FILE}", mUi->uCustomVersionFileEdit, !mUi->uCustomVersionFileBox->isChecked(), "CUSTOM_VERSION_FILE");
    ReplaceTag(pOutput, "#{SHOW_BOOTSCREEN}", mUi->uShowBootscreenBox, "SHOW_BOOTSCREEN");
    ReplaceTag(pOutput, "#{SHOW_CUSTOM_BOOTSCREEN}", mUi->uShowCustomBootscreenBox, "SHOW_CUSTOM_BOOTSCREEN");
    ReplaceTag(pOutput, "#{CUSTOM_STATUS_SCREEN_IMAGE}", mUi->uCustomStatusScreenImageBox, "CUSTOM_STATUS_SCREEN_IMAGE");
}
