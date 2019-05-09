#pragma once
#include "Car.h"
#include "Button.h"


struct CarListing{
	Car car;
	//Button buyBtn;
};
typedef struct CarListing CarListing;



CarListing generateListing();

