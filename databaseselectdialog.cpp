#include "databaseselectdialog.h"
#include "ui_databaseselectdialog.h"

#include <QFileDialog>

DatabaseSelectDialog::DatabaseSelectDialog(bool onStartup, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DatabaseSelectDialog)
{
    ui->setupUi(this);
    this->onStartup = onStartup;
    connect(ui->localRadioBtn, SIGNAL(clicked()), this, SLOT(selectLocalDatabase()));
    connect(ui->remoteRadioBtn, SIGNAL(clicked()), this, SLOT(selectRemoteDatabase()));
    connect(ui->okBtn, SIGNAL(clicked()), this, SLOT(accept()));
}

void DatabaseSelectDialog::selectLocalDatabase() {
    ui->localRadioBtn->setChecked(true);
    ui->localBox->setEnabled(true);
    ui->remoteBox->setEnabled(false);
}

void DatabaseSelectDialog::selectRemoteDatabase() {
    ui->remoteRadioBtn->setChecked(true);
    ui->localBox->setEnabled(false);
    ui->remoteBox->setEnabled(true);
}

DatabaseSelectDialog::~DatabaseSelectDialog()
{
    delete ui;
}

void DatabaseSelectDialog::on_localBrowseBtn_clicked()
{
    QString *tmpName = new QString(QFileDialog::getOpenFileName(this, "Otwórz bazę danych", QDir::currentPath(), "SQLite3 database (*.db)", nullptr, QFileDialog::DontUseNativeDialog));
    if (*tmpName != "") {
        ui->localPath->setText(*tmpName);
    }
}

char DatabaseSelectDialog::getSelected() {
    if (ui->localRadioBtn->isChecked()) {
        return 'l';
    } else {
        return 'r';
    }
}

QString DatabaseSelectDialog::getLocal() {
    return ui->localPath->text();
}

QString DatabaseSelectDialog::getRemote() {
    return ui->remoteHost->text() + ";" + ui->remotePort->text() + ";" + ui->remoteName->text() + ";" + ui->remoteUser->text() + ";" + ui->remotePassword->text();
}
