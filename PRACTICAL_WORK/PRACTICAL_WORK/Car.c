#include "Car.h"
#include <stdlib.h>
#include <string.h>

char *carNames[9] = { "AE86","FC RX-7","FD RX-7", "22B", "911", "Eclipse", "Astra F", "Civic", "NSX" };

Car car_init() {
	Car temp;
	temp.BrakePower = 0;
	temp.CenterOfMass = 0;
	temp.HorsePower = 0;
	temp.aeroItem = 0;
	temp.engineItem = 0;
	temp.tireItem = 0;
	temp.turboItem = 0;
	temp.exhaustItem = 0;
	temp.price = 0;
	strcpy_s(temp.name, 20, "None");
	return temp;
}

Car car_generate() {
	//init default values for items
	Car temp = car_init();
	int x = rand() % 9;
	strcpy_s(temp.name, 20, carNames[x]);
	//each car has its own variation of stats and price
	switch (x) {
	case 0:
		temp.price = rand() % 1000 + 800;
		temp.BrakePower = rand() % 50 + 50;
		temp.CenterOfMass = 0.6;
		temp.HorsePower = rand() % 50 + 100;
		break;
	case 1:
		temp.price = rand() % 1000 + 2000;
		temp.BrakePower = rand() % 50 + 50;
		temp.CenterOfMass = 0.51;
		temp.HorsePower = rand() % 100 + 150;
		break;
	case 2:
		temp.price = rand() % 1000 + 3000;
		temp.BrakePower = rand() % 50 + 50;
		temp.CenterOfMass = 0.5;
		temp.HorsePower = rand() % 150 + 200;
		break;
	case 3:
		temp.price = rand() % 1000 + 3000;
		temp.BrakePower = rand() % 50 + 50;
		temp.CenterOfMass = 0.65;
		temp.HorsePower = rand() % 100 + 200;
		break;
	case 4:
		temp.price = rand() % 1000 + 5000;
		temp.BrakePower = rand() % 50 + 100;
		temp.CenterOfMass = 0.4;
		temp.HorsePower = rand() % 100 + 300;
		break;
	case 5:
		temp.price = rand() % 500 + 800;
		temp.BrakePower = rand() % 50 + 50;
		temp.CenterOfMass = 0.7;
		temp.HorsePower = rand() % 30 + 120;
		break;
	case 6:
		temp.price = rand() % 300 + 300;
		temp.BrakePower = rand() % 50 + 50;
		temp.CenterOfMass = 0.68;
		temp.HorsePower = rand() % 70 + 50;
		break;
	case 7:
		temp.price = rand() % 500 + 800;
		temp.BrakePower = rand() % 50 + 50;
		temp.CenterOfMass = 0.67;
		temp.HorsePower = rand() % 35 + 90;
		break;
	case 8:
		temp.price = rand() % 1000 + 2500;
		temp.BrakePower = rand() % 50 + 80;
		temp.CenterOfMass = 0.48;
		temp.HorsePower = rand() % 100 + 200;
		break;
	}

	return temp;
}