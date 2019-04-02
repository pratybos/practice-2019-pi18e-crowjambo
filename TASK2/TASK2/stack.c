#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


struct node {
	int data;
	struct node *next;
};

void greetings(int x) {
	printf("\n\n%d\n\n hello", x);
}

void displayStack(struct node *top) {
	struct node *ptr;
	ptr = top;
	if (top == NULL) {
		printf("stack is empty");
	}
	else {
		while (ptr != NULL) {
			printf("%d \n", ptr->data);
			ptr = ptr->next;
		}
	}
}

struct node *push(struct node *top, int value) {
	struct node *ptr;
	ptr = (struct node*)malloc(sizeof(struct node));
	ptr->data = value;
	if (top == NULL) {
		ptr->next = NULL;
		top = ptr;
	}
	else {
		ptr->next = top;
		top = ptr;
	}

	return top;
}

struct node *pop(struct node *top) {
	struct node *ptr;
	ptr = top;
	if (top == NULL) {
		printf("stack is empty");
	}
	else {
		top = top->next;
		free(ptr);
	}

	return top;
}

/*
int main() {

	struct node *top = NULL;

	top = push(top, 5);
	display(top);
	top = pop(top);
	display(top);


	system("pause");
	return 0;
}
*/
