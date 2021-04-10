#include "amounthabit.h"


AmountHabit::AmountHabit(std::string _description,
                         std::string _name,
                         std::string _repeatPeriod,
                         QDateTime _time,
                         int _amount,HabitType _habitType):
    Habit(_description,_name,_repeatPeriod, _time),
    amount(_amount),
    habitType(_habitType)
{

}

std::string AmountHabit::getDetails()
{
    return Habit::getDetails() + "\n" + "amount: " + std::to_string(amount);
}

AmountHabit::~AmountHabit(){}


int AmountHabit:: getAmount(){
    return amount;
}
void AmountHabit::setAmount(int _amount){
amount=_amount;
}

HabitType AmountHabit::getHabitType(){
    return habitType;
}
void  AmountHabit::setHabitType(HabitType _habitType)
{
    habitType=_habitType;
}
int AmountHabit::getValue(){
    return 1;
}
