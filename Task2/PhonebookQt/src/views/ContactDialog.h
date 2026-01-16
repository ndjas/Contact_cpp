#ifndef CONTACTDIALOG_H
#define CONTACTDIALOG_H

#include <QDialog>
#include <QListWidget>
#include "../models/Contact.h"

namespace Ui {
class ContactDialog;
}

class ContactDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ContactDialog(QWidget *parent = nullptr);
    ~ContactDialog();

    void setContact(const Contact& contact);
    Contact getContact() const;

private slots:
    void onAddNumberClicked();
    void onRemoveNumberClicked();
    void onSaveClicked();
    void onCancelClicked();
    void validateForm();

private:
    Ui::ContactDialog *ui;
    
    void setupUI();
    void setupConnections();
    void updateNumberList();
    bool validateFields();
    
    QVector<PhoneNumber> phoneNumbers;
};

#endif // CONTACTDIALOG_H