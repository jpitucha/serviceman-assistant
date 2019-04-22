#ifndef ADDEDITDEVICEDIALOG_H
#define ADDEDITDEVICEDIALOG_H

#include <QDialog>

namespace Ui {
class AddEditDeviceDialog;
}

class AddEditDeviceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddEditDeviceDialog(QString windowTitle, QStringList allClients, QStringList allModels, QWidget *parent = nullptr, QString sn = "", QString client = "", QString model = "");
    QString getData();
    ~AddEditDeviceDialog();

private:
    Ui::AddEditDeviceDialog *ui;
};

#endif // ADDEDITDEVICEDIALOG_H
