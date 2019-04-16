/* 
TASK 2 - ADT's
EVALDAS PAULAUSKAS - PI18E group
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "Stack.h"
#include "Queue.h"


int main() {

// STACK USAGE
/*
#pragma region STACK USAGE

	// 9*(((5+8)+(8*7))+3) in postfix form = 958+87*+3+*
	stack *s = create_stack();
	char* calculate = "958+87*+3+*";
	printf("Result = %d", StackCalculation_Postfix(calculate,s));


#pragma endregion
*/

// QUEUE USAGE
/*
#pragma region QUEUE USAGE

	queue *test = create_queue();
	enqueue(test, 15);
	enqueue(test, 55);
	enqueue(test, 12);
	printf("%s", is_queue_empty(test) ? "true\n" : "false\n");
	display_queue(test);
	dequeue(test);
	display_queue(test);

#pragma endregion
*/



	printf("\n\n"); 
	system("pause");
	return(0);

}

