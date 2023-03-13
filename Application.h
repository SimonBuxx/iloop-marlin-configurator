/*!
 * \file Application.h
 * \brief The Application class represents the application
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

#ifndef APPLICATION_H
#define APPLICATION_H

#include "MainWindow.h"

#include <QFileInfo>

///
/// \brief The Application class represents the application
///
class Application : public QObject
{
    Q_OBJECT
public:
    /// \brief Constructor for Application
    ///
    /// \param pParent: Reference to the parent widget
    Application(QObject *pParent = nullptr);

    /// \brief Default destructor for Application
    ~Application(void) override;

protected slots:
    /// \brief Exports the current configuration
    void OnConfigure(void);

    /// \brief Saves the project either in the open location or asks for the file path
    void OnSaveProject(void);

    /// \brief Called when the current workspace is being closed
    void OnCloseWorkspace(void);

    void OnOpenWorkspace(void);

    void OnBuildMarlin(const QString& pEnvironment);

    void OnClean(const QString& pEnvironment);

protected:
    /// \brief Generates the Configuration.h file from the template
    ///
    /// \return The Configuration.h content as a QStringList, if successful
    std::optional<QStringList> GenerateCode(void);

    void OpenConfigurationJson(const QFileInfo& pFilePath);

protected:
    MainWindow mMainWindow;

    std::optional<QStringList> mTemplate;
    std::optional<QFileInfo> mOpenFileInfo;
    std::optional<QFileInfo> mFolderInfo;

    QString mCurrent;

    bool mBuildSuccess{false};

    bool mNewWorkspace{false};
};

#endif // APPLICATION_H
