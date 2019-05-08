#include "Car.h"


Car car_init() {
	Car temp;
	temp.BrakePower = 0;
	temp.CenterOfMass = 0;
	temp.HorsePower = 0;
	strcpy_s(temp.name, 20, "None");
	return temp;
}