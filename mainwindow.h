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
    QStringList list;
    ~MainWindow();

private slots:
    void openTechniciansDialog();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
