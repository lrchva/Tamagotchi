#ifndef MISC
#define MISC
#include <QString>
#include <QMap>
#include <QJsonObject>
#include <QPushButton>
using namespace std;
class Misc
{
public:
    Misc();
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
	  size_t rank;
    QString toWhom;

    QMap<QString, int> effects;

    static Misc createFromJsonObjectIterator(QJsonObject::iterator);
    QPushButton* button;
};
#endif// MISC
