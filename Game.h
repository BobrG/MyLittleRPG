#pragma once

#include "Unit.h"


void menu(Unit* u);

int h_or_t();

void list();

void create(int key, Unit** u);

bool AnyAlive(Unit* a, Unit* b);

void Arena(Unit* Player);

void SingleArena(Unit* Player);

void TeamArena(Unit* Player);