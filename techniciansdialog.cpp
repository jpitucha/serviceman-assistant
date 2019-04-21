#include "techniciansdialog.h"
#include "ui_techniciansdialog.h"

#include "addedittechniciandialog.h"
#include <QMessageBox>

QStringList TechniciansDialog::data;

TechniciansDialog::TechniciansDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TechniciansDialog)
{
    ui->setupUi(this);
    model = new QStringListModel(this);
    TechniciansDialog::data << "Serwisant 1" << "Serwisant 2" << "Serwisant 3";
    model->setStringList(TechniciansDialog::data);
    ui->listView->setModel(model);
    ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->listView->setCurrentIndex(model->index(0));
}

TechniciansDialog::~TechniciansDialog()
{
    delete ui;
}

void TechniciansDialog::on_addButton_clicked()
{
    AddEditTechnicianDialog *dialog = new AddEditTechnicianDialog("Dodaj");
    if (dialog->exec() == QDialog::Accepted) {
        if (dialog->getTechnician() != "") {
            if (!TechniciansDialog::data.contains(dialog->getTechnician())) {
                TechniciansDialog::data.append(dialog->getTechnician());
                model->setStringList(TechniciansDialog::data);
            } else {
                QMessageBox::critical(this, "Błąd", "Taki serwisant już istnieje");
            }
        } else {
            QMessageBox::critical(this, "Błąd", "To pole nie może być puste");
        }
    }
}

void TechniciansDialog::on_editButton_clicked()
{
    AddEditTechnicianDialog *dialog = new AddEditTechnicianDialog("Edytuj", model->stringList().at(ui->listView->currentIndex().row()));
    if (dialog->exec() == QDialog::Accepted) {
        if (dialog->getTechnician() != "") {
            if (!TechniciansDialog::data.contains(dialog->getTechnician())) {
                TechniciansDialog::data.replace(ui->listView->currentIndex().row(), dialog->getTechnician());
                model->setStringList(TechniciansDialog::data);
            } else {
                QMessageBox::critical(this, "Błąd", "Takie urządzenie już istnieje");
            }
        } else {
            QMessageBox::critical(this, "Błąd", "To pole nie może być puste");
        }
    }
}

void TechniciansDialog::on_deleteButton_clicked()
{
    if (model->rowCount() > 0) {
        if (QMessageBox::warning(this, "Ostrzeżenie", "Na pewno?", QMessageBox::No, QMessageBox::Yes) == QMessageBox::Yes) {
            TechniciansDialog::data.removeAt(ui->listView->currentIndex().row());
            model->setStringList(TechniciansDialog::data);
        }
    } else {
        QMessageBox::critical(this, "Błąd", "Nic już tu nie ma!");
    }
}
