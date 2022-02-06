#include "animal.h"
#include <iostream>
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

Animal::Animal(QString name, QString type, size_t level, QMap<QString, size_t> chars)
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

void Animal::takeEffects(Misc source)
{
    try
    {
        for(auto it = this->chars.keys().begin(); it != this->chars.keys().end(); it++)
        {
            this->chars[*it] += source.effects[*it];
        }
    }
    catch(std::exception e)
    {
        std::cout << e.what() << std::endl;
    }
}
