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
    if (!QFile::exists(QDir::currentPath() + "/settings.ini")) return 5;
    settings = new QSettings("settings.ini", QSettings::IniFormat);
    if (settings->value("databaseType", "null") == "null") return 4;
    if (settings->value("databaseType") == "local") {
        if (settings->value("localPath", "null") == "null") return 2;
        localSettings = settings->value("localPath").toString();
        ldm = new LocalDatabaseManager(localSettings);
        databaseType = 'l';
        if (ldm->init()) return 0; else return 1;
    } else if (settings->value("databaseType") == "remote") {
        if (settings->value("remoteHost", "null") == "null") return 6;
        if (settings->value("remotePort", "null") == "null") return 7;
        if (settings->value("remoteName", "null") == "null") return 8;
        if (settings->value("remoteUser", "null") == "null") return 9;
        if (settings->value("remotePassword", "null") == "null") return 10;
        remoteSettings << settings->value("remoteHost").toString();
        remoteSettings << settings->value("remotePort").toString();
        remoteSettings << settings->value("remoteName").toString();
        remoteSettings << settings->value("remoteUser").toString();
        remoteSettings << settings->value("remotePassword").toString();
        rdm = new RemoteDatabaseManager(remoteSettings.at(0),
                                        remoteSettings.at(1),
                                        remoteSettings.at(2),
                                        remoteSettings.at(3),
                                        remoteSettings.at(4));
        databaseType = 'r';
        if (rdm->init()) return 0; else return 1;
    } else {
        return 3;
    }
}

 /* CODES
  * 0 - OK
  * 1 - Local / Remote Data Manager failed
  * 2 - localPath not provided in settings
  * 3 - databaseType neither 'local' nor 'remote'
  * 4 - databaseType not provided in settings
  * 5 - settings file does not exists
  * 6 - remoteHost not provided in settings
  * 7 - remotePort not provided in settings
  * 8 - remoteName not provided in setiings
  * 9 - remoteUser not provided in settings
  * 10 - remotePassword not provided in settings
  */

void DatabaseManager::saveLocalSettings(QString settings) {
    this->settings = new QSettings("settings.ini", QSettings::IniFormat);
    this->settings->clear(); //we don't want to keep old entries
    this->settings->setValue("databaseType", "local");
    this->settings->setValue("localPath", settings);
    this->settings->sync(); //flush
}

void DatabaseManager::saveRemoteSettings(QString settings) {
    this->settings = new QSettings("settings.ini", QSettings::IniFormat);
    this->settings->clear();
    this->settings->setValue("databaseType", "remote");
    this->settings->setValue("remoteHost", settings.split(";").at(0));
    this->settings->setValue("remotePort", settings.split(";").at(1));
    this->settings->setValue("remoteName", settings.split(";").at(2));
    this->settings->setValue("remoteUser", settings.split(";").at(3));
    this->settings->setValue("remotePassword", settings.split(";").at(4));
    this->settings->sync();
}

QStringList DatabaseManager::getAllClients() {
    if (databaseType == 'l') {
        return ldm->getAllClients();
    } else {
        return rdm->getAllClients();
    }
}

QStringList DatabaseManager::getAllDamages() {
    if (databaseType == 'l') {
        return ldm->getAllDamages();
    } else {
        return rdm->getAllDamages();
    }
}

QStringList DatabaseManager::getAllModels() {
    if (databaseType == 'l') {
        return ldm->getAllModels();
    } else {
        return rdm->getAllModels();
    }
}

QStringList DatabaseManager::getAllTechnicians() {
    if (databaseType == 'l') {
        return ldm->getAllTechnicians();
    } else {
        return rdm->getAllTechnicians();
    }
}
