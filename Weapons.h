#pragma once
#include <random>
#include <vector>
#include "Skills.h"

class Attack {
public:
	/* Function attack():
	*  virtual function, which returns caused damage
	*  and computes side effects;
	*  Inheritance changes type of caused 'baff'.
	*/
	virtual int attack() = 0;

	/* Function fendoff():
	*  virtual function, which gets caused damage
	*  and protects unit in some cases, depends on
	*  weapons type;
	*/
	virtual void fendoff(int damage) = 0;

	/* Function GetBaff - returnes vector of side effects;*/

	Buffs GetBaff();

	/* Function stamina_required returns the amount of stamina which is needed to produce attack
	*  on health points or defence points of unit;
	*/
	int stamina_required(std::string type);

	virtual ~Attack() = default; // not defined yet;
protected:
	/* Weapons data/status:
	*  DMG - caused damage.
	*  stamina_hp - stamina required for attack health.
	*  staamina_df - stamina required for attack defence.
	*/
	int DMG;
	int stamina_hp;
	int stamina_df;
	int insp;

	// special effects produced by weapon; 
	Buffs spec_eff;
};

class Sword : public Attack { 
public:
	Sword();
	int attack();
	void fendoff(int damage);
	void info();
private:
	/* Randomization data for
	*  computing probability;
	*/
	int max_dmg = 50;
	std::random_device rd;
	std::mt19937 mt;
	std::uniform_int_distribution<int> dist;
	std::uniform_int_distribution<int> dist1;
};

class Staff : public Attack { 
public:
	Staff();
	int attack();
	void fendoff(int damage);
	void info();
private:
	int max_dmg = 30;
	std::random_device rd;
	std::mt19937 mt;
	std::uniform_int_distribution<int> dist;
	std::uniform_int_distribution<int> dist1;
};

class Shield : public Attack { 
public:
	Shield();
	int attack();
	void fendoff(int damage);
	void info();
private:
	int max_dmg = 40;
	std::random_device rd;
	std::mt19937 mt;
	std::uniform_int_distribution<int> dist;
	std::uniform_int_distribution<int> dist1;
};
