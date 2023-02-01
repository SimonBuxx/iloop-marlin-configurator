#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include <QFileDialog>
#include <QDateTime>
#include <QDesktopServices>

MainWindow::MainWindow(QWidget *pParent)
    : QMainWindow(pParent)
    , mUi(new Ui::MainWindow)
    , mAboutDialog(this)
{
    mUi->setupUi(this);

    ConnectGuiSignalsAndSlots();
}

MainWindow::~MainWindow()
{
    delete mUi;
}

void MainWindow::ConnectGuiSignalsAndSlots()
{
    QObject::connect(mUi->uCloseAction, &QAction::triggered, this, &QMainWindow::close);
    QObject::connect(mUi->uAboutAction, &QAction::triggered, &mAboutDialog, &AboutDialog::show);
    QObject::connect(mUi->uNewProjectAction, &QAction::triggered, this, &MainWindow::OnNewProject);

    QObject::connect(mUi->uExportAction, &QAction::triggered, this, [&]()
    {
        QString fileName = QFileDialog::getSaveFileName(this, tr("Export as..."), QDir::homePath() + "/Configuration.h", tr("C++ header (*.h)"));
        const auto config = FetchConfiguration();

        emit ExportConfigurationSignal(QFileInfo(fileName), config);
    });

    QObject::connect(mUi->uSaveProjectAction, &QAction::triggered, this, [&]()
    {
        const auto&& config = FetchConfiguration();
        emit SaveProjectSignal(config);
    });

    QObject::connect(mUi->uSaveProjectAsAction, &QAction::triggered, this, [&]()
    {
        const auto&& config = FetchConfiguration();
        emit SaveProjectSignal(config, true);
    });

    QObject::connect(mUi->uActionOpenGitHub, &QAction::triggered, this, [&]()
    {
        QDesktopServices::openUrl(QUrl("https://github.com/SimonBuxx/iloop-marlin-configurator/"));
    });

}

void MainWindow::OnNewProject()
{
    mUi->uBasicsPage->ResetValues();

    SetProjectName(std::nullopt);
    Log("New project initialized.");

    emit NewProjectSignal();
}

Configuration MainWindow::FetchConfiguration()
{
    Configuration config;

    mUi->uBasicsPage->FetchConfiguration(config);

    return config;
}

void MainWindow::SetProjectName(const std::optional<QString>& pName)
{
    mUi->uProjectLabel->setText(QString("Project: %0").arg(pName.value_or("-")));

    setWindowTitle(QString("%0iMC - iLOOP Marlin Configurator v0.1.0").arg(pName.has_value() ? pName.value() + " - " : ""));
}

void MainWindow::Log(const QString& pText, const QString& pColorString)
{
    const auto timestamp = QDateTime::currentDateTime().toString(Qt::DateFormat::ISODate).replace('T', ' ');

    mUi->uLogConsole->append(QString("<span style=\"color: rgb(100, 100, 100);\">[%0]</span> <span style=\"color: %1;\">%2</span>").arg(timestamp, pColorString, pText));
}
