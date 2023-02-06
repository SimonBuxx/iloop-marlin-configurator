#include "PowerSupplyPage.h"
#include "./ui_PowerSupplyPage.h"
#include "HelperFunctions.h"

#include <QStyledItemDelegate>
#include <QAbstractItemView>

PowerSupplyPage::PowerSupplyPage(QWidget *parent) :
    QWidget(parent),
    mUi(new Ui::PowerSupplyPage)
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

    QObject::connect(mUi->uPsuControlCheckBox, &QCheckBox::stateChanged, this, [&](auto pState)
    {
        mUi->uMksPwcCheckBox->setEnabled(pState > 0);
        mUi->uPsOffConfirmCheckBox->setEnabled(pState > 0);
        mUi->uPsOffSoundCheckBox->setEnabled(pState > 0);
        mUi->uPsuActiveStateComboBox->setEnabled(pState > 0);
        mUi->uPsuDefaultOffCheckBox->setEnabled(pState > 0);
        mUi->uPsuPowerUpDelayEdit->setEnabled(pState > 0);
        mUi->uLedPowerOffTimeoutEdit->setEnabled(pState > 0);
        mUi->uPowerOffTimerCheckBox->setEnabled(pState > 0);
        mUi->uPowerOffWaitForCooldownCheckBox->setEnabled(pState > 0);
        mUi->uPsuPowerUpCodeEdit->setEnabled(pState > 0);
        mUi->uPsuPowerOffCodeEdit->setEnabled(pState > 0);
        mUi->uAutoPowerControlCheckBox->setEnabled(pState > 0);

        mUi->uAutoPowerFansCheckBox->setEnabled(pState > 0 && mUi->uAutoPowerControlCheckBox->isChecked());
        mUi->uAutoPowerEFansCheckBox->setEnabled(pState > 0 && mUi->uAutoPowerControlCheckBox->isChecked());
        mUi->uAutoPowerControllerFanCheckBox->setEnabled(pState > 0 && mUi->uAutoPowerControlCheckBox->isChecked());
        mUi->uAutoPowerChamberFanCheckBox->setEnabled(pState > 0 && mUi->uAutoPowerControlCheckBox->isChecked());
        mUi->uAutoPowerCoolerFanCheckBox->setEnabled(pState > 0 && mUi->uAutoPowerControlCheckBox->isChecked());
        mUi->uPowerTimeoutEdit->setEnabled(pState > 0 && mUi->uAutoPowerControlCheckBox->isChecked());
        mUi->uPowerOffDelayEdit->setEnabled(pState > 0 && mUi->uAutoPowerControlCheckBox->isChecked());

        mUi->uAutoPowerETempEdit->setEnabled(pState > 0 && (mUi->uAutoPowerControlCheckBox->isChecked() || mUi->uPowerOffWaitForCooldownCheckBox->isChecked()));
        mUi->uAutoPowerChamberTempEdit->setEnabled(pState > 0 && (mUi->uAutoPowerControlCheckBox->isChecked() || mUi->uPowerOffWaitForCooldownCheckBox->isChecked()));
        mUi->uAutoPowerCoolerTempEdit->setEnabled(pState > 0 && (mUi->uAutoPowerControlCheckBox->isChecked() || mUi->uPowerOffWaitForCooldownCheckBox->isChecked()));
    });

    QObject::connect(mUi->uAutoPowerControlCheckBox, &QCheckBox::stateChanged, this, [&](auto pState)
    {
        mUi->uAutoPowerFansCheckBox->setEnabled(pState > 0);
        mUi->uAutoPowerEFansCheckBox->setEnabled(pState > 0);
        mUi->uAutoPowerControllerFanCheckBox->setEnabled(pState > 0);
        mUi->uAutoPowerChamberFanCheckBox->setEnabled(pState > 0);
        mUi->uAutoPowerCoolerFanCheckBox->setEnabled(pState > 0);
        mUi->uPowerTimeoutEdit->setEnabled(pState > 0);
        mUi->uPowerOffDelayEdit->setEnabled(pState > 0);

        mUi->uAutoPowerETempEdit->setEnabled(pState > 0 || mUi->uPowerOffWaitForCooldownCheckBox->isChecked());
        mUi->uAutoPowerChamberTempEdit->setEnabled(pState > 0 || mUi->uPowerOffWaitForCooldownCheckBox->isChecked());
        mUi->uAutoPowerCoolerTempEdit->setEnabled(pState > 0 || mUi->uPowerOffWaitForCooldownCheckBox->isChecked());
    });

    QObject::connect(mUi->uPowerOffWaitForCooldownCheckBox, &QCheckBox::stateChanged, this, [&](auto pState)
    {
                         mUi->uAutoPowerETempEdit->setEnabled(pState > 0 || mUi->uAutoPowerControlCheckBox->isChecked());
        mUi->uAutoPowerChamberTempEdit->setEnabled(pState > 0 || mUi->uAutoPowerControlCheckBox->isChecked());
        mUi->uAutoPowerCoolerTempEdit->setEnabled(pState > 0 || mUi->uAutoPowerControlCheckBox->isChecked());
    });

    ResetValues();

}

