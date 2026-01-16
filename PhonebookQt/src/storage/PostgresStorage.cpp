#include "PostgresStorage.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

PostgresStorage::PostgresStorage(const QString& host, int port, 
                                 const QString& dbName,
                                 const QString& user, 
                                 const QString& password)
    : host(host), port(port), dbName(dbName), user(user), 
      password(password), cachedContact(nullptr)
{
    db = QSqlDatabase::addDatabase("QPSQL", "postgres_connection");
}

PostgresStorage::~PostgresStorage()
{
    disconnect();
    if (cachedContact) {
        delete cachedContact;
    }
}

void PostgresStorage::setConnectionParams(const QString& h, int p, 
                                         const QString& d, 
                                         const QString& u, 
                                         const QString& pwd)
{
    host = h;
    port = p;
    dbName = d;
    user = u;
    password = pwd;
}

bool PostgresStorage::connect()
{
    db.setHostName(host);
    db.setPort(port);
    db.setDatabaseName(dbName);
    db.setUserName(user);
    db.setPassword(password);
    
    if (!db.open()) {
        lastError = db.lastError().text();
        qWarning() << "PostgreSQL connection failed:" << lastError;
        return false;
    }
    
    if (!createTables()) {
        lastError = "Failed to create tables";
        return false;
    }
    
    return true;
}

bool PostgresStorage::disconnect()
{
    if (db.isOpen()) {
        db.close();
    }
    return true;
}

bool PostgresStorage::isConnected() const
{
    return db.isOpen();
}

QString PostgresStorage::getConnectionInfo() const
{
    return QString("%1:%2/%3 (user: %4)")
        .arg(host)
        .arg(port)
        .arg(dbName)
        .arg(user);
}

bool PostgresStorage::createTables()
{
    QSqlQuery query(db);
    
    // Table contacts
    QString createContactsTable = R"(
        CREATE TABLE IF NOT EXISTS contacts (
            id SERIAL PRIMARY KEY,
            name VARCHAR(255) NOT NULL,
            surname VARCHAR(255) NOT NULL,
            patronym VARCHAR(255),
            address VARCHAR(500),
            born_date VARCHAR(20),
            email VARCHAR(255) NOT NULL,
            created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
            updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
        )
    )";
    
    if (!query.exec(createContactsTable)) {
        lastError = query.lastError().text();
        qWarning() << "Failed to create contacts table:" << lastError;
        return false;
    }
    
    // Table phone_numbers
    QString createPhoneTable = R"(
        CREATE TABLE IF NOT EXISTS phone_numbers (
            id SERIAL PRIMARY KEY,
            contact_id INTEGER REFERENCES contacts(id) ON DELETE CASCADE,
            phone_number VARCHAR(20) NOT NULL,
            phone_type VARCHAR(20) NOT NULL,
            created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
        )
    )";
    
    if (!query.exec(createPhoneTable)) {
        lastError = query.lastError().text();
        qWarning() << "Failed to create phone_numbers table:" << lastError;
        return false;
    }
    
    // Index pour performances
    query.exec("CREATE INDEX IF NOT EXISTS idx_contact_id ON phone_numbers(contact_id)");
    query.exec("CREATE INDEX IF NOT EXISTS idx_email ON contacts(email)");
    
    return true;
}

QVector<Contact> PostgresStorage::loadAll()
{
    QVector<Contact> contacts;
    
    if (!isConnected()) {
        qWarning() << "Not connected to database";
        return contacts;
    }
    
    QSqlQuery query(db);
    query.prepare("SELECT id, name, surname, patronym, address, born_date, email FROM contacts ORDER BY id");
    
    if (!query.exec()) {
        lastError = query.lastError().text();
        qWarning() << "Failed to load contacts:" << lastError;
        return contacts;
    }
    
    while (query.next()) {
        Contact contact;
        contact.setId(query.value(0).toInt());
        contact.setName(query.value(1).toString());
        contact.setSurname(query.value(2).toString());
        contact.setPatronym(query.value(3).toString());
        contact.setAddress(query.value(4).toString());
        contact.setBornDate(query.value(5).toString());
        contact.setEmail(query.value(6).toString());
        
        // Charger les numéros de téléphone
        contact.setNumbers(loadPhoneNumbers(contact.getId()));
        
        contacts.append(contact);
    }
    
    return contacts;
}

bool PostgresStorage::save(const Contact& contact)
{
    if (!isConnected()) {
        lastError = "Not connected to database";
        return false;
    }
    
    QSqlQuery query(db);
    query.prepare(R"(
        INSERT INTO contacts (name, surname, patronym, address, born_date, email)
        VALUES (:name, :surname, :patronym, :address, :born_date, :email)
        RETURNING id
    )");
    
    query.bindValue(":name", contact.getName());
    query.bindValue(":surname", contact.getSurname());
    query.bindValue(":patronym", contact.getPatronym());
    query.bindValue(":address", contact.getAddress());
    query.bindValue(":born_date", contact.getBornDate());
    query.bindValue(":email", contact.getEmail());
    
    if (!query.exec()) {
        lastError = query.lastError().text();
        qWarning() << "Failed to save contact:" << lastError;
        return false;
    }
    
    if (query.next()) {
        int newId = query.value(0).toInt();
        return savePhoneNumbers(newId, contact.getNumbers());
    }
    
    return false;
}

