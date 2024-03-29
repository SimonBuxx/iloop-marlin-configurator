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
#include "AbstractPage.h"
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

    void CompilerLog(const std::optional<QString>& pPath, const QString& pText, const QString& pColorString = "white");

    /// \brief Fetches the current configuration as configured in the GUI widgets
    ///
    /// \return The current configuration as a Configuration object
    Configuration FetchConfiguration(void);

    /// \brief Setter for the project name on the GUI
    ///
    /// \param pName: The new project name to display or std::nullopt to display no name
    void SetWorkspace(const std::optional<QString>& pName);

    bool LoadConfigurationFromJson(const QJsonObject& pJson);

    void ReplaceTags(QStringList& pOutput);

    void JumpToFirstConfigTab(void);

    QString GetEnvironment(void) const;

    void ActivateCancelButton(void);
    void DeactivateCancelButton(void);
    bool IsBuildCanceled(void) const;

signals:
    /// \brief Emitted when the current configuration should be exported as a C++ header file
    void GenerateSignal(void);

    /// \brief Emitted when the current workspace configuration should be saved
    void SaveProjectSignal(void);

    /// \brief Emitted when the workspace is being closed
    void CloseWorkspaceSignal(void);

    void OpenWorkspaceSignal(void);

    void BuildMarlinSignal(void);
    void RebuildMarlinSignal(void);
    void CleanSignal(void);
    void UploadSignal(void);

public slots:
    /// \brief Closes the current workspace and resets the configuration
    void OnCloseWorkspace(void);

    void OnOpenWorkspace(void);

    void OnWorkspaceOpened(void);

    void OnResetConfiguration(void);

    void OnResetCurrentPage(void);

    void ResetValues(void);

protected slots:
    void OnSetDefaultViewport(void);

    void OnSetExpandedViewport(void);

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

    std::vector<AbstractPage*> mConfigPages;

    QLabel mStatusLabel;
    QLabel mMarlinVersionLabel;

    int8_t mLastCheckedButton = -1;

    bool mBuildCanceled = false;
};
#endif // MAINWINDOW_H
