#include "entriesmanager.h"
#include "ui_entriesmanager.h"
#include "addedititemdialog.h"
#include <QMessageBox>
#include "databasemanager.h"

EntriesManager::EntriesManager(QString windowTitle, QString table, QString column, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EntriesManager)
{
    ui->setupUi(this);
    setWindowTitle(windowTitle);
    this->table = table;
    this->column = column;
    model = new QStringListModel(this);

    QStringList *tempSL = new QStringList(DatabaseManager::getInstance()->getAll(table, column));

    if (tempSL->size() > 0) {
        QMap<QString, QString> *tempM = new QMap<QString, QString>();
        for (int i = 0; i < tempSL->size(); i++) {
            tempM->clear();
            tempM->insert("id", tempSL->at(i).split(";").at(0));
            tempM->insert("data", tempSL->at(i).split(";").at(1));
            data.append(*tempM);
        }
        delete tempM;
        tempSL = new QStringList();
        for (int i = 0; i < data.size(); i++) {
            tempSL->append(data.at(i).value("data"));
        }
        model->setStringList(*tempSL);
        delete  tempSL;
        ui->listView->setCurrentIndex(model->index(0));
    } else {
        ui->editButton->setEnabled(false);
        ui->deleteButton->setEnabled(false);
    }
    ui->listView->setModel(model);
}

void EntriesManager::on_addButton_clicked() {
    AddEditItemDialog *dialog = new AddEditItemDialog("Dodaj", "", this);
    if (dialog->exec() == QDialog::Accepted) {
        if (dialog->getText() != "") {
            if (!recordExists(dialog->getText())) {
                model->insertRow(data.size());
                model->setData(model->index(data.size()), dialog->getText());
                DatabaseManager::getInstance()->addRecord(table, QStringList(column + "=" + dialog->getText()));
                QMap<QString, QString> *tempM = new QMap<QString, QString>();
                tempM->insert("id", DatabaseManager::getInstance()->getLastID(table));
                tempM->insert("data", dialog->getText());
                data.append(*tempM);
                delete tempM;
                ui->listView->setCurrentIndex(model->index(model->rowCount() - 1));
                ui->editButton->setEnabled(true);
                ui->deleteButton->setEnabled(true);
            } else {
                QMessageBox::critical(this, "Błąd", "Taki wpis już istnieje");
            }
        } else {
            QMessageBox::critical(this, "Błąd", "To pole nie może być puste");
        }
    }
}

void EntriesManager::on_editButton_clicked() {
    QModelIndex *tmpIndex = new QModelIndex(ui->listView->currentIndex());
    QString *selected = new  QString(model->stringList().at(tmpIndex->row()));
    AddEditItemDialog *dialog = new AddEditItemDialog("Edytuj", *selected, this);
    if (dialog->exec() == QDialog::Accepted) {
        if (dialog->getText() != "") {
            if (!recordExists(dialog->getText())) {
                model->setData(*tmpIndex, dialog->getText());
                QString *id = new QString();
                for (int i = 0; i < data.size(); i++) {
                    if (data.at(i).value("data") == *selected) {
                        *id = data.at(i).value("id");
                        QMap<QString, QString> *tempM = new QMap<QString, QString>();
                        tempM->insert("id", *id);
                        tempM->insert("data", dialog->getText());
                        data.replace(i, *tempM);
                        delete tempM;
                        break;
                    }
                }
                DatabaseManager::getInstance()->editRecord(table, id->toInt(), QStringList(column + "=" + dialog->getText()));
                delete id;
                ui->listView->setCurrentIndex(*tmpIndex);
            } else {
                QMessageBox::critical(this, "Błąd", "Taki wpis już istnieje");
            }
        } else {
            QMessageBox::critical(this, "Błąd", "To pole nie może być puste");
        }
    }
}

void EntriesManager::on_deleteButton_clicked() {
    QModelIndex *tmpIndex = new QModelIndex(ui->listView->currentIndex());
    if (QMessageBox::warning(this, "Ostrzeżenie", "Na pewno?", QMessageBox::No, QMessageBox::Yes) == QMessageBox::Yes) {
        QString *selected = new QString(model->stringList().at(tmpIndex->row()));
        QString *id = new QString();
        for (int i = 0; i < data.size(); i++) {
            if (data.at(i).value("data") == *selected) {
                *id = data.at(i).value("id");
                break;
            }
        }
        model->removeRow(tmpIndex->row());
        data.removeAt(tmpIndex->row());
        DatabaseManager::getInstance()->deleteRecord(table, id->toInt());
        if (model->rowCount() > 0) {
            if (model->rowCount() - 1 >= tmpIndex->row()) {
                ui->listView->setCurrentIndex(*tmpIndex);
            } else if (tmpIndex->row() == model->rowCount()) {
                ui->listView->setCurrentIndex(model->index(model->rowCount() - 1));
            }
        } else {
            ui->editButton->setEnabled(false);
            ui->deleteButton->setEnabled(false);
        }
    }
}

bool EntriesManager::recordExists(QString record) {
    for (int i = 0; i < data.size(); i++) {
        if (data.at(i).value("data") == record) return true;
    }
    return false;
}

EntriesManager::~EntriesManager()
{
    delete ui;
}
