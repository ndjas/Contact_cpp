#include "JSONStorage.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDir>

JSONStorage::JSONStorage(const QString& filepath)
    : filepath(filepath), connected(false)
{
}

JSONStorage::~JSONStorage()
{
    disconnect();
}

bool JSONStorage::connect()
{
    QFile file(filepath);
    
    if (!file.exists()) {
        QDir dir;
        dir.mkpath(QFileInfo(filepath).absolutePath());
        
        file.open(QIODevice::WriteOnly);
        file.write("[]");
        file.close();
    }
    
    connected = loadFromFile();
    return connected;
}

bool JSONStorage::disconnect()
{
    if (connected) {
        saveToFile();
        contacts.clear();
        connected = false;
    }
    return true;
}

QVector<Contact> JSONStorage::loadAll()
{
    if (!connected) {
        connect();
    }
    return contacts;
}

bool JSONStorage::save(const Contact& contact)
{
    Contact newContact = contact;
    newContact.setId(getNextId());
    contacts.append(newContact);
    return saveToFile();
}

bool JSONStorage::update(const Contact& contact)
{
    int index = findIndexById(contact.getId());
    if (index == -1) {
        return false;
    }
    
    contacts[index] = contact;
    return saveToFile();
}

bool JSONStorage::remove(int id)
{
    int index = findIndexById(id);
    if (index == -1) {
        return false;
    }
    
    contacts.removeAt(index);
    return saveToFile();
}

Contact* JSONStorage::findById(int id)
{
    int index = findIndexById(id);
    return (index != -1) ? &contacts[index] : nullptr;
}

int JSONStorage::getNextId()
{
    int maxId = 0;
    for (const auto& contact : contacts) {
        if (contact.getId() > maxId) {
            maxId = contact.getId();
        }
    }
    return maxId + 1;
}

bool JSONStorage::loadFromFile()
{
    QFile file(filepath);
    
    if (!file.open(QIODevice::ReadOnly)) {
        return false;
    }
    
    QByteArray data = file.readAll();
    file.close();
    
    QJsonDocument doc = QJsonDocument::fromJson(data);
    
    if (!doc.isArray()) {
        return false;
    }
    
    contacts.clear();
    QJsonArray array = doc.array();
    
    for (const auto& value : array) {
        if (value.isObject()) {
            Contact contact(value.toObject());
            contacts.append(contact);
        }
    }
    
    return true;
}

bool JSONStorage::saveToFile()
{
    QJsonArray array;
    
    for (const auto& contact : contacts) {
        array.append(contact.toJson());
    }
    
    QJsonDocument doc(array);
    
    QFile file(filepath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        return false;
    }
    
    file.write(doc.toJson(QJsonDocument::Indented));
    file.close();
    
    return true;
}

int JSONStorage::findIndexById(int id) const
{
    for (int i = 0; i < contacts.size(); ++i) {
        if (contacts[i].getId() == id) {
            return i;
        }
    }
    return -1;
}
