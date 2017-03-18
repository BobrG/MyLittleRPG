#include "Unit.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <windows.h>
#include <random>

void Unit::InitUnit() {
	
}

int Unit::getHealth() {
	return HP;
}

bool Unit::is_Dead() {
	return (HP <= 0);
}

void Unit::SetStat(int damage, const Buff& buff_) {
	HP -= damage;

	buff.push_back(buff_);
	
	for (int i = 0; i < buff.size(); ++i) {
		// applying buffs to unit;
		if (buff[i].Is_On()) {
			if (buff[i].Return_Type() == "hp") {
				buff[i].Apply_Effect(HP);
			}
			if (buff[i].Return_Type() == "df") {
				buff[i].Apply_Effect(DF);
			}
			if (buff[i].Return_Type() == "st") {
				buff[i].Apply_Effect(battle_stats[1]);
			}
		}
		else {
			// when buff's effects end we delete them from vector of buffs; 
			buff[i].~Buff();
			buff.erase(buff.begin() + i);
		}
	}

}


void Unit::UnitMenu() {
	int n = 24;
	std::string temp;
	std::cout << " " << std::setw(2 * n) << std::right << std::setfill('_') << " " << std::endl;
	std::cout << "|" << std::setw(n) << std::right << std::setfill('_');
	std::cout << type;
	std::cout << std::setw(n) << std::right << std::setfill('_') << "|" << std::endl;
	std::cout << "|" << std::setw(2 * n) << std::right << std::setfill('_') << "|" << std::endl;

	std::cout << "|" << std::setw(n) << std::right << std::setfill('_');
	std::cout << name;
	std::cout << std::setw(n) << std::right << std::setfill('_') << "|" << std::endl;
	std::cout << "|" << std::setw(2 * n) << std::right << std::setfill('_') << "|" << std::endl;

	temp = "Health";
	std::cout << "|_" << temp;
	std::cout << std::setw(n - temp.size()) << std::right << std::setfill('_') << "|";
	if (HP <= 0) {
		temp = "dead";
		std::cout << "___" << temp;
	}
	else {
		std::cout << "___" << HP;
		temp = std::to_string(HP);
	}
	std::cout << std::setw(n - temp.size() - 4) << std::right << std::setfill('_') << "|" << std::endl;

	temp = "Defence";
	std::cout << "|_" << temp;
	std::cout << std::setw(n - temp.size()) << std::right << std::setfill('_') << "|";
	std::cout << "___";
	std::cout << DF;
	temp = std::to_string(DF);
	std::cout << std::setw(n - temp.size() - 4) << std::right << std::setfill('_') << "|" << std::endl;

	temp = "Level";
    std::cout << "|_" << temp;
	std::cout << std::setw(n - temp.size()) << std::right << std::setfill('_') << "|";
	std::cout << "___";
	std::cout << level;
	temp = std::to_string(level);
	std::cout << std::setw(n - temp.size() - 4) << std::right << std::setfill('_') << "|" << std::endl;

	temp = "Initiative";
	std::cout << "|_" << temp;
	std::cout << std::setw(n - temp.size()) << std::right << std::setfill('_') << "|";
	std::cout << "___";
	std::cout << init_max;
	temp = std::to_string(init_max);
	std::cout << std::setw(n - temp.size() - 4) << std::right << std::setfill('_') << "|" << std::endl;


	temp = "Stamina";
	std::cout << "|_" << temp;
	std::cout << std::setw(n - temp.size()) << std::right << std::setfill('_') << "|";
	std::cout << "___";
	std::cout << battle_stats[1];
	temp = std::to_string(battle_stats[1]);
	std::cout << std::setw(n - temp.size() - 4) << std::right << std::setfill('_') << "|" << std::endl;

	temp = "Inspiration"; 
	std::cout << "|_" << temp;
	std::cout << std::setw(n - temp.size()) << std::right << std::setfill('_') << "|";
	std::cout << "___";
	std::cout << battle_stats[2];
	temp = std::to_string(battle_stats[2]);
	std::cout << std::setw(n - temp.size() - 4) << std::right << std::setfill('_') << "|" << std::endl;
	
	std::cout << "|" << std::setw(2 * n) << std::right << std::setfill('_') << "|" << std::endl;
}

Attack* Unit::Hit(int i) {
	replica();
	if (i > gear.size()) {
		return 0;
	}
	else
	return gear[i];
}

