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
