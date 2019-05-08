#pragma once
#include "MainLibs.h"

enum SCENES {
	START,
	MAIN,
	HOME,
	CAR_SHOP,
	PARTS_SHOP,
	RACE
};

enum DAYS {
	MONDAY = 1,
	TUESDAY,
	WEDNESDAY,
	THURSDAY,
	FRIDAY,
	SATURDAY,
	SUNDAY
};

struct GameManager {
	int currentScene;
	int currentDay;
	int currentHour;
	float timePlayed;

};
typedef struct GameManager GameManager;


//functions
GameManager GameManager_Init();