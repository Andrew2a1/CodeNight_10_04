#include "User.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>

User::User(const QString &name) :
    name(name)
{

}

const QString &User::getName()
{
    return name;
}

Unicorn *User::getUnicorn()
{
    return &unicorn;
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

void User::serialize() const
{
    QJsonDocument jsonDoc;
    QJsonObject json;
    QFile saveFile(this->name +".json");
    saveFile.open(QIODevice::WriteOnly);

    json["name"]=this->name;
    QJsonArray habitArray;
    for( const auto &habit : habits){
        QJsonObject habitObject;
        habit->serialize(habitObject);
        habitArray.append(habitObject);
    }
    QJsonObject unicornObject;
    this->unicorn.serialize(unicornObject);
    json["unicorn"]=unicornObject;
    json["habits"]=habitArray;
    jsonDoc.setObject(json);
    saveFile.write(jsonDoc.toJson());
    saveFile.close();
}

void User::deserialize()
{
    QFile saveFile(this->name+".json");
    if(saveFile.open(QIODevice::ReadOnly))
    {
        QJsonDocument jsonDoc = QJsonDocument::fromJson(saveFile.readAll());

<<<<<<< Updated upstream
        QJsonObject json = jsonDoc.object();
        QJsonArray array = json["habits"].toArray();

        for( const auto &item : array)
        {
            QJsonObject habitObject = item.toObject();
            habits.append(std::shared_ptr<Habit>(Habit::deserialize(habitObject)));
        }

        QJsonObject unicornObject = json["unicorn"].toObject();
        unicorn.deserialize(unicornObject);
    }
=======
}
else{}
>>>>>>> Stashed changes
}