bool PostgresStorage::update(const Contact& contact)
{
    if (!isConnected()) {
        lastError = "Not connected to database";
        return false;
    }
    
    QSqlQuery query(db);
    query.prepare(R"(
        UPDATE contacts 
        SET name = :name, surname = :surname, patronym = :patronym,
            address = :address, born_date = :born_date, email = :email,
            updated_at = CURRENT_TIMESTAMP
        WHERE id = :id
    )");
    
    query.bindValue(":id", contact.getId());
    query.bindValue(":name", contact.getName());
    query.bindValue(":surname", contact.getSurname());
    query.bindValue(":patronym", contact.getPatronym());
    query.bindValue(":address", contact.getAddress());
    query.bindValue(":born_date", contact.getBornDate());
    query.bindValue(":email", contact.getEmail());
    
    if (!query.exec()) {
        lastError = query.lastError().text();
        qWarning() << "Failed to update contact:" << lastError;
        return false;
    }
    
    // Mettre à jour les numéros
    deletePhoneNumbers(contact.getId());
    return savePhoneNumbers(contact.getId(), contact.getNumbers());
}

bool PostgresStorage::remove(int id)
{
    if (!isConnected()) {
        lastError = "Not connected to database";
        return false;
    }
    
    QSqlQuery query(db);
    query.prepare("DELETE FROM contacts WHERE id = :id");
    query.bindValue(":id", id);
    
    if (!query.exec()) {
        lastError = query.lastError().text();
        qWarning() << "Failed to delete contact:" << lastError;
        return false;
    }
    
    return true;
}

Contact* PostgresStorage::findById(int id)
{
    if (!isConnected()) {
        return nullptr;
    }
    
    QSqlQuery query(db);
    query.prepare("SELECT id, name, surname, patronym, address, born_date, email FROM contacts WHERE id = :id");
    query.bindValue(":id", id);
    
    if (!query.exec() || !query.next()) {
        return nullptr;
    }
    
    if (cachedContact) {
        delete cachedContact;
    }
    
    cachedContact = new Contact();
    cachedContact->setId(query.value(0).toInt());
    cachedContact->setName(query.value(1).toString());
    cachedContact->setSurname(query.value(2).toString());
    cachedContact->setPatronym(query.value(3).toString());
    cachedContact->setAddress(query.value(4).toString());
    cachedContact->setBornDate(query.value(5).toString());
    cachedContact->setEmail(query.value(6).toString());
    cachedContact->setNumbers(loadPhoneNumbers(id));
    
    return cachedContact;
}

int PostgresStorage::getNextId()
{
    if (!isConnected()) {
        return -1;
    }
    
    QSqlQuery query(db);
    query.exec("SELECT COALESCE(MAX(id), 0) + 1 FROM contacts");
    
    if (query.next()) {
        return query.value(0).toInt();
    }
    
    return 1;
}

bool PostgresStorage::savePhoneNumbers(int contactId, const QVector<PhoneNumber>& numbers)
{
    QSqlQuery query(db);
    query.prepare(R"(
        INSERT INTO phone_numbers (contact_id, phone_number, phone_type)
        VALUES (:contact_id, :phone_number, :phone_type)
    )");
    
    for (const auto& num : numbers) {
        query.bindValue(":contact_id", contactId);
        query.bindValue(":phone_number", num.value);
        query.bindValue(":phone_type", num.typeToString().toLower());
        
        if (!query.exec()) {
            lastError = query.lastError().text();
            qWarning() << "Failed to save phone number:" << lastError;
            return false;
        }
    }
    
    return true;
}

QVector<PhoneNumber> PostgresStorage::loadPhoneNumbers(int contactId)
{
    QVector<PhoneNumber> numbers;
    
    QSqlQuery query(db);
    query.prepare("SELECT phone_number, phone_type FROM phone_numbers WHERE contact_id = :contact_id");
    query.bindValue(":contact_id", contactId);
    
    if (!query.exec()) {
        lastError = query.lastError().text();
        return numbers;
    }
    
    while (query.next()) {
        PhoneNumber num;
        num.value = query.value(0).toString();
        
        QString type = query.value(1).toString().toLower();
        if (type == "home") {
            num.type = NumberType::Home;
        } else if (type == "work") {
            num.type = NumberType::Work;
        } else {
            num.type = NumberType::Personal;
        }
        
        numbers.append(num);
    }
    
    return numbers;
}

bool PostgresStorage::deletePhoneNumbers(int contactId)
{
    QSqlQuery query(db);
    query.prepare("DELETE FROM phone_numbers WHERE contact_id = :contact_id");
    query.bindValue(":contact_id", contactId);
    
    return query.exec();
}
