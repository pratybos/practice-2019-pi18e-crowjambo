#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

/*

Real life task, made into algorhithm. THINK LIKE A COMPUTER, divide it into tasks and execute

Use normal C and just arrays to draw things, maybe WinAPI and extra thread for drawing ( or so ) and regex for clearscreen/console(veryfast)

- Going to store (with a map from arrays)
- Buying groceries (navigate aswell?), can pick whatever you want
- Paying
- Going home

*/


int main()
{
	int key = 0; // getch returns int
	while (1) {
		if (_kbhit()) {
			key = _getch();
			printf("\t %d \n", key);

			if (key == 'w') {			// now it works, remember difference in ASCII value between capital letters and not
				printf("w has been pressed");
				break;
			}
			else {
				printf("\n other value %d", key);
			}
		}
		Sleep(200); // needed windows.h inclusion to work
		printf(" === NOTHING === \n");
	}
	
	printf("\n\n");
	system("pause"); // can be used for any command like dir or cls (clearscreen) make use of it for prototype
	return 0;
}
