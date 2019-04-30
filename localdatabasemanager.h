#ifndef LOCALDATABASEMANAGER_H
#define LOCALDATABASEMANAGER_H

#include <QObject>

class LocalDatabaseManager : public QObject
{
    Q_OBJECT
public:
    explicit LocalDatabaseManager(QString path, QObject *parent = nullptr);
    bool init();

signals:

public slots:
};

#endif // LOCALDATABASEMANAGER_H
