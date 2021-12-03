#ifndef ANIMAL
#define ANIMAL
#include <string>
#include <map>
#include <set>

using namespace std;

class Animal
{
protected:
	string name;
	string pathToSkin;
	string pathToSound;
	map<string, size_t> HungerChars;
	map<string, size_t> SleepChars;
	map<string, size_t> AttentionChars;
	map<string, size_t> TidinessChars;
	map<string, size_t> ActivityChars;
	map<string, size_t> GeneralChars;
	const set<string> _listOfCharachteristics =
	{ "cur", "max", "base"};
	void eat();
	void drink();
	void goToBed();
	void pet();
	void wash();
	void walk();
	void play();
};
class Rabbit : public Animal
{

};
class Cat : public Animal
{
	
};
class Dog : public Animal
{
	
};
class Hamster : public Animal
{
	
};
class MiniPig : public Animal
{
	
};
#endif// ANIMAL
