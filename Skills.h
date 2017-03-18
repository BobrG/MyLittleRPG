#pragma once
#include <string>
#include "Unit.h"
//class of buffs
class Buff {
public:

	virtual void Init_Buff(int eff, int n, std::string type_);
	
	virtual void Apply_Effect(int stat);
   
	std::string Return_Type();

	bool Is_On();

	virtual ~Buff() = default;
protected:
	int effect;
	int num_steps;	
	std::string type;
};

class Debuff:public Buff {
public:

    void Init_Buff(int dmg, int n, std::string type_);

    void Apply_Effect(int stat);

	std::string Return_Type();

	bool Is_On();

};

// class special skills 
class Skills {
public:
	virtual void CauseEffect(Unit& Player);
};

class FireBall : public Skills {
public:
	void CauseEffect(Unit& Player);
	Debuff ReturnBaff();
private:
	Debuff buff;
	int min_dmg = 10;
	int max_dmg = 50;
};

class Rage : public Skills {
public:
	void CauseEffect(Unit& Player);
private:
	int min_dmg = 10;
	int max_dmg = 30;
};

class Blessing : public Skills {
public:
	void CauseEffect(Unit& Player);
private:
	int min_hill = 10;
	int max_hill = 30;
};

class Shield : public Skills {
public:
	void CauseEffect(Unit& Player);
};