#include "entriesmanager.h"
#include "ui_entriesmanager.h"

EntriesManager::EntriesManager(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EntriesManager)
{
    ui->setupUi(this);
}

EntriesManager::~EntriesManager()
{
    delete ui;
}
