#pragma once

#include "Unit.h"
typedef std::vector<Unit*> UnArr;

void menu(Unit* u);

void list();

void create(int key, Unit** u);

bool AnyAlive(Unit* a, Unit* b);

void Arena(Unit* Player);

int AutoAttack(UnArr& Oppenents);

int AutoAttack(Unit* Player, Unit* Opponent);

void Battle(Unit* FirstPl, Unit* SecondPl);

void Team_List(UnArr& Players);

void Exclude_Dead(UnArr& Players);

void Team_Battle(UnArr& FirstPl, UnArr& SecondPl);

void SingleArena(Unit* Player);

void TeamArena(Unit* Player);