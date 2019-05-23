/* 
TASK 2 - ADT's
EVALDAS PAULAUSKAS - PI18E group
*/

#include "UtilityLibs.h"
#include "Stack.h"
#include "Queue.h"
#include "BinaryTree.h"
#include "LinkedList.h"


int main() {
	int i = 0;
	srand(time(0));

// STACK ALGORITHM 

//#pragma region STACK USAGE
//
//	// 9*(((5+8)+(8*7))+3) in postfix form = 958+87*+3+*
//	stack *s = create_stack();
//	char* calculate = "958+87*+3+*";
//	printf("Result = %d", StackCalculation_Postfix(calculate,s));
//
//
//#pragma endregion
//

// QUEUE USAGE

//#pragma region QUEUE USAGE
//
//	queue *myNewQueue = create_queue();
//	int temp = 0;
//	for (i = 0; i < 10; i++) {
//		temp = rand() % 100;
//		enqueue(myNewQueue, temp);
//	}
//	printf("Filled queue preview : \n");
//	display_queue(myNewQueue);
//	printf(" -----\n\n ");
//	//deque and preview
//	for (i = 0; i < 10; i++) {
//		dequeue(myNewQueue);
//		display_queue(myNewQueue);
//		printf(" -----\n\n ");
//	}
//	destroy_queue(myNewQueue);
//
//#pragma endregion


// TREE ALGORITHM

#pragma region BINARY TREE USAGE

	//Simple binary tree usage
	tree *myNewTree = create_tree();
	for (i = 0; i < 20; i++) {
		int temp = rand() % 100;
		insert_to_tree(myNewTree, temp);
	}
	//biggest to smallest print out
	display_tree(myNewTree->root, 2);


 //PARSE TREE ALGORITHM
	//tree *bt = create_tree();
	//insert_to_tree(bt, ' ');
	//char arrc_equation[] = "(3+(4*5))";
	//int arr_lenght = strlen(arrc_equation);
	//
	////for traversing the tree
	//tree_node* current_branch;
	//tree_node* parent_branch;
	//stack_for_trees *parent_stack = create_stack_tree();
	//current_branch = bt->root;
	//

	//for (int i = 0; i < arr_lenght; i++) {

	//	
	//		if (arrc_equation[i] == '(') {
	//			//rule 1 create new node as left child of root, and 
	//			insert_left(current_branch, ' ');
	//			push_stack_tree(parent_stack, current_branch);
	//			//move current node to be this new child
	//			current_branch = current_branch->left_child;

	//		}
	//		//numbers reading
	//		else if (((int)arrc_equation[i] >= 48 && (int)arrc_equation[i] <= 57) || ((int)arrc_equation[i] >= 65 && (int)arrc_equation[i] <= 90) || ((int)arrc_equation[i] >= 97 && (int)arrc_equation[i] <= 122)) {

	//			//rule 3
	//			current_branch->data = arrc_equation[i];
	//			parent_branch = peek_stack_tree(parent_stack);
	//			pop_stack_tree(parent_stack);
	//			current_branch = parent_branch;
	//			

	//		}
	//		//operands reading
	//		else if (arrc_equation[i] == '/' || arrc_equation[i] == '*' || arrc_equation[i] == '-' || arrc_equation[i] == '+') {

	//			//rule 2
	//			current_branch->data = arrc_equation[i];
	//			insert_right(current_branch, ' ');
	//			push_stack_tree(parent_stack, current_branch);
	//			current_branch->right_child;


	//		}
	//		else if (arrc_equation[i] == ')') {

	//			//rule 4
	//			if (is_stack_empty_tree(parent_stack) != 0) {
	//				parent_branch = peek_stack_tree(parent_stack);
	//				pop_stack_tree(parent_stack);
	//			}

	//		}
	//	}
	//	display_tree(bt->root, 1);
	

#pragma endregion


// LINKED LIST USAGE

//#pragma region LINKED LIST USAGE
//
// /*find the average value of all values in linked list*/
//	list *newList = create_list();
//	for (i = 0; i < 10; i++) {
//		list_insert_at_front(newList, i+1);
//	}
//	list_display(newList);
//	printf("\n average value = %.1f", list_average_value(newList));
//	
//
//#pragma endregion



	// ctrl + K + U (uncomment) , ctrl+K+C (comment)
	printf("\n\n"); 
	system("pause");
	return(0);

}

