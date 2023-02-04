#ifndef HOTENDTEMPSENSORSCONFIGURATOR_H
#define HOTENDTEMPSENSORSCONFIGURATOR_H

#include <QDialog>

namespace Ui {
class HotendTempSensorsConfigurator;
}

class HotendTempSensorsConfigurator : public QDialog
{
    Q_OBJECT

public:
    explicit HotendTempSensorsConfigurator(QWidget *parent = nullptr);
    ~HotendTempSensorsConfigurator() override;

    void ResetValues();

private:
    Ui::HotendTempSensorsConfigurator *ui;
};

#endif // HOTENDTEMPSENSORSCONFIGURATOR_H
