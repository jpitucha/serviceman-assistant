#include "addeditclientdialog.h"
#include "ui_addeditclientdialog.h"

AddEditClientDialog::AddEditClientDialog(QString action, QString client, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEditClientDialog)
{
    ui->setupUi(this);
    setWindowTitle(action);
    ui->label->setText(action + " " + ui->label->text());
    ui->lineEdit->setText(client);
}

AddEditClientDialog::~AddEditClientDialog()
{
    delete ui;
}

QString AddEditClientDialog::getClient() {
    return ui->lineEdit->text();
}
