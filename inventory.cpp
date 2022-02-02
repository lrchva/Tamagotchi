#include "inventory.h"
#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <QMessageBox>

bool Inventory::fillFromJson(QString path)
{
    QString val;
    QFile fin(path);
    if(!fin.open(QIODevice::ReadOnly | QIODevice::Text)) return false;
    val = fin.readAll();
    fin.close();

    QJsonDocument doc = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject json = doc.object();

    try
    {
        for(auto it = json.begin(); it != json.end(); it++)
        {
            int jhbygvuj = 7;
            if(it.value().toObject()["type"] == "food")
            {
                Food temp;
                temp.name = it.key();
                temp.price = it.value().toObject()["price"].toDouble();
                temp.restoringPower = it.value().toObject()["restoringPower"].toDouble();
                temp.pathToSkin = it.value().toObject()["pathToSkin"].toString();
                temp.rank = it.value().toObject()["rank"].toDouble();
                temp.type = "food";

                QString toWhom_s = it.value().toObject()["toWhom"].toString();
                if(toWhom_s == "Rabbit") temp.toWhom = Misc::toWhomEnum::RABBIT;
                if(toWhom_s == "Cat") temp.toWhom = Misc::toWhomEnum::CAT;
                if(toWhom_s == "Dog") temp.toWhom = Misc::toWhomEnum::DOG;
                if(toWhom_s == "Hamster") temp.toWhom = Misc::toWhomEnum::HAMSTER;
                if(toWhom_s == "Minipig") temp.toWhom = Misc::toWhomEnum::MINIPIG;

                this->food_storage[temp.name] = QPair<Food, size_t>(temp, it.value().toObject()["count"].toDouble());
            }
            else if(it.value().toObject()["type"] == "sleepMisc")
            {
                SleepMisc temp;
                temp.name = it.key();
                temp.price = it.value().toObject()["price"].toDouble();
                temp.restoringPower = it.value().toObject()["restoringPower"].toDouble();
                temp.pathToSkin = it.value().toObject()["pathToSkin"].toString();
                temp.rank = it.value().toObject()["rank"].toDouble();
                temp.type = "sleepMisc";

                QString toWhom_s = it.value().toObject()["toWhom"].toString();
                if(toWhom_s == "Rabbit") temp.toWhom = Misc::toWhomEnum::RABBIT;
                if(toWhom_s == "Cat") temp.toWhom = Misc::toWhomEnum::CAT;
                if(toWhom_s == "Dog") temp.toWhom = Misc::toWhomEnum::DOG;
                if(toWhom_s == "Hamster") temp.toWhom = Misc::toWhomEnum::HAMSTER;
                if(toWhom_s == "Minipig") temp.toWhom = Misc::toWhomEnum::MINIPIG;

                this->sleepMisc_storage[temp.name] = QPair<SleepMisc, size_t>(temp, it.value().toObject()["count"].toDouble());
            }
            else if(it.value().toObject()["type"] == "walkMisc")
            {
                WalkMisc temp;
                temp.name = it.key();
                temp.price = it.value().toObject()["price"].toDouble();
                temp.restoringPower = it.value().toObject()["restoringPower"].toDouble();
                temp.pathToSkin = it.value().toObject()["pathToSkin"].toString();
                temp.rank = it.value().toObject()["rank"].toDouble();
                temp.type = "walkMisc";

                QString toWhom_s = it.value().toObject()["toWhom"].toString();
                if(toWhom_s == "Rabbit") temp.toWhom = Misc::toWhomEnum::RABBIT;
                if(toWhom_s == "Cat") temp.toWhom = Misc::toWhomEnum::CAT;
                if(toWhom_s == "Dog") temp.toWhom = Misc::toWhomEnum::DOG;
                if(toWhom_s == "Hamster") temp.toWhom = Misc::toWhomEnum::HAMSTER;
                if(toWhom_s == "Minipig") temp.toWhom = Misc::toWhomEnum::MINIPIG;

                this->walkMisc_storage[temp.name] = QPair<WalkMisc, size_t>(temp, it.value().toObject()["count"].toDouble());
            }
            else if(it.value().toObject()["type"] == "washMisc")
        {
            WashMisc temp;
            temp.name = it.key();
            temp.price = it.value().toObject()["price"].toDouble();
            temp.restoringPower = it.value().toObject()["restoringPower"].toDouble();
            temp.pathToSkin = it.value().toObject()["pathToSkin"].toString();
            temp.rank = it.value().toObject()["rank"].toDouble();
            temp.type = "washMisc";

            QString toWhom_s = it.value().toObject()["toWhom"].toString();
            if(toWhom_s == "Rabbit") temp.toWhom = Misc::toWhomEnum::RABBIT;
            if(toWhom_s == "Cat") temp.toWhom = Misc::toWhomEnum::CAT;
            if(toWhom_s == "Dog") temp.toWhom = Misc::toWhomEnum::DOG;
            if(toWhom_s == "Hamster") temp.toWhom = Misc::toWhomEnum::HAMSTER;
            if(toWhom_s == "Minipig") temp.toWhom = Misc::toWhomEnum::MINIPIG;

            this->washMisc_storage[temp.name] = QPair<WashMisc, size_t>(temp, it.value().toObject()["count"].toDouble());
        }
            else if(it.value().toObject()["type"] == "petMisc")
        {
            PetMisc temp;
            temp.name = it.key();
            temp.price = it.value().toObject()["price"].toDouble();
            temp.restoringPower = it.value().toObject()["restoringPower"].toDouble();
            temp.pathToSkin = it.value().toObject()["pathToSkin"].toString();
            temp.rank = it.value().toObject()["rank"].toDouble();
            temp.type = "petMisc";

            QString toWhom_s = it.value().toObject()["toWhom"].toString();
            if(toWhom_s == "Rabbit") temp.toWhom = Misc::toWhomEnum::RABBIT;
            if(toWhom_s == "Cat") temp.toWhom = Misc::toWhomEnum::CAT;
            if(toWhom_s == "Dog") temp.toWhom = Misc::toWhomEnum::DOG;
            if(toWhom_s == "Hamster") temp.toWhom = Misc::toWhomEnum::HAMSTER;
            if(toWhom_s == "Minipig") temp.toWhom = Misc::toWhomEnum::MINIPIG;

            this->petMisc_storage[temp.name] = QPair<PetMisc, size_t>(temp, it.value().toObject()["count"].toDouble());
        }
        }
    }
    catch(exception e)
    {
        QMessageBox mb;
        mb.setText(e.what());
        mb.setIcon(QMessageBox::Critical);
        mb.exec();
        return false;
    }
    return true;
}

