#include "Weapons.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <windows.h>
#include <random>

std::vector <int> Attack::GetBaff() {
	return baff;
}

Shield::Shield() : rd()
, mt(rd())
, dist(1, 30)
, dist1(1, 100)
{
	baff.resize(3);
}

int Shield::attack() {
	DMG = dist(mt);
	info();
	return DMG;
}

void Shield::fendoff(int damage) {
	if (dist1(mt) > 50) {
		baff[0] = (damage * 5) / 10;
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

Spell::Spell() : rd()
, mt(rd())
, dist(1, 20)
, dist1(1, 100)
{
	baff.resize(3);
}

int Spell::attack() {
	DMG = dist(mt);
	if (dist1(mt) > 40) {
		baff[0] = (DMG * 6) / 10;
		std::cout << "H I L L I N G" << std::endl;

	}
	info();
	return DMG;
}

void Spell::fendoff(int damage) {
	//empty;
}

void Spell::info() {
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

Rage::Rage() : rd()
, mt(rd())
, dist(1, 50)
, dist1(1, 100)
{
	baff.resize(3);
}

int Rage::attack() {
	if (dist1(mt) > 30) {
		DMG = 2 * dist(mt);
		std::cout << "C R I T I C A L S T R I K E" << std::endl;
	}
	else
		DMG = dist(mt);
	info();
	return DMG;
}

void Rage::fendoff(int damage) {
	//empty;
}

void Rage::info() {
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

