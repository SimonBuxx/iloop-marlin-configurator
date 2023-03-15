/*!
 * \file UserInterfaceLanguagePage.cpp
/// \brief The UserInterfaceLanguagePage class represents the user interface language page
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

#include "UserInterfaceLanguagePage.h"
#include "./ui_UserInterfaceLanguagePage.h"
#include "HelperFunctions.h"

#include <QToolButton>

UserInterfaceLanguagePage::UserInterfaceLanguagePage(QWidget *pParent) :
    AbstractPage(USER_INTERFACE_LANGUAGE_TEMPLATE_PATH, pParent),
    mUi(new Ui::UserInterfaceLanguagePage)
{
    mUi->setupUi(this);

    // Set the clear button icon of the search box
    mUi->uLanguageSearchBox->findChild<QToolButton*>()->setIcon(QIcon(":/close_FILL0_wght100_GRAD0_opsz20_white.svg"));
}

UserInterfaceLanguagePage::~UserInterfaceLanguagePage()
{
    delete mUi;
}

void UserInterfaceLanguagePage::ConnectGuiSignalsAndSlots()
{
    QObject::connect(mUi->uDocumentationButton, &QPushButton::clicked, this, [&]()
    {
        OpenMarlinDocumentation("user-interface-language");
    });

    QObject::connect(mUi->uLanguageSearchBox, &QLineEdit::textChanged, this, [&](const QString& pText){
        const auto& index = mUi->uLcdLanguageDropdown->findText(pText, Qt::MatchFlag::MatchContains);
        if (index >= 0 && !pText.isEmpty())
        {
            mUi->uLcdLanguageDropdown->setCurrentIndex(index);
        }
    });

    AbstractPage::ConnectGuiSignalsAndSlots();
}

void UserInterfaceLanguagePage::ResetValues()
{
    mIsLoading = true;

    mUi->uLcdLanguageDropdown->setCurrentText(defaults::LCD_LANGUAGE);
    mUi->uDisplayCharsetHd44780Dropdown->setCurrentText(defaults::DISPLAY_CHARSET_HD44780);
    mUi->uLcdInfoScreenStyleDropdown->setCurrentText(defaults::LCD_INFO_SCREEN_STYLE);

    mIsLoading = false;
}

bool UserInterfaceLanguagePage::LoadFromJson(const QJsonObject &pJson)
{
    bool success = true;
    mIsLoading = true;

    success &= LoadConfig(mUi->uLcdLanguageDropdown, pJson, "LCD_LANGUAGE");
    success &= LoadConfig(mUi->uDisplayCharsetHd44780Dropdown, pJson, "DISPLAY_CHARSET_HD44780");
    success &= LoadConfig(mUi->uLcdInfoScreenStyleDropdown, pJson, "LCD_INFO_SCREEN_STYLE");

    mIsLoading = false;
    return success;
}

void UserInterfaceLanguagePage::FetchConfiguration(Configuration& pConfig)
{
    SetConfig(pConfig.userInterfaceLanguage.LCD_LANGUAGE, mUi->uLcdLanguageDropdown);
    SetConfig(pConfig.userInterfaceLanguage.DISPLAY_CHARSET_HD44780, mUi->uDisplayCharsetHd44780Dropdown);
    SetConfig(pConfig.userInterfaceLanguage.LCD_INFO_SCREEN_STYLE, mUi->uLcdInfoScreenStyleDropdown);
}

void UserInterfaceLanguagePage::ReplaceTags(QStringList& pOutput)
{
    ReplaceTag(pOutput, "#{LCD_LANGUAGE}", mUi->uLcdLanguageDropdown, false, "LCD_LANGUAGE", true);
    ReplaceTag(pOutput, "#{DISPLAY_CHARSET_HD44780}", mUi->uDisplayCharsetHd44780Dropdown, false, "DISPLAY_CHARSET_HD44780");
    ReplaceTag(pOutput, "#{LCD_INFO_SCREEN_STYLE}", mUi->uLcdInfoScreenStyleDropdown, false, "LCD_INFO_SCREEN_STYLE", true);
}
