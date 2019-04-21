#include "devicesdatabasedialog.h"
#include "ui_devicesdatabasedialog.h"

DevicesDatabaseDialog::DevicesDatabaseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DevicesDatabaseDialog)
{
    ui->setupUi(this);
}

DevicesDatabaseDialog::~DevicesDatabaseDialog()
{
    delete ui;
}
