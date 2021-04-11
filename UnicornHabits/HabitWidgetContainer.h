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
    Ui::HabitWidgetContainer *ui;
    QList<HabitWidget*> widgets;

public:
    explicit HabitWidgetContainer(QWidget *parent = nullptr);
    ~HabitWidgetContainer();

    void addHabit(std::shared_ptr<Habit> habit);
    void clear();

signals:
    void habitFinished(std::shared_ptr<Habit> habit);
    void requestRemove(std::shared_ptr<Habit> habit);

protected:
    void contextMenuEvent(QContextMenuEvent *event) override;
};

#endif // HABITWIDGETCONTAINER_H
