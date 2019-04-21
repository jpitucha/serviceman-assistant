#include "addeditdevicedialog.h"
#include "ui_addeditdevicedialog.h"

AddEditDeviceDialog::AddEditDeviceDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEditDeviceDialog)
{
    ui->setupUi(this);
}

AddEditDeviceDialog::~AddEditDeviceDialog()
{
    delete ui;
}

QString AddEditDeviceDialog::getDevice() {
    return ui->lineEdit->text();
}
