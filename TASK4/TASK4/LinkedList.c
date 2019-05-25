#include "LinkedList.h"


list *create_list() {
	list *temp = (list*)malloc(sizeof(list));
	temp->head = NULL;
	temp->size = 0;
	return temp;
}

//create an unconnected list node with data
list_node *createNewListNode(int data) {
	list_node *temp = (list_node*)malloc(sizeof(list_node));
	temp->data = data;
	temp->next = NULL;
}

bool is_list_empty(list *list) {
	return list->size == 0;
}

void list_insert_at_front(list *list, int data) {
	list_node *temp = createNewListNode(data);
	temp->next = list->head;
	list->head = temp;
	list->size++;
}

void list_insert_at_back(list *list, int data) {
	list_node *temp = createNewListNode(data);
	list_node *p = list->head;
	while (p != NULL && p->next != NULL) {
		p = p->next;
	}
	// if list is empty, just assign it as the first/head element
	if (p == NULL) {
		list->head = temp;
	}
	p->next = temp;
	list->size++;
}

void list_display(list *list) {
	list_node *temp = list->head;
	while (temp != NULL) {
		printf("value: %d \n", temp->data);
		temp = temp->next;
	}
}

void list_remove_first(list *list) {
	if (is_list_empty(list)) {
		return;
	}
	list_node *temp = list->head;
	list->head = list->head->next;
	list->size--;
	free(temp);
}

void list_remove_last(list *list) {
	if (is_list_empty(list)) {
		return;
	}
	//only one element
	if (list->head->next == NULL) {
		free(list->head);
		list->head = NULL;
	}

	list_node *temp = list->head;
	//traversal through list to the 1 before last node
	while (temp->next->next != NULL) {
		temp = temp->next;
	}
	// free the node which goes after the 1 before last node ( the last node )
	free(temp->next);
	//reset next pointer to NULL
	temp->next = NULL;
	list->size--;
}
