#include "clientsdialog.h"
#include "ui_clientsdialog.h"

#include <QStringListModel>
#include <QMessageBox>
#include "addeditclientdialog.h"
#include "QDebug"

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
    AddEditClientDialog *dialog = new AddEditClientDialog("Dodaj");
    if (dialog->exec() == QDialog::Accepted) {
        if (dialog->getClient() != "") {
            if (!ClientsDialog::data.contains(dialog->getClient())) {
                ClientsDialog::data.append(dialog->getClient());
                model->setStringList(ClientsDialog::data);
            } else {
                QMessageBox::critical(this, "Błąd", "Taki klient już istnieje");
            }
        } else {
            QMessageBox::critical(this, "Błąd", "To pole nie może być puste");
        }
    }
}

void ClientsDialog::on_editButton_clicked()
{
    AddEditClientDialog *dialog = new AddEditClientDialog("Edytuj", model->stringList().at(ui->listView->currentIndex().row()));
    if (dialog->exec() == QDialog::Accepted) {
        if (dialog->getClient() != "") {
            if (!ClientsDialog::data.contains(dialog->getClient())) {
                ClientsDialog::data.replace(ui->listView->currentIndex().row(), dialog->getClient());
                model->setStringList(ClientsDialog::data);
            } else {
                QMessageBox::critical(this, "Błąd", "Taki klient już istnieje");
            }
        } else {
            QMessageBox::critical(this, "Błąd", "To pole nie może być puste");
        }
    }
}

void ClientsDialog::on_deleteButton_clicked()
{
    if (model->rowCount() > 0) {
        if (QMessageBox::warning(this, "Ostrzeżenie", "Na pewno?", QMessageBox::No, QMessageBox::Yes) == QMessageBox::Yes) {
            model->removeRow(ui->listView->currentIndex().row());
            ClientsDialog::data = model->stringList();
        }
    } else {
        QMessageBox::critical(this, "Błąd", "Nic już tu nie ma!");
    }
}
