/********************************************************************************
** Form generated from reading UI file 'preemptive.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREEMPTIVE_H
#define UI_PREEMPTIVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_preemptive
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_name5;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_arrival5;
    QPushButton *PB_next;
    QPushButton *PB_finish;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_burst5;

    void setupUi(QDialog *preemptive)
    {
        if (preemptive->objectName().isEmpty())
            preemptive->setObjectName(QString::fromUtf8("preemptive"));
        preemptive->resize(769, 544);
        layoutWidget = new QWidget(preemptive);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 161, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit_name5 = new QLineEdit(layoutWidget);
        lineEdit_name5->setObjectName(QString::fromUtf8("lineEdit_name5"));

        horizontalLayout->addWidget(lineEdit_name5);

        layoutWidget_2 = new QWidget(preemptive);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(20, 60, 161, 31));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_arrival5 = new QLineEdit(layoutWidget_2);
        lineEdit_arrival5->setObjectName(QString::fromUtf8("lineEdit_arrival5"));

        horizontalLayout_2->addWidget(lineEdit_arrival5);

        PB_next = new QPushButton(preemptive);
        PB_next->setObjectName(QString::fromUtf8("PB_next"));
        PB_next->setGeometry(QRect(260, 220, 75, 23));
        PB_finish = new QPushButton(preemptive);
        PB_finish->setObjectName(QString::fromUtf8("PB_finish"));
        PB_finish->setGeometry(QRect(380, 220, 75, 23));
        layoutWidget_3 = new QWidget(preemptive);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(20, 100, 161, 51));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEdit_burst5 = new QLineEdit(layoutWidget_3);
        lineEdit_burst5->setObjectName(QString::fromUtf8("lineEdit_burst5"));

        horizontalLayout_3->addWidget(lineEdit_burst5);

        QWidget::setTabOrder(lineEdit_name5, lineEdit_arrival5);
        QWidget::setTabOrder(lineEdit_arrival5, lineEdit_burst5);
        QWidget::setTabOrder(lineEdit_burst5, PB_next);
        QWidget::setTabOrder(PB_next, PB_finish);

        retranslateUi(preemptive);

        QMetaObject::connectSlotsByName(preemptive);
    } // setupUi

    void retranslateUi(QDialog *preemptive)
    {
        preemptive->setWindowTitle(QCoreApplication::translate("preemptive", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("preemptive", "process name", nullptr));
        label_2->setText(QCoreApplication::translate("preemptive", "arrival time", nullptr));
        PB_next->setText(QCoreApplication::translate("preemptive", "next", nullptr));
        PB_finish->setText(QCoreApplication::translate("preemptive", "finish", nullptr));
        label_3->setText(QCoreApplication::translate("preemptive", "burst time", nullptr));
    } // retranslateUi

};

namespace Ui {
    class preemptive: public Ui_preemptive {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREEMPTIVE_H
