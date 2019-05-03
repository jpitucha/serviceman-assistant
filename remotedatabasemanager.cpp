#include "remotedatabasemanager.h"

RemoteDatabaseManager::RemoteDatabaseManager(QString host, QString port, QString name, QString user, QString password, QObject *parent) : QObject(parent)
{

}

bool RemoteDatabaseManager::init() {
    return true;
}

QStringList RemoteDatabaseManager::getAllClients() {
    return QStringList();
}

QStringList RemoteDatabaseManager::getAllDamages() {
    return QStringList();
}

QStringList RemoteDatabaseManager::getAllModels() {
    return QStringList();
}

QStringList RemoteDatabaseManager::getAllTechnicians() {
    return QStringList();
}
