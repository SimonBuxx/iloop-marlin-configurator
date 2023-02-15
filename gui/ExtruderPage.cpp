/*!
 * \file HardwarePage.cpp
 * \brief The HardwarePage class represents the hardware page
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

#include "ExtruderPage.h"
#include "./ui_ExtruderPage.h"
#include "HelperFunctions.h"

ExtruderPage::ExtruderPage(QWidget *pParent) :
    AbstractPage(EXTRUDER_TEMPLATE_PATH, pParent),
    mUi(new Ui::ExtruderPage)
{
    mUi->setupUi(this);
}

ExtruderPage::~ExtruderPage()
{
    delete mUi;
}

void ExtruderPage::ConnectGuiSignalsAndSlots()
{
    QObject::connect(mUi->uDocumentationButton, &QPushButton::clicked, this, [&]()
    {
        OpenMarlinDocumentation("extruder-info");
    });

    AbstractPage::ConnectGuiSignalsAndSlots();
}

void ExtruderPage::ResetValues()
{
    mUi->uExtrudersBox->setValue(defaults::EXTRUDERS);
}

bool ExtruderPage::LoadFromJson(const QJsonObject &pJson)
{
    bool success = true;

    success &= LoadConfig(mUi->uExtrudersBox, pJson, "EXTRUDERS");

    return success;
}

void ExtruderPage::FetchConfiguration(Configuration& pConfig)
{
    SetConfig(pConfig.extruder.EXTRUDERS, mUi->uExtrudersBox);
}

void ExtruderPage::ReplaceTags(QStringList& pOutput)
{
    ReplaceTag(pOutput, "#{EXTRUDERS}", mUi->uExtrudersBox, false, "EXTRUDERS");
}
