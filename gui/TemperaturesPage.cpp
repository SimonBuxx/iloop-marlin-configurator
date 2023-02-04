#include "TemperaturesPage.h"
#include "./ui_TemperaturesPage.h"

TemperaturesPage::TemperaturesPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TemperaturesPage)
{
    ui->setupUi(this);

    QObject::connect(ui->uConfigureHotendTempSensorsButton, &QPushButton::clicked, &mHotendTempSensorsConfigurator, &HotendTempSensorsConfigurator::show);

    ResetValues();
}

TemperaturesPage::~TemperaturesPage()
{
    delete ui;
}

void TemperaturesPage::ResetValues()
{
    mHotendTempSensorsConfigurator.ResetValues();
}

void TemperaturesPage::LoadFromJson(QJsonDocument &pJson)
{

}
