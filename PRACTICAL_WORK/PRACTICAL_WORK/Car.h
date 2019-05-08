#pragma once

struct Car {
	char name[20];
	int HorsePower;
	int BrakePower;
	float CenterOfMass;
	//upgrades | items
	int engineItem;
	int turboItem;
	int exhaustItem;
	int aeroItem;
	int tireItem;
};
typedef struct Car Car;

Car car_init();