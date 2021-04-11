#ifndef HABITFINISHEDDIALOG_H
#define HABITFINISHEDDIALOG_H

#include <QDialog>

namespace Ui {
class HabitFinishedDialog;
}

class HabitFinishedDialog : public QDialog
{
    Q_OBJECT

private:
    Ui::HabitFinishedDialog *ui;

public:
    explicit HabitFinishedDialog(QWidget *parent = nullptr);
    ~HabitFinishedDialog();

    void setName(const QString &name);
    void setDeadline(const QString &deadline);
    void setPeriod(const QString &period);
    void setAmount(const QString &amount);
};

#endif // HABITFINISHEDDIALOG_H
