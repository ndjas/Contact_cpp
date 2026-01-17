#ifndef CONTACTMANAGER_H
#define CONTACTMANAGER_H

#include <QVector>
#include <QString>
#include "Contact.h"
#include "../storage/IStorage.h"
#include "../storage/JSONStorage.h"
#include "../storage/PostgresStorage.h"

enum class StorageMode {
    JSON,
    PostgreSQL
};

class ContactManager
{
public:
    ContactManager();
    ~ContactManager();
    
    // Gestion du mode de stockage
    void setStorageMode(StorageMode mode);
    StorageMode getStorageMode() const { return currentMode; }
    
    // Configuration PostgreSQL
    void configurePostgres(const QString& host, int port, 
                          const QString& dbName,
                          const QString& user, 
                          const QString& password);
    
    // CRUD operations
    bool loadContacts();
    bool addContact(const Contact& contact);
    bool updateContact(const Contact& contact);
    bool removeContact(int id);
    
    // Recherche
    QVector<Contact> searchContacts(const QString& query) const;
    Contact* getContactById(int id);
    QVector<Contact> getAllContacts() const { return contacts; }
    
    // Informations de connexion
    QString getStorageInfo() const;
    QString getLastError() const;
    bool isConnected() const;
    
private:
    IStorage* storage;
    JSONStorage* jsonStorage;
    PostgresStorage* postgresStorage;
    StorageMode currentMode;
    QVector<Contact> contacts;
    
    void switchStorage();
    bool matchContact(const Contact& contact, const QString& query) const;
};

#endif // CONTACTMANAGER_H