#include "remotedatabasemanager.h"

RemoteDatabaseManager::RemoteDatabaseManager(QString host, QString port, QString name, QString user, QString password, QObject *parent) : QObject(parent)
{

}

bool RemoteDatabaseManager::init() {
    return true;
}
