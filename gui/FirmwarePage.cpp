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
    QWidget(pParent),
    mUi(new Ui::FirmwarePage)
{
    mUi->setupUi(this);

    ResetValues();
}

FirmwarePage::~FirmwarePage()
{
    delete mUi;
}

void FirmwarePage::ResetValues()
{
    mUi->uAuthorNameEdit->setText(defaults::STRING_CONFIG_H_AUTHOR);
    mUi->uCustomVersionFileEdit->setText(defaults::CUSTOM_VERSION_FILE);
    mUi->uShowBootscreenCheckBox->setChecked(defaults::SHOW_BOOTSCREEN);
    mUi->uShowCustomBootscreenCheckBox->setChecked(defaults::SHOW_CUSTOM_BOOTSCREEN);
    mUi->uCustomStatusScreenImageCheckBox->setChecked(defaults::CUSTOM_STATUS_SCREEN_IMAGE);
}

bool FirmwarePage::LoadFromJson(const QJsonObject &pJson)
{
    bool success = true;
    success &= LoadConfig(mUi->uAuthorNameEdit, pJson, "STRING_CONFIG_H_AUTHOR");
    success &= LoadConfig(mUi->uCustomVersionFileEdit, pJson, "CUSTOM_VERSION_FILE");
    success &= LoadConfig(mUi->uShowBootscreenCheckBox, pJson, "SHOW_BOOTSCREEN");
    success &= LoadConfig(mUi->uShowCustomBootscreenCheckBox, pJson, "SHOW_CUSTOM_BOOTSCREEN");
    success &= LoadConfig(mUi->uCustomStatusScreenImageCheckBox, pJson, "CUSTOM_STATUS_SCREEN_IMAGE");

    return success;
}

FirmwareConfiguration FirmwarePage::FetchConfiguration()
{
    FirmwareConfiguration config;

    SetConfig(config.STRING_CONFIG_H_AUTHOR, mUi->uAuthorNameEdit);
    SetConfig(config.CUSTOM_VERSION_FILE, mUi->uCustomVersionFileEdit);
    SetConfig(config.SHOW_BOOTSCREEN, mUi->uShowBootscreenCheckBox);
    SetConfig(config.SHOW_CUSTOM_BOOTSCREEN, mUi->uShowCustomBootscreenCheckBox);
    SetConfig(config.CUSTOM_STATUS_SCREEN_IMAGE, mUi->uCustomStatusScreenImageCheckBox);

    return config;
}

void FirmwarePage::ReplaceTags(QStringList& pOutput)
{
    ReplaceTag(pOutput, "#{STRING_CONFIG_H_AUTHOR}", mUi->uAuthorNameEdit, false, "STRING_CONFIG_H_AUTHOR", true);
    ReplaceTag(pOutput, "#{CUSTOM_VERSION_FILE}", mUi->uCustomVersionFileEdit, mUi->uCustomVersionFileEdit->text().isEmpty(), "CUSTOM_VERSION_FILE");
    ReplaceTag(pOutput, "#{SHOW_BOOTSCREEN}", mUi->uShowBootscreenCheckBox, "SHOW_BOOTSCREEN");
    ReplaceTag(pOutput, "#{SHOW_CUSTOM_BOOTSCREEN}", mUi->uShowCustomBootscreenCheckBox, "SHOW_CUSTOM_BOOTSCREEN");
    ReplaceTag(pOutput, "#{CUSTOM_STATUS_SCREEN_IMAGE}", mUi->uCustomStatusScreenImageCheckBox, "CUSTOM_STATUS_SCREEN_IMAGE");
}
