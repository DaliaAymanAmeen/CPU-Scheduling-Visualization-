#ifndef PREEMPTIVE_H
#define PREEMPTIVE_H

#include <QDialog>

struct SRTF_Process {
    QString id; // Process ID
    float bt; // Burst Time
    float at; // Arrival Time
    float rmt; // remaning time
    float wt; // waiting time
    SRTF_Process(QString i, float b, float a) {
        id = i;
        bt = b;
        at = a;
        rmt = b;
        wt = 0;
    }
};

void SRTF(QVector<QString>&id, QVector<float>&burst, QVector<float>&arival, QVector<float> &start, QVector<SRTF_Process> &v);

void SRTF_Gantt_Chart(QVector<SRTF_Process> &sr, QVector<QString> &ids);

float SRTF_Waiting_time(QVector<SRTF_Process> &sr);
float SRTF_Turn_Around(QVector<SRTF_Process> &sr);

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
