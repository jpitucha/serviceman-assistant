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
    explicit DatabaseSelectDialog(bool onStartup = false, QWidget *parent = nullptr);
    char getSelected();
    QString getLocal();
    QString getRemote();
    ~DatabaseSelectDialog();

public slots:
    void selectLocalDatabase();
    void selectRemoteDatabase();

private slots:
    void on_localBrowseBtn_clicked();

private:
    Ui::DatabaseSelectDialog *ui;
    bool onStartup;
};

#endif // DATABASESELECTDIALOG_H
