#pragma once
#include <string>

//class of buffs
class Buff {
public:

	void Init_Buff(int eff, int n, std::string type_);

	void Apply_Effect(int stat);

	std::string Return_Type();

	bool Is_On();

	virtual ~Buff();
protected:
	int effect;
	int num_steps;
	std::string type;
};

class Debuff :public Buff {
public:

	void Init_Buff(int dmg, int n, std::string type_);

	void Apply_Effect(int stat);

	std::string Return_Type();

	bool Is_On();

};
