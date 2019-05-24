/*

TASK 4 - EVALDAS PAULAUSKAS PI18E

*/
#include "HashTable.h"
#include <stdlib.h>
#include <stdio.h>
#define HT_INITIAL_BASE_SIZE 50

//void ht_insert(ht_hash_table* ht, const char* key, const char* value);
//char* ht_search(ht_hash_table* ht, const char* key);

int main() {

	ht_hash_table* ht = ht_new();
	ht_insert(ht, "Cat", "big");
	ht_insert(ht, "Bobo", "small");
	printf("Search result : %s \n", ht_search(ht,"Cat"));


	system("pause");
	return 0;
}