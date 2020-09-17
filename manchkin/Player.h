#pragma once
#include <iostream>
#include "CardTool.h"
#include "Deck.h"
#include <vector>
#include "CardEnemy.h"
#include <algorithm>
#include <ctime>
#include <locale.h>
using namespace std;

class Player{
private:
	
	string name;
	vector<Card*> cards;
	//vector<CardEnemy> enemies;
	Deck* deck;
	CardEnemy* enemy;
	
public:
	int bonus;
	int lvl = 1;
	Player(string name, Deck* deck) {
		setlocale(LC_ALL, "Russian");
		this->name = name;
		this->deck = deck;
		takeCardTool(4);
		takeCardEnemy(4);
	}

	void takeCardTool(int numberOfCards) {
		for (int i = 0; i < numberOfCards; i++)
		{
			cards.push_back(deck->getCardTool());
		}
	}

	void takeCardEnemy(int numberOfCards) {
		for (int i = 0; i < numberOfCards; i++)
		{
			cards.push_back(deck->getCardEnemy());
		}
	}
	
	void showCards() {
		for (int i = 0; i < cards.size(); i++)
		{
			cards[i]->showCard();
		}
	}

	/*void showEnemies() {
		for (int i = 0; i < enemies.size(); i++)
		{
			enemies[i].showCard();
		}
	}*/
	
	void showPlayerInfo() {
		cout << name << " -- " << lvl << "   lvl   " << "bonus = " << bonus << endl;
	}
	
	void playCard(int indexct) {
		cards[indexct]->playCard(this);
		cards[indexct] = cards[cards.size() - 1];
		cards.pop_back();
	}
	
	void knockKnock() {
		enemy = (deck->getCardEnemy());
	}

	void fight() {
		int a;
		int b;
		a = lvl + bonus;
		b = enemy->getLvl();
		if (a > b)
		{
			cout << "U win, u get " << enemy->getCardToolBonus() << " tools, " << enemy->getLvlBonus() << " lvl(s)";
			lvl += enemy->getLvlBonus();
			takeCardTool(enemy->getCardToolBonus());
			return;
		}
		runAway();

	}
	 
	void runAway() {
		cout << "You cant defeat this monster, here's your chance to slip away: you need to guess 1 number " <<
			"from 1 till 6 to do it, othervise you lose";
		srand(time(NULL));
		int r = rand() % 6;
		int r2;
		do
			r2 = rand() % 6;
		while (r == r2);
		r++;
		r2++;
		int r3;
		cin >> r3;
		if (r3 == r || r3 == r2)
			cout << "You slipped away, but didnt get the tools((";
		else
			lose();
	}
	
	void lose() {
		int a = enemy->getAntiLvlBonus();
		lvl -= a;
		cout << "Your lvl became " << lvl << ". It was downgraded by " << enemy->getAntiLvlBonus() << endl;
		if (lvl <= 0)
			cout << "YOU DIED";
	}
	
	vector<Card*>* getCards() {
		return &cards;
	}
};

