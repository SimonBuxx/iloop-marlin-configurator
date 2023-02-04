#include "HardwarePage.h"
#include "./ui_HardwarePage.h"
#include "../HelperFunctions.h"
#include <QStyledItemDelegate>
#include <QAbstractItemView>

HardwarePage::HardwarePage(QWidget *parent) :
    QWidget(parent),
    mUi(new Ui::HardwarePage)
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

    QObject::connect(mUi->uSerialPort2ComboBox, &QComboBox::currentIndexChanged, this, [&](auto pIndex)
    {
        mUi->uBaudRate2ComboBox->setEnabled(pIndex > 0);
    });

    QObject::connect(mUi->uSerialPort3ComboBox, &QComboBox::currentIndexChanged, this, [&](auto pIndex)
    {
        mUi->uBaudRate3ComboBox->setEnabled(pIndex > 0);
    });

    ResetValues();
}

HardwarePage::~HardwarePage()
{
    delete mUi;
}

void HardwarePage::ResetValues()
{
    mUi->uMotherboardBox->setCurrentText(defaults::MOTHERBOARD);
    mUi->uSerialPortBox->setCurrentText(defaults::SERIAL_PORT);
    mUi->uBaudrateBox->setCurrentText(defaults::BAUDRATE);
    mUi->uBaudRateGCodeCheckBox->setChecked(defaults::BAUD_RATE_GCODE);
    mUi->uSerialPort2ComboBox->setCurrentText(defaults::SERIAL_PORT_2);
    mUi->uBaudRate2ComboBox->setCurrentText(defaults::BAUDRATE_2);
    mUi->uSerialPort3ComboBox->setCurrentText(defaults::SERIAL_PORT_3);
    mUi->uBaudRate3ComboBox->setCurrentText(defaults::BAUDRATE_3);
    mUi->uBluetoothCheckBox->setChecked(defaults::BLUETOOTH);
    mUi->uPrinterNameEdit->setText(defaults::CUSTOM_MACHINE_NAME);
    mUi->uMachineUuidEdit->setText(defaults::MACHINE_UUID);
}

bool HardwarePage::LoadFromJson(const QJsonObject &pJson)
{
    bool success = true;
    if (pJson.contains("MOTHERBOARD") && pJson["MOTHERBOARD"].isString())
    {
        const auto&& index = mUi->uMotherboardBox->findText(pJson["MOTHERBOARD"].toString(), Qt::MatchContains);
        mUi->uMotherboardBox->setCurrentIndex(index);
    }
    else
    {
        success = false;
    }

    success &= LoadStringToComboBox(mUi->uSerialPortBox, pJson, "SERIAL_PORT");
    success &= LoadStringToComboBox(mUi->uBaudrateBox, pJson, "BAUDRATE");
    success &= LoadBool(mUi->uBaudRateGCodeCheckBox, pJson, "BAUD_RATE_GCODE");
    success &= LoadStringToComboBox(mUi->uSerialPort2ComboBox, pJson, "SERIAL_PORT_2");
    success &= LoadStringToComboBox(mUi->uBaudRate2ComboBox, pJson, "BAUDRATE_2");
    success &= LoadStringToComboBox(mUi->uSerialPort3ComboBox, pJson, "SERIAL_PORT_3");
    success &= LoadStringToComboBox(mUi->uBaudRate3ComboBox, pJson, "BAUDRATE_3");
    success &= LoadBool(mUi->uBluetoothCheckBox, pJson, "BLUETOOTH");
    success &= LoadStringToLineEdit(mUi->uPrinterNameEdit, pJson, "CUSTOM_MACHINE_NAME");
    success &= LoadStringToLineEdit(mUi->uMachineUuidEdit, pJson, "MACHINE_UUID");

    return success;
}

void HardwarePage::FetchConfiguration(Configuration& pConfig)
{
    pConfig.hardware.MOTHERBOARD = ExtractFlagNameInSquareBrackets(mUi->uMotherboardBox->currentText()).value_or("");
    pConfig.hardware.SERIAL_PORT = mUi->uSerialPortBox->currentText();
    pConfig.hardware.BAUDRATE = mUi->uBaudrateBox->currentText();
    pConfig.hardware.BAUD_RATE_GCODE = mUi->uBaudRateGCodeCheckBox->isChecked();
    pConfig.hardware.SERIAL_PORT_2 = mUi->uSerialPort2ComboBox->currentText();
    pConfig.hardware.BAUDRATE_2 = mUi->uBaudRate2ComboBox->currentText();
    pConfig.hardware.SERIAL_PORT_3 = mUi->uSerialPort3ComboBox->currentText();
    pConfig.hardware.BAUDRATE_3 = mUi->uBaudRate3ComboBox->currentText();
    pConfig.hardware.BLUETOOTH = mUi->uBluetoothCheckBox->isChecked();
    pConfig.hardware.CUSTOM_MACHINE_NAME = mUi->uPrinterNameEdit->text();
    pConfig.hardware.MACHINE_UUID = mUi->uMachineUuidEdit->text();
}
