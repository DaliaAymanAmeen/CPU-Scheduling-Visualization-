#ifndef INPUT_FCFS_H
#define INPUT_FCFS_H

#include <QDialog>

namespace Ui {
class input_fcfs;
}

class input_fcfs : public QDialog
{
    Q_OBJECT

public:
    explicit input_fcfs(QWidget *parent = nullptr);
    ~input_fcfs();

private slots:
    void on_PB_next_clicked();

    void on_PB_finish_clicked();

private:
    Ui::input_fcfs *ui;
};

#endif // INPUT_FCFS_H
