#include "habit.h"

Habit::Habit(std::string _description,
             std::string _name,
             std::string _repeatPeriod,
             QDateTime _time):
    description(_description),
    name(_name),
    repeatPeriod(_repeatPeriod),
    time(_time)
{

};

Habit::~Habit(){

}

std::string Habit::getDetails()
{
    return name + ": " + description + "\n" + getTime().toString().toStdString();
}

bool Habit::hasExpired()
{
    return QDateTime::currentDateTime() >= getTime();
}

std::string Habit::getDescription(){
    return description;
}
std::string Habit::getName() const {
    return name;
}
std::string Habit::getRepeatPeriod(){
    return repeatPeriod;
}
void Habit::setDescription(std::string _description){
    description=_description;
}
void Habit::setName(std::string _name){
    name=_name;

}
void Habit::setRepeatPeriod(std::string _repeatPeriod){
    repeatPeriod=_repeatPeriod;
}

QDateTime Habit::getTime(){
    return time;
}

void Habit::setTime(QDateTime _time){
    time=_time;
}

