#ifndef JSONSTORAGE_H
#define JSONSTORAGE_H

#include "IStorage.h"
#include <QString>
#include <QVector>

class JSONStorage : public IStorage
{
public:
    JSONStorage(const QString& filepath = "./data/phonebook.json");
    ~JSONStorage() override;
    
    bool connect() override;
    bool disconnect() override;
    bool isConnected() const override { return connected; }
    
    QVector<Contact> loadAll() override;
    bool save(const Contact& contact) override;
    bool update(const Contact& contact) override;
    bool remove(int id) override;
    Contact* findById(int id) override;
    int getNextId() override;
    
    QString getStorageType() const override { return "JSON File"; }
    QString getConnectionInfo() const override { return filepath; }
    
private:
    QString filepath;
    QVector<Contact> contacts;
    bool connected;
    
    bool loadFromFile();
    bool saveToFile();
    int findIndexById(int id) const;
};

#endif // JSONSTORAGE_H
