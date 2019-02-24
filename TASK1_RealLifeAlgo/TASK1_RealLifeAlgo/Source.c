/*

TASK 1 - REAL LIFE ALGORITHM
EVALDAS PAULAUSKAS - PI18E group

ALGORITHM :
INPUT :
OUTPUT :
STEPS :
ASSUMPTIONS :


*/

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

/*
1. create a array grid/representatino of a map (as a struct)
2. create a player struct ( with position )
3. use keyboard inputs ( put it in a function ) to move player around the map
4. look into changing player color.
*/

#pragma region FunctionINIT

void FillMap();
void DrawMap();
void ChangePosition(struct player p);
int Inputs();
void AllDrawingActions();

//utility , faster cls
void cls(HANDLE hConsole);


#pragma endregion


#pragma region Structs

struct map {
	int size[25][25];

};

struct player {
	int playerNumber;
	int Xpos;
	int Ypos;
	int size;
};

#pragma endregion



#pragma region Global Struct definitions

	struct map firstMap;
	struct player player1;

#pragma endregion
	

// global input
int key = 0;


int main() 
{
	
	//PLAYER INIT.
	player1.playerNumber = 6;
	player1.size = 2;
	player1.Xpos = 11;
	player1.Ypos = 22;

	//Initial drawing of the field
	FillMap();
	ChangePosition(player1);
	DrawMap();

	//infinite game loop
	while (1) {

		// only draw if correct inputs were made
		if (Inputs()) {
			AllDrawingActions();
		}



		// miliseconds to wait
		Sleep(20);
	}

	system("Pause");
	return 0;
}


#pragma region FunctionDefinitions

void FillMap(){
	int i, j;
	for (i = 0; i < 25; i++) {
		for (j = 0; j < 25; j++) {
			// value to fill the map with
			firstMap.size[i][j] = 0;

		}
	}
}

void DrawMap() {
	int i, j;
	for (i = 0; i < 25; i++) {
		for (j = 0; j < 25; j++) {
			// make the map look square or rectangle. Draw new line at the end of each 10 elements.
			if (j == 24) {
				printf("%d \n", firstMap.size[i][j]);
				continue;
			}
			printf("%d", firstMap.size[i][j]);

		}
	}
	// new line after print for cleanup
	printf("\n\n\n");
	printf("x pos : %d , y pos : %d", player1.Xpos, player1.Ypos);

}

void ChangePosition(struct player p) {
	
	// set it in map space. Make player of size depending on its size attribute ( in cube shape )
	for (int i = 0; i < p.size; i++) {
		for (int j = 0; j < p.size; j++) {
			firstMap.size[p.Ypos + i][p.Xpos + j] = p.playerNumber;
		}
	}
	


}

int Inputs() {

	if (_kbhit()) {

		key = _getch();

		//only proc update if input keys are pressed
		if (key == 'w' || key == 's' || key == 'd' || key == 'a') {

			// remember difference in ASCII value between capital letters and not
			// take care of proper inputs/collisions
			if (key == 'w') {
				if (player1.Ypos > 0) {
					player1.Ypos -= 1;
				}
			}

			// taking into account bigger player size
			if (key == 's') {
				if (player1.Ypos+player1.size-1 < 24) {
					player1.Ypos += 1;
				}
			}

			// taking into account bigger player size
			if (key == 'd') {
				if (player1.Xpos+player1.size-1 < 24) {
					player1.Xpos += 1;
				}
			}

			if (key == 'a') {
				if (player1.Xpos > 0) {
					player1.Xpos -= 1;
				}
			}

			return 1;
		}
		return 0;
	}
}

void AllDrawingActions() {

	HANDLE hStdout;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	cls(hStdout);
	FillMap();
	ChangePosition(player1);
	DrawMap();

}

void cls(HANDLE hConsole)
{
	COORD coordScreen = { 0, 0 };    // home for the cursor 
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD dwConSize;

	// Get the number of character cells in the current buffer. 

	if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
	{
		return;
	}

	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

	// Fill the entire screen with blanks.

	if (!FillConsoleOutputCharacter(hConsole,        // Handle to console screen buffer 
		(TCHAR) ' ',     // Character to write to the buffer
		dwConSize,       // Number of cells to write 
		coordScreen,     // Coordinates of first cell 
		&cCharsWritten))// Receive number of characters written
	{
		return;
	}

	// Get the current text attribute.

	if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
	{
		return;
	}

	// Set the buffer's attributes accordingly.

	if (!FillConsoleOutputAttribute(hConsole,         // Handle to console screen buffer 
		csbi.wAttributes, // Character attributes to use
		dwConSize,        // Number of cells to set attribute 
		coordScreen,      // Coordinates of first cell 
		&cCharsWritten)) // Receive number of characters written
	{
		return;
	}

	// Put the cursor at its home coordinates.

	SetConsoleCursorPosition(hConsole, coordScreen);
}

#pragma endregion

