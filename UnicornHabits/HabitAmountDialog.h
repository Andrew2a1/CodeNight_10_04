#ifndef HABITAMOUNTDIALOG_H
#define HABITAMOUNTDIALOG_H

#include <QDialog>

namespace Ui {
class HabitAmountDialog;
}

class HabitAmountDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HabitAmountDialog(QWidget *parent = nullptr);
    ~HabitAmountDialog();

    float getAmountDone();

    void setName(const QString &name);
    void setDeadline(const QString &deadline);
    void setPeriod(const QString &period);
    void setAmount(const QString &amount);

private:
    Ui::HabitAmountDialog *ui;
};

#endif // HABITAMOUNTDIALOG_H
