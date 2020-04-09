#include "input_fcfs.h"
#include "ui_input_fcfs.h"
#include <QString>
#include<QLabel>
#include<QDebug>
#include <QMessageBox>
#include "output.h"
#include "ui_output.h"
#include <QTextEdit>
input_fcfs::input_fcfs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::input_fcfs)
{
    ui->setupUi(this);


   // priority_non.exec();
}

input_fcfs::~input_fcfs()
{
    delete ui;
}



int k=0;
QString Process[1000];
int ArrivalTime[1000];
int BurstTime[1000];
int WaitingTime[1000];
int TurnAroundTime[1000];
float AvgWaitingTime=0;
float AvgTurnAround=0;
int starting_time[1000];
int gap[1000];

void input_fcfs::on_PB_next_clicked()
{
    Process[k]=ui->lineEdit_name->text();
    ArrivalTime[k]=ui->lineEdit_arrival->text().split(" ")[0].toInt();
    BurstTime[k]=ui->lineEdit_burst->text().split(" ")[0].toInt();
    k++;
    ui->lineEdit_name->clear();
    ui->lineEdit_arrival->clear();
    ui->lineEdit_burst->clear();

}



void Sort_arriaval_time(QString Process[], int ArrivalTime[], int BurstTime[], int size) {
    int temp_at;
    int temp_bt;
    QString temp_Process;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
        {
            if (ArrivalTime[i] < ArrivalTime[j]) {
                // swaping arrival time
                temp_at = ArrivalTime[i];
                ArrivalTime[i] = ArrivalTime[j];
                ArrivalTime[j] = temp_at;
                //swaping bt
                temp_bt = BurstTime[i];
                BurstTime[i] = BurstTime[j];
                BurstTime[j] = temp_bt;
                //swaping process
                temp_Process = Process[i];
                Process[i] = Process[j];
                Process[j] = temp_Process;
            }
        }
    }
}



void find_waiting_time(QString Process[], int ArrivalTime[], int BurstTime[], int size, int WaitingTime[]) {
    Sort_arriaval_time(Process, ArrivalTime, BurstTime, size);

    //int *service_time = new int[size];        //ghayart di l array 3adi
    int service_time [10];
    service_time[0] = 0;

    //WaitingTime.resize(size); // change  // shelt di khales

    WaitingTime[0] = 0 ;
    for (int i = 1; i < size; i++) {  // Change
        //Add all burst time
        service_time[i] = service_time[i - 1] + BurstTime[i - 1];  //func to convert string to int
        // find wait time
        WaitingTime[i] = service_time[i] - ArrivalTime[i];   //func to convert string to int
        if (WaitingTime[i] < 0)
            WaitingTime[i] = 0;
    }

}



void find_total_arround_time(QString Process[], int ArrivalTime[], int BurstTime[], int size, int WaitingTime[], int TurnAroundTime[]) {
    find_waiting_time(Process, ArrivalTime, BurstTime, size, WaitingTime);

    //TurnAroundTime.resize(size);   //Change

    for (int i = 0; i < size; i++) {
        TurnAroundTime[i] = WaitingTime[i] + BurstTime[i];
    }
}


void find_total_average_time(QString Process[], int ArrivalTime[], int BurstTime[], int size, int WaitingTime[], int TurnAroundTime[],
   float &AvgWaitingTime, float &AvgTurnAround)  {

    int sumOfTurnAround = 0;
    find_total_arround_time(Process, ArrivalTime, BurstTime, size, WaitingTime, TurnAroundTime);
    int sumOfWaitingTime = 0;
    find_waiting_time(Process, ArrivalTime, BurstTime, size, WaitingTime);
    for (int i = 0; i < size; i++)
    {
        sumOfTurnAround += TurnAroundTime[i];
        sumOfWaitingTime += WaitingTime[i];
    }
    AvgWaitingTime = (float)sumOfWaitingTime / (float)size;
    AvgTurnAround = (float)sumOfTurnAround / (float)size;
}


