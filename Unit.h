#pragma once
#include <random>
#include <vector>
#include "Weapons.h"

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

	virtual void SetStat(int damage, std::vector<int> &baff); //updates hero's stats 

	virtual void UnitMenu() = 0;

	// not finished yet;
	virtual ~Unit() = default; //destructor, undefined yet;
protected:
	/* Unit's data/status:
	*  HP - character's health points;
	*  DF - character's defence points; NOT USED YET!!!ÿ	
	*  TODO: Create units profile, which will save and represent
	*  unit's info in more appropriate way.
	*/
	std::string type;
	int HP;
	int DF;
	int level;
	std::vector <Attack*> gear;
	// Diez simbol is used to represent info. about character's data.
	char InfoBlock = '#';
};

class Dwarf :public Unit {
public:
	void InitUnit();
	Attack* Hit();
	void SetStat(int damage, std::vector<int> &baff);
	void UnitMenu();
	void info(); //ctrl+c from previous task;
	void replica();
};

class Wizard :public Unit {
public:
	void InitUnit();
	Attack* Hit();
	void SetStat(int damage, std::vector<int> &baff);
	void UnitMenu();
	void info(); //ctrl+c from previous task;
	void replica();
};

class Orc :public Unit {
public:
	void InitUnit();
	Attack* Hit();
	void SetStat(int damage, std::vector<int> &baff);
	void UnitMenu();
	void info(); //ctrl+c from previous task;
	void replica();
};

