#pragma once
#include <iostream>


using namespace std;
class Player;
class Card
{
protected:
	string name;
	string description;
public:
	Card(string name, string description) {
		this->name = name;
		this->description = description;
	}
	virtual void playCard(Player* player) {
		cout << "Ya Karta\n";

	}
	virtual void showCard() {

	}
};

