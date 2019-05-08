#include "Player.h"


Player player_init() {
	Player pl;
	//init car too?
	//init inventory?
	pl.money = 1000;
	strcpy_s(pl.name, 20, "");

	return pl;
}