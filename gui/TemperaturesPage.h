#ifndef TEMPERATURESPAGE_H
#define TEMPERATURESPAGE_H

#include "HotendTempSensorsConfigurator.h"
#include <QWidget>

namespace Ui {
class TemperaturesPage;
}

class TemperaturesPage : public QWidget
{
    Q_OBJECT

public:
    explicit TemperaturesPage(QWidget *parent = nullptr);
    ~TemperaturesPage(void) override;

    void ResetValues(void);

    void LoadFromJson(QJsonDocument &pJson);

protected:
    Ui::TemperaturesPage *ui;

    HotendTempSensorsConfigurator mHotendTempSensorsConfigurator;
};

#endif // TEMPERATURESPAGE_H
