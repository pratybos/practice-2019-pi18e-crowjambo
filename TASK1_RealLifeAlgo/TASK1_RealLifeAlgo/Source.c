/*

TASK 1 - REAL LIFE ALGORITHM
EVALDAS PAULAUSKAS - PI18E group

ALGORITHM :
INPUT :
OUTPUT :
STEPS :
ASSUMPTIONS :


*/

/*

ADD : 
	- interraction with buildings
	- extra input to intteract with building
	- some refactoring
	- fulfill actual objective by reaching a building, interracting with it and going home, then breaking the loop

- Going to store (with a map from arrays)
- Buying groceries (navigate aswell?), can pick whatever you want
- Paying
- Going home

*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#define NUMBER_OF_OBSTACLES 3
#define MAP_SIZE 40


enum ObstacleType {
	Home=0,
	SuperMarket,
	CandyStore,
};

#pragma region FunctionINIT

void FillMap();
void DrawMap();
void ChangePosition(struct collidable p);
int Inputs();
void AllDrawingActions();

//utility , faster cls
void cls(HANDLE hConsole);


#pragma endregion

#pragma region Structs

struct map {
	int size[MAP_SIZE][MAP_SIZE];
	int graphics;
};

struct collidable {
	int numberRepresentation;
	int Xpos;
	int Ypos;
	int size;
	enum ObstacleType type;
	int Xtrigger;
	int Ytrigger;
};


#pragma endregion


// to not have to pass them to functions
#pragma region Global Struct definitions

	struct map firstMap;
	struct collidable player1;
	struct collidable obstacles[NUMBER_OF_OBSTACLES];

#pragma endregion
	

// global input, simplified this way
int key = 0;


int main() 
{

	#pragma region INIT values/actions

	// MAP graphics INIT
		firstMap.graphics = 0;

	//PLAYER INIT.
		player1.numberRepresentation = 6;
		player1.size = 2;
		player1.Xpos = 11;
		player1.Ypos = 22;

	//Obstacles INIT
		//home obstacle
		obstacles[0].type = Home;
		obstacles[0].numberRepresentation = 3;
		obstacles[0].size = 4;
		obstacles[0].Xpos = 6;
		obstacles[0].Ypos = 19;
		//make doors be in the middle bottom of obstacle
		obstacles[0].Xtrigger = obstacles[0].Xpos + obstacles[0].size / 2;
		obstacles[0].Ytrigger = obstacles[0].Ypos + obstacles[0].size;
		//shop1
		obstacles[1].type = SuperMarket;
		obstacles[1].numberRepresentation = 9;
		obstacles[1].size = 8;
		obstacles[1].Xpos = 15;
		obstacles[1].Ypos = 2;
		//shop2
		obstacles[2].type = CandyStore;
		obstacles[2].numberRepresentation = 2;
		obstacles[2].size = 5;
		obstacles[2].Xpos = 0;
		obstacles[2].Ypos = 0;

		//Initial drawing of the field
		FillMap();
		ChangePosition(player1);
		//set all buildings/obstacles
		for (int i = 0; i < NUMBER_OF_OBSTACLES; i++) {
			ChangePosition(obstacles[i]);
		}
		DrawMap();

	#pragma endregion

	//infinite game loop
	while (1) {

		// only draw if correct inputs were made
		if (Inputs()) {
			AllDrawingActions();
		}

		// miliseconds to wait
		Sleep(20);
	}

	//system("Pause");
	return 0;
}


#pragma region FunctionDefinitions

// function for refilling the map with default values ( dirty solution )
void FillMap(){
	int i, j;
	for (i = 0; i < MAP_SIZE; i++) {
		for (j = 0; j < MAP_SIZE; j++) {
			// value to fill the map with
			firstMap.size[i][j] = firstMap.graphics;

		}
	}
}

// function for performing all of the drawing of objects/player after the positions are changed
void DrawMap() {
	int i, j;
	char testWords[] = "Enter Home";
	if (player1.Xpos == obstacles[0].Xtrigger) {
		printf("\n\n %s \n\n", testWords);
	}
	else {
		printf("\n\n \n\n");
	}

	for (i = 0; i < MAP_SIZE; i++) {
		for (j = 0; j < MAP_SIZE; j++) {
			// make the map look square or rectangle. Draw new line at the end of each 10 elements.
			if (j == MAP_SIZE-1) {
				printf("%d \n", firstMap.size[i][j]);
				continue;
			}
			printf("%d", firstMap.size[i][j]);

		}
	}
	printf("\n Current objective : Go to supermarket \n\n You = 6 ; HOME = 3 ; SUPERMARKET = 9");
	// new line after print for cleanup

	//debugging print values
	
	//printf("\n\n\n");
	//printf("x pos : %d , y pos : %d \n", player1.Xpos, player1.Ypos);
	//printf("y+1 : %d | x+1: %d ", firstMap.size[player1.Ypos + 1][player1.Xpos], firstMap.size[player1.Ypos][player1.Xpos + 1]);

	
}


// function for SETTING position of both player and obstacles on the map
void ChangePosition(struct collidable p) {
	
	// set it in map space. Make player of size depending on its size attribute ( in cube shape )
	for (int i = 0; i < p.size; i++) {
		for (int j = 0; j < p.size; j++) {
			firstMap.size[p.Ypos + i][p.Xpos + j] = p.numberRepresentation;
		}
	}
	


}

// Handles all inputs and proper collisions detection
int Inputs() {

	if (_kbhit()) {

		//dont forget, getch() returns INTS!
		key = _getch();

		//only proc update if input keys are pressed
		if (key == 'w' || key == 's' || key == 'd' || key == 'a') {

			// remember difference in ASCII value between capital letters and not

			// take care of proper inputs/collisions
			if (key == 'w') {
				// check if position above player(by 1) is tile 0 or something else, (0 is the default ground number atm)
				if (player1.Ypos > 0 && firstMap.size[player1.Ypos-1][player1.Xpos] == firstMap.graphics && firstMap.size[player1.Ypos - 1][player1.Xpos + player1.size - 1] == firstMap.graphics) {
					player1.Ypos -= 1;
				}
			}

			// taking into account bigger player size.
			if (key == 's') {
				if (player1.Ypos + player1.size < MAP_SIZE && firstMap.size[player1.Ypos + player1.size][player1.Xpos] == firstMap.graphics && firstMap.size[player1.Ypos + player1.size][player1.Xpos + player1.size - 1] == firstMap.graphics) {
					player1.Ypos += 1;
				}
			}

			// taking into account bigger player size. 
			if (key == 'd') {
				if (player1.Xpos+player1.size < MAP_SIZE && firstMap.size[player1.Ypos][player1.Xpos+player1.size] == firstMap.graphics && firstMap.size[player1.Ypos + player1.size-1][player1.Xpos + player1.size] == firstMap.graphics) {
					player1.Xpos += 1;
				}
			}

			//check for COMPLETELY OUT OF BOUNDS && if next tile is walkable ground tile or something else
			if (key == 'a') {
				if (player1.Xpos > 0 && firstMap.size[player1.Ypos][player1.Xpos-1] == firstMap.graphics && firstMap.size[player1.Ypos + player1.size - 1][player1.Xpos - 1] == firstMap.graphics) {
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
	for (int i = 0; i < NUMBER_OF_OBSTACLES; i++) {
		ChangePosition(obstacles[i]);
	}
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

