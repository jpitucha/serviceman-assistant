#ifndef ENTRIESMANAGER_H
#define ENTRIESMANAGER_H

#include <QDialog>
#include <QStringListModel>

namespace Ui {
class EntriesManager;
}

class EntriesManager : public QDialog
{
    Q_OBJECT

public:
    explicit EntriesManager(QString windowTitle, QString table, QString column, QWidget *parent = nullptr);
    QString table;
    QString column;
    QList<QMap<QString, QString>> data;
    bool recordExists(QString record);
    ~EntriesManager();

private slots:
    void on_addButton_clicked();
    void on_editButton_clicked();
    void on_deleteButton_clicked();

private:
    Ui::EntriesManager *ui;
    QStringListModel *model;
};

#endif // ENTRIESMANAGER_H
