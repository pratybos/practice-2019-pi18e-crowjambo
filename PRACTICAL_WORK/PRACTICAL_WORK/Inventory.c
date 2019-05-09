#include "Inventory.h"



Inventory inventory_init() {
	Inventory temp;
	temp.size = 0;
	int i = 0;
	for (i = 0; i < 20; i++) {
		temp.items[i] = NONE;
	}

	return temp;
}

char *inventory_ToName(int itemNR) {
	switch (itemNR) {
	case 0: return "Engine_1";
	case 1: return "Engine_2";
	case 2: return "Engine_3";
	case 3: return "Turbo_1";
	case 4: return "Turbo_2";
	case 5: return "Turbo_3";
	case 6: return "Tires_1";
	case 7: return "Tires_2";
	case 8: return "Tires_3";
	case 9: return "Exhaust_1";
	case 10: return "Exhaust_2";
	case 11: return "Exhaust_3";
	case 12: return "Aerodynamics_1";
	case 13: return "Aerodynamics_2";
	case 14: return "Aerodynamics_3";
	case 15: return "NONE";
	}
}

Item items_init(int x) {
	Item temp;
	temp.itemNR = x;
	temp.price = 50 * x +100;

	return temp;
}