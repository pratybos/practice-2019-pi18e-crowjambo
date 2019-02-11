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
void PlayerDraw(int x, int y);

#pragma endregion


#pragma region Structs

struct map {
	int size[10][10];

};

struct player {
	int playerNumber;
	int Xpos;
	int Ypos;
	int(*Draw)(int,int);
	// place inputs in here too?
	// function pointers as well for movement
};

#pragma endregion



#pragma region Global Struct definitions

	struct map firstMap;
	struct player player1;

#pragma endregion



int main() 
{
	//LOCAL VARIABLES
	int key = 0; // _getch returns ints

	//PLAYER INIT.
	player1.Draw = &PlayerDraw;
	player1.playerNumber = 6;
	player1.Xpos = 5;
	player1.Ypos = 5;


	//infinite game loop
	while (1) {

		//DRAWING + Clearing screen
		system("cls");
		FillMap();
		player1.Draw(player1.Xpos, player1.Ypos);
		DrawMap();
		//
		//INPUT
		if (_kbhit()) {
			key = _getch();

			// remember difference in ASCII value between capital letters and not
			if (key == 'w') {			
				player1.Xpos = player1.Xpos - 1;
			}

		}
		// miliseconds to wait
		Sleep(200); 
	}



	system("Pause");
	return 0;
}


#pragma region FunctionDefinitions

void FillMap(){
	int i, j;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			// value to fill the map with
			firstMap.size[i][j] = 2;

		}
	}

}

void DrawMap() {
	int i, j;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			// make the map look square or rectangle. Draw new line at the end of each 10 elements.
			if (j == 9) {
				printf("%d \n", firstMap.size[i][j]);
				continue;
			}
			printf("%d", firstMap.size[i][j]);

		}
	}
	// new line after print for cleanup
	printf("\n");

}

void PlayerDraw(int y, int x) {
	
	// set it in map space
	firstMap.size[y][x] = player1.playerNumber;

}


#pragma endregion

