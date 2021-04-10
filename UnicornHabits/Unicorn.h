#ifndef UNICORN_H
#define UNICORN_H

#include <QString>

class Unicorn
{
private:
    QString skin;
    QString background;
    int power;

public:
    int getPower();
    void addPower(int amount);
};

#endif // UNICORN_H
