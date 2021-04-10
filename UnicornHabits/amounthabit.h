#pragma once
#ifndef AMOUNTHABIT_H
#define AMOUNTHABIT_H

#include "habit.h"

enum class HabitType{
    Time,
    Calories,
    Volume
};

class AmountHabit final : public Habit
{
private:
    int amount;
    HabitType habitType;

public:
    AmountHabit()=delete;
    AmountHabit(std::string _description,std::string _name,std::string _repeatPeriod,int _amount,HabitType _habitType);
    ~AmountHabit() override;

    AmountHabit(const AmountHabit&) = delete;
    AmountHabit& operator=(const AmountHabit&) = delete;
    virtual std::string getDetails() override;

    int getValue() override final;
    int getAmount();
    void setAmount(int);
    HabitType getHabitType();
    void setHabitType(HabitType);
};

#endif // AMOUNTHABIT_H
