#include "RaceManager.h"

RaceManager RaceManager_init() {
	RaceManager temp;
	temp.chosenAccel = 1;
	temp.chosenBrake = 1;
	temp.chosenLine = 1;

	return temp;
}