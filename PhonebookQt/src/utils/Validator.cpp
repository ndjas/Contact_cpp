#include "Validator.h"
#include <QRegularExpression>
#include <QDate>

bool Validator::isValidEmail(const QString& email)
{
    QRegularExpression regex(R"(\w+@\w+\.\w{2,4})");
    return regex.match(email).hasMatch();
}

bool Validator::isValidName(const QString& name)
{
    if (name.isEmpty()) return false;
    
    QRegularExpression regex(R"(^[^a-zA-Z0-9])");
    return !regex.match(name).hasMatch();
}

bool Validator::isValidNumber(const QString& number)
{
    QRegularExpression regex(
        R"(^(\+7|8)?[\s-]*\(?\d{3}\)?[\s-]*\d{3}[\s-]*\d{2}[\s-]*\d{2}$|^(\+7|8)?\s*\d{10}$)"
    );
    return regex.match(number).hasMatch();
}

bool Validator::isValidDate(const QString& dateStr)
{
    QDate date = QDate::fromString(dateStr, "dd-MM-yyyy");
    
    if (!date.isValid()) {
        return false;
    }
    
    // La date doit être dans le passé
    return date < QDate::currentDate();
}

bool Validator::isLeapYear(int year)
{
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}
