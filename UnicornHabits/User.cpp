#include "User.h"

User::User(const QString &name) :
    name(name)
{

}

const QString &User::getName()
{
    return name;
}