void Paladin::InitUnit() {
	type = "Paladin";
	std::cout << "What is your name adventurer?" << std::endl;
	std::cin >> name;
	HP = 300;
	DF = 150;
	level = 0;
	init_max = 25;
	battle_stats.resize(3);
	battle_stats[0] = 1;// start initiation;
	battle_stats[1] = 100;// start stamina; 
	battle_stats[2] = 100;// start inspiration;
	spec_ab = { 1,3,7 };
	gear.resize(1);

}

int Paladin::setInitiative() {
	std::random_device rd;
	std::mt19937 mt;
	std::uniform_int_distribution<int> dist(1, init_max);
	return dist(mt);
}

void Paladin::info(){
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hstdout, &csbi);
	std::cout << "|_";
	SetConsoleTextAttribute(hstdout, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "Paladin";
	SetConsoleTextAttribute(hstdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	std::cout << std::setw(13) << std::right << std::setfill('_') << "|";
	std::cout << std::setw(48) << std::right << std::setfill('_') << "|" << std::endl;

	if (HP < 50) {
		if (HP < 30) {
			std::cout << "|_HealthPoints_" << std::setw(6) << std::right << std::setfill('_') << "|_";
			std::cout << std::setw(3) << std::left << std::setfill('_') << HP << "|";
			SetConsoleTextAttribute(hstdout, FOREGROUND_RED | FOREGROUND_INTENSITY);
			if (HP > 0) {
				for (int i = 0; i < HP; i = i + 10) {
					std::cout << InfoBlock;
				}
			}
			else
				std::cout << "dead";
			std::cout << std::endl;
		}
		else {
			std::cout << "|_HealthPoints_" << std::setw(6) << std::right << std::setfill('_') << "|_";
			std::cout << std::setw(3) << std::left << std::setfill('_') << HP << "|";
			SetConsoleTextAttribute(hstdout, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
			for (int i = 0; i < HP; i = i + 10) {
				std::cout << InfoBlock;
			}
			std::cout << std::endl;
		}
	}
	else {
		std::cout << "|_HealthPoints_" << std::setw(6) << std::right << std::setfill('_') << "|_";
		std::cout << std::setw(3) << std::left << std::setfill('_') << HP << "|";
		SetConsoleTextAttribute(hstdout, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		for (int i = 0; i < HP; i = i + 10) {
			std::cout << InfoBlock;
		}
		std::cout << std::endl;
	}
	

	SetConsoleTextAttribute(hstdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	std::cout << std::endl;
}

// NOT IMPLEMENTED YET!!!

Skills* Paladin::LearnSkill() {
	if (level == spec_ab[0]) {
		return new Blessing;
	}
	if (level == spec_ab[1]) {

	}
	if (level == spec_ab[2]) {

	}
}

void Paladin::replica() {
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hstdout, &csbi);

	SetConsoleTextAttribute(hstdout, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "Paladin gets S h i e l d !" << std::endl;

	SetConsoleTextAttribute(hstdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	std::cout << std::endl;

}

//Attack* Paladin::Hit(int i) {
//	replica();
//	return new Shield();
//}

void Wizard::InitUnit() {
	type = "Wizard";
	std::cout << "What is your name adventurer?" << std::endl;
	std::cin >> name;
	HP = 250;
	DF = 50;
	level = 0;
	init_max = 20;
	battle_stats.resize(3);
	battle_stats[0] = 1;
	battle_stats[1] = 100;
	battle_stats[2] = 100;
	spec_ab = { 1,3,6 };
	gear.resize(1);
	Staff* obj;
	gear[0] = obj;

}

int Wizard::setInitiative() {
	std::random_device rd;
	std::mt19937 mt;
	std::uniform_int_distribution<int> dist(1, init_max);
	return dist(mt);
}

void Wizard::info() {
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hstdout, &csbi);
	std::cout << "|_";
	SetConsoleTextAttribute(hstdout, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "Wizard";
	SetConsoleTextAttribute(hstdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	std::cout << std::setw(13) << std::right << std::setfill('_') << "|";
	std::cout << std::setw(48) << std::right << std::setfill('_') << "|" << std::endl;

	if (HP < 50) {
		if (HP < 30) {
			std::cout << "|_HealthPoints_" << std::setw(6) << std::right << std::setfill('_') << "|_";
			std::cout << std::setw(3) << std::left << std::setfill('_') << HP << "|";
			SetConsoleTextAttribute(hstdout, FOREGROUND_RED | FOREGROUND_INTENSITY);
			if (HP > 0) {
				for (int i = 0; i < HP; i = i + 10) {
					std::cout << InfoBlock;
				}
			}
			else
				std::cout << "dead";
			std::cout << std::endl;
		}
		else {
			std::cout << "|_HealthPoints_" << std::setw(6) << std::right << std::setfill('_') << "|_";
			std::cout << std::setw(3) << std::left << std::setfill('_') << HP << "|";
			SetConsoleTextAttribute(hstdout, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
			for (int i = 0; i < HP; i = i + 10) {
				std::cout << InfoBlock;
			}
			std::cout << std::endl;
		}
	}
	else {
		std::cout << "|_HealthPoints_" << std::setw(6) << std::right << std::setfill('_') << "|_";
		std::cout << std::setw(3) << std::left << std::setfill('_') << HP << "|";
		SetConsoleTextAttribute(hstdout, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		for (int i = 0; i < HP; i = i + 10) {
			std::cout << InfoBlock;
		}
		std::cout << std::endl;
	}


	SetConsoleTextAttribute(hstdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	std::cout << std::endl;

}

void Wizard::replica() {
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hstdout, &csbi);

	SetConsoleTextAttribute(hstdout, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	std::cout << "Wizard casts S P E L L !" << std::endl;

	SetConsoleTextAttribute(hstdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	std::cout << std::endl;

}

Skills* Wizard::LearnSkill() {
	if (level == spec_ab[0]) {
		return new FireBall;
	}
	if (level == spec_ab[1]) {

	}
	if (level == spec_ab[2]) {

	}
}

//Attack* Wizard::Hit(int i) {
//	replica();
//	return gear[i];
//}

void Berserk::InitUnit() {
	type = "Berserk";
	std::cout << "What is your name adventurer?" << std::endl;
	std::cin >> name;
	HP = 350;
	DF = 100;
	level = 0;
	init_max = 30;
	battle_stats.resize(3);
	battle_stats[0] = 1;
	battle_stats[1] = 100;
	battle_stats[2] = 100;
	spec_ab = { 1,4,5 };
	gear.resize(1);
	Sword* obj;
	gear[0] = obj;
}

int Berserk::setInitiative() {
	std::random_device rd;
	std::mt19937 mt;
	std::uniform_int_distribution<int> dist(1, init_max);
	return dist(mt);
}

void Berserk::info() {
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hstdout, &csbi);
	std::cout << "|_";
	SetConsoleTextAttribute(hstdout, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "Berserk";
	SetConsoleTextAttribute(hstdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	std::cout << std::setw(15) << std::right << std::setfill('_') << "|";
	std::cout << std::setw(48) << std::right << std::setfill('_') << "|" << std::endl;

	if (HP < 50) {
		if (HP < 30) {
			std::cout << "|_HealthPoints_" << std::setw(6) << std::right << std::setfill('_') << "|_";
			std::cout << std::setw(3) << std::left << std::setfill('_') << HP << "|";
			SetConsoleTextAttribute(hstdout, FOREGROUND_RED | FOREGROUND_INTENSITY);
			if (HP > 0) {
				for (int i = 0; i < HP; i = i + 10) {
					std::cout << InfoBlock;
				}
			}
			else
				std::cout << "dead";
			std::cout << std::endl;
		}
		else {
			std::cout << "|_HealthPoints_" << std::setw(6) << std::right << std::setfill('_') << "|_";
			std::cout << std::setw(3) << std::left << std::setfill('_') << HP << "|";
			SetConsoleTextAttribute(hstdout, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
			for (int i = 0; i < HP; i = i + 10) {
				std::cout << InfoBlock;
			}
			std::cout << std::endl;
		}
	}
	else {
		std::cout << "|_HealthPoints_" << std::setw(6) << std::right << std::setfill('_') << "|_";
		std::cout << std::setw(3) << std::left << std::setfill('_') << HP << "|";
		SetConsoleTextAttribute(hstdout, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		for (int i = 0; i < HP; i = i + 10) {
			std::cout << InfoBlock;
		}
		std::cout << std::endl;
	}


	SetConsoleTextAttribute(hstdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	std::cout << std::endl;

}

void Berserk::replica() {
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hstdout, &csbi);

	SetConsoleTextAttribute(hstdout, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "Berserk is full of R A G E !" << std::endl;

	SetConsoleTextAttribute(hstdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	std::cout << std::endl;

}

// NOT IMPLEMENTED YET!!!

Skills* Berserk::LearnSkill() {
	if (level == spec_ab[0]) {
		return new Rage;
	}
	if (level == spec_ab[1]) {

	}
	if (level == spec_ab[2]) {

	}
}

//Attack* Berserk::Hit(int i) {
//	replica();
//	if (i > gear.size()) {
//		return 0;
//	}
//	else
//	return gear[i];
//}