Food Inventory::atFood(QString itemName)
{
    auto temp = this->food_storage.find(itemName);
    if(temp == this->food_storage.end()) return Food();
    return temp->first;
}
Food Inventory::atFood(size_t itemIndex)
{
    auto it = this->food_storage.begin();
    for(size_t i = 0; i < itemIndex && i < food_storage.size(); i++)
    {
        it++;
    }
    return it->first;
}
WashMisc Inventory::atWashMisc(QString itemName)
{
    auto temp = this->washMisc_storage.find(itemName);
    if(temp == this->washMisc_storage.end()) return WashMisc();
    return temp->first;
}
WashMisc Inventory::atWashMisc(size_t itemIndex)
{
    auto it = this->washMisc_storage.begin();
    for(size_t i = 0; i < itemIndex && i < washMisc_storage.size(); i++)
    {
        it++;
    }
    return it->first;
}
WalkMisc Inventory::atWalkMisc(QString itemName)
{
    auto temp = this->walkMisc_storage.find(itemName);
    if(temp == this->walkMisc_storage.end()) return WalkMisc();
    return temp->first;
}
PetMisc Inventory::atPetMisc(QString itemName)
{
    auto temp = this->petMisc_storage.find(itemName);
    if(temp == this->petMisc_storage.end()) return PetMisc();
    return temp->first;
}
SleepMisc Inventory::atSleepMisc(QString itemName)
{
    auto temp = this->sleepMisc_storage.find(itemName);
    if(temp == this->sleepMisc_storage.end()) return SleepMisc();
    return temp->first;
}

