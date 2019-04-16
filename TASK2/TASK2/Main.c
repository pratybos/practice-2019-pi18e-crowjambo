/* 
TASK 2 - ADT's
EVALDAS PAULAUSKAS - PI18E group
*/


#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "Stack.h"


int main() {

	stack *s = create_stack();
	push_stack(s, 5);
	printf("%d\n", s->top->data);

	printf("\n\n"); 
	system("pause");
	return(0);

}