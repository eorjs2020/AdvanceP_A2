#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<sstream>
#include<fstream>

using namespace std;

class Fighter
{
private:
	string fName;
	int damage;
	int structStrength;
public:
	Fighter(string name, int dmg, int stStrength)
	{
		fName = name;
		damage = dmg;
		structStrength = stStrength;
	}
	void reduceStructure(int damage) 
	{
		structStrength -= damage;
	}
	string geFName()
	{
		return fName;
	}

	int	getStructStrength()
	{
		return structStrength;
	}

	int getDamage()
	{
		return damage;
	}
	string getInfo() 
	{
		ostringstream ss;
		ss << "Fighter name        : " << fName << "\n";
		ss << "Structural strength : " << structStrength << "\n";
		ss << "Damage              :" << damage << "\n" << "\n";
		return ss.str();
	}



};

class Carrier
{
private:
	string name;
	int maxBays;
	int numFighters;
	Fighter* bayList[];
public:
	Carrier(int maxBays, int numFighters)
	{
		this->numFighters = numFighters;
		this->maxBays = maxBays;
		bayList[maxBays];
	}

	bool loadFighter(Fighter* f)
	{
		if (numFighters < maxBays)
			return true;

		
		return false;
	}
	Fighter* launchNextFighter()
	{
		return;
	}
	string getInfo()
	{
		return;
	}
	bool hasFighters() {
		
		if (numFighters != 0)
			return true;

		return false;
	}

	int getCapacity() {	return maxBays;	}

	int getNumFighters(){ return numFighters; }

	string getName(){ return name; }
};




int main()
{


	return 0;
}