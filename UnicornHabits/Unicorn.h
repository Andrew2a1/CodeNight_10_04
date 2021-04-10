#ifndef UNICORN_H
#define UNICORN_H

#include <QString>

class Unicorn
{
private:
    QString skin;
    QString background;
    int power = 0;

public:
    int getPower();
    void addPower(int amount);
};

#endif // UNICORN_H
