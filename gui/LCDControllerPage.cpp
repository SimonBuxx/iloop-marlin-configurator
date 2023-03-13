/*!
 * \file LCDControllerPage.cpp
/// \brief The LCDControllerPage class represents the LCD controller page
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

#include "LCDControllerPage.h"
#include "./ui_LCDControllerPage.h"
#include "HelperFunctions.h"

LCDControllerPage::LCDControllerPage(QWidget *pParent) :
    AbstractPage(LCD_CONTROLLER_TEMPLATE_PATH, pParent),
    mUi(new Ui::LCDControllerPage)
{
    mUi->setupUi(this);
}

LCDControllerPage::~LCDControllerPage()
{
    delete mUi;
}

void LCDControllerPage::ConnectGuiSignalsAndSlots()
{
    QObject::connect(mUi->uDocumentationButton, &QPushButton::clicked, this, [&]()
    {
        OpenMarlinDocumentation("lcd-controller");
    });

    AbstractPage::ConnectGuiSignalsAndSlots();
}

void LCDControllerPage::ResetValues()
{
    mIsLoading = true;

    mIsLoading = false;
}

bool LCDControllerPage::LoadFromJson(const QJsonObject &pJson)
{
    bool success = true;
    mIsLoading = true;

    mIsLoading = false;
    return success;
}

void LCDControllerPage::FetchConfiguration(Configuration& pConfig)
{
}

void LCDControllerPage::ReplaceTags(QStringList& pOutput)
{
}
