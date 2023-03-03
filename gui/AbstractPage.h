/*!
 * \file AbstractPage.h
 * \brief The AbstractPage class respresents a configuration page
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

#ifndef ABSTRACTPAGE_H
#define ABSTRACTPAGE_H

#include "Configuration.h"

#include <QWidget>

///
/// \brief The AbstractPage class respresents a configuration page
///
class AbstractPage : public QWidget
{
    Q_OBJECT
public:
    /// \brief Constructor for the page widget
    ///
    /// \param pTemplatePath: Path to the code preview template
    /// \param pParent: Reference to the parent widget
    explicit AbstractPage(const QString& pTemplatePath, QWidget *pParent = nullptr);

    /// \brief Initializes the configuration page
    virtual void Init(void);

    /// \brief Resets all parameters on the page to their defaults
    virtual void ResetValues(void) = 0;

    /// \brief Loads the page parameters from the given JSON object
    ///
    /// \param pJson: Reference to the JSON object
    /// \return \b true, if all expected parameters where found in the JSON
    virtual bool LoadFromJson(const QJsonObject &pJson) = 0;

    /// \brief Writes the page parameters into the given Configuration object
    ///
    /// \param pConfig: Reference to the config to write into
    /// \return Configuration object
    virtual void FetchConfiguration(Configuration& pConfig) = 0;

    /// \brief Replaces the tags in the given text with the associated GUI states
    ///
    /// \param pOutput: Reference to the text to replace tags in
    virtual void ReplaceTags(QStringList& pOutput) = 0;

public slots:
    /// \brief Generates a code preview based on the template and GUI states and
    /// emits UpdatePreviewSignal with the code preview included
    virtual void OnUpdatePreview(void);

protected:
    /// \brief Connects this widget's signals and slots
    virtual void ConnectGuiSignalsAndSlots(void);

signals:
    /// \brief Emitted when the page requests a code preview update
    /// \param pOutput: The code preview text to display
    void UpdatePreviewSignal(const QStringList& pOutput);

protected:
    std::optional<QStringList> mTemplate;

    bool mIsLoading{false};
};

#endif // ABSTRACTPAGE_H
