/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
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
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(900, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        lblTitle = new QLabel(centralwidget);
        lblTitle->setObjectName("lblTitle");

        verticalLayout->addWidget(lblTitle);

        searchLayout = new QHBoxLayout();
        searchLayout->setObjectName("searchLayout");
        searchLineEdit = new QLineEdit(centralwidget);
        searchLineEdit->setObjectName("searchLineEdit");
        searchLineEdit->setMinimumSize(QSize(0, 35));

        searchLayout->addWidget(searchLineEdit);

        btnAdd = new QPushButton(centralwidget);
        btnAdd->setObjectName("btnAdd");
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
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Horizontal);
        leftPanel = new QWidget(splitter);
        leftPanel->setObjectName("leftPanel");
        verticalLayout_2 = new QVBoxLayout(leftPanel);
        verticalLayout_2->setSpacing(5);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        lblContactCount = new QLabel(leftPanel);
        lblContactCount->setObjectName("lblContactCount");
        lblContactCount->setStyleSheet(QString::fromUtf8("color: #7f8c8d; font-weight: bold;"));

        verticalLayout_2->addWidget(lblContactCount);

        contactListWidget = new QListWidget(leftPanel);
        contactListWidget->setObjectName("contactListWidget");
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
        rightPanel->setObjectName("rightPanel");
        verticalLayout_3 = new QVBoxLayout(rightPanel);
        verticalLayout_3->setSpacing(10);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        contactDetailsTextEdit = new QTextEdit(rightPanel);
        contactDetailsTextEdit->setObjectName("contactDetailsTextEdit");
        contactDetailsTextEdit->setReadOnly(true);
        contactDetailsTextEdit->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"    border: 1px solid #bdc3c7;\n"
"    border-radius: 5px;\n"
"    background-color: white;\n"
"    padding: 10px;\n"
"}"));

        verticalLayout_3->addWidget(contactDetailsTextEdit);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName("buttonLayout");
        btnEdit = new QPushButton(rightPanel);
        btnEdit->setObjectName("btnEdit");
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
        btnDelete->setObjectName("btnDelete");
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
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 900, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MATOBEC Contact", nullptr));
        lblTitle->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:700; color:#2c3e50;\">MATOBEC Contact</span></p><p align=\"center\"><span style=\" font-size:9pt; color:#7f8c8d;\">By @leStatois</span></p></body></html>", nullptr));
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
