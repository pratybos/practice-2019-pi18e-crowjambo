#include "Car.h"
#include <stdlib.h>
#include <string.h>

char *carNames[9] = { "AE86","FC RX-7","FD RX-7", "22B", "911", "Eclipse", "Astra F", "Civic", "NSX" };

int calculate_performance(Car x) {
	return (int)((x.HorsePower + x.BrakePower) / x.weigth / x.downForce);
}

Car car_init() {
	Car temp;
	temp.BrakePower = 0;
	temp.CenterOfMass = 0;
	temp.HorsePower = 0;
	temp.aeroItem = 15;
	temp.engineItem = 15;
	temp.tireItem = 15;
	temp.turboItem = 15;
	temp.exhaustItem = 15;
	temp.price = 0;
	temp.baseHorsePower = 0;
	temp.performanceRatio = 0;
	temp.rearGrip = 0;
	temp.frontGrip = 0;
	temp.weigth = 0;
	temp.downForce = 0;
	temp.currentLine = 1;
	temp.currentSpeed = 0;
	temp.topSpeed = 0;
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
		temp.CenterOfMass = 0.6f;
		temp.HorsePower = rand() % 50 + 100;
		temp.baseHorsePower = temp.HorsePower;
		temp.weigth = 800;
		temp.downForce = 0.1;
		temp.topSpeed = 150;
		break;
	case 1:
		temp.price = rand() % 1000 + 2000;
		temp.BrakePower = rand() % 50 + 50;
		temp.CenterOfMass = 0.51f;
		temp.HorsePower = rand() % 100 + 150;
		temp.baseHorsePower = temp.HorsePower;
		temp.weigth = 1100;
		temp.downForce = 0.2;
		temp.topSpeed = 150;
		break;
	case 2:
		temp.price = rand() % 1000 + 3000;
		temp.BrakePower = rand() % 50 + 50;
		temp.CenterOfMass = 0.5f;
		temp.HorsePower = rand() % 150 + 200;
		temp.baseHorsePower = temp.HorsePower;
		temp.weigth = 1250;
		temp.downForce = 0.25;
		temp.topSpeed = 150;
		break;
	case 3:
		temp.price = rand() % 1000 + 3000;
		temp.BrakePower = rand() % 50 + 50;
		temp.CenterOfMass = 0.65f;
		temp.HorsePower = rand() % 100 + 200;
		temp.baseHorsePower = temp.HorsePower;
		temp.weigth = 1500;
		temp.downForce = 0.1;
		temp.topSpeed = 150;
		break;
	case 4:
		temp.price = rand() % 1000 + 5000;
		temp.BrakePower = rand() % 50 + 100;
		temp.CenterOfMass = 0.4f;
		temp.HorsePower = rand() % 100 + 300;
		temp.baseHorsePower = temp.HorsePower;
		temp.weigth = 1100;
		temp.downForce = 0.4;
		temp.topSpeed = 150;
		break;
	case 5:
		temp.price = rand() % 500 + 800;
		temp.BrakePower = rand() % 50 + 50;
		temp.CenterOfMass = 0.7f;
		temp.HorsePower = rand() % 30 + 120;
		temp.baseHorsePower = temp.HorsePower;
		temp.weigth = 1100;
		temp.downForce = 0.1;
		temp.topSpeed = 150;
		break;
	case 6:
		temp.price = rand() % 300 + 300;
		temp.BrakePower = rand() % 50 + 50;
		temp.CenterOfMass = 0.68f;
		temp.HorsePower = rand() % 70 + 50;
		temp.baseHorsePower = temp.HorsePower;
		temp.weigth = 900;
		temp.downForce = 0.1;
		temp.topSpeed = 150;
		break;
	case 7:
		temp.price = rand() % 500 + 800;
		temp.BrakePower = rand() % 50 + 50;
		temp.CenterOfMass = 0.67f;
		temp.HorsePower = rand() % 35 + 90;
		temp.baseHorsePower = temp.HorsePower;
		temp.weigth = 950;
		temp.downForce = 0.1;
		temp.topSpeed = 150;
		break;
	case 8:
		temp.price = rand() % 1000 + 2500;
		temp.BrakePower = rand() % 50 + 80;
		temp.CenterOfMass = 0.48f;
		temp.HorsePower = rand() % 100 + 200;
		temp.baseHorsePower = temp.HorsePower;
		temp.weigth = 1050;
		temp.downForce = 0.35;
		temp.topSpeed = 150;
		break;
	}

	temp.performanceRatio = calculate_performance(temp);
	return temp;
}