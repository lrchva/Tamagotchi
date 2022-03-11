#include "inventory.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMap>

#define p pair<QString, Misc::typeEnum>

Inventory::Inventory(QString annotation)
{
   Inventory::existingOnes[annotation] = this;
}
QMap<QString, Inventory*> Inventory::existingOnes = QMap<QString, Inventory*>();
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

bool Inventory::saveToJson(QString path)
{
    QJsonObject json;
    for(auto it = this->storage.begin(); it != this->storage.end(); it++)
    {
        QString type;
        switch(it->item->type)
        {
        case 0: type = "Food"; break;
        case 1: type = "Wash"; break;
        case 2: type = "Walk"; break;
        case 3: type = "Pet"; break;
        case 4: type = "Sleep"; break;
        default: type = "Unknown"; break;
        }

        QJsonObject curSlot;
        curSlot.insert("type", type);
        curSlot.insert("price", QJsonValue::fromVariant(it->item->price));
        curSlot.insert("pathToSkin", it->pathToSkin);
        curSlot.insert("rank", QJsonValue::fromVariant(it->item->rank));
        curSlot.insert("toWhom", it->item->toWhom);
        curSlot.insert("count", QJsonValue::fromVariant(it->count));
        QJsonObject effs;
        effs.insert("hunger_current", QJsonValue::fromVariant(it->item->effects["hunger_current"]));
        effs.insert("wash_current", QJsonValue::fromVariant(it->item->effects["wash_current"]));
        effs.insert("walk_current", QJsonValue::fromVariant(it->item->effects["walk_current"]));
        effs.insert("pet_current", QJsonValue::fromVariant(it->item->effects["pet_current"]));
        effs.insert("sleep_current", QJsonValue::fromVariant(it->item->effects["sleep_current"]));
        curSlot.insert("effects", effs);

        json.insert(it->item->name, curSlot);
    }
    QJsonDocument doc(json);
    QFile fout(path);
    if(!fout.open(QIODevice::WriteOnly | QIODevice::Text)) return false;
    fout.write(doc.toJson());
    fout.close();
    return true;
}

Inventory::Slot& Inventory::operator[](size_t index)
{

    if(index > storage.size())
    {
        Slot* temp = new Slot();
        return *temp;
    }
    return storage[index];
}
Inventory::Slot& Inventory::operator[](QString name)
{
    for(int i = 0; i < storage.size(); i++)
    {
        if(storage[i].item->name == name)
        {
            return storage[i];
        }
    }
    throw std::exception();
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

void Inventory::addItem(Misc a, size_t count, QString pathToSkin)
{
    Slot temp;
    temp.item = new Misc(a);
    temp.pathToSkin = pathToSkin;
    try
    {
        (*this)[a.name].count += count;
    }
    catch(std::exception e)
    {
        temp.count = count;
        this->storage.push_back(temp);
    }
}

void Inventory::removeItem(size_t index, size_t count)
{
    if(index >= this->storage.size()) throw std::exception();
    if((*this)[index].count >= count)
    {
        if((*this)[index].count > count)
        {
           (*this)[index].count -= count;
        }
        else
        {
            auto it = this->storage.begin();
            int i = 0;
            while(it != this->storage.end() && i != index)
            {
                i++;
                it++;
            }
            this->storage.erase(it);
        }
    }
    else throw std::exception();
}

void Inventory::removeItem(QString name, size_t count)
{
    int index = -1;
    for(int i = 0; i < storage.size(); i++)
    {
        if(storage[i].item->name == name)
        {
            index = i;
        }
    }
    if (index == -1) throw std::exception();
    if(index >= this->storage.size()) throw std::exception();
    if((*this)[index].count >= count)
    {
        if((*this)[index].count > count)
        {
           (*this)[index].count -= count;
        }
        else
        {
            auto it = this->storage.begin();
            int i = 0;
            while(it != this->storage.end() && i != index)
            {
                i++;
                it++;
            }
            this->storage.erase(it);
        }
    }
    else throw std::exception();
}
