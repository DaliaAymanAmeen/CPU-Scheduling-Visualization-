/********************************************************************************
** Form generated from reading UI file 'output.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OUTPUT_H
#define UI_OUTPUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_output
{
public:

    void setupUi(QDialog *output)
    {
        if (output->objectName().isEmpty())
            output->setObjectName(QString::fromUtf8("output"));
        output->resize(769, 544);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(194, 195, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        output->setPalette(palette);

        retranslateUi(output);

        QMetaObject::connectSlotsByName(output);
    } // setupUi

    void retranslateUi(QDialog *output)
    {
        output->setWindowTitle(QCoreApplication::translate("output", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class output: public Ui_output {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OUTPUT_H
