#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    QStringList clientsList;
    QStringList modelsList;
    QStringList damagesList;
    QStringList techniciansList;
    QStringList labels;
    QStringList devicesList;
    ~MainWindow();

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
