#define _CRT_SECURE_NO_WARNINGS
#include "UtilityLibs.h"
#include "testHeader.h"

//Create a console program that can guess your invented word for a freely chosen topic
	/*
	TODO:
		- dynamic. If you answer wrong, it allows you to append a question OR answer if next node which you were about to traverse to is EMPTY ( this way its both dynamic and I can fill it in quickly and easily )
		- update data structure in binary tree
		- update createTreeNode, to take in strings, and create+allocate memory for new data node and append it to tree_node during treenode creation
		- after last value is reached, program should make a guess on current best answer

		- current best answer Char, which copies current best answer as you traverse, and once you reach dead end it prints it out, and if thats wrong, you can append new stuff
	*/

typedef struct {
	data data[100];

}savedData;

int main() {

	//FILES
	FILE *outfile = NULL;

	//VARS
	bool finished = false;
	bool takenInput = false;
	bool anotherInput = false;
	char input = 'z';
	char question[100], ch;
	char answer[20], ch2;
	//INIT, note -  root is NULL 
	tree *someTree = create_tree();


	//init first question
	set_root(someTree,"Test Question?", "None");
	someTree->size += 1;

	//Car buying expert system
	printf("Welcome to car buying expert system, y for Yes n for No\n");

	//navigator node init
	tree_node *currentNode = someTree->root;

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
						}
						else if (input == '2') {
							printf("Enter answer: ");
							fgets(answer, 20, stdin);

							insert_left(currentNode, "", answer);
							someTree->size += 1;
							anotherInput = true;
						}
					}

				}
				currentNode = currentNode->left_child;
				takenInput = true;
			}
			else if (input == 'n') {
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
						}
						else if (input == '2') {
							printf("Enter answer: ");
							fgets(answer, 20, stdin);

							insert_right(currentNode, "", answer);
							someTree->size += 1;
							anotherInput = true;
						}
					}
				}

				currentNode = currentNode->right_child;
				takenInput = true;
			}
		}
	}
	//traverese through tree and save data
	currentNode = someTree->root;

	//save created nodes to file
	outfile = fopen("data.dat", "w");
	list someList;
	someList.head = NULL;
	someList.size = 0;
	
	//save tree values to list
	tree_values(&someList, someTree->root);
	
	//traversal
	list_node *temp = someList.head;
	//print out multiple saved values
	while(temp != NULL) {
		printf("%s %s", temp->testData.question, temp->testData.answer);
		temp = temp->next;
	}
	system("pause");

	//printf("%s %s \n", someList.head->testData.question, someList.head->testData.answer);
	//fwrite(&, sizeof(savedData), 1, outfile);
	


	fclose(outfile);


	//reading
	outfile = fopen("data.dat", "r");
	

	//system("pause");
	return 0;
}

