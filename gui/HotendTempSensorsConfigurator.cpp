#include "HotendTempSensorsConfigurator.h"
#include "ui_HotendTempSensorsConfigurator.h"

#include <QAbstractItemView>

HotendTempSensorsConfigurator::HotendTempSensorsConfigurator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HotendTempSensorsConfigurator)
{
    ui->setupUi(this);

#warning temporary code, subclass QComboBox
    for (const auto& comp : ui->frame->children())
    {
        if (nullptr != dynamic_cast<QComboBox*>(comp))
        {
            static_cast<QComboBox*>(comp)->view()->parentWidget()->setStyleSheet("background: rgb(54, 60, 70);");
        }
    }
}

void HotendTempSensorsConfigurator::ResetValues()
{
    ui->uTempSensor0Box->setCurrentIndex(5);
    ui->uTempSensor1Box->setCurrentIndex(5);
    ui->uTempSensor2Box->setCurrentIndex(3);
    ui->uTempSensor3Box->setCurrentIndex(3);
    ui->uTempSensor4Box->setCurrentIndex(3);
    ui->uTempSensor5Box->setCurrentIndex(3);
    ui->uTempSensor6Box->setCurrentIndex(3);
    ui->uTempSensor7Box->setCurrentIndex(3);
}

HotendTempSensorsConfigurator::~HotendTempSensorsConfigurator()
{
    delete ui;
}
