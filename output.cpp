#include "output.h"
#include "ui_output.h"
#include "input_fcfs.h"
#include"ui_input_fcfs.h"
#include "rr.h"
#include <QString>

output::output(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::output)
{
    ui->setupUi(this);

    //this->setStyleSheet("background-color: white;");

   //ui->textEdit_ave->setText(QString::number(&AvgWaitingTime));

           //ui->waitingTimeView->setText(QString::number(AvgWaitingTime));
           //ui->turnAroundTimeView->setText(QString::number(AvgTurnAround));
}

output::~output()
{
    delete ui;
}
