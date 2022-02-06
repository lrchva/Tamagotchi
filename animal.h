#ifndef ANIMAL_H
#define ANIMAL_H
#include <QString>
#include <QMap>
#include "Misc.h"

class Animal
{
public:
    Animal();
    Animal(QString, QString, size_t, QMap<QString, size_t>);
    QString name;
    QString type;
    size_t level;
    QMap<QString, size_t> chars;

    void takeEffects(Misc);
    void* takeSpaecialEffects(Misc);
};

#endif // ANIMAL_H
