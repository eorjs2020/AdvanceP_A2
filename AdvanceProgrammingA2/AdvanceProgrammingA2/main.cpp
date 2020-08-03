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
	string getFName()
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
	int tail;
	int top;
	Fighter* bayList[100];
public:
	Carrier(int max, string name)
	{
		this->name = name;
		numFighters = 0;
		tail = top = -1;
		this->maxBays = max;
		
		//bayList[max];
	}

	bool loadFighter(Fighter* f)
	{
		if (numFighters == maxBays)
			return false;
		
		if (top == -1)
		{
			top = tail = 0;
			bayList[tail] = new Fighter("dd", 13, 13);

		}
		else
		{
			tail = (tail + 1) % maxBays;
			bayList[tail] = f;
		}
		++numFighters;
		return true;
		
	}
	Fighter* launchNextFighter()
	{
		
	
		Fighter* curr = nullptr;
		if (hasFighters())
		{
			curr = bayList[top];
		
			if (top == tail)
			{
				
				top = tail = -1;
			}
			else
			{
				
				
				top = (top + 1) % maxBays;
				
			}
			--numFighters;
		}
		else
		{
			cout << "Empty" << endl;
			
		}
		return curr;
	}
	string getInfo()
	{
		string s = "  ";
		return s;
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