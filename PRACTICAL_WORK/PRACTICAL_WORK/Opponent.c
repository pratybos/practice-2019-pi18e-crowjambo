#include "Opponent.h"
#include <stdlib.h>
#include <string.h>

char *peopleNames[6] = { "Takumi", "Bob", "Indigo", "Crow", "Julian", "Big" };
char *peopleLastNames[5] = { "Fujiwara", "Jam" , "Slow" , "Fast", "No Idea"};

Opponent opponent_init() {
	Opponent temp;
	//car gen
	temp.car = car_generate();

	//random first and last name generation into single char
	char tempTemp[30];
	int x = rand() % 5;
	strcpy_s(temp.name, 30, peopleNames[x]);
	x = rand() % 4;
	strcpy_s(tempTemp, 30, peopleLastNames[x]);
	strcat_s(temp.name, 30, tempTemp);

	//map gen


	return temp;
}


