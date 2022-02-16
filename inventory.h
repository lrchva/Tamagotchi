#ifndef INVENTORY_H
#define INVENTORY_H
#include <QVector>
#include "Misc.h"

class Inventory
{
public:
    Inventory();
    class Slot
    {
    public:
        QString pathToSkin;
        Misc* item;
        size_t count;
    };
private:
    QVector<Slot> storage;
public:
    bool loadFromJson(QString path = "Inventory.json");
    bool saveToJson(QString path = "Inventory.json");
    Slot& operator[](size_t index);
    Slot& operator[](QString name);
    void addItem(Misc a, size_t count);
    void removeItem(size_t index, size_t count);
    void removeItem(QString name, size_t count);
    size_t size(QString type);
};

#endif // INVENTORY_H
