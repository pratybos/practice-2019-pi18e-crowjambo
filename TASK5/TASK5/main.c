#include "UtilityLibs.h"
#include "BinaryTree.h"

//Create a console program that can guess your invented word for a freely chosen topic
	/*
	TODO:
		- just do forward chaining, basic, but have some depth in questions at first

	*/

int main() {
	//VARS
	bool finished = false;
	bool testDone = false;
	char input = 'z';
	//INIT, note -  root is NULL 
	tree *someTree = create_tree();
	//creating array of questions, and allocating some memory to it
	data **questions = (data *)malloc(sizeof(data)*10);
	questions[0] = tree_data_create("Does it have feathers?", "None");
	questions[1] = tree_data_create("Does it eat grass?", "None");
	questions[2] = tree_data_create("Is it a pet?", "None");
	questions[3] = tree_data_create("", "Bird-Cow");
	questions[4] = tree_data_create("", "Crow");
	questions[5] = tree_data_create("", "Human");
	set_root(someTree, questions[0]);
	insert_left(someTree->root, questions[1]);
	insert_left(someTree->root->left_child, questions[3]);
	insert_right(someTree->root->left_child, questions[4]);
	insert_right(someTree->root, questions[5]);

	//testing
	//printf("%s\n", someTree->root->data->question);

	//navigator node
	tree_node *currentNode = someTree->root;

	//main loop
	while (!finished) {
		//_fgetchar();
		testDone = false;
		if (strcmp(currentNode->data->answer,"None")) {
			printf("My guess : %s\n", currentNode->data->answer);
			finished = true;
			continue;
		}
		printf("%s\n", currentNode->data->question);
		
		while (!testDone) {
			input = _getch();
			if (input == 'y') {
				currentNode = currentNode->left_child;
				testDone = true;
			}
			else if (input == 'n') {
				currentNode = currentNode->right_child;
				testDone = true;
			}
		}

		
		
	}


	system("pause");
	return 0;
}