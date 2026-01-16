#include "Contact.h"
#include <QJsonArray>

Contact::Contact() : id(-1) {}

Contact::Contact(const QJsonObject& json)
{
    fromJson(json);
}

QString PhoneNumber::typeToString() const
{
    switch(type) {
        case NumberType::Home: return "Home";
        case NumberType::Personal: return "Personal";
        case NumberType::Work: return "Work";
        default: return "Unknown";
    }
}

NumberType PhoneNumber::stringToType(const QString& str)
{
    if (str == "home") return NumberType::Home;
    if (str == "work") return NumberType::Work;
    return NumberType::Personal;
}

QJsonObject Contact::toJson() const
{
    QJsonObject obj;
    obj["id"] = id;
    obj["name"] = name;
    obj["surname"] = surname;
    obj["patronym"] = patronym;
    obj["address"] = address;
    obj["born_date"] = bornDate;
    obj["email"] = email;
    
    QJsonObject numsObj;
    QJsonArray homeArray, personalArray, workArray;
    
    for (const auto& num : numbers) {
        switch(num.type) {
            case NumberType::Home:
                homeArray.append(num.value);
                break;
            case NumberType::Personal:
                personalArray.append(num.value);
                break;
            case NumberType::Work:
                workArray.append(num.value);
                break;
        }
    }
    
    numsObj["home"] = homeArray;
    numsObj["personnal"] = personalArray;
    numsObj["work"] = workArray;
    
    QJsonArray numeroArray;
    numeroArray.append(numsObj);
    obj["numero"] = numeroArray;
    
    return obj;
}

void Contact::fromJson(const QJsonObject& json)
{
    id = json["id"].toInt();
    name = json["name"].toString();
    surname = json["surname"].toString();
    patronym = json["patronym"].toString();
    address = json["address"].toString();
    bornDate = json["born_date"].toString();
    email = json["email"].toString();
    
    numbers.clear();
    
    if (json.contains("numero") && json["numero"].isArray()) {
        QJsonArray numeroArray = json["numero"].toArray();
        if (!numeroArray.isEmpty()) {
            QJsonObject numsObj = numeroArray[0].toObject();
            
            if (numsObj.contains("home")) {
                QJsonArray homeArray = numsObj["home"].toArray();
                for (const auto& val : homeArray) {
                    PhoneNumber num;
                    num.value = val.toString();
                    num.type = NumberType::Home;
                    numbers.append(num);
                }
            }
            
            if (numsObj.contains("personnal")) {
                QJsonArray personalArray = numsObj["personnal"].toArray();
                for (const auto& val : personalArray) {
                    PhoneNumber num;
                    num.value = val.toString();
                    num.type = NumberType::Personal;
                    numbers.append(num);
                }
            }
            
            if (numsObj.contains("work")) {
                QJsonArray workArray = numsObj["work"].toArray();
                for (const auto& val : workArray) {
                    PhoneNumber num;
                    num.value = val.toString();
                    num.type = NumberType::Work;
                    numbers.append(num);
                }
            }
        }
    }
}

QString Contact::getFullName() const
{
    QString fullName = name;
    if (!surname.isEmpty()) {
        fullName += " " + surname;
    }
    if (!patronym.isEmpty()) {
        fullName += " " + patronym;
    }
    return fullName;
}

QString Contact::getPrimaryPhone() const
{
    return numbers.isEmpty() ? "" : numbers.first().value;
}
