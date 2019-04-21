#ifndef DAMAGESDIALOG_H
#define DAMAGESDIALOG_H

#include <QDialog>

namespace Ui {
class DamagesDialog;
}

class DamagesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DamagesDialog(QWidget *parent = nullptr);
    ~DamagesDialog();

private:
    Ui::DamagesDialog *ui;
};

#endif // DAMAGESDIALOG_H
