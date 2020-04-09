#include "rr.h"
#include "ui_rr.h"
#include <QString>
#include<QLabel>
#include<QDebug>
#include <QMessageBox>
#include "output.h"
#include "ui_output.h"
#include <QTextEdit>
#include "QVector"


rr::rr(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rr)
{
    ui->setupUi(this);
}

rr::~rr()
{
    delete ui;
}

int r=0;
QVector <QString> process6(1000);
QVector <int> ArrivalTime6(1000);
QVector <int> BurstTime6(1000);
QVector <QString> fixed_process(1000);
int TurnAroundTime6[1000];
float AvgWaitingTime6=0;
float AvgTurnAround6=0;
QVector <int> StartingTime6 (1000);
int Q;
int temp;
int old_size;
QVector <int> GapTime6 (1000);
int size1;

void rr::on_PB_next_clicked()
{
    process6[r]=ui->lineEdit_name6->text();
    ArrivalTime6[r]=ui->lineEdit_arrival6->text().split(" ")[0].toInt();
    BurstTime6[r]=ui->lineEdit_burst6->text().split(" ")[0].toInt();
    fixed_process[r]=process6[r];
    r++;
    ui->lineEdit_name6->clear();
    ui->lineEdit_arrival6->clear();
    ui->lineEdit_burst6->clear();

}

void erase( QVector <QString> &process , QVector <int>&ArrivalTime, QVector <int> &BurstTime, int &size,int i){
    //function to erase one element from each vector with index i
    for(int j=i ;j<size-1;j++)
    {
        process[j]=process[j+1];
        ArrivalTime[j]=ArrivalTime[j+1];
        BurstTime[j]=BurstTime[j+1];
    }
    size--;
    process.resize(size);
    ArrivalTime.resize(size);
    BurstTime.resize(size);

}


void sort_process( QVector <QString> &process,QVector <int>&ArrivalTime, QVector <int> &BurstTime, int &size){
    //function to sort processes according to arrival time.
    int temp_int;
    QString temp_process;
    for(int i=0;i<size;i++){
        for(int j=i;j<size;j++){
            if(ArrivalTime[j]<ArrivalTime[i]){
                //swape arrival time
                 temp_int=ArrivalTime[j];
                ArrivalTime[j]=ArrivalTime[i];
                ArrivalTime[i]= temp_int;
                //swape burst time
                 temp_int=BurstTime[j];
                 BurstTime[j]=BurstTime[i];
                 BurstTime[i]=temp_int;
                 //swape processes
                 temp_process=process[j];
                 process[j]=process[i];
                 process[i]=temp_process;
            }
        }
    }
}

void round_robin_editing(QVector <QString> &process,QVector <int>&ArrivalTime, QVector <int> &BurstTime, int &size,int Q){
            int temp_size=0,adder=0;
            QVector <QString> rr_process;
            QVector <int> rr_ArrivalTime;
            QVector <int>  rr_BurstTime;
            QVector <int>  rr_GapTime;
            int  rr_size;
            //calculating new number of processes according to RR and resizing the new vectors.
            for(int i=0;i<size;i++){
            if(BurstTime[i]%Q ==0)
            {temp_size=temp_size+(BurstTime[i]/Q);}
            else
            {temp_size=temp_size+(BurstTime[i]/Q)+1;}

            }
            rr_size=temp_size+1;
            rr_process.resize(rr_size);
            rr_ArrivalTime.resize(rr_size);
            rr_BurstTime.resize(rr_size);
            //cutting the old processes accroding to the RR and placing them in the new vectors
            int j=0,total_burst=0;
            while(size >0){
                for(int i=0;i<size;i++){
                    for(int k=0;k<j;k++){
                        total_burst+=rr_BurstTime[k];
                    }
                    if(((ArrivalTime[i]>total_burst)&& (i!=0)) && (ArrivalTime[i]>(total_burst+ArrivalTime[0])) )
                    {total_burst=0;
                    continue;}
                    total_burst=0;
                    rr_process[j]=process[i];
                    rr_ArrivalTime[j]=ArrivalTime[i];
                    if(BurstTime[i]>=Q)
                    {	rr_BurstTime[j]=Q;
                        BurstTime[i]=BurstTime[i]-Q;
                        if(BurstTime[i]==0)
                        {erase(process,ArrivalTime,BurstTime,size,i);
                        i--;}

                    }
                    else
                    {
                        rr_BurstTime[j]=BurstTime[i];
                        erase(process,ArrivalTime,BurstTime,size,i);
                        i--;

                    }
                    j++;

                }
            }
            //returning the new processes to old vectors
            size=rr_size-1;
            process.resize(size);
            ArrivalTime.resize(size);
            BurstTime.resize(size);
            for(int i=0;i<size;i++){
                process[i]=rr_process[i];
                ArrivalTime[i]=rr_ArrivalTime[i];
                BurstTime[i]=rr_BurstTime[i];
            }

    }

 void adding_starting_gap_time(QVector <QString> &process,QVector <int>&ArrivalTime, QVector <int> &BurstTime,QVector <int> &StartingTime,QVector <int> &GapTime, int &size)
        {
            int temp=0;
            //resizing new vectors to the new number of processes after modifying them.
            StartingTime.resize(size);
            GapTime.resize(size);
            //placing first element as is
            StartingTime[0]=ArrivalTime[0];
            GapTime[0]=ArrivalTime[0];
            //calculating starting time and Burst time by comparing with last element.
            for(int i=1;i<size;i++)
            {
                if((StartingTime[i-1]+BurstTime[i-1])>=ArrivalTime[i])
                {
                    StartingTime[i]=StartingTime[i-1]+BurstTime[i-1];
                    GapTime[i]=0;
                }
                else
                {

                    GapTime[i]=ArrivalTime[i]-(StartingTime[i-1]+BurstTime[i-1]);
                    StartingTime[i]=StartingTime[i-1]+BurstTime[i-1]+GapTime[i];
                }

            }
        }

