#ifndef ANIMAL_H
#define ANIMAL_H
#include <QString>
#include <QMap>
#include "Misc.h"

class Animal
{
public:
    static QVector<Animal> storage;
    static bool loadFromJson(QString path);
    static bool saveToJson(QString path);
    Animal();
    Animal(QString, QString, size_t, QMap<QString, int>);
    QString name;
    QString type;
    size_t level;
    QString pathToSkin;
    QMap<QString, int> chars;

    void takeEffects(Misc);
    void* takeSpaecialEffects(Misc);
};

#endif // ANIMAL_H
