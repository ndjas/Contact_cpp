#ifndef CONTACTMANAGER_H
#define CONTACTMANAGER_H

#include <QVector>
#include <QString>
#include "Contact.h"

class ContactManager
{
public:
    ContactManager(const QString& filepath = "./data/phonebook.json");
    
    // CRUD operations
    bool loadContacts();
    bool saveContacts();
    bool addContact(const Contact& contact);
    bool updateContact(const Contact& contact);
    bool removeContact(int id);
    
    // Recherche
    QVector<Contact> searchContacts(const QString& query) const;
    Contact* getContactById(int id);
    QVector<Contact>& getAllContacts() { return contacts; }
    const QVector<Contact>& getAllContacts() const { return contacts; }
    
    int getNextId() const;
    
private:
    QString filepath;
    QVector<Contact> contacts;
    
    int findIndexById(int id) const;
    bool matchContact(const Contact& contact, const QString& query) const;
};

#endif // CONTACTMANAGER_H
