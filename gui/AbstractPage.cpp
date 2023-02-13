#include "AbstractPage.h"

#include <QGroupBox>
#include <QLineEdit>
#include <QComboBox>
#include <QSpinBox>

AbstractPage::AbstractPage(QWidget *pParent) :
    QWidget(pParent)
{
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
}

void AbstractPage::OnUpdatePreview()
{
    if (mTemplate.has_value())
    {
        QStringList output = mTemplate.value();

        ReplaceTags(output);
        emit UpdatePreviewSignal(output);
    }
    else
    {
        emit UpdatePreviewSignal(QStringList("Preview not available."));
    }
}
