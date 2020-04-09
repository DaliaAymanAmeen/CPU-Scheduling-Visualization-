#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "input_fcfs.h"
#include <input_priority_non.h>
#include <sjf_non.h>
#include <preemptive.h>
#include <rr.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if(ui->RB_FCFS->isChecked())
    {
        input_fcfs fcfsIn;
        fcfsIn.setModal(true);
        fcfsIn.exec();
    }

    else if(ui->RB_priority->isChecked())
    {
        input_priority_non priority_non;
        priority_non.setModal(true);
        priority_non.exec();
    }

    else if(ui->RB_sjf->isChecked())
    {
        SJF_non sjf_non;
        sjf_non.setModal(true);
        sjf_non.exec();
    }

    else if(ui->RB_preemptive->isChecked())
    {
        preemptive preemptive;
        preemptive.setModal(true);
        preemptive.exec();
    }

    else if (ui->RB_rr->isChecked())
    {
        rr rr;
        rr.setModal(true);
        rr.exec();


    }




}
