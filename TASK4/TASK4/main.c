/*

TASK 4 - EVALDAS PAULAUSKAS PI18E

//filter some information by column data : ascending or descending order;
//implement Map Abstract Data Type and use it;
//search by keyword;

*/
#pragma region HEADERS

#define _CRT_SECURE_NO_WARNINGS
#include "UtilityLibs.h"
#include "HashTable.h"
#include "LinkedList.h"
#include "Student.h"

#pragma endregion

/*
TODO:
	- print out columns/table data
	- using switch + loop have UI to select actions of sorting in descending/ascending order and keyword search and display all elements and quit program

*/

void Instructions() {
	printf("1 - Show all records \n 2 - Show records in Descending order \n 3 - Show records in Ascending order \n 4 - full name(keyword) search \n 5 - Exit program \n");
}
void PrintColumns() {
	printf("First Name | Last Name | Group Name | Age |\n -----------------------------------------");
}


void PrintAllValues(ht_hash_table *temp) {
	int i = 0;
	list_node *tempNode = NULL;
	for (i = 0; i < temp->size; i++) {
		if (temp->items[i] != NULL) {
			tempNode = temp->items[i]->value;
		}
		else {
			while (tempNode != NULL) {
				printf("\n%s   | %s   | %s | %d |\n", tempNode->data.name, tempNode->data.lastName, tempNode->data.groupName, tempNode->data.age);
				tempNode = tempNode->next;
			}
		}

	}
}


int main() {

	#pragma region INIT

	srand(time(0));
	int i = 0;
	//initialize table
	ht_hash_table *ht = ht_new();
	char *groups[] = { "PI18E", "PI18A", "PI18B", "PI18C", "PI18D" };

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
	#pragma region Variables

	bool finished = false;
	int choice = 0;
	char searchName[20];
	char searchLastN[20];
	list_node *temp = NULL;

	#pragma endregion
	#pragma region MAIN_LOOP

	while (!finished) {
		//MAIN MENU
		system("cls");
		Instructions();
		//INPUT
		printf("--------------------------------------\nMake a choice : ");
		choice = _getch()-48;
		//LOGIC
		switch (choice) {
		case 1:
			system("cls");
			PrintColumns();
			PrintAllValues(ht);
			_fgetchar();
			break;
		case 2:
			//descending order list(by last name)
			break;
		case 3:
			//ascending order list (by last name)
			break;
		case 4:
			system("cls");
			printf("Enter first name : ");
			fgets(searchName, 20, stdin);
			printf("Enter last name: ");
			fgets(searchLastN, 20, stdin);
			//clean up of newline symbols
			strtok(searchName, "\n");
			strtok(searchLastN, "\n");
			//create temp variable to hold found person
			temp = custom_ht_search_fullName(ht, searchLastN, searchName);
			//print out value + error check
			if (temp != NULL) {
				printf("\n%s %s %s %d", temp->data.name, temp->data.lastName, temp->data.groupName, temp->data.age);
			}
			else {
				printf("Record wasn't found");
			}

			//make sure key needs to be pressed to return to main menu
			_fgetchar();
			
			break;
		case 5:
			finished = true;
			break;
		}
	}

	#pragma endregion

#pragma region TESTS

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
	
	return 0;
}