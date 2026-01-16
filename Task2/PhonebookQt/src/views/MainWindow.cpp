#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "ContactDialog.h"
#include <QMessageBox>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , contactManager(new ContactManager())
{
    ui->setupUi(this);
    setupUI();
    setupConnections();
    refreshContactList();
}

MainWindow::~MainWindow()
{
    delete contactManager;
    delete ui;
}

void MainWindow::setupUI()
{
    setWindowTitle("MATOBEC Contact - By @leStatois");
    resize(900, 600);
    
    // Désactiver les boutons d'édition/suppression au démarrage
    ui->btnEdit->setEnabled(false);
    ui->btnDelete->setEnabled(false);
    
    // Style de la barre de recherche
    ui->searchLineEdit->setPlaceholderText("Rechercher un contact (nom, email, numéro...)");
}

void MainWindow::setupConnections()
{
    connect(ui->searchLineEdit, &QLineEdit::textChanged, 
            this, &MainWindow::onSearchTextChanged);
    
    connect(ui->btnAdd, &QPushButton::clicked, 
            this, &MainWindow::onAddContactClicked);
    
    connect(ui->btnEdit, &QPushButton::clicked, 
            this, &MainWindow::onEditContactClicked);
    
    connect(ui->btnDelete, &QPushButton::clicked, 
            this, &MainWindow::onDeleteContactClicked);
    
    connect(ui->contactListWidget, &QListWidget::itemDoubleClicked, 
            this, &MainWindow::onContactDoubleClicked);
    
    connect(ui->contactListWidget, &QListWidget::itemSelectionChanged, 
            this, &MainWindow::onContactSelectionChanged);
}

void MainWindow::loadContacts(const QString& searchQuery)
{
    ui->contactListWidget->clear();
    
    QVector<Contact> contacts = searchQuery.isEmpty() 
        ? contactManager->getAllContacts()
        : contactManager->searchContacts(searchQuery);
    
    for (const auto& contact : contacts) {
        QListWidgetItem* item = new QListWidgetItem();
        
        // Texte principal
        QString displayText = contact.getFullName();
        if (!contact.getPrimaryPhone().isEmpty()) {
            displayText += "\n" + contact.getPrimaryPhone();
        }
        if (!contact.getEmail().isEmpty()) {
            displayText += "\n" + contact.getEmail();
        }
        
        item->setText(displayText);
        item->setData(Qt::UserRole, contact.getId());
        
        ui->contactListWidget->addItem(item);
    }
    
    // Mise à jour du compteur
    ui->lblContactCount->setText(QString("Total: %1 contact(s)").arg(contacts.size()));
}

void MainWindow::onSearchTextChanged(const QString& text)
{
    loadContacts(text);
    clearContactDetails();
}

void MainWindow::onAddContactClicked()
{
    ContactDialog dialog(this);
    dialog.setWindowTitle("Ajouter un contact");
    
    if (dialog.exec() == QDialog::Accepted) {
        Contact newContact = dialog.getContact();
        
        if (contactManager->addContact(newContact)) {
            QMessageBox::information(this, "Succès", 
                "Le contact a été ajouté avec succès!");
            refreshContactList();
        } else {
            QMessageBox::critical(this, "Erreur", 
                "Impossible d'ajouter le contact.");
        }
    }
}

void MainWindow::onContactDoubleClicked(QListWidgetItem* item)
{
    if (!item) return;
    onEditContactClicked();
}

void MainWindow::onContactSelectionChanged()
{
    QListWidgetItem* item = ui->contactListWidget->currentItem();
    
    if (item) {
        int contactId = item->data(Qt::UserRole).toInt();
        Contact* contact = contactManager->getContactById(contactId);
        
        if (contact) {
            updateContactDetails(contact);
            ui->btnEdit->setEnabled(true);
            ui->btnDelete->setEnabled(true);
            return;
        }
    }
    
    clearContactDetails();
    ui->btnEdit->setEnabled(false);
    ui->btnDelete->setEnabled(false);
}

