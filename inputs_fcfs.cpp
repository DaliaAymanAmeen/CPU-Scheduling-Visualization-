#include "inputs_fcfs.h"
#include "ui_inputs_fcfs.h"

INPUTS_FCFS::INPUTS_FCFS(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::INPUTS_FCFS)
{
    ui->setupUi(this);
}

INPUTS_FCFS::~INPUTS_FCFS()
{
    delete ui;
}
