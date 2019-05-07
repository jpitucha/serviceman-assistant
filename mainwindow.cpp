#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "entriesmanager.h"
#include "addeditdevicedialog.h"
#include <QMessageBox>
#include "databasemanager.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionClients, SIGNAL(triggered()), this, SLOT(openClientsDialog()));
    connect(ui->actionModels, SIGNAL(triggered()), this, SLOT(openDevicesDialog()));
    connect(ui->actionDamages, SIGNAL(triggered()), this, SLOT(openDamagesDialog()));
    connect(ui->actionTechnicians, SIGNAL(triggered()), this, SLOT(openTechniciansDialog()));
    connect(ui->actionAdd, SIGNAL(triggered()), this, SLOT(openAddDeviceDialog()));
    connect(ui->actionEdit, SIGNAL(triggered()), this, SLOT(openEditDeviceDialog()));
    connect(ui->actionDelete, SIGNAL(triggered()), this, SLOT(deleteDevice()));

    labels << "SN" << "Klient" << "Model";

//    clientsList << "Klient 1" << "Klient 2" << "Klient 3";
//    modelsList << "Urządzenie 1" << "Urządzenie 2" << "Urządzenie 3";
//    damagesList << "Usterka 1" << "Usterka 2" << "Usterka 3";
//    techniciansList << "Serwisant 1" << "Serwisant 2" << "Serwisant 3";

    model = new QStandardItemModel(this);
    model->setHorizontalHeaderLabels(labels);
    ui->tableView->setModel(model);
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
        if (QMessageBox::critical(this, "Błąd", "Nieznana lokalizacja bazy danych. Popraw ustawienia!") == QMessageBox::Ok) {
            dsd = new DatabaseSelectDialog(true, this);
            connect(dsd, SIGNAL(accepted()), this, SLOT(retry()));
            dsd->show();
        }
        break;
    }
    case 4: {
        if (QMessageBox::critical(this, "Błąd", "Nieznany typ połączenia z bazą danych. Popraw ustawienia!") == QMessageBox::Ok) {
            dsd = new DatabaseSelectDialog(true, this);
            connect(dsd, SIGNAL(accepted()), this, SLOT(retry()));
            dsd->show();
        }
        break;
    }
    case 5: {
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

}

void MainWindow::retry() {
    if (dsd->getSelected() == 'l') {
        DatabaseManager::getInstance()->saveLocalSettings(dsd->getLocal());
    } else if (dsd->getSelected() == 'r') {
        DatabaseManager::getInstance()->saveRemoteSettings(dsd->getRemote());
    }
    dsd->deleteLater();
    start();
}

void MainWindow::openClientsDialog() {
//    EntriesManager *em = new EntriesManager("Klienci", clientsList, this);
//    em->open();
}

void MainWindow::openDevicesDialog() {
//    EntriesManager *em = new EntriesManager("Modele", modelsList, this);
//    em->open();
}

void MainWindow::openDamagesDialog() {
//    EntriesManager *em = new EntriesManager("Usterki", damagesList, this);
//    em->open();
}

void MainWindow::openTechniciansDialog() {
//    EntriesManager *em = new EntriesManager("Serwisanci", techniciansList, this);
//    em->open();
}

void MainWindow::openAddDeviceDialog() {
    AddEditDeviceDialog *dialog = new AddEditDeviceDialog("Dodaj", clientsList, modelsList, this);
    if (dialog->exec() == QDialog::Accepted) {
        if (dialog->getData().split(';')[0] != "") {
            if (!checkIfDeviceListContainsSN()) { // devicelist SN PART !!!
                devicesList.append(dialog->getData());
                QList<QStandardItem*> tmpList;
                tmpList.append(new QStandardItem(dialog->getData().split(';')[0]));
                tmpList.append(new QStandardItem(dialog->getData().split(';')[1]));
                tmpList.append(new QStandardItem(dialog->getData().split(';')[2]));
                model->appendRow(tmpList);
            } else {
                QMessageBox::critical(this, "Błąd", "Taki wpis już istnieje");
            }
        } else {
            QMessageBox::critical(this, "Błąd", "To pole nie może być puste");
        }
    }
}

void MainWindow::openEditDeviceDialog() {
    QStringList *tmpDevice = new QStringList(devicesList.at(ui->tableView->currentIndex().row()).split(';'));
    AddEditDeviceDialog *dialog = new AddEditDeviceDialog("Dodaj", clientsList, modelsList, this, tmpDevice->at(0), tmpDevice->at(1), tmpDevice->at(2));
    if (dialog->exec() == QDialog::Accepted) {
        if (dialog->getData().split(';')[0] != "") {
            if (!checkIfDeviceListContainsSN()) {
                devicesList.replace(ui->tableView->currentIndex().row(), dialog->getData());
                model->setData(model->index(ui->tableView->currentIndex().row(), 0), QVariant(tmpDevice->at(0)));
                model->setData(model->index(ui->tableView->currentIndex().row(), 1), QVariant(tmpDevice->at(1)));
                model->setData(model->index(ui->tableView->currentIndex().row(), 2), QVariant(tmpDevice->at(2)));
                model->dataChanged(model->index(ui->tableView->currentIndex().row(), 0), model->index(ui->tableView->currentIndex().row(), 2));
            } else {
                QMessageBox::critical(this, "Błąd", "Taki wpis już istnieje");
            }
        } else {
            QMessageBox::critical(this, "Błąd", "To pole nie może być puste");
        }
    }
}

void MainWindow::deleteDevice() {
    QModelIndex *tmpIndex = new QModelIndex(ui->tableView->currentIndex());
    if (model->rowCount() > 0) {
        if (QMessageBox::warning(this, "Ostrzeżenie", "Na pewno?", QMessageBox::No, QMessageBox::Yes) == QMessageBox::Yes) {
            devicesList.removeAt(tmpIndex->row());
            model->removeRows(tmpIndex->row(), 1);
        }
    } else {
        QMessageBox::critical(this, "Błąd", "Nic już tu nie ma!");
    }

}

bool MainWindow::checkIfDeviceListContainsSN() {
    return false;
}

MainWindow::~MainWindow()
{
    delete ui;
}
