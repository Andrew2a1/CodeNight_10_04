#ifndef MAINAPPWIDGET_H
#define MAINAPPWIDGET_H

#include <QWidget>
#include "User.h"
#include "habit.h"

class MainWindow;

namespace Ui {
class MainAppWidget;
}

class MainAppWidget : public QWidget
{
    Q_OBJECT

private:
    Ui::MainAppWidget *ui;
    User *user = nullptr;

public:
    explicit MainAppWidget(QWidget *parent = nullptr);
    ~MainAppWidget();

    void setUser(User *user);
    void addHabit(std::shared_ptr<Habit> habit);

public slots:
    void updateHabits();
    void addPowerPoints(int points);

signals:
    void btnAddHabitPressed();

private slots:
    void on_addHabitBtn_clicked();

};

#endif // MAINAPPWIDGET_H
