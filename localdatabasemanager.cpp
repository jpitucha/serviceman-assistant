#include "localdatabasemanager.h"

#include <QDebug>

LocalDatabaseManager::LocalDatabaseManager(QString path, QObject *parent) : QObject(parent)
{
    this->path = path;
}

bool LocalDatabaseManager::init() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);
    if (db.open()) q = new QSqlQuery(db);
    return db.isOpen();
}

QStringList LocalDatabaseManager::getAllClients() {
    q->exec("SELECT * FROM clients");
    tmp = new QStringList();
    while (q->next()) {
        tmp->append(q->value(0).toString());
    }
    return *tmp;
}

QStringList LocalDatabaseManager::getAllDamages() {
    q->exec("SELECT * FROM damages");
    tmp = new QStringList();
    while (q->next()) {
        tmp->append(q->value(0).toString());
    }
    return *tmp;
}

QStringList LocalDatabaseManager::getAllModels() {
    q->exec("SELECT * FROM models");
    tmp = new QStringList();
    while (q->next()) {
        tmp->append(q->value(0).toString());
    }
    return *tmp;
}

QStringList LocalDatabaseManager::getAllTechnicians() {
    q->exec("SELECT * FROM technicians");
    tmp = new QStringList();
    while (q->next()) {
        tmp->append(q->value(0).toString());
    }
    return *tmp;
}

QStringList LocalDatabaseManager::getAll(QString table) {
    q->exec("SELECT * FROM " + table);
    int i = 0;
    tmp = new QStringList();
    while (q->next()) {
        i = 0;
        while (true) {
            if (q->value(i).isValid()) {
                tmp->append(q->value(i).toString());
                i++;
            } else {
                break;
            }
        }
    }
    return *tmp;
}
