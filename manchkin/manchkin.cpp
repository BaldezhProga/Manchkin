﻿using namespace std;

#include <iostream>
#include <vector>
#include "Deck.h"
#include "Player.h"
#include "CardTool.h"
#include <locale.h>

using namespace std;
void fightEnemy(Player player);

int main()
{
	setlocale(LC_ALL, "Russian");
    string name = "Makar";
	Deck* deck = new Deck;

	Player player(name, deck);
	player.showCards();
	player.showPlayerInfo();
	cout << "I'm glad to welcome you, manchkin, right now your on the 1st level of progress, reach 10th level to win the game while fighting different monsters" << "press keys'1' - '10' to choose a card, press'0' to play the latest chosen card" << endl;
	int b = 0;
	int p = 0;
	do {
		cin >> b;
		if (b > player.getCards()->size())
		{
			cout << "Choose another card, you dont have this much cards";
			continue;
		}
		if (b != 0) {
			p = b;
			(*player.getCards())[b - 1]->showCard();
		}
	} while (b != 0);
	if (p == 0)
		p++;
	player.playCard(p-1);
	fightEnemy(player);

	delete deck;
}
void fightEnemy(Player player) {
	cout << "If you are ready to fight a monster write 'knock'";
	string knock;
	cin >> knock;
	if (knock == "knock") {
		player.knockKnock();
		cout << "Do you think ure strong enough to fight it? Press 'f' to fight, press 's' to try to slip away";
		string input;
		cin >> input;
		if (input == "f")
			player.fight();
		else if (input == "s")
			player.runAway();
	}
	return;
}



