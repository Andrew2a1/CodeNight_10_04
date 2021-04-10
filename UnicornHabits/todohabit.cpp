#include "todohabit.h"

TodoHabit::TodoHabit(std::string _description,std::string _name,std::string _repeatPeriod,QDateTime _time):Habit(_description,_name,_repeatPeriod),time(_time){

}

int TodoHabit::getValue(){
    return 1;
}
TodoHabit::~TodoHabit(){}
QDateTime TodoHabit::getTime(){
    return time;
}
void TodoHabit::setTime(QDateTime _time){
    time=_time;
}
