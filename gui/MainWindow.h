/*!
 * \file MainWindow.h
 * \brief The MainWindow class represents the main window of the software
 * \author Simon Buchholz
 * \copyright Copyright (c) 2023, Simon Buchholz
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFileInfo>
#include <QMainWindow>
#include <QLabel>

#include "AboutDialog.h"
#include "Configuration.h"

// Forward declarations
QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

///
/// \brief The MainWindow class represents the main window of the software
///
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    /// \brief Constructor for MainWindow
    ///
    /// \param pParent: Reference to the parent widget
    MainWindow(QWidget *pParent = nullptr);

    /// \brief Default destructor for MainWindow
    ~MainWindow(void) override;

    /// \brief Appends a log message to the logging widget
    ///
    /// \param pText: The text message to append to the logging widget
    /// \param pColorString: A CSS style color string, e.g. "rgb(100, 100, 100)"
    void Log(const QString& pText, const QString& pColorString = "white");

    /// \brief Fetches the current configuration as configured in the GUI widgets
    ///
    /// \return The current configuration as a Configuration object
    Configuration FetchConfiguration(void);

    /// \brief Setter for the project name on the GUI
    ///
    /// \param pName: The new project name to display or std::nullopt to display no name
    void SetProjectName(const std::optional<QString>& pName);

    bool LoadProject(const QJsonObject& pJson);

    void ReplaceTags(QStringList& pOutput);

    void JumpToFirstConfigTab(void);

    void ResetValues(void);

signals:
    /// \brief Emitted when a configuration should be exported as a C++ header file
    ///
    /// \param pFileInfo: File info of the target file
    /// \param pConfig: The configuration to export as a Configuration object
    void ExportConfigurationSignal(const QFileInfo& pFileInfo, const Configuration& pConfig);

    /// \brief Emitted when the current project should be saved
    ///
    /// \param pConfig: The configuration to save into the project
    /// \param pForceSaveAs: If \b true, the save dialog is always displayed
    void SaveProjectSignal(const Configuration& pConfig, bool pForceSaveAs = false);

    /// \brief Emitted when a new project is being initialized
    void NewProjectSignal(void);

    void OpenProjectSignal(void);

public slots:
    /// \brief Initializes a new project by resetting the configuration
    void OnNewProject(void);

protected:
    void ConnectGuiSignalsAndSlots(void);

    void UpdateActiveTabButtonColor(void);

    /// \brief Sets the content of the code preview widget to the given code string
    ///
    /// \param pPreviewCode: Reference to the code to display
    void OnUpdatePreview(const QStringList& pPreviewCode);

protected:
    Ui::MainWindow *mUi;
    AboutDialog mAboutDialog;

    QLabel mStatusLabel;
    QLabel mMarlinVersionLabel;

    int8_t mLastCheckedButton = -1;
};
#endif // MAINWINDOW_H
