#ifndef HELPERFUNCTIONS_H
#define HELPERFUNCTIONS_H

#include <QString>
#include <QJsonObject>

inline const std::optional<QString> ExtractFlagNameInSquareBrackets(const QString& pString)
{
    const auto&& start = pString.indexOf('[');
    const auto&& end = pString.indexOf(']');

    if (start < 0 || end < 0)
    {
        return std::nullopt;
    }

    return pString.mid(start + 1, end - start - 1);
}

template <typename T>
inline bool LoadStringToLineEdit(T& pWidget, const QJsonObject &pJson, const QString& pAttribute)
{
    if (pJson.contains(pAttribute) && pJson[pAttribute].isString())
    {
        pWidget->setText(pJson[pAttribute].toString());
        return true;
    }
    return false;
}

template <typename T>
inline bool LoadStringToComboBox(T& pWidget, const QJsonObject &pJson, const QString& pAttribute)
{
    if (pJson.contains(pAttribute) && pJson[pAttribute].isString())
    {
        pWidget->setCurrentText(pJson[pAttribute].toString());
        return true;
    }
    return false;
}


template <typename T>
inline bool LoadBool(T& pWidget, const QJsonObject &pJson, const QString& pAttribute)
{
    if (pJson.contains(pAttribute) && pJson[pAttribute].isBool())
    {
        pWidget->setChecked(pJson[pAttribute].toBool());
        return true;
    }
    return false;
}

#endif // HELPERFUNCTIONS_H
