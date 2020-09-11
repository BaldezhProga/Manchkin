#pragma once
#include <iostream>
#include "Card.h"
#include "Player.h"
using namespace std;


class CardTool: public Card {
private:
 
	int bonus;
public:
	CardTool(string n, string d, int b) : Card(n, d){
		bonus = b;
	}
	void playCard(Player* player) {
		cout << "The card you played is  " << name << "!\n" << description << "\nyour bonus is " << bonus << "!\n";
		player->bonus += bonus;
	}
	void showCard() {
		cout << "The card is  " << name << "!\n" << description << "\nbonus " << bonus << "!\n";
	}
	int getBonus() {
		return bonus;
	}
};