void MainWindow::onEditContactClicked()
{
    int contactId = getSelectedContactId();
    if (contactId == -1) return;
    
    Contact* contact = contactManager->getContactById(contactId);
    if (!contact) return;
    
    ContactDialog dialog(this);
    dialog.setWindowTitle("Modifier le contact");
    dialog.setContact(*contact);
    
    if (dialog.exec() == QDialog::Accepted) {
        Contact updatedContact = dialog.getContact();
        updatedContact.setId(contactId);
        
        if (contactManager->updateContact(updatedContact)) {
            QMessageBox::information(this, "Succès", 
                "Le contact a été modifié avec succès!");
            refreshContactList();
        } else {
            QMessageBox::critical(this, "Erreur", 
                "Impossible de modifier le contact.");
        }
    }
}

void MainWindow::onDeleteContactClicked()
{
    int contactId = getSelectedContactId();
    if (contactId == -1) return;
    
    Contact* contact = contactManager->getContactById(contactId);
    if (!contact) return;
    
    QMessageBox::StandardButton reply = QMessageBox::question(
        this, 
        "Confirmation",
        QString("Êtes-vous sûr de vouloir supprimer le contact '%1' ?")
            .arg(contact->getFullName()),
        QMessageBox::Yes | QMessageBox::No
    );
    
    if (reply == QMessageBox::Yes) {
        if (contactManager->removeContact(contactId)) {
            QMessageBox::information(this, "Succès", 
                "Le contact a été supprimé avec succès!");
            refreshContactList();
            clearContactDetails();
        } else {
            QMessageBox::critical(this, "Erreur", 
                "Impossible de supprimer le contact.");
        }
    }
}

void MainWindow::refreshContactList()
{
    QString searchText = ui->searchLineEdit->text();
    loadContacts(searchText);
}

void MainWindow::updateContactDetails(const Contact* contact)
{
    if (!contact) {
        clearContactDetails();
        return;
    }
    
    QString details = "<html><body style='font-family: Arial; font-size: 11pt;'>";
    
    details += "<h2 style='color: #2c3e50; margin-bottom: 10px;'>" 
               + contact->getFullName() + "</h2>";
    
    details += "<table cellpadding='5' style='width: 100%;'>";
    
    if (!contact->getEmail().isEmpty()) {
        details += "<tr><td style='color: #7f8c8d; font-weight: bold;'>Email:</td>"
                   "<td>" + contact->getEmail() + "</td></tr>";
    }
    
    if (!contact->getAddress().isEmpty()) {
        details += "<tr><td style='color: #7f8c8d; font-weight: bold;'>Adresse:</td>"
                   "<td>" + contact->getAddress() + "</td></tr>";
    }
    
    if (!contact->getBornDate().isEmpty()) {
        details += "<tr><td style='color: #7f8c8d; font-weight: bold;'>Date de naissance:</td>"
                   "<td>" + contact->getBornDate() + "</td></tr>";
    }
    
    details += "</table>";
    
    // Numéros de téléphone
    if (!contact->getNumbers().isEmpty()) {
        details += "<h3 style='color: #2c3e50; margin-top: 15px;'>Numéros de téléphone</h3>";
        details += "<table cellpadding='3' style='width: 100%;'>";
        
        for (const auto& num : contact->getNumbers()) {
            details += QString("<tr><td style='color: #7f8c8d; width: 100px;'>%1:</td>"
                              "<td style='font-weight: bold;'>%2</td></tr>")
                       .arg(num.typeToString())
                       .arg(num.value);
        }
        
        details += "</table>";
    }
    
    details += "</body></html>";
    
    ui->contactDetailsTextEdit->setHtml(details);
}

void MainWindow::clearContactDetails()
{
    ui->contactDetailsTextEdit->clear();
}

int MainWindow::getSelectedContactId()
{
    QListWidgetItem* item = ui->contactListWidget->currentItem();
    if (!item) return -1;
    
    return item->data(Qt::UserRole).toInt();
}