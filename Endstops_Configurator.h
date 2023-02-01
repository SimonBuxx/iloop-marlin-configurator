#ifndef ENDSTOPS_CONFIGURATOR_H
#define ENDSTOPS_CONFIGURATOR_H

#include <QDialog>

namespace Ui {
class Endstops_Configurator;
}

class Endstops_Configurator : public QDialog
{
    Q_OBJECT

public:
    explicit Endstops_Configurator(QWidget *parent = nullptr);
    ~Endstops_Configurator();

    void ResetValues();

private:
    Ui::Endstops_Configurator *ui;
};

#endif // ENDSTOPS_CONFIGURATOR_H
