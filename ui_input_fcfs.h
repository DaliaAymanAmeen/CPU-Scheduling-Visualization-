/********************************************************************************
** Form generated from reading UI file 'input_fcfs.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUT_FCFS_H
#define UI_INPUT_FCFS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_input_fcfs
{
public:
    QPushButton *PB_next;
    QPushButton *PB_finish;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_name;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_arrival;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_burst;

    void setupUi(QDialog *input_fcfs)
    {
        if (input_fcfs->objectName().isEmpty())
            input_fcfs->setObjectName(QString::fromUtf8("input_fcfs"));
        input_fcfs->resize(769, 544);
        input_fcfs->setMaximumSize(QSize(769, 544));
        PB_next = new QPushButton(input_fcfs);
        PB_next->setObjectName(QString::fromUtf8("PB_next"));
        PB_next->setGeometry(QRect(250, 250, 75, 23));
        PB_finish = new QPushButton(input_fcfs);
        PB_finish->setObjectName(QString::fromUtf8("PB_finish"));
        PB_finish->setGeometry(QRect(370, 250, 75, 23));
        layoutWidget = new QWidget(input_fcfs);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 50, 161, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit_name = new QLineEdit(layoutWidget);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));

        horizontalLayout->addWidget(lineEdit_name);

        layoutWidget1 = new QWidget(input_fcfs);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 90, 161, 31));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_arrival = new QLineEdit(layoutWidget1);
        lineEdit_arrival->setObjectName(QString::fromUtf8("lineEdit_arrival"));

        horizontalLayout_2->addWidget(lineEdit_arrival);

        layoutWidget2 = new QWidget(input_fcfs);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 130, 161, 51));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEdit_burst = new QLineEdit(layoutWidget2);
        lineEdit_burst->setObjectName(QString::fromUtf8("lineEdit_burst"));

        horizontalLayout_3->addWidget(lineEdit_burst);


        retranslateUi(input_fcfs);

        QMetaObject::connectSlotsByName(input_fcfs);
    } // setupUi

    void retranslateUi(QDialog *input_fcfs)
    {
        input_fcfs->setWindowTitle(QCoreApplication::translate("input_fcfs", "Dialog", nullptr));
        PB_next->setText(QCoreApplication::translate("input_fcfs", "next", nullptr));
        PB_finish->setText(QCoreApplication::translate("input_fcfs", "finish", nullptr));
        label->setText(QCoreApplication::translate("input_fcfs", "process name", nullptr));
        label_2->setText(QCoreApplication::translate("input_fcfs", "arrival time", nullptr));
        label_3->setText(QCoreApplication::translate("input_fcfs", "burst time", nullptr));
    } // retranslateUi

};

namespace Ui {
    class input_fcfs: public Ui_input_fcfs {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUT_FCFS_H
