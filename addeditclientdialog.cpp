#include "addeditclientdialog.h"
#include "ui_addeditclientdialog.h"

#include <QDebug>

AddEditClientDialog::AddEditClientDialog(QString text, QString client, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEditClientDialog)
{
    ui->setupUi(this);
    setWindowTitle(text);
    ui->label->setText(text + " " + ui->label->text());
    ui->lineEdit->setText(client);
}

AddEditClientDialog::~AddEditClientDialog()
{
    delete ui;
}

QString AddEditClientDialog::getClient() {
    return ui->lineEdit->text();
}
