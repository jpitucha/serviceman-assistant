#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include "databaseselectdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void start();
    DatabaseSelectDialog *dsd;
    QStringList clientsList;
    QStringList modelsList;
    QStringList damagesList;
    QStringList techniciansList;
    QStringList labels;
    QStringList devicesList;
    bool checkIfDeviceListContainsSN();
    ~MainWindow();

public slots:
    void retry();

private slots:
    void openClientsDialog();
    void openDevicesDialog();
    void openDamagesDialog();
    void openTechniciansDialog();
    void openAddDeviceDialog();
    void openEditDeviceDialog();
    void deleteDevice();

private:
    Ui::MainWindow *ui;
    QStandardItemModel *model;
};

#endif // MAINWINDOW_H
