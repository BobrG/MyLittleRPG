#pragma once
#include "Unit.h"

class Skills {
public:
	virtual void CauseAffect(Unit& Opponent) = 0;
private:
};

class FireBall : public Skills {
public:
	void CauseAffect(Unit& Opponent);
};