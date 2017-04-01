#include <iostream>
#include <random>
#include <iomanip>
#include "Game.h"
#include "Unit.h"

typedef std::vector<Unit*> UnArr;

void list() {
	std::cout << " 1 - Wizard" << std::endl;
	std::cout << " 2 - Warrior" << std::endl;
	std::cout << " 3 - Paladin" << std::endl;
	std::cout << " 4 - Defender" << std::endl;
	std::cout << " 5 - Demon Slayer" << std::endl;
	std::cout << " any other key - /leave" << std::endl;
}


void create(int key, Unit** u) {
	if (key == 1) {
		*u = new Wizard;
	}
	else if (key == 2) {
		*u = new Berserk;
	}
	else if (key == 3) {
		*u = new Paladin;
	}
	else if (key == 4) {
		*u = new Defender;
	}
	else if (key == 5) {
		*u = new DemonSlayer;
	}
	else {
		key = 0;
	}
}

bool AnyAlive(Unit* a, Unit* b) {
	return (a->getHealth() > 0 && b->getHealth() > 0);
}

void Arena(Unit* Player) {
	int key = 0;
	std::cout << "Choose a type of fight:" << std::endl;
	// Two types: team battle key = 2 && single player key = 1;
	std::cout << " 1 - Single battle;" << std::endl;
	std::cout << " 2 - Team battle;" << std::endl;
	std::cin >> key;

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

bool max_el(Unit* a, Unit* b) { return (a->getHealth() < b->getHealth()); }

int AutoAttack(UnArr& Oppenents) {
	int key = 0;
	Unit* tmp = Oppenents[0];
	for (int i = 1; i < Oppenents.size(); ++i) {
		if (tmp->getHealth() > Oppenents[i]->getHealth) {
			tmp = Oppenents[i];
			key = i;
		}
	}
	return key;
}

int AutoAttack(Unit* Player, Unit* Opponent) {
	int key = 0;
	if (0/*check inspiration*/) {
		return 3;
	}
	if (Player->getStamina() >= Player->requiredStamina(0, "df") && Opponent->getDefence() != 0) {
		return 2;
	}
	if (Player->getStamina() >= Player->requiredStamina(0, "hp") && Opponent->getHealth() != 0) {
		return 1;
	}
	else
		return 4;
}

void Battle(Unit* FirstPl, Unit* SecondPl) {
	int key_1 = 0;
	
	if (FirstPl->checkAutoAttack()) {
		key_1 = AutoAttack(FirstPl,SecondPl);
	}
	else {
		std::cout << "Choose your attack:" << std::endl;
		std::cout << "|" << "1 - Slice" << std::endl;
		std::cout << "Requires " << FirstPl->requiredStamina(0,"hp") << " stamina" << std::endl;
		std::cout << "Unit's stamina: " << FirstPl->getStamina() << std::endl;

		/*std::cout << "|" << std::setw(12) << std::setfill('_') << "2 - Rape";
		std::cout << std::setw(18) << std::setfill('_') << std::endl;
		std::cout << "Requires " << FirstPl->requiredStamina(0, "df") << " stamina" << std::endl;
		std::cout << "Unit's stamina: " << FirstPl->checkStamina();
		*/
		std::cout << "|" << "3 - Use Special Powers" << std::endl;
		std::cout << "Requires " << " inspiration" << std::endl;
		std::cout << "Unit's inspiration: " << FirstPl->getInspiration() << std::endl;
		std::cout << "|" << "4 - Skip" << std::endl;
		std::cin >> key_1;
	}

	std::cout << FirstPl->getType() << "'s turn!" << std::endl;

	switch (key_1)
    {
	case 1: {
		if (FirstPl->getStamina() <= FirstPl->requiredStamina(0, "hp")) {
			std::cout << "Unfortunately you haven't got enough STAMINA to attack." << std::endl;
			FirstPl->setStamina(100);
			break;
		}
		Attack* pl1_hit = FirstPl->Hit(0);
		Attack* pl2_hit = SecondPl->Hit(0);
		FirstPl->info();
		SecondPl->info();
		int pl_dmg;
		pl_dmg = pl1_hit->attack();
		pl2_hit->fendoff(pl_dmg);

		SecondPl->setStat(pl_dmg, pl2_hit->GetBaff());
		FirstPl->setStat(0, pl1_hit->GetBaff());

		FirstPl->info();
		SecondPl->info();

		FirstPl->setStamina(-1*pl1_hit->stamina_required("hp"));
		break; 
	}
	case 2:
		std::cout << "Player 1 Uses defence attack" << std::endl;
		break;
	case 3:
		std::cout << "Player 1 Uses skill" << std::endl;
		//FirstPl->setInspiration(/**/);
		FirstPl->setStamina(50);
		break;
	case 4:
		FirstPl->setStamina(100);
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

	Opponent->initUnit();
	Opponent->setAutoAttack(true);

	int init_pl = Player->setInitiative();
	int init_opp = Opponent->setInitiative();

	for (int i = 0; AnyAlive(Player, Opponent); ++i) {
		system("CLS");
		std::cout << "STEP #" << i + 1 << std::endl;
		if (init_pl > init_opp) {
			Battle(Player, Opponent);
			Battle(Opponent, Player);
		}
		else {
			Battle(Opponent, Player);
			Battle(Player, Opponent);
		}
		std::cout << "Press ENTER to CONTINUE" << std::endl;
		std::getchar();
		std::getchar();

	}

	//for (int i = 0; AnyAlive(Player, Opponent); ++i) {
	//	int pl_dmg, opp_dmg;
	//	std::cout << "Round #" << i + 1 << std::endl;
	//	Player->info();
	//	Opponent->info();

	//	std::cout << "Player attacks: " << std::endl;
	//	pl_dmg = pl_hit->attack();// player attacks;
	//	opp_hit->fendoff(pl_dmg);// opponent fends off;
	//	std::cout << "Opponent attacks: " << std::endl;
	//	opp_dmg = opp_hit->attack();// opponent attacks;
	//	pl_hit->fendoff(opp_dmg);// player fends off; 

	//	Opponent->SetStat(pl_dmg, opp_hit->GetBaff());
	//	Player->SetStat(opp_dmg, pl_hit->GetBaff());
	//}

	system("CLS");
	std::cout << "THE END OF FIGHT:" << std::endl;

	Player->info();
	Opponent->info();

}

/*Create five classes with special abilities.
  For now I can think of these:
  1. Warrior - specials: Rage, Multiple attack, etc
  2. Mage - specials: Power of Nature, Hilling, etc
  3. Defender - specials: Shield, Defend nearbyes, etc
  4. Paladin - specials: Blessing baff, Rising undead, etc
  5. Demon Slayer - specials: Calling for Dead, Cast a sucuub, etc
  
  Create a step-to-step attack:
  every character can use one of type of attacks
  1. Normal attack. (increases *inspiration*)
     Random special of weapon. (is included to 1.)
  2.Special class attack (requires amount of *inspiration*)
  3.Use a special item.
  Also you should choose the target of your attack - defence or health;
  Each attack requires the stamina, which grows on every step and 
  decreases with every attack;
  Attacking the defence requires less stamina than attacking health.
  Also there will be an initiation in attack(who strikes first), which defines by random;
  In summary we need to include three parametres to Unit class description:
  - stamina
  - inspiration
  - initiation
  

  Team attack:
  Summary initiative defines what team strikes first
  (how declare the first attack ???)
  Opponent's units are disposed in order of each unit initiative;
  Player's units are disposed in order defined by user;

  In each battle the order is defined by initiative, which counts second time for fighters;

  TODO: Add class system. Expand and improve Skills class;

  RAGE - Warrior skill:
  Increases STAMINA and all stats;

  POWER OF NATURE - Mage skill:
  Hills unit and makes damage to opponent;

  DOGS - Defender skill:
  Casts horde of dogs, who fight with player;

  RESSURECT - Paladin skill:
  Makes dead unit alive, with minimum HP;

  CURSE - Demon Slayer skill:
  Curses all opponent's team members;

  */

void Team_List(UnArr& Players) {
	for (int i = 0; i < Players.size(); ++i) {
		Players[i]->unitMenu();
	}
}

void Exclude_Dead(UnArr& Players) {
	for (int i = 0; i < Players.size(); ++i) {
		if (Players[i]->is_Dead()) {
			Players.erase(Players.begin() + i);
		}
	}
}

void Team_Battle(UnArr& FirstPl, UnArr& SecondPl) {
	for (int i = 0; i < FirstPl.size(); ++i) {
		if (FirstPl[i]->checkAutoAttack()) {
			int j;
			j = AutoAttack(SecondPl);
			Battle(FirstPl[i], SecondPl[j]); // First attacks, Second defence;
		}
		else {
			if (!FirstPl[i]->is_Dead()) {
				int j;
				std::cout << "Choose opponent to attack" << std::endl;
				std::cin >> j;
				Battle(FirstPl[i], SecondPl[j]); // First attacks, Second defence;
			}
			else 
				std::cout << "Unit is dead." << std::endl;
		}
	}
}

void TeamArena(Unit* Player) {
	std::vector <Unit*> Opponents;
	std::vector <Unit*> Players;
	int summ_pl = 0;
    int summ_opp = 0;
	int num_opp, num_pl, num_min, num_max;


	std::cout << "Hire your teammates!" << std::endl << "How much do you need?" << std::endl;
	std::cin >> num_pl;
	Players.resize(num_pl); 
	summ_pl = Player->setInitiative();
	for (int i = 0; i < num_pl; ++i) {
		int key;
		std::cout << "Choose your teammate #" << i + 1 << std::endl;
		list();
		std::cin >> key;
		create(key, &Players[i]);
		Players[i]->initUnit();
		summ_pl += Players[i]->setInitiative();
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
		Opponents[i]->initUnit();
		Opponents[i]->setAutoAttack(true);
		summ_opp += Opponents[i]->setInitiative();
	}

	
	std::cout << "Define the order in which your team will fight." << std::endl;
	for (int i = 0; i < Players.size(); ++i) {
		std::cout << "Player #" << i + 1 << std::endl;
		Players[i]->unitMenu();
		std::cout << std::endl;
	}
	for (int i = 0; i < Players.size(); ++i) {
		int k;
		std::cout << "Who goes #" << i+1  << "?" << std::endl;
		std::cin >> k;
		if (k < Players.size()) {
			std::swap(Players[i], Players[k]);
		}
		else
		{
			//exception 1;
		}
	}


	/*std::cout << "Define opponents to your teammates." << std::endl;
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
		Players[i]->unitMenu();

		std::cout << "Opponent #" << i + 1 << std::endl;
		Opponents[i]->unitMenu();
	}
	
	if (Opponents.size() > Players.size()) {
		for (int i = num_min; i < num_max; ++i) {
			std::cout << "Opponent #" << i + 1 << std::endl;
			Opponents[i]->unitMenu();
		}
	}
	else {
		for (int i = num_min; i < num_max; ++i) {
			std::cout << "Player #" << i + 1 << std::endl;
			Players[i]->unitMenu();
		}
	}
*/

	for (int i = 0; ; ++i) {
		Exclude_Dead(Players);
		Exclude_Dead(Opponents);

		if (summ_pl > summ_opp) {
			Team_Battle(Players, Opponents);
			Team_Battle(Opponents, Players);
		}
		else {
			Team_Battle(Opponents, Players);
			Team_Battle(Players, Opponents);
		}
	}


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

			u->unitMenu();
			std::cout << "Back to main menu: press e n t e r." << std::endl;

			std::getchar();
			if (std::getchar() == '\n') {
				MenuOn = 1;
			}
			else
				MenuOn = 0;
				break;
		case 2: // it. 2
			break;
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
