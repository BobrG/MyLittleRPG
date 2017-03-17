#pragma once
#include <string>
#include "Unit.h"
//class of buffs
class Buff {
public:
	std::string type;

	virtual void Init_Buff();
	
	virtual void Apply_Effect(int stat);
   
	std::string Return_Type();
	virtual ~Buff() = default;
};


class Poisoning :public Buff {
public:
	void Init_Buff(int dmg, int n);
	void Apply_Effect(int stat);

private:
	int dmg;
	int num_steps;
};

class Burning :public Buff {
public:
	void Init_Buff(int damage, int n);
	void Apply_Effect(int stat);
	
private:
	int dmg;
	int num_steps;
	bool on;
};
// class special skills 
class Skills {
public:
	virtual void CauseEffect(Unit& Player);
};

class FireBall : public Skills {
public:
	void CauseEffect(Unit& Player);
	Burning ReturnBaff();
private:
	Burning buff;
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