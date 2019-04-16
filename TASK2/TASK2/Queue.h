#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct queue_node {
	int data;
	struct queue_node *next;
};
typedef struct queue_node queue_node;

struct queue {
	queue_node *front;
	queue_node *back;
	int size;
};
typedef struct queue queue;

// FUNCTIONS
queue *create_queue();
bool is_queue_empty(queue *q);
void push_queue(queue *q, int data);
int pop_queue(queue *q);
void destroy_queue(queue *q);
void display_queue(queue *q);
