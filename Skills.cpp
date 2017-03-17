
#include <string>
#include "Skills.h"


void FireBall::CauseEffect(Unit& Opponent) {
	std::random_device rd;
	std::mt19937 mt;
	std::uniform_int_distribution<int> dist(min_dmg, max_dmg);
	std::uniform_int_distribution<int> dist1(min_dmg/10, max_dmg/10);
	buff.Init_Buff(dist1(mt),3);
	Opponent.SetStat(dist(mt));
}


//Burning FireBall::ReturnBaff() {
//	return buff;
//}

std::string Buff::Return_Type() {
	return type;
}

void Burning::Init_Buff(int damage, int n) {
	type = "hp";
	dmg = damage;
	num_steps = n;
	on = true;
}

void Burning::Apply_Effect(int stat) {
	stat -= dmg;
}

void Poisoning::Init_Buff(int damage, int n) {

}

void Poisoning::Apply_Effect(int stat) {
	stat -= dmg;
}