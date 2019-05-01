#include "databasemanager.h"
#include "localdatabasemanager.h"
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
                return 1; // handle remote DB part
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
  */
