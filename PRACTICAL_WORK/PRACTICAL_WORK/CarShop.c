#include "CarShop.h"
#include <stdlib.h>
#include <string.h>

char *carNames[9] = { "AE86","FC RX-7","FD RX-7", "22B", "911", "Eclipse", "Astra F", "Civic", "NSX" };

CarListing generateListing() {
	int x = rand() % 9;
	CarListing temp;
	temp.price = rand() % 4500 +500;
	strcpy_s(temp.name, 20, carNames[x]);

	return temp;
}
