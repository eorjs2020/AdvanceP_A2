//Michael Shular 101273089
//Daekoen Lee 101076401

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
	string m_pFighterName;
	int m_pDamage;
	int m_pStructStrength;
public:
	Fighter(string name, int dmg, int stStrength) {	
		m_pFighterName = name;
		m_pDamage = dmg;
		m_pStructStrength = stStrength;
	}
	void reduceStructure(int damage) {
		m_pStructStrength -= damage;
	}
	string getInfo() {
		ostringstream ss;
		ss << "Fighter name        : " << m_pFighterName << "\n";
		ss << "Structural strength : " << m_pStructStrength << "\n";
		ss << "Damage              : " << m_pDamage << "\n" << "\n";
		return ss.str();
	}
	string getFName() { return m_pFighterName; }
	int	getStructStrength() { return m_pStructStrength; }
	int getDamage() { return m_pDamage; }
};

class Carrier {
private:
	string m_pName;
	int m_pMaxBays,m_pNumFighters, m_pTail, m_pTop;
	Fighter* m_pBayList[100];
public:
	Carrier(int max, string name) {
		this->m_pName = name;
		m_pNumFighters = 0;
		m_pTail = m_pTop = -1;
		this->m_pMaxBays = max;
		//m_pBayList[m_pMaxBays];
	}
	bool loadFighter(Fighter* f) {
		if (m_pNumFighters == m_pMaxBays)
			return false;
		if (m_pTop == -1) {
			m_pTop = m_pTail = 0;
			m_pBayList[m_pTail] = f;

		}
		else {
			m_pTail = (m_pTail + 1) % m_pMaxBays;
			m_pBayList[m_pTail] = f;
		}
		++m_pNumFighters;
		return true;
	}
	Fighter* launchNextFighter(){
		Fighter* curr = nullptr;
		if (hasFighters()) {
			curr = m_pBayList[m_pTop];
			if (m_pTop == m_pTail) {
				m_pTop = m_pTail = -1;
			}
			else{	
				m_pTop = (m_pTop + 1) % m_pMaxBays;
			}
			--m_pNumFighters;
		}
		else {
			cout << "Empty" << endl;
		}
		return curr;
	}
	string getInfo() {
		ostringstream ss;
		ss << "Carrier name: " << m_pName << "\n";
		for (int i = 0; i < m_pNumFighters; i++) {
			ss << m_pBayList[i]->getInfo();
		}
		return ss.str();
	}
	bool hasFighters() {	
		if (m_pNumFighters != 0)
			return true;
		return false;
	}
	int getCapacity() {	return m_pMaxBays;	}
	int getNumFighters(){ return m_pNumFighters; }
	string getName(){ return m_pName; }
};

void battle(Carrier* a, Carrier* b) {
	Fighter* tempf1, * tempf2, *first, *second;
	Carrier* tempc1 = a, * tempc2 = b;
	int rollToHit, rollToAttackFirst, damageRoll, amountOfTurns = 0;
	
	//Step 4 Loop for battle until no more ships
	while (tempc1->hasFighters() && tempc2->hasFighters()) {
		system("cls");
		//Step 1 both carriers launch fighters 
		tempf1 = tempc1->launchNextFighter();
		tempf2 = tempc2->launchNextFighter();
		//Step 2 loop for fighters to attack
		while (tempf1->getStructStrength() > 0 && tempf2->getStructStrength() > 0) {
			rollToHit = damageRoll = rollToAttackFirst = 0;
			cout << "Turn: " << amountOfTurns << endl;
			//Step 2.1 randomize turn order 
			rollToAttackFirst = rand() % 2 + 1;
			if(rollToAttackFirst){
				first = tempf1;
				second = tempf2;
			}
			else {
				first = tempf2;
				second = tempf1;
			}
			//Step 2.2 Check to see if attack hits or misses
			rollToHit = rand() % 100 + 1;
			if (rollToHit >= 50) {		
				damageRoll = rand() % first->getDamage() + 1;
				second->reduceStructure(damageRoll);
				cout << first->getFName() << " hits " << second->getFName() << " for " << damageRoll << endl;
			}
			else {
				cout << first->getFName() << " misses " << second->getFName() << endl;
			}
			//Step 2.4 Oppsite fighter attacks 
			rollToHit = rand() % 100 + 1;
			if (second->getStructStrength() <= 0 ){
				break;
			}
			if (rollToHit >= 50) {	
				damageRoll = rand() % second->getDamage() + 1;
				first->reduceStructure(damageRoll);
				cout << second->getFName() << " hits " << first->getFName() << " for " << damageRoll << endl;
			}
			else {
				cout << second->getFName() << " misses " << first->getFName() << endl;
			}
			++amountOfTurns;
		}
		//Step 3 Loading suviving fighter
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

int main() {
	Carrier* c1,* c2;
	Fighter* tempFighter;
	std::ifstream in;
	int bayCapacity, maxFighters, structStrength, damage;
	std::string nameCarrier, nameFighter;
	
	srand((unsigned)time(0));
	//Step 1. Loading data for text files
	in.open("shipData.txt");
	if (!in.is_open()) {
		std::cout << "Error";
	}
	in >> nameCarrier;
	in.ignore();
	in >> bayCapacity;
	in >> maxFighters; 
	c1 = new Carrier(bayCapacity, nameCarrier);
	for (int x = 0; x < maxFighters; ++x) {
		in >> nameFighter;
		in.ignore();
		in >> damage;
		in >> structStrength;
		tempFighter = new Fighter(nameFighter, structStrength, damage);
		c1->loadFighter(tempFighter);
	}
	in >> nameCarrier;
	in.ignore();
	in >> bayCapacity;
	in >> maxFighters;
	c2 = new Carrier(bayCapacity, nameCarrier);
	for (int x = 0; x < maxFighters; ++x) {
		in >> nameFighter;
		in.ignore();
		in >> damage;
		in >> structStrength;
		tempFighter = new Fighter(nameFighter, structStrength, damage);
		c2->loadFighter(tempFighter);
	}
	in.close();
	//Step 2. Print out carrier data 
	cout << c1->getInfo();
	cout << c2->getInfo();
	system("pause");
	//Step 3. Battle simulation 
	battle(c1, c2);
	system("pause");
	//Step 4. Print out carrier data
	system("cls");
	cout << c1->getInfo() << endl;
	cout << c2->getInfo();
	system("pause");
	return 0;
}