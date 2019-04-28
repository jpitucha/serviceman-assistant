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
    explicit DatabaseSelectDialog(QWidget *parent = nullptr);
    ~DatabaseSelectDialog();

public slots:
    void selectLocalDatabase();
    void selectRemoteDatabase();

private slots:
    void on_localBrowseBtn_clicked();

private:
    Ui::DatabaseSelectDialog *ui;
};

#endif // DATABASESELECTDIALOG_H
