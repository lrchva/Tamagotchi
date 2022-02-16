#include "animal.h"
#include <iostream>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
Animal::Animal()
{
    name = type = "UNDEFINED";
    level = 0;
    chars["hunger_current"] = 0;
    chars["hunger_max"] = 0;
    chars["wash_current"] = 0;
    chars["wash_max"] = 0;
    chars["walk_current"] = 0;
    chars["walk_max"] = 0;
    chars["pet_current"] = 0;
    chars["pet_max"] = 0;
    chars["sleep_current"] = 0;
    chars["sleep_max"] = 0;
}

Animal::Animal(QString name, QString type, size_t level, QMap<QString, int> chars)
{
    this->name = name;
    this->type = type;
    this->level = level;
    try
    {
        this->chars["hunger_current"] = chars["hunger_current"];
        this->chars["hunger_max"] = chars["hunger_max"];
        this->chars["wash_current"] = chars["wash_current"];
        this->chars["wash_max"] = chars["wash_max"];
        this->chars["walk_current"] = chars["walk_current"];
        this->chars["walk_max"] = chars["walk_max"];
        this->chars["pet_current"] = chars["pet_current"];
        this->chars["pet_max"] = chars["pet_max"];
        this->chars["sleep_current"] = chars["sleep_current"];
        this->chars["sleep_max"] = chars["sleep_max"];
        if(this->chars.size() != chars.size()) throw std::exception();
    }
    catch(std::exception e)
    {
        std::cout << e.what() << std::endl;
    }
}

QVector<Animal> Animal::storage = QVector<Animal>();

void Animal::loadFromJson(QString path)
{
    QString val;
    QFile fin(path);
    if(!fin.open(QIODevice::ReadOnly | QIODevice::Text)) return;
    val = fin.readAll();
    fin.close();

    QJsonDocument doc = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject json = doc.object();

    for(auto it = json.begin(); it != json.end(); it++)
    {
        Animal temp;
        temp.name = it.key();
        temp.type = it.value().toObject()["type"].toString();
        temp.pathToSkin = it.value().toObject()["pathToSkin"].toString();
        temp.level = it.value().toObject()["level"].toDouble();
        for(auto currentChar : temp.chars.keys())
        {
            temp.chars[currentChar] = it.value().toObject()["chars"].toObject()[currentChar].toDouble();
        }
        Animal::storage.push_back(temp);
    }
}

void Animal::takeEffects(Misc source)
{
    try
    {
        for(auto it = source.effects.keys().begin(); it != source.effects.keys().end(); it++)
        {
            this->chars[*it] += source.effects[*it];
        }
    }
    catch(std::exception e)
    {
        std::cout << e.what() << std::endl;
    }
}
