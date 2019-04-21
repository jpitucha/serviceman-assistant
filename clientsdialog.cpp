#include "clientsdialog.h"
#include "ui_clientsdialog.h"

ClientsDialog::ClientsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientsDialog)
{
    ui->setupUi(this);
}

ClientsDialog::~ClientsDialog()
{
    delete ui;
}
