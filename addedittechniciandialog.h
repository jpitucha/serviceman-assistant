#ifndef ADDEDITTECHNICIANDIALOG_H
#define ADDEDITTECHNICIANDIALOG_H

#include <QDialog>

namespace Ui {
class AddEditTechnicianDialog;
}

class AddEditTechnicianDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddEditTechnicianDialog(QString action, QString name = "", QWidget *parent = nullptr);
    QString getTechnician();
    ~AddEditTechnicianDialog();

private:
    Ui::AddEditTechnicianDialog *ui;
};

#endif // ADDEDITTECHNICIANDIALOG_H
