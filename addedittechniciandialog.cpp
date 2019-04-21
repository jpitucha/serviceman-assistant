#include "addedittechniciandialog.h"
#include "ui_addedittechniciandialog.h"

AddEditTechnicianDialog::AddEditTechnicianDialog(QString action, QString name, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEditTechnicianDialog)
{
    ui->setupUi(this);
    setWindowTitle(action);
    ui->label->setText(action + " " + ui->label->text());
    ui->lineEdit->setText(name);
}

AddEditTechnicianDialog::~AddEditTechnicianDialog()
{
    delete ui;
}

QString AddEditTechnicianDialog::getTechnician() {
    return ui->lineEdit->text();
}
