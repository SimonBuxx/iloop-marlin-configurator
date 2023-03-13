/*!
 * \file LCDMenuItemsPage.cpp
/// \brief The LCDMenuItemsPage class represents the LCD menu items page
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

#include "LCDMenuItemsPage.h"
#include "./ui_LCDMenuItemsPage.h"
#include "HelperFunctions.h"

LCDMenuItemsPage::LCDMenuItemsPage(QWidget *pParent) :
    AbstractPage(LCD_MENU_ITEMS_TEMPLATE_PATH, pParent),
    mUi(new Ui::LCDMenuItemsPage)
{
    mUi->setupUi(this);
}

LCDMenuItemsPage::~LCDMenuItemsPage()
{
    delete mUi;
}

void LCDMenuItemsPage::ConnectGuiSignalsAndSlots()
{
    QObject::connect(mUi->uDocumentationButton, &QPushButton::clicked, this, [&]()
    {
        OpenMarlinDocumentation("lcd-menu-items");
    });

    AbstractPage::ConnectGuiSignalsAndSlots();
}

void LCDMenuItemsPage::ResetValues()
{
    mIsLoading = true;

    mIsLoading = false;
}

bool LCDMenuItemsPage::LoadFromJson(const QJsonObject &pJson)
{
    bool success = true;
    mIsLoading = true;

    mIsLoading = false;
    return success;
}

void LCDMenuItemsPage::FetchConfiguration(Configuration& pConfig)
{
}

void LCDMenuItemsPage::ReplaceTags(QStringList& pOutput)
{
}
