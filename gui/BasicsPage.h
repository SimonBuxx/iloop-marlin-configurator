#ifndef BASICSPAGE_H
#define BASICSPAGE_H

#include "../Configuration.h"
#include "Endstops_Configurator.h"
#include <QWidget>

namespace Ui {
class BasicsPage;
}

class BasicsPage : public QWidget
{
    Q_OBJECT

public:
    explicit BasicsPage(QWidget *parent = nullptr);
    ~BasicsPage(void) override;

    void ResetValues(void);

    void LoadFromJson(QJsonDocument &pJson);

    void FetchConfiguration(Configuration& pConfig);

protected:
    Ui::BasicsPage *mUi;

    Endstops_Configurator mEndstopsConfigurator;
};

#endif // BASICSPAGE_H
