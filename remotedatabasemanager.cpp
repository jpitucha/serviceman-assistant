#include "remotedatabasemanager.h"

#include <QVariant>
#include <QtSql>

RemoteDatabaseManager::RemoteDatabaseManager(QString host, QString port, QString name, QString user, QString password, QObject *parent) : QObject(parent) {
    this->host = host;
    this->port = port;
    this->name = name;
    this->user = user;
    this->password = password;
}

bool RemoteDatabaseManager::init() {
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(host);
    db.setPort(port.toInt());
    db.setDatabaseName(name);
    db.setUserName(user);
    db.setPassword(password);
    if (db.open()) q = new QSqlQuery(db);
    return db.isOpen();
}

QStringList RemoteDatabaseManager::getAll(QString table) {
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

void RemoteDatabaseManager::addRecord(QString table, QStringList data) {
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

void RemoteDatabaseManager::editRecord(QString table, int id, QStringList data) {
    QString *args = new QString();
    for (int i = 0; i < data.size(); i++) {
        if (i < data.size() - 1) args->append(data.at(i).split('=').at(0) + "='" + data.at(i).split('=').at(1) + "', "); else args->append(data.at(i).split('=').at(0) + "='" + data.at(i).split('=').at(1) + "'");
    }
    q->exec("UPDATE " + table + " SET " + *args + " WHERE rowid = " + QString::number(id) + ";");
    delete args;
}

void RemoteDatabaseManager::deleteRecord(QString table, int id) {
    q->exec("DELETE FROM " + table + " WHERE rowid = " + QString::number(id) + ";");
}
