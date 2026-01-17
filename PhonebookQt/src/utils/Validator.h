#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <QString>

class Validator
{
public:
    static bool isValidEmail(const QString& email);
    static bool isValidName(const QString& name);
    static bool isValidNumber(const QString& number);
    static bool isValidDate(const QString& dateStr);
    
private:
    static bool isLeapYear(int year);
};

#endif // VALIDATOR_H
