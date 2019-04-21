#ifndef TECHNICIANSDIALOG_H
#define TECHNICIANSDIALOG_H

#include <QDialog>

namespace Ui {
class TechniciansDialog;
}

class TechniciansDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TechniciansDialog(QWidget *parent = nullptr);
    ~TechniciansDialog();

private:
    Ui::TechniciansDialog *ui;
};

#endif // TECHNICIANSDIALOG_H