void RR(QVector <QString> &process,QVector <int>&ArrivalTime, QVector <int> &BurstTime,QVector <int> &StartingTime,QVector <int> &GapTime, int &size,int Q){
            //sorting processes according to arrival time.
            sort_process(process,ArrivalTime,BurstTime,size);
            //making RR slices.
            round_robin_editing(process,ArrivalTime,BurstTime,size,Q);
            //adding starting and gap times to the processes.
            adding_starting_gap_time(process,ArrivalTime,BurstTime,StartingTime,GapTime,size);
        }

float AVG_waiting(QVector <int>&ArrivalTime,QVector <int> &StartingTime, int &size){

            int total_wait=0;
            for(int i=0;i<size;i++){
                total_wait+=StartingTime[i]-ArrivalTime[i];



            }
            return ((float)total_wait/(float)size);
        }

float AVG_TurnAround(QVector <QString> &process,QVector <QString> &old_process,QVector <int>&ArrivalTime, QVector <int> &BurstTime,QVector <int> &StartingTime,int &size,int &old_size){

            QVector <int> turn_around(old_size);
            int turn_aroundd=0,sum=0;
            for(int i=0;i<old_size;i++){
                for(int j=0;j<size;j++){
                    if(old_process[i]==process[j])
                    {turn_aroundd=StartingTime[j]+BurstTime[j]-ArrivalTime[j];}

                }
                turn_around[i]=turn_aroundd;
            }

            for(int i=0;i<old_size;i++)
                sum+=turn_around[i];
            return ((float)sum/(float)old_size);
        }





void rr::on_PB_finish_clicked()
{
    process6[r]=ui->lineEdit_name6->text();
    ArrivalTime6[r]=ui->lineEdit_arrival6->text().split(" ")[0].toInt();
    BurstTime6[r]=ui->lineEdit_burst6->text().split(" ")[0].toInt();
    Q=ui->lineEdit_timeslice->text().split(" ")[0].toInt();
    size1=r+1;
    old_size=size1;

    RR(process6,ArrivalTime6,BurstTime6,StartingTime6,GapTime6,size1,Q);
    AvgWaitingTime6 = AVG_waiting(ArrivalTime6,StartingTime6, size1);
    AvgTurnAround6 = AVG_TurnAround(process6,fixed_process,ArrivalTime6,BurstTime6,StartingTime6,size1,old_size);



    output out;
    out.setModal(true);
    QTextEdit* text_avg =new QTextEdit(&out);
    QTextEdit* text_TurnAround =new QTextEdit(&out);
    text_avg->setText(QString::number(AvgWaitingTime6));
    text_avg->setFixedHeight(30);
    text_TurnAround->setText(QString::number(AvgTurnAround6));
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
 for(int i=0;i<size1;i++)
 {

    QLabel* label = new QLabel(&out);
    label->setText(process6[i]);

    if(i==0)
    {
        label->setFixedWidth((int(BurstTime6[i]))*7);
        move=BurstTime6[0];

    }

    else
    {
        label->setFixedWidth((int(BurstTime6[i]))*7);
        label->move((move)*7,0);
        move+=BurstTime6[i];

    }

    label->setStyleSheet("QLabel {text-align: center;background-color :pink; color :white; border-width : 2px ; border-style: solid; border-color:white }");
    //label->setLayout(QLay)
     label->show();

 }


int move1=0;

 for (int i=0 ; i<size1 ; i++)
 {
    QLabel* lable =new QLabel(&out);
    lable->setText(QString::number(StartingTime6[i]));
    lable->move((move1)*7,21);
    move1+=BurstTime6[i];
    lable->show();

 }


out.exec();


}
