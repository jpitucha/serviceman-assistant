#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QSettings>
#include "localdatabasemanager.h"
#include "remotedatabasemanager.h"

class DatabaseManager : public QObject
{
    Q_OBJECT
public:
    static DatabaseManager *getInstance();
    int init();
    void saveLocalSettings(QString settings);
    void saveRemoteSettings(QString settings);
    QStringList getAll(QString table);
    void addRecord(QString table, int id, QStringList data);
    void editRecord(QString table, int id, QStringList data);
    void deleteRecord(QString table, int id);

private:
    explicit DatabaseManager(QObject *parent = nullptr);
    static DatabaseManager *instance;
    QSettings *settings;
    LocalDatabaseManager *ldm;
    RemoteDatabaseManager *rdm;
    QStringList remoteSettings;
    QString localSettings;
    QString databaseType;
};

#endif // DATABASEMANAGER_H
