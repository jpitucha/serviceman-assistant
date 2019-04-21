#include "damagesdialog.h"
#include "ui_damagesdialog.h"

#include "addeditdamagedialog.h"
#include <QMessageBox>

QStringList DamagesDialog::data;

DamagesDialog::DamagesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DamagesDialog)
{
    ui->setupUi(this);
    model = new QStringListModel(this);
    DamagesDialog::data << "Usterka 1" << "Usterka 2" << "Usterka 3";
    model->setStringList(DamagesDialog::data);
    ui->listView->setModel(model);
    ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->listView->setCurrentIndex(model->index(0));
}

DamagesDialog::~DamagesDialog()
{
    delete ui;
}

void DamagesDialog::on_addButton_clicked()
{
    AddEditDamageDialog *dialog = new AddEditDamageDialog("Dodaj");
    if (dialog->exec() == QDialog::Accepted) {
        if (dialog->getDamage() != "") {
            if (!DamagesDialog::data.contains(dialog->getDamage())) {
                DamagesDialog::data.append(dialog->getDamage());
                model->setStringList(DamagesDialog::data);
            } else {
                QMessageBox::critical(this, "Błąd", "Taka usterka już istnieje");
            }
        } else {
            QMessageBox::critical(this, "Błąd", "To pole nie może być puste");
        }
    }
}

void DamagesDialog::on_editButton_clicked()
{
    AddEditDamageDialog *dialog = new AddEditDamageDialog("Edytuj", model->stringList().at(ui->listView->currentIndex().row()));
    if (dialog->exec() == QDialog::Accepted) {
        if (dialog->getDamage() != "") {
            if (!DamagesDialog::data.contains(dialog->getDamage())) {
                DamagesDialog::data.replace(ui->listView->currentIndex().row(), dialog->getDamage());
                model->setStringList(DamagesDialog::data);
            } else {
                QMessageBox::critical(this, "Błąd", "Taka usterka już istnieje");
            }
        } else {
            QMessageBox::critical(this, "Błąd", "To pole nie może być puste");
        }
    }
}

void DamagesDialog::on_deleteButton_clicked()
{
    if (model->rowCount() > 0) {
        if (QMessageBox::warning(this, "Ostrzeżenie", "Na pewno?", QMessageBox::No, QMessageBox::Yes) == QMessageBox::Yes) {
            DamagesDialog::data.removeAt(ui->listView->currentIndex().row());
            model->setStringList(DamagesDialog::data);
        }
    } else {
        QMessageBox::critical(this, "Błąd", "Nic już tu nie ma!");
    }
}
