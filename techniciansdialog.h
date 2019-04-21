#ifndef TECHNICIANSDIALOG_H
#define TECHNICIANSDIALOG_H

#include <QDialog>
#include <QStringListModel>

namespace Ui {
class TechniciansDialog;
}

class TechniciansDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TechniciansDialog(QWidget *parent = nullptr);
    static QStringList data;
    ~TechniciansDialog();

private slots:
    void on_addButton_clicked();
    void on_editButton_clicked();
    void on_deleteButton_clicked();

private:
    Ui::TechniciansDialog *ui;
    QStringListModel *model;
};

#endif // TECHNICIANSDIALOG_H
