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

int count_nums(const int num) {
	int digits = num;
	int i;
	if (num) {
		if (num < 0) {
			i = 1;
		}
		else
			i = 0;

		for (i; digits; ++i) {
			digits /= 10;
		}
		return i;
	}
	else
	return 1;

}

void Dwarf::InitUnit() {
	type = "Dwarf";
	HP = 300;
	DF = 150;
	level = 0;
}

void Dwarf::info(){
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hstdout, &csbi);
	std::cout << "|_";
	SetConsoleTextAttribute(hstdout, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "Dwarf";
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

void Dwarf::SetStat(int damage, std::vector<int> &baff) {
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

void Dwarf::UnitMenu() {
	int n = 24;
	int health_size = 6;
	int defence_size = 7;
	int level_size = 5;
	std::cout << " " << std::setw(2*n) << std::right << std::setfill('_') << " " << std::endl;
	std::cout << "|" << std::setw(n) << std::right << std::setfill('_');
	std::cout << type;
	std::cout << std::setw(n) << std::right << std::setfill('_') <<  "|" << std::endl;
	std::cout << "|" << std::setw(2*n) << std::right << std::setfill('_') << "|" << std::endl;

	std::cout << "|_Health";
	std::cout << std::setw(n - health_size) << std::right << std::setfill('_') << "|";
	std::cout << "___" << HP;
	health_size = count_nums(HP);
	std::cout << std::setw(n - health_size - 4) << std::right << std::setfill('_') << "|" << std::endl;

	std::cout << "|_Defence";
	std::cout << std::setw(n - defence_size) << std::right << std::setfill('_') << "|";
	std::cout << "___";
	std::cout << DF;
	defence_size = count_nums(DF);
	std::cout << std::setw(n - defence_size - 4) << std::right << std::setfill('_') << "|" << std::endl;
    
	std::cout << "|_Level";
	std::cout << std::setw(n - level_size) << std::right << std::setfill('_') << "|";
	std::cout << "___";
	std::cout << level;
	level_size = count_nums(level);
	std::cout << std::setw(n - level_size - 4) << std::right << std::setfill('_') << "|" << std::endl;

	std::cout << "|" << std::setw(2 * n) << std::right << std::setfill('_') << "|" << std::endl;
}

void Dwarf::replica() {
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hstdout, &csbi);

	SetConsoleTextAttribute(hstdout, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "Dwarf gets S h i e l d !" << std::endl;

	SetConsoleTextAttribute(hstdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	std::cout << std::endl;

}

Attack* Dwarf::Hit() {
	replica();
	return new Shield();
}

void Wizard::InitUnit() {
	type = "Wizard";
	HP = 250;
	DF = 50;
	level = 0;
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

void Wizard::UnitMenu() {
	std::cout << type;
	std::cout << HP;
	std::cout << DF;
	std::cout << level;

}

Attack* Wizard::Hit() {
	replica();
	return new Spell();
}

void Orc::InitUnit() {
	type = "Orc";
	HP = 350;
	DF = 100;
	level = 0;
}

void Orc::info() {
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hstdout, &csbi);
	std::cout << "|_";
	SetConsoleTextAttribute(hstdout, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "Orc";
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

void Orc::replica() {
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hstdout, &csbi);

	SetConsoleTextAttribute(hstdout, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "Orc is full of R A G E !" << std::endl;

	SetConsoleTextAttribute(hstdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	std::cout << std::endl;

}

void Orc::SetStat(int damage, std::vector<int> &baff) {
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

void Orc::UnitMenu() {
	std::cout << type;
	std::cout << HP;
	std::cout << DF;
	std::cout << level;

}

Attack* Orc::Hit() {
	replica();
	return new Rage();
}

