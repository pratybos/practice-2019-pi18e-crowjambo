#include "Queue.h"

queue *create_queue() {
	queue *q = (queue*)malloc(sizeof(queue));
	q->back = q->front = NULL;
	q->size = 0;
	return q;
}

bool is_queue_empty(queue *q) {
	return q->size == 0;
}

void enqueue(queue *q, int data) {
	queue_node *temp = (queue_node *)malloc(sizeof(queue_node));
	temp->next = NULL;
	temp->data = data;
	//if empty make new node be both front and back
	if (is_queue_empty(q)) {
		q->back = q->front = temp;
	}
	//if not empty
	else {
		//make current BACK node face the new last node
		q->back->next = temp;
		//replace the MAIN back node, with the new last node address
		q->back = temp;
	}
	q->size++;
}

// pops and returns value of recent pop
int dequeue(queue *q) {
	if (is_queue_empty(q)) {
		printf("Queue is empty, can't pop");
		return 0;
	}
	int tempValue = q->front->data;
	// temp pointer to take place of current front for deletion
	queue_node *temp = q->front;
	// new front will be node current front is pointing to next
	q->front = q->front->next;
	// free the address that current front node was taking
	free(temp);
	q->size--;
	return tempValue;
}

void destroy_queue(queue *q) {
	if (is_queue_empty(q)) {
		q->back = NULL;
		q->front = NULL;
		q->size = NULL;
		free(q);
		return;
	}
	queue_node *current = q->front;
	queue_node *next;
	while (current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}
	q->back = NULL;
	q->front = NULL;
	q->size = NULL;
	free(q);
}

void display_queue(queue *q) {
	if (is_queue_empty(q)) {
		printf("empty queue");
		return;
	}
	queue_node *temp = q->front;
	while (temp != NULL) {
		printf("%d\n", temp->data);
		temp = temp->next;
	}
}
