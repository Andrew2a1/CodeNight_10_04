#include "todohabit.h"

TodoHabit::TodoHabit(std::string _description,
                     std::string _name,
                     std::string _repeatPeriod,
                     QDateTime _time):
    Habit(_description, _name, _repeatPeriod, _time)
{

}

int TodoHabit::getValue(){
    return 1;
}
TodoHabit::~TodoHabit(){}

std::string TodoHabit::getDetails()
{
    return Habit::getDetails() + "\n" + getTime().toString().toStdString();
}

bool TodoHabit::hasExpired()
{
   return QDateTime::currentDateTime() >= getTime();
}
