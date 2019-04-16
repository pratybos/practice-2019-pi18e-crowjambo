/* 
TASK 2 - ADT's
EVALDAS PAULAUSKAS - PI18E group
*/

#include "UtilityLibs.h"
#include "Stack.h"
#include "Queue.h"
#include "BinaryTree.h"


int main() {

// STACK USAGE

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
//	queue *test = create_queue();
//	enqueue(test, 15);
//	enqueue(test, 55);
//	enqueue(test, 12);
//	printf("%s", is_queue_empty(test) ? "true\n" : "false\n");
//	display_queue(test);
//	dequeue(test);
//	display_queue(test);
//
//#pragma endregion
//

// TREE USAGE

//#pragma region BINARY TREE USAGE
//
//	
//	
////	insert_tree(treeTest, 5);
//
//#pragma endregion

	// ctrl + K + U (uncomment) , ctrl+K+C (comment)
	tree *newTree;
	newTree = create_tree();
	insert_to_tree(newTree, 5);
	insert_to_tree(newTree, 1);
	insert_to_tree(newTree, 2);
	insert_to_tree(newTree, 8);
	insert_to_tree(newTree, 20);
	//send the root tree_node, not tree itself!
	display_tree(newTree->root,3);
	
	system("Pause");
	destroy_tree(newTree->root);
	//display_tree(newTree->root,1);

	printf("\n\n"); 
	system("pause");
	return(0);

}

