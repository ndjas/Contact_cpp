#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include "../models/ContactManager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onSearchTextChanged(const QString& text);
    void onAddContactClicked();
    void onContactDoubleClicked(QListWidgetItem* item);
    void onContactSelectionChanged();
    void onEditContactClicked();
    void onDeleteContactClicked();
    void refreshContactList();

private:
    Ui::MainWindow *ui;
    ContactManager* contactManager;
    
    void setupUI();
    void setupConnections();
    void loadContacts(const QString& searchQuery = "");
    void updateContactDetails(const Contact* contact);
    void clearContactDetails();
    int getSelectedContactId();
};

#endif // MAINWINDOW_H