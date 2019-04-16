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
	stack *s = create_stack();

	// 9*(((5+8)+(8*7))+3)
	push_stack(s, 9);
	push_stack(s, 5);
	push_stack(s, 8);
	push_stack(s, pop_stack(s) + pop_stack(s));
	push_stack(s, 8);
	push_stack(s, 7);
	push_stack(s, pop_stack(s)*pop_stack(s));
	push_stack(s, pop_stack(s) + pop_stack(s));
	push_stack(s, 3);
	push_stack(s, pop_stack(s) + pop_stack(s));
	push_stack(s, pop_stack(s)*pop_stack(s));
	display_stack(s);
#pragma endregion
*/

// QUEUE USAGE
/*
#pragma region QUEUE USAGE

	queue *test = create_queue();
	push_queue(test, 15);
	push_queue(test, 55);
	push_queue(test, 12);
	printf("%s", is_queue_empty(test) ? "true\n" : "false\n");
	display_queue(test);
	pop_queue(test);
	display_queue(test);

#pragma endregion
*/



	printf("\n\n"); 
	system("pause");
	return(0);

}