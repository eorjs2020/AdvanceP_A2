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
	int head;
	Fighter* bayList[];
public:
	Carrier(int maxBays, string name)
	{
		this->maxBays = maxBays;
		bayList[maxBays];
		numFighters = -1;
		head = -1;
	}

	bool loadFighter(Fighter* f)
	{
		++numFighters;
		bayList[numFighters] = f;
		return false;
	}
	Fighter* launchNextFighter()
	{
		if (!hasFighters)
		{
			head++;
			return bayList[head];
		}
		
		return;
	}
	string getInfo()
	{
		return;
	}
	bool hasFighters() {
		
		if (numFighters != -1)
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