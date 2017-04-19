#pragma once
#include <string>

class Buff {
public:
	/* function Init_Buff - initializes side effect. It was considered to
	*  implement next parametres for side effect initialization:
	*  - eff - caused effect;
	*  - type - the stat whcih is affected;
	*  - n - amount of steps which the buff lasts;
	*/
	virtual void Init_Buff(int eff, int n, std::string type_);

	/* function Apply_Effect - produces an effect on stat;*/
	virtual void Apply_Effect(int* stat);

	std::string Return_Type();

	bool Is_On();

	virtual ~Buff();
protected:
	int effect;
	int num_steps;
	std::string type;
};