PowerSupplyPage::~PowerSupplyPage()
{
    delete mUi;
}

void PowerSupplyPage::ResetValues()
{
    mUi->uPsuControlCheckBox->setChecked(defaults::PSU_CONTROL);
    mUi->uPsuNameEdit->setText(defaults::PSU_NAME);
    mUi->uMksPwcCheckBox->setChecked(defaults::MKS_PWC);
    mUi->uPsOffConfirmCheckBox->setChecked(defaults::PS_OFF_CONFIRM);
    mUi->uPsOffSoundCheckBox->setChecked(defaults::PS_OFF_SOUND);
    mUi->uPsuActiveStateComboBox->setCurrentText(defaults::PSU_ACTIVE_STATE);
    mUi->uPsuDefaultOffCheckBox->setChecked(defaults::PSU_DEFAULT_OFF);
    mUi->uPsuPowerUpDelayEdit->setValue(defaults::PSU_POWERUP_DELAY);
    mUi->uLedPowerOffTimeoutEdit->setValue(defaults::LED_POWEROFF_TIMEOUT);
    mUi->uPowerOffTimerCheckBox->setChecked(defaults::POWER_OFF_TIMER);
    mUi->uPowerOffWaitForCooldownCheckBox->setChecked(defaults::POWER_OFF_WAIT_FOR_COOLDOWN);
    mUi->uPsuPowerUpCodeEdit->setText(defaults::PSU_POWERUP_GCODE);
    mUi->uPsuPowerOffCodeEdit->setText(defaults::PSU_POWEROFF_GCODE);
    mUi->uAutoPowerControlCheckBox->setChecked(defaults::AUTO_POWER_CONTROL);
    mUi->uAutoPowerFansCheckBox->setChecked(defaults::AUTO_POWER_FANS);
    mUi->uAutoPowerEFansCheckBox->setChecked(defaults::AUTO_POWER_E_FANS);
    mUi->uAutoPowerControllerFanCheckBox->setChecked(defaults::AUTO_POWER_CONTROLLERFAN);
    mUi->uAutoPowerChamberFanCheckBox->setChecked(defaults::AUTO_POWER_CHAMBER_FAN);
    mUi->uAutoPowerCoolerFanCheckBox->setChecked(defaults::AUTO_POWER_COOLER_FAN);
    mUi->uPowerTimeoutEdit->setValue(defaults::POWER_TIMEOUT);
    mUi->uPowerOffDelayEdit->setValue(defaults::POWER_OFF_DELAY);
    mUi->uAutoPowerETempEdit->setValue(defaults::AUTO_POWER_E_TEMP);
    mUi->uAutoPowerChamberTempEdit->setValue(defaults::AUTO_POWER_CHAMBER_TEMP);
    mUi->uAutoPowerCoolerTempEdit->setValue(defaults::AUTO_POWER_COOLER_TEMP);
}

bool PowerSupplyPage::LoadFromJson(const QJsonObject &pJson)
{
    bool success = true;

    success &= LoadBool(mUi->uPsuControlCheckBox, pJson, "PSU_CONTROL");
    success &= LoadStringToLineEdit(mUi->uPsuNameEdit, pJson, "PSU_NAME");
    success &= LoadBool(mUi->uMksPwcCheckBox, pJson, "MKS_PWC");
    success &= LoadBool(mUi->uPsOffConfirmCheckBox, pJson, "PS_OFF_CONFIRM");
    success &= LoadBool(mUi->uPsOffSoundCheckBox, pJson, "PS_OFF_SOUND");
    success &= LoadStringToComboBox(mUi->uPsuActiveStateComboBox, pJson, "PSU_ACTIVE_STATE");
    success &= LoadBool(mUi->uPsuDefaultOffCheckBox, pJson, "PSU_DEFAULT_OFF");
    success &= LoadIntToSpinBox(mUi->uPsuPowerUpDelayEdit, pJson, "PSU_POWERUP_DELAY");
    success &= LoadIntToSpinBox(mUi->uLedPowerOffTimeoutEdit, pJson, "LED_POWEROFF_TIMEOUT");
    success &= LoadBool(mUi->uPowerOffTimerCheckBox, pJson, "POWER_OFF_TIMER");
    success &= LoadBool(mUi->uPowerOffWaitForCooldownCheckBox, pJson, "POWER_OFF_WAIT_FOR_COOLDOWN");
    success &= LoadStringToLineEdit(mUi->uPsuPowerUpCodeEdit, pJson, "PSU_POWERUP_GCODE");
    success &= LoadStringToLineEdit(mUi->uPsuPowerOffCodeEdit, pJson, "PSU_POWEROFF_GCODE");
    success &= LoadBool(mUi->uAutoPowerControlCheckBox, pJson, "AUTO_POWER_CONTROL");
    success &= LoadBool(mUi->uAutoPowerFansCheckBox, pJson, "AUTO_POWER_FANS");
    success &= LoadBool(mUi->uAutoPowerEFansCheckBox, pJson, "AUTO_POWER_E_FANS");
    success &= LoadBool(mUi->uAutoPowerControllerFanCheckBox, pJson, "AUTO_POWER_CONTROLLERFAN");
    success &= LoadBool(mUi->uAutoPowerChamberFanCheckBox, pJson, "AUTO_POWER_CHAMBER_FAN");
    success &= LoadBool(mUi->uAutoPowerCoolerFanCheckBox, pJson, "AUTO_POWER_COOLER_FAN");
    success &= LoadIntToSpinBox(mUi->uPowerTimeoutEdit, pJson, "POWER_TIMEOUT");
    success &= LoadIntToSpinBox(mUi->uPowerOffDelayEdit, pJson, "POWER_OFF_DELAY");
    success &= LoadIntToSpinBox(mUi->uAutoPowerETempEdit, pJson, "AUTO_POWER_E_TEMP");
    success &= LoadIntToSpinBox(mUi->uAutoPowerChamberTempEdit, pJson, "AUTO_POWER_CHAMBER_TEMP");
    success &= LoadIntToSpinBox(mUi->uAutoPowerCoolerTempEdit, pJson, "AUTO_POWER_COOLER_TEMP");

    return success;
}

