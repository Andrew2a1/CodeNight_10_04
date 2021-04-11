#include "Unicorn.h"

int Unicorn::getPower()
{
    return power;
}

void Unicorn::addPower(int amount)
{
    power += amount;
}

void Unicorn::serialize(QJsonObject &json) const
{
    json["power"]=this->power;
    json["skin"]=this->skin;
    json["background"]=this->background;
}

void Unicorn::deserialize(QJsonObject &json)
{
    power = json["power"].toInt();
    skin = json["skin"].toString();
    background = json["background"].toString();
}



