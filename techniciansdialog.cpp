#include "techniciansdialog.h"
#include "ui_techniciansdialog.h"

TechniciansDialog::TechniciansDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TechniciansDialog)
{
    ui->setupUi(this);
}

TechniciansDialog::~TechniciansDialog()
{
    delete ui;
}
