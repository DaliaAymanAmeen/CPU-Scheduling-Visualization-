/********************************************************************************
** Form generated from reading UI file 'rr.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RR_H
#define UI_RR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_rr
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_name6;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_arrival6;
    QPushButton *PB_next;
    QPushButton *PB_finish;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_burst6;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEdit_timeslice;

    void setupUi(QDialog *rr)
    {
        if (rr->objectName().isEmpty())
            rr->setObjectName(QString::fromUtf8("rr"));
        rr->resize(769, 544);
        layoutWidget = new QWidget(rr);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 60, 161, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit_name6 = new QLineEdit(layoutWidget);
        lineEdit_name6->setObjectName(QString::fromUtf8("lineEdit_name6"));

        horizontalLayout->addWidget(lineEdit_name6);

        layoutWidget_2 = new QWidget(rr);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(30, 100, 161, 31));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_arrival6 = new QLineEdit(layoutWidget_2);
        lineEdit_arrival6->setObjectName(QString::fromUtf8("lineEdit_arrival6"));

        horizontalLayout_2->addWidget(lineEdit_arrival6);

        PB_next = new QPushButton(rr);
        PB_next->setObjectName(QString::fromUtf8("PB_next"));
        PB_next->setGeometry(QRect(270, 260, 75, 23));
        PB_finish = new QPushButton(rr);
        PB_finish->setObjectName(QString::fromUtf8("PB_finish"));
        PB_finish->setGeometry(QRect(390, 260, 75, 23));
        layoutWidget_3 = new QWidget(rr);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(30, 140, 161, 51));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEdit_burst6 = new QLineEdit(layoutWidget_3);
        lineEdit_burst6->setObjectName(QString::fromUtf8("lineEdit_burst6"));

        horizontalLayout_3->addWidget(lineEdit_burst6);

        layoutWidget_4 = new QWidget(rr);
        layoutWidget_4->setObjectName(QString::fromUtf8("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(30, 200, 161, 51));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        lineEdit_timeslice = new QLineEdit(layoutWidget_4);
        lineEdit_timeslice->setObjectName(QString::fromUtf8("lineEdit_timeslice"));

        horizontalLayout_4->addWidget(lineEdit_timeslice);

        QWidget::setTabOrder(lineEdit_name6, lineEdit_arrival6);
        QWidget::setTabOrder(lineEdit_arrival6, lineEdit_burst6);
        QWidget::setTabOrder(lineEdit_burst6, lineEdit_timeslice);
        QWidget::setTabOrder(lineEdit_timeslice, PB_next);
        QWidget::setTabOrder(PB_next, PB_finish);

        retranslateUi(rr);

        QMetaObject::connectSlotsByName(rr);
    } // setupUi

    void retranslateUi(QDialog *rr)
    {
        rr->setWindowTitle(QCoreApplication::translate("rr", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("rr", "process name", nullptr));
        label_2->setText(QCoreApplication::translate("rr", "arrival time", nullptr));
        PB_next->setText(QCoreApplication::translate("rr", "next", nullptr));
        PB_finish->setText(QCoreApplication::translate("rr", "finish", nullptr));
        label_3->setText(QCoreApplication::translate("rr", "burst time", nullptr));
        lineEdit_burst6->setText(QString());
        label_4->setText(QCoreApplication::translate("rr", "time_slice", nullptr));
        lineEdit_timeslice->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class rr: public Ui_rr {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RR_H
