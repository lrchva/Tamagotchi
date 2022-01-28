#ifndef MISC
#define MISC
#include <QString>
using namespace std;
class Misc
{
public:
    enum toWhomEnum
    {
        RABBIT,
        CAT,
        DOG,
        HAMSTER,
        MINIPIG
    };
    QString type;
    QString name;
	size_t price;
	size_t restoringPower;
    QString pathToSkin;
	size_t rank;
    toWhomEnum toWhom;
protected:
	virtual void specialEffect() = 0;
	virtual void submitEffect() = 0;
};

class Food : public Misc
{
public:
	void specialEffect() override;
	void submitEffect() override;
    Food(const Misc&);
    Food();
};
class WashMisc : public Misc
{
public:
	void specialEffect() override;
	void submitEffect() override;
};
class WalkMisc : public Misc
{
public:
	void specialEffect() override;
	void submitEffect() override;
};
class PetMisc : public Misc
{
public:
	void specialEffect() override;
	void submitEffect() override;
};
class SleepMisc : public Misc
{
public:
	void specialEffect() override;
	void submitEffect() override;
};
#endif// MISC
