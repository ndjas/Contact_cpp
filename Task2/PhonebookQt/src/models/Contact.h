#ifndef CONTACT_H
#define CONTACT_H

#include <QString>
#include <QVector>
#include <QJsonObject>

enum class NumberType {
    Home,
    Personal,
    Work
};

struct PhoneNumber {
    QString value;
    NumberType type;
    
    QString typeToString() const;
    static NumberType stringToType(const QString& str);
};

class Contact
{
public:
    Contact();
    Contact(const QJsonObject& json);
    
    int getId() const { return id; }
    QString getName() const { return name; }
    QString getSurname() const { return surname; }
    QString getPatronym() const { return patronym; }
    QString getAddress() const { return address; }
    QString getBornDate() const { return bornDate; }
    QString getEmail() const { return email; }
    QVector<PhoneNumber> getNumbers() const { return numbers; }
    
    void setId(int id) { this->id = id; }
    void setName(const QString& name) { this->name = name; }
    void setSurname(const QString& surname) { this->surname = surname; }
    void setPatronym(const QString& patronym) { this->patronym = patronym; }
    void setAddress(const QString& address) { this->address = address; }
    void setBornDate(const QString& date) { this->bornDate = date; }
    void setEmail(const QString& email) { this->email = email; }
    void addNumber(const PhoneNumber& number) { numbers.append(number); }
    void setNumbers(const QVector<PhoneNumber>& nums) { numbers = nums; }
    
    QJsonObject toJson() const;
    void fromJson(const QJsonObject& json);
    
    QString getFullName() const;
    QString getPrimaryPhone() const;
    
private:
    int id;
    QString name;
    QString surname;
    QString patronym;
    QString address;
    QString bornDate;
    QString email;
    QVector<PhoneNumber> numbers;
};

#endif // CONTACT_H
