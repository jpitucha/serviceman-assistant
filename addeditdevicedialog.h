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
    explicit AddEditDeviceDialog(QString action, QString device = "", QWidget *parent = nullptr);
    QString getDevice();
    ~AddEditDeviceDialog();

private:
    Ui::AddEditDeviceDialog *ui;
};

#endif // ADDEDITDEVICEDIALOG_H
