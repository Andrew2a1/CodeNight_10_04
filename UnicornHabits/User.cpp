#include "User.h"

User::User(const QString &name) :
    name(name)
{

}

const QString &User::getName()
{
    return name;
}

void User::addHabit(std::shared_ptr<Habit> habit)
{
    habits.append(habit);
}

void User::removeHabit(std::shared_ptr<Habit> habit)
{
    habits.removeOne(habit);
}

const QList<std::shared_ptr<Habit> > &User::getHabits() const
{
    return habits;
}
