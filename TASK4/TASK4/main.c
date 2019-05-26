/*

TASK 4 - EVALDAS PAULAUSKAS PI18E

*/
#define _CRT_SECURE_NO_WARNINGS
#include "UtilityLibs.h"
#include "HashTable.h"
#include "LinkedList.h"
#include "Student.h"

//void ht_insert(ht_hash_table* ht, const char* key, const char* value);
//char* ht_search(ht_hash_table* ht, const char* key);

//filter some information by column data : ascending or descending order;
//implement Map Abstract Data Type and use it;
//search by keyword;

//just example
char *groups[] = { "PI18E", "PI18A", "PI18B", "PI18C", "PI18D" };

list_node *searchTest(ht_hash_table *ht , char *searchLastName, char *searchName) {
	int found = 0;
	list_node *temp = ht_search(ht, searchLastName);
	while (temp != NULL && !found) {
		if (strcmp(temp->data.name, searchName) == 0) {
			found = 1;
			return temp;
		}
		temp = temp->next;
	}
	return NULL;

}

int main() {

	#pragma region INIT

	srand(time(0));
	int i = 0;
	//initialize table
	ht_hash_table *ht = ht_new();


	//POPULATE THE TABLE
	FILE *fp;
	char str[100];
	char *fileName = "C:\\students.txt";
	fopen_s(&fp, fileName, "r");
	char _name[20];
	char _lastName[20];
	int counter = 0;
	//will read and store each new line in str 
	while (fgets(str, 100, fp) != NULL) {
		//remove new line token out of each line read
		strtok(str, "\n");
		//write first name, last name, first name etc;
		if (counter == 1) {
			strcpy_s(_lastName, 20, str);
			counter--;
			custom_ht_insert(ht, _name, _lastName, rand() % 10 + 18, groups[rand() % 5]);
		}
		else {
			strcpy_s(_name, 20, str);
			counter++;
		}

	}
	fclose(fp);

	#pragma endregion

	////print out all values
	//for (i = 0; i < ht->size; i++) {
	//ht_item* item = ht->items[i];
	//if (item != NULL) {
	//while (item->value != NULL) {
	//		printf("NR : %d || %s %s %d %s\n", i,item->value->data.name, item->value->data.lastName, item->value->data.age, item->value->data.groupName);
	//		item->value = item->value->next;
	//		}
	//	}
	//}
	//printf("\n\n how many keys - %d , what size - %d\n", ht->count, ht->size);


	//for (i = 0; i < ht->size; i++) {
	//	ht_item* item = ht->items[i];
	//	if (item != NULL) {
	//		printf("KEY %d : %s \n", i,item->key);	
	//	}
	//}

	printf("RESULT : %s \n", ht_search(ht, "Ramsey")->data.name);



#pragma region TESTS

	//testStruct someShit;
	//strcpy_s(someShit.name, 20, "SomeName");
	//someShit.number = 10;
	//ht_hash_table* ht = ht_new();
	////ht_insert(ht, "Cat", "big");
	////ht_insert(ht, "Bobo", "small");
	////printf("Search result : %s \n", ht_search(ht,"Cat"));
	//ht_insert(ht, "Cat", &someShit);
	//
	//testStruct *previewStruct = ht_search(ht, "Cat");
	//printf("Some values %s %d \n", previewStruct->name, previewStruct->number);

	//void custom_ht_insert(ht_hash_table* ht, char *name, char *lastName, int age, char *groupName);
	//ht_hash_table *ht = ht_new();
	//custom_ht_insert(ht, "Evaldas", "Paulauskas", 25, "PI18E");
	//custom_ht_insert(ht, "Arturas", "Paulauskas", 26, "EMPLOYED");
	//custom_ht_insert(ht, "TetTest", "Paulauskas", 26, "EMPLOYED");
	//custom_ht_insert(ht, "345", "Paulauskas", 26, "EMPLOYED");
	//custom_ht_insert(ht, "Skanus", "Oboluys", 26, "EMPLOYED");


	//printf("Searching for Paulauskas... \n results : %s \n %s \n %s \n %d \n", ht_search(ht, "P")->data.name, ht_search(ht, "P")->data.lastName, ht_search(ht, "P")->data.groupName, ht_search(ht, "P")->data.age);


	//printf("Searching for Paulauskas... \n results :\n %s \n %s \n %s \n %d \n", custom_ht_search(ht, "Paulauskas")->data.name, custom_ht_search(ht, "Paulauskas")->data.lastName, custom_ht_search(ht, "Paulauskas")->data.groupName, custom_ht_search(ht, "Paulauskas")->data.age);

	//printf("\n results :\n %s \n" , custom_ht_search(ht, "Paulauskas")->next->data.name);

	//printf(" %d %d \n\n", ht->count, ht->size);


	//function to print out all items
	//for (i = 65; i < 91; i++) {
	//	//ht->items[0]->value->data.name;
	//	//printf("%c", i);
	//	//iterate through hashtable in alphabetical order
	//	char *testKey = (char*)&i;
	//	list_node *testTest = custom_ht_search(ht, testKey);
	//	while (testTest != NULL) {
	//		printf("%s %s \n\n", testTest->data.name, testTest->data.lastName);
	//		testTest = testTest->next;
	//	}

	//}

	//ITERATE THROUGH THE WHOLE HASH TABLE and print out values
	//for (i = 0; i < ht->size; i++) {
	//	ht_item* item = ht->items[i];
	//	if (item != NULL) {
	//		while (item->value != NULL) {
	//			printf("%s %s \n\n", item->value->data.name, item->value->data.lastName);
	//			item->value = item->value->next;
	//		}
	//	}
	//}


		//for (i = 0; i < ht->size; i++) {
	//ht_item* item = ht->items[i];
	//if (item != NULL) {
	//	while (item->value != NULL) {
	//		printf("%s %s %d %s\n", item->value->data.name, item->value->data.lastName, item->value->data.age, item->value->data.groupName);
	//		item->value = item->value->next;
	//		}
	//	}
	//}


#pragma endregion

	




	system("pause");
	return 0;
}