#include <iostream>
#include <random>
#include <iomanip>
#include "Unit.h"

void list() {
	std::cout << " 1 - Wizard" << std::endl;
	std::cout << " 2 - Warrior" << std::endl;
	std::cout << " 3 - Paladin" << std::endl;
	std::cout << " any other key - /leave" << std::endl;
}

void create(int key, Unit** u) {
	if (key == 1) {
		*u = new Wizard;
	}
	else if (key == 2) {
		*u = new Warrior;
	}
	else if (key == 3) {
		*u = new Paladin;
	}
	else {
		key = 0;
	}
}

bool AnyAlive(Unit* a, Unit* b) {
	int aa, bb;
	return (a->getHealth() > 0 && b->getHealth() > 0);
}

void Arena(Unit* Player) {
	int key = 0;
	std::cout << "Choose a type of fight:" << std::endl;
	// Two types: team battle key = 2 && single player key = 1;
	switch (key)
	{
	case 1:
		SingleArena(Player);
		break;
	case 2:
		TeamArena(Player);
		break;
	default:
		break;
	}
	
}

void SingleArena(Unit* Player) {
	Unit* Opponent = NULL;
	int key = 0;
	std::cout << "Choose your opponent:" << std::endl;
	list();
	std::cin >> key;
	create(key, &Opponent);
	//if (!key) { return 0; }
	Opponent->InitUnit();
	Attack* pl_hit = Player->Hit();
	Attack* opp_hit = Opponent->Hit();

	for (int i = 0; AnyAlive(Player, Opponent); ++i) {
		int pl_dmg, opp_dmg;
		std::cout << "Round #" << i + 1 << std::endl;
		Player->info();
		Opponent->info();

		std::cout << "Player attacks: " << std::endl;
		pl_dmg = pl_hit->attack();// player attacks;
		opp_hit->fendoff(pl_dmg);// opponent fends off;
		std::cout << "Opponent attacks: " << std::endl;
		opp_dmg = opp_hit->attack();// opponent attacks;
		pl_hit->fendoff(opp_dmg);// player fends off; 

		Opponent->SetStat(pl_dmg, opp_hit->GetBaff());
		Player->SetStat(opp_dmg, pl_hit->GetBaff());
	}

	std::cout << "THE END OF FIGHT:" << std::endl;

	Player->info();
	Opponent->info();

}

void TeamArena(Unit* Player) {
	std::vector <Unit*> Opponents;
	std::vector <Unit*> Players;
	int num_opp, num_pl, num_min, num_max;
	std::cout << "Input size of your team: (take your character in account too)" << std::endl;
	std::cin >> num_pl;
	Players.resize(num_pl); 
	for (int i = 0; i < num_pl; ++i) {
		int key;
		std::cout << "Choose your teammate #" << i + 1 << std::endl;
		list();
		std::cin >> key;
		create(key, &Players[i]);
	}
	Players.insert(Players.begin(),Player);

	std::cout << "Input size of your opponent team:" << std::endl;
	std::cin >> num_opp;
	Opponents.resize(num_opp);
	for (int i = 0; i < num_opp; ++i) {
		int key;
		std::cout << "Choose your opponent #" << i + 1 << std::endl;
		list();
		std::cin >> key;
		create(key, &Opponents[i]);
	}

	if (num_pl > num_opp) {
		num_min = num_opp;
		num_max = num_pl;
	}
	else {
		num_min = num_pl;
		num_max = num_opp;
	}
	for (int i = 0; i < num_min; ++i) {
		std::cout << "Player #" << i + 1 << std::endl;
		Players[i]->UnitMenu();

		std::cout << "Opponent #" << i + 1 << std::endl;
		Opponents[i]->UnitMenu();
	}
	if (Opponents.size() > Players.size()) {
		for (int i = num_min; i < num_max; ++i) {
			std::cout << "Opponent #" << i + 1 << std::endl;
			Opponents[i]->UnitMenu();
		}
	}
	else {
		for (int i = num_min; i < num_max; ++i) {
			std::cout << "Player #" << i + 1 << std::endl;
			Players[i]->UnitMenu();
		}
	}

	std::cout << "Choose the order of team's attack:" << std::endl;
	std::cout << "Player's team strikes first." << std::endl;
	std::cout << "Opponent's team strikes first." << std::endl;


}

void menu(Unit* u) {
	int key = 0;
	bool MenuOn = 1;
	// TODO: add options
	// 1. Calling unit's menu.
	// 2. Present invitation to dungeon.
	// 3. Choose team battle mode.
	// 4. Leave menu.
	while (MenuOn) {
		system("CLS");
		std::cout << " " << std::setw(48) << std::right << std::setfill('_') << " " << std::endl;
		std::cout << "|" << std::setw(26) << std::right << std::setfill('_');
		std::cout << "M_E_N_U" << std::setw(22) << std::right << std::setfill('_') << "|" << std::endl;
		std::cout << "|" << std::setw(48) << std::right << std::setfill('_') << "|" << std::endl;
		std::cout << "|" << std::setw(20) << std::right << std::setfill('_');
		std::cout  << "1._Unit_menu." ;
		std::cout << std::setw(28) << std::right << std::setfill('_') << "|"  << std::endl;
		std::cout << "|" << std::setw(19) << std::right << std::setfill('_');
		std::cout << "2._Dungeons." ;
		std::cout << std::setw(29) << std::right << std::setfill('_') << "|" << std::endl;
		std::cout << "|" << std::setw(16) << std::right << std::setfill('_');
		std::cout << "3._Arena.";
		std::cout << std::setw(32) << std::right << std::setfill('_') << "|" << std::endl;
		std::cout << "|" << std::setw(16) << std::right << std::setfill('_');
		std::cout << "4._Leave.";
		std::cout << std::setw(32) << std::right << std::setfill('_') << "|" << std::endl;
		std::cout << "|" << std::setw(48) << std::right << std::setfill('_') << "|" << std::endl;
		std::cin >> key;

		switch (key)
		{
		case 1: // Unit's menu;
			system("CLS");

			u->UnitMenu();
			std::cout << "Back to main menu: press e n t e r." << std::endl;

			std::getchar();
			if (std::getchar() == '\n') {
				MenuOn = 1;
			}
			else
				MenuOn = 0;
				break;
		case 2: // it. 2
		case 3:
			system("CLS");

			Arena(u);
			std::cout << "Back to main menu: press e n t e r." << std::endl;

			std::getchar();
			if (std::getchar() == '\n') {
				MenuOn = 1;
			}
			else
				MenuOn = 0;
			break;
		case 4:
			system("CLS");
			std::cout << "Do you really want to leave?" << std::endl;
			std::cout << "0 - No." << std::endl;
			std::cout << "1 - Yes." << std::endl;
			std::cin >> key;
			if (!key) {
				MenuOn = 1;
			}
			else if (key == 1)
				MenuOn = 0;
			break;

		default:
			std::cout << "Unknown command. Please concentrate and try again." << std::endl;
			std::cin >> key;

			break;
		}
		if (u->getHealth() <= 0) {
			system("CLS");
			std::cout << "Your hero is dead. Rest in piece... and come again for new battles." << std::endl;
			break;
		}
	}
}
