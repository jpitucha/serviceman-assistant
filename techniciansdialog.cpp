#include "techniciansdialog.h"
#include "ui_techniciansdialog.h"

QStringList TechniciansDialog::data;

TechniciansDialog::TechniciansDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TechniciansDialog)
{
    ui->setupUi(this);
    model = new QStringListModel(this);
    TechniciansDialog::data << "Serwisant 1" << "Serwisant 2" << "Serwisant 3";
    model->setStringList(TechniciansDialog::data);
    ui->listView->setModel(model);
    ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->listView->setCurrentIndex(model->index(0));
}

TechniciansDialog::~TechniciansDialog()
{
    delete ui;
}

void TechniciansDialog::on_addButton_clicked()
{

}

void TechniciansDialog::on_editButton_clicked()
{

}

void TechniciansDialog::on_deleteButton_clicked()
{

}
