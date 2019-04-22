#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "entriesmanager.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionClients, SIGNAL(triggered()), this, SLOT(openClientsDialog()));
    connect(ui->actionDevices, SIGNAL(triggered()), this, SLOT(openDevicesDialog()));
    connect(ui->actionDamages, SIGNAL(triggered()), this, SLOT(openDamagesDialog()));
    connect(ui->actionTechnicians, SIGNAL(triggered()), this, SLOT(openTechniciansDialog()));
    clientsList << "Klient 1" << "Klient 2" << "Klient 3";
    devicesList << "Urządzenie 1" << "Urządzenie 2" << "Urządzenie 3";
    damagesList << "Usterka 1" << "Usterka 2" << "Usterka 3";
    techniciansList << "Serwisant 1" << "Serwisant 2" << "Serwisant 3";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openClientsDialog() {
    EntriesManager *em = new EntriesManager("Serwisanci", clientsList);
    em->open();
}

void MainWindow::openDevicesDialog() {
    EntriesManager *em = new EntriesManager("Serwisanci", devicesList);
    em->open();
}

void MainWindow::openDamagesDialog() {
    EntriesManager *em = new EntriesManager("Serwisanci", damagesList);
    em->open();
}

void MainWindow::openTechniciansDialog() {
    EntriesManager *em = new EntriesManager("Serwisanci", techniciansList);
    em->open();
}
