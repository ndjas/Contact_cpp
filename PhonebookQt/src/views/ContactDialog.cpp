#include "ContactDialog.h"
#include "ui_ContactDialog.h"
#include "../utils/Validator.h"
#include <QMessageBox>
#include <QRegularExpression>

ContactDialog::ContactDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ContactDialog)
{
    ui->setupUi(this);
    setupUI();
    setupConnections();
}

ContactDialog::~ContactDialog()
{
    delete ui;
}

void ContactDialog::setupUI()
{
    setModal(true);
    resize(500, 600);
    
    // Date actuelle par défaut
    ui->dateEdit->setDate(QDate::currentDate());
    ui->dateEdit->setDisplayFormat("dd-MM-yyyy");
    ui->dateEdit->setCalendarPopup(true);
    ui->dateEdit->setMaximumDate(QDate::currentDate());
    
    // Désactiver le bouton Save au départ
    ui->btnSave->setEnabled(false);
}

void ContactDialog::setupConnections()
{
    connect(ui->btnAddNumber, &QPushButton::clicked, 
            this, &ContactDialog::onAddNumberClicked);
    
    connect(ui->btnRemoveNumber, &QPushButton::clicked, 
            this, &ContactDialog::onRemoveNumberClicked);
    
    connect(ui->btnSave, &QPushButton::clicked, 
            this, &ContactDialog::onSaveClicked);
    
    connect(ui->btnCancel, &QPushButton::clicked, 
            this, &ContactDialog::onCancelClicked);
    
    // Validation en temps réel
    connect(ui->lineEditName, &QLineEdit::textChanged, 
            this, &ContactDialog::validateForm);
    connect(ui->lineEditSurname, &QLineEdit::textChanged, 
            this, &ContactDialog::validateForm);
    connect(ui->lineEditEmail, &QLineEdit::textChanged, 
            this, &ContactDialog::validateForm);
}

void ContactDialog::setContact(const Contact& contact)
{
    ui->lineEditName->setText(contact.getName());
    ui->lineEditSurname->setText(contact.getSurname());
    ui->lineEditPatronym->setText(contact.getPatronym());
    ui->lineEditAddress->setText(contact.getAddress());
    ui->lineEditEmail->setText(contact.getEmail());
    
    if (!contact.getBornDate().isEmpty()) {
        QDate date = QDate::fromString(contact.getBornDate(), "dd-MM-yyyy");
        if (date.isValid()) {
            ui->dateEdit->setDate(date);
        }
    }
    
    phoneNumbers = contact.getNumbers();
    updateNumberList();
    validateForm();
}

Contact ContactDialog::getContact() const
{
    Contact contact;
    
    contact.setName(ui->lineEditName->text().trimmed());
    contact.setSurname(ui->lineEditSurname->text().trimmed());
    contact.setPatronym(ui->lineEditPatronym->text().trimmed());
    contact.setAddress(ui->lineEditAddress->text().trimmed());
    contact.setEmail(ui->lineEditEmail->text().trimmed());
    contact.setBornDate(ui->dateEdit->date().toString("dd-MM-yyyy"));
    contact.setNumbers(phoneNumbers);
    
    return contact;
}

void ContactDialog::onAddNumberClicked()
{
    QString number = ui->lineEditNumber->text().trimmed();
    
    if (number.isEmpty()) {
        QMessageBox::warning(this, "Attention", 
            "Veuillez entrer un numéro de téléphone.");
        return;
    }
    
    if (!Validator::isValidNumber(number)) {
        QMessageBox::warning(this, "Numéro invalide", 
            "Le format du numéro n'est pas valide.\n"
            "Exemple valide: +79123456789 ou 89123456789");
        return;
    }
    
    PhoneNumber phoneNum;
    phoneNum.value = number;
    
    // Récupérer le type sélectionné
    QString typeStr = ui->comboBoxNumberType->currentText();
    if (typeStr == "Domicile") {
        phoneNum.type = NumberType::Home;
    } else if (typeStr == "Travail") {
        phoneNum.type = NumberType::Work;
    } else {
        phoneNum.type = NumberType::Personal;
    }
    
    phoneNumbers.append(phoneNum);
    updateNumberList();
    
    // Réinitialiser le champ
    ui->lineEditNumber->clear();
    ui->lineEditNumber->setFocus();
    
    validateForm();
}

void ContactDialog::onRemoveNumberClicked()
{
    int currentRow = ui->numberListWidget->currentRow();
    
    if (currentRow < 0 || currentRow >= phoneNumbers.size()) {
        QMessageBox::warning(this, "Attention", 
            "Veuillez sélectionner un numéro à supprimer.");
        return;
    }
    
    phoneNumbers.removeAt(currentRow);
    updateNumberList();
    validateForm();
}

void ContactDialog::onSaveClicked()
{
    if (!validateFields()) {
        return;
    }
    
    accept();
}

void ContactDialog::onCancelClicked()
{
    reject();
}

void ContactDialog::validateForm()
{
    bool isValid = validateFields();
    ui->btnSave->setEnabled(isValid);
}

void ContactDialog::updateNumberList()
{
    ui->numberListWidget->clear();
    
    for (const auto& num : phoneNumbers) {
        QString displayText = QString("%1 (%2)")
            .arg(num.value)
            .arg(num.typeToString());
        
        ui->numberListWidget->addItem(displayText);
    }
    
    ui->lblNumberCount->setText(QString("Numéros: %1").arg(phoneNumbers.size()));
}

bool ContactDialog::validateFields()
{
    // Nom obligatoire
    QString name = ui->lineEditName->text().trimmed();
    if (name.isEmpty()) {
        return false;
    }
    
    if (!Validator::isValidName(name)) {
        return false;
    }
    
    // Prénom obligatoire
    QString surname = ui->lineEditSurname->text().trimmed();
    if (surname.isEmpty()) {
        return false;
    }
    
    if (!Validator::isValidName(surname)) {
        return false;
    }
    
    // Email obligatoire et valide
    QString email = ui->lineEditEmail->text().trimmed();
    if (email.isEmpty()) {
        return false;
    }
    
    if (!Validator::isValidEmail(email)) {
        return false;
    }
    
    // Au moins un numéro de téléphone
    if (phoneNumbers.isEmpty()) {
        return false;
    }
    
    // Patronyme (optionnel mais si rempli, doit être valide)
    QString patronym = ui->lineEditPatronym->text().trimmed();
    if (!patronym.isEmpty() && !Validator::isValidName(patronym)) {
        return false;
    }
    
    // Adresse (optionnel mais si rempli, doit être valide)
    QString address = ui->lineEditAddress->text().trimmed();
    if (!address.isEmpty() && !Validator::isValidName(address)) {
        return false;
    }
    
    return true;
}