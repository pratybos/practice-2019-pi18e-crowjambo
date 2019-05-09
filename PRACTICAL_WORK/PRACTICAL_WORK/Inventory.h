#pragma once

enum ITEMNAMES {
	Engine_1,
	Engine_2,
	Engine_3,
	Turbo_1,
	Turbo_2,
	Turbo_3,
	Tires_1,
	Tires_2,
	Tires_3,
	Exhaust_1,
	Exhaust_2,
	Exhaust_3,
	Aerodynamics_1,
	Aerodynamics_2,
	Aerodynamics_3,
	NONE
};

struct Inventory {
	int size;
	int items[20];
};
typedef struct Inventory Inventory;

struct Item {
	int itemNR;
	int price;
};
typedef struct Item Item;

Inventory inventory_init();
char *inventory_ToName(int itemNR);
Item items_init(int x);