#ifndef HARDWAREPAGE_H
#define HARDWAREPAGE_H

#include "../Configuration.h"
#include "Endstops_Configurator.h"
#include <QWidget>

namespace Ui {
class HardwarePage;
}

class HardwarePage : public QWidget
{
    Q_OBJECT

public:
    explicit HardwarePage(QWidget *parent = nullptr);
    ~HardwarePage(void) override;

    void ResetValues(void);

    void LoadFromJson(QJsonDocument &pJson);

    void FetchConfiguration(Configuration& pConfig);

protected:
    Ui::HardwarePage *mUi;

    Endstops_Configurator mEndstopsConfigurator;
};

#endif // HARDWAREPAGE_H
