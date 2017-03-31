#include <string>
#include "Skills.h"

Buff::Buff() {

}

void Buff::Apply_Effect(int* stat) {
	*stat += effect;
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
