#include "HotendTempSensorsConfigurator.h"
#include "ui_HotendTempSensorsConfigurator.h"

HotendTempSensorsConfigurator::HotendTempSensorsConfigurator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HotendTempSensorsConfigurator)
{
    ui->setupUi(this);
}

void HotendTempSensorsConfigurator::ResetValues()
{

}

HotendTempSensorsConfigurator::~HotendTempSensorsConfigurator()
{
    delete ui;
}
