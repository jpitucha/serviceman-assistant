#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "clientsdialog.h"
#include "devicesdialog.h"
#include "damagesdialog.h"
#include "techniciansdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionClients, SIGNAL(triggered()), new ClientsDialog, SLOT(open()));
    connect(ui->actionDevices, SIGNAL(triggered()), new DevicesDialog, SLOT(open()));
    connect(ui->actionDamages, SIGNAL(triggered()), new DamagesDialog, SLOT(open()));
    connect(ui->actionTechnicians, SIGNAL(triggered()), new TechniciansDialog, SLOT(open()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
