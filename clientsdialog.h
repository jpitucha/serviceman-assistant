#ifndef CLIENTSDIALOG_H
#define CLIENTSDIALOG_H

#include <QDialog>

namespace Ui {
class ClientsDialog;
}

class ClientsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ClientsDialog(QWidget *parent = nullptr);
    ~ClientsDialog();

private:
    Ui::ClientsDialog *ui;
};

#endif // CLIENTSDIALOG_H