void PowerSupplyPage::FetchConfiguration(Configuration& pConfig)
{
    pConfig.powerSupply.PSU_CONTROL = mUi->uPsuControlCheckBox->isChecked();
    pConfig.powerSupply.PSU_NAME = mUi->uPsuNameEdit->text();
    pConfig.powerSupply.MKS_PWC = mUi->uMksPwcCheckBox->isChecked();
    pConfig.powerSupply.PS_OFF_CONFIRM = mUi->uPsOffConfirmCheckBox->isChecked();
    pConfig.powerSupply.PS_OFF_SOUND = mUi->uPsOffSoundCheckBox->isChecked();
    pConfig.powerSupply.PSU_ACTIVE_STATE = mUi->uPsuActiveStateComboBox->currentText();
    pConfig.powerSupply.PSU_DEFAULT_OFF = mUi->uPsuDefaultOffCheckBox->isChecked();
    pConfig.powerSupply.PSU_POWERUP_DELAY = mUi->uPsuPowerUpDelayEdit->value();
    pConfig.powerSupply.LED_POWEROFF_TIMEOUT = mUi->uLedPowerOffTimeoutEdit->value();
    pConfig.powerSupply.POWER_OFF_TIMER = mUi->uPowerOffTimerCheckBox->isChecked();
    pConfig.powerSupply.POWER_OFF_WAIT_FOR_COOLDOWN = mUi->uPowerOffWaitForCooldownCheckBox->isChecked();
    pConfig.powerSupply.PSU_POWERUP_GCODE = mUi->uPsuPowerUpCodeEdit->text();
    pConfig.powerSupply.PSU_POWEROFF_GCODE = mUi->uPsuPowerOffCodeEdit->text();
    pConfig.powerSupply.AUTO_POWER_CONTROL = mUi->uAutoPowerControlCheckBox->isChecked();
    pConfig.powerSupply.AUTO_POWER_FANS = mUi->uAutoPowerFansCheckBox->isChecked();
    pConfig.powerSupply.AUTO_POWER_E_FANS = mUi->uAutoPowerEFansCheckBox->isChecked();
    pConfig.powerSupply.AUTO_POWER_CONTROLLERFAN = mUi->uAutoPowerControllerFanCheckBox->isChecked();
    pConfig.powerSupply.AUTO_POWER_CHAMBER_FAN = mUi->uAutoPowerChamberFanCheckBox->isChecked();
    pConfig.powerSupply.AUTO_POWER_COOLER_FAN = mUi->uAutoPowerCoolerFanCheckBox->isChecked();
    pConfig.powerSupply.POWER_TIMEOUT = mUi->uPowerTimeoutEdit->value();
    pConfig.powerSupply.POWER_OFF_DELAY = mUi->uPowerOffDelayEdit->value();
    pConfig.powerSupply.AUTO_POWER_E_TEMP = mUi->uAutoPowerETempEdit->value();
    pConfig.powerSupply.AUTO_POWER_CHAMBER_TEMP = mUi->uAutoPowerChamberTempEdit->value();
    pConfig.powerSupply.AUTO_POWER_COOLER_TEMP = mUi->uAutoPowerCoolerTempEdit->value();
}
