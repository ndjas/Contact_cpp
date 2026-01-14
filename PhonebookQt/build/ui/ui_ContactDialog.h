/********************************************************************************
** Form generated from reading UI file 'ContactDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTACTDIALOG_H
#define UI_CONTACTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ContactDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *lblHeader;
    QGroupBox *groupBoxPersonalInfo;
    QFormLayout *formLayout;
    QLabel *lblName;
    QLineEdit *lineEditName;
    QLabel *lblSurname;
    QLineEdit *lineEditSurname;
    QLabel *lblPatronym;
    QLineEdit *lineEditPatronym;
    QLabel *lblBornDate;
    QDateEdit *dateEdit;
    QLabel *lblAddress;
    QLineEdit *lineEditAddress;
    QLabel *lblEmail;
    QLineEdit *lineEditEmail;
    QGroupBox *groupBoxNumbers;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEditNumber;
    QComboBox *comboBoxNumberType;
    QPushButton *btnAddNumber;
    QLabel *lblNumberCount;
    QListWidget *numberListWidget;
    QPushButton *btnRemoveNumber;
    QLabel *lblRequired;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnCancel;
    QPushButton *btnSave;

    void setupUi(QDialog *ContactDialog)
    {
        if (ContactDialog->objectName().isEmpty())
            ContactDialog->setObjectName("ContactDialog");
        ContactDialog->resize(500, 650);
        verticalLayout = new QVBoxLayout(ContactDialog);
        verticalLayout->setObjectName("verticalLayout");
        lblHeader = new QLabel(ContactDialog);
        lblHeader->setObjectName("lblHeader");

        verticalLayout->addWidget(lblHeader);

        groupBoxPersonalInfo = new QGroupBox(ContactDialog);
        groupBoxPersonalInfo->setObjectName("groupBoxPersonalInfo");
        formLayout = new QFormLayout(groupBoxPersonalInfo);
        formLayout->setObjectName("formLayout");
        formLayout->setHorizontalSpacing(10);
        formLayout->setVerticalSpacing(10);
        lblName = new QLabel(groupBoxPersonalInfo);
        lblName->setObjectName("lblName");

        formLayout->setWidget(0, QFormLayout::LabelRole, lblName);

        lineEditName = new QLineEdit(groupBoxPersonalInfo);
        lineEditName->setObjectName("lineEditName");

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditName);

        lblSurname = new QLabel(groupBoxPersonalInfo);
        lblSurname->setObjectName("lblSurname");

        formLayout->setWidget(1, QFormLayout::LabelRole, lblSurname);

        lineEditSurname = new QLineEdit(groupBoxPersonalInfo);
        lineEditSurname->setObjectName("lineEditSurname");

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditSurname);

        lblPatronym = new QLabel(groupBoxPersonalInfo);
        lblPatronym->setObjectName("lblPatronym");

        formLayout->setWidget(2, QFormLayout::LabelRole, lblPatronym);

        lineEditPatronym = new QLineEdit(groupBoxPersonalInfo);
        lineEditPatronym->setObjectName("lineEditPatronym");

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEditPatronym);

        lblBornDate = new QLabel(groupBoxPersonalInfo);
        lblBornDate->setObjectName("lblBornDate");

        formLayout->setWidget(3, QFormLayout::LabelRole, lblBornDate);

        dateEdit = new QDateEdit(groupBoxPersonalInfo);
        dateEdit->setObjectName("dateEdit");

        formLayout->setWidget(3, QFormLayout::FieldRole, dateEdit);

        lblAddress = new QLabel(groupBoxPersonalInfo);
        lblAddress->setObjectName("lblAddress");

        formLayout->setWidget(4, QFormLayout::LabelRole, lblAddress);

        lineEditAddress = new QLineEdit(groupBoxPersonalInfo);
        lineEditAddress->setObjectName("lineEditAddress");

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEditAddress);

        lblEmail = new QLabel(groupBoxPersonalInfo);
        lblEmail->setObjectName("lblEmail");

        formLayout->setWidget(5, QFormLayout::LabelRole, lblEmail);

        lineEditEmail = new QLineEdit(groupBoxPersonalInfo);
        lineEditEmail->setObjectName("lineEditEmail");

        formLayout->setWidget(5, QFormLayout::FieldRole, lineEditEmail);


        verticalLayout->addWidget(groupBoxPersonalInfo);

        groupBoxNumbers = new QGroupBox(ContactDialog);
        groupBoxNumbers->setObjectName("groupBoxNumbers");
        verticalLayout_2 = new QVBoxLayout(groupBoxNumbers);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        lineEditNumber = new QLineEdit(groupBoxNumbers);
        lineEditNumber->setObjectName("lineEditNumber");

        horizontalLayout->addWidget(lineEditNumber);

        comboBoxNumberType = new QComboBox(groupBoxNumbers);
        comboBoxNumberType->addItem(QString());
        comboBoxNumberType->addItem(QString());
        comboBoxNumberType->addItem(QString());
        comboBoxNumberType->setObjectName("comboBoxNumberType");
        comboBoxNumberType->setMinimumSize(QSize(120, 0));

        horizontalLayout->addWidget(comboBoxNumberType);

        btnAddNumber = new QPushButton(groupBoxNumbers);
        btnAddNumber->setObjectName("btnAddNumber");
        btnAddNumber->setMinimumSize(QSize(80, 0));
        btnAddNumber->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #27ae60;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 3px;\n"
"    padding: 5px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #229954;\n"
"}"));

        horizontalLayout->addWidget(btnAddNumber);


        verticalLayout_2->addLayout(horizontalLayout);

        lblNumberCount = new QLabel(groupBoxNumbers);
        lblNumberCount->setObjectName("lblNumberCount");
        lblNumberCount->setStyleSheet(QString::fromUtf8("color: #7f8c8d; font-size: 9pt;"));

        verticalLayout_2->addWidget(lblNumberCount);

        numberListWidget = new QListWidget(groupBoxNumbers);
        numberListWidget->setObjectName("numberListWidget");
        numberListWidget->setMaximumSize(QSize(16777215, 120));
        numberListWidget->setStyleSheet(QString::fromUtf8("QListWidget {\n"
"    border: 1px solid #bdc3c7;\n"
"    border-radius: 3px;\n"
"}\n"
"QListWidget::item {\n"
"    padding: 5px;\n"
"}\n"
"QListWidget::item:selected {\n"
"    background-color: #3498db;\n"
"    color: white;\n"
"}"));

        verticalLayout_2->addWidget(numberListWidget);

        btnRemoveNumber = new QPushButton(groupBoxNumbers);
        btnRemoveNumber->setObjectName("btnRemoveNumber");
        btnRemoveNumber->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #e74c3c;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 3px;\n"
"    padding: 5px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #c0392b;\n"
"}"));

        verticalLayout_2->addWidget(btnRemoveNumber);


        verticalLayout->addWidget(groupBoxNumbers);

        lblRequired = new QLabel(ContactDialog);
        lblRequired->setObjectName("lblRequired");

        verticalLayout->addWidget(lblRequired);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btnCancel = new QPushButton(ContactDialog);
        btnCancel->setObjectName("btnCancel");
        btnCancel->setMinimumSize(QSize(100, 35));
        btnCancel->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #95a5a6;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 5px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #7f8c8d;\n"
"}"));

        horizontalLayout_2->addWidget(btnCancel);

        btnSave = new QPushButton(ContactDialog);
        btnSave->setObjectName("btnSave");
        btnSave->setMinimumSize(QSize(100, 35));
        btnSave->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #27ae60;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 5px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #229954;\n"
"}\n"
"QPushButton:disabled {\n"
"    background-color: #bdc3c7;\n"
"    color: #7f8c8d;\n"
"}"));

        horizontalLayout_2->addWidget(btnSave);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(ContactDialog);

        QMetaObject::connectSlotsByName(ContactDialog);
    } // setupUi

    void retranslateUi(QDialog *ContactDialog)
    {
        ContactDialog->setWindowTitle(QCoreApplication::translate("ContactDialog", "Contact", nullptr));
        lblHeader->setText(QCoreApplication::translate("ContactDialog", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700; color:#2c3e50;\">Informations du contact</span></p></body></html>", nullptr));
        groupBoxPersonalInfo->setTitle(QCoreApplication::translate("ContactDialog", "Informations personnelles", nullptr));
        lblName->setText(QCoreApplication::translate("ContactDialog", "Nom: *", nullptr));
        lineEditName->setPlaceholderText(QCoreApplication::translate("ContactDialog", "Entrez le nom", nullptr));
        lblSurname->setText(QCoreApplication::translate("ContactDialog", "Pr\303\251nom: *", nullptr));
        lineEditSurname->setPlaceholderText(QCoreApplication::translate("ContactDialog", "Entrez le pr\303\251nom", nullptr));
        lblPatronym->setText(QCoreApplication::translate("ContactDialog", "Patronyme:", nullptr));
        lineEditPatronym->setPlaceholderText(QCoreApplication::translate("ContactDialog", "Entrez le patronyme (optionnel)", nullptr));
        lblBornDate->setText(QCoreApplication::translate("ContactDialog", "Date de naissance:", nullptr));
        lblAddress->setText(QCoreApplication::translate("ContactDialog", "Adresse:", nullptr));
        lineEditAddress->setPlaceholderText(QCoreApplication::translate("ContactDialog", "Entrez l'adresse", nullptr));
        lblEmail->setText(QCoreApplication::translate("ContactDialog", "Email: *", nullptr));
        lineEditEmail->setPlaceholderText(QCoreApplication::translate("ContactDialog", "exemple@email.com", nullptr));
        groupBoxNumbers->setTitle(QCoreApplication::translate("ContactDialog", "Num\303\251ros de t\303\251l\303\251phone", nullptr));
        lineEditNumber->setPlaceholderText(QCoreApplication::translate("ContactDialog", "+79123456789 ou 89123456789", nullptr));
        comboBoxNumberType->setItemText(0, QCoreApplication::translate("ContactDialog", "Personnel", nullptr));
        comboBoxNumberType->setItemText(1, QCoreApplication::translate("ContactDialog", "Domicile", nullptr));
        comboBoxNumberType->setItemText(2, QCoreApplication::translate("ContactDialog", "Travail", nullptr));

        btnAddNumber->setText(QCoreApplication::translate("ContactDialog", "\342\236\225 Ajouter", nullptr));
        lblNumberCount->setText(QCoreApplication::translate("ContactDialog", "Num\303\251ros: 0", nullptr));
        btnRemoveNumber->setText(QCoreApplication::translate("ContactDialog", "\360\237\227\221\357\270\217 Supprimer le num\303\251ro s\303\251lectionn\303\251", nullptr));
        lblRequired->setText(QCoreApplication::translate("ContactDialog", "<html><head/><body><p><span style=\" font-size:9pt; color:#e74c3c;\">* Champs obligatoires (nom, pr\303\251nom, email, au moins 1 num\303\251ro)</span></p></body></html>", nullptr));
        btnCancel->setText(QCoreApplication::translate("ContactDialog", "Annuler", nullptr));
        btnSave->setText(QCoreApplication::translate("ContactDialog", "\360\237\222\276 Enregistrer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ContactDialog: public Ui_ContactDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTACTDIALOG_H
