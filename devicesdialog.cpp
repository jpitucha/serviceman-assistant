#include "devicesdialog.h"
#include "ui_devicesdialog.h"

#include "addeditdevicedialog.h"
#include <QStringListModel>

QStringList DevicesDialog::data;

DevicesDialog::DevicesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DevicesDialog)
{
    ui->setupUi(this);
    model = new QStringListModel(this);
    DevicesDialog::data << "Urządzenie 1" << "Urządzenie 2" << "Urządzenie 3";
    model->setStringList(DevicesDialog::data);
    ui->listView->setModel(model);
    ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->listView->setCurrentIndex(model->index(0));
}

DevicesDialog::~DevicesDialog()
{
    delete ui;
}

void DevicesDialog::on_addButton_clicked()
{

}

void DevicesDialog::on_editButton_clicked()
{

}

void DevicesDialog::on_deleteButton_clicked()
{

}
