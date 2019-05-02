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
    if (QFile::exists(QDir::currentPath() + "/settings.ini")) {
        settings = new QSettings("settings.ini", QSettings::IniFormat);
        if (settings->value("databaseType", "null") != "null") {
            if (settings->value("databaseType") == "local") {
                if (settings->value("localPath", "null") != "null") {
                    ldm = new LocalDatabaseManager(settings->value("localPath").toString());
                    if (ldm->init()) {
                        return 0;
                    } else {
                        return 1;
                    }
                } else {
                    return 2;
                }
            } else if (settings->value("databaseType") == "remote") {
                //
                if (settings->value("remoteHost", "null") != "null") {
                    if (settings->value("remotePort", "null") != "null") {
                        if (settings->value("remoteName", "null") != "null") {
                            if (settings->value("remoteUser", "null") != "null") {
                                if (settings->value("remotePassword", "null") != "null") {
                                    rdm = new RemoteDatabaseManager(settings->value("remoteHost").toString(), settings->value("remotePort").toString(), settings->value("remoteName").toString(), settings->value("remoteUser").toString(), settings->value("remotePassword").toString());
                                    if (rdm->init()) {
                                        return  0;
                                    } else {
                                        return 1;
                                    }
                                } else {
                                    return 10;
                                }
                            } else {
                                return 9;
                            }
                        } else {
                            return 8;
                        }
                    } else {
                        return 7;
                    }
                } else {
                    return 6;
                }
                //
            } else {
                return 3;
            }
        } else {
            return 4;
        }
    } else {
        return 5;
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
    this->settings->clear();
    this->settings->setValue("databaseType", "local");
    this->settings->setValue("localPath", settings);
    this->settings->sync(); //flush
}

void DatabaseManager::saveRemoteSettings(QString settings) {
    this->settings->clear();
    this->settings->setValue("databaseType", "remote");
    this->settings->setValue("remoteHost", settings.split(";").at(0));
    this->settings->setValue("remotePort", settings.split(";").at(1));
    this->settings->setValue("remoteName", settings.split(";").at(2));
    this->settings->setValue("remoteUser", settings.split(";").at(3));
    this->settings->setValue("remotePassword", settings.split(";").at(4));
    this->settings->sync();
}
