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

void Habit::setUnits(AmountUnit units)
{
    this->units = units;
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

void Habit::Habit::serialize(QJsonObject &json) const
{
    json["name"] = this->name;
    json["deadline"] = this->deadline.toString();
    json["defaultAmount"] = this->defaultAmount;
    json["amount"] = this->amount;

    json["repeatPeriod"] = (int)this->repeatPeriod;
    json["units"] = (int)this->units;
}

Habit *Habit::deserialize(QJsonObject &habitObject)
{
    QString habitName = habitObject["name"].toString();
    QDateTime deadline = QDateTime::fromString(habitObject["deadline"].toString());
    float defaultAmount = habitObject["defaultAmount"].toDouble(0);
    float amount = habitObject["amount"].toDouble(0);

    RepeatPeriod period = (RepeatPeriod)habitObject["repeatPeriod"].toInt();
    AmountUnit units = (AmountUnit)habitObject["units"].toInt();

    Habit *habit = new Habit(habitName, deadline, defaultAmount);
    habit->setAmount(amount);
    habit->setRepeatPeriod(period);
    habit->setUnits(units);

    return habit;
}

