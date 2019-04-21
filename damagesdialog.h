#ifndef DAMAGESDIALOG_H
#define DAMAGESDIALOG_H

#include <QDialog>
#include <QStringListModel>

namespace Ui {
class DamagesDialog;
}

class DamagesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DamagesDialog(QWidget *parent = nullptr);
    static QStringList data;
    ~DamagesDialog();

private slots:
    void on_addButton_clicked();
    void on_editButton_clicked();
    void on_deleteButton_clicked();

private:
    Ui::DamagesDialog *ui;
    QStringListModel *model;
};

#endif // DAMAGESDIALOG_H
