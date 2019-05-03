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
    QStringList getAllClients();
    QStringList getAllDamages();
    QStringList getAllModels();
    QStringList getAllTechnicians();
    QString *databaseTyp = new QString("");

private:
    explicit DatabaseManager(QObject *parent = nullptr);
    static DatabaseManager *instance;
    QSettings *settings;
    LocalDatabaseManager *ldm;
    RemoteDatabaseManager *rdm;
    QStringList remoteSettings;
    QString localSettings;

};

#endif // DATABASEMANAGER_H
