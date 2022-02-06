#ifndef MISC
#define MISC
#include <QString>
#include <QMap>
#include <QJsonObject>
using namespace std;
class Misc
{
public:
    enum typeEnum
    {
        FOOD,
        WASH,
        WALK,
        PET,
        SLEEP
    };
    typeEnum type;
    QString name;
	size_t price;
	size_t restoringPower;
	size_t rank;
    QString toWhom;

    QMap<QString, int> effects;

    static Misc createFromJsonObjectIterator(QJsonObject::iterator);
};
#endif// MISC
