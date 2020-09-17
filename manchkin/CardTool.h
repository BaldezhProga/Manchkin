#pragma once
#include <iostream>
#include "Card.h"
using namespace std;
class Player;

class CardTool: public Card {
private:
 
	int bonus;
public:
	CardTool(string n, string d, int b) : Card(n, d){
		bonus = b;
	}
	void playCard(Player* player);
	void showCard() {
		cout << "The card is  " << name << "!\n" << description << "\nbonus " << bonus << "!\n";
	}
	int getBonus() {
		return bonus;
	}
};


