/*

TASK 4 - EVALDAS PAULAUSKAS PI18E

*/
#include "UtilityLibs.h"
#include "HashTable.h"

//void ht_insert(ht_hash_table* ht, const char* key, const char* value);
//char* ht_search(ht_hash_table* ht, const char* key);

//filter some information by column data : ascending or descending order;
//implement Map Abstract Data Type and use it;
//search by keyword;

int main() {
	testStruct someShit;
	strcpy_s(someShit.name, 20, "SomeName");
	someShit.number = 10;
	ht_hash_table* ht = ht_new();
	//ht_insert(ht, "Cat", "big");
	//ht_insert(ht, "Bobo", "small");
	//printf("Search result : %s \n", ht_search(ht,"Cat"));
	ht_insert(ht, "Cat", &someShit);
	
	testStruct *previewStruct = ht_search(ht, "Cat");
	printf("Some values %s %d \n", previewStruct->name, previewStruct->number);

	system("pause");
	return 0;
}