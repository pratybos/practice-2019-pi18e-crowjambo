//TASK 3 - EVALDAS PAULAUSKAS
//PI18E - DATA STRUCTURES AND ALGORITHMS


#include "UtilityLibs.h"
#include "BinaryTree.h"

unsigned long long int factorialRecursive(int x) {
	if (x >= 1) {
		return x * factorialRecursive(x - 1);
	}
	else {
		return 1;
	}
}
int fibbonacci(int n) {
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else {
		return (fibbonacci(n - 1) + fibbonacci(n - 2));
	}
}
int count = 0, indent = 0;
int ackermann(int x, int y)
{
	count++;
	if (x < 0 || y < 0)
		return -1;
	if (x == 0)
		return y + 1;
	if (y == 0)
		return ackermann(x - 1, 1);
	return ackermann(x - 1, ackermann(x, y - 1));
}

int main() {
	int i = 0;
	int n = 10;

//recursive binary tree traversal

//#pragma region Recursive Binary Tree TRAVERSAL
//
//	tree *newTree = create_tree();
//	set_root(newTree, 1);
//	insert_left(newTree->root, 2);
//	insert_left(newTree->root->left_child, 4);
//	insert_right(newTree->root->left_child, 5);
//	insert_right(newTree->root, 3);
//	display_tree(newTree->root, InOrder);
//	printf("\n");
//	display_tree(newTree->root, PreOrder);
//	printf("\n");
//	display_tree(newTree->root, PostOrder);
//	printf("\n");
//
//#pragma endregion

	//factorial recursive
	//printf("factorial of 20 = %llu \n", factorialRecursive(20));

	//fibbonacci recursive
	//printf("Fibbonacci of %d: ", n);
	//for (i = 0; i < n; i++) {
	//	printf("%d ", fibbonacci(i));
	//}

	//ackermann function
	int x = 2;
	int y = 2;
	printf("\nAckermann Function with inputs (%d,%d) is %d\n", x, y, ackermann(x, y));
	printf("\nFunction called %d times.\n", count);



	printf("\n");
	system("pause");
	return 0;
}