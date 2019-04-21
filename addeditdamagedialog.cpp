#include "addeditdamagedialog.h"
#include "ui_addeditdamagedialog.h"

AddEditDamageDialog::AddEditDamageDialog(QString action, QString damage, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEditDamageDialog)
{
    ui->setupUi(this);
    setWindowTitle(action);
    ui->label->setText(action + " " + ui->label->text());
    ui->lineEdit->setText(damage);
}

AddEditDamageDialog::~AddEditDamageDialog()
{
    delete ui;
}

QString AddEditDamageDialog::getDamage() {
    return ui->lineEdit->text();
}
