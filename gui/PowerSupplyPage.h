#ifndef POWERSUPPLYPAGE_H
#define POWERSUPPLYPAGE_H

#include "../Configuration.h"
#include <QWidget>

namespace Ui {
class PowerSupplyPage;
}

class PowerSupplyPage : public QWidget
{
    Q_OBJECT

public:
    explicit PowerSupplyPage(QWidget *parent = nullptr);
    ~PowerSupplyPage(void) override;

    void ResetValues(void);

    bool LoadFromJson(const QJsonObject &pJson);

    void FetchConfiguration(Configuration& pConfig);

protected:
    Ui::PowerSupplyPage *mUi;
};

#endif // POWERSUPPLYPAGE_H
