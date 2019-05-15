#pragma once
#include "Car.h"
#include "Map.h"

struct Opponent {
	Car car;
	char name[30];
	
};
typedef struct Opponent Opponent;



Opponent opponent_init();