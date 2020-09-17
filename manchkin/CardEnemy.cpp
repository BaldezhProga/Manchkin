#include "CardEnemy.h"
#include "Player.h"
using namespace std;

void CardEnemy::playCard(Player* player) {
	cout << "The card you played is  " << name << "!\n" << description << "!\n";
	showCard();
	int a;
	int b;
	a = player->lvl + player->bonus;
	b = enemyLvl;
	if (a > b)
	{
		cout << "U win, u get " << getCardToolBonus() << " tools, " << getLvlBonus() << " lvl(s)";
		player->lvl += getLvlBonus();
		player->takeCardTool(getCardToolBonus());
		return;
	}
	player->runAway();
}

