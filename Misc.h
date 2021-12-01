#ifndef MISC
#define MISC
#include <string>
using namespace std;
class Misc
{
protected:
	size_t price;
	size_t restoringPower;
	string pathToSkin;
	size_t rank;
	enum toWhom
	{
		RABBIT,
		CAT,
		DOG,
		HAMSTER,
		MINIPIG
	};
	virtual void specialEffect() = 0;
	virtual void submitEffect() = 0;
};

class Food : public Misc
{
public:
	void specialEffect() override;
	void submitEffect() override;
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