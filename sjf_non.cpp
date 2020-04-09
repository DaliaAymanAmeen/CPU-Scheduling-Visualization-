#include "sjf_non.h"
#include "ui_sjf_non.h"
#include <QString>
#include<QDebug>
#include <QLabel>
#include <QMessageBox>
#include "output.h"
#include <QTextEdit>

SJF_non::SJF_non(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SJF_non)
{
    ui->setupUi(this);
}

SJF_non::~SJF_non()
{
    delete ui;
}

int l=0;
QString Process2[1000];
int ArrivalTime2[1000];
int BurstTime2[1000];
int bt1[1000];
int arr1[1000];
int starting1[1000];
int waiting1[1000];
int gap2[1000];
float turnaroundAvg1;
float waitingAvg1;
int starting_time2[1000];


void SJF_non::on_PB_next_clicked()
{
    Process2[l]=ui->lineEdit_name_3->text();
    ArrivalTime2[l]=ui->lineEdit_arrival_3->text().split(" ")[0].toInt();
    BurstTime2[l]=ui->lineEdit_burst_3->text().split(" ")[0].toInt();

    l++;
    ui->lineEdit_name_3->clear();
    ui->lineEdit_arrival_3->clear();
    ui->lineEdit_burst_3->clear();

}

int bt_comparison1(int v[], int count) {

    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += v[i];
    }
    return sum;
}

void sort_process_sjf_nonpre(QString proc_name[] , int bt[] , int arr[] , int size) {

        int temp , index ;
        QString temp_str;

        for (int i = 0; i < size ; i++) {

            index = i;

            if(i == 0){
            for (int j = i + 1; j < size; j++) {
                if (arr[j] < arr[index]) {

                        index = j;

                }
                else if (arr[j] == arr[index]) {
                    if(bt[j] < bt[index]){

                        index = j;

                    }

                    //we can handle if burst are equal by process name.
                }
            }
            }
            else {

                for (int j = i + 1; j < size; j++) {
                    if (arr[j] <= (bt_comparison1(bt,i))) {
                        if (arr[i] > bt_comparison1(bt,i)) {
                            index = j;
                    }
                        else if (bt[j] < bt[index]) {
                            index = j;
                        }

                        else if(bt[j] == bt[index]){
                            if (arr[j] < arr[index]) {
                                index = j;
                        }
                        }
                        //we can handle if burst are equal by process name.

                    }

                }


            }


            temp_str = proc_name[i];
            proc_name[i] = proc_name[index];
            proc_name[index] = temp_str;

            temp = bt[i];
            bt[i] = bt[index];
            bt[index] = temp;


            temp = arr[i];
            arr[i] = arr[index];
            arr[index] = temp;


        }


    }

void calc_waiting_starting_gap1 (int bt[] , int arr[] , int starting[] , int waiting[], int gap1[] ,int size) {


    for (int i = 0; i < size; i++) {

        if (i == 0) {
            starting[i] = arr[i];
            waiting[i] = 0;
        }
        else {
            starting[i] = bt_comparison1(bt, i) + arr[0];
            if(arr[i] > starting[i]){
                gap1[i] = arr[i] - starting[i];
                starting[i] = arr[i];
                waiting[i] = starting[i] - arr[i];

            }

            else {
                waiting[i] = starting[i] - arr[i];
            }
        }
    }

}



float  turnaround_avg1(int bt[] , int waiting[] , int size ) {

    float ta_avg = 0;

    for (int i = 0; i < size; i++) {

        ta_avg += (bt[i] + waiting[i]);

    }

    ta_avg = ta_avg / size;

    return ta_avg;
}

// this function simply return average waiting time.

float  waiting_avg1(int waiting[] , int size) {
    float avg = 0;
    for (int i = 0; i < size; i++) {
        avg += waiting[i];
    }
    avg = avg / size;

    return avg;
}


