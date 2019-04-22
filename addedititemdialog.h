#ifndef ADDEDITITEMDIALOG_H
#define ADDEDITITEMDIALOG_H

#include <QDialog>

namespace Ui {
class AddEditItemDialog;
}

class AddEditItemDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddEditItemDialog(QString windowTitle, QString text, QWidget *parent = nullptr);
    QString getText();
    ~AddEditItemDialog();

private:
    Ui::AddEditItemDialog *ui;
};

#endif // ADDEDITITEMDIALOG_H
