#pragma once
#include "UtilityLibs.h"
#include "Student.h"
#include "LinkedList.h"


//key value pairs
//typedef struct {
//	char* key;
//	char* value;
//} ht_item;

//key value pairs
typedef struct {
	char* key;
	list_node* value;
} ht_item;

//table stores an array of pointers to items, and some details about its size and how full it is
typedef struct {
	//this gets autoset with define in hashtable.c to 50
	int base_size;
	int size;
	int count;
	ht_item** items;
} ht_hash_table;


//Methods
void ht_insert(ht_hash_table* ht, const char* key, list_node* value);
list_node* ht_search(ht_hash_table* ht, const char* key);
void ht_delete(ht_hash_table* h, const char* key);
void ht_del_hash_table(ht_hash_table* ht);
ht_hash_table* ht_new();

//CUSTOM
void custom_ht_insert(ht_hash_table* ht, char *name, char *lastName, int age, char *groupName);
list_node* custom_ht_search(ht_hash_table* ht, const char *searchValue);


