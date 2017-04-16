#include "Unit.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <windows.h>
#include <random>

void Unit::initUnit() {
	
}

int Unit::getHealth() {
	return HP;
}

int Unit::getDefence() {
	return DF;
}

int Unit::getInspiration() {
	return battle_stats[2];
}

int Unit::requiredInspiration() {
	return required_insp;
}

void Unit::setInspiration(int eff) {
	if (battle_stats[2] > 0) {
		battle_stats[2] -= eff;
	}
}

bool Unit::is_Dead() {
	return (HP <= 0);
}

void Unit::addAffection(Buffs& buff_) {
	spec_Aff.insert(spec_Aff.end(), buff_.begin(), buff_.end());
}

void Unit::addEffect(Buffs& buff_) {
	spec_Eff.insert(spec_Eff.end(), buff_.begin(), buff_.end());
}

Buffs Unit::getAffects() {
	return spec_Aff;
}

Buffs Unit::getEffects() {
	return spec_Eff;
}

void Unit::setName() {
	std::cout << "What is your name adventurer?" << std::endl;
	std::cin >> name;
}

void Unit::setAutoAttack(bool on) {
	if (on) {
		type += " bot";
	}
	else {
		int i = type.find(" ");
		type.erase(type.begin() + i, type.end());
	}
}

bool Unit::checkAutoAttack() {
	std::size_t f = type.find(" bot");
	if (f != std::string::npos) {
		return true;
	}
	else
		return false;

}

void Unit::useEffect(Buff& buff_) {
	if (buff_.Return_Type() == "hp") {
		buff_.Apply_Effect(&HP);
	}
	if (buff_.Return_Type() == "df") {
		buff_.Apply_Effect(&DF);
	}
	if (buff_.Return_Type() == "st") {
		buff_.Apply_Effect(&battle_stats[1]);
	}
}

void Unit::setStat(int damage, Buffs& buff_, int mode) {
	HP -= damage;

	if (!buff_.empty()) {
		for (int i = 0; i < buff_.size(); ++i) {
			if (!buff_[i]->Return_Status()) {
				spec_Eff.push_back(buff_[i]);
				buff_[i]->~Buff();
				buff_.erase(buff_.begin() + i);
			}
		}
	}
	for (int i = 0; i < spec_Eff.size(); ++i) {
		// applying buffs to unit;
		if (spec_Eff[i]->Is_On()) {
			useEffect(*spec_Eff[i]);

		}
		else {
			// when buff's effects end we delete them from vector of buffs; 
			spec_Eff[i]->~Buff();
			spec_Eff.erase(spec_Eff.begin() + i);
			i--;
		}
	}


}

std::string Unit::getType() {
	return type;
}

