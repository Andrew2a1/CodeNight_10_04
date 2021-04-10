#include "todohabit.h"

TodoHabit::TodoHabit(std::string _description,std::string _name,std::string _repeatPeriod,QDateTime _time):Habit(_description,_name,_repeatPeriod),time(_time){

}

int TodoHabit::getValue(){
    return 1;
}
TodoHabit::~TodoHabit(){}

std::string TodoHabit::getDetails()
{
    return Habit::getDetails() + "\n" + time.toString().toStdString();
}

bool TodoHabit::hasExpired()
{
   return QDateTime::currentDateTime() >= time;
}

QDateTime TodoHabit::getTime(){
    return time;
}

void TodoHabit::setTime(QDateTime _time){
    time=_time;
}
