#include "Unit.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <windows.h>
#include <random>

void Unit::InitUnit() {
	HP = 250;
	DF = 100;

}

int Unit::getHealth() {
	return HP;
}

void Unit::SetStat(int damage, std::vector<int> &baff) {
	HP -= damage;
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

void Paladin::InitUnit() {
	type = "Paladin";
	std::cout << "What is your name adventurer?" << std::endl;
	std::cin >> name;
	HP = 300;
	DF = 150;
	level = 0;
	init_max = 25;
	battle_stats.resize(3);
	battle_stats[0] = 1;
	battle_stats[1] = 100;
	battle_stats[2] = 100;
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

void Paladin::SetStat(int damage, std::vector<int> &baff) {
	HP -= damage;
	if (baff[0]) {
		HP += baff[0];
	}
	if (baff[1]) {
		HP *= baff[1];
	}
	if (baff[2]) {
		//something special *_*
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

Attack* Paladin::Hit() {
	replica();
	return new Shield();
}

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

void Wizard::SetStat(int damage, std::vector<int> &baff) {
	HP -= damage;
	if (baff[0]) {
		HP += baff[0];
	}
	if (baff[1]) {
		HP *= baff[1];
	}
	if (baff[2]) {
	//something special ^_^
	}
}


Attack* Wizard::Hit() {
	replica();
	return new Spell();
}

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

void Berserk::SetStat(int damage, std::vector<int> &baff) {
	HP -= damage;
	if (baff[0]) {
		HP += baff[0];
	}
	if (baff[1]) {
		HP *= baff[1];
	}
	if (baff[2]) {
		//something special <3
	}
}

Attack* Berserk::Hit() {
	replica();
	return new Rage();
}

