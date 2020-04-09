#ifndef INPUT_PRIORITY_NON_H
#define INPUT_PRIORITY_NON_H

#include <QDialog>

namespace Ui {
class input_priority_non;
}

class input_priority_non : public QDialog
{
    Q_OBJECT

public:
    explicit input_priority_non(QWidget *parent = nullptr);
    ~input_priority_non();

private slots:
    void on_PB_next_clicked();

    void on_PB_finish_clicked();

private:
    Ui::input_priority_non *ui;
};

#endif // INPUT_PRIORITY_NON_H
