#ifndef HARDWAREPAGE_H
#define HARDWAREPAGE_H

#include "../Configuration.h"
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

    bool LoadFromJson(const QJsonObject &pJson);

    void FetchConfiguration(Configuration& pConfig);

protected:
    Ui::HardwarePage *mUi;
};

#endif // HARDWAREPAGE_H
