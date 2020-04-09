#ifndef RR_H
#define RR_H

#include <QDialog>

namespace Ui {
class rr;
}

class rr : public QDialog
{
    Q_OBJECT

public:
    explicit rr(QWidget *parent = nullptr);
    ~rr();

private slots:
    void on_PB_next_clicked();

    void on_PB_finish_clicked();

private:
    Ui::rr *ui;
};

#endif // RR_H
