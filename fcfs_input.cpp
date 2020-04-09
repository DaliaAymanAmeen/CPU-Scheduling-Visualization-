#include "fcfs_input.h"
#include "ui_fcfs_input.h"

fcfs_input::fcfs_input(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::fcfs_input)
{
    ui->setupUi(this);
}

fcfs_input::~fcfs_input()
{
    delete ui;
}
