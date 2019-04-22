#include "entriesmanager.h"
#include "ui_entriesmanager.h"
#include "addedititemdialog.h"
#include <QMessageBox>

EntriesManager::EntriesManager(QString windowTitle, QStringList entries, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EntriesManager)
{
    ui->setupUi(this);
    setWindowTitle(windowTitle);
    data = entries;
    model = new QStringListModel(this);
    model->setStringList(data);
    ui->listView->setModel(model);
    ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->listView->setCurrentIndex(model->index(0));
}

EntriesManager::~EntriesManager()
{
    delete ui;
}

void EntriesManager::on_addButton_clicked()
{
    AddEditItemDialog *dialog = new AddEditItemDialog("Dodaj");
    if (dialog->exec() == QDialog::Accepted) {
        if (dialog->getText() != "") {
            if (!data.contains(dialog->getText())) {
                data.append(dialog->getText());
                model->setStringList(data);
            } else {
                QMessageBox::critical(this, "Błąd", "Taki wpis już istnieje");
            }
        } else {
            QMessageBox::critical(this, "Błąd", "To pole nie może być puste");
        }
    }
}

void EntriesManager::on_editButton_clicked()
{
    AddEditItemDialog *dialog = new AddEditItemDialog("Edytuj", model->stringList().at(ui->listView->currentIndex().row()));
    if (dialog->exec() == QDialog::Accepted) {
        if (dialog->getText() != "") {
            if (!data.contains(dialog->getText())) {
                data.replace(ui->listView->currentIndex().row(), dialog->getText());
                model->setStringList(data);
            } else {
                QMessageBox::critical(this, "Błąd", "Taki wpis już istnieje");
            }
        } else {
            QMessageBox::critical(this, "Błąd", "To pole nie może być puste");
        }
    }
}

void EntriesManager::on_deleteButton_clicked()
{
    if (model->rowCount() > 0) {
        if (QMessageBox::warning(this, "Ostrzeżenie", "Na pewno?", QMessageBox::No, QMessageBox::Yes) == QMessageBox::Yes) {
            data.removeAt(ui->listView->currentIndex().row());
            model->setStringList(data);
        }
    } else {
        QMessageBox::critical(this, "Błąd", "Nic już tu nie ma!");
    }
}
