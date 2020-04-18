#include "output.h"
#include "ui_output.h"
#include "input_fcfs.h"
#include"ui_input_fcfs.h"
#include "rr.h"
#include "preemptive.h"
#include <QString>

output::output(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::output)
{
    ui->setupUi(this);

    QPixmap bkgnd(":/new/prefix1/img/watercolour-texture-background-vector.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);


    //this->setStyleSheet("background-color: white;");

   //ui->textEdit_ave->setText(QString::number(&AvgWaitingTime));

           //ui->waitingTimeView->setText(QString::number(AvgWaitingTime));
           //ui->turnAroundTimeView->setText(QString::number(AvgTurnAround));
}

output::~output()
{
    delete ui;
}
