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
