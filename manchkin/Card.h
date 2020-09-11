#pragma once
#include <iostream>
using namespace std;
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
	virtual void playCard() {
		cout << "Ya Karta\n";

	}
};

