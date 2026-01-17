#include "ContactManager.h"

ContactManager::ContactManager()
    : storage(nullptr),
    jsonStorage(new JSONStorage()),
    postgresStorage(new PostgresStorage()),
    currentMode(StorageMode::JSON)
{
    storage = jsonStorage;
    loadContacts();
}

ContactManager::~ContactManager()
{
    if (jsonStorage) delete jsonStorage;
    if (postgresStorage) delete postgresStorage;
}

void ContactManager::setStorageMode(StorageMode mode)
{
    if (currentMode == mode) {
        return;
    }

    currentMode = mode;
    switchStorage();
    loadContacts();
}

void ContactManager::configurePostgres(const QString& host, int port,
                                       const QString& dbName,
                                       const QString& user,
                                       const QString& password)
{
    postgresStorage->setConnectionParams(host, port, dbName, user, password);

    if (currentMode == StorageMode::PostgreSQL) {
        switchStorage();
        loadContacts();
    }
}

void ContactManager::switchStorage()
{
    if (storage) {
        storage->disconnect();
    }

    storage = (currentMode == StorageMode::JSON) ?
                  static_cast<IStorage*>(jsonStorage) :
                  static_cast<IStorage*>(postgresStorage);

    storage->connect();
}

bool ContactManager::loadContacts()
{
    if (!storage) {
        return false;
    }

    if (!storage->isConnected()) {
        storage->connect();
    }

    contacts = storage->loadAll();
    return true;
}

bool ContactManager::addContact(const Contact& contact)
{
    if (!storage || !storage->isConnected()) {
        return false;
    }

    bool result = storage->save(contact);
    if (result) {
        loadContacts();
    }
    return result;
}

bool ContactManager::updateContact(const Contact& contact)
{
    if (!storage || !storage->isConnected()) {
        return false;
    }

    bool result = storage->update(contact);
    if (result) {
        loadContacts();
    }
    return result;
}

bool ContactManager::removeContact(int id)
{
    if (!storage || !storage->isConnected()) {
        return false;
    }

    bool result = storage->remove(id);
    if (result) {
        loadContacts();
    }
    return result;
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
    if (!storage || !storage->isConnected()) {
        return nullptr;
    }

    return storage->findById(id);
}

QString ContactManager::getStorageInfo() const
{
    if (!storage) {
        return "No storage configured";
    }

    return QString("%1: %2")
        .arg(storage->getStorageType())
        .arg(storage->getConnectionInfo());
}

QString ContactManager::getLastError() const
{
    if (currentMode == StorageMode::PostgreSQL) {
        return postgresStorage->getLastError();
    }
    return "";
}

bool ContactManager::isConnected() const
{
    return storage && storage->isConnected();
}

bool ContactManager::matchContact(const Contact& contact, const QString& query) const
{
    if (contact.getName().toLower().contains(query) ||
        contact.getSurname().toLower().contains(query) ||
        contact.getEmail().toLower().contains(query)) {
        return true;
    }

    for (const auto& num : contact.getNumbers()) {
        if (num.value.contains(query)) {
            return true;
        }
    }

    return false;
}
