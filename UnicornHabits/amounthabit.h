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
    float amount;
    float defaultAmount;
    HabitType habitType;

public:
    AmountHabit()=delete;
    AmountHabit(std::string _description,
                std::string _name,
                std::string _repeatPeriod,
                QDateTime _time,
                float _amount,
                HabitType _habitType);

    ~AmountHabit() override;

    AmountHabit(const AmountHabit&) = delete;
    AmountHabit& operator=(const AmountHabit&) = delete;
    virtual std::string getDetails() override;

    int getValue() override final;

    float getAmount();
    void setAmount(float);

    void resetToDefault();

    HabitType getHabitType();
    void setHabitType(HabitType);
};

#endif // AMOUNTHABIT_H
