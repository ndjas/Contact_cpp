#include "PostgresConfigDialog.h"
#include "ui_PostgresConfigDialog.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>

PostgresConfigDialog::PostgresConfigDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PostgresConfigDialog)
{
    ui->setupUi(this);
    
    setModal(true);
    setWindowTitle("Configuration PostgreSQL");
    
    // Valeurs par défaut
    ui->lineEditHost->setText("localhost");
    ui->spinBoxPort->setValue(5432);
    ui->lineEditDatabase->setText("phonebook_db");
    ui->lineEditUsername->setText("postgres");
    
    connect(ui->btnTestConnection, &QPushButton::clicked, 
            this, &PostgresConfigDialog::onTestConnectionClicked);
    connect(ui->btnSave, &QPushButton::clicked, 
            this, &PostgresConfigDialog::onSaveClicked);
    connect(ui->btnCancel, &QPushButton::clicked, 
            this, &PostgresConfigDialog::onCancelClicked);
}

PostgresConfigDialog::~PostgresConfigDialog()
{
    delete ui;
}

QString PostgresConfigDialog::getHost() const
{
    return ui->lineEditHost->text();
}

int PostgresConfigDialog::getPort() const
{
    return ui->spinBoxPort->value();
}

QString PostgresConfigDialog::getDatabase() const
{
    return ui->lineEditDatabase->text();
}

QString PostgresConfigDialog::getUsername() const
{
    return ui->lineEditUsername->text();
}

QString PostgresConfigDialog::getPassword() const
{
    return ui->lineEditPassword->text();
}

void PostgresConfigDialog::setHost(const QString& host)
{
    ui->lineEditHost->setText(host);
}

void PostgresConfigDialog::setPort(int port)
{
    ui->spinBoxPort->setValue(port);
}

void PostgresConfigDialog::setDatabase(const QString& db)
{
    ui->lineEditDatabase->setText(db);
}

void PostgresConfigDialog::setUsername(const QString& user)
{
    ui->lineEditUsername->setText(user);
}

void PostgresConfigDialog::onTestConnectionClicked()
{
    if (testConnection()) {
        QMessageBox::information(this, "Succès", 
            "✅ Connexion PostgreSQL réussie!");
    } else {
        // Le message d'erreur est déjà affiché par testConnection()
    }
}

void PostgresConfigDialog::onSaveClicked()
{
    if (ui->lineEditHost->text().isEmpty() ||
        ui->lineEditDatabase->text().isEmpty() ||
        ui->lineEditUsername->text().isEmpty()) {
        
        QMessageBox::warning(this, "Attention", 
            "Veuillez remplir tous les champs obligatoires.");
        return;
    }
    
    accept();
}

void PostgresConfigDialog::onCancelClicked()
{
    reject();
}

bool PostgresConfigDialog::testConnection()
{
    QSqlDatabase testDb = QSqlDatabase::addDatabase("QPSQL", "test_connection");
    testDb.setHostName(getHost());
    testDb.setPort(getPort());
    testDb.setDatabaseName(getDatabase());
    testDb.setUserName(getUsername());
    testDb.setPassword(getPassword());
    
    bool success = testDb.open();
    
    if (!success) {
        QString error = testDb.lastError().text();
        QMessageBox::critical(this, "Erreur de connexion", 
            QString("❌ Impossible de se connecter à PostgreSQL:\n\n%1\n\n"
                   "Vérifiez que:\n"
                   "• PostgreSQL est installé et démarré\n"
                   "• Les paramètres de connexion sont corrects\n"
                   "• L'utilisateur a les permissions nécessaires")
            .arg(error));
    }
    
    testDb.close();
    QSqlDatabase::removeDatabase("test_connection");
    
    return success;
}
