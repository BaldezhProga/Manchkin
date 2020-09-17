#include "CardTool.h"
#include "Player.h"
using namespace std;

void CardTool::playCard(Player* player) {
	cout << "The card you played is  " << name << "!\n" << description << "\nyour bonus is " << bonus << "!\n";
	player->bonus += bonus;
}