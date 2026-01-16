#ifndef POSTGRESSTORAGE_H
#define POSTGRESSTORAGE_H

#include "IStorage.h"
#include <QSqlDatabase>
#include <QString>

class PostgresStorage : public IStorage
{
public:
    PostgresStorage(const QString& host = "localhost",
                   int port = 5432,
                   const QString& dbName = "phonebook_db",
                   const QString& user = "postgres",
                   const QString& password = "");
    ~PostgresStorage() override;
    
    bool connect() override;
    bool disconnect() override;
    bool isConnected() const override;
    
    QVector<Contact> loadAll() override;
    bool save(const Contact& contact) override;
    bool update(const Contact& contact) override;
    bool remove(int id) override;
    Contact* findById(int id) override;
    int getNextId() override;
    
    QString getStorageType() const override { return "PostgreSQL"; }
    QString getConnectionInfo() const override;
    
    // Configuration
    void setConnectionParams(const QString& host, int port, 
                           const QString& dbName, 
                           const QString& user, 
                           const QString& password);
    
    QString getLastError() const { return lastError; }
    
private:
    QSqlDatabase db;
    QString host;
    int port;
    QString dbName;
    QString user;
    QString password;
    QString lastError;
    Contact* cachedContact;
    
    bool createTables();
    bool savePhoneNumbers(int contactId, const QVector<PhoneNumber>& numbers);
    QVector<PhoneNumber> loadPhoneNumbers(int contactId);
    bool deletePhoneNumbers(int contactId);
};

#endif // POSTGRESSTORAGE_H
