#pragma once

struct Car {
	char name[20];
	int HorsePower;
	int baseHorsePower;
	int BrakePower;
	float CenterOfMass;
	//upgrades | items
	int engineItem;
	int turboItem;
	int exhaustItem;
	int aeroItem;
	int tireItem;
	int price;
	int performanceRatio;
	float frontGrip;
	float rearGrip;
	int weigth;
	float downForce;
	int currentSpeed;
	int currentLine;
	int topSpeed;
};
typedef struct Car Car;



Car car_init();
Car car_generate();