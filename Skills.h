#pragma once
#include "Unit.h"
//class of buffs
class Buff {
public:
	virtual void Init_Buff();
	virtual void ApplyEffect(int stat);
	virtual ~Buff() = default;
};


class Poisoning :public Buff {
public:
	void Init_Buff(int dmg);
	void ApplyEffect(int stat);

private:
	int dmg;
	int num_steps;
};

class Burning :public Buff {
public:
	void Init_Buff(int damage, int n);
	void ApplyEffect(int stat);
	
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