#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "clientsdialog.h"
#include "devicesdialog.h"
#include "damagesdialog.h"
#include "techniciansdialog.h"
#include "devicesdatabasedialog.h"

#include "entriesmanager.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionDatabase, SIGNAL(triggered()), new DevicesDatabaseDialog, SLOT(open()));
    connect(ui->actionClients, SIGNAL(triggered()), new ClientsDialog, SLOT(open()));
    connect(ui->actionDevices, SIGNAL(triggered()), new DevicesDialog, SLOT(open()));
    connect(ui->actionDamages, SIGNAL(triggered()), new DamagesDialog, SLOT(open()));
    connect(ui->actionTechnicians, SIGNAL(triggered()), this, SLOT(openTechniciansDialog()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openTechniciansDialog() {
    QStringList list;
    list << "Serwisant 1" << "Serwisant 22" << "Serwisant 3";
    EntriesManager *em = new EntriesManager("Serwisanci", list);
    em->open();
}
