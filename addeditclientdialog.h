#ifndef ADDEDITCLIENTDIALOG_H
#define ADDEDITCLIENTDIALOG_H

#include <QDialog>

namespace Ui {
class AddEditClientDialog;
}

class AddEditClientDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddEditClientDialog(QString text, QString client = "", QWidget *parent = nullptr);
    QString getClient();
    ~AddEditClientDialog();

private:
    Ui::AddEditClientDialog *ui;
};

#endif // ADDEDITCLIENTDIALOG_H
