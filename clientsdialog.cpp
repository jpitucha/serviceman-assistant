#include "clientsdialog.h"
#include "ui_clientsdialog.h"

#include <QStringListModel>
#include <QMessageBox>

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
    ui->listView->setCurrentIndex(model->index(0));
}

ClientsDialog::~ClientsDialog()
{
    delete ui;
}

void ClientsDialog::on_addButton_clicked()
{

}

void ClientsDialog::on_editButton_clicked()
{

}

void ClientsDialog::on_deleteButton_clicked()
{
    if (model->rowCount() > 0) {
        if (QMessageBox::warning(this, "Ostrzeżenie", "Na pewno?", QMessageBox::No, QMessageBox::Yes) == QMessageBox::Yes) {
            model->removeRow(ui->listView->currentIndex().row());
        }
    } else {
        QMessageBox::critical(this, "Błąd", "Nic już tu nie ma!");
    }
    ClientsDialog::data = model->stringList();
}