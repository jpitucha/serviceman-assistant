#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSettings>
#include <QSqlDatabase>
#include <QSqlQuery>

class DatabaseManager : public QObject
{
    Q_OBJECT
public:
    static DatabaseManager *getInstance();
    int init();
    void saveSettings(QString settings);
    QStringList getAll(QString table, QString column = "");
    void addRecord(QString table, QStringList data);
    void editRecord(QString table, int id, QStringList data);
    void deleteRecord(QString table, int id);
    QString getLastID(QString table);

private:
    explicit DatabaseManager(QObject *parent = nullptr);
    bool connect(QString path);
    static DatabaseManager *instance;
    QSettings *settings;
    QString path;
    QSqlDatabase db;
    QSqlQuery *q;
    QStringList *tmp;
};

#endif // DATABASEMANAGER_H
