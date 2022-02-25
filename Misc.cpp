#include "Misc.h"
#define p pair<QString, Misc::typeEnum>

Misc::Misc()
{
    this->button = nullptr;
}

Misc Misc::createFromJsonObjectIterator(QJsonObject::iterator source)
{
    Misc item;
    item.name = source.key();
    item.toWhom = source.value().toObject()["toWhom"].toString();
    item.price = source.value().toObject()["price"].toDouble();
    item.rank = source.value().toObject()["rank"].toDouble();
    QMap<QString, Misc::typeEnum> typeDict =
    {
        p("Food", Misc::typeEnum::FOOD),
        p("Walk", Misc::typeEnum::WALK),
        p("Wash", Misc::typeEnum::WASH),
        p("Walk", Misc::typeEnum::WALK),
        p("Pet", Misc::typeEnum::PET),
        p("Sleep", Misc::typeEnum::SLEEP),
    };
    item.type = typeDict[source.value().toObject()["type"].toString()];
    auto temp_effs = source.value().toObject()["effects"].toObject();
    for(auto it = temp_effs.begin(); it != temp_effs.end(); it++)
    {
        item.effects[it.key()] = it.value().toDouble();
    }
    return item;
}
