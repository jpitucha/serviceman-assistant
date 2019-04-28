#include "mainwindow.h"
#include <QApplication>

#include "databaseselectdialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DatabaseSelectDialog *dsd = new DatabaseSelectDialog();
    dsd->show();

    MainWindow w;
    w.show();

    return a.exec();
}
