#include "clientsdialog.h"
#include "ui_clientsdialog.h"

#include <QStringListModel>

QStringList ClientsDialog::data;

ClientsDialog::ClientsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientsDialog)
{
    ui->setupUi(this);

    model = new QStringListModel(this);

    ClientsDialog::data << "Firma 1" << "Firma 2" << "Firma 3";

    model->setStringList(ClientsDialog::data);
    ui->listView->setModel(model);
    ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

ClientsDialog::~ClientsDialog()
{
    delete ui;
}
