#ifndef ISTORAGE_H
#define ISTORAGE_H

#include <QVector>
#include "../models/Contact.h"

// Interface abstraite pour le stockage
class IStorage
{
public:
    virtual ~IStorage() {}
    
    // Opérations CRUD
    virtual bool connect() = 0;
    virtual bool disconnect() = 0;
    virtual bool isConnected() const = 0;
    
    virtual QVector<Contact> loadAll() = 0;
    virtual bool save(const Contact& contact) = 0;
    virtual bool update(const Contact& contact) = 0;
    virtual bool remove(int id) = 0;
    virtual Contact* findById(int id) = 0;
    virtual int getNextId() = 0;
    
    // Métadonnées
    virtual QString getStorageType() const = 0;
    virtual QString getConnectionInfo() const = 0;
};

#endif // ISTORAGE_H
