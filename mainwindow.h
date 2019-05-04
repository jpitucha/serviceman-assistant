#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QStringListModel>
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
    void loadData();
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
    QStringListModel *devicesModel;
};

#endif // MAINWINDOW_H
