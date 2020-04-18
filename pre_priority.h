#ifndef PRIORITY_PREEMPTIVE_H
#define PRIORITY_PREEMPTIVE_H

#include <QDialog>


struct priority_Preemptive {
    QString id; // Process ID
    int bt; // Burst Time
   int at; // Arrival Time
    int rmt; // remaning time
    int wt; // waiting time
    int pr; //priority


    priority_Preemptive(QString i, float b, float a, int c) {
        id = i;
        bt = b;
        at = a;
        rmt = b;
        wt = 0;
        pr = c;



    }
};

void priority_pree(QVector<QString>&id, QVector<float>&burst, QVector<float>&arrival, QVector<float> &start, QVector<int>&priority, QVector<priority_Preemptive> &v);

void priority_pree_Gantt_Chart(QVector<priority_Preemptive> &sr, QVector<QString>&ids);

float priority_pree_Waiting_time(QVector<priority_Preemptive> &sr);
float priority_pree_Turn_Around(QVector<priority_Preemptive> &sr);



namespace Ui {
class pre_priority;
}

class pre_priority : public QDialog
{
    Q_OBJECT

public:
    explicit pre_priority(QWidget *parent = nullptr);
    ~pre_priority();

private slots:
    void on_PB_next_clicked();

    void on_PB_finish_clicked();

private:
    Ui::pre_priority *ui;
};

#endif // PRIORITY_PREEMPTIVE_H
