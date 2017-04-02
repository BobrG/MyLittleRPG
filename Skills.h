#pragma once
#include <string>
#include <vector>

//class of buffs
class Buff {
public:
	Buff();

	virtual void Init_Buff(int eff, int n, std::string type_, bool activate);

	virtual void Apply_Effect(int* stat);

	bool Return_Status();

	void Set_STatus(bool activate);

	std::string Return_Type();

	bool Is_On();

	virtual ~Buff();
protected:
	bool active;
	int effect;
	int num_steps;
	int dest;
	std::string type;
};

class Debuff :public Buff {
public:

	void Init_Buff(int eff, int n, std::string type_, bool activate);

	void Apply_Effect(int* stat);

};

typedef std::vector<Buff*> Buffs;