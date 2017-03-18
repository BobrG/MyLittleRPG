
#include <string>
#include "Skills.h"


void FireBall::CauseEffect(Unit& Opponent) {
	std::random_device rd;
	std::mt19937 mt;
	std::uniform_int_distribution<int> dist(min_dmg, max_dmg);
	std::uniform_int_distribution<int> dist1(min_dmg/10, max_dmg/10);
	Buff eff;
	eff.Init_Buff(dist1(mt), 3, "hp");
	Opponent.SetStat(dist(mt), eff);
}


//Burning FireBall::ReturnBaff() {
//	return buff;
//}

void Buff::Apply_Effect(int stat) {
	stat += effect;
	num_steps--;
}

void Debuff::Apply_Effect(int stat) {
	stat -= effect;
	num_steps--;
}

void Buff::Init_Buff(int eff, int n, std::string type_) {
	type = type_;
	effect = eff;
	num_steps = n;
}

void Debuff::Init_Buff(int damage, int n, std::string type_) {
	type = type_;
	effect = damage;
	num_steps = n;
}

std::string Buff::Return_Type() {
	return type;
}

bool Buff::Is_On() {
	return (num_steps > 0);
}

Buff::~Buff() {
	num_steps = 0;
	effect = 0;
}