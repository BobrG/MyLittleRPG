#include "Game.h"
#include <cstdlib>
#include <iostream>


int main() {
	Unit* Player = NULL;
	int key;

	std::cout << "Choose your destiny:" << std::endl;
	list();
	std::cin >> key;
	create(key, &Player);
	Player->initUnit();

	menu(Player);
	
	return 0;
}