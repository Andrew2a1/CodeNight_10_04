#ifndef HABITWIDGET_H
#define HABITWIDGET_H

#include <QWidget>
#include "habit.h"

#include <memory>

namespace Ui {
class HabitWidget;
}

class HabitWidget : public QWidget
{
    Q_OBJECT

private:
    Ui::HabitWidget *ui;
    std::shared_ptr<Habit> habit;

public:
    explicit HabitWidget(std::shared_ptr<Habit> habit,
                         QWidget *parent = nullptr);
    ~HabitWidget();

signals:
    void habitDone(std::shared_ptr<Habit> habit);

protected:
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // HABITWIDGET_H
