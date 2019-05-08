#pragma once
#include "Inventory.h"
#include "Car.h"

struct Player {
	char name[20];
	Inventory inventory;
	int currentCar;
	Car ownedCars[10];
	int money;
};
typedef struct Player Player;


Player player_init();