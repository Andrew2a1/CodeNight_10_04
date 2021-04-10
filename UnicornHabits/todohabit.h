#pragma once
#ifndef TODOHABIT_H
#define TODOHABIT_H

#include "habit.h"
#include <QDateTime>

class TodoHabit final : public Habit
{

public:
    TodoHabit()=delete;
    TodoHabit(std::string _description,
              std::string _name,
              std::string _repeatPeriod,
              QDateTime _time);

    TodoHabit(const TodoHabit&) = delete;
    TodoHabit& operator=(const TodoHabit&) = delete;

    int getValue() override final;
    ~TodoHabit() override;

    virtual std::string getDetails() override;
    virtual bool hasExpired() override;

};

#endif // TODOHABIT_H
