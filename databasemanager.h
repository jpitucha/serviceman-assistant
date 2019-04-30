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

private:
    explicit DatabaseManager(QObject *parent = nullptr);
    static DatabaseManager *instance;
    QSettings *settings;
    LocalDatabaseManager *ldm;

signals:

public slots:
};

#endif // DATABASEMANAGER_H
