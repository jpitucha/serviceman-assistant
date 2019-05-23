#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "entriesmanager.h"
#include "addeditdevicedialog.h"
#include <QMessageBox>
#include "databasemanager.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionClients, SIGNAL(triggered()), this, SLOT(openClientsDialog()));
    connect(ui->actionModels, SIGNAL(triggered()), this, SLOT(openDevicesDialog()));
    connect(ui->actionDamages, SIGNAL(triggered()), this, SLOT(openDamagesDialog()));
    connect(ui->actionTechnicians, SIGNAL(triggered()), this, SLOT(openTechniciansDialog()));
    connect(ui->actionDatabaseSettings, SIGNAL(triggered()), this, SLOT(openDatabaseSettings()));
    connect(ui->actionAdd, SIGNAL(triggered()), this, SLOT(openAddDeviceDialog()));
    connect(ui->actionEdit, SIGNAL(triggered()), this, SLOT(openEditDeviceDialog()));
    connect(ui->actionDelete, SIGNAL(triggered()), this, SLOT(deleteDevice()));

    devicesModel = new QStringListModel(this);
}

void MainWindow::start() {
    switch (DatabaseManager::getInstance()->init()) {
    case 0: {
        loadData();
        show();
        break;
    }
    case 1: {
        if (QMessageBox::critical(this, "Błąd", "Wystąpił problem przy połączeniu z bazą danych. Popraw ustawienia!") == QMessageBox::Ok) {
            dsd = new DatabaseSelectDialog(true, this);
            connect(dsd, SIGNAL(accepted()), this, SLOT(retry()));
            dsd->show();
        }
        break;
    }
    case 2: {
        if (QMessageBox::critical(this, "Błąd", "Brak ścieżki do bazy danych. Popraw ustawienia!") == QMessageBox::Ok) {
            dsd = new DatabaseSelectDialog(true, this);
            connect(dsd, SIGNAL(accepted()), this, SLOT(retry()));
            dsd->show();
        }
        break;
    }
    case 3: {
        if (QMessageBox::critical(this, "Błąd", "Plik ustawień nie istnieje. Popraw ustawienia!") == QMessageBox::Ok) {
            dsd = new DatabaseSelectDialog(true, this);
            connect(dsd, SIGNAL(accepted()), this, SLOT(retry()));
            dsd->show();
        }
        break;
    }
    }
}

void MainWindow::loadData() {
    QStringList *tempSL = new QStringList(DatabaseManager::getInstance()->getAll("devices", "sn, client, model"));
    if (tempSL->size() > 0) {
        QMap<QString, QString> *tempM = new QMap<QString, QString>();
        for (int i = 0; i < tempSL->size(); i++) {
            tempM->clear();
            tempM->insert("id", tempSL->at(i).split(";").at(0));
            tempM->insert("sn", tempSL->at(i).split(";").at(1));
            tempM->insert("client", tempSL->at(i).split(";").at(2));
            tempM->insert("model", tempSL->at(i).split(";").at(3));
            devices.append(*tempM);
        }
        delete tempM;
        tempSL->clear();
        for (int i = 0; i < devices.size(); i++) {
            tempSL->append(devices.at(i).value("sn") + " (" + devices.at(i).value("client") + ", " + devices.at(i).value("model") + ")");
        }
        devicesModel->setStringList(*tempSL);
        delete tempSL;
        ui->deviceListView->setCurrentIndex(devicesModel->index(0));
    } else {
        //disable edit and delete buttons
    }
    ui->deviceListView->setModel(devicesModel);
}

void MainWindow::retry() {
    dsd->deleteLater();
    start();
}

void MainWindow::openClientsDialog() {
    EntriesManager *em = new EntriesManager("Klienci", "clients", "client", this);
    em->open();
}

void MainWindow::openDevicesDialog() {
    EntriesManager *em = new EntriesManager("Modele", "models", "model", this);
    em->open();
}

void MainWindow::openDamagesDialog() {
    EntriesManager *em = new EntriesManager("Usterki", "damages", "damage", this);
    em->open();
}

void MainWindow::openTechniciansDialog() {
    EntriesManager *em = new EntriesManager("Serwisanci", "technicians", "technician", this);
    em->open();
}

void MainWindow::openDatabaseSettings() {
    dsd = new DatabaseSelectDialog(false, this);
    dsd->open();
}

void MainWindow::openAddDeviceDialog() {
//    AddEditDeviceDialog *dialog = new AddEditDeviceDialog("Dodaj", DatabaseManager::getInstance()->getAll("clients", "client"), DatabaseManager::getInstance()->getAll("models", "model"), this);
//    if (dialog->exec() == QDialog::Accepted) {
//        if (dialog->getData().split(';')[0] != "") {
//            if (!devicesModel.stringList().contains(dialog->getData().split(';').at(0))) {
//                devicesList.append(dialog->getData());
//                QList<QStandardItem*> tmpList;
//                tmpList.append(new QStandardItem(dialog->getData().split(';')[0]));
//                tmpList.append(new QStandardItem(dialog->getData().split(';')[1]));
//                tmpList.append(new QStandardItem(dialog->getData().split(';')[2]));
//                model->appendRow(tmpList);
//            } else {
//                QMessageBox::critical(this, "Błąd", "Taki wpis już istnieje");
//            }
//        } else {
//            QMessageBox::critical(this, "Błąd", "To pole nie może być puste");
//        }
//    }
}

void MainWindow::openEditDeviceDialog() {
//    QStringList *tmpDevice = new QStringList(devicesList.at(ui->tableView->currentIndex().row()).split(';'));
//    AddEditDeviceDialog *dialog = new AddEditDeviceDialog("Dodaj", clientsList, modelsList, this, tmpDevice->at(0), tmpDevice->at(1), tmpDevice->at(2));
//    if (dialog->exec() == QDialog::Accepted) {
//        if (dialog->getData().split(';')[0] != "") {
//            if (!checkIfDeviceListContainsSN()) {
//                devicesList.replace(ui->tableView->currentIndex().row(), dialog->getData());
//                model->setData(model->index(ui->tableView->currentIndex().row(), 0), QVariant(tmpDevice->at(0)));
//                model->setData(model->index(ui->tableView->currentIndex().row(), 1), QVariant(tmpDevice->at(1)));
//                model->setData(model->index(ui->tableView->currentIndex().row(), 2), QVariant(tmpDevice->at(2)));
//                model->dataChanged(model->index(ui->tableView->currentIndex().row(), 0), model->index(ui->tableView->currentIndex().row(), 2));
//            } else {
//                QMessageBox::critical(this, "Błąd", "Taki wpis już istnieje");
//            }
//        } else {
//            QMessageBox::critical(this, "Błąd", "To pole nie może być puste");
//        }
//    }
}

void MainWindow::deleteDevice() {
//    QModelIndex *tmpIndex = new QModelIndex(ui->tableView->currentIndex());
//    if (model->rowCount() > 0) {
//        if (QMessageBox::warning(this, "Ostrzeżenie", "Na pewno?", QMessageBox::No, QMessageBox::Yes) == QMessageBox::Yes) {
//            devicesList.removeAt(tmpIndex->row());
//            model->removeRows(tmpIndex->row(), 1);
//        }
//    } else {
//        QMessageBox::critical(this, "Błąd", "Nic już tu nie ma!");
//    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
