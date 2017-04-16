#pragma once
#include <random>
#include <vector>
#include "Skills.h"
#include "Weapons.h"

typedef std::vector<Attack*> Weapons;

/* The main difference among units is in SetStat function as different classes of units 
*  respond on attack in their unique way.
*  What is added for now:
*  - Berserks:
*   with 30% probability can avoid any damage;
*  - Wizard:
*   with 60% probability hills himself and increases HP on random variable less than 100 and more 40;
*  - Paladin:
*   with 50% probability hills previous and next teammates (towards the Paladin position) with 1/2 of received damage;
*  - Defender:
*   with 75% protects himself from 1/4 damage;
*  - Demon Slayer:
*   with 50% produces the same damage to enemy who attacked;
*
*
*  Effects and Affects:
*  I considered that it would be great to separate buffs which unit applies to opponent (or friend)
*  from buffs which were added to unit. 
*  Due to this strategy buffs appeared in each battle after using a weapon or skill are added to unit's vector
*  of *affects* because this buffs should be transported to opponents vector of *effects* later. This *affects*
*  will be shifted to opponent during the battle, added to his vector of *effects*	 and applied to him. 
*/

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

	void info(); //info about units stats;

	int getHealth(); //get unit's HP;

	bool is_Dead();// returns true whether unit is dead;

	/* Function LearnSkill():
	*  virtual Skills* LearnSkill() = 0;
	*/

	//virtual void useSkill();

	/* function setInitiative sets and returns unit's initiative.
	*  The value is randomized from the range defined for each unique unite.
	*/

	virtual int setInitiative() = 0;

	/* Function replica():
	*  virtual void function, throws a unit's sentence.
	*  Inheritance in classes of each hero.
	*/

	virtual void replica() = 0; //screaming time;
	
	/* Function SetStat(int damage, Buffs& buff_, int mode):
	*  virtual void function, which takes damage as 
	*  an agrument and updates heroes data. Also adds all side effects collected during the
	*  battle to the unit.
	*/

	virtual void setStat(int damage, Buffs& buff_, int mode); //updates hero's stats 

	/* Function UnitMenu()
	*  void function which displays all stats
	*  of character in "beautifully designed window".
	*/
	int getDefence();

	/* function AddAffection attaches input value (vector of buffs) to
	*  unit's affection vector. More details about effects and affects find above;
	*/

	void addAffection(Buffs& buff_);

	/* function AddEffect attaches input value (vector of buffs) to
	*  unit's vector of effects. More details about effects and affects find above;
	*/

	void addEffect(Buffs& buff_);

	/* returns vector of affects*/

	Buffs getAffects();

	/* return vector of effects*/

	Buffs getEffects();

	/* returns unit's inspiration */

	int getInspiration();

	/* function useEffect implements buffs added in the vector of effects.*/

	void useEffect(Buff& buff_);

	/* effects inspiration with input value.*/

	void setInspiration(int eff);

	/* returns required inspiration for skill.
	NOT IMPLEMENTED YET!!!*/

	int requiredInspiration();

	//virtual void useSkill();

	void setName();

	/* function setAutoAttack turns on the auto attack mode
	*  and in this case unit will be fighting with help of AI.
	*  Is especially useful for bots.
	*/

	void setAutoAttack(bool on);

	/* Defines whether unit is bot or a user.*/

	bool checkAutoAttack();

	/* returns amount of stamina required for attack on defined type of points (health or defence)
	*  for unit's weapon. FOR NOW UNIT HAS ONLY ONE WEAPON WITH INDEX 0!!!*/

	int requiredStamina(int i, std::string type);

	int getStamina();

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
	*  buff - vector of side effects(pointers on elements of class Buff);
	*/
	std::string type;
	std::string name;
	int HP;
	int DF;
	int required_insp;
	int init_max;
	int min_insp;
	int level;
	std::vector<int> battle_stats;
	Buffs spec_Eff; // effects caused by opponents;
	Buffs spec_Aff; // affection caused by unit on opponents;
	Weapons gear; //FOR NOW UNIT HAS ONLY ONE WEAPON WITH INDEX 0!!!
	// Diez simbol is used to represent info. about character's data.
	char InfoBlock = '#';
	
};

class Paladin :public Unit {
public:
	void initUnit();
	int setInitiative();
	void setStat(int damage, Buffs& buff_, int mode);
	void useSkill(); // not implemented yet;
	void replica();
private:
	// levels required for each ability; NOT IMPLEMENTED YET!!!
	std::vector <int> spec_ab;
	int max_hp;
};

class Wizard :public Unit {
public:
	void initUnit();
	int setInitiative();
	void setStat(int damage, Buffs& buff_, int mode);
	//void useSkill(); 
	void replica();
private:
	// levels required for each ability;
	std::vector <int> spec_ab;
	int max_hp;
};

class Berserk :public Unit {
public:
	void initUnit();
	int setInitiative();
	void setStat(int damage, Buffs& buff_, int mode);
	//void useSkill(); 
	void replica();
private:
	// levels required for each ability;
	std::vector <int> spec_ab;
	int max_hp;
};

class DemonSlayer :public Unit {
public:
	void initUnit();
	int setInitiative();
	void setStat(int damage, Buffs& buff_, int mode);
	void useSkill(); 
	void replica();
private:
	// levels required for each ability;
	std::vector <int> spec_ab;
	int max_hp;
};

class Defender :public Unit {
public:
	void initUnit();
	int setInitiative();
	void setStat(int damage, Buffs& buff_, int mode);
	//void useSkill();
	void replica();
private:
	// levels required for each ability;
	std::vector <int> spec_ab;
	int max_hp;
};

