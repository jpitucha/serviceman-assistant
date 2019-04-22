#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    QStringList clientsList;
    QStringList devicesList;
    QStringList damagesList;
    QStringList techniciansList;
    ~MainWindow();

private slots:
    void openClientsDialog();
    void openDevicesDialog();
    void openDamagesDialog();
    void openTechniciansDialog();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
