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
    ~MainWindow();

public slots:
    void retry();

private slots:
    void openClientsDialog();
    void openDevicesDialog();
    void openDamagesDialog();
    void openTechniciansDialog();
    void openDatabaseSettings();
    void openAddDeviceDialog();
    void openEditDeviceDialog();
    void deleteDevice();

private:
    void loadData();
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
