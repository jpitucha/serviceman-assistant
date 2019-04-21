#ifndef DEVICESDIALOG_H
#define DEVICESDIALOG_H

#include <QDialog>
#include <QStringListModel>

namespace Ui {
class DevicesDialog;
}

class DevicesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DevicesDialog(QWidget *parent = nullptr);
    static QStringList data;
    ~DevicesDialog();

private slots:
    void on_addButton_clicked();
    void on_editButton_clicked();
    void on_deleteButton_clicked();

private:
    Ui::DevicesDialog *ui;
    QStringListModel *model;
};

#endif // DEVICESDIALOG_H
