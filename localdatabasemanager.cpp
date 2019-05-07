#include "localdatabasemanager.h"

#include <QVariant>

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

QStringList LocalDatabaseManager::getAll(QString table) {
    q->exec("SELECT * FROM " + table + ";");
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

void LocalDatabaseManager::addRecord(QString table, QStringList data) {
    QString *args = new QString();
    for (int i = 0; i < data.size(); i++) {
        if (i < data.size() - 1) args->append(data.at(i).split('=').at(0) + ", "); else args->append(data.at(i).split('=').at(0));
    }
    QString *args2 = new QString();
    for (int i = 0; i < data.size(); i++) {
        if (i < data.size() - 1) args2->append("'" + data.at(i).split('=').at(1) + "', "); else args2->append("'" + data.at(i).split('=').at(1) + "'");
    }
    q->exec("INSERT INTO " + table + " (" + *args + ") VALUES (" + *args2 + ");");
    delete args;
    delete args2;
}

void LocalDatabaseManager::editRecord(QString table, int id, QStringList data) {
    QString *args = new QString();
    for (int i = 0; i < data.size(); i++) {
        if (i < data.size() - 1) args->append(data.at(i).split('=').at(0) + "='" + data.at(i).split('=').at(1) + "', "); else args->append(data.at(i).split('=').at(0) + "='" + data.at(i).split('=').at(1) + "'");
    }
    q->exec("UPDATE " + table + " SET " + *args + " WHERE rowid = " + QString::number(id) + ";");
    delete args;
}

void LocalDatabaseManager::deleteRecord(QString table, int id) {
    q->exec("DELETE FROM " + table + " WHERE rowid = " + QString::number(id) + ";");
}
