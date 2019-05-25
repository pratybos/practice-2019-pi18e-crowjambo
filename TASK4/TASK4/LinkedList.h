#pragma once
#include "UtilityLibs.h"
#include "Student.h"

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct list_node {
	Student data;
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
list_node *createNewListNode(Student data);
bool is_list_empty(list *list);
void list_insert_at_front(list *list, Student data);
void list_insert_at_back(list *list, Student data);
void list_display(list *list);
void list_remove_first(list *list);
void list_remove_last(list *list);

















#endif
