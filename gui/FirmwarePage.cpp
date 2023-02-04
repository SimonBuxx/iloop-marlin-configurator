#include "FirmwarePage.h"
#include "./ui_FirmwarePage.h"
#include "HelperFunctions.h"

#include <QStyledItemDelegate>
#include <QAbstractItemView>

FirmwarePage::FirmwarePage(QWidget *parent) :
    QWidget(parent),
    mUi(new Ui::FirmwarePage)
{
    mUi->setupUi(this);

    ResetValues();
}

FirmwarePage::~FirmwarePage()
{
    delete mUi;
}

void FirmwarePage::ResetValues()
{
    mUi->uAuthorNameEdit->setText(defaults::STRING_CONFIG_H_AUTHOR);
    mUi->uCustomVersionFileEdit->setText(defaults::CUSTOM_VERSION_FILE);
    mUi->uShowBootscreenCheckBox->setChecked(defaults::SHOW_BOOTSCREEN);
    mUi->uShowCustomBootscreenCheckBox->setChecked(defaults::SHOW_CUSTOM_BOOTSCREEN);
    mUi->uCustomStatusScreenImageCheckBox->setChecked(defaults::CUSTOM_STATUS_SCREEN_IMAGE);
}

bool FirmwarePage::LoadFromJson(const QJsonObject &pJson)
{
    bool success = true;
    success &= LoadStringToLineEdit(mUi->uAuthorNameEdit, pJson, "STRING_CONFIG_H_AUTHOR");
    success &= LoadStringToLineEdit(mUi->uCustomVersionFileEdit, pJson, "CUSTOM_VERSION_FILE");
    success &= LoadBool(mUi->uShowBootscreenCheckBox, pJson, "SHOW_BOOTSCREEN");
    success &= LoadBool(mUi->uShowCustomBootscreenCheckBox, pJson, "SHOW_CUSTOM_BOOTSCREEN");
    success &= LoadBool(mUi->uCustomStatusScreenImageCheckBox, pJson, "CUSTOM_STATUS_SCREEN_IMAGE");

    return success;
}

void FirmwarePage::FetchConfiguration(Configuration& pConfig)
{
    pConfig.firmware.STRING_CONFIG_H_AUTHOR = mUi->uAuthorNameEdit->text();
    pConfig.firmware.CUSTOM_VERSION_FILE = mUi->uCustomVersionFileEdit->text();
    pConfig.firmware.SHOW_BOOTSCREEN = mUi->uShowBootscreenCheckBox->isChecked();
    pConfig.firmware.SHOW_CUSTOM_BOOTSCREEN = mUi->uShowCustomBootscreenCheckBox->isChecked();
    pConfig.firmware.CUSTOM_STATUS_SCREEN_IMAGE = mUi->uCustomStatusScreenImageCheckBox->isChecked();
}
