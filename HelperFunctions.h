#ifndef HELPERFUNCTIONS_H
#define HELPERFUNCTIONS_H

#include <QString>

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

#endif // HELPERFUNCTIONS_H
