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

}

bool PowerSupplyPage::LoadFromJson(const QJsonObject &pJson)
{
    bool success = true;

    return success;
}

void PowerSupplyPage::FetchConfiguration(Configuration& pConfig)
{

}
