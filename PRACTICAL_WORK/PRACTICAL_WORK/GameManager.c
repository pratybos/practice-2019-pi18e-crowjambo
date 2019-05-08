#include "GameManager.h"

GameManager GameManager_Init() {
	GameManager mng;
	mng.currentScene = START;
	mng.currentDay = MONDAY;
	mng.currentHour = 8;
	mng.timePlayed = 0;
	return mng;
}