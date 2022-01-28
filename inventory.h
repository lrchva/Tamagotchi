#ifndef INVENTORY_H
#define INVENTORY_H
#include "Misc.h"
#include <QString>
#include <QMap>
class Inventory
{
private:
    QMap<QString, QPair<Food, size_t> > food_storage;
    QMap<QString, QPair<WashMisc, size_t> > washMisc_storage;
    QMap<QString, QPair<WalkMisc, size_t> > walkMisc_storage;
    QMap<QString, QPair<PetMisc, size_t> > petMisc_storage;
    QMap<QString, QPair<SleepMisc, size_t> > sleepMisc_storage;
public:
    bool fillFromJson(QString path);
    bool contains(QString itemName);
    bool addItem(const Misc& item, size_t count = 1);
    bool removeItem(QString itemName, size_t count = 1);
    void clear();

    Food atFood(QString itemName);
    WashMisc atWashMisc(QString itemName);
    WalkMisc atWalkMisc(QString itemName);
    PetMisc atPetMisc(QString itemName);
    SleepMisc atSleepMisc(QString itemName);
};

#endif // INVENTORY_H
