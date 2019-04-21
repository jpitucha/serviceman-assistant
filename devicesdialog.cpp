#include "devicesdialog.h"
#include "ui_devicesdialog.h"

#include "addeditdevicedialog.h"
#include <QStringListModel>
#include <QMessageBox>

QStringList DevicesDialog::data;

DevicesDialog::DevicesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DevicesDialog)
{
    ui->setupUi(this);
    model = new QStringListModel(this);
    DevicesDialog::data << "Urządzenie 1" << "Urządzenie 2" << "Urządzenie 3";
    model->setStringList(DevicesDialog::data);
    ui->listView->setModel(model);
    ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->listView->setCurrentIndex(model->index(0));
}

DevicesDialog::~DevicesDialog()
{
    delete ui;
}

void DevicesDialog::on_addButton_clicked()
{
    AddEditDeviceDialog *dialog = new AddEditDeviceDialog("Dodaj");
    if (dialog->exec() == QDialog::Accepted) {
        if (dialog->getDevice() != "") {
            if (!DevicesDialog::data.contains(dialog->getDevice())) {
                DevicesDialog::data.append(dialog->getDevice());
                model->setStringList(DevicesDialog::data);
            } else {
                QMessageBox::critical(this, "Błąd", "Takie urządzenie już istnieje");
            }
        } else {
            QMessageBox::critical(this, "Błąd", "To pole nie może być puste");
        }
    }
}

void DevicesDialog::on_editButton_clicked()
{
    AddEditDeviceDialog *dialog = new AddEditDeviceDialog("Edytuj", model->stringList().at(ui->listView->currentIndex().row()));
    if (dialog->exec() == QDialog::Accepted) {
        if (dialog->getDevice() != "") {
            if (!DevicesDialog::data.contains(dialog->getDevice())) {
                DevicesDialog::data.replace(ui->listView->currentIndex().row(), dialog->getDevice());
                model->setStringList(DevicesDialog::data);
            } else {
                QMessageBox::critical(this, "Błąd", "Takie urządzenie już istnieje");
            }
        } else {
            QMessageBox::critical(this, "Błąd", "To pole nie może być puste");
        }
    }
}

void DevicesDialog::on_deleteButton_clicked()
{
    if(model->rowCount() > 0) {
        if (QMessageBox::warning(this, "Ostrzeżenie", "Na pewno?", QMessageBox::No, QMessageBox::Yes) == QMessageBox::Yes) {
            DevicesDialog::data.removeAt(ui->listView->currentIndex().row());
            model->setStringList(DevicesDialog::data);
        }
    } else {
        QMessageBox::critical(this, "Błąd", "Nic już tu nie ma!");
    }
}
