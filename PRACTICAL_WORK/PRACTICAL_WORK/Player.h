#pragma once

struct Player {
	char name[20];
	Inventory inventory;
	Car car;
	int money;
};
typedef struct Player Player;