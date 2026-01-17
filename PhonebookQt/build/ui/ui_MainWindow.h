/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.17
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *lblTitle;
    QGroupBox *groupBoxStorage;
    QHBoxLayout *horizontalLayout_storage;
    QRadioButton *radioJSON;
    QRadioButton *radioPostgres;
    QPushButton *btnConfigPostgres;
    QLabel *lblStorageStatus;
    QSpacerItem *horizontalSpacer_storage;
    QHBoxLayout *searchLayout;
    QLineEdit *searchLineEdit;
    QPushButton *btnAdd;
    QSplitter *splitter;
    QWidget *leftPanel;
    QVBoxLayout *verticalLayout_2;
    QLabel *lblContactCount;
    QListWidget *contactListWidget;
    QWidget *rightPanel;
    QVBoxLayout *verticalLayout_3;
    QTextEdit *contactDetailsTextEdit;
    QHBoxLayout *buttonLayout;
    QPushButton *btnEdit;
    QPushButton *btnDelete;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(900, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lblTitle = new QLabel(centralwidget);
        lblTitle->setObjectName(QString::fromUtf8("lblTitle"));

        verticalLayout->addWidget(lblTitle);

        groupBoxStorage = new QGroupBox(centralwidget);
        groupBoxStorage->setObjectName(QString::fromUtf8("groupBoxStorage"));
        horizontalLayout_storage = new QHBoxLayout(groupBoxStorage);
        horizontalLayout_storage->setObjectName(QString::fromUtf8("horizontalLayout_storage"));
        radioJSON = new QRadioButton(groupBoxStorage);
        radioJSON->setObjectName(QString::fromUtf8("radioJSON"));
        radioJSON->setChecked(true);

        horizontalLayout_storage->addWidget(radioJSON);

        radioPostgres = new QRadioButton(groupBoxStorage);
        radioPostgres->setObjectName(QString::fromUtf8("radioPostgres"));

        horizontalLayout_storage->addWidget(radioPostgres);

        btnConfigPostgres = new QPushButton(groupBoxStorage);
        btnConfigPostgres->setObjectName(QString::fromUtf8("btnConfigPostgres"));
        btnConfigPostgres->setMinimumSize(QSize(120, 25));
        btnConfigPostgres->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #34495e;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 3px;\n"
"    font-size: 9pt;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #2c3e50;\n"
"}"));

        horizontalLayout_storage->addWidget(btnConfigPostgres);

        lblStorageStatus = new QLabel(groupBoxStorage);
        lblStorageStatus->setObjectName(QString::fromUtf8("lblStorageStatus"));

        horizontalLayout_storage->addWidget(lblStorageStatus);

        horizontalSpacer_storage = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_storage->addItem(horizontalSpacer_storage);


        verticalLayout->addWidget(groupBoxStorage);

        searchLayout = new QHBoxLayout();
        searchLayout->setObjectName(QString::fromUtf8("searchLayout"));
        searchLineEdit = new QLineEdit(centralwidget);
        searchLineEdit->setObjectName(QString::fromUtf8("searchLineEdit"));
        searchLineEdit->setMinimumSize(QSize(0, 35));

        searchLayout->addWidget(searchLineEdit);

        btnAdd = new QPushButton(centralwidget);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));
        btnAdd->setMinimumSize(QSize(120, 35));
        btnAdd->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #3498db;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 5px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #2980b9;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #21618c;\n"
