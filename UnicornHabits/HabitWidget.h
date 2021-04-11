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
    bool isPressed = false;

public:
    explicit HabitWidget(std::shared_ptr<Habit> habit,
                         QWidget *parent = nullptr);
    ~HabitWidget();

    std::shared_ptr<Habit> getHabit() const;
    void refresh();

signals:
    void habitDone(std::shared_ptr<Habit> habit);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private:
    QString getHabitDescription();

};

#endif // HABITWIDGET_H
