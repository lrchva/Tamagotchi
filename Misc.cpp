#include "Misc.h"

void Food::submitEffect()
{
	//Increase satiety
	//Increase vitality
}
void Food::specialEffect()
{
	//Increase general happiness
	//Slightly increase attention
	//Slightly decrease tidyness
}
Food::Food(const Misc& o)
{
    this->type = o.type;
    this->name = o.name;
    this->price = o.price;
    this->restoringPower = o.restoringPower;
    this->pathToSkin = o.pathToSkin;
    this->rank = o.rank;
    this->toWhom = o.toWhom;
}
Food::Food()
{
    this->type = "";
    this->name = "";
    this->price = 0;
    this->restoringPower = 0;
    this->pathToSkin = "";
    this->rank = 0;
}

void WashMisc::submitEffect()
{
	//Increase tidyness
	//Change skin to tidy
    //Slightly increase vitality
}
void WashMisc::specialEffect()
{
	//Increase general happiness
	//Slightly increase attention
}
WashMisc::WashMisc(const Misc& misc)
{
    this->type = misc.type;
    this->name = misc.name;
    this->price = misc.price;
    this->restoringPower= misc.restoringPower;
    this->pathToSkin = misc.pathToSkin;
    this->rank = misc.rank;
    this->toWhom = misc.toWhom;
}
WashMisc::WashMisc()
{
    this->type = "";
    this->name = "";
    this->price = 0;
    this->restoringPower = 0;
    this->pathToSkin = "";
    this->rank = 0;
}

void WalkMisc::submitEffect()
{
	//Increase activity
	//Decrease tidyness
	//Decrease satiety
	//Decrease vitality
}
void WalkMisc::specialEffect()
{
	//Increase general happiness
	//Slightly increase attention
}
WalkMisc::WalkMisc(const Misc& misc)
{
    this->type = misc.type;
    this->name = misc.name;
    this->price = misc.price;
    this->restoringPower= misc.restoringPower;
    this->pathToSkin = misc.pathToSkin;
    this->rank = misc.rank;
    this->toWhom = misc.toWhom;
}
WalkMisc::WalkMisc()
{
    this->type = "";
    this->name = "";
    this->price = 0;
    this->restoringPower = 0;
    this->pathToSkin = "";
    this->rank = 0;
}

void PetMisc::submitEffect()
{
	//Greatly increase attention
	//Slightly increase vitality
	//Slightly decrease activity
}
void PetMisc::specialEffect()
{
	//Increase general happiness
}
PetMisc::PetMisc(const Misc& misc)
{
    this->type = misc.type;
    this->name = misc.name;
    this->price = misc.price;
    this->restoringPower= misc.restoringPower;
    this->pathToSkin = misc.pathToSkin;
    this->rank = misc.rank;
    this->toWhom = misc.toWhom;
}
PetMisc::PetMisc()
{
    this->type = "";
    this->name = "";
    this->price = 0;
    this->restoringPower = 0;
    this->pathToSkin = "";
    this->rank = 0;
}

void SleepMisc::submitEffect()
{
	//Greatly increase vitality
	//Decrease satiety
	//Slightly decrease attention
	//Decrease activity
}
void SleepMisc::specialEffect()
{
	//Increase general happiness
}
SleepMisc::SleepMisc(const Misc& misc)
{
    this->type = misc.type;
    this->name = misc.name;
    this->price = misc.price;
    this->restoringPower= misc.restoringPower;
    this->pathToSkin = misc.pathToSkin;
    this->rank = misc.rank;
    this->toWhom = misc.toWhom;
}
SleepMisc::SleepMisc()
{
    this->type = "";
    this->name = "";
    this->price = 0;
    this->restoringPower = 0;
    this->pathToSkin = "";
    this->rank = 0;
}
