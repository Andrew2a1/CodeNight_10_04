#ifndef HABITSERIALIZER_H
#define HABITSERIALIZER_H

#include <QByteArray>
#include "habit.h"

class HabitSerializer
{
public:
    HabitSerializer();

    QByteArray serialize(Habit *habit);
    Habit *deserialize(QByteArray data);
};

#endif // HABITSERIALIZER_H
