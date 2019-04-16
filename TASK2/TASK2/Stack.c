#include "Stack.h"

stack * create_stack() {
	stack *s = (stack *)malloc(sizeof(stack));
	s->size = 0;
	s->top = NULL;
	return s;
}

// return true or false depending if stack is empty or not
bool is_stack_empty(stack *s) {
	return s->top == NULL;
}

// stack to push to and a value
void push_stack(stack *s, int data) {
	stack_node *n = (stack_node*)malloc(sizeof(stack_node));
	n->data = data;
	n->next = s->top;
	s->top = n;
	s->size++;
}

// remove top element, and return its value as int
int pop_stack(stack *s) {
	if (is_stack_empty(s)) {
		printf("can't pop, stack is empty");
		return 0;
	}
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

int peek_stack(stack *s) {
	if (is_stack_empty(s)) {
		printf("can't peek, stack is empty");
		return;
	}
	return s->top->data;
}

void display_stack(stack *s) {
	if (is_stack_empty(s)) {
		printf("can't print, stack is empty");
		return;
	}
	// temp value for traversing the stack
	stack_node *temp = s->top;
	while (temp != NULL) {
		printf("%d \n",temp->data);
		temp = temp->next;
	}
}

// Traverse through stack and turn everything into NULL's and free nodes
void destroy_stack(stack *s){
	if (is_stack_empty(s)) {
		s->size = NULL;
		s->top = NULL;
		free(s);
		return;
	}
	stack_node *current = s->top;
	stack_node *next;
	while (current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}
	s->size = NULL;
	s->top = NULL;
	free(s);
}

int StackCalculation_Postfix(char* exp, stack* s) {
	for (int i = 0; i < strlen(exp); i++) {
		// if current char is operator, pop 2 from stack and perform the needed operation
		if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
			int number2 = pop_stack(s);
			int number1 = pop_stack(s);
			// performing operation here
			int result = Calculate(exp[i], number1, number2);
			// push the result back to stack
			push_stack(s, result);
		}
		// if char is number push it to stack
		else {
			// - '0' to convert chars to ints 
			int number = exp[i] - '0';
			push_stack(s, number);
		}
	}
	return peek_stack(s);
}

// Basic if statements to determine which operation to perform
int Calculate(char* operation, int number1, int number2) {
	if (operation == '+') {
		return number1 + number2;
	}
	else if (operation == '-') {
		return number1 - number2;
	}
	else if (operation == '*') {
		return number1 * number2;
	}
	else if (operation == '/') {
		return number1 / number2;
	}

}