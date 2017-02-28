#pragma once

#include "Unit.h"


void menu(Unit* u);

void list();

void create(int key, Unit** u);

bool AnyAlive(Unit* a, Unit* b);

void Arena(Unit* Player);