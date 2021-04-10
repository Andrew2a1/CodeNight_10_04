#include "amounthabit.h"
#include <QString>

AmountHabit::AmountHabit(std::string _description,
                         std::string _name,
                         std::string _repeatPeriod,
                         QDateTime _time,
                         float _amount,
                         HabitType _habitType):
    Habit(_description,_name,_repeatPeriod, _time),
    amount(_amount),
    defaultAmount(_amount),
    habitType(_habitType)
{

}

std::string AmountHabit::getDetails()
{
    return Habit::getDetails() + "\n" +
            "amount: " + QString::number(amount).toStdString();
}

AmountHabit::~AmountHabit(){}


float AmountHabit:: getAmount(){
    return amount;
}
void AmountHabit::setAmount(float _amount){
    amount=_amount;
}

void AmountHabit::resetToDefault()
{
    amount = defaultAmount;
}

HabitType AmountHabit::getHabitType(){
    return habitType;
}
void  AmountHabit::setHabitType(HabitType _habitType)
{
    habitType=_habitType;
}

int AmountHabit::getValue()
{
    return 1;
}
