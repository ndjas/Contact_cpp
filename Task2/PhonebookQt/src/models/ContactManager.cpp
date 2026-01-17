#include "ContactManager.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDir>

ContactManager::ContactManager(const QString& filepath)
    : filepath(filepath)
{
    loadContacts();
}

bool ContactManager::loadContacts()
{
    QFile file(filepath);
    
    // Créer le fichier s'il n'existe pas
    if (!file.exists()) {
        QDir dir;
        dir.mkpath(QFileInfo(filepath).absolutePath());
        
        file.open(QIODevice::WriteOnly);
        file.write("[]");
        file.close();
        return true;
    }
    
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

bool ContactManager::saveContacts()
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

bool ContactManager::addContact(const Contact& contact)
{
    Contact newContact = contact;
    newContact.setId(getNextId());
    contacts.append(newContact);
    return saveContacts();
}

bool ContactManager::updateContact(const Contact& contact)
{
    int index = findIndexById(contact.getId());
    if (index == -1) {
        return false;
    }
    
    contacts[index] = contact;
    return saveContacts();
}

bool ContactManager::removeContact(int id)
{
    int index = findIndexById(id);
    if (index == -1) {
        return false;
    }
    
    contacts.removeAt(index);
    return saveContacts();
}

QVector<Contact> ContactManager::searchContacts(const QString& query) const
{
    if (query.isEmpty()) {
        return contacts;
    }
    
    QVector<Contact> results;
    QString lowerQuery = query.toLower();
    
    for (const auto& contact : contacts) {
        if (matchContact(contact, lowerQuery)) {
            results.append(contact);
        }
    }
    
    return results;
}

Contact* ContactManager::getContactById(int id)
{
    int index = findIndexById(id);
    return (index != -1) ? &contacts[index] : nullptr;
}

int ContactManager::getNextId() const
{
    int maxId = 0;
    for (const auto& contact : contacts) {
        if (contact.getId() > maxId) {
            maxId = contact.getId();
        }
    }
    return maxId + 1;
}

int ContactManager::findIndexById(int id) const
{
    for (int i = 0; i < contacts.size(); ++i) {
        if (contacts[i].getId() == id) {
            return i;
        }
    }
    return -1;
}

bool ContactManager::matchContact(const Contact& contact, const QString& query) const
{
    // Recherche dans nom, prénom, email
    if (contact.getName().toLower().contains(query) ||
        contact.getSurname().toLower().contains(query) ||
        contact.getEmail().toLower().contains(query)) {
        return true;
    }
    
    // Recherche dans les numéros
    for (const auto& num : contact.getNumbers()) {
        if (num.value.contains(query)) {
            return true;
        }
    }
    
    return false;
}
