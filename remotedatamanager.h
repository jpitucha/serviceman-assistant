#ifndef REMOTEDATAMANAGER_H
#define REMOTEDATAMANAGER_H

#include <QObject>

class RemoteDataManager : public QObject
{
    Q_OBJECT
public:
    explicit RemoteDataManager(QString  host, QString port, QString name, QString user, QString password, QObject *parent = nullptr);
    bool init();

signals:

public slots:
};

#endif // REMOTEDATAMANAGER_H
