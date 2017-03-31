#include "Weapons.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <windows.h>
#include <random>

Buffs Attack::GetBaff() {
	return spec_eff;
}

int Attack::stamina_required(std::string type) {
	if (type == "hp") {
		return stamina_hp;
	}
	if (type == "df") {
		return stamina_df;
	}
}

Shield::Shield() : rd()
, mt(rd())
, dist(1, max_dmg)
, dist1(1, 100)
{
	stamina_hp = 100;
	stamina_df = 50;
	insp = 1;
}

int Shield::attack() {
	Buff* b;
	DMG = dist(mt);
	info();
	//b->Init_Buff(35,0,"st");
	//spec_eff.push_back(b);
	return DMG;
}

void Shield::fendoff(int damage) {
	Buff* b = new Buff;
	if (dist1(mt) > 50) {
		b->Init_Buff((damage * 5) / 10, 0, "hp");
		spec_eff.push_back(b);
		std::cout << "P R O T E C T E D" << std::endl;
	}
}

void Shield::info() {
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hstdout, &csbi);


	SetConsoleTextAttribute(hstdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	std::cout << "|_Attack___" << std::setw(10) << std::right << std::setfill('_') << "|_";
	std::cout << std::setw(3) << std::left << std::setfill('_') << DMG << "|";

	if (DMG < 90) {
		if (DMG <= 30) {
			std::cout << "weak" << std::endl;
		}
		if (DMG > 30 && DMG < 70) {
			SetConsoleTextAttribute(hstdout, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
			std::cout << "good" << std::endl;
		}
		if (DMG >= 70) {
			SetConsoleTextAttribute(hstdout, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			std::cout << "perfect" << std::endl;
		}


	}
	else {

		SetConsoleTextAttribute(hstdout, FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << "critical" << std::endl;
		std::cout << std::endl;
	}
	SetConsoleTextAttribute(hstdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	std::cout << std::endl;

}

Staff::Staff() : rd()
, mt(rd())
, dist(1, max_dmg)
, dist1(1, 100)
{
	//baff.resize(4);
	stamina_df = 30;
	stamina_hp = 50;
	insp = 3;
}

int Staff::attack() {
	Buff* b = new Buff;
	DMG = dist(mt);
	if (dist1(mt) > 40) {
		b->Init_Buff((DMG * 6) / 10, 0, "hp");
		std::cout << "H I L L I N G" << std::endl;

	}
	info();
	//baff[0] = 35;
	return DMG;
}

void Staff::fendoff(int damage) {
	//empty;
}

void Staff::info() {
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hstdout, &csbi);

	SetConsoleTextAttribute(hstdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	std::cout << "|_Attack___" << std::setw(10) << std::right << std::setfill('_') << "|_";
	std::cout << std::setw(3) << std::left << std::setfill('_') << DMG << "|";

	if (DMG < 90) {
		if (DMG <= 30) {
			std::cout << "weak" << std::endl;
		}
		if (DMG > 30 && DMG < 70) {
			SetConsoleTextAttribute(hstdout, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
			std::cout << "good" << std::endl;
		}
		if (DMG >= 70) {
			SetConsoleTextAttribute(hstdout, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			std::cout << "perfect" << std::endl;
		}


	}
	else {

		SetConsoleTextAttribute(hstdout, FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << "critical" << std::endl;
		std::cout << std::endl;
	}
	SetConsoleTextAttribute(hstdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	std::cout << std::endl;

}

Sword::Sword() : rd()
, mt(rd())
, dist(1, max_dmg)
, dist1(1, 100)
{
	//baff.resize(3);
	stamina_hp = 250;
	stamina_df = 100;
	insp = 2;
}

int Sword::attack() {
	if (dist1(mt) > 30) {
		DMG = 2 * dist(mt);
		std::cout << "C R I T I C A L S T R I K E" << std::endl;
	}
	else
		DMG = dist(mt);
	info();
	//baff[0] = 35;
	return DMG;
}

void Sword::fendoff(int damage) {
	//empty;
}

void Sword::info() {
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hstdout, &csbi);

	SetConsoleTextAttribute(hstdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	std::cout << "|_Attack___" << std::setw(10) << std::right << std::setfill('_') << "|_";
	std::cout << std::setw(3) << std::left << std::setfill('_') << DMG << "|";

	if (DMG < 90) {
		if (DMG <= 30) {
			std::cout << "weak" << std::endl;
		}
		if (DMG > 30 && DMG < 70) {
			SetConsoleTextAttribute(hstdout, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
			std::cout << "good" << std::endl;
		}
		if (DMG >= 70) {
			SetConsoleTextAttribute(hstdout, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			std::cout << "perfect" << std::endl;
		}


	}
	else {

		SetConsoleTextAttribute(hstdout, FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << "critical" << std::endl;
		std::cout << std::endl;
	}
	SetConsoleTextAttribute(hstdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	std::cout << std::endl;

}

