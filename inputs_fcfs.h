#ifndef INPUTS_FCFS_H
#define INPUTS_FCFS_H

#include <QMainWindow>

namespace Ui {
class INPUTS_FCFS;
}

class INPUTS_FCFS : public QMainWindow
{
    Q_OBJECT

public:
    explicit INPUTS_FCFS(QWidget *parent = nullptr);
    ~INPUTS_FCFS();

private:
    Ui::INPUTS_FCFS *ui;
};

#endif // INPUTS_FCFS_H
