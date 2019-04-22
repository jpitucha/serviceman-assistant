#include "entriesmanager.h"
#include "ui_entriesmanager.h"
#include "addedititemdialog.h"

EntriesManager::EntriesManager(QString windowTitle, QStringList entries, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EntriesManager)
{
    ui->setupUi(this);
    setWindowTitle(windowTitle);
    data = entries;
    model = new QStringListModel(this);
    model->setStringList(data);
    ui->listView->setModel(model);
    ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->listView->setCurrentIndex(model->index(0));
}

EntriesManager::~EntriesManager()
{
    delete ui;
}

void EntriesManager::on_addButton_clicked()
{

}

void EntriesManager::on_editButton_clicked()
{

}

void EntriesManager::on_deleteButton_clicked()
{

}
