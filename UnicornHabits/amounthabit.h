#pragma once
#ifndef AMOUNTHABIT_H
#define AMOUNTHABIT_H

#include "habit.h"


class AmountHabit final : public Habit
{
private:
    enum class HabitType{
        Time,
        Calories,
        Volume
    };
    int amount;
    HabitType habitType;
public:
    AmountHabit()=delete;
    AmountHabit(std::string _description,std::string _name,std::string _repeatPeriod,int _amount,HabitType _habitType);
    ~AmountHabit() override;
    AmountHabit(const AmountHabit&) = delete;
    AmountHabit& operator=(const AmountHabit&) = delete;
    int getValue() override final;
    int getAmount();
    void setAmount(int);
    HabitType getHabitType();
    void setHabitType(HabitType);
};

#endif // AMOUNTHABIT_H
