#pragma once

struct RaceManager {
	int chosenAccel;
	int chosenBrake;
	int chosenLine;
};
typedef struct RaceManager RaceManager;


RaceManager RaceManager_init();