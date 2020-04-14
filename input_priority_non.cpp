#include "input_priority_non.h"
#include "ui_input_priority_non.h"
#include <QString>
#include<QDebug>
#include <QLabel>
#include <QMessageBox>
#include"output.h"
#include <QTextEdit>
#include <QDoubleValidator>

input_priority_non::input_priority_non(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::input_priority_non)
{
    ui->setupUi(this);
}

input_priority_non::~input_priority_non()
{
    delete ui;
}

int j=0;
QString Process1[1000];
float ArrivalTime1[1000];
float BurstTime1[1000];
QString proc_name[1000];
float bt[1000];
float arr[1000];
float priority[1000];
float starting[1000];
float waiting [1000];
float gap1[1000];
float turnaroundAvg;
float waitingAvg;
float starting_time1[1000];

void input_priority_non::on_PB_next_clicked()
{

    int pos=0;
        QString arrival =ui->lineEdit_arrival_2->text();
        QString Burst=ui->lineEdit_burst_2->text();
        QString Priority=ui->priority->text();

         QDoubleValidator v( 0, 10000,3, this );




        if(v.validate(arrival , pos)==QValidator::Invalid ||v.validate(Burst , pos)==QValidator::Invalid  ||v.validate(Priority , pos)==QValidator::Invalid)
        {
            QMessageBox::warning(this, "Wrong input", "Please enter a number");

        }

    else{
    Process1[j]=ui->lineEdit_name_2->text();
    ArrivalTime1[j]=ui->lineEdit_arrival_2->text().split(" ")[0].toFloat();
    BurstTime1[j]=ui->lineEdit_burst_2->text().split(" ")[0].toFloat();
    priority[j]=ui->priority->text().split(" ")[0].toFloat();

    j++;
    ui->lineEdit_name_2->clear();
    ui->lineEdit_arrival_2->clear();
    ui->lineEdit_burst_2->clear();
    ui->priority->clear();
    }
}



float bt_comparison(float v[], int count) {

    float sum = 0;
    for (int i = 0; i < count; i++) {
        sum += v[i];
    }
    return sum;
}


