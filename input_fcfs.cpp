#include "input_fcfs.h"
#include "ui_input_fcfs.h"
#include <QString>
#include<QLabel>
#include<QDebug>
#include <QMessageBox>
#include "output.h"
#include "ui_output.h"
#include <QTextEdit>
#include <QIntValidator>
#include <QDoubleValidator>

input_fcfs::input_fcfs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::input_fcfs)
{
    ui->setupUi(this);
    QPixmap bkgnd(":/new/prefix1/img/watercolour-texture-background-vector.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);


   // priority_non.exec();
}

input_fcfs::~input_fcfs()
{
    delete ui;
}



int k=0;
QString Process[1000];
float ArrivalTime[1000];
float BurstTime[1000];
float WaitingTime[1000];
float TurnAroundTime[1000];
float AvgWaitingTime=0;
float AvgTurnAround=0;
float starting_time[1000];
float gap[1000];


void input_fcfs::on_PB_next_clicked()
{   int pos=0;
    QString arrival =ui->lineEdit_arrival->text();
    QString Burst=ui->lineEdit_burst->text();
    QDoubleValidator vd(0,1000,3,this);
     //QIntValidator v( 0, 10000, this );




    if(vd.validate(arrival , pos)==QValidator::Invalid ||vd.validate(Burst , pos)==QValidator::Invalid  )
    {
        QMessageBox::warning(this, "Wrong input", "Please enter a number");

    }
    else{
        Process[k]=ui->lineEdit_name->text();
    ArrivalTime[k]=ui->lineEdit_arrival->text().split(" ")[0].toFloat();
    BurstTime[k]=ui->lineEdit_burst->text().split(" ")[0].toFloat();
    k++;
    ui->lineEdit_name->clear();
    ui->lineEdit_arrival->clear();
    ui->lineEdit_burst->clear();
    }
}



void Sort_arriaval_time(QString Process[], float ArrivalTime[], float BurstTime[], int size) {
    float temp_at;
    float temp_bt;
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



void find_waiting_time(QString Process[], float ArrivalTime[], float BurstTime[], int size, float WaitingTime[]) {
    Sort_arriaval_time(Process, ArrivalTime, BurstTime, size);

    //int *service_time = new int[size];        //ghayart di l array 3adi
    float service_time [1000];
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



void find_total_arround_time(QString Process[], float ArrivalTime[], float BurstTime[], int size,float WaitingTime[], float TurnAroundTime[]) {
    find_waiting_time(Process, ArrivalTime, BurstTime, size, WaitingTime);

    //TurnAroundTime.resize(size);   //Change

    for (int i = 0; i < size; i++) {
        TurnAroundTime[i] = WaitingTime[i] + BurstTime[i];
    }
}


void find_total_average_time(QString Process[], float ArrivalTime[], float BurstTime[], int size, float WaitingTime[], float TurnAroundTime[],
   float &AvgWaitingTime, float &AvgTurnAround)  {

    float sumOfTurnAround = 0;
    find_total_arround_time(Process, ArrivalTime, BurstTime, size, WaitingTime, TurnAroundTime);
    float sumOfWaitingTime = 0;
    find_waiting_time(Process, ArrivalTime, BurstTime, size, WaitingTime);
    for (int i = 0; i < size; i++)
    {
        sumOfTurnAround += TurnAroundTime[i];
        sumOfWaitingTime += WaitingTime[i];
    }
    AvgWaitingTime = (float)sumOfWaitingTime / (float)size;
    AvgTurnAround = (float)sumOfTurnAround / (float)size;
}


void Gant_chart(QString Process[], float ArrivalTime[], float BurstTime[], int size,float starting_time[], float gap[]) {
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
    int pos=0;
        QString arrival =ui->lineEdit_arrival->text();
        QString Burst=ui->lineEdit_burst->text();
         QDoubleValidator v( 0, 10000,3, this );




        if(v.validate(arrival , pos)==QValidator::Invalid ||v.validate(Burst , pos)==QValidator::Invalid)
        {
            QMessageBox::warning(this, "Wrong input", "Please enter a number");

        }


    else{
    Process[k]=ui->lineEdit_name->text();
    ArrivalTime[k]=ui->lineEdit_arrival->text().split(" ")[0].toFloat();
    BurstTime[k]=ui->lineEdit_burst->text().split(" ")[0].toFloat();


    find_total_average_time(Process, ArrivalTime,  BurstTime, k+1 ,  WaitingTime,  TurnAroundTime,
        AvgWaitingTime,  AvgTurnAround);

    //QMessageBox::about(this, "test",  QString::number(AvgWaitingTime));
    //QMessageBox::about(this, "test", QString::number(AvgTurnAround));


    Gant_chart(Process, ArrivalTime,  BurstTime, k+1 ,starting_time, gap);


    //QMessageBox::about(this, "test", QString::number(starting_time[0]));

    //to check the output
    //
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

    text_avg->move(200,150); //
    text_TurnAround->move(200,190); //
    text_avg->show();
    text_TurnAround->show();

    QLabel* label_avg =new QLabel(&out);
    label_avg->setText("Average Waiting time:");
    label_avg->move(50,160); //
    QLabel* label_turn= new QLabel(&out);
    label_turn->setText("Average TurnAround Time:");
    label_turn->move(50,200); //
    label_avg->show();
    label_turn->show();


   int move=0;
 for(int i=0;i<k+1;i++)
 {

    QLabel* label = new QLabel(&out);
    label->setText(Process[i]);

    if(i==0)
    {
        label->move(5,300);
        label->setFixedWidth((int(BurstTime[i]))*14);
        label->setFixedHeight(25);

        move=BurstTime[0]+gap[1];

    }

    else
    {
        label->setFixedWidth((int(BurstTime[i]))*14);
        label->setFixedHeight(25);
        label->move((move)*14,300);
        move+=BurstTime[i]+gap[i+1];

    }

    label->setStyleSheet("QLabel {text-align: center;background-color :rgb(148, 200, 190);color :white; border-width : 2px ; border-style: solid; border-color:white }");
    //label->setLayout(QLay)
     label->show();

 }



int move1=0;

 for (int i=0 ; i<k+1 ; i++)
 {

    QLabel* lable =new QLabel(&out);
    lable->setText(QString::number(starting_time[i]));
    lable->move((move1)*14,325);
    move1+=BurstTime[i]+gap[i+1];
    lable->show();
    if (i==k)
        {  QLabel* lable =new QLabel(&out);
            lable->move((move1)*14,325);
            lable->setText(QString::number(starting_time[i]+BurstTime[i]));
            move1+=BurstTime[i]+gap[i+1];
            lable->show();
        }

 }

int move2=BurstTime[0];

   for (int i=0 ; i<k+1 ; i++)
   {
      if (gap[i+1]==0){move2+=BurstTime[i]; continue;}
      QLabel* lable =new QLabel(&out);
      lable->move((move2)*14,325);
      lable->setText(QString::number(starting_time[i]+BurstTime[i]));
      move2+=BurstTime[i+1]+gap[i+1];
      lable->show();

   }
out.exec();
for(int i=0;i<k+1;i++)
{
    Process[i]="";
    ArrivalTime[i]=0;
    BurstTime[i]=0;
    WaitingTime[i]=0;
    TurnAroundTime[i]=0;

    starting_time[i]=0;
    gap[i]=0;

}
AvgWaitingTime=0;
AvgTurnAround=0;
k=0;
move=0;
move1=0;
move2=0;
ui->lineEdit_name->clear();
ui->lineEdit_arrival->clear();
ui->lineEdit_burst->clear();
    }
}




