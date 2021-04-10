#ifndef USER_H
#define USER_H

#include <QString>
#include "Unicorn.h"

class User
{
private:
    QString name;
    Unicorn unicorn;

public:
    User(const QString &name);
    const QString &getName();
};

#endif // USER_H