bool Inventory::contains(QString itemName)
{
    if(atFood(itemName).name != "") return true;
    if(atWashMisc(itemName).name != "") return true;
    if(atWalkMisc(itemName).name != "") return true;
    if(atPetMisc(itemName).name != "") return true;
    if(atSleepMisc(itemName).name != "") return true;
    return false;
}

bool Inventory::addItem(const Misc& item, size_t count)
{
    if(item.type == "food")
    {
        if(this->contains(item.name)) this->food_storage[item.name].second += count;
        else
        {
            this->food_storage[item.name] = QPair<Food, size_t>(Food(item), count);
            return true;
        }
    }
    else if(item.type == "sleepMisc")
    {
        if(this->contains(item.name)) this->sleepMisc_storage[item.name].second += count;
        else
        {
            this->sleepMisc_storage[item.name] = QPair<SleepMisc, size_t>(SleepMisc(item), count);
            return true;
        }
    }
    else if(item.type == "walkMisc")
    {
        if(this->contains(item.name)) this->walkMisc_storage[item.name].second += count;
        else
        {
            this->walkMisc_storage[item.name] = QPair<WalkMisc, size_t>(WalkMisc(item), count);
            return true;
        }
    }
    else if(item.type == "washMisc")
    {
        if(this->contains(item.name)) this->washMisc_storage[item.name].second += count;
        else
        {
            this->washMisc_storage[item.name] = QPair<WashMisc, size_t>(WashMisc(item), count);
            return true;
        }
    }
    else if(item.type == "petMisc")
    {
        if(this->contains(item.name)) this->petMisc_storage[item.name].second += count;
        else
        {
            this->petMisc_storage[item.name] = QPair<PetMisc, size_t>(PetMisc(item), count);
            return true;
        }
    }
    //TODO: Add other misc types
    return false;
}

bool Inventory::removeItem(QString itemName, size_t count)
{
    if(contains(itemName))
    {
        if(food_storage.find(itemName) != food_storage.end())
        {
            if(food_storage.find(itemName)->second <= count)
            {
                food_storage.erase(food_storage.find(itemName));
            }
            else
            {
                food_storage.find(itemName)->second -= count;
            }
        }
        if(sleepMisc_storage.find(itemName) != sleepMisc_storage.end())
        {
            if(sleepMisc_storage.find(itemName)->second <= count)
            {
                sleepMisc_storage.erase(sleepMisc_storage.find(itemName));
            }
            else
            {
                sleepMisc_storage.find(itemName)->second -= count;
            }
        }
        if(walkMisc_storage.find(itemName) != walkMisc_storage.end())
        {
            if(walkMisc_storage.find(itemName)->second <= count)
            {
                walkMisc_storage.erase(walkMisc_storage.find(itemName));
            }
            else
            {
                walkMisc_storage.find(itemName)->second -= count;
            }
        }
        if(washMisc_storage.find(itemName) != washMisc_storage.end())
        {
            if(washMisc_storage.find(itemName)->second <= count)
            {
                washMisc_storage.erase(washMisc_storage.find(itemName));
            }
            else
            {
                washMisc_storage.find(itemName)->second -= count;
            }
        }
        if(petMisc_storage.find(itemName) != petMisc_storage.end())
        {
            if(petMisc_storage.find(itemName)->second <= count)
            {
                petMisc_storage.erase(petMisc_storage.find(itemName));
            }
            else
            {
                petMisc_storage.find(itemName)->second -= count;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}

size_t Inventory::foodSize()
{
    return this->food_storage.size();
}

size_t Inventory::washMiscSize()
{
    return this->washMisc_storage.size();
}


size_t Inventory::size()
{
    return
    (
                this->food_storage.size() +
                this->petMisc_storage.size() +
                this->walkMisc_storage.size() +
                this->washMisc_storage.size() +
                this->sleepMisc_storage.size()
    );
}
