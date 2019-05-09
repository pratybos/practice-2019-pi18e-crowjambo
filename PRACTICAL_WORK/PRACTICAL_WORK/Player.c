#include "Player.h"


Player player_init() {
	int i = 0;

	Player pl;
	pl.currentCar = 0;
	pl.inventory = inventory_init();
	pl.money = 10000;
	strcpy_s(pl.name, 20, "");
	for (i = 0; i < 10; i++) {
		pl.ownedCars[i] = car_init();
	}

	return pl;
}