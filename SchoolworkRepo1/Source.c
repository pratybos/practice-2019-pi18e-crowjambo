/*
ARMSTRONG ALGORHITHM implementation in C
EVALDAS PAULAUAS PI18E
1/5/2019
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main() {

	int number, tempNumber, remainder, result = 0, counter = 0;

	printf("Enter an integer: ");
	scanf_s("%d", &number);

	tempNumber = number;

	while (tempNumber != 0)
	{
		tempNumber /= 10;
		++counter;
	}

	tempNumber = number;

	while (tempNumber != 0)
	{
		remainder = tempNumber % 10;
		printf("\n remainder %d", remainder);
		result += pow(remainder, counter);
		printf("\n result %d", result);
		tempNumber /= 10;
		printf("\n temp number %d \n", tempNumber);
	}

	if (result == number)
		printf("%d is an Armstrong number. \n", number);
	else
		printf("%d is not an Armstrong number. \n", number);

	system("pause");

	return 0;
}