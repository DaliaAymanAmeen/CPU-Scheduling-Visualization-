#ifndef PREEMPTIVE_H
#define PREEMPTIVE_H

#include <QDialog>

namespace Ui {
class preemptive;
}

class preemptive : public QDialog
{
    Q_OBJECT

public:
    explicit preemptive(QWidget *parent = nullptr);
    ~preemptive();

private slots:
    void on_PB_next_clicked();

    void on_PB_finish_clicked();

private:
    Ui::preemptive *ui;
};

#endif // PREEMPTIVE_H
