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
			bayList[tail] = f;

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
		ostringstream ss;
		ss << "Carrier name: " << name << "\n";
		for (int i = 0; i < numFighters; i++)
		{
			ss << bayList[i]->getInfo();
		}
		return ss.str();
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

void battle(Carrier* a, Carrier* b)
{
	
	Fighter* tempf1, * tempf2, *first, *second;
	Carrier* tempc1 = a, * tempc2 = b;
	int roll, rollfirst, damageroll, turn;
	turn = 0;
	
	while (tempc1->hasFighters() && tempc2->hasFighters()) 
	{
		system("cls");
		tempf1 = tempc1->launchNextFighter();
		tempf2 = tempc2->launchNextFighter();
		while (tempf1->getStructStrength() > 0 && tempf2->getStructStrength() > 0)
		{
			roll = damageroll = rollfirst = 0;
			cout << "Turn: " << turn << endl;
			rollfirst = rand() % 2 + 1;
			if(rollfirst){
				first = tempf1;
				second = tempf2;
			}
			else {
				first = tempf2;
				second = tempf1;
			}
			roll = rand() % 100 + 1;
			if (roll >= 50) {		
				damageroll = rand() % first->getDamage() + 1;
				second->reduceStructure(damageroll);
				cout << first->getFName() << " hits " << second->getFName() << " for " << damageroll << endl;
			}
			else {
				cout << first->getFName() << " misses " << second->getFName() << endl;
			}
			roll = rand() % 100 + 1;
			if (second->getStructStrength() <= 0 ){
				break;
			}
			if (roll >= 50) {	
				damageroll = rand() % second->getDamage() + 1;
				first->reduceStructure(damageroll);
				cout << second->getFName() << " hits " << first->getFName() << " for " << damageroll << endl;
			}
			else {
				cout << second->getFName() << " misses " << first->getFName() << endl;
			}
			++turn;
		}
		
		if (tempf1->getStructStrength() > 0){
			tempc1->loadFighter(tempf1);
		}
		else{
			cout << "BOOOOOMMMM " << tempf1->getFName() << " destroyed!!!!!" << endl ; 
		}
		if (tempf2->getStructStrength() > 0){	
			tempc2->loadFighter(tempf2);
		}
		else {
			cout << "BOOOOOMMMM " << tempf2->getFName() << " destroyed!!!!!" << endl;
		}
		system("pause");
	}
	if (tempc1->hasFighters())	{
		cout << tempc1->getName() << " wins the battle " << endl;
	}
	if (tempc2->hasFighters()){
		cout << tempc2->getName() << " wins the battle " << endl;
	}
}


int main()
{
	srand((unsigned)time(0));
	Carrier* c1,* c2;
	Fighter* ftemp;
	std::ifstream in;
	int m, n, n1;
	std::string name;
	in.open("shipData.txt");
	if (!in.is_open()) {
		std::cout << "Error";
	}
	
	in >> name;
	in.ignore();
	in >> m;
	//in.ignore();
	in >> n; 
	c1 = new Carrier(m, name);
	for (int x = 0; x < n; ++x) {
		in >> name;
		in.ignore();
		in >> m;
			
		in >> n1;
		ftemp = new Fighter(name, n1, m);
		c1->loadFighter(ftemp);
	}
	in >> name;
	in.ignore();
	in >> m;

	in >> n;
	c2 = new Carrier(m, name);
	for (int x = 0; x < n; ++x) {
		in >> name;
		in.ignore();
		in >> m;
			
		in >> n1;
		ftemp = new Fighter(name, n1, m);
		c2->loadFighter(ftemp);
	}
	
	in.close();
	

	cout << c1->getInfo();
	cout << c2->getInfo();
	system("pause");
	battle(c1, c2);

	system("pause");
	return 0;
}