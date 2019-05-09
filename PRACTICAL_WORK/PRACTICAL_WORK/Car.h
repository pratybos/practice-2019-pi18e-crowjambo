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
	int price;
};
typedef struct Car Car;



Car car_init();
Car car_generate();