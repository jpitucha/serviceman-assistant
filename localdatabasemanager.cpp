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

void LocalDatabaseManager::addRecord(QString table, int id, QStringList data) {

}

void LocalDatabaseManager::editRecord(QString table, int id, QStringList data) {

}

void LocalDatabaseManager::deleteRecord(QString table, int id) {

}
