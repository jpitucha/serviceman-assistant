#include "databasemanager.h"
#include <QDir>
#include <QFile>
#include <QDebug>

DatabaseManager * DatabaseManager::instance = nullptr;

DatabaseManager * DatabaseManager::getInstance() {
    if (instance == nullptr) {
        instance = new DatabaseManager();
    }
    return instance;
}

DatabaseManager::DatabaseManager(QObject * parent): QObject(parent) {

}

int DatabaseManager::init() {
    if (!QFile::exists(QDir::currentPath() + "/settings.ini")) return 3;
    settings = new QSettings("settings.ini", QSettings::IniFormat);
    if (settings->value("databasePath", "null") == "null") return 2;
    path = settings->value("databasePath").toString();
    if (connect(path)) return 0; else return 1;
}

/* CODES
  * 0 - OK
  * 1 - Open database failed
  * 2 - Path not provided in settings
  * 3 - Settings file does not exists
  */

void DatabaseManager::saveSettings(QString settings) {
    this->settings = new QSettings("settings.ini", QSettings::IniFormat);
    this->settings->clear(); //we don't want to keep old entries
    this->settings->setValue("databasePath", settings);
    this->settings->sync(); //flush
}

bool DatabaseManager::connect(QString path) {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);
    if (db.open()) q = new QSqlQuery(db);
    return db.isOpen();
}

QStringList DatabaseManager::getAll(QString table, QString column) {
    if (column.isEmpty()) q->exec("SELECT rowid FROM " + table + ";"); else q->exec("SELECT rowid, " + column + " FROM " + table + ";");
    int i = 0;
    QString *record = new QString();
    tmp = new QStringList();
    while (q->next()) {
        i = 0;
        record = new QString();
        while (true) {
            if (q->value(i).isValid()) {
                record->append(q->value(i).toString() + ";");
                i++;
            } else {
                break;
            }
        }
        *record = record->left(record->length() - 1);
        tmp->append(*record);
    }
    delete record;
    return *tmp;
}

void DatabaseManager::addRecord(QString table, QStringList data) {
    QString *args = new QString();
    for (int i = 0; i < data.size(); i++) {
        if (i < data.size() - 1) args->append(data.at(i).split('=').at(0) + ", "); else args->append(data.at(i).split('=').at(0));
    }
    QString *values = new QString();
    for (int i = 0; i < data.size(); i++) {
        if (i < data.size() - 1) values->append("'" + data.at(i).split('=').at(1) + "', "); else values->append("'" + data.at(i).split('=').at(1) + "'");
    }
    q->exec("INSERT INTO " + table + " (" + *args + ") VALUES (" + *values + ");");
    delete args;
    delete values;
}

void DatabaseManager::editRecord(QString table, int id, QStringList data) {
    QString *args = new QString();
    for (int i = 0; i < data.size(); i++) {
        if (i < data.size() - 1) args->append(data.at(i).split('=').at(0) + " = '" + data.at(i).split('=').at(1) + "', "); else args->append(data.at(i).split('=').at(0) + " = '" + data.at(i).split('=').at(1) + "'");
    }
    qDebug() << "UPDATE " + table + " SET " + *args + " WHERE rowid = " + QString::number(id) + ";";
    q->exec("UPDATE " + table + " SET " + *args + " WHERE rowid = " + QString::number(id) + ";");
    delete args;
}

void DatabaseManager::deleteRecord(QString table, int id) {
    q->exec("DELETE FROM " + table + " WHERE rowid = " + QString::number(id) + ";");
}

QString DatabaseManager::getLastID(QString table) {
    q->exec("SELECT rowid FROM " + table + " ORDER BY rowid DESC LIMIT 1;");
    q->next();
    qDebug() << q->value(0).toString();
    return q->value(0).toString();
}
