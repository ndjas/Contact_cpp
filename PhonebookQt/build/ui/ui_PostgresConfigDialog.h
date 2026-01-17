/********************************************************************************
** Form generated from reading UI file 'PostgresConfigDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.17
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POSTGRESCONFIGDIALOG_H
#define UI_POSTGRESCONFIGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PostgresConfigDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *lblTitle;
    QGroupBox *groupBoxConnection;
    QFormLayout *formLayout;
    QLabel *lblHost;
    QLineEdit *lineEditHost;
    QLabel *lblPort;
    QSpinBox *spinBoxPort;
    QLabel *lblDatabase;
    QLineEdit *lineEditDatabase;
    QLabel *lblUsername;
    QLineEdit *lineEditUsername;
    QLabel *lblPassword;
    QLineEdit *lineEditPassword;
    QLabel *lblInfo;
    QPushButton *btnTestConnection;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnCancel;
    QPushButton *btnSave;

    void setupUi(QDialog *PostgresConfigDialog)
    {
        if (PostgresConfigDialog->objectName().isEmpty())
            PostgresConfigDialog->setObjectName(QString::fromUtf8("PostgresConfigDialog"));
        PostgresConfigDialog->resize(450, 400);
        verticalLayout = new QVBoxLayout(PostgresConfigDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lblTitle = new QLabel(PostgresConfigDialog);
        lblTitle->setObjectName(QString::fromUtf8("lblTitle"));

        verticalLayout->addWidget(lblTitle);

        groupBoxConnection = new QGroupBox(PostgresConfigDialog);
        groupBoxConnection->setObjectName(QString::fromUtf8("groupBoxConnection"));
        formLayout = new QFormLayout(groupBoxConnection);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setHorizontalSpacing(10);
        formLayout->setVerticalSpacing(15);
        lblHost = new QLabel(groupBoxConnection);
        lblHost->setObjectName(QString::fromUtf8("lblHost"));

        formLayout->setWidget(0, QFormLayout::LabelRole, lblHost);

        lineEditHost = new QLineEdit(groupBoxConnection);
        lineEditHost->setObjectName(QString::fromUtf8("lineEditHost"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditHost);

        lblPort = new QLabel(groupBoxConnection);
        lblPort->setObjectName(QString::fromUtf8("lblPort"));

        formLayout->setWidget(1, QFormLayout::LabelRole, lblPort);

        spinBoxPort = new QSpinBox(groupBoxConnection);
        spinBoxPort->setObjectName(QString::fromUtf8("spinBoxPort"));
        spinBoxPort->setMinimum(1);
        spinBoxPort->setMaximum(65535);
        spinBoxPort->setValue(5432);

        formLayout->setWidget(1, QFormLayout::FieldRole, spinBoxPort);

        lblDatabase = new QLabel(groupBoxConnection);
        lblDatabase->setObjectName(QString::fromUtf8("lblDatabase"));

        formLayout->setWidget(2, QFormLayout::LabelRole, lblDatabase);

        lineEditDatabase = new QLineEdit(groupBoxConnection);
        lineEditDatabase->setObjectName(QString::fromUtf8("lineEditDatabase"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEditDatabase);

        lblUsername = new QLabel(groupBoxConnection);
        lblUsername->setObjectName(QString::fromUtf8("lblUsername"));

        formLayout->setWidget(3, QFormLayout::LabelRole, lblUsername);

        lineEditUsername = new QLineEdit(groupBoxConnection);
        lineEditUsername->setObjectName(QString::fromUtf8("lineEditUsername"));

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEditUsername);

        lblPassword = new QLabel(groupBoxConnection);
        lblPassword->setObjectName(QString::fromUtf8("lblPassword"));

        formLayout->setWidget(4, QFormLayout::LabelRole, lblPassword);

        lineEditPassword = new QLineEdit(groupBoxConnection);
        lineEditPassword->setObjectName(QString::fromUtf8("lineEditPassword"));
        lineEditPassword->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEditPassword);


        verticalLayout->addWidget(groupBoxConnection);

        lblInfo = new QLabel(PostgresConfigDialog);
        lblInfo->setObjectName(QString::fromUtf8("lblInfo"));
        lblInfo->setWordWrap(true);

        verticalLayout->addWidget(lblInfo);

        btnTestConnection = new QPushButton(PostgresConfigDialog);
        btnTestConnection->setObjectName(QString::fromUtf8("btnTestConnection"));
        btnTestConnection->setMinimumSize(QSize(0, 35));
        btnTestConnection->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #3498db;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 5px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #2980b9;\n"
"}"));

        verticalLayout->addWidget(btnTestConnection);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnCancel = new QPushButton(PostgresConfigDialog);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
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

        horizontalLayout->addWidget(btnCancel);

        btnSave = new QPushButton(PostgresConfigDialog);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
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
"}"));

        horizontalLayout->addWidget(btnSave);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(PostgresConfigDialog);

        QMetaObject::connectSlotsByName(PostgresConfigDialog);
    } // setupUi

    void retranslateUi(QDialog *PostgresConfigDialog)
    {
        PostgresConfigDialog->setWindowTitle(QCoreApplication::translate("PostgresConfigDialog", "Configuration PostgreSQL", nullptr));
        lblTitle->setText(QCoreApplication::translate("PostgresConfigDialog", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:700; color:#2c3e50;\">\360\237\220\230 Configuration PostgreSQL</span></p></body></html>", nullptr));
        groupBoxConnection->setTitle(QCoreApplication::translate("PostgresConfigDialog", "Param\303\250tres de connexion", nullptr));
        lblHost->setText(QCoreApplication::translate("PostgresConfigDialog", "H\303\264te: *", nullptr));
        lineEditHost->setPlaceholderText(QCoreApplication::translate("PostgresConfigDialog", "localhost", nullptr));
        lblPort->setText(QCoreApplication::translate("PostgresConfigDialog", "Port: *", nullptr));
        lblDatabase->setText(QCoreApplication::translate("PostgresConfigDialog", "Base de donn\303\251es: *", nullptr));
        lineEditDatabase->setPlaceholderText(QCoreApplication::translate("PostgresConfigDialog", "phonebook_db", nullptr));
        lblUsername->setText(QCoreApplication::translate("PostgresConfigDialog", "Utilisateur: *", nullptr));
        lineEditUsername->setPlaceholderText(QCoreApplication::translate("PostgresConfigDialog", "postgres", nullptr));
        lblPassword->setText(QCoreApplication::translate("PostgresConfigDialog", "Mot de passe:", nullptr));
        lineEditPassword->setPlaceholderText(QCoreApplication::translate("PostgresConfigDialog", "Mot de passe (optionnel)", nullptr));
        lblInfo->setText(QCoreApplication::translate("PostgresConfigDialog", "<html><head/><body><p><span style=\" font-size:9pt; color:#7f8c8d; font-style:italic;\">\360\237\222\241 La base de donn\303\251es et les tables seront cr\303\251\303\251es automatiquement si elles n'existent pas.</span></p></body></html>", nullptr));
        btnTestConnection->setText(QCoreApplication::translate("PostgresConfigDialog", "\360\237\224\214 Tester la connexion", nullptr));
        btnCancel->setText(QCoreApplication::translate("PostgresConfigDialog", "Annuler", nullptr));
        btnSave->setText(QCoreApplication::translate("PostgresConfigDialog", "\360\237\222\276 Enregistrer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PostgresConfigDialog: public Ui_PostgresConfigDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POSTGRESCONFIGDIALOG_H
