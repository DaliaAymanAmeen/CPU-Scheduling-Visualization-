#include "preemptive.h"
#include "ui_preemptive.h"
#include <QString>
#include<QDebug>
#include <QLabel>
#include <QMessageBox>
#include "output.h"
#include <QTextEdit>
#include<iostream>
#include <algorithm>
#include <QtAlgorithms>

#include <QDoubleValidator>
preemptive::preemptive(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::preemptive)
{
    ui->setupUi(this);
    QPixmap bkgnd(":/new/prefix1/img/watercolour-texture-background-vector.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

}

preemptive::~preemptive()
{
    delete ui;
}

int q=0;

QVector<float>burst;


QVector<float>arival;  //gap
QVector<float> start;



QVector<QString> ids;

float AvgWaitingTime5=0;
float AvgTurnAround5=0;
int size_p;



void preemptive::on_PB_next_clicked()
{
    int pos=0;
        QString arrival =ui->lineEdit_arrival5->text();
        QString Burst=ui->lineEdit_burst5->text();
        QDoubleValidator vd(0,1000,3,this);





        if(vd.validate(arrival , pos)==QValidator::Invalid ||vd.validate(Burst , pos)==QValidator::Invalid  )
        {
            QMessageBox::warning(this, "Wrong input", "Please enter a number");

        }
    else{
    QString idstr=ui->lineEdit_name5->text();
    ids.push_back(idstr);
  float arrivalstr =ui->lineEdit_arrival5->text().split(" ")[0].toFloat();
     arival.push_back(arrivalstr);
   float burststr =ui->lineEdit_burst5->text().split(" ")[0].toFloat();
     burst.push_back(burststr);
    q++;
    ui->lineEdit_name5->clear();
    ui->lineEdit_arrival5->clear();
    ui->lineEdit_burst5->clear();
    }
}

bool cmp(SRTF_Process A, SRTF_Process B) {
    if (A.bt != B.bt)
        return A.bt < B.bt;
    else
        return A.at < B.at;
}


void SRTF_Gantt_Chart(QVector<SRTF_Process> &sr, QVector<QString> &ids)
{
    float time = 0;
    int flag = 0, num = sr.size();
    while (flag != 1)
    {
        flag = 1;

        for (int i = 0; i < sr.size(); i++) {

            if (sr[i].rmt > 0 && sr[i].at <= time) {

                //cout << "At " << time << " : process NO. :" << sr[i].id << endl;
                ids.push_back(sr[i].id);
                sr[i].rmt--;
                flag = 0;
                if (sr[i].rmt == 0) {
                    num--;
                }
                for (int j = 0; j < sr.size(); j++) {
                    if (j != i && sr[j].at <= time && sr[j].rmt > 0) {
                        sr[j].wt++;
                    }
                }
                break;
            }
        }
        if (num != 0 && flag == 1) {
            flag = 0;
            ids.push_back("-1");
            for (int j = 0; j < sr.size(); j++) {
                if (sr[j].at <= time && sr[j].rmt > 0) {
                    sr[j].wt++;
                }
            }
        }
        time++;
    }
    //cout << "the processes take " << time-1 << endl;
}



float SRTF_Waiting_time(QVector<SRTF_Process> &sr) {

    int total = 0;
    for (int i = 0; i < sr.size(); i++)
    {
        total += sr[i].wt;
    }
    //cout<<"avg waiting time" << (1.0*total / sr.size())<<endl;
    return (1.0*total / sr.size());
}




float SRTF_Turn_Around(QVector<SRTF_Process> &sr) {

    int total = 0;
    for (int i = 0; i < sr.size(); i++) {

        total += sr[i].wt + sr[i].bt;
    }
    return (1.0*total / sr.size());
}



void SRTF(QVector<QString>&id, QVector<float>&burst, QVector<float>&arival, QVector<float> &start, QVector<SRTF_Process> &v) {
    QVector<QString>time_line;
    //to put the input in SRFT QVector

    for (int i = 0; i <= q; i++) {

        v.push_back(SRTF_Process(id[i], burst[i], arival[i]));
    }
    id.clear();
    burst.clear();
    arival.clear();
    start.clear();
    qSort(v.begin(), v.end(),cmp);
    SRTF_Gantt_Chart(v, time_line);
    int  gap = 0, time = 0;
    QString lastid = time_line[0];

    time_line.push_back("-1");
    for (int i = 0; i < time_line.size(); i++) {

        if (time_line[i] == lastid) {
            if (time_line[i] != "-1") {
                time++;
            }
            else if (time_line[i] == "-1") {
                gap++;
            }
        }
        else if (time_line[i] != lastid) {
            if (lastid != "-1" && time_line[i] != "-1") {
                id.push_back(lastid);
                burst.push_back(time);
                arival.push_back(gap);
                lastid = time_line[i];
                time = 1;
                gap = 0;
            }
            else if (lastid != "-1" && time_line[i] == "-1") {
                id.push_back(lastid);
                burst.push_back(time);
                arival.push_back(gap);
                lastid = time_line[i];
                time = 0;
                gap = 1;
            }
            else if (lastid == "-1") {
                lastid = time_line[i];
                time = 1;
            }
        }
    }
    float sta = 0;
    for (int i = 0; i < burst.size(); i++) {
        sta += arival[i];
        start.push_back(sta);
        sta += burst[i];
    }
}



QVector<SRTF_Process> sr;


void preemptive::on_PB_finish_clicked()
{
    int pos=0;
        QString arrival =ui->lineEdit_arrival5->text();
        QString Burst=ui->lineEdit_burst5->text();
        QDoubleValidator vd(0,1000,3,this);





        if(vd.validate(arrival , pos)==QValidator::Invalid ||vd.validate(Burst , pos)==QValidator::Invalid  )
        {
            QMessageBox::warning(this, "Wrong input", "Please enter a number");

        }
    else{
            QString idstr=ui->lineEdit_name5->text();
            ids.push_back(idstr);
          float arrivalstr =ui->lineEdit_arrival5->text().split(" ")[0].toFloat();
             arival.push_back(arrivalstr);
           float burststr =ui->lineEdit_burst5->text().split(" ")[0].toFloat();
             burst.push_back(burststr);

     SRTF(ids, burst, arival, start,sr);

    // SRTF_Gantt_Chart (sr, ids);

     AvgWaitingTime5 = SRTF_Waiting_time(sr);
     AvgTurnAround5 =  SRTF_Turn_Around(sr);



    output out;
    out.setModal(true);
    QTextEdit* text_avg =new QTextEdit(&out);
    QTextEdit* text_TurnAround =new QTextEdit(&out);
    text_avg->setText(QString::number(AvgWaitingTime5));
    text_avg->setFixedHeight(30);
    text_TurnAround->setText(QString::number(AvgTurnAround5));
    text_TurnAround->setFixedHeight(30);

    text_avg->move(200,150);
    text_TurnAround->move(200,190);
    text_avg->show();
    text_TurnAround->show();

    QLabel* label_avg =new QLabel(&out);
    label_avg->setText("Average Waiting time:");
    label_avg->move(50,160);
    QLabel* label_turn= new QLabel(&out);
    label_turn->setText("Average TurnAround Time:");
    label_turn->move(50,200);
    label_avg->show();
    label_turn->show();


    int move=0;

 for(int i=0;i<ids.size();i++)
 {

    QLabel* label = new QLabel(&out);
    label->setText(ids[i]);

    if(i==0)
    {
        label->move(5,300);
        label->setFixedWidth((burst[0])*14);
          label->setFixedHeight(25);
        move=burst[0]+arival[1];

    }

    else
    {
        label->setFixedWidth((burst[i])*14);
          label->setFixedHeight(25);
        label->move((move)*14,300);
        if (i!=ids.size()-1) move+=burst[i]+arival[i+1];

    }
    ids[i]="";

    label->setStyleSheet("QLabel {text-align: center;background-color :rgb(148, 200, 190);color :white; border-width : 2px ; border-style: solid; border-color:white }");
    //label->setLayout(QLay)
     label->show();

 }




int move1=0;  //starting time

 for (int i=0 ; i<start.size() ; i++)
 {
    QLabel* lable =new QLabel(&out);
    lable->setText(QString::number(start[i]));
    lable->move((move1)*14,325);
    if (i!=start.size()-1) move1+=burst[i]+arival[i+1];
    else move1+=burst[i];
    lable->show();


    if (i==start.size()-1)  //finish last process
        {  QLabel* lable =new QLabel(&out);
            lable->move((move1)*14,325);
            lable->setText(QString::number(start[i]+burst[i]));
           // move1+=burst[i]+arival[i+1];
            lable->show();
        }

 }


 int move2=burst[0]; //finish time

    for (int i=0 ; i<arival.size()-1 ; i++)
    {
       if (arival[i+1]==0){move2+=burst[i]; continue;}
       QLabel* lable =new QLabel(&out);
       lable->move((move2)*14,325);
       lable->setText(QString::number(start[i]+burst[i]));
       if (i != arrival.size()-1) move2+=burst[i+1]+arival[i+1];
       lable->show();


    }



out.exec();


move=0;
move1=0;
move2=0;
        q=0;
        burst.clear();
        arival.clear();
        start.clear();
        ids.clear();
        sr.clear();
        ui->lineEdit_name5->clear();
        ui->lineEdit_arrival5->clear();
        ui->lineEdit_burst5->clear();}

}
