#pragma once
#ifndef HABIT_H
#define HABIT_H

#include <QString>
#include <QDateTime>
#include <QJsonObject>

enum class RepeatPeriod
{
    None,
    Everyday,
    Everyweek
};

enum class AmountUnit
{
    None,
    Hours,
    Kcals,
    Steps,
    Liters
};

class Habit
{
private:
    QString name;

    QDateTime deadline;
    RepeatPeriod repeatPeriod = RepeatPeriod::None;

    float amount;
    float defaultAmount;

    AmountUnit units = AmountUnit::None;

public:
    Habit()=delete;

    Habit(QString _name,
          QDateTime _deadline,
          float defaultAmount = 0.0f);

    Habit(const Habit&) = delete;
    Habit& operator=(const Habit&) = delete;

    virtual ~Habit() = default;
    int getValue();
    bool hasExpired();

    void setAmount(float amount);
    float getAmount();

    void setUnits(AmountUnit units);

    void resetAmount();

    void setAmountUnit(AmountUnit units);
    AmountUnit getAmountUnit();

    QString getDescription();
    QString getName() const;
    RepeatPeriod getRepeatPeriod();

    void setDescription(QString _description);
    void setName(QString _name);
    void setRepeatPeriod(RepeatPeriod _repeatPeriod);

    QDateTime getDeadline();
    void setDeadline(QDateTime _time);

    void serialize(QJsonObject &json) const;
    static Habit *deserialize(QJsonObject &habitObject);
};

#endif // HABIT_H
