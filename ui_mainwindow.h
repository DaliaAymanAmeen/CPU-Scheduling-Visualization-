/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *RB_FCFS;
    QRadioButton *RB_priority;
    QRadioButton *RB_sjf;
    QRadioButton *RB_rr;
    QRadioButton *RB_preemptive_SJF;
    QRadioButton *Pre_Priority;
    QPushButton *pushButton;
    QPushButton *NewOperation;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("border-color: rgb(255, 85, 255);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(30, 40, 291, 261));
        groupBox->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        RB_FCFS = new QRadioButton(groupBox);
        RB_FCFS->setObjectName(QString::fromUtf8("RB_FCFS"));

        verticalLayout->addWidget(RB_FCFS);

        RB_priority = new QRadioButton(groupBox);
        RB_priority->setObjectName(QString::fromUtf8("RB_priority"));

        verticalLayout->addWidget(RB_priority);

        RB_sjf = new QRadioButton(groupBox);
        RB_sjf->setObjectName(QString::fromUtf8("RB_sjf"));

        verticalLayout->addWidget(RB_sjf);

        RB_rr = new QRadioButton(groupBox);
        RB_rr->setObjectName(QString::fromUtf8("RB_rr"));

        verticalLayout->addWidget(RB_rr);

        RB_preemptive_SJF = new QRadioButton(groupBox);
        RB_preemptive_SJF->setObjectName(QString::fromUtf8("RB_preemptive_SJF"));

        verticalLayout->addWidget(RB_preemptive_SJF);

        Pre_Priority = new QRadioButton(groupBox);
        Pre_Priority->setObjectName(QString::fromUtf8("Pre_Priority"));

        verticalLayout->addWidget(Pre_Priority);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(410, 290, 81, 31));
        NewOperation = new QPushButton(centralwidget);
        NewOperation->setObjectName(QString::fromUtf8("NewOperation"));
        NewOperation->setGeometry(QRect(510, 290, 111, 28));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Process:", nullptr));
        RB_FCFS->setText(QCoreApplication::translate("MainWindow", "FCFS", nullptr));
        RB_priority->setText(QCoreApplication::translate("MainWindow", "Priority", nullptr));
        RB_sjf->setText(QCoreApplication::translate("MainWindow", "SJF", nullptr));
        RB_rr->setText(QCoreApplication::translate("MainWindow", "Round_Robin", nullptr));
        RB_preemptive_SJF->setText(QCoreApplication::translate("MainWindow", "Preemptive_SJF", nullptr));
        Pre_Priority->setText(QCoreApplication::translate("MainWindow", "Pre_Priority", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Next", nullptr));
        NewOperation->setText(QCoreApplication::translate("MainWindow", "New Operation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