void Unit::info() {
		HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo(hstdout, &csbi);
		std::cout << "|_";
		SetConsoleTextAttribute(hstdout, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << type;
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


		if (DF < 50) {
			if (DF < 30) {
				std::cout << "|_DefencePoints_" << std::setw(6) << std::right << std::setfill('_') << "|_";
				std::cout << std::setw(3) << std::left << std::setfill('_') << DF << "|";
				SetConsoleTextAttribute(hstdout, FOREGROUND_RED | FOREGROUND_INTENSITY);
				if (HP > 0) {
					for (int i = 0; i < DF; i = i + 10) {
						std::cout << InfoBlock;
					}
				}
				else
					std::cout << "dead";
				std::cout << std::endl;
			}
			else {
				std::cout << "|_DefencePoints_" << std::setw(6) << std::right << std::setfill('_') << "|_";
				std::cout << std::setw(3) << std::left << std::setfill('_') << HP << "|";
				SetConsoleTextAttribute(hstdout, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
				for (int i = 0; i < HP; i = i + 10) {
					std::cout << InfoBlock;
				}
				std::cout << std::endl;
			}
		}
		else {
			std::cout << "|_DefencePoints_" << std::setw(6) << std::right << std::setfill('_') << "|_";
			std::cout << std::setw(3) << std::left << std::setfill('_') << DF << "|";
			SetConsoleTextAttribute(hstdout, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			for (int i = 0; i < DF; i = i + 10) {
				std::cout << InfoBlock;
			}
			std::cout << std::endl;
		}


		SetConsoleTextAttribute(hstdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		std::cout << std::endl;

}

int Unit::getStamina() {
	return battle_stats[1];
}

void Unit::setStamina(int eff) {
	battle_stats[1] += eff;
}

int Unit::requiredStamina(int i, std::string type) {
	if (type == "hp") {
		return gear[i]->stamina_required(type);
	}

	if (type == "df") {
		return gear[i]->stamina_required(type);
	}
	return 0;
}

void Unit::unitMenu() {
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

void Paladin::initUnit() {
	Shield* weapon = new Shield;
	type = "Paladin";
	HP = 300;
	DF = 150;
	level = 0;
	init_max = 25;
	battle_stats.resize(3);
	battle_stats[0] = 1;// start initiation;
	battle_stats[1] = 500;// start stamina; 
	battle_stats[2] = 0;// start inspiration, max = 10;
	spec_ab = { 1,3,7 };
	gear.push_back(weapon);

}

void Paladin::setStat(int damage, Buffs& buff_, int mode) {
	std::mt19937 gen(std::random_device().operator()());
	std::uniform_int_distribution<> dist1(1, 100);

	if (DF <= 0 || mode == 1) {
		HP -= damage;
	}
	else {
		DF -= damage;
		if (DF < 0) 
			DF = 0;
	}
	if (dist1(gen) > 50 && damage != 0) {
		Buff* b = new Buff;
		std::cout << type << " hills his teammates!" << std::endl;
		std::cout << "Hills " << damage / 2 << " points" << std::endl;
		b->Init_Buff(damage / 2, 1, "hp", false);
		spec_Aff.push_back(b);
	}


	if (!buff_.empty()) {
		for (int i = 0; i < buff_.size(); ++i) {
			if (!buff_[i]->Return_Status()) {
				spec_Eff.push_back(buff_[i]);
				buff_[i]->~Buff();
				buff_.erase(buff_.begin() + i);
			}
		}
	}



	for (int i = 0; i < spec_Eff.size(); ++i) {
		// applying buffs to unit;
		if (spec_Eff[i]->Is_On()) {
			useEffect(*spec_Eff[i]);

		}
		else {
			// when buff's effects end we delete them from vector of buffs; 
			spec_Eff[i]->~Buff();
			spec_Eff.erase(spec_Eff.begin() + i);
			i--;
		}
	}


}

int Paladin::setInitiative() {
	std::mt19937 gen(std::random_device().operator()());
	std::uniform_int_distribution<> dist(1, init_max);

	return dist(gen);
}

// NOT IMPLEMENTED YET!!!

//Skills* Paladin::LearnSkill() {
//	if (level == spec_ab[0]) {
//		//return new Blessing;
//	}
//	if (level == spec_ab[1]) {
//
//	}
//	if (level == spec_ab[2]) {
//
//	}
//}

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

void Wizard::initUnit() {
	Staff* weapon = new Staff;
	type = "Wizard";
	HP = 100;
	DF = 50;
	level = 0;
	init_max = 20;
	battle_stats.resize(3);
	battle_stats[0] = 1;
	battle_stats[1] = 500;
	battle_stats[2] = 3; //start inspiration, max = 10;
	spec_ab = { 1,3,6 };
	gear.push_back(weapon);
}

void Wizard::setStat(int damage, Buffs& buff_, int mode) {
	int hill;
	std::mt19937 gen(std::random_device().operator()());
	std::uniform_int_distribution<> dist1(1, 100);
	
	if (DF == 0 || mode == 1) {
		HP -= damage;
	}
	else
		DF -= damage;
	    
	if ((hill = dist1(gen)) > 40) {
		std::cout << "Wizard hills himself" << std::endl;
		std::cout << "Health increases on " << hill << " points" << std::endl;
		HP += hill;
	}

	if (!buff_.empty()) {
		for (int i = 0; i < buff_.size(); ++i) {
			if (!buff_[i]->Return_Status()) {
				spec_Eff.push_back(buff_[i]);
				buff_[i]->~Buff();
				buff_.erase(buff_.begin() + i);
			}
		}
	}

	for (int i = 0; i < spec_Eff.size(); ++i) {
		// applying buffs to unit;
		if (spec_Eff[i]->Is_On()) {
			useEffect(*spec_Eff[i]);

		}
		else {
			// when buff's effects end we delete them from vector of buffs; 
			spec_Eff[i]->~Buff();
			spec_Eff.erase(spec_Eff.begin() + i);
			i--;
		}
	}

}

int Wizard::setInitiative() {
	std::mt19937 gen(std::random_device().operator()());
	std::uniform_int_distribution<> dist(1, init_max);

	return dist(gen);
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

//Skills* Wizard::LearnSkill() {
//	if (level == spec_ab[0]) {
//	//	return new FireBall;
//	}
//	if (level == spec_ab[1]) {
//
//	}
//	if (level == spec_ab[2]) {
//
//	}
//}

//Attack* Wizard::Hit(int i) {
//	replica();
//	return gear[i];
//}

void Berserk::initUnit() {
	Sword* weapon = new Sword;
	type = "Berserk";
	HP = 100;
	DF = 100;
	level = 0;
	init_max = 30;
	battle_stats.resize(3);
	battle_stats[0] = 1;
	battle_stats[1] = 500;
	battle_stats[2] = 0; // start inspiration, max = 10;
	spec_ab = { 1,4,5 };
	gear.push_back(weapon);
}

void Berserk::setStat(int damage, Buffs& buff_, int mode) {
	std::mt19937 gen(std::random_device().operator()());
	std::uniform_int_distribution<> dist1(1, 100);

	if (dist1(gen) < 70) {
		if (DF <= 0 || mode == 1) {
			HP -= damage;
		}
		else {
			DF -= damage;
			if (DF < 0)
				DF = 0;
		}
	}
	else
		std::cout << type << " reflected all damage!" << std::endl;

	if (!buff_.empty()) {
		for (int i = 0; i < buff_.size(); ++i) {
			if (!buff_[i]->Return_Status()) {
				spec_Eff.push_back(buff_[i]);
				buff_[i]->~Buff();
				buff_.erase(buff_.begin() + i);
			}
		}
	}
	for (int i = 0; i < spec_Eff.size(); ++i) {
		// applying buffs to unit;
		if (spec_Eff[i]->Is_On()) {
			useEffect(*spec_Eff[i]);

		}
		else {
			// when buff's effects end we delete them from vector of buffs; 
			spec_Eff[i]->~Buff();
			spec_Eff.erase(spec_Eff.begin() + i);
			i--;
		}
	}

}

int Berserk::setInitiative() {
	std::mt19937 gen(std::random_device().operator()());
	std::uniform_int_distribution<> dist(1, init_max);
	return dist(gen);
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

//Skills* Berserk::LearnSkill() {
//	if (level == spec_ab[0]) {
//	//	return new Rage;
//	}
//	if (level == spec_ab[1]) {
//
//	}
//	if (level == spec_ab[2]) {
//
//	}
//}

//Attack* Berserk::Hit(int i) {
//	replica();
//	if (i > gear.size()) {
//		return 0;
//	}
//	else
//	return gear[i];
//}

void Defender::initUnit() {
	Sword* weapon = new Sword;
	type = "Defender";
	HP = 100;
	DF = 300;
	level = 0;
	init_max = 30;
	battle_stats.resize(3);
	battle_stats[0] = 1;
	battle_stats[1] = 500;
	battle_stats[2] = 0; // start inspiration, max = 10;
	spec_ab = { 1,4,5 };
	gear.push_back(weapon);

}

void Defender::setStat(int damage, Buffs& buff_, int mode) {
	std::mt19937 gen(std::random_device().operator()());
	std::uniform_int_distribution<> dist1(1, 100);

	if (dist1(gen) > 25) {
		std::cout << "P R O T E C T E D !" << std::endl;
		std::cout << type << " got " << (damage * 25) / 100 << " damage!" << std::endl;
		if (DF <= 0 || mode == 1) {
			HP -= (damage * 25) / 100;
		}
		else {
			DF -= (damage * 25) / 100;
			if (DF < 0)
				DF = 0;
		}
	}

	if (!buff_.empty()) {
		for (int i = 0; i < buff_.size(); ++i) {
			if (!buff_[i]->Return_Status()) {
				spec_Eff.push_back(buff_[i]);
				buff_[i]->~Buff();
				buff_.erase(buff_.begin() + i);
			}
		}
	}
	
	for (int i = 0; i < spec_Eff.size(); ++i) {
		// applying buffs to unit;
		if (spec_Eff[i]->Is_On()) {
			useEffect(*spec_Eff[i]);

		}
		else {
			// when buff's effects end we delete them from vector of buffs; 
			spec_Eff[i]->~Buff();
			spec_Eff.erase(spec_Eff.begin() + i);
			i--;
		}
	}


}

int Defender::setInitiative() {
	std::mt19937 gen(std::random_device().operator()());
	std::uniform_int_distribution<> dist(1, init_max);
	return dist(gen);
}

void Defender::replica() {
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hstdout, &csbi);

	SetConsoleTextAttribute(hstdout, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "Defender get P R O T E C T I O N !" << std::endl;

	SetConsoleTextAttribute(hstdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	std::cout << std::endl;

}

void DemonSlayer::initUnit() {
	Staff* weapon = new Staff;
	type = "DemonSlayer";
	HP = 100;
	DF = 50;
	level = 0;
	init_max = 25;

	//std::uniform_int_distribution<std::mt19937::result_type> dist(1, init_max);

	battle_stats.resize(3);
	battle_stats[0] = 1;
	battle_stats[1] = 500;
	battle_stats[2] = 3; // start inspiration, max = 10;
	spec_ab = { 1,4,5 };
	gear.push_back(weapon);

}

void DemonSlayer::setStat(int damage, Buffs& buff_, int mode) {
	std::mt19937 gen(std::random_device().operator()());
	std::uniform_int_distribution<> dist1(1, 100);

	if (dist1(gen) > 50) {
		Debuff* b = new Debuff;
		if (DF <= 0 || mode == 1) {
			HP -= damage;
		}
		else {
			DF -= damage;
			if (DF < 0)
				DF = 0;
		}
		std::cout << type << " is protected by black magic!" << std::endl;
		std::cout << "He makes enemy's weapon to strike back!" << std::endl;
		b->Init_Buff(damage, 1, "hp",true);
		spec_Aff.push_back(b);
	}

	if (!buff_.empty()) {
		for (int i = 0; i < buff_.size(); ++i) {
			if (!buff_[i]->Return_Status()) {
				spec_Eff.push_back(buff_[i]);
				buff_[i]->~Buff();
				buff_.erase(buff_.begin() + i);
			}
		}
	}

	for (int i = 0; i < spec_Eff.size(); ++i) {
		// applying buffs to unit;
		if (spec_Eff[i]->Is_On()) {
			useEffect(*spec_Eff[i]);

		}
		else {
			// when buff's effects end we delete them from vector of buffs; 
			spec_Eff[i]->~Buff();
			spec_Eff.erase(spec_Eff.begin() + i);
			i--;
		}
	}
}

int DemonSlayer::setInitiative() {
	std::mt19937 gen(std::random_device().operator()());
	std::uniform_int_distribution<> dist(1, init_max);
	return dist(gen);
}

void DemonSlayer::replica() {
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hstdout, &csbi);

	SetConsoleTextAttribute(hstdout, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "Demon Slayer is possesed by D E M O N S !" << std::endl;

	SetConsoleTextAttribute(hstdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	std::cout << std::endl;

}

void DemonSlayer::useSkill() {

}