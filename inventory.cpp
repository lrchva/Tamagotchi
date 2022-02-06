#include "inventory.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMap>

#define p pair<QString, Misc::typeEnum>

Inventory::Inventory()
{

}

bool Inventory::loadFromJson(QString path)
{
    QString val;
    QFile fin(path);
    if(!fin.open(QIODevice::ReadOnly | QIODevice::Text)) return false;
    val = fin.readAll();
    fin.close();

    QJsonDocument doc = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject json = doc.object();

    for(auto it = json.begin(); it != json.end(); it++)
    {
        Slot temp;
        temp.count = it.value().toObject()["count"].toDouble();
        temp.pathToSkin = it.value().toObject()["pathToSkin"].toString();
        temp.item = new Misc(Misc::createFromJsonObjectIterator(it));
        this->storage.push_back(temp);
    }
    return json.size() == this->storage.size();
}

Inventory::Slot& Inventory::operator[](size_t index)
{

    if(index > storage.size())
    {
        auto temp = new Slot();
        return *temp;
    }
    return storage[index];
}

size_t Inventory::size(QString type)
{
    if(type == "all") return storage.size();
    QMap<Misc::typeEnum, size_t> counters;
    counters[Misc::typeEnum::FOOD] = 0;
    counters[Misc::typeEnum::WASH] = 0;
    counters[Misc::typeEnum::WALK] = 0;
    counters[Misc::typeEnum::PET] = 0;
    counters[Misc::typeEnum::SLEEP] = 0;
    for(size_t i = 0; i < storage.size(); i++)
    {
        counters[storage[i].item->type]++;
    }
    if(type == "food") return counters[Misc::typeEnum::FOOD];
    if(type == "wash") return counters[Misc::typeEnum::WASH];
    if(type == "walk") return counters[Misc::typeEnum::WALK];
    if(type == "pet") return counters[Misc::typeEnum::PET];
    if(type == "sleep") return counters[Misc::typeEnum::SLEEP];
    return 0;
}
