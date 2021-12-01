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