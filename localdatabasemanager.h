#ifndef LOCALDATABASEMANAGER_H
#define LOCALDATABASEMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>

class LocalDatabaseManager : public QObject
{
    Q_OBJECT
public:
    explicit LocalDatabaseManager(QString path, QObject *parent = nullptr);
    bool init();
    QStringList getAllClients();
    QStringList getAllDamages();
    QStringList getAllModels();
    QStringList getAllTechnicians();

signals:

public slots:

private:
    QSqlDatabase db;
    QString path;
    QSqlQuery *q;
    QStringList *tmp;
};

#endif // LOCALDATABASEMANAGER_H
