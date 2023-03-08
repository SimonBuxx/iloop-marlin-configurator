/*!
 * \file HelperFunctions.h
 * \brief Contains global helper functions
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

#ifndef HELPERFUNCTIONS_H
#define HELPERFUNCTIONS_H

#include <QString>
#include <QJsonObject>
#include "Dropdown.h"
#include <QGroupBox>
#include <QLineEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QCheckBox>
#include <QDesktopServices>
#include <QFile>
#include <QFileInfo>

/// \brief Extracts the flag name inside the square brackets in pString
///
/// \param pString: The string to extract the flag name from
/// \return The flag name as a QString
/// \throws std::invalid_argument if pString does not contain square brackets
inline QString ExtractFlagNameInSquareBrackets(const QString& pString)
{
    const auto&& start = pString.indexOf('[');
    const auto&& end = pString.indexOf(']');

    if (start < 0 || end < 0)
    {
        throw std::invalid_argument("Parameter does not contain square brackets");
    }

    return pString.mid(start + 1, end - start - 1);
}

/// \brief Reads a configuration template into memory
///
/// \param pFileInfo: Location of the template file
/// \return The template as a QStringList, if successful
inline std::optional<QStringList> ReadTemplateFromFile(const QFileInfo& pFileInfo)
{
    QStringList stringList;
    QFile file(pFileInfo.filePath());

    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        return std::nullopt;
    }

    QTextStream textStream(&file);
    while (true)
    {
        QString line = textStream.readLine();
        if (line.isNull())
        {
            break;
        }
        else
        {
            stringList.append(line);
        }
    }

    file.close();

    return stringList;
}

/// \brief Sets the given line edit to the text given in the JSON object
///
/// \param pWidget: Pointer to the line edit
/// \param pJson: Reference to the JSON object containing the attribute
/// \param pAttribute: The name of the JSON attribute
/// \return \b true, if the JSON contains the parameter of type string
inline bool LoadConfig(QLineEdit* pWidget, const QJsonObject &pJson, const QString& pAttribute)
{
    if (pJson.contains(pAttribute) && pJson[pAttribute].isString())
    {
        pWidget->setText(pJson[pAttribute].toString());
        return true;
    }
    return false;
}

/// \brief Sets the given dropdown menu to the item that contains the given parameter
///
/// \param pWidget: Pointer to the dropdown menu
/// \param pJson: Reference to the JSON object containing the attribute
/// \param pAttribute: The name of the JSON attribute
/// \param pMatchItemInBrackets: If true, the widget is set to the item that contains the parameter in square brackets
/// \return \b true, if the JSON contains the parameter of type string and the widget contains a valid item
inline bool LoadConfig(Dropdown* pWidget, const QJsonObject &pJson, const QString& pAttribute, bool pMatchItemInBrackets = false)
{
    if (pJson.contains(pAttribute) && pJson[pAttribute].isString())
    {
        if (pMatchItemInBrackets)
        {
            const auto&& index = pWidget->findText(QString("[%0]").arg(pJson[pAttribute].toString()), Qt::MatchContains);
            if (index >= 0)
            {
                pWidget->setCurrentIndex(index);
                return true;
            }
        }
        else
        {
            pWidget->setCurrentText(pJson[pAttribute].toString());
            return true;
        }
    }
    return false;
}

/// \brief Sets the given widget (e.g. QSpinBox) to the value given in the JSON object
///
/// \param pWidget: Reference to the widget
/// \param pJson: Reference to the JSON object containing the attribute
/// \param pAttribute: The name of the JSON attribute
/// \return \b true, if the JSON contains the parameter of type double
template <typename T>
inline bool LoadConfig(T& pWidget, const QJsonObject &pJson, const QString& pAttribute)
{
    if (pJson.contains(pAttribute) && pJson[pAttribute].isDouble())
    {
        pWidget->setValue(pJson[pAttribute].toInt());
        return true;
    }
    return false;
}

/// \brief Sets the given QDoubleSpinBox to the value given in the JSON object
///
/// \param pWidget: Reference to the QDoubleSpinBox widget
/// \param pJson: Reference to the JSON object containing the attribute
/// \param pAttribute: The name of the JSON attribute
/// \return \b true, if the JSON contains the parameter of type double
inline bool LoadConfig(QDoubleSpinBox* pWidget, const QJsonObject &pJson, const QString& pAttribute)
{
    if (pJson.contains(pAttribute) && pJson[pAttribute].isDouble())
    {
        pWidget->setValue(pJson[pAttribute].toDouble());
        return true;
    }
    return false;
}

/// \brief Sets the given checkbox to the value given in the JSON object
///
/// \param pWidget: Pointer to the widget
/// \param pJson: Reference to the JSON object containing the attribute
/// \param pAttribute: The name of the JSON attribute
/// \return \b true, if the JSON contains the parameter of type bool
inline bool LoadConfig(QCheckBox* pWidget, const QJsonObject &pJson, const QString& pAttribute)
{
    if (pJson.contains(pAttribute) && pJson[pAttribute].isBool())
    {
        pWidget->setChecked(pJson[pAttribute].toBool());
        return true;
    }
    return false;
}

/// \brief Sets the given group box to the check value given in the JSON object
///
/// \param pWidget: Pointer to the widget
/// \param pJson: Reference to the JSON object containing the attribute
/// \param pAttribute: The name of the JSON attribute
/// \return \b true, if the JSON contains the parameter of type bool
inline bool LoadConfig(QGroupBox* pWidget, const QJsonObject &pJson, const QString& pAttribute)
{
    if (pJson.contains(pAttribute) && pJson[pAttribute].isBool())
    {
        pWidget->setChecked(pJson[pAttribute].toBool());
        return true;
    }
    return false;
}

/// \brief Sets the given string to the line edit's text
///
/// \param pConfigItem: Reference to the string to set
/// \param pWidget: Pointer to the widget
inline void SetConfig(QString& pConfigItem, const QLineEdit* pWidget)
{
    pConfigItem = pWidget->text();
}

/// \brief Sets the given string to the dropdown menu's item text
///
/// \param pConfigItem: Reference to the string to set
/// \param pWidget: Pointer to the widget
/// \param pUseItemInBrackets: If \b true, the flag name is extracted from the item text
inline void SetConfig(QString& pConfigItem, const Dropdown* pWidget, bool pUseItemInBrackets = false)
{
    if (pUseItemInBrackets)
    {
        pConfigItem = ExtractFlagNameInSquareBrackets(pWidget->currentText());
    }
    else
    {
        pConfigItem = pWidget->currentText();
    }
}

/// \brief Sets the given bool to the checkbox state
///
/// \param pConfigItem: Reference to the bool to set
/// \param pWidget: Pointer to the widget
inline void SetConfig(bool& pConfigItem, const QCheckBox* pWidget)
{
    pConfigItem = pWidget->isChecked();
}

/// \brief Sets the given bool to the group box check state
///
/// \param pConfigItem: Reference to the bool to set
/// \param pWidget: Pointer to the widget
inline void SetConfig(bool& pConfigItem, const QGroupBox* pWidget)
{
    Q_ASSERT(pWidget->isCheckable());
    pConfigItem = pWidget->isChecked();
}

/// \brief Sets the given integer to the widget's (e.g. QSpinBox) value
///
/// \param pConfigItem: Reference to the integer to set
/// \param pWidget: Reference to the widget
template <typename T>
inline void SetConfig(int32_t& pConfigItem, const T& pWidget)
{
    pConfigItem = pWidget->value();
}

/// \brief Sets the given double to the widget's (e.g. QDoubleSpinBox) value
///
/// \param pConfigItem: Reference to the double to set
/// \param pWidget: Reference to the widget
template <typename T>
inline void SetConfig(double& pConfigItem, const T& pWidget)
{
    pConfigItem = pWidget->value();
}

inline void ReplaceTag(QStringList& pOutput, const QString& pTagName, const Dropdown* pWidget, bool pCommentOut, const QString& pParam, bool pUseItemInBrackets = false)
{
    if (pUseItemInBrackets)
    {
        pOutput.replaceInStrings(pTagName, QString("%0#define %1 %2").arg((!pWidget->isEnabled() || pCommentOut) ? "//" : "", pParam, (!pWidget->isEnabled() || pCommentOut) ? "" : ExtractFlagNameInSquareBrackets(pWidget->currentText())));
    }
    else
    {
        pOutput.replaceInStrings(pTagName, QString("%0#define %1 %2").arg((!pWidget->isEnabled() || pCommentOut) ? "//" : "", pParam, (!pWidget->isEnabled() || pCommentOut) ? "" : pWidget->currentText()));
    }
}

inline void ReplaceTag(QStringList& pOutput, const QString& pTagName, const QCheckBox* pWidget, const QString& pParam)
{
    pOutput.replaceInStrings(pTagName, QString("%0#define %1").arg(pWidget->isChecked() && pWidget->isEnabled() ? "" : "//", pParam));
}

inline void ReplaceTag(QStringList& pOutput, const QString& pTagName, const QGroupBox* pWidget, const QString& pParam)
{
    Q_ASSERT(pWidget->isCheckable());
    pOutput.replaceInStrings(pTagName, QString("%0#define %1").arg(pWidget->isChecked() && pWidget->isEnabled() ? "" : "//", pParam));
}

inline void ReplaceTag(QStringList& pOutput, const QString& pTagName, const QLineEdit* pWidget, bool pCommentOut, const QString& pParam, bool pUseParentheses = false)
{
    pOutput.replaceInStrings(pTagName, QString(pUseParentheses ? "%0#define %1 \"%2\"" : "%0#define %1 %2").arg((!pWidget->isEnabled() || pCommentOut) ? "//" : "", pParam, (!pWidget->isEnabled() || pCommentOut) ? "" : pWidget->text()));
}

inline void ReplaceTag(QStringList& pOutput, const QString& pTagName, const QSpinBox* pWidget, bool pCommentOut, const QString& pParam)
{
    pOutput.replaceInStrings(pTagName, QString("%0#define %1 %2").arg((!pWidget->isEnabled() || pCommentOut) ? "//" : "", pParam, (!pWidget->isEnabled() || pCommentOut) ? "" : QString::number(pWidget->value())));
}

inline void ReplaceArrayTag(QStringList& pOutput, const QString& pTagName, bool pCommentOut, const QString& pParam, std::vector<int32_t> pVector, bool pEnabled = true)
{
    QString array = "{ ";
    for (int i = 0; i < pVector.size(); i++)
    {
        array.append(QString::number(pVector.at(i)));
        if (i < pVector.size() - 1)
        {
            array.append(", ");
        }
    }
    array.append(" }");
    pOutput.replaceInStrings(pTagName, QString("%0#define %1 %2").arg((!pEnabled || pCommentOut) ? "//" : "", pParam, (!pEnabled || pCommentOut) ? "" : array));
}

inline void ReplaceTag(QStringList& pOutput, const QString& pTagName, const QDoubleSpinBox* pWidget, bool pCommentOut, const QString& pParam, uint8_t pPrecision = 2, bool pIncludeF = false)
{
    const QString suffix = (pIncludeF && pWidget->isEnabled()) ? "f" : "";

    pOutput.replaceInStrings(pTagName, QString("%0#define %1 %2%3").arg((!pWidget->isEnabled() || pCommentOut) ? "//" : "", pParam, (!pWidget->isEnabled() || pCommentOut) ? "" : QString::number(pWidget->value(), 'f', pPrecision), suffix));
}

inline void OpenMarlinDocumentation(const QString& pChapterName)
{
    QDesktopServices::openUrl(QUrl(QString("https://marlinfw.org/docs/configuration/configuration.html#%0").arg(pChapterName)));
}

#endif // HELPERFUNCTIONS_H
