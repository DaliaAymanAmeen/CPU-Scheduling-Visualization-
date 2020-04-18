/********************************************************************************
** Form generated from reading UI file 'input_priority_non.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUT_PRIORITY_NON_H
#define UI_INPUT_PRIORITY_NON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_input_priority_non
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEdit_arrival_2;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *lineEdit_burst_2;
    QPushButton *PB_finish;
    QPushButton *PB_next;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *lineEdit_name_2;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QLineEdit *priority;

    void setupUi(QDialog *input_priority_non)
    {
        if (input_priority_non->objectName().isEmpty())
            input_priority_non->setObjectName(QString::fromUtf8("input_priority_non"));
        input_priority_non->resize(769, 544);
        layoutWidget = new QWidget(input_priority_non);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 70, 161, 31));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        lineEdit_arrival_2 = new QLineEdit(layoutWidget);
        lineEdit_arrival_2->setObjectName(QString::fromUtf8("lineEdit_arrival_2"));

        horizontalLayout_4->addWidget(lineEdit_arrival_2);

        layoutWidget_2 = new QWidget(input_priority_non);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(30, 110, 161, 51));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);

        lineEdit_burst_2 = new QLineEdit(layoutWidget_2);
        lineEdit_burst_2->setObjectName(QString::fromUtf8("lineEdit_burst_2"));

        horizontalLayout_5->addWidget(lineEdit_burst_2);

        PB_finish = new QPushButton(input_priority_non);
        PB_finish->setObjectName(QString::fromUtf8("PB_finish"));
        PB_finish->setGeometry(QRect(390, 230, 75, 23));
        PB_next = new QPushButton(input_priority_non);
        PB_next->setObjectName(QString::fromUtf8("PB_next"));
        PB_next->setGeometry(QRect(270, 230, 75, 23));
        layoutWidget_3 = new QWidget(input_priority_non);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(30, 30, 161, 31));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_6->addWidget(label_6);

        lineEdit_name_2 = new QLineEdit(layoutWidget_3);
        lineEdit_name_2->setObjectName(QString::fromUtf8("lineEdit_name_2"));

        horizontalLayout_6->addWidget(lineEdit_name_2);

        layoutWidget_4 = new QWidget(input_priority_non);
        layoutWidget_4->setObjectName(QString::fromUtf8("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(30, 180, 161, 51));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_7->addWidget(label_7);

        priority = new QLineEdit(layoutWidget_4);
        priority->setObjectName(QString::fromUtf8("priority"));

        horizontalLayout_7->addWidget(priority);

        QWidget::setTabOrder(PB_next, PB_finish);
        QWidget::setTabOrder(PB_finish, lineEdit_name_2);
        QWidget::setTabOrder(lineEdit_name_2, lineEdit_arrival_2);
        QWidget::setTabOrder(lineEdit_arrival_2, lineEdit_burst_2);
        QWidget::setTabOrder(lineEdit_burst_2, priority);

        retranslateUi(input_priority_non);

        QMetaObject::connectSlotsByName(input_priority_non);
    } // setupUi

    void retranslateUi(QDialog *input_priority_non)
    {
        input_priority_non->setWindowTitle(QCoreApplication::translate("input_priority_non", "Dialog", nullptr));
        label_4->setText(QCoreApplication::translate("input_priority_non", "arrival time", nullptr));
        label_5->setText(QCoreApplication::translate("input_priority_non", "burst time", nullptr));
        PB_finish->setText(QCoreApplication::translate("input_priority_non", "finish", nullptr));
        PB_next->setText(QCoreApplication::translate("input_priority_non", "next", nullptr));
        label_6->setText(QCoreApplication::translate("input_priority_non", "process name", nullptr));
        label_7->setText(QCoreApplication::translate("input_priority_non", "priority", nullptr));
    } // retranslateUi

};

namespace Ui {
    class input_priority_non: public Ui_input_priority_non {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUT_PRIORITY_NON_H
