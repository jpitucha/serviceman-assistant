#include "addeditdamagedialog.h"
#include "ui_addeditdamagedialog.h"

AddEditDamageDialog::AddEditDamageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEditDamageDialog)
{
    ui->setupUi(this);
}

AddEditDamageDialog::~AddEditDamageDialog()
{
    delete ui;
}
