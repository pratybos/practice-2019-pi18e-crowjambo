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
#pragma region FUNCTIONS
enum SortOrder
{
	Descending,
	Ascending
	
};
enum SortBy {
	FirstName,
	LastName,
	Group
};

void Instructions() {
	printf("1 - Show all records \n 2 - Show records in Descending order \n 3 - Show records in Ascending order \n 4 - full name(keyword) search \n 5 - Exit program \n");
}
void PrintColumns() {
	printf("First Name | Last Name | Group Name | Age |\n -----------------------------------------\n");
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
				printf("%s   | %s   | %s | %d |\n", tempNode->data.name, tempNode->data.lastName, tempNode->data.groupName, tempNode->data.age);
				tempNode = tempNode->next;
			}
		}

	}
}
struct list_node* swap(struct list_node* ptr1, struct list_node* ptr2)
{
	struct list_node* tmp = ptr2->next;
	ptr2->next = ptr1;
	ptr1->next = tmp;
	return ptr2;
}
int bubbleSort(struct list_node** head, int count, int sortBy, int orderBy){
	struct list_node** h;
	int i, j, swapped;
	for (i = 0; i <= count; i++) {
		h = head;
		swapped = 0;
		for (j = 0; j < count - i - 1; j++) {
			struct list_node* p1 = *h;
			struct list_node* p2 = p1->next;

			switch (orderBy) {
			//descending order
			case 0:
				switch (sortBy) {
				//by name
				case 0:
					if (strcmp(p1->data.name, p2->data.name) > 0) {
						/* update the link after swapping */
						*h = swap(p1, p2);
						swapped = 1;
					}
					break;
				//by lastName
				case 1:
					if (strcmp(p1->data.lastName, p2->data.lastName) > 0) {
						/* update the link after swapping */
						*h = swap(p1, p2);
						swapped = 1;
					}
					break;
				//by group
				case 2:
					if (strcmp(p1->data.groupName, p2->data.groupName) > 0) {
						/* update the link after swapping */
						*h = swap(p1, p2);
						swapped = 1;
					}
					break;
				}
				break;
			//ascending order
			case 1:
				switch (sortBy) {
				//by name
				case 0:
					if (strcmp(p1->data.name, p2->data.name) < 0) {

						/* update the link after swapping */
						*h = swap(p1, p2);
						swapped = 1;
					}
					break;
				//by lastname
				case 1:
					if (strcmp(p1->data.lastName, p2->data.lastName) < 0) {

						/* update the link after swapping */
						*h = swap(p1, p2);
						swapped = 1;
					}
					break;
				//by group
				case 2:
					if (strcmp(p1->data.groupName, p2->data.groupName) < 0) {

						/* update the link after swapping */
						*h = swap(p1, p2);
						swapped = 1;
					}
					break;
				}
				break;
			}
	
			h = &(*h)->next;
		}

		/* break if the loop ended without any swap */
		if (swapped == 0)
			break;
	}
}

void sortTest(ht_hash_table *temp, int sortBy, int orderBy) {
	int i = 0;
	//Init a list
	list *someList = create_list();
	list_node *tempNode = NULL;

	//read through hashtable
	for (i = 0; i < temp->size; i++) {
		if (temp->items[i] != NULL) {
			tempNode = temp->items[i]->value;
		}
		else {
			//insert each hashtable node into new list
			while (tempNode != NULL) {
				list_insert_at_front(someList, tempNode->data);
				//navigate through child nodes in hashtable aswell
				tempNode = tempNode->next;
			}
		}
	}

	bubbleSort(&someList->head, someList->size,sortBy,orderBy);

	tempNode = someList->head;
	while (tempNode != NULL) {
	printf("%s %s %s %d \n", tempNode->data.name, tempNode->data.lastName, tempNode->data.groupName, tempNode->data.age);
	tempNode = tempNode->next;
	
	}
}

#pragma endregion

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
	int sortBy = 0;
	char searchName[20];
	char searchLastN[20];
	list_node *temp = NULL;
	list_node *sortedList = NULL;

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
			system("cls");
			printf("Sort by : 0 - FirstName ; 1 - LastName ; 2 - Group \n");
			scanf_s("%d", &sortBy);
			system("cls");
			sortTest(ht, sortBy, Descending);
			_fgetchar();
			_fgetchar();
			break;
		case 3:	
			system("cls");
			printf("Sort by : 0 - FirstName ; 1 - LastName ; 2 - Group \n");
			scanf_s("%d", &sortBy);
			system("cls");
			sortTest(ht, sortBy, Ascending);
			_fgetchar();
			_fgetchar();
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