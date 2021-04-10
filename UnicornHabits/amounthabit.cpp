#include "amounthabit.h"


AmountHabit::AmountHabit(std::string _description,std::string _name,std::string _repeatPeriod,int _amount,HabitType _habitType):Habit(_description,_name,_repeatPeriod),amount(_amount),habitType(_habitType){

}
AmountHabit::~AmountHabit(){}


int AmountHabit:: getAmount(){
    return amount;
}
void AmountHabit::setAmount(int _amount){
amount=_amount;
}
AmountHabit::HabitType AmountHabit::getHabitType(){
    return habitType;
}
void  AmountHabit::setHabitType(HabitType _habitType)
{
    habitType=_habitType;
}
int AmountHabit::getValue(){
    return 1;
}
