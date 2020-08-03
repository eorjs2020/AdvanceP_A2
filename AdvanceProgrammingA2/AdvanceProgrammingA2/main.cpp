#include <iostream>
#include <vector>
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
	vector<Fighter*> bayList;
public:
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