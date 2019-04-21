#include "damagesdialog.h"
#include "ui_damagesdialog.h"

QStringList DamagesDialog::data;

DamagesDialog::DamagesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DamagesDialog)
{
    ui->setupUi(this);
    model = new QStringListModel(this);
    DamagesDialog::data << "Usterka 1" << "Usterka 2" << "Usterka 3";
    model->setStringList(DamagesDialog::data);
    ui->listView->setModel(model);
    ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->listView->setCurrentIndex(model->index(0));
}

DamagesDialog::~DamagesDialog()
{
    delete ui;
}

void DamagesDialog::on_addButton_clicked()
{

}

void DamagesDialog::on_editButton_clicked()
{

}

void DamagesDialog::on_deleteButton_clicked()
{

}
