#pragma once
#ifndef HABIT_H
#define HABIT_H
#include <string>

class Habit
{
private:
    std::string description;
    std::string name;
    std::string repeatPeriod;
public:
    Habit()=delete;

    Habit(std::string _description,
          std::string _name,
          std::string _repeatPeriod);

    Habit(const Habit&) = delete;
    Habit& operator=(const Habit&) = delete;

    virtual ~Habit();
    virtual int getValue() = 0;
    virtual std::string getDetails();
    virtual bool hasExpired();

    std::string getDescription();
    std::string getName() const;
    std::string getRepeatPeriod();

    void setDescription(std::string _description);
    void setName(std::string _name);
    void setRepeatPeriod(std::string _repeatPeriod);
};

#endif // HABIT_H
