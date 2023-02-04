#include "BasicsPage.h"
#include "./ui_BasicsPage.h"
#include "../HelperFunctions.h"
#include <QStyledItemDelegate>
#include <QAbstractItemView>

BasicsPage::BasicsPage(QWidget *parent) :
    QWidget(parent),
    mUi(new Ui::BasicsPage)
{
    mUi->setupUi(this);

#warning temporary code, subclass QComboBox
    for (const auto& comp : this->children())
    {
        if (nullptr != dynamic_cast<QComboBox*>(comp))
        {
            static_cast<QComboBox*>(comp)->view()->parentWidget()->setStyleSheet("background: rgb(54, 60, 70);");
        }
    }

    QObject::connect(mUi->uConfigureEndstopsButton, &QPushButton::clicked, &mEndstopsConfigurator, &Endstops_Configurator::show);

    ResetValues();
}

BasicsPage::~BasicsPage()
{
    delete mUi;
}

void BasicsPage::ResetValues()
{
    mUi->uAuthorNameEdit->setText(defaults::STRING_CONFIG_H_AUTHOR);
    mUi->uPrinterNameEdit->setText(defaults::CUSTOM_MACHINE_NAME);
    mUi->uBaudrateBox->setCurrentText(QString::number(defaults::BAUDRATE));
    mUi->uSerialPortBox->setCurrentText(QString::number(defaults::SERIAL_PORT));
    mUi->uExtrudersBox->setCurrentText(QString::number(defaults::EXTRUDERS));
    mUi->uFilamentDiaBox->setCurrentText(QString("%1 mm").arg(QString::number(defaults::DEFAULT_NOMINAL_FILAMENT_DIA, 'f', 2)));
    mUi->uMotherboardBox->setCurrentText(defaults::MOTHERBOARD);
    mUi->uLcdDisplayBox->setCurrentText(defaults::LCD_DISPLAY);
    mUi->uShowBootscreenTrue->setChecked(defaults::SHOW_BOOTSCREEN);
    mUi->uShowBootscreenFalse->setChecked(!defaults::SHOW_BOOTSCREEN);
    mUi->uXBedSizeBox->setValue(defaults::X_BED_SIZE);
    mUi->uYBedSizeBox->setValue(defaults::Y_BED_SIZE);

    mEndstopsConfigurator.ResetValues();
}

void BasicsPage::LoadFromJson(QJsonDocument &pJson)
{

}

void BasicsPage::FetchConfiguration(Configuration& pConfig)
{
    pConfig.SHOW_BOOTSCREEN = mUi->uShowBootscreenTrue->isChecked();
    pConfig.SERIAL_PORT = mUi->uSerialPortBox->currentText().toInt();
    pConfig.BAUDRATE = mUi->uBaudrateBox->currentText().toInt();
    pConfig.CUSTOM_MACHINE_NAME = mUi->uPrinterNameEdit->text();
    pConfig.STRING_CONFIG_H_AUTHOR = mUi->uAuthorNameEdit->text();
    pConfig.MOTHERBOARD = ExtractFlagNameInSquareBrackets(mUi->uMotherboardBox->currentText()).value_or("");
    pConfig.LCD_DISPLAY = mUi->uLcdDisplayBox->currentText();
    pConfig.EXTRUDERS = mUi->uExtrudersBox->currentText().toInt();
    pConfig.DEFAULT_NOMINAL_FILAMENT_DIA = mUi->uFilamentDiaBox->currentText().chopped(3).toDouble();
    pConfig.X_BED_SIZE = mUi->uXBedSizeBox->value();
    pConfig.Y_BED_SIZE = mUi->uYBedSizeBox->value();

    //pConfig.USE_XMIN_PLUG = mEndstopsConfigurator->FetchConfiguration(pConfig);
}
