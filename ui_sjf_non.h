/********************************************************************************
** Form generated from reading UI file 'sjf_non.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SJF_NON_H
#define UI_SJF_NON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SJF_non
{
public:
    QPushButton *PB_next;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEdit_arrival_3;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *lineEdit_burst_3;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *lineEdit_name_3;
    QPushButton *PB_finish;

    void setupUi(QDialog *SJF_non)
    {
        if (SJF_non->objectName().isEmpty())
            SJF_non->setObjectName(QString::fromUtf8("SJF_non"));
        SJF_non->resize(769, 544);
        PB_next = new QPushButton(SJF_non);
        PB_next->setObjectName(QString::fromUtf8("PB_next"));
        PB_next->setGeometry(QRect(260, 230, 75, 23));
        layoutWidget = new QWidget(SJF_non);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 70, 161, 31));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        lineEdit_arrival_3 = new QLineEdit(layoutWidget);
        lineEdit_arrival_3->setObjectName(QString::fromUtf8("lineEdit_arrival_3"));

        horizontalLayout_4->addWidget(lineEdit_arrival_3);

        layoutWidget_2 = new QWidget(SJF_non);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(20, 110, 161, 51));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);

        lineEdit_burst_3 = new QLineEdit(layoutWidget_2);
        lineEdit_burst_3->setObjectName(QString::fromUtf8("lineEdit_burst_3"));

        horizontalLayout_5->addWidget(lineEdit_burst_3);

        layoutWidget_3 = new QWidget(SJF_non);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(20, 30, 161, 31));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_6->addWidget(label_6);

        lineEdit_name_3 = new QLineEdit(layoutWidget_3);
        lineEdit_name_3->setObjectName(QString::fromUtf8("lineEdit_name_3"));

        horizontalLayout_6->addWidget(lineEdit_name_3);

        PB_finish = new QPushButton(SJF_non);
        PB_finish->setObjectName(QString::fromUtf8("PB_finish"));
        PB_finish->setGeometry(QRect(380, 230, 75, 23));
        QWidget::setTabOrder(lineEdit_name_3, lineEdit_arrival_3);
        QWidget::setTabOrder(lineEdit_arrival_3, lineEdit_burst_3);
        QWidget::setTabOrder(lineEdit_burst_3, PB_next);
        QWidget::setTabOrder(PB_next, PB_finish);

        retranslateUi(SJF_non);

        QMetaObject::connectSlotsByName(SJF_non);
    } // setupUi

    void retranslateUi(QDialog *SJF_non)
    {
        SJF_non->setWindowTitle(QCoreApplication::translate("SJF_non", "Dialog", nullptr));
        PB_next->setText(QCoreApplication::translate("SJF_non", "next", nullptr));
        label_4->setText(QCoreApplication::translate("SJF_non", "arrival time", nullptr));
        label_5->setText(QCoreApplication::translate("SJF_non", "burst time", nullptr));
        label_6->setText(QCoreApplication::translate("SJF_non", "process name", nullptr));
        PB_finish->setText(QCoreApplication::translate("SJF_non", "finish", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SJF_non: public Ui_SJF_non {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SJF_NON_H
