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
    Food(const Misc& misc);
    Food();
};
class WashMisc : public Misc
{
public:
	void specialEffect() override;
	void submitEffect() override;
    WashMisc(const Misc& misc);
    WashMisc();
};
class WalkMisc : public Misc
{
public:
	void specialEffect() override;
	void submitEffect() override;
    WalkMisc(const Misc& misc);
    WalkMisc();
};
class PetMisc : public Misc
{
public:
	void specialEffect() override;
	void submitEffect() override;
    PetMisc(const Misc& misc);
    PetMisc();
};
class SleepMisc : public Misc
{
public:
	void specialEffect() override;
	void submitEffect() override;
    SleepMisc(const Misc& misc);
    SleepMisc();
};
#endif// MISC
