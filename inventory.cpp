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
        temp.item = new Misc;
        temp.item->name = it.key();
        temp.item->toWhom = it.value().toObject()["toWhom"].toString();
        temp.item->price = it.value().toObject()["price"].toDouble();
        temp.item->restoringPower = it.value().toObject()["restoringPower"].toDouble();
        temp.item->rank = it.value().toObject()["rank"].toDouble();
        QMap<QString, Misc::typeEnum> typeDict =
        {
            p("Food", Misc::typeEnum::FOOD),
            p("Walk", Misc::typeEnum::WALK),
            p("Wash", Misc::typeEnum::WASH),
            p("Walk", Misc::typeEnum::WALK),
            p("Pet", Misc::typeEnum::PET),
            p("Sleep", Misc::typeEnum::SLEEP),
        };
        temp.item->type = typeDict[it.value().toObject()["type"].toString()];
        this->storage.push_back(temp);
    }
    return json.size() == this->storage.size();
}
