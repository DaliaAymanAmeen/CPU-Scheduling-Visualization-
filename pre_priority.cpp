#include "ui_pre_priority.h"
#include "pre_priority.h"
#include <QString>
#include<QDebug>
#include <QLabel>
#include <QMessageBox>
#include "output.h"
#include <QTextEdit>
#include<iostream>
#include <QIntValidator>
#include <QDoubleValidator>
#include <algorithm>
#include <QtAlgorithms>

pre_priority::pre_priority(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pre_priority)
{
    ui->setupUi(this);
    QPixmap bkgnd(":/new/prefix1/img/watercolour-texture-background-vector.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

pre_priority::~pre_priority()
{
    delete ui;
}



int w=0;

QVector<float>burstp;

QVector<float>arivalp;  //gap
QVector<float> startp;

QVector<int> priority7;

QVector<QString> idsp;

float AvgWaitingTime7=0;
float AvgTurnAround7=0;
int size_pp;


void pre_priority::on_PB_next_clicked()
{
    int pos=0;
        QString arrival_2 =ui->lineEdit_arrival->text();
        QString Burst_2=ui->lineEdit_burst->text();
        QString priority_2=ui->priority_2->text();
        QDoubleValidator vd(0,1000,3,this);



        if(vd.validate(arrival_2 , pos)==QValidator::Invalid ||vd.validate(Burst_2 , pos)==QValidator::Invalid || vd.validate(priority_2 , pos)==QValidator::Invalid)
        {
            QMessageBox::warning(this, "Wrong input", "Please enter a number");

        }
    else{
    QString idstr_2=ui->lineEdit_Process->text();
    idsp.push_back(idstr_2);
  float arrivalstr_2 =ui->lineEdit_arrival->text().split(" ")[0].toFloat();
     arivalp.push_back(arrivalstr_2);
   float burststr_2 =ui->lineEdit_burst->text().split(" ")[0].toFloat();
     burstp.push_back(burststr_2);
   float priorityy_2 =ui->priority_2->text().split(" ")[0].toInt();
      priority7.push_back(priorityy_2);

    w++;
    ui->lineEdit_Process->clear();
    ui->lineEdit_arrival->clear();
    ui->lineEdit_burst->clear();
    ui->priority_2->clear();
    }


}


bool cmp(priority_Preemptive A, priority_Preemptive B) {
    if (A.pr != B.pr)
        return A.pr < B.pr;
    else
        return A.at < B.at;
}



void priority_pree_Gantt_Chart(QVector<priority_Preemptive> &sr, QVector<QString>&ids)
{


    float time = 0, flag = 0, num = sr.size();
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


float priority_pree_Waiting_time(QVector<priority_Preemptive> &sr) {

    float total = 0;
    for (int i = 0; i < sr.size(); i++) {

        total += sr[i].wt;


    }

    //cout<<"avg waiting time" << (1.0*total / sr.size())<<endl;
    return (1.0*total / sr.size());


}


float priority_pree_Turn_Around(QVector<priority_Preemptive> &sr) {

    float total = 0;
    for (int i = 0; i < sr.size(); i++) {

        total += sr[i].wt + sr[i].bt;


    }

    return (1.0*total / sr.size());
}




void priority_pree(QVector<QString>&id, QVector<float>&burst, QVector<float>&arrival, QVector<float>&start, QVector<int> &priority, QVector<priority_Preemptive> &v) {
    QVector<QString>time_line;
    //to put the input in SRFT vector

    for (int i = 0; i < id.size(); i++) {
        v.push_back(priority_Preemptive(id[i], burst[i], arrival[i], priority[i]));
    }
    id.clear();
    burst.clear();
    arrival.clear();
    priority.clear();

    qSort(v.begin(), v.end(), cmp);
    priority_pree_Gantt_Chart(v, time_line);
    QString lastid = time_line[0];
    float gap = 0, time = 0;

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
                arrival.push_back(gap);
                lastid = time_line[i];
                time = 1;
                gap = 0;
            }
            else if (lastid != "-1" && time_line[i] == "-1") {
                id.push_back(lastid);
                burst.push_back(time);
                arrival.push_back(gap);
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
        sta += arrival[i];
        start.push_back(sta);
        sta += burst[i];
    }




}

QVector<priority_Preemptive> srp;


void pre_priority::on_PB_finish_clicked()
{

    int pos=0;
        QString arrival =ui->lineEdit_arrival->text();
        QString Burst=ui->lineEdit_burst->text();
        QString priority=ui->priority_2->text();


        QDoubleValidator vd(0,1000,3,this);





        if(vd.validate(arrival , pos)==QValidator::Invalid ||vd.validate(Burst , pos)==QValidator::Invalid  )
        {
            QMessageBox::warning(this, "Wrong input", "Please enter a number");

        }
    else{
            QString idstr=ui->lineEdit_Process->text();
            idsp.push_back(idstr);
          float arrivalstr =ui->lineEdit_arrival->text().split(" ")[0].toFloat();
             arivalp.push_back(arrivalstr);
           float burststr =ui->lineEdit_burst->text().split(" ")[0].toFloat();
             burstp.push_back(burststr);
            float priorityy =ui->priority_2->text().split(" ")[0].toFloat();
                 priority7.push_back(priorityy);

     priority_pree(idsp, burstp, arivalp, startp, priority7 ,srp);



     AvgWaitingTime7 = priority_pree_Waiting_time(srp);
     AvgTurnAround7 =  priority_pree_Turn_Around(srp);



    output out;
    out.setModal(true);
    QTextEdit* text_avg =new QTextEdit(&out);
    QTextEdit* text_TurnAround =new QTextEdit(&out);
    text_avg->setText(QString::number(AvgWaitingTime7));
    text_avg->setFixedHeight(30);
    text_TurnAround->setText(QString::number(AvgTurnAround7));
    text_TurnAround->setFixedHeight(30);

    text_avg->move(200,120);
    text_TurnAround->move(200,150);
    text_avg->show();
    text_TurnAround->show();

    QLabel* label_avg =new QLabel(&out);
    label_avg->setText("Average Waiting time:");
    label_avg->move(50,130);
    QLabel* label_turn= new QLabel(&out);
    label_turn->setText("Average TurnAround Time:");
    label_turn->move(50,160);
    label_avg->show();
    label_turn->show();


    int move=0;

 for(int i=0;i<idsp.size();i++)
 {

    QLabel* label = new QLabel(&out);
    label->setText(idsp[i]);

    if(i==0)
    {
        if (idsp.size()==1)
        {
            label->move(5,300);
            label->setFixedWidth((burstp[0])*14);
              label->setFixedHeight(25);
              label->setStyleSheet("QLabel {text-align: center;background-color :rgb(148, 200, 190); color :white; border-width : 2px ; border-style: solid; border-color:white }");
              //label->setLayout(QLay)
               label->show();continue;
            } // w hna 3lshan law process wahda

        label->move(5,300);
        label->setFixedWidth((burstp[0])*14);
          label->setFixedHeight(25);
        move=burstp[0]+arivalp[1];

    }

    else
    {
        label->setFixedWidth((burstp[i])*14);
          label->setFixedHeight(25);
        label->move((move)*14,300);
        if (i!=idsp.size()-1) move+=burstp[i]+arivalp[i+1];

    }
    idsp[i]="";

    label->setStyleSheet("QLabel {text-align: center;background-color :rgb(148, 200, 190); color :white; border-width : 2px ; border-style: solid; border-color:white }");
    //label->setLayout(QLay)
     label->show();

 }


int move1=0;  //starting time

 for (int i=0 ; i<startp.size() ; i++)
 {
    QLabel* lable =new QLabel(&out);
    lable->setText(QString::number(startp[i]));
    lable->move((move1)*14,325);
    if (i!=startp.size()-1) move1+=burstp[i]+arivalp[i+1];
    else move1+=burstp[i];
    lable->show();


    if (i==startp.size()-1)  //finish last process
        {  QLabel* lable =new QLabel(&out);
            lable->move((move1)*14,325);
            lable->setText(QString::number(startp[i]+burstp[i]));
           // move1+=burst[i]+arival[i+1];
            lable->show();
        }

 }






 int move2=burstp[0]; //finish time

    for (int i=0 ; i<arivalp.size()-1 ; i++)
    {
       if (arivalp.size()==1) continue; //hna 3lshan law process wahda

       if (arivalp[i+1]==0){move2+=burstp[i+1]; continue;}
       QLabel* lable =new QLabel(&out);
       lable->move((move2)*14,325);
       lable->setText(QString::number(startp[i]+burstp[i]));
       if (i != arrival.size()-1) move2+=burstp[i+1]+arivalp[i+1];
       lable->show();

    }

out.exec();


move=0;
move1=0;
move2=0;

        w=0;
        burstp.clear();
        arivalp.clear();
        startp.clear();
        idsp.clear();
        srp.clear();
        ui->lineEdit_Process->clear();
        ui->lineEdit_arrival->clear();
        ui->lineEdit_burst->clear();
        ui->priority_2->clear();

        }


}
