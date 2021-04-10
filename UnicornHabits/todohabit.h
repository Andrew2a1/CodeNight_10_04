#pragma once
#ifndef TODOHABIT_H
#define TODOHABIT_H

#include "habit.h"
#include <QDateTime>

 class TodoHabit final : public Habit
{
private:
QDateTime time;
public:
    TodoHabit()=delete;
    TodoHabit(std::string _description,std::string _name,std::string _repeatPeriod,QDateTime _time);
    TodoHabit(const TodoHabit&) = delete;
    TodoHabit& operator=(const TodoHabit&) = delete;
    int getValue() override final;
    ~TodoHabit() override;
    QDateTime getTime();
    void setTime(QDateTime _time);

};

#endif // TODOHABIT_H
