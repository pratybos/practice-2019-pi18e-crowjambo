#pragma once
#include "UtilityLibs.h"

#ifndef STUDENT_H
#define STUDENT_H

typedef struct {
	char name[20];
	char lastName[20];
	int age;
	char groupName[10];
}Student;

//FUNCTIONS
Student student_create(char name, char lastName, int age, char groupName);






#endif