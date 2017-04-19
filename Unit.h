#pragma once
#include <vector>

#include "Buffs.h"

class Unit {
public:
	virtual void initUnit();

	virtual void setStat(int damage, Buffs& buff_);

	int getHealth();

	int getDefence();

	int getStamina();

	void setStamina(int eff);

	int getInspiration();

	void setInspiration(int eff);

	bool is_Dead();

	void info();

	void setAutoAttack(bool on);

	virtual ~Unit() = default;

private:
	/* Unit's data/status:
	*  type - unit's class;
	*  name - unit's name, designed by user;
	*  HP - character's health points;
	*  DF - character's defence points;
	*  battle_stats - vector of special unit's stats used in battle:
	*  [0] - initiation;
	*  [1] - stamina;
	*  [2] - inspiration;
	*  gear - vector of weapons(pointers on class Attack);
	*/
	std::string type;
	std::string name;
	int HP;
	int DF;
	int level;
	std::vector<int> battle_stats;
	Weapons gear;

};

class Paladin :public Unit {
public:
	void initUnit();
	
	void setStat(int damage, Buffs& buff_, int mode);
	
private:
	// levels required for each ability;
	std::vector <int> spec_ab;
};

class Wizard :public Unit {
public:
	void initUnit();

	void setStat(int damage, Buffs& buff_, int mode);
	
private:
	// levels required for each ability;
	std::vector <int> spec_ab;
};

class Berserk :public Unit {
public:
	void initUnit();

	void setStat(int damage, Buffs& buff_, int mode);
	
private:
	// levels required for each ability;
	std::vector <int> spec_ab;
};

class DemonSlayer :public Unit {
public:
	void initUnit();

	void setStat(int damage, Buffs& buff_, int mode);

private:
	// levels required for each ability;
	std::vector <int> spec_ab;
};

class Defender :public Unit {
public:
	void initUnit();

	void setStat(int damage, Buffs& buff_, int mode);

private:
	// levels required for each ability;
	std::vector <int> spec_ab;
};

