#pragma once

#include "Unit.h"
typedef std::vector<Unit*> UnArr;

void menu(Unit* u);

void list();

// creates unit of choosen class;
void create(int key, Unit** u);

// checks if any unit of two fighters is dead;
bool AnyAlive(Unit* a, Unit* b);

// Arena section, provides the choice of mode - Single or Team;
void Arena(Unit* Player);

// quite simple AI for opponent units aka bots;
// chooses the type of attack;
// the main feature which determines the choice is amount of STAMINA and inspiration;
// bot prefers to use Skill if he had enough inspiration;
// else bot chooses to attack defence if he has enough STAMINA;
// in other cases bot chooses to attack health point;
int AutoAttack(UnArr& Oppenents);

// quite simple AI for opponent team of bots;
// determines the player's unit to attack;
// chooses unit with less h.p.;
int AutoAttack(Unit* Player, Unit* Opponent);

// function which describes a battle between twwo single units;
// more details in the cpp file;
void Battle(Unit* FirstPl, Unit* SecondPl);

// displays info about all team members of single team;
void Team_List(UnArr& Players);

// excludes units with zero HP (dead) from the battle.
// they cannot continue the battle anymore;
void Exclude_Dead(UnArr& Players);

// description of battle of teams; more detailes in cpp file;
void Team_Battle(UnArr& FirstPl, UnArr& SecondPl);

// single battle mode;
void SingleArena(Unit* Player);

// the team battle mode, with choosing teammates, their classes, defining the order of fight, etc;
void TeamArena(Unit* Player);