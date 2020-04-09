#ifndef SJF_NON_H
#define SJF_NON_H

#include <QDialog>

namespace Ui {
class SJF_non;
}

class SJF_non : public QDialog
{
    Q_OBJECT

public:
    explicit SJF_non(QWidget *parent = nullptr);
    ~SJF_non();

private slots:
    void on_PB_next_clicked();

    void on_PB_finish_clicked();

private:
    Ui::SJF_non *ui;
};

#endif // SJF_NON_H
