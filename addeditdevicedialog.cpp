#include "addeditdevicedialog.h"
#include "ui_addeditdevicedialog.h"

AddEditDeviceDialog::AddEditDeviceDialog(QString windowTitle, QStringList allClients, QStringList allModels, QWidget *parent, QString sn, QString client, QString model) :
    QDialog(parent),
    ui(new Ui::AddEditDeviceDialog)
{
    ui->setupUi(this);
    setWindowTitle(windowTitle);
    ui->lineEdit->setText(sn);
    ui->clientBox->addItems(allClients);
    ui->clientBox->setCurrentText(client);
    ui->modelBox->addItems(allModels);
    ui->modelBox->setCurrentText(model);
}

AddEditDeviceDialog::~AddEditDeviceDialog()
{
    delete ui;
}

QString AddEditDeviceDialog::getData() {
    return ui->lineEdit->text() + ";" + ui->clientBox->currentText() + ";" + ui->modelBox->currentText();
}
