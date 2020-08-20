#pragma once
#include <iostream>
#include "CardTool.h"
#include "Deck.h"
#include <vector>
#include "CardEnemy.h"
using namespace std;

class Player{
private:
	int lvl = 1;
	string name;
	vector<CardTool> cards;
	vector<CardEnemy> enemies;
	Deck* deck;
	CardEnemy* enemy;
	int bonus;
public:
	Player(string name, Deck* deck) {
		this->name = name;
		this->deck = deck;
		takeCard(8);
	}

	void takeCard(int numberOfCards) {
		for (int i = 0; i < numberOfCards; i++)
		{
			cards.push_back(deck->getCardTool());
		}
	}
	
	void showCards() {
		for (int i = 0; i < cards.size(); i++)
		{
			cards[i].showCard();
		}
	}

	void showEnemies() {
		for (int i = 0; i < enemies.size(); i++)
		{
			enemies[i].showCard();
		}
	}
	
	void showPlayerInfo() {
		cout << name << " -- " << lvl << "   lvl   " << "bonus = " << bonus << endl;
	}
	
	void playCard(int indexct) {
		cards[indexct].playCard();
		bonus += cards[indexct].getBonus();
		cards[indexct] = cards[cards.size() - 1];
		cards.pop_back();
	}
	
	void knockKnock(int indexce) {
	
	}
	
	vector<CardTool> getCards() {
		return cards;
	}
};

