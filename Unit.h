#pragma once
#include <random>
#include <vector>
#include "Skills.h"
#include "Weapons.h"

typedef std::vector<Attack*> Weapons;

class Unit {
public:
	/* Function Hit():
	*  returnes pointer on object of class Attack - heroe's weapon.
	*  Index i determines number of required element 
	*  in the vector of weapons;
	*/

    Attack* Hit(int i); //return character's weapon;

	//virtual void TakeItem(Item& it);

	/* Function InitUnit(): 
	*  void function, which is called once to initialize 
	*  units start status.
	*/

	virtual void InitUnit(); //initialization of unit;

	/* Function info():
	*  virtual void function, which shows all unit's data
	*  and it's status. 
	*/

	virtual void info() = 0; //info about units stats;

	int getHealth(); //get unit's HP;

	bool is_Dead();

	/* Function LearnSkill():
	*  
	*/
	virtual Skills* LearnSkill() = 0;

	virtual int setInitiative() = 0;//sets unit's initiative before each battle;

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

	virtual void SetStat(int damage, const std::vector<int>& baff = {}); //updates hero's stats 

	virtual void UnitMenu();

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
	*/
	std::string type;
	std::string name;
	int HP;
	int DF;
	int init_max;
	int min_insp;
	int level;
	std::vector<int> battle_stats;
	std::vector <Attack*> gear;
	std::vector <Skills*> skill;
	// Diez simbol is used to represent info. about character's data.
	char InfoBlock = '#';
};

class Paladin :public Unit {
public:
	void InitUnit();
	int setInitiative();
	Skills* LearnSkill();
	void SetStat(int damage, const std::vector<Buff>& baff = {});
	void info();
	void replica();
private:
	// levels required for each ability;
	std::vector <int> spec_ab;
};

class Wizard :public Unit {
public:
	void InitUnit();
	int setInitiative();
	void SetStat(int damage, const std::vector<Buff>& baff = {});
	Skills* LearnSkill();
	void info(); //ctrl+c from previous task;
	void replica();
private:
	// levels required for each ability;
	std::vector <int> spec_ab;
};

class Berserk :public Unit {
public:
	void InitUnit();
	int setInitiative();
	
	void SetStat(int damage, const std::vector<Buff>& baff = {});
	Skills* LearnSkill();
	void info(); //ctrl+c from previous task;
	void replica();
private:
	// levels required for each ability;
	std::vector <int> spec_ab;

};

