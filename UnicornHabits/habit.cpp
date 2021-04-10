#include "habit.h"

Habit::Habit(QString _name,
             QDateTime _deadline,
             float defaultAmount):
    name(_name),
    deadline(_deadline),
    defaultAmount(defaultAmount)
{

}

int Habit::getValue()
{
    return 1;
}

bool Habit::hasExpired()
{
    return QDateTime::currentDateTime() >= getDeadline();
}

void Habit::setAmount(float amount)
{
    this->amount = amount;
}

float Habit::getAmount()
{
    return amount;
}

void Habit::resetAmount()
{
    amount = defaultAmount;
}

void Habit::setAmountUnit(AmountUnit units)
{
    this->units = units;
}

AmountUnit Habit::getAmountUnit()
{
    return units;
}

QString Habit::getName() const {
    return name;
}

RepeatPeriod Habit::getRepeatPeriod(){
    return repeatPeriod;
}

void Habit::setName(QString _name){
    name=_name;

}
void Habit::setRepeatPeriod(RepeatPeriod _repeatPeriod){
    repeatPeriod=_repeatPeriod;
}

QDateTime Habit::getDeadline(){
    return deadline;
}

void Habit::setDeadline(QDateTime _time){
    deadline=_time;
}

