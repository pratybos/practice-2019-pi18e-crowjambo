/* 
TASK 2 - ADT's
EVALDAS PAULAUSKAS - PI18E group
*/


#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct stack_node {
	int data;
	struct stack_node *next;
};
typedef struct stack_node stack_node;

struct stack {
	stack_node *top;
	int size;
};
typedef struct stack stack;

stack * create_stack() {
	stack *s = (stack *)malloc(sizeof(stack));
	s->size = 0;
	s->top = NULL;
	return s;
}
// return true or false depending if stack is empty or not
bool is_stack_empty(stack *s) {
	return s->size == 0;
}

// stack to push to and a value
void push_stack(stack *s, int data) {
	stack_node *n = (stack_node*)malloc(sizeof(stack_node));
	n->data = data;
	n->next = s->top;
	s->top = n;
	s->size++;
}




int main() {


	system("pause");
	return(0);

}