#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};

struct node *createNode() {
	struct node *newNode;
	newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = rand() % 10;
	newNode->next = NULL;
	return newNode;
};

struct node *createList(struct node *start, size_t size) {
	struct node* newNode, *ptr;
	int i;

	for (i = 0; i < size; i++) {
		newNode = createNode();
		if (start == NULL) {
			start = newNode;
		}
		else {
			ptr = start;
			while (ptr->next != NULL) {
				ptr = ptr->next;
			}
			ptr->next = newNode;
		}
	}
	return start;
};

void displayList(struct node *start) {
	struct node *ptr;
	int i;
	ptr = start;

	while (ptr != NULL) {
		printf("%d \n", ptr->data);
		ptr = ptr->next;
	}
};

struct node *insertAtBeg(struct node *start) {
	struct node *newNode;
	newNode = createNode();
	newNode->next = start;
	start = newNode;
	return start;
};

struct node *insertAtEnd(struct node *start) {
	struct node *ptr, *newNode;
	newNode = createNode();
	ptr = start;
	while (ptr->next != NULL) {
		ptr = ptr->next;
	}
	ptr->next = newNode;

	return start;
};

struct node *deleteEnd(struct node *start) {
	struct node *ptr, *preptr = NULL;
	ptr = start;

	while (ptr->next != NULL) {
		preptr = ptr;
		ptr = ptr->next;
	}
	preptr->next = NULL;
	free(ptr);

	return start;
};

int main() {
	struct node *start = NULL;
	start = createList(start, 5);
	displayList(start);
	printf("\n -------- \n");
	start = insertAtBeg(start);
	displayList(start);
	printf("\n -------- \n");
	start = insertAtEnd(start);
	displayList(start);
	printf("\n -------- \n");
	start = deleteEnd(start);
	displayList(start);

	system("pause");
	return 0;
};