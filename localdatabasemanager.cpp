#include "localdatabasemanager.h"

LocalDatabaseManager::LocalDatabaseManager(QString path, QObject *parent) : QObject(parent)
{

}

bool LocalDatabaseManager::init() {
    return true;
}
