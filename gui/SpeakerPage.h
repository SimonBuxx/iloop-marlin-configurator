/*!
 * \file SpeakerPage.h
/// \brief The SpeakerPage class represents the speaker page
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

#ifndef SPEAKERPAGE_H
#define SPEAKERPAGE_H

#include "Configuration.h"
#include "AbstractPage.h"

// Forward declarations
namespace Ui {
class SpeakerPage;
}

///
/// \brief The SpeakerPage class represents the speaker page
///
class SpeakerPage : public AbstractPage
{
    Q_OBJECT
public:
    /// \brief Constructor for the page widget
    ///
    /// \param pParent: Reference to the parent widget
    explicit SpeakerPage(QWidget *pParent = nullptr);

    /// \brief Destructor for the page widget
    ~SpeakerPage(void) override;

    /// \brief Resets all parameters on the page to their defaults
    void ResetValues(void) override;

    /// \brief Loads the page parameters from the given JSON object
    ///
    /// \param pJson: Reference to the JSON object
    /// \return \b true, if all expected parameters where found in the JSON
    bool LoadFromJson(const QJsonObject &pJson) override;

    /// \brief Writes the page parameters into the given Configuration object
    ///
    /// \param pConfig: Reference to the config to write into
    /// \return Configuration object
    void FetchConfiguration(Configuration& pConfig) override;

    /// \brief Replaces the tags in the given text with the associated GUI states
    ///
    /// \param pOutput: Reference to the text to replace tags in
    void ReplaceTags(QStringList& pOutput) override;

protected:
    /// \brief Connects this widget's signals and slots
    void ConnectGuiSignalsAndSlots(void) override;

protected:
    Ui::SpeakerPage *mUi;
};

#endif // SPEAKERPAGE_H