void Gant_chart2(QString Process2[], int ArrivalTime2[], int BurstTime2[], int size,int starting_time2[], int gap2[]) {
    //gap.resize(size);
    //starting_time.resize(size);
    for (int i = 0; i < size; i++) {
        if (i == 0) {
            starting_time2[0] = ArrivalTime2[0];
            if (ArrivalTime2[0] > 0) {
                gap2[0] = ArrivalTime2[0];
            }
            gap2[0] = 0;
        }
        else if (i == size) {
            starting_time2[i] = ArrivalTime2[i - 1] + BurstTime2[i - 1];
        }
        else if (starting_time2[i - 1] + BurstTime2[i - 1] < ArrivalTime2[i]) {
            starting_time2[i] = ArrivalTime2[i];
            gap2[i] = ArrivalTime2[i] - (starting_time2[i - 1] + BurstTime2[i - 1]);
        }
        else {
            starting_time2[i] = starting_time2[i - 1] + BurstTime2[i - 1];
            gap2[i] = 0;
        }

    }
}





void SJF_non::on_PB_finish_clicked()
{
    Process2[l]=ui->lineEdit_name_3->text();
    ArrivalTime2[l]=ui->lineEdit_arrival_3->text().split(" ")[0].toInt();
    BurstTime2[l]=ui->lineEdit_burst_3->text().split(" ")[0].toInt();

   sort_process_sjf_nonpre(Process2 , BurstTime2 ,ArrivalTime2 , l+1);
   calc_waiting_starting_gap1(BurstTime2 , ArrivalTime2 , starting1 , waiting1 , gap2 , l+1);

    turnaroundAvg1=turnaround_avg1( BurstTime2 , waiting1 , l+1 );
    waitingAvg1=waiting_avg1( waiting1 , l+1);

    //QMessageBox::about(this, "test", Process1[0]);
    //QMessageBox::about(this, "test", QString::number(turnaroundAvg));
    //QMessageBox::about(this, "test", QString::number(waitingAvg));

    //ui->waitingTimeView->setText(QString::number(waitingAvg1));
    //ui->turnAroundTimeView->setText(QString::number(turnaroundAvg1));
    Gant_chart2(Process2, ArrivalTime2,  BurstTime2, l+1 ,starting_time2, gap2);

    output out;
    out.setModal(true);



//el output betla3 fe dool
    QTextEdit* text_avg =new QTextEdit(&out);
    QTextEdit* text_TurnAround =new QTextEdit(&out);
    text_avg->setText(QString::number(waitingAvg1));
    text_avg->setFixedHeight(30);
    text_TurnAround->setText(QString::number(turnaroundAvg1));
    text_TurnAround->setFixedHeight(30);

    text_avg->move(200,120);
    text_TurnAround->move(200,150);
    text_avg->show();
    text_TurnAround->show();
//el labels elly abl el output
    QLabel* label_avg =new QLabel(&out);
    label_avg->setText("Average Waiting time is:");
    label_avg->move(50,130);
    QLabel* label_turn= new QLabel(&out);
    label_turn->setText("Average TurnAround Time is :");
    label_turn->move(50,160);
    label_avg->show();
    label_turn->show();

    int move=0;
 for(int i=0;i<l+1;i++)
 {

    QLabel* label = new QLabel(&out);
    label->setText(Process2[i]);

    if(i==0)
    {
        label->setFixedWidth((int(BurstTime2[i]))*7);
        move=BurstTime2[0]+gap2[1];

    }

    else
    {
        label->setFixedWidth((int(BurstTime2[i]))*7);
        label->move((move)*7,0);
        move+=BurstTime2[i]+gap2[i+1];

    }

    label->setStyleSheet("QLabel {text-align: center;background-color :pink; color :white; border-width : 2px ; border-style: solid; border-color:white }");
    //label->setLayout(QLay)
     label->show();

 }


int move1=0;

 for (int i=0 ; i<l+1 ; i++)
 {
    QLabel* lable =new QLabel(&out);
    lable->setText(QString::number(starting_time2[i]));
    lable->move((move1)*7,21);
    move1+=BurstTime2[i]+gap2[i+1];
    lable->show();

 }
out.exec();
}
