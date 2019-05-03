#ifndef REMOTEDATABASEMANAGER_H
#define REMOTEDATABASEMANAGER_H

#include <QObject>

class RemoteDatabaseManager : public QObject
{
    Q_OBJECT
public:
    explicit RemoteDatabaseManager(QString  host, QString port, QString name, QString user, QString password, QObject *parent = nullptr);
    bool init();
    QStringList getAllClients();
    QStringList getAllDamages();
    QStringList getAllModels();
    QStringList getAllTechnicians();

signals:

public slots:
};

#endif // REMOTEDATABASEMANAGER_H
