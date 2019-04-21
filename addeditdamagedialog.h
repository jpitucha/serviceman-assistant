#ifndef ADDEDITDAMAGEDIALOG_H
#define ADDEDITDAMAGEDIALOG_H

#include <QDialog>

namespace Ui {
class AddEditDamageDialog;
}

class AddEditDamageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddEditDamageDialog(QWidget *parent = nullptr);
    ~AddEditDamageDialog();

private:
    Ui::AddEditDamageDialog *ui;
};

#endif // ADDEDITDAMAGEDIALOG_H
