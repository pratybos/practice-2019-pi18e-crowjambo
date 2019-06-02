#define _CRT_SECURE_NO_WARNINGS
#include "UtilityLibs.h"
#include "testHeader.h"

//Create a console program that can guess your invented word for a freely chosen topic


typedef struct {
	char input[100];
}InputStruct;

int main() {

	//FILES
	FILE *outfile = NULL;

	//VARS
	bool finished = false;
	bool takenInput = false;
	bool anotherInput = false;
	char input = 'z';
	char question[100];
	char answer[20];
	int i = 0;
	//INIT, note -  root is NULL 
	tree *someTree = create_tree();

	//user input replay data
	InputStruct userInput;
	int inputCounter = 0;


#pragma region Reading already written data

	//populate input data
	outfile = fopen("input.dat", "r");
	if (outfile != NULL) {
		//while (fread(&userInput, sizeof(userInput), 1, outfile)) {}
		fread(&userInput, sizeof(userInput), 1, outfile);
		fclose(outfile);
	}

	//populate list w values
	outfile = fopen("data.dat", "r");
	if (outfile != NULL) {
		testStruct forReadingINTRO;
		list *readingList = create_list();
		//read data.dat into forReadingINTRO struct and append to linkedList
		while (fread(&forReadingINTRO, sizeof(testStruct), 1, outfile)) {
			//printf("%s %s \n ", forReading.question, forReading.answer);
			//each binary tree node was written to list, and now being read and added to list again
			list_new_insert(readingList, forReadingINTRO);
		}
		fclose(outfile);

		//Create binary tree using input data and list data
		int anotherCounter = 0;

		//traversal node
		list_node *listTraversal = readingList->head;

		//add root before this loop
		//start appending afterwards
		set_root(someTree, listTraversal->testData.question, listTraversal->testData.answer);
		//move up after root by a step in list
		listTraversal = listTraversal->next;
		//set root traversal node
		tree_node *treeTarversal = someTree->root;

		//find the end of user input
		char someChar = 'y';
		//while theres user input data in array
		while (someChar == 'y' || someChar == 'n' || someChar == 'e') {
			//if end of session symbol
			if (userInput.input[anotherCounter] == 'e') {
				//reset binary tree traversal to beginning
				treeTarversal = someTree->root;
			}

			else if (userInput.input[anotherCounter] == 'y') {
				insert_left(treeTarversal, listTraversal->testData.question, listTraversal->testData.answer);
				//move up to the left
				treeTarversal = treeTarversal->left_child;
			}
			else if (userInput.input[anotherCounter] == 'n') {
				insert_right(treeTarversal, listTraversal->testData.question, listTraversal->testData.answer);
				//move up to the right
				treeTarversal = treeTarversal->right_child;
			}

			//read next stored input
			anotherCounter++;
			someChar = userInput.input[anotherCounter];
			//next list value
			if (listTraversal->next != NULL) {
				listTraversal = listTraversal->next;
			}
		}
		inputCounter = anotherCounter;

	}
	//no data.dat
	else {
		set_root(someTree, "First Question", "None");
	}

#pragma endregion



	//Car buying expert system
	printf("Welcome to car buying expert system, y for Yes n for No\n");

	//navigator node init
	tree_node *currentNode = someTree->root;

	//modifier var
	bool isModified = false;

	//main loop
	while (!finished) {
		takenInput = false;
		anotherInput = false;

		//if string NOT None, print answer
		if (strcmp(currentNode->data.answer,"None")) {
			printf("My guess : %s\n", currentNode->data.answer);
			finished = true;
			continue;
		}
		printf("%s\n", currentNode->data.question);
		
		//loop for input, fixes double print bug
		while (!takenInput) {
			input = _getch();
			if (input == 'y') {
				userInput.input[inputCounter] = 'y';
				inputCounter++;
				//next node is empty(append new answers/questions)
				if (currentNode->left_child == NULL) {
					printf("Add question[1] or answer[2]?\n");

					while (!anotherInput) {
						input = _getch();
						if (input == '1') {
							printf("Enter Question: ");
							fgets(question, 100, stdin);

							insert_left(currentNode, question, "None");
							someTree->size += 1;
							anotherInput = true;
							isModified = true;
						}
						else if (input == '2') {
							printf("Enter answer: ");
							fgets(answer, 20, stdin);

							insert_left(currentNode, "No Question", answer);
							someTree->size += 1;
							anotherInput = true;
							isModified = true;
						}
					}

				}
				//show next node
				currentNode = currentNode->left_child;
				takenInput = true;
			}
			else if (input == 'n') {
				userInput.input[inputCounter] = 'n';
				inputCounter++;
				if (currentNode->right_child == NULL) {
					printf("Add question[1] or answer[2]?\n");

					while (!anotherInput) {
						input = _getch();
						if (input == '1') {
							printf("Enter Question: ");
							fgets(question, 100, stdin);

							insert_right(currentNode, question, "None");
							someTree->size += 1;
							anotherInput = true;
							isModified = true;
						}
						else if (input == '2') {
							printf("Enter answer: ");
							fgets(answer, 20, stdin);

							insert_right(currentNode, "No Question", answer);
							someTree->size += 1;
							anotherInput = true;
							isModified = true;
						}
					}
				}
				//show next node
				currentNode = currentNode->right_child;
				takenInput = true;
			}
		}
	}

	if (isModified) {
		//save created nodes to file
		outfile = fopen("data.dat", "w");
		//temp list creation to store binary tree data
		list someList;
		someList.head = NULL;
		someList.size = 0;

		//save tree values to list
		//tree_values(&someList, someTree->root);

#pragma region NewWriting Method
		//Write the data using replay information, this way everything is CLEAN
		//gotta append values in order to linkedList

		//VARS
		char someChar2 = 'y';
		int otherCounter = 0;
		tree_node *treeTrav = someTree->root;
		list_node *listTrav = someList.head;

		testStruct testingStruct2;
		strcpy(testingStruct2.question, someTree->root->data.question);
		strcpy(testingStruct2.answer, someTree->root->data.answer);
		//send in the root to list
		list_new_insert(&someList, testingStruct2);
		//travel next
		listTrav = listTrav->next;

		//while theres user input data in array
		while (someChar2 == 'y' || someChar2 == 'n' || someChar2 == 'e') {
			//if end of session symbol
			if (userInput.input[otherCounter] == 'e') {
				//reset binary tree traversal to beginning
				treeTrav = someTree->root;
			}

			else if (userInput.input[otherCounter] == 'y') {
				//list_new_insert(&someList,)

				insert_left(treeTrav, listTrav->testData.question, listTrav->testData.answer);
				//move up to the left
				treeTrav = treeTrav->left_child;
			}
			else if (userInput.input[otherCounter] == 'n') {
				insert_right(treeTrav, listTrav->testData.question, listTrav->testData.answer);
				//move up to the right
				treeTrav = treeTrav->right_child;
			}

			//read next stored input
			otherCounter++;
			someChar2 = userInput.input[otherCounter];
			//next list value
			if (listTrav->next != NULL) {
				listTrav = listTrav->next;
			}
		}
		//inputCounter = otherCounter;


#pragma endregion



		//save list values to file
		testStruct temp;
		//traversal node
		list_node *temp_node = someList.head;
		while (temp_node != NULL) {
			//copy data to temp testStruct
			strcpy(temp.question, temp_node->testData.question);
			strcpy(temp.answer, temp_node->testData.answer);
			//write data to file
			fwrite(&temp, sizeof(testStruct), 1, outfile);
			//traverse to next list node
			temp_node = temp_node->next;
		}
		//close file
		fclose(outfile);

		//to the end of current replay data inputs save a special symbol to indicate end of that session
		//length of current input array
		char lengthX = 'y';
		i = 0;
		while (lengthX == 'y' || lengthX == 'n' || lengthX == 'e') {
			lengthX = userInput.input[i];
			i++;
		}
		//add to the last element e to indicate end
		userInput.input[i - 1] = 'e';

		//save inputs
		outfile = fopen("input.dat", "w");
		fwrite(&userInput, sizeof(InputStruct), 1, outfile);
		fclose(outfile);
	}
	

	system("pause");
	return 0;
}

