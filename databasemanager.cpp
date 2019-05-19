#include "databasemanager.h"
#include <QDir>
#include <QFile>

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

QStringList DatabaseManager::getAll(QString table) {
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

void DatabaseManager::addRecord(QString table, QStringList data) {
    //args2 -> values
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

void DatabaseManager::editRecord(QString table, int id, QStringList data) {
    QString *args = new QString();
    for (int i = 0; i < data.size(); i++) {
        if (i < data.size() - 1) args->append(data.at(i).split('=').at(0) + "='" + data.at(i).split('=').at(1) + "', "); else args->append(data.at(i).split('=').at(0) + "='" + data.at(i).split('=').at(1) + "'");
    }
    q->exec("UPDATE " + table + " SET " + *args + " WHERE rowid = " + QString::number(id) + ";");
    delete args;
}

void DatabaseManager::deleteRecord(QString table, int id) {
    q->exec("DELETE FROM " + table + " WHERE rowid = " + QString::number(id) + ";");
}
