#ifndef FIRMWAREPAGE_H
#define FIRMWAREPAGE_H

#include "../Configuration.h"
#include <QWidget>

namespace Ui {
class FirmwarePage;
}

class FirmwarePage : public QWidget
{
    Q_OBJECT

public:
    explicit FirmwarePage(QWidget *parent = nullptr);
    ~FirmwarePage(void) override;

    void ResetValues(void);

    void LoadFromJson(QJsonDocument &pJson);

    void FetchConfiguration(Configuration& pConfig);

protected:
    Ui::FirmwarePage *mUi;
};

#endif // FIRMWAREPAGE_H
