/*!
 * \file AbstractPage.cpp
 * \brief The AbstractPage class respresents a configuration page
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

#include "AbstractPage.h"
#include "HelperFunctions.h"

#include <QGroupBox>
#include <QLineEdit>
#include <QComboBox>
#include <QSpinBox>
#include <QFileInfo>

AbstractPage::AbstractPage(const QString& pTemplatePath, QWidget *pParent) :
    QWidget(pParent)
{
    mTemplate = ReadTemplateFromFile(QFileInfo(pTemplatePath));
}

void AbstractPage::Init()
{
    ConnectGuiSignalsAndSlots();
    ResetValues();
}

void AbstractPage::ConnectGuiSignalsAndSlots()
{
    for (auto&& groupBox : findChildren<QGroupBox*>())
    {
        QObject::connect(groupBox, &QGroupBox::toggled, this, &AbstractPage::OnUpdatePreview);
    }

    for (auto&& lineEdit : findChildren<QLineEdit*>())
    {
        QObject::connect(lineEdit, &QLineEdit::textChanged, this, &AbstractPage::OnUpdatePreview);
    }

    for (auto&& comboBox : findChildren<QComboBox*>())
    {
        QObject::connect(comboBox, &QComboBox::currentIndexChanged, this, &AbstractPage::OnUpdatePreview);
    }

    for (auto&& spinBox : findChildren<QSpinBox*>())
    {
        QObject::connect(spinBox, &QSpinBox::valueChanged, this, &AbstractPage::OnUpdatePreview);
    }

    for (auto&& spinBox : findChildren<QDoubleSpinBox*>())
    {
        QObject::connect(spinBox, &QDoubleSpinBox::valueChanged, this, &AbstractPage::OnUpdatePreview);
    }
}

void AbstractPage::OnUpdatePreview()
{
    if (mIsLoading)
    {
        return;
    }

    if (mTemplate.has_value())
    {
        QStringList output = mTemplate.value();

        ReplaceTags(output);
        emit UpdatePreviewSignal(output);
    }
    else
    {
        emit UpdatePreviewSignal(QStringList()); // Set to placeholder text
    }
}
