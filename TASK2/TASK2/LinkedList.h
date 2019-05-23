#pragma once

#include "UtilityLibs.h"

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct list_node {
	int data;
	struct list_node *next;
};
typedef struct list_node list_node;

struct list {
	list_node *head;
	int size;
};
typedef struct list list;

//FUNCTIONS
list *create_list();
list_node *createNewListNode(int data);
bool is_list_empty(list *list);
void list_insert_at_front(list *list, int data);
void list_insert_at_back(list *list, int data);
void list_display(list *list);
void list_remove_first(list *list);
void list_remove_last(list *list);
float list_average_value(list *_list);















#endif
