#pragma once
#include <random>
#include <vector>
#include "Skills.h"
#include "Weapons.h"

typedef std::vector<Attack*> Weapons;
class Skills;

class Unit {
public:
	/* Function Hit():
	*  returnes pointer on object of class Attack - heroe's weapon.
	*  Index i determines number of required element 
	*  in the vector of weapons;
	*/

    Attack* Hit(int i); //return character's weapon;

	// IMPLEMENT ITEM SYSTEM (ARMOR WITH BUFFS, SPECIAL STATS, ETC);
	//virtual void TakeItem(Item& it);

	/* Function InitUnit(): 
	*  void function, which is called once to initialize 
	*  units start status.
	*/

	virtual void initUnit(); //initialization of unit;

	/* Function info():
	*  virtual void function, which shows all unit's data
	*  and it's status. 
	*/

	virtual void info() = 0; //info about units stats;

	int getHealth(); //get unit's HP;

	bool is_Dead();// returns true whether unit is dead;

	/* Function LearnSkill():
	*  virtual Skills* LearnSkill() = 0;
	*/

	//virtual void useSkill();

	virtual int setInitiative() = 0;//sets and returns unit's initiative before each battle;

	/* Function replica():
	*  virtual void function, throws a unit's sentence.
	*  Inheritance in classes of each hero.
	*/

	virtual void replica() = 0; //screaming time;
	
	/* Function SetStat(int damage):
	*  virtual void function, which takes damage as 
	*  an agrument and updates heroes data [1]. Inheritance 
	*  adds baff and some special abilities of each hero.
	*/

	virtual void setStat(int damage, Buffs& buff_); //updates hero's stats 

	/* Function UnitMenu()
	*  void function which displays all stats
	*  of character in "beautifully designed window".
	*/

	virtual void useSkill();

	void setName();

	void setAutoAttack(bool on);

	bool checkAutoAttack();

	int requiredStamina(int i, std::string type);

	int checkStamina();

	void setStamina(int eff);

	std::string getType();

	virtual void unitMenu();

	// not finished yet;
	virtual ~Unit() = default; //destructor, undefined yet;

protected:
	/* Unit's data/status:
	*  type - unit's class;
	*  name - unit's name, designed by user;
	*  HP - character's health points;
	*  DF - character's defence points; NOT USED YET!!!	
	*  init_max - max initiative in a range; 
	*  min_insp - minimum inspiration requered for abilities;
	*  battle_stats - vector of special unit's stats used in battle:
	*  [0] - initiation;
	*  [1] - stamina;
	*  [2] - inspiration;
	*  gear - vector of weapons(pointers on class Attack);
	*  skill - vector of special skills unique for each unit;
	*  buff - vector of side effects(pointers on elements of class Buff);
	*/
	std::string type;
	std::string name;
	int HP;
	int DF;
	int init_max;
	int min_insp;
	int level;
	std::vector<int> battle_stats;
	std::vector<Buff*> spec_eff;
	Weapons gear;
	// Diez simbol is used to represent info. about character's data.
	char InfoBlock = '#';
};

class Paladin :public Unit {
public:
	void initUnit();
	int setInitiative();
	void setStat(int damage, Buffs& buff_);
	void useSkill(); 
	void info();
	void replica();
private:
	// levels required for each ability;
	std::vector <int> spec_ab;
};

class Wizard :public Unit {
public:
	void initUnit();
	int setInitiative();
	void setStat(int damage, Buffs& buff_);
	void useSkill(); 
	void info(); //ctrl+c from previous task;
	void replica();
private:
	// levels required for each ability;
	std::vector <int> spec_ab;
};

class Berserk :public Unit {
public:
	void initUnit();
	int setInitiative();
	void setStat(int damage, Buffs& buff_);
	void useSkill(); 
	void info();
	void replica();
private:
	// levels required for each ability;
	std::random_device rd;
	std::mt19937 mt;
	std::uniform_int_distribution<int> dist;
	std::uniform_int_distribution<int> dist1;
	std::vector <int> spec_ab;

};

class DemonSlayer :public Unit {
public:
	void initUnit();
	int setInitiative();
	void setStat(int damage, Buffs& buff_);
	void useSkill(); 
	void info();
	void replica();
private:
	// levels required for each ability;
	std::vector <int> spec_ab;

};

class Defender :public Unit {
public:
	void initUnit();
	int setInitiative();
	void setStat(int damage, Buffs& buff_);
	void useSkill();
	void info();
	void replica();
private:
	// levels required for each ability;
	std::random_device rd;
	std::mt19937 mt;
	std::uniform_int_distribution<int> dist;
	std::uniform_int_distribution<int> dist1;
	std::vector <int> spec_ab;

};

