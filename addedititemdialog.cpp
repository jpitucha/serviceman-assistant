#include "addedititemdialog.h"
#include "ui_addedititemdialog.h"

AddEditItemDialog::AddEditItemDialog(QString windowTitle, QString text, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEditItemDialog)
{
    ui->setupUi(this);
    setWindowTitle(windowTitle);
    ui->lineEdit->setText(text);
}

AddEditItemDialog::~AddEditItemDialog()
{
    delete ui;
}

QString AddEditItemDialog::getText() {
    return ui->lineEdit->text();
}
