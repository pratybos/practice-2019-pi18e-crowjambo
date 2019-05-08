#pragma once
#include "MainLibs.h"

struct Player {
	char name[20];
	Inventory inventory;
	Car car;
	int money;
};
typedef struct Player Player;


Player player_init();