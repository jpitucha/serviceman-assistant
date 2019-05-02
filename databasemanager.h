#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QSettings>
#include "localdatabasemanager.h"

class DatabaseManager : public QObject
{
    Q_OBJECT
public:
    static DatabaseManager *getInstance();
    int init();
    void saveLocalSettings(QString settings);
    void saveRemoteSettings(QString settings);

private:
    explicit DatabaseManager(QObject *parent = nullptr);
    static DatabaseManager *instance;
    QSettings *settings;
    LocalDatabaseManager *ldm;

};

#endif // DATABASEMANAGER_H
