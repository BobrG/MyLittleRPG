#pragma once
#include <string>
#include <vector>

//class of buffs. STILL REQUIRES MORE CONSIDERATION!
class Buff {
public:
	/* function Init_Buff - initializes side effect. It was considered to 
	*  implement next parametres for side effect initialization:
	*  - eff - caused effect;
	*  - type - the stat whcih is affected;
	*  - n - amount of steps which the buff lasts;
	*  - activate - was the buff activated or not. WARNING WORKAROUND DETECTED! However I haven't created better solution
	*  for some cases, yet :C
	*/
	virtual void Init_Buff(int eff, int n, std::string type_, bool activate);

	/* function Apply_Effect - produces an effect on stat;*/
	virtual void Apply_Effect(int* stat);

	bool Return_Status();

	void Set_STatus(bool activate);

	std::string Return_Type();

	bool Is_On();

	virtual ~Buff();
protected:
	// activated or not. This parameter was used to choose what buffs should be added to friend units
	// and what to enemy units;
	bool active;

	int effect;
	int num_steps;
	std::string type;
};

// buffs with negative effects. Not considered properly, yet
class Debuff :public Buff {
public:

	void Init_Buff(int eff, int n, std::string type_, bool activate);

	void Apply_Effect(int* stat);

};

typedef std::vector<Buff*> Buffs;