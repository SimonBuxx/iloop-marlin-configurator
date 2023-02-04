#include "Endstops_Configurator.h"
#include "ui_Endstops_Configurator.h"
#include "../Configuration.h"

Endstops_Configurator::Endstops_Configurator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Endstops_Configurator)
{
    ui->setupUi(this);
}

void Endstops_Configurator::ResetValues()
{
    ui->uUseXminPlug->setChecked(defaults::USE_XMIN_PLUG);
    ui->uUseYminPlug->setChecked(defaults::USE_YMIN_PLUG);
    ui->uUseZminPlug->setChecked(defaults::USE_ZMIN_PLUG);
    ui->uUseIminPlug->setChecked(defaults::USE_IMIN_PLUG);
    ui->uUseJminPlug->setChecked(defaults::USE_JMIN_PLUG);
    ui->uUseKminPlug->setChecked(defaults::USE_KMIN_PLUG);

    ui->uUseXmaxPlug->setChecked(defaults::USE_XMAX_PLUG);
    ui->uUseYmaxPlug->setChecked(defaults::USE_YMAX_PLUG);
    ui->uUseZmaxPlug->setChecked(defaults::USE_ZMAX_PLUG);
    ui->uUseImaxPlug->setChecked(defaults::USE_IMAX_PLUG);
    ui->uUseJmaxPlug->setChecked(defaults::USE_JMAX_PLUG);
    ui->uUseKmaxPlug->setChecked(defaults::USE_KMAX_PLUG);

    ui->uXminEndstopInverting->setChecked(defaults::X_MIN_ENDSTOP_INVERTING);
    ui->uYminEndstopInverting->setChecked(defaults::Y_MIN_ENDSTOP_INVERTING);
    ui->uZminEndstopInverting->setChecked(defaults::Z_MIN_ENDSTOP_INVERTING);
    ui->uIminEndstopInverting->setChecked(defaults::I_MIN_ENDSTOP_INVERTING);
    ui->uJminEndstopInverting->setChecked(defaults::J_MIN_ENDSTOP_INVERTING);
    ui->uKminEndstopInverting->setChecked(defaults::K_MIN_ENDSTOP_INVERTING);
    ui->uZminProbeEndstopInverting->setChecked(defaults::Z_MIN_PROBE_ENDSTOP_INVERTING);

    ui->uXmaxEndstopInverting->setChecked(defaults::X_MAX_ENDSTOP_INVERTING);
    ui->uYmaxEndstopInverting->setChecked(defaults::Y_MAX_ENDSTOP_INVERTING);
    ui->uZmaxEndstopInverting->setChecked(defaults::Z_MAX_ENDSTOP_INVERTING);
    ui->uImaxEndstopInverting->setChecked(defaults::I_MAX_ENDSTOP_INVERTING);
    ui->uJmaxEndstopInverting->setChecked(defaults::J_MAX_ENDSTOP_INVERTING);
    ui->uKmaxEndstopInverting->setChecked(defaults::K_MAX_ENDSTOP_INVERTING);
}

Endstops_Configurator::~Endstops_Configurator()
{
    delete ui;
}
