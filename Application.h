#ifndef APPLICATION_H
#define APPLICATION_H

#include <QFileInfo>
#include <QMessageBox>

#include "Configuration.h"
#include "MainWindow.h"

static constexpr auto TEMPLATE_PATH{":/resources/configuration_template.txt"};

class Application : public QObject
{
    Q_OBJECT
public:
    Application(QObject *parent = nullptr);

    ~Application(void) override;

protected slots:
    void OnExportConfiguration(const QFileInfo& pFileInfo, const Configuration& pConfig);

    void OnSaveProject(const Configuration& pConfig, bool pForceSaveAs = false);

    void OnNewProject(void);

protected:
    std::optional<QStringList> ReadConfigurationTemplateFromFile(const QFileInfo& pFileInfo);

    std::optional<QStringList> GenerateConfigurationContent(const Configuration& pConfig);

protected:
    MainWindow mMainWindow;

    std::optional<QStringList> mTemplate;
    std::optional<QFileInfo> mOpenFileInfo;
};

#endif // APPLICATION_H
