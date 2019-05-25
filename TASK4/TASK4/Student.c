#include "Student.h"


Student student_create(char *name, char *lastName, int age, char *groupName) {
	Student temp;
	temp.age = age;
	strcpy_s(temp.name, 20, name);
	strcpy_s(temp.lastName, 20, lastName);
	strcpy_s(temp.groupName, 10, groupName);
	return temp;
}