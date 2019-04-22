#ifndef ENTRIESMANAGER_H
#define ENTRIESMANAGER_H

#include <QDialog>

namespace Ui {
class EntriesManager;
}

class EntriesManager : public QDialog
{
    Q_OBJECT

public:
    explicit EntriesManager(QWidget *parent = nullptr);
    ~EntriesManager();

private:
    Ui::EntriesManager *ui;
};

#endif // ENTRIESMANAGER_H
