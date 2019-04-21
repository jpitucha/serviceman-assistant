#ifndef CLIENTSDIALOG_H
#define CLIENTSDIALOG_H

#include <QDialog>
#include <QStringListModel>

namespace Ui {
class ClientsDialog;
}

class ClientsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ClientsDialog(QWidget *parent = nullptr);
    static QStringList data;
    ~ClientsDialog();

private:
    Ui::ClientsDialog *ui;
    QStringListModel *model;
};

#endif // CLIENTSDIALOG_H
