#ifndef FCFS_INPUT_H
#define FCFS_INPUT_H

#include <QMainWindow>

namespace Ui {
class fcfs_input;
}

class fcfs_input : public QMainWindow
{
    Q_OBJECT

public:
    explicit fcfs_input(QWidget *parent = nullptr);
    ~fcfs_input();

private:
    Ui::fcfs_input *ui;
};

#endif // FCFS_INPUT_H