void sort_process_nonpre( QString proc_name[] , float bt[] ,  float arr[] ,float priority[] , int size) {

   float temp ;
            int index;
    QString temp_str;

    for (int i = 0; i < size ; i++) {

        index = i;

        if(i == 0){
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[index]) {

                    index = j;

            }
            else if (arr[j] == arr[index]) {
                if(priority[j] < priority[index]){

                    index = j;

                }

                //we can handle if priorities are equal by process name.
            }
        }
        }
        else {

            for (int j = i + 1; j < size; j++) {
                if (arr[j] <= bt_comparison(bt,index) && priority[j] < priority[index]) {

                    index = j;

                    //we can handle if priorities are equal by process name.

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


        temp = priority[i];
        priority[i] = priority[index];
        priority[index] = temp;
    }


}


void calc_waiting_starting_gap (float bt[] , float arr[] , float starting[] , float waiting[], float gap1[] ,int size) {


    for (int i = 0; i < size; i++) {

        if (i == 0) {
            starting[i] = arr[i];
            waiting[i] = 0;
        }
        else {
            starting[i] = bt_comparison(bt, i) + arr[0];
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



float  turnaround_avg(float bt[] , float waiting[] , int size ) {

    float ta_avg = 0;

    for (int i = 0; i < size; i++) {

        ta_avg += (bt[i] + waiting[i]);

    }

    ta_avg = ta_avg / size;

    return ta_avg;
}

// this function simply return average waiting time.

float  waiting_avg(float waiting[] , int size) {
    float avg = 0;
    for (int i = 0; i < size; i++) {
        avg += waiting[i];
    }
    avg = avg / size;

    return avg;
}

void Gant_chart1(QString Process1[], float ArrivalTime1[], float BurstTime1[], int size,float starting_time[], float gap1[]) {
    //gap.resize(size);
    //starting_time.resize(size);
    for (int i = 0; i < size; i++) {
        if (i == 0) {
            starting_time[0] = ArrivalTime1[0];
            if (ArrivalTime1[0] > 0) {
                gap1[0] = ArrivalTime1[0];
            }
            gap1[0] = 0;
        }
        else if (i == size) {
            starting_time[i] = ArrivalTime1[i - 1] + BurstTime1[i - 1];
        }
        else if (starting_time[i - 1] + BurstTime1[i - 1] < ArrivalTime1[i]) {
            starting_time[i] = ArrivalTime1[i];
            gap1[i] = ArrivalTime1[i] - (starting_time[i - 1] + BurstTime1[i - 1]);
        }
        else {
            starting_time[i] = starting_time[i - 1] + BurstTime1[i - 1];
            gap1[i] = 0;
        }

    }
}


void input_priority_non::on_PB_finish_clicked()
{


    int pos=0;
        QString arrival =ui->lineEdit_arrival_2->text();
        QString Burst=ui->lineEdit_burst_2->text();
        QString Priority =ui->priority->text();
         QDoubleValidator v( 0, 10000,3, this );




        if(v.validate(arrival , pos)==QValidator::Invalid ||v.validate(Burst , pos)==QValidator::Invalid ||v.validate(Priority , pos)==QValidator::Invalid)
        {
            QMessageBox::warning(this, "Wrong input", "Please enter a number");

        }

    else{
    Process1[j]=ui->lineEdit_name_2->text();
    ArrivalTime1[j]=ui->lineEdit_arrival_2->text().split(" ")[0].toFloat();
    BurstTime1[j]=ui->lineEdit_burst_2->text().split(" ")[0].toFloat();
    priority[j]=ui->priority->text().split(" ")[0].toFloat();

    sort_process_nonpre(Process1 , BurstTime1 , ArrivalTime1 , priority , j+1);
   calc_waiting_starting_gap(BurstTime1 , ArrivalTime1 , starting , waiting , gap1 , j+1);

    turnaroundAvg=turnaround_avg( BurstTime1 , waiting , j+1 );
    waitingAvg=waiting_avg( waiting , j+1);

    Gant_chart1(Process1, ArrivalTime1,  BurstTime1, j+1 ,starting_time1, gap1);


    //QMessageBox::about(this, "test", Process1[0]);
    //QMessageBox::about(this, "test", QString::number(turnaroundAvg));
    //QMessageBox::about(this, "test", QString::number(waitingAvg));

    //ui->waitingTimeView->setText(QString::number(waitingAvg));
    //ui->turnAroundTimeView->setText(QString::number(turnaroundAvg));


output out;
out.setModal(true);


QTextEdit* text_avg =new QTextEdit(&out);
QTextEdit* text_TurnAround =new QTextEdit(&out);
text_avg->setText(QString::number(waitingAvg));
text_avg->setFixedHeight(30);
text_TurnAround->setText(QString::number(turnaroundAvg));
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
 for(int i=0;i<j+1;i++)
 {

    QLabel* label = new QLabel(&out);
    label->setText(Process1[i]);

    if(i==0)
    {
        label->setFixedWidth((int(BurstTime1[i]))*14);
        move=BurstTime1[0]+gap1[1];

    }

    else
    {
        label->setFixedWidth((int(BurstTime1[i]))*14);
        label->move((move)*14,0);
        move+=BurstTime1[i]+gap1[i+1];

    }

    label->setStyleSheet("QLabel {text-align: center;background-color :pink; color :white; border-width : 2px ; border-style: solid; border-color:white }");
    //label->setLayout(QLay)
     label->show();

 }



int move1=0;

 for (int i=0 ; i<j+1 ; i++)
 {
    QLabel* lable =new QLabel(&out);
    lable->setText(QString::number(starting_time1[i]));
    lable->move((move1)*14,21);
    move1+=BurstTime1[i]+gap1[i+1];
    lable->show();
    if (i==j)
    {  QLabel* lable =new QLabel(&out);
        lable->move((move1)*14,21);
        lable->setText(QString::number(starting_time1[i]+BurstTime1[i]));
        move1+=BurstTime1[i]+gap1[i+1];
        lable->show();
    }

 }
 int move2=BurstTime1[0];

 for (int i=0 ; i<j+1 ; i++)
 {
   if (gap1[i+1]==0) {move2+=BurstTime1[i]; continue;}
   QLabel* lable =new QLabel(&out);
   lable->move((move2)*14,21);
   lable->setText(QString::number(starting_time1[i]+BurstTime1   [i]));
   move2+=BurstTime1[i+1]+gap1[i+1];
   lable->show();

 }


 out.exec();
 for(int i=0;i<j+1;i++)
 {
     Process1[i]="";
     ArrivalTime1[i]=0;
    BurstTime1[i]=0;
     proc_name[i]="";
     bt[i]=0;
     arr[i]=0;
     priority[i]=0;
     starting[i]=0;
     waiting[i]=0;
     gap1[i]=0;

     starting_time1[i]=0;

 }
 waitingAvg=0;
 turnaroundAvg=0;
 j=0;
 move=0;
 move1=0;
 move2=0;
 ui->lineEdit_name_2->clear();
 ui->lineEdit_arrival_2->clear();
 ui->lineEdit_burst_2->clear();
 ui->priority->clear();
        }

}


