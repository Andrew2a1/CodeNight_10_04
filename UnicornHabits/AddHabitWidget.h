#ifndef ADDHABITWIDGET_H
#define ADDHABITWIDGET_H

#include <QWidget>
#include "habit.h"

namespace Ui {
class AddHabitWidget;
}

class AddHabitWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AddHabitWidget(QWidget *parent = nullptr);
    ~AddHabitWidget();

private slots:
    void on_okBtn_clicked();

    void on_cancelBtn_clicked();

    void on_habitType_currentTextChanged(const QString &arg1);

    void on_shouldRepeat_toggled(bool checked);

signals:
    void habitCreated(Habit *habit);

private:
    Ui::AddHabitWidget *ui;
};

#endif // ADDHABITWIDGET_H
