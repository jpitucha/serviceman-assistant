#ifndef DEVICESDATABASEDIALOG_H
#define DEVICESDATABASEDIALOG_H

#include <QDialog>

namespace Ui {
class DevicesDatabaseDialog;
}

class DevicesDatabaseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DevicesDatabaseDialog(QWidget *parent = nullptr);
    ~DevicesDatabaseDialog();

private:
    Ui::DevicesDatabaseDialog *ui;
};

#endif // DEVICESDATABASEDIALOG_H
