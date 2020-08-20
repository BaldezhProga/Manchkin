#pragma once
#include <iostream>
using namespace std;

class CardTool {
private:
	string name;
	string description;
	int bonus;
public:
	CardTool(string n, string d, int b) {
		name = n;
		description = d;
		bonus = b;
	}
	void playCard() {
		cout << "The card you played is  " << name << "!\n" << description << "\nyour bonus is " << bonus << "!\n";
	}
	void showCard() {
		cout << "The card is  " << name << "!\n" << description << "\nbonus " << bonus << "!\n";
	}
	int getBonus() {
		return bonus;
	}
};


