/*!
 * \file FirmwarePage.h
/// \brief The FirmwarePage class represents the firmware page
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

#ifndef FIRMWAREPAGE_H
#define FIRMWAREPAGE_H

#include "Configuration.h"
#include <QWidget>

// Forward declarations
namespace Ui {
class FirmwarePage;
}

///
/// \brief The FirmwarePage class represents the firmware page
///
class FirmwarePage : public QWidget
{
    Q_OBJECT

public:
    /// \brief Constructor for the page widget
    ///
    /// \param pParent: Reference to the parent widget
    explicit FirmwarePage(QWidget *pParent = nullptr);

    /// \brief Destructor for the page widget
    ~FirmwarePage(void) override;

    /// \brief Resets all parameters on the page to their defaults
    void ResetValues(void);

    /// \brief Loads the page parameters from the given JSON object
    ///
    /// \param pJson: Reference to the JSON object
    /// \return \b true, if all expected parameters where found in the JSON
    bool LoadFromJson(const QJsonObject &pJson);

    /// \brief Writes the page parameters into the given Configuration object
    ///
    /// \param pConfig: Reference to the configuration object to write into
    void FetchConfiguration(Configuration& pConfig);

protected:
    Ui::FirmwarePage *mUi;
};

#endif // FIRMWAREPAGE_H
