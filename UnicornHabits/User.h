#ifndef USER_H
#define USER_H

#include <QString>
#include <QList>

#include <memory>

#include "Unicorn.h"
#include "habit.h"

class User
{
private:
    QString name;
    Unicorn unicorn;
    QList<std::shared_ptr<Habit>> habits;

public:
    User(const QString &name);
    const QString &getName();

    void addHabit(std::shared_ptr<Habit> habit);
    void removeHabit(std::shared_ptr<Habit> habit);
    const QList<std::shared_ptr<Habit> > &getHabits() const;
};

#endif // USER_H
