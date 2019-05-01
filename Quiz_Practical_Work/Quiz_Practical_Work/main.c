#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Given two arrays:
	int array1[5] = {1, 4, 5, 2, 8};
	int array2[5] = {9, 1, 3, 2, 3};
write function to merge array1 -> 14528 and array2 -> 91323 into single digit.
multiply both numbers and output to console.
*/

void MergeArraysAndMultiply(int arr1[], int arr2[], int length1, int length2) {
	char temp[30] = { NULL };
	char combined1[30] = { NULL };
	char combined2[30] = { NULL };
	int i, num1,num2;

	for (i = 0; i < length1; i++) {
		sprintf(temp, "%d", arr1[i]);
		strcat(combined1, temp);
	}
	num1 = atoi(combined1);

	for (i = 0; i < length2; i++) {
		sprintf(temp, "%d", arr2[i]);
		strcat(combined2, temp);
	}
	num2 = atoi(combined2);
	
	printf("final outcome : %d", num1*num2);
	
}

int main(void) {
	int array1[5] = { 1, 4, 5, 2, 8 };
	int array2[5] = { 9, 1, 3, 2, 3 };

	MergeArraysAndMultiply(array1, array2, 5,5);



	printf("\n\n");
	system("pause");
	return 0;
}
