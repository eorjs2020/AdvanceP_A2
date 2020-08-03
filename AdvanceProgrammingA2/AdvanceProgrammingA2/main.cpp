#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<sstream>
#include<fstream>

using namespace std;

class Fighter
{
	
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

	void loadFighter(Fighter* f)
	{
		if (numFighters < maxBays)
			return;
	}
	void launchNextFighter()
	{

	}
	void getInfo()
	{

	}
	bool hasFighters() { return; }

	int getCapacity() {	return maxBays;	}

	int getNumFighters(){ return numFighters; }

	string getName(){ return name; }
};




int main()
{


	return 0;
}