#pragma once
#include <iostream>
#include "CardTool.h"
#include "CardEnemy.h"
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <ctime>
#include <locale.h>

using namespace std;
class Deck
{
private:
	vector <CardTool> cardTools;
	vector <CardEnemy> cardEnemies;
    void getTools(){
		string path = "D:/CppNeRussian/CardTools.txt";
		ifstream fin(path);
		string name;
		string description;
		int bonus;
		while (getline(fin, name)) {
			getline(fin, description);
			fin >> bonus;
			CardTool ct(name, description, bonus);
			cardTools.push_back(ct);
			getline(fin, name);
		}
		fin.close(); }
	void getEnemy() {
		setlocale(LC_ALL, "Russian");
		string enemyPath = "D:/CppNeRussian/CardEnemy.txt";
		ifstream fin(enemyPath);
		string name;
		int lvl;
		string description;
		int lvlBonus;
		int cardToolBonus;
		int antiLvlBonus;
		while (getline(fin, name)) {
			fin >> lvl;
			getline(fin, description);
			getline(fin, description);
			fin >> lvlBonus >> cardToolBonus >> antiLvlBonus;
			CardEnemy ce(name, lvl, description, lvlBonus, cardToolBonus, antiLvlBonus);
			cardEnemies.push_back(ce);
			getline(fin, name);
		}
		fin.close();
	}
	void shuffleTools() {
		srand(time(NULL));
		for (int i = 0; i < cardTools.size(); i++) {
			int r = rand() % cardTools.size();
			auto ct = cardTools[i];
			cardTools[i] = cardTools[r];
			cardTools[r] = ct;
		}
	}
	void shuffleEnemies() {
		srand(time(NULL));
		for (int i = 0; i < cardEnemies.size(); i++) {
			int r = rand() % cardEnemies.size();
			auto ce = cardEnemies[i];
			cardEnemies[i] = cardEnemies[r];
			cardEnemies[r] = ce;
		}
	}

public:
	Deck() {
		setlocale(LC_ALL, "Russian");
		getTools();
		getEnemy();
		shuffleTools();
	}
	CardTool getCardTool() {
		CardTool ct = cardTools[cardTools.size() - 1];
		cardTools.pop_back();
		return(ct);
	}
	CardEnemy getCardEnemy() {
		CardEnemy ce = cardEnemies[cardEnemies.size() - 1];
		cardEnemies.pop_back();
		ce.showCard();
		return (ce);
	}
	
};

