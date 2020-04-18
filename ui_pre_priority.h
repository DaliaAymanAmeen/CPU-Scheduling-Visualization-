/********************************************************************************
** Form generated from reading UI file 'pre_priority.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRE_PRIORITY_H
#define UI_PRE_PRIORITY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pre_priority
{
public:
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *lineEdit_Process;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *lineEdit_burst;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QLineEdit *priority_2;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEdit_arrival;
    QPushButton *PB_next;
    QPushButton *PB_finish;

    void setupUi(QDialog *pre_priority)
    {
        if (pre_priority->objectName().isEmpty())
            pre_priority->setObjectName(QString::fromUtf8("pre_priority"));
        pre_priority->resize(769, 544);
        layoutWidget_3 = new QWidget(pre_priority);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(60, 120, 161, 31));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_6->addWidget(label_6);

        lineEdit_Process = new QLineEdit(layoutWidget_3);
        lineEdit_Process->setObjectName(QString::fromUtf8("lineEdit_Process"));

        horizontalLayout_6->addWidget(lineEdit_Process);

        layoutWidget_2 = new QWidget(pre_priority);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(60, 200, 161, 51));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);

        lineEdit_burst = new QLineEdit(layoutWidget_2);
        lineEdit_burst->setObjectName(QString::fromUtf8("lineEdit_burst"));

        horizontalLayout_5->addWidget(lineEdit_burst);

        layoutWidget_4 = new QWidget(pre_priority);
        layoutWidget_4->setObjectName(QString::fromUtf8("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(60, 270, 161, 51));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_7->addWidget(label_7);

        priority_2 = new QLineEdit(layoutWidget_4);
        priority_2->setObjectName(QString::fromUtf8("priority_2"));

        horizontalLayout_7->addWidget(priority_2);

        layoutWidget = new QWidget(pre_priority);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(60, 160, 161, 31));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        lineEdit_arrival = new QLineEdit(layoutWidget);
        lineEdit_arrival->setObjectName(QString::fromUtf8("lineEdit_arrival"));

        horizontalLayout_4->addWidget(lineEdit_arrival);

        PB_next = new QPushButton(pre_priority);
        PB_next->setObjectName(QString::fromUtf8("PB_next"));
        PB_next->setGeometry(QRect(300, 320, 75, 23));
        PB_finish = new QPushButton(pre_priority);
        PB_finish->setObjectName(QString::fromUtf8("PB_finish"));
        PB_finish->setGeometry(QRect(420, 320, 75, 23));
        QWidget::setTabOrder(lineEdit_Process, lineEdit_arrival);
        QWidget::setTabOrder(lineEdit_arrival, lineEdit_burst);
        QWidget::setTabOrder(lineEdit_burst, priority_2);
        QWidget::setTabOrder(priority_2, PB_next);
        QWidget::setTabOrder(PB_next, PB_finish);

        retranslateUi(pre_priority);

        QMetaObject::connectSlotsByName(pre_priority);
    } // setupUi

    void retranslateUi(QDialog *pre_priority)
    {
        pre_priority->setWindowTitle(QCoreApplication::translate("pre_priority", "Dialog", nullptr));
        label_6->setText(QCoreApplication::translate("pre_priority", "process name", nullptr));
        label_5->setText(QCoreApplication::translate("pre_priority", "burst time", nullptr));
        label_7->setText(QCoreApplication::translate("pre_priority", "priority", nullptr));
        label_4->setText(QCoreApplication::translate("pre_priority", "arrival time", nullptr));
        PB_next->setText(QCoreApplication::translate("pre_priority", "next", nullptr));
        PB_finish->setText(QCoreApplication::translate("pre_priority", "finish", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pre_priority: public Ui_pre_priority {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRE_PRIORITY_H
