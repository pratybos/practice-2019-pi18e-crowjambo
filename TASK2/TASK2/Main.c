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

 //PARSE TREE ALGORITHM


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

