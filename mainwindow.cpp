#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "entriesmanager.h"
#include "addeditdevicedialog.h"
#include <QDebug>

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

    clientsList << "Klient 1" << "Klient 2" << "Klient 3";
    modelsList << "Urządzenie 1" << "Urządzenie 2" << "Urządzenie 3";
    damagesList << "Usterka 1" << "Usterka 2" << "Usterka 3";
    techniciansList << "Serwisant 1" << "Serwisant 2" << "Serwisant 3";

    model = new QStandardItemModel(this);
    model->setHorizontalHeaderLabels(labels);
    ui->tableView->setModel(model);

    QList<QStandardItem*> lista;
    lista << new QStandardItem("test") << new QStandardItem("test2") << new QStandardItem("test3");

    model->appendRow(lista);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openClientsDialog() {
    EntriesManager *em = new EntriesManager("Klienci", clientsList, this);
    em->open();
}

void MainWindow::openDevicesDialog() {
    EntriesManager *em = new EntriesManager("Modele", modelsList, this);
    em->open();
}

void MainWindow::openDamagesDialog() {
    EntriesManager *em = new EntriesManager("Usterki", damagesList, this);
    em->open();
}

void MainWindow::openTechniciansDialog() {
    EntriesManager *em = new EntriesManager("Serwisanci", techniciansList, this);
    em->open();
}

void MainWindow::openAddDeviceDialog() {
    AddEditDeviceDialog *dialog = new AddEditDeviceDialog("Dodaj", clientsList, modelsList, this);
    dialog->open();
}

void MainWindow::openEditDeviceDialog() {

}

void MainWindow::deleteDevice() {

}
