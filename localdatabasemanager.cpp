#include "localdatabasemanager.h"

#include <QDebug>

LocalDatabaseManager::LocalDatabaseManager(QString path, QObject *parent) : QObject(parent)
{
    this->path = path;
}

bool LocalDatabaseManager::init() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);
    db.open();
    if (db.isOpen()) q = new QSqlQuery(db);
    return db.isOpen();
}

QStringList LocalDatabaseManager::getAllClients() {
    q->exec("SELECT * FROM clients");
    QStringList *tmp = new QStringList();
    while (q->next()) {
        tmp->append(q->value(0).toString());
    }
    return *tmp;
}

QStringList LocalDatabaseManager::getAllDamages() {
    q->exec("SELECT * FROM damages");
    QStringList *tmp = new QStringList();
    while (q->next()) {
        tmp->append(q->value(0).toString());
    }
    return *tmp;
}

QStringList LocalDatabaseManager::getAllModels() {
    q->exec("SELECT * FROM models");
    QStringList *tmp = new QStringList();
    while (q->next()) {
        tmp->append(q->value(0).toString());
    }
    return *tmp;
}

QStringList LocalDatabaseManager::getAllTechnicians() {
    q->exec("SELECT * FROM technicians");
    QStringList *tmp = new QStringList();
    while (q->next()) {
        tmp->append(q->value(0).toString());
    }
    return *tmp;
}
