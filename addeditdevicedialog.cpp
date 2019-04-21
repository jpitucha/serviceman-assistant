#include "addeditdevicedialog.h"
#include "ui_addeditdevicedialog.h"

AddEditDeviceDialog::AddEditDeviceDialog(QString action, QString device, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEditDeviceDialog)
{
    ui->setupUi(this);
    setWindowTitle(action);
    ui->label->setText(action + " " + ui->label->text());
    ui->lineEdit->setText(device);
}

AddEditDeviceDialog::~AddEditDeviceDialog()
{
    delete ui;
}

QString AddEditDeviceDialog::getDevice() {
    return ui->lineEdit->text();
}
