#ifndef HABITWIDGETCONTAINER_H
#define HABITWIDGETCONTAINER_H

#include <QWidget>
#include <memory>

#include "HabitWidget.h"
#include "habit.h"

namespace Ui {
class HabitWidgetContainer;
}

class HabitWidgetContainer : public QWidget
{
    Q_OBJECT

private:
    QList<HabitWidget*> widgets;

public:
    explicit HabitWidgetContainer(QWidget *parent = nullptr);
    ~HabitWidgetContainer();

    void addHabit(std::shared_ptr<Habit> habit);
    void clear();

signals:
    void powerPointsAdded(int points);

private:
    Ui::HabitWidgetContainer *ui;
};

#endif // HABITWIDGETCONTAINER_H
