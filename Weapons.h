#pragma once
#include <random>
#include <vector>

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

	std::vector <int> GetBaff();

	virtual ~Attack() = default; // not defined yet;
protected:
	/* Weapons data/status:
	*  DMG - caused damage.
	*/
	int DMG;

	/* baff is a vector of side effects:
	*  baff[0] - effects on HP (+/-)
	*  baff[1] - effects on HP (multiplication)
	*  baff[2] - special effects(poisoning for ex.)
	*/
	std::vector<int> baff;
};

class Rage : public Attack { //for Orc;
public:
	Rage();
	int attack();
	void fendoff(int damage);
	void info();
private:
	/* Randomization data for
	*  computing probability;
	*/
	std::random_device rd;
	std::mt19937 mt;
	std::uniform_int_distribution<int> dist;
	std::uniform_int_distribution<int> dist1;
};

class Spell : public Attack { //for Wizard;
public:
	Spell();
	int attack();
	void fendoff(int damage);
	void info();
private:
	std::random_device rd;
	std::mt19937 mt;
	std::uniform_int_distribution<int> dist;
	std::uniform_int_distribution<int> dist1;
};

class Shield : public Attack { //for Dwarf
public:
	Shield();
	int attack();
	void fendoff(int damage);
	void info();
private:
	std::random_device rd;
	std::mt19937 mt;
	std::uniform_int_distribution<int> dist;
	std::uniform_int_distribution<int> dist1;
};

class PowerofNature : public Attack { //todo: add new kind of weapon;
public:
	PowerofNature();
	int attack();
	void fendoff(int damage);
	void info();
private:
	std::random_device rd;
	std::mt19937 mt;
	std::uniform_int_distribution<int> dist;
	std::uniform_int_distribution<int> dist1;
};

