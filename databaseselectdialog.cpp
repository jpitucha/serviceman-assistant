#include "databaseselectdialog.h"
#include "ui_databaseselectdialog.h"

#include <QFileDialog>
#include <QMessageBox>
#include "databasemanager.h"

DatabaseSelectDialog::DatabaseSelectDialog(bool onStartup, QWidget *parent) : QDialog(parent),
    ui(new Ui::DatabaseSelectDialog) {
    ui->setupUi(this);
    this->onStartup = onStartup;
    connect(ui->okBtn, SIGNAL(clicked()), this, SLOT(accept()));
}

QString DatabaseSelectDialog::getPath() {
    return ui->localPath->text();
}

void DatabaseSelectDialog::on_localBrowseBtn_clicked() {
    QString *tmpName = new QString(QFileDialog::getOpenFileName(this, "Otwórz bazę danych", QDir::currentPath(), "SQLite3 database (*.db)", nullptr, QFileDialog::DontUseNativeDialog));
    if (*tmpName != "") {
        ui->localPath->setText(*tmpName);
    }
}

void DatabaseSelectDialog::reject() {
    if (onStartup) {
        if (QMessageBox::question(this, "Uwaga", "To spowoduje zamknięcie aplikacji. Kontynuować?") == QMessageBox::Yes) {
            QApplication::quit();
        }
    } else QDialog::reject();
}

void DatabaseSelectDialog::accept() {
    if (getPath().isEmpty()) {
        QMessageBox::warning(this, "Uwaga", "To pole nie może być puste");
    } else {
        DatabaseManager::getInstance()->saveSettings(getPath());
        QDialog::accept();
    }
}

DatabaseSelectDialog::~DatabaseSelectDialog() {
    delete ui;
}
