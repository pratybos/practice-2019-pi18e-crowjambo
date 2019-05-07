#pragma once

enum SCENES {
	START,
	MAIN,
	HOME,
	CAR_SHOP,
	PARTS_SHOP,
	RACE
};

struct GameManager {
	int currentScene;
	int currentDay;
	int currentHour;
	float timePlayed;

};
typedef struct GameManager GameManager;