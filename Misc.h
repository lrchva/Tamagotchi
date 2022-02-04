#ifndef MISC
#define MISC
#include <QString>
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
    void effect();
    void specialEffect();
};
#endif// MISC
