#include "preemptive.h"
#include "ui_preemptive.h"
#include <QString>
#include<QDebug>
#include <QLabel>
#include <QMessageBox>
#include "output.h"
#include <QTextEdit>
preemptive::preemptive(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::preemptive)
{
    ui->setupUi(this);
}

preemptive::~preemptive()
{
    delete ui;
}

int q=0;
QString Process5[10];
int ArrivalTime5[10];
int BurstTime5[10];
int WaitingTime5[10];
int TurnAroundTime5[10];
float AvgWaitingTime5=0;
float AvgTurnAround5=0;
int starting_time5[10];
int gap5[10];


void preemptive::on_PB_next_clicked()
{
    Process5[q]=ui->lineEdit_name5->text();
    ArrivalTime5[q]=ui->lineEdit_arrival5->text().split(" ")[0].toInt();
    BurstTime5[q]=ui->lineEdit_burst5->text().split(" ")[0].toInt();
    q++;
    ui->lineEdit_name5->clear();
    ui->lineEdit_arrival5->clear();
    ui->lineEdit_burst5->clear();
}





















void preemptive::on_PB_finish_clicked()
{
    Process5[q]=ui->lineEdit_name5->text();
    ArrivalTime5[q]=ui->lineEdit_arrival5->text().split(" ")[0].toInt();
    BurstTime5[q]=ui->lineEdit_burst5->text().split(" ")[0].toInt();








    output out;
    out.setModal(true);
    QTextEdit* text_avg =new QTextEdit(&out);
    QTextEdit* text_TurnAround =new QTextEdit(&out);
    text_avg->setText(QString::number(AvgWaitingTime5));
    text_avg->setFixedHeight(30);
    text_TurnAround->setText(QString::number(AvgTurnAround5));
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
 for(int i=0;i<q+1;i++)
 {

    QLabel* label = new QLabel(&out);
    label->setText(Process5[i]);

    if(i==0)
    {
        label->setFixedWidth((int(BurstTime5[i]))*14);
        move=BurstTime5[0];

    }

    else
    {
        label->setFixedWidth((int(BurstTime5[i]))*14);
        label->move((move)*14,0);
        move+=BurstTime5[i];

    }

    label->setStyleSheet("QLabel {text-align: center;background-color :blue; color :white; border-width : 2px ; border-style: solid; border-color:black }");
    //label->setLayout(QLay)
     label->show();

 }



int move1=0;

 for (int i=0 ; i<q+1 ; i++)
 {
    QLabel* lable =new QLabel(&out);
    lable->setText(QString::number(starting_time5[i]));
    lable->move((move1)*14,21);
    move1+=BurstTime5[i];
    lable->show();

 }


out.exec();


}
