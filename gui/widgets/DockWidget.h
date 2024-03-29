/*!
 * \file DockWidget.h
 * \brief The DockWidget class represents a customized dock widget
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

#ifndef DOCKWIDGET_H
#define DOCKWIDGET_H

#include <QDockWidget>

///
/// \brief The DockWidget class represents a customized dock widget
///
class DockWidget : public QDockWidget
{
    Q_OBJECT
public:
    /// \brief Constructor for the dock widget menu
    ///
    /// \param pParent: Reference to the parent widget
    DockWidget(QWidget *pParent = nullptr);

    /// \brief Destructor for the dock widget menu
    ~DockWidget(void) override;

protected:
    /// \brief Sets the widget's border color to orange on focus
    ///
    /// \param pEvent: Pointer to the focus event
    void focusInEvent(QFocusEvent *pEvent) override;

    /// \brief Sets the widget's border color to black on focus leave
    ///
    /// \param pEvent: Pointer to the focus event
    void focusOutEvent(QFocusEvent *pEvent) override;
};

#endif // DOCKWIDGET_H
