#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


float CalculateSigma(int k) {

	int n;
	float sum = 0;
	for (n = 1; n <= k; n++) {
		sum += (2 * n + 1)*(n - 2);
		printf("curent sum %.1f\n", sum);
	}
	return sum;
}

int main() {

	printf("\n Final Result = %.1f", CalculateSigma(5));

	return 0;
}

/*

1

void longOutputFunction(){
  long number = 0b10101L;
  printf("%li", number);
}

====================================================================================================
2

void ArrayPrintOutFromTheBack(int x, int arr[], int arrSize){
	int i;
	for(i=0; i<x ; i++ ){
		printf("\t %d", arr[arrSize-i]);
	}
}

int main(void) {
  int arrayTest[6]= {98, 78, 55, 22, 44, 66};
  ArrayPrintOutFromTheBack(2, arrayTest,6);

  return 0;
}

====================================================================================================

3

void CopyToArray(int src[], int dest[], int srcLength) {

	int i;
	for (i = 0; i < srcLength; i++) {
		if (src[i] == 0) {
			dest[i] = -1;
		}
		else {
			dest[i] = src[i];
		}
	}
}

int main() {

	int temp[10] = { 5, 5, 9, 1, 2, 3 };
	int source[40];

	CopyToArray(temp, source, sizeof(temp)/sizeof(temp[0]));

	int i;
	for (i = 0; i < 40; i++) {
		printf("final values : %d \n", source[i]);
	}


	printf("\n\n");
	system("pause");
	return 0;
}

====================================================================================================

4

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int NumberGenerator(){
  int number, choice;
  while(1){
	number = rand()%100;
	printf("Number generated: %d \n", number);
	printf("Any key to continue. N or n to stop\n");

	choice = getchar();
	if(choice == 'n' || choice == 'N') return number;
  }
}

int main(void) {
  srand(time(0));

  int randomNumber = NumberGenerator();
  printf("final number is %d", randomNumber);


  return 0;
}

====================================================================================================

5

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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


====================================================================================================

6

yes its correct

====================================================================================================

7

all true

====================================================================================================

8

1. c = 65 due too ++c call, in %c (char form) = A ; 2. c = 66 in %c form = B 3. c=67 = C ; 4. c=68 = D ; 5. c=69 = E

====================================================================================================

9

float CalculateSigma(int k) {

	int n;
	float sum = 0;
	for (n = 1; n <= k; n++) {
		sum += (2 * n + 1)*(n - 2);
		printf("curent sum %.1f\n", sum);
	}
	return sum;
}

int main() {

	printf("\n Final Result = %.1f", CalculateSigma(5));

	return 0;
}

====================================================================================================


10

1. Goodbye!Hello  2.Goodbye!Hello 3.Goodbye!Hello 4.Goodbye!Hello
First program enters infinite loop("hello") and prints Goodbye, then enters secondary loop("Goodbye") which prints "Hello " and breaks, which returns to the first infinite loop("hello") and prints everything again over and over infinitely.

====================================================================================================


*/