void Gant_chart(QString Process[], int ArrivalTime[], int BurstTime[], int size,int starting_time[], int gap[]) {
    //gap.resize(size);
    //starting_time.resize(size);
    for (int i = 0; i < size; i++) {
        if (i == 0) {
            starting_time[0] = ArrivalTime[0];
            if (ArrivalTime[0] > 0) {
                gap[0] = ArrivalTime[0];
            }
            gap[0] = 0;
        }
        else if (i == size) {
            starting_time[i] = ArrivalTime[i - 1] + BurstTime[i - 1];
        }
        else if (starting_time[i - 1] + BurstTime[i - 1] < ArrivalTime[i]) {
            starting_time[i] = ArrivalTime[i];
            gap[i] = ArrivalTime[i] - (starting_time[i - 1] + BurstTime[i - 1]);
        }
        else {
            starting_time[i] = starting_time[i - 1] + BurstTime[i - 1];
            gap[i] = 0;
        }

    }
}



void input_fcfs::on_PB_finish_clicked()
{
    Process[k]=ui->lineEdit_name->text();
    ArrivalTime[k]=ui->lineEdit_arrival->text().split(" ")[0].toInt();
    BurstTime[k]=ui->lineEdit_burst->text().split(" ")[0].toInt();


    find_total_average_time(Process, ArrivalTime,  BurstTime, k+1 ,  WaitingTime,  TurnAroundTime,
        AvgWaitingTime,  AvgTurnAround);

    //QMessageBox::about(this, "test",  QString::number(AvgWaitingTime));
    //QMessageBox::about(this, "test", QString::number(AvgTurnAround));


    Gant_chart(Process, ArrivalTime,  BurstTime, k+1 ,starting_time, gap);


    //QMessageBox::about(this, "test", QString::number(starting_time[0]));

    //to check the output
    //QMessageBox::about(this, "test", Process[0]);
    //QMessageBox::about(this, "test", Process[1]);
    //QMessageBox::about(this, "test", Process[2]);
    //QMessageBox::about(this, "test", Process[3]);

   // ui->waitingTimeView->setText(QString::number(AvgWaitingTime));
    //ui->turnAroundTimeView->setText(QString::number(AvgTurnAround));

    output out;
    out.setModal(true);
    QTextEdit* text_avg =new QTextEdit(&out);
    QTextEdit* text_TurnAround =new QTextEdit(&out);
    text_avg->setText(QString::number(AvgWaitingTime));
    text_avg->setFixedHeight(30);
    text_TurnAround->setText(QString::number(AvgTurnAround));
    text_TurnAround->setFixedHeight(30);

    text_avg->move(200,120);
    text_TurnAround->move(200,150);
    text_avg->show();
    text_TurnAround->show();

    QLabel* label_avg =new QLabel(&out);
    label_avg->setText("Average Waiting time is:");
    label_avg->move(50,130);
    QLabel* label_turn= new QLabel(&out);
    label_turn->setText("Average TurnAround Time is :");
    label_turn->move(50,160);
    label_avg->show();
    label_turn->show();


    int move=0;
 for(int i=0;i<k+1;i++)
 {

    QLabel* label = new QLabel(&out);
    label->setText(Process[i]);

    if(i==0)
    {
        label->setFixedWidth((int(BurstTime[i]))*7);
        move=BurstTime[0]+gap[1];

    }

    else
    {
        label->setFixedWidth((int(BurstTime[i]))*7);
        label->move((move)*7,0);
        move+=BurstTime[i]+gap[i+1];

    }

    label->setStyleSheet("QLabel {text-align: center;background-color :pink; color :white; border-width : 2px ; border-style: solid; border-color:white }");
    //label->setLayout(QLay)
     label->show();

 }



int move1=0;

 for (int i=0 ; i<k+1 ; i++)
 {

    QLabel* lable =new QLabel(&out);
    lable->setText(QString::number(starting_time[i]));
    lable->move((move1)*7,21);
    move1+=BurstTime[i]+gap[i+1];
    lable->show();

 }


out.exec();

}