"}"));

        searchLayout->addWidget(btnAdd);


        verticalLayout->addLayout(searchLayout);

        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        leftPanel = new QWidget(splitter);
        leftPanel->setObjectName(QString::fromUtf8("leftPanel"));
        verticalLayout_2 = new QVBoxLayout(leftPanel);
        verticalLayout_2->setSpacing(5);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        lblContactCount = new QLabel(leftPanel);
        lblContactCount->setObjectName(QString::fromUtf8("lblContactCount"));
        lblContactCount->setStyleSheet(QString::fromUtf8("color: #7f8c8d; font-weight: bold;"));

        verticalLayout_2->addWidget(lblContactCount);

        contactListWidget = new QListWidget(leftPanel);
        contactListWidget->setObjectName(QString::fromUtf8("contactListWidget"));
        contactListWidget->setStyleSheet(QString::fromUtf8("QListWidget {\n"
"    border: 1px solid #bdc3c7;\n"
"    border-radius: 5px;\n"
"    background-color: white;\n"
"}\n"
"QListWidget::item {\n"
"    padding: 10px;\n"
"    border-bottom: 1px solid #ecf0f1;\n"
"}\n"
"QListWidget::item:selected {\n"
"    background-color: #3498db;\n"
"    color: white;\n"
"}\n"
"QListWidget::item:hover {\n"
"    background-color: #ecf0f1;\n"
"}"));

        verticalLayout_2->addWidget(contactListWidget);

        splitter->addWidget(leftPanel);
        rightPanel = new QWidget(splitter);
        rightPanel->setObjectName(QString::fromUtf8("rightPanel"));
        verticalLayout_3 = new QVBoxLayout(rightPanel);
        verticalLayout_3->setSpacing(10);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        contactDetailsTextEdit = new QTextEdit(rightPanel);
        contactDetailsTextEdit->setObjectName(QString::fromUtf8("contactDetailsTextEdit"));
        contactDetailsTextEdit->setReadOnly(true);
        contactDetailsTextEdit->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"    border: 1px solid #bdc3c7;\n"
"    border-radius: 5px;\n"
"    background-color: white;\n"
"    padding: 10px;\n"
"}"));

        verticalLayout_3->addWidget(contactDetailsTextEdit);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName(QString::fromUtf8("buttonLayout"));
        btnEdit = new QPushButton(rightPanel);
        btnEdit->setObjectName(QString::fromUtf8("btnEdit"));
        btnEdit->setMinimumSize(QSize(0, 35));
        btnEdit->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #f39c12;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 5px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #e67e22;\n"
"}\n"
"QPushButton:disabled {\n"
"    background-color: #bdc3c7;\n"
"    color: #7f8c8d;\n"
"}"));

        buttonLayout->addWidget(btnEdit);

        btnDelete = new QPushButton(rightPanel);
        btnDelete->setObjectName(QString::fromUtf8("btnDelete"));
        btnDelete->setMinimumSize(QSize(0, 35));
        btnDelete->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #e74c3c;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 5px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #c0392b;\n"
"}\n"
"QPushButton:disabled {\n"
"    background-color: #bdc3c7;\n"
"    color: #7f8c8d;\n"
"}"));

        buttonLayout->addWidget(btnDelete);


        verticalLayout_3->addLayout(buttonLayout);

        splitter->addWidget(rightPanel);

        verticalLayout->addWidget(splitter);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 900, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MATOBEC Contact", nullptr));
        lblTitle->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:700; color:#2c3e50;\">MATOBEC Contact</span></p><p align=\"center\"><span style=\" font-size:9pt; color:#7f8c8d;\">By @leStatois</span></p></body></html>", nullptr));
        groupBoxStorage->setTitle(QCoreApplication::translate("MainWindow", "Mode de stockage", nullptr));
        radioJSON->setText(QCoreApplication::translate("MainWindow", "\360\237\223\204 Fichier JSON", nullptr));
        radioPostgres->setText(QCoreApplication::translate("MainWindow", "\360\237\220\230 PostgreSQL", nullptr));
        btnConfigPostgres->setText(QCoreApplication::translate("MainWindow", "\342\232\231\357\270\217 Configuration", nullptr));
        lblStorageStatus->setText(QCoreApplication::translate("MainWindow", "<span style=\"color: #27ae60;\">\342\234\205 Connect\303\251</span>", nullptr));
        searchLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Rechercher un contact...", nullptr));
        btnAdd->setText(QCoreApplication::translate("MainWindow", "\342\236\225 Ajouter", nullptr));
        lblContactCount->setText(QCoreApplication::translate("MainWindow", "Total: 0 contact(s)", nullptr));
        contactDetailsTextEdit->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#7f8c8d;\">S\303\251lectionnez un contact pour voir les d\303\251tails</span></p></body></html>", nullptr));
        btnEdit->setText(QCoreApplication::translate("MainWindow", "\342\234\217\357\270\217 Modifier", nullptr));
        btnDelete->setText(QCoreApplication::translate("MainWindow", "\360\237\227\221\357\270\217 Supprimer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
