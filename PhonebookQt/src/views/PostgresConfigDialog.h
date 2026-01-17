#ifndef POSTGRESCONFIGDIALOG_H
#define POSTGRESCONFIGDIALOG_H

#include <QDialog>

namespace Ui {
class PostgresConfigDialog;
}

class PostgresConfigDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PostgresConfigDialog(QWidget *parent = nullptr);
    ~PostgresConfigDialog();

    QString getHost() const;
    int getPort() const;
    QString getDatabase() const;
    QString getUsername() const;
    QString getPassword() const;
    
    void setHost(const QString& host);
    void setPort(int port);
    void setDatabase(const QString& db);
    void setUsername(const QString& user);

private slots:
    void onTestConnectionClicked();
    void onSaveClicked();
    void onCancelClicked();

private:
    Ui::PostgresConfigDialog *ui;
    
    bool testConnection();
};

#endif // POSTGRESCONFIGDIALOG_H
