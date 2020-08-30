#pragma once
#include <iostream>
using namespace std;

class CardEnemy
{
private:
	string enemyName;
	int enemyLvl;
	string enemyDescription;
	int enemyLvlBonus;
	int enemyCardToolBonus;
	int enemyAntiLvlBonus;
public:
	CardEnemy(string n, int lvl, string d, int lvlb, int ctb, int antib) {
		enemyName = n;
		enemyLvl = lvl;
		enemyDescription = d;
		enemyLvlBonus = lvlb;
		enemyCardToolBonus = ctb;
		enemyAntiLvlBonus = antib;
	}
	void showCard() {
		cout << "The enemy is  " << enemyName << "!\n" << enemyDescription << "enemy lvl is" << enemyLvl << "!\n" << "Treasure that u'll get is"
			<< enemyCardToolBonus << "Level that u'll get +" << enemyLvlBonus << "!\n" << "If you lose u'll downgrade by" << enemyAntiLvlBonus << "lvl\n"; 
	}
	int getLvl() {
		return enemyLvl;
	}
	 
	int getLvlBonus() {
		return enemyLvlBonus;
	}

	int getCardToolBonus() {
		return enemyCardToolBonus;
	}
	
	int getAntiLvlBonus() {
		return enemyAntiLvlBonus;
	}



	/*void playCard() {
		cout << "The card you played is  " << enemyName << "!\n" << enemyDescription << "\nyour bonus is " << bonus << "!\n";
	}
	int getBonus() {
		return bonus;
	}*/
};
