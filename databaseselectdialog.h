#ifndef DATABASESELECTDIALOG_H
#define DATABASESELECTDIALOG_H

#include <QDialog>

namespace Ui {
class DatabaseSelectDialog;
}

class DatabaseSelectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DatabaseSelectDialog(bool onStartup, QWidget *parent = nullptr);
    QString getPath();
    ~DatabaseSelectDialog();

public slots:
    void reject();
    void accept();

private slots:
    void on_localBrowseBtn_clicked();

private:
    Ui::DatabaseSelectDialog *ui;
    bool onStartup;
};

#endif // DATABASESELECTDIALOG_H
