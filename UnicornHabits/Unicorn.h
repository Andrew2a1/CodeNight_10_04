#ifndef UNICORN_H
#define UNICORN_H

#include <QString>
#include <QJsonObject>
class Unicorn
{
private:
    QString skin;
    QString background;
    int power = 0;

public:
    int getPower();
    void addPower(int amount);

    void serialize(QJsonObject &json) const;
    void deserialize(QJsonObject &json);
};

#endif // UNICORN_H
