#include "damagesdialog.h"
#include "ui_damagesdialog.h"

DamagesDialog::DamagesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DamagesDialog)
{
    ui->setupUi(this);
}

DamagesDialog::~DamagesDialog()
{
    delete ui;
}
