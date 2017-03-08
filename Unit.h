#pragma once
#include <random>
#include <vector>
#include "Weapons.h"

typedef std::vector<Attack*> Weapons;

class Unit {
public:
	/* Function Hit():
	*  virtual function, which creates and returnes an object
	*  of class Attack - hero's weapon.
	*/

	virtual Attack* Hit() = 0; //return character's weapon;

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

	/* Function getHealth(): 
	*  Cacrries out encapsulating of unit's data [1].
	*  Returns unit's health points.
	*/

	int getHealth(); //get unit's HP;

	virtual int SpecialAbility() = 0;

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
	*  TODO: Create units profile, which will save and represent
	*  unit's info in more appropriate way.
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
	// Diez simbol is used to represent info. about character's data.
	char InfoBlock = '#';
};

class Paladin :public Unit {
public:
	void InitUnit();
	int setInitiative();
	Attack* Hit();
	void SetStat(int damage, const std::vector<int>& baff = {});
	int SpecialAbility();
	void info(); //ctrl+c from previous task;
	void replica();
};

class Wizard :public Unit {
public:
	void InitUnit();
	int setInitiative();
	Attack* Hit();
	void SetStat(int damage, const std::vector<int>& baff = {});
	int SpecialAbility();
	void Fire_Ball(int damage);
	void Hilling(Unit& Player);
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
	Attack* Hit();
	void SetStat(int damage, const std::vector<int>& baff = {});
	int SpecialAbility();
	void info(); //ctrl+c from previous task;
	void replica();
};

