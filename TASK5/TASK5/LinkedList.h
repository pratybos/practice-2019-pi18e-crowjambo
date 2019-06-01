#pragma once

#include "UtilityLibs.h"


#ifndef LINKEDLIST_H
#define LINKEDLIST_H
typedef struct {
	char question[100];
	char answer[20];
}testStruct;

struct list_node {
	testStruct testData;
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
list_node *createNewListNode(testStruct data2);
bool is_list_empty(list *list);
void list_new_insert(list *tempList, testStruct someData);


//void list_insert_at_front(list *list, int data);
//void list_insert_at_back(list *list, tree_node *data);
////void list_display(list *list);
//void list_remove_first(list *list);
//void list_remove_last(list *list);
//float list_average_value(list *_list);



#endif
