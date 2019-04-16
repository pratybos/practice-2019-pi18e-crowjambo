#include "Stack.h"

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

int pop_stack(stack *s) {
	// store data of node that is going to be deleted
	int data = s->top->data;
	// saving address of current top node to free it later
	stack_node *temp = s->top;
	// Moving the current top to the next one
	s->top = s->top->next;
	s->size--;
	free(temp);
	return data;
}
