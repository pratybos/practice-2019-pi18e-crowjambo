//TASK 3 - EVALDAS PAULAUSKAS
//PI18E - DATA STRUCTURES AND ALGORITHMS


//If its possible try to implement same algorithms : “Factorial, Fibonacci, Ackermar, Read files, Binary Tree traversal” without recursion.Else Write some explanation why is so hard to implement that algorithm.
/*
EXPLANATION

Iterative functions are simpler, but take more lines of code
The more complicated the recursion, the more loops(for/while) you'll be needing to use to simulate the recursion making the code unclean and potentially harder to understand/read.
In some cases , you ll have to be using a stack data structure to keep changes to the variables in memory as the program keeps going through the loops. (once again adding more lines of code and complexity)

For simple recursive functions, converting it into non recursive using one for loop or two, is easy though.


*/


#define _CRT_SECURE_NO_WARNINGS
#include "UtilityLibs.h"
#include "BinaryTree.h"
#include <Windows.h>


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
bool ListDirectoryContents(const char *sDir)
{
	WIN32_FIND_DATA fdFile;
	HANDLE hFind = NULL;

	char sPath[2048];

	//Specify a file mask. *.* = We want everything!
	//sprintf(sPath, "%s\\*.*", sDir);

	//make it read and target only .txt files
	sprintf(sPath, "%s\\*.txt", sDir);

	if ((hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE)
	{
		printf("Path not found: [%s]\n", sDir);
		return false;
	}

	do
	{
		//Find first file will always return "."
		//    and ".." as the first two directories.
		if (strcmp(fdFile.cFileName, ".") != 0
			&& strcmp(fdFile.cFileName, "..") != 0)
		{
			//Build up our file path using the passed in
			//  [sDir] and the file/foldername we just found:
			sprintf(sPath, "%s\\%s", sDir, fdFile.cFileName);

			//Is the entity a File or Folder?
			if (fdFile.dwFileAttributes &FILE_ATTRIBUTE_DIRECTORY)
			{
				printf("Directory: %s\n", sPath);
				ListDirectoryContents(sPath); //Recursion, I love it!
			}
			else {
				printf("File: %s\n", sPath);
			}
		}
	} while (FindNextFile(hFind, &fdFile)); //Find the next file.

	FindClose(hFind); //Always, Always, clean things up!

	return true;
}


int main() {
	int i = 0;
	int n = 10;

#pragma region Recursive Binary Tree TRAVERSAL

	//tree *newTree = create_tree();
	//set_root(newTree, 1);
	//insert_left(newTree->root, 2);
	//insert_left(newTree->root->left_child, 4);
	//insert_right(newTree->root->left_child, 5);
	//insert_right(newTree->root, 3);
	//display_tree(newTree->root, InOrder);
	//printf("\n");
	//display_tree(newTree->root, PreOrder);
	//printf("\n");
	//display_tree(newTree->root, PostOrder);
	//printf("\n");

#pragma endregion


	//factorial recursive
	//printf("factorial of 20 = %llu \n", factorialRecursive(20));

	//fibbonacci recursive
	//printf("Fibbonacci of %d: ", n);
	//for (i = 0; i < n; i++) {
	//	printf("%d ", fibbonacci(i));
	//}

	//ackermann function
	//int x = 2;
	//int y = 2;
	//printf("\nAckermann Function with inputs (%d,%d) is %d\n", x, y, ackermann(x, y));
	//printf("\nFunction called %d times.\n", count);


	//read text files in a directory recursively
	//ListDirectoryContents("C:\\rufus_files\\syslinux-6.03\\");




	printf("\n");
	system("pause");
	return 0;
}