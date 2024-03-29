/*

2019 PRACTICAL WORK PI18E - EVALDAS PAULAUSKAS

*/
#pragma region Headers

//allegro and custom imports
#include "MainLibs.h"
#include "Button.h"
#include "Inventory.h"
#include "Car.h"
#include "GameManager.h"
#include "Player.h"
#include "CarShop.h"
#include "Achievements.h"
#include "Opponent.h"
#include "Map.h"
#include "RaceManager.h"
//standard imports
#include <stdio.h>
#include <string.h>
#include <time.h>
//for shellexecute to work(to open website ranking)
#include <Windows.h>

#pragma endregion
#pragma region Globals

//defines
#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768

//variables
bool fullyDone = false;
GameManager mng;
int FPS = 30;
Player player1;

#pragma endregion
#pragma region ALLEGRO VARIABLES
//display
ALLEGRO_DISPLAY *display;
//fonts
ALLEGRO_FONT *font12;
ALLEGRO_FONT *font16;
ALLEGRO_FONT *font22;
ALLEGRO_FONT *font36;
//colors
ALLEGRO_COLOR colors[4];
//timers
ALLEGRO_TIMER *timer;
//event queues
ALLEGRO_EVENT_QUEUE *event_queue;
#pragma endregion
#pragma region FUNCTIONS

void turn_processing(RaceManager mng) {
	//line processing
	switch (mng.chosenLine) {
	case 1:
		player1.ownedCars[player1.currentCar].currentLine = 1;
		break;
	case 2:
		player1.ownedCars[player1.currentCar].currentLine = 2;
		break;
	case 3:
		player1.ownedCars[player1.currentCar].currentLine = 3;
		break;
	}
	//accel processing
	switch (mng.chosenAccel) {
	case 1:
		player1.ownedCars[player1.currentCar].currentSpeed += 0.05 * player1.ownedCars[player1.currentCar].HorsePower;
		break;
	case 2:
		player1.ownedCars[player1.currentCar].currentSpeed += 0.1 * player1.ownedCars[player1.currentCar].HorsePower;
		break;
	case 3:
		player1.ownedCars[player1.currentCar].currentSpeed += 0.15 * player1.ownedCars[player1.currentCar].HorsePower;
		break;
	}
	//brake processing
	switch (mng.chosenBrake) {
	case 1:
		player1.ownedCars[player1.currentCar].currentSpeed -= 0.05 * player1.ownedCars[player1.currentCar].BrakePower;
		break;
	case 2:
		player1.ownedCars[player1.currentCar].currentSpeed -= 0.1 * player1.ownedCars[player1.currentCar].BrakePower;
		break;
	case 3:
		player1.ownedCars[player1.currentCar].currentSpeed -= 0.15 * player1.ownedCars[player1.currentCar].BrakePower;
		break;
	}

	//quick error check to limit values
	if (player1.ownedCars[player1.currentCar].currentSpeed > player1.ownedCars[player1.currentCar].topSpeed) {
		player1.ownedCars[player1.currentCar].currentSpeed = player1.ownedCars[player1.currentCar].topSpeed;
	}
	else if (player1.ownedCars[player1.currentCar].currentSpeed < 0) {
		player1.ownedCars[player1.currentCar].currentSpeed = 0;
	}

}

void draw_car(Car car) {
	if (car.currentLine == 1) {
		al_draw_filled_rectangle(55, 600, 255, 500, colors[1]);
	}
	else if (car.currentLine == 2) {
		al_draw_filled_rectangle(355, 600, 555, 500, colors[1]);
	}
	else if (car.currentLine == 3) {
		al_draw_filled_rectangle(655, 600, 855, 500, colors[1]);
	}
}
void draw_point(Point point) {
	// 1 = left , 2 == right
	if (point.LeftRight == 1) {

		//first straight part for each road part
		al_draw_line(50, 600, 400, 300, colors[0], 1);
		al_draw_line(900, 600, 650, 300, colors[0], 1);

		//second part, calculate angles here and draw the rest
		al_draw_line(400, 300, 400-point.angle*5, 20, colors[0], 1);
		al_draw_line(650, 300, 500-point.angle*5, 20, colors[0], 1);
		
		//al_draw_line(origin x, origin y, dest x, dest y, colors[0], 1);
	}
	else if (point.LeftRight == 2) {

		//first straight part for each road part
		al_draw_line(50, 600, 400, 300, colors[0], 1);
		al_draw_line(900, 600, 650, 300, colors[0], 1);

		//second part, calculate angles here and draw the rest
		al_draw_line(400, 300, 400 + point.angle * 5, 20, colors[0], 1);
		al_draw_line(650, 300, 500 + point.angle * 5 , 20, colors[0], 1);
	}
}


//car stats recalculation without exchange
void recalculate_car_stats_normal(int EquippedItem) {

	switch (EquippedItem) {
	case 0:
		player1.ownedCars[player1.currentCar].HorsePower += 50;
		break;
	case 1:
		player1.ownedCars[player1.currentCar].HorsePower += 100;
		break;
	case 2:
		player1.ownedCars[player1.currentCar].HorsePower += 150;
		break;
	case 3:
		player1.ownedCars[player1.currentCar].HorsePower += 50;
		break;
	case 4:
		player1.ownedCars[player1.currentCar].HorsePower += 100;
		break;
	case 5:
		player1.ownedCars[player1.currentCar].HorsePower += 150;
		break;
	case 6:
		player1.ownedCars[player1.currentCar].frontGrip += 0.1f;
		player1.ownedCars[player1.currentCar].rearGrip += 0.1f;
		break;
	case 7:
		player1.ownedCars[player1.currentCar].frontGrip += 0.2f;
		player1.ownedCars[player1.currentCar].rearGrip += 0.2f;
		break;
	case 8:
		player1.ownedCars[player1.currentCar].frontGrip += 0.3f;
		player1.ownedCars[player1.currentCar].rearGrip += 0.3f;
		break;
	case 9:
		player1.ownedCars[player1.currentCar].HorsePower += 10;
		break;
	case 10:
		player1.ownedCars[player1.currentCar].HorsePower += 20;
		break;
	case 11:
		player1.ownedCars[player1.currentCar].HorsePower += 30;
		break;
	case 12:
		player1.ownedCars[player1.currentCar].downForce += 0.1f;
		break;
	case 13:
		player1.ownedCars[player1.currentCar].downForce += 0.2f;
		break;
	case 14:
		player1.ownedCars[player1.currentCar].downForce += 0.3f;
		break;
	}
	/*switch (player1.ownedCars[player1.currentCar].engineItem) {
	case 0:
		player1.ownedCars[player1.currentCar].HorsePower += 50;
		break;
	case 1:
		player1.ownedCars[player1.currentCar].HorsePower += 100;
		break;
	case 2:

		break;
	}
	switch (player1.ownedCars[player1.currentCar].turboItem) {
	case 3:
		player1.ownedCars[player1.currentCar].HorsePower += 50;
		break;
	case 4:
		player1.ownedCars[player1.currentCar].HorsePower += 100;
		break;
	case 5:

		break;
	}
	switch (player1.ownedCars[player1.currentCar].tireItem) {
	case 6:

		break;
	case 7:

		break;
	case 8:

		break;
	}
	switch (player1.ownedCars[player1.currentCar].exhaustItem) {
	case 9:

		break;
	case 10:

		break;
	case 11:

		break;
	}
	switch (player1.ownedCars[player1.currentCar].aeroItem) {
	case 12:

		break;
	case 13:

		break;
	case 14:

		break;
	}*/
	
}

//car stats recalc, but exchanging items
void recalculate_car_stats_exchange(int swappedItem, int newItem) {
	
	switch (swappedItem) {
	case 0:
		player1.ownedCars[player1.currentCar].HorsePower -= 50;
		break;
	case 1:
		player1.ownedCars[player1.currentCar].HorsePower -= 100;
		break;
	case 2:
		player1.ownedCars[player1.currentCar].HorsePower -= 150;
		break;
	case 3:
		player1.ownedCars[player1.currentCar].HorsePower -= 50;
		break;
	case 4:
		player1.ownedCars[player1.currentCar].HorsePower -= 100;
		break;
	case 5:
		player1.ownedCars[player1.currentCar].HorsePower -= 150;
		break;
	case 6:
		player1.ownedCars[player1.currentCar].frontGrip -= 0.1f;
		player1.ownedCars[player1.currentCar].rearGrip -= 0.1f;
		break;
	case 7:
		player1.ownedCars[player1.currentCar].frontGrip -= 0.2f;
		player1.ownedCars[player1.currentCar].rearGrip -= 0.2f;
		break;
	case 8:
		player1.ownedCars[player1.currentCar].frontGrip -= 0.3f;
		player1.ownedCars[player1.currentCar].rearGrip -= 0.3f;
		break;
	case 9:
		player1.ownedCars[player1.currentCar].HorsePower -= 10;
		break;
	case 10:
		player1.ownedCars[player1.currentCar].HorsePower -= 20;
		break;
	case 11:
		player1.ownedCars[player1.currentCar].HorsePower -= 30;
		break;
	case 12:
		player1.ownedCars[player1.currentCar].downForce -= 0.1f;
		break;
	case 13:
		player1.ownedCars[player1.currentCar].downForce -= 0.2f;
		break;
	case 14:
		player1.ownedCars[player1.currentCar].downForce -= 0.3f;
		break;
	}
	switch (newItem) {
	case 0:
		player1.ownedCars[player1.currentCar].HorsePower += 50;
		break;
	case 1:
		player1.ownedCars[player1.currentCar].HorsePower += 100;
		break;
	case 2:
		player1.ownedCars[player1.currentCar].HorsePower += 150;
		break;
	case 3:
		player1.ownedCars[player1.currentCar].HorsePower += 50;
		break;
	case 4:
		player1.ownedCars[player1.currentCar].HorsePower += 100;
		break;
	case 5:
		player1.ownedCars[player1.currentCar].HorsePower += 150;
		break;
	case 6:
		player1.ownedCars[player1.currentCar].frontGrip += 0.1f;
		player1.ownedCars[player1.currentCar].rearGrip += 0.1f;
		break;
	case 7:
		player1.ownedCars[player1.currentCar].frontGrip += 0.2f;
		player1.ownedCars[player1.currentCar].rearGrip += 0.2f;
		break;
	case 8:
		player1.ownedCars[player1.currentCar].frontGrip += 0.3f;
		player1.ownedCars[player1.currentCar].rearGrip += 0.3f;
		break;
	case 9:
		player1.ownedCars[player1.currentCar].HorsePower += 10;
		break;
	case 10:
		player1.ownedCars[player1.currentCar].HorsePower += 20;
		break;
	case 11:
		player1.ownedCars[player1.currentCar].HorsePower += 30;
		break;
	case 12:
		player1.ownedCars[player1.currentCar].downForce += 0.1f;
		break;
	case 13:
		player1.ownedCars[player1.currentCar].downForce += 0.2f;
		break;
	case 14:
		player1.ownedCars[player1.currentCar].downForce += 0.3f;
		break;
	}
}

//convert enums used for days into strings
char *EnumsToString(enum DAYS day) {
	switch (day) {
	case MONDAY: return "MONDAY";
	case TUESDAY: return "TUESDAY";
	case WEDNESDAY: return "WEDNESDAY";
	case THURSDAY: return "THURSDAY";
	case FRIDAY: return "FRIDAY";
	case SATURDAY: return "SATURDAY";
	case SUNDAY: return "SUNDAY";
	}
}

//multi purpose used to check if button was pressed or not each frame
int ReturnOne() {
	return 1;
}

//windows.h function to open a set file
int OpenRankings() {
	ShellExecute(NULL, "open", "\output.html", NULL, NULL, 0);
};

//useful for multi-init of buttons, in case they all need very different functionality
int(*buttonFuncArray[3]) = { ReturnOne, OpenRankings, NULL};

#pragma endregion
#pragma region SCENES

int Start_Scene() {

	#pragma region Variables
	//temps
	int i = 0;
	char temp[20];
	//mouse position
	int x = 0;
	int y = 0;
	//mouse left click hold detection
	bool leftClick = false;
	//function main loop end condition
	bool done = false;
	bool redraw = false;
	//navigation vars
	int currentPage = 1;


	#pragma endregion
	#pragma region Buttons
		#pragma region Page1

		//number of buttons
		const int buttonsNMB1 = 3;
		//menu button detection variable(one for each button)
		int buttonVal[3] = { 0,0,0 };
		//all buttons
		Button buttonsMain[3];
		//quick button init
		for (i = 0; i < buttonsNMB1; i++) {
			buttonsMain[i] = buttonInit(SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 3 + i * 100, 200, 50, colors[0], colors[1], colors[2], colors[3], ReturnOne, "Empty");
		}
		//assign different names for buttons
		strcpy_s(buttonsMain[0].label, 20, "Start Game");
		strcpy_s(buttonsMain[1].label, 20, "Rankings");
		buttonsMain[1].function = OpenRankings;
		strcpy_s(buttonsMain[2].label, 20, "Quit Game");

		#pragma endregion
		#pragma region Page2

		//number of buttons
		const int buttonsNMB2 = 1;
		//menu button detection variable(one for each button)
		int buttonVal2[3] = { 0,0,0 };
		//all buttons
		Button buttonsPage2[1];
		//quick button init
		for (i = 0; i < buttonsNMB2; i++) {
			buttonsPage2[i] = buttonInit(SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 1.2 + i * 100, 200, 50, colors[0], colors[1], colors[2], colors[3], ReturnOne, "Empty");
		}
		//assign different names for buttons
		strcpy_s(buttonsPage2[0].label, 20, "OK");


		#pragma endregion
		#pragma region Page3

		//number of buttons
		const int buttonsNMB3 = 1;
		//menu button detection variable(one for each button)
		int buttonVal3[3] = { 0,0,0 };
		//all buttons
		Button buttonsPage3[1];
		//quick button init
		for (i = 0; i < buttonsNMB3; i++) {
			buttonsPage3[i] = buttonInit(SCREEN_WIDTH - 300, SCREEN_HEIGHT / 1.2 + i * 100, 200, 50, colors[0], colors[1], colors[2], colors[3], ReturnOne, "Empty");
		}
		//assign different names for buttons
		strcpy_s(buttonsPage3[0].label, 20, "Continue");

		#pragma endregion


#pragma endregion
	//main loop
	while (!done) {
		
	#pragma region Events

		ALLEGRO_EVENT event;
		al_wait_for_event(event_queue, &event);
		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			fullyDone = true;
			done = true;
		}
		else if (event.type == ALLEGRO_EVENT_TIMER) {
			redraw = true;
			//makes sure your clicks dont carry over to next frame!
			leftClick = false;
			//reset button press values
			for (i = 0; i < buttonsNMB1; i++) {
				buttonVal[i] = 0;
			}
			for (i = 0; i < buttonsNMB2; i++) {
				buttonVal2[i] = 0;
			}


		}
		else if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
			x = event.mouse.x;
			y = event.mouse.y;

		}
		else if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			// 1 is left click, 2 is right
			if (event.mouse.button & 1) {
				leftClick = true;

			}
		}
		else if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			if (event.mouse.button & 1) {
				leftClick = false;

			}
		}

		else if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
			if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
				currentPage -= 1;
				if (currentPage < 1) {
					currentPage = 1;
				}
			}
			if (currentPage == 2) {
				#pragma region TextBox Input
				if (event.keyboard.keycode == ALLEGRO_KEY_BACKSPACE) {
					strcpy_s(player1.name, 20, "");
				}
				if (strlen(player1.name) < 15) {
					switch (event.keyboard.keycode) {
					case ALLEGRO_KEY_A:
						strcat_s(player1.name, 20, "A");
						break;
					case ALLEGRO_KEY_B:
						strcat_s(player1.name, 20, "B");
						break;
					case ALLEGRO_KEY_C:
						strcat_s(player1.name, 20, "C");
						break;
					case ALLEGRO_KEY_D:
						strcat_s(player1.name, 20, "D");
						break;
					case ALLEGRO_KEY_E:
						strcat_s(player1.name, 20, "E");
						break;
					case ALLEGRO_KEY_F:
						strcat_s(player1.name, 20, "F");
						break;
					case ALLEGRO_KEY_G:
						strcat_s(player1.name, 20, "G");
						break;
					case ALLEGRO_KEY_H:
						strcat_s(player1.name, 20, "H");
						break;
					case ALLEGRO_KEY_I:
						strcat_s(player1.name, 20, "I");
						break;
					case ALLEGRO_KEY_J:
						strcat_s(player1.name, 20, "J");
						break;
					case ALLEGRO_KEY_K:
						strcat_s(player1.name, 20, "K");
						break;
					case ALLEGRO_KEY_L:
						strcat_s(player1.name, 20, "L");
						break;
					case ALLEGRO_KEY_M:
						strcat_s(player1.name, 20, "M");
						break;
					case ALLEGRO_KEY_N:
						strcat_s(player1.name, 20, "N");
						break;
					case ALLEGRO_KEY_O:
						strcat_s(player1.name, 20, "O");
						break;
					case ALLEGRO_KEY_P:
						strcat_s(player1.name, 20, "P");
						break;
					case ALLEGRO_KEY_Q:
						strcat_s(player1.name, 20, "Q");
						break;
					case ALLEGRO_KEY_R:
						strcat_s(player1.name, 20, "R");
						break;
					case ALLEGRO_KEY_S:
						strcat_s(player1.name, 20, "S");
						break;
					case ALLEGRO_KEY_T:
						strcat_s(player1.name, 20, "T");
						break;
					case ALLEGRO_KEY_U:
						strcat_s(player1.name, 20, "U");
						break;
					case ALLEGRO_KEY_V:
						strcat_s(player1.name, 20, "V");
						break;
					case ALLEGRO_KEY_W:
						strcat_s(player1.name, 20, "W");
						break;
					case ALLEGRO_KEY_X:
						strcat_s(player1.name, 20, "X");
						break;
					case ALLEGRO_KEY_Y:
						strcat_s(player1.name, 20, "Y");
						break;
					case ALLEGRO_KEY_Z:
						strcat_s(player1.name, 20, "Z");

						break;
					}
				}
				

				#pragma endregion
			}
		}


	#pragma endregion
	#pragma region Drawing

		if (redraw && al_is_event_queue_empty(event_queue)) {

			switch (currentPage) {
			case 1:
				#pragma region Page1
				//button checks		
				for (i = 0; i < buttonsNMB1; i++) {
					buttonVal[i] = checkButton(&buttonsMain[i], x, y, leftClick, buttonVal[i]);
				}

				//button drawing
				for (i = 0; i < buttonsNMB1; i++) {
					drawButton(buttonsMain[i], font16, 16);
				}

				//button results check
				//start button
				if (buttonVal[0] == 1) {
					currentPage = 2;
				}
				//ranking button
				else if (buttonVal[1] == 1) {
					
				}
				//quit button
				else if (buttonVal[2] == 1) {
					fullyDone = true;
					done = true;
				}
				#pragma endregion
				break;
			case 2:
				#pragma region Page2

				//text input box
				al_draw_text(font22, colors[0], SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 3 - 55, NULL, "Input Name :");
				al_draw_rectangle(SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 3 -25, SCREEN_WIDTH / 2 + 100, SCREEN_HEIGHT / 3 + 25, colors[0], 1);
				al_draw_textf(font16, colors[0], SCREEN_WIDTH / 2 - 95, SCREEN_HEIGHT / 3 - 20, NULL, player1.name);

				//button checks		
				for (i = 0; i < buttonsNMB2; i++) {
					buttonVal2[i] = checkButton(&buttonsPage2[i], x, y, leftClick, buttonVal2[i]);
				}

				//button drawing
				for (i = 0; i < buttonsNMB1; i++) {
					drawButton(buttonsPage2[i], font16, 16);
				}

				//button results check
				//OK button
				if (buttonVal2[0] == 1) {
					currentPage = 3;
				}

				#pragma endregion
				break;
			case 3:
				#pragma region Page3

				//Story text
				al_draw_multiline_textf(font16, colors[0], 100, SCREEN_HEIGHT / 2 - 100, SCREEN_WIDTH - 200, 30, NULL, "HELLO %s , Welcome to THE GAME!\n Objectives : \n 1. Have fun \n 2. Testing \n All clear? Okay! Press continue to play", player1.name);
				
				//button checks		
				for (i = 0; i < buttonsNMB3; i++) {
					buttonVal3[i] = checkButton(&buttonsPage3[i], x, y, leftClick, buttonVal3[i]);
				}

				//button drawing
				for (i = 0; i < buttonsNMB1; i++) {
					drawButton(buttonsPage3[i], font16, 16);
				}

				//button results check
				//Continue button , switch scenes
				if (buttonVal3[0] == 1) {
					mng.currentScene = MAIN;
					done = true;
				}
				#pragma endregion
				break;
			}
		}

			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
		}

	#pragma endregion


	#pragma region Clean up / destroy

	//destroy everything local here

	#pragma endregion
	sceneLoad();
	return 0;
}
int Main_Scene(){

	#pragma region Variables
	//temps
	int i = 0;
	int j = 0;
	char temp[20];
	//mouse position
	int x = 0;
	int y = 0;
	//mouse left click hold detection
	bool leftClick = false;
	//function main loop end condition
	bool done = false;
	bool redraw = false;
	//navigation vars
	int currentPage = 1;
	//cars for sale generation
	CarListing carsForSale[10];
	for (i = 0; i < 10; i++) {
		carsForSale[i] = generateListing();
	}
	//parts quick listings generation
	Item itemsForSale[15];
	for (i = 0; i < 15; i++) {
		itemsForSale[i] = items_init(i);
	}
	//achievement list
	Achievement achList[30];
	for (i = 0; i < 30; i++) {
		char tempBuffer[20];
		achList[i].isFinished = 0;
		strcpy_s(achList[i].name, 20, "Achievement ");
		_itoa_s(i+1, tempBuffer, 20, 10);
		strcat_s(achList[i].name, 20, tempBuffer);
		strcpy_s(achList[i].description, 50, "Some description");
	}
	//example of one description
	strcpy_s(achList[0].description, 50, "Check Garage");

	//race mode, racers generation
	Opponent oppList[4];
	for (i = 0; i < 4; i++) {
		oppList[i] = opponent_init();
	}
	
	FILE *fp;

	#pragma endregion
	#pragma region Buttons

	#pragma region Page1

	//number of buttons
	const int buttonsNMB1 = 5;
	//menu button detection variable(one for each button)
	int buttonVal[5] = { 0,0,0,0,0 };
	//all buttons
	Button buttonsPage1[5];
	//quick button init
	for (i = 0; i < buttonsNMB1; i++) {
		buttonsPage1[i] = buttonInit(SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 3 + i * 100, 200, 50, colors[0], colors[1], colors[2], colors[3], ReturnOne, "Empty");
	}
	//assign different names for buttons
	strcpy_s(buttonsPage1[0].label, 20, "Home");
	strcpy_s(buttonsPage1[1].label, 20, "Car Shop");
	strcpy_s(buttonsPage1[2].label, 20, "Parts Shop");
	strcpy_s(buttonsPage1[3].label, 20, "Race");
	strcpy_s(buttonsPage1[4].label, 20, "Achievements");

	#pragma endregion
	#pragma region PageHome

	//number of buttons
	const int buttonsNMB2 = 2;
	//menu button detection variable(one for each button)
	int buttonVal2[2] = { 0,0 };
	//all buttons
	Button buttonsHome[2];
	//quick button init
	for (i = 0; i < buttonsNMB2; i++) {
		buttonsHome[i] = buttonInit( 100+i*250, SCREEN_HEIGHT -100, 200, 50, colors[0], colors[1], colors[2], colors[3], ReturnOne, "Empty");
	}
	//assign different names for buttons
	strcpy_s(buttonsHome[0].label, 20, "Garage");
	strcpy_s(buttonsHome[1].label, 20, "Sleep");

	#pragma endregion
	#pragma region PageGarage

	//number of buttons
	const int buttonsNMBGarage = 10;
	//menu button detection variable(one for each button)
	int buttonValGarage[10] = { 0,0,0,0,0,0,0,0,0,0 };
	//all buttons
	Button buttonsGarage[10];
	//quick button init
	for (i = 0; i < buttonsNMBGarage; i++) {
		buttonsGarage[i] = buttonInit(310-100, 112+i*20, 80, 15, colors[0], colors[1], colors[2], colors[3], ReturnOne, "Equip");
	}

	#pragma endregion
	#pragma region PageGarage2

	//number of buttons
	const int buttonsNMBGarage2 = 20;
	//menu button detection variable(one for each button)
	int buttonValGarage2[20] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	//all buttons
	Button buttonsGarage2[20];
	//quick button init
	for (i = 0; i < buttonsNMBGarage2; i++) {
		buttonsGarage2[i] = buttonInit(310 + 20 + 300 - 100, 112 + i * 20, 80, 15, colors[0], colors[1], colors[2], colors[3], ReturnOne, "Equip");
	}

	#pragma endregion
	#pragma region PageCarShop

	//number of buttons
	const int buttonsNMBCarShop = 11;
	//menu button detection variable(one for each button)
	int buttonValCarShop[11] = { 0,0,0,0,0,0,0,0,0,0,0};
	//all buttons
	Button buttonsCarShop[11];
	//quick button init
	for (i = 0; i < buttonsNMBCarShop-1; i++) {
		buttonsCarShop[i] = buttonInit(500, 112 + i * 40, 80, 15, colors[0], colors[1], colors[2], colors[3], ReturnOne, "Buy");
	}
	//sell button
	buttonsCarShop[10] = buttonInit(SCREEN_WIDTH - 300, SCREEN_HEIGHT - 100, 200, 50, colors[0], colors[1], colors[2], colors[3], ReturnOne, "Sell");

	#pragma endregion
	#pragma region PagePartsShop

	//number of buttons
	const int buttonsNMBPartsShop = 15;
	//menu button detection variable(one for each button)
	int buttonValPartsShop[15] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	//all buttons
	Button buttonsPartsShop[15];
	//quick button init
	for (i = 0; i < buttonsNMBPartsShop; i++) {
		buttonsPartsShop[i] = buttonInit(300, 112 + i * 20, 80, 15, colors[0], colors[1], colors[2], colors[3], ReturnOne, "Buy");
	}


	#pragma endregion
	#pragma region PageRace

	//number of buttons
	const int buttonsRaceNMB = 4;
	//menu button detection variable(one for each button)
	int buttonValRace[] = { 0,0,0,0 };
	//all buttons
	Button buttonsRace[4];
	//quick button init
	for (i = 0; i < buttonsRaceNMB; i++) {
		buttonsRace[i] = buttonInit(0, SCREEN_HEIGHT/2-100 , 200, 50, colors[0], colors[1], colors[2], colors[3], ReturnOne, "Race");
	}
	//row1
	buttonsRace[0].x = 300;
	buttonsRace[1].x = 700;
	//row2
	buttonsRace[2].x = 300;
	buttonsRace[2].y = SCREEN_HEIGHT/2+200;
	buttonsRace[3].x = 700;
	buttonsRace[3].y = SCREEN_HEIGHT / 2 + 200;


	#pragma endregion


	#pragma endregion

	//main loop
	while (!done) {

	#pragma region Events

		ALLEGRO_EVENT event;
		al_wait_for_event(event_queue, &event);
		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			fullyDone = true;
			done = true;
			//write and open rankings after closing
			fopen_s(&fp,"\output.html", "w+");
			fprintf(fp, "<html><head><link rel=\"stylesheet\" type=\"text / css\" href=\"style.css\"></head><body>");
			fprintf(fp, "<h1>%s | %d  | %s | </h1></body></html>", player1.name, player1.money, player1.ownedCars[player1.currentCar].name);
			OpenRankings();
		}
		else if (event.type == ALLEGRO_EVENT_TIMER) {
			redraw = true;
			leftClick = false;
			//button value reset
			for (i = 0; i < buttonsNMB1; i++) {
				buttonVal[i] = 0;
			}
			for (i = 0; i < buttonsNMB2; i++) {
				buttonVal2[i] = 0;
			}
			for (i = 0; i < buttonsNMBGarage; i++) {
				buttonValGarage[i] = 0;
			}
			for (i = 0; i < buttonsNMBGarage2; i++) {
				buttonValGarage2[i] = 0;
			}
			for (i = 0; i < buttonsNMBCarShop; i++) {
				buttonValCarShop[i] = 0;
			}
			for (i = 0; i < buttonsNMBPartsShop; i++) {
				buttonValPartsShop[i] = 0;
			}
			for (i = 0; i < buttonsRaceNMB; i++) {
				buttonValRace[i] = 0;
			}
		}
		else if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
			x = event.mouse.x;
			y = event.mouse.y;

		}
		else if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			// 1 is left click, 2 is right
			if (event.mouse.button & 1) {
				leftClick = true;

			}
		}
		else if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			if (event.mouse.button & 1) {
				leftClick = false;

			}
		}
		else if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
			if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
				//Return to main page
				currentPage = 1;
			}
		}
	#pragma endregion
	#pragma region Drawing

		if (redraw && al_is_event_queue_empty(event_queue)) {

			#pragma region Top and Bottom status bar

			//top bar
			al_draw_textf(font16, colors[0], SCREEN_WIDTH - 10, 10, ALLEGRO_ALIGN_RIGHT, "Day : %s ; Hour : %d", EnumsToString(mng.currentDay), mng.currentHour);
			//bot bar
			al_draw_textf(font16, colors[0], 10, SCREEN_HEIGHT - 20, ALLEGRO_ALIGN_LEFT, "Money : %d ; Car : %s", player1.money, player1.ownedCars[player1.currentCar].name);

			#pragma endregion

			switch (currentPage) {
			case 1:
				#pragma region Page1

				//button checking and drawing
				for (i = 0; i < buttonsNMB1; i++) {
					buttonVal[i] = checkButton(&buttonsPage1[i], x, y, leftClick, buttonVal[i]);
					drawButton(buttonsPage1[i], font16, 16);
				}

				//button home
				if (buttonVal[0] == 1) {
					currentPage = 2;
				}
				//button carshop
				if (buttonVal[1] == 1) {
					currentPage = 3;
				}
				//button partsshop
				if (buttonVal[2] == 1) {
					currentPage = 4;
				}
				//button race
				if (buttonVal[3] == 1) {
					currentPage = 5;
				}
				//button achievements
				if (buttonVal[4] == 1) {
					currentPage = 8;
				}

				#pragma endregion
				break;
			case 2:
				#pragma region PageHome

				//button checking and drawing
				for (i = 0; i < buttonsNMB2; i++) {
					buttonVal2[i] = checkButton(&buttonsHome[i], x, y, leftClick, buttonVal2[i]);
					drawButton(buttonsHome[i], font16, 16);
				}

				//button garage
				if (buttonVal2[0] == 1) {
					//show garage screen with inventory/cars/parts and equip if can/want
					currentPage = 6;
					achList[0].isFinished = 1;
				}
				//button sleep
				if (buttonVal2[1] == 1) {
					//some function to skip time to next day 8 AM.
					mng.currentDay += 1;
					if (mng.currentDay > 7) {
						mng.currentDay = 1;
					}
					mng.currentHour = 8;
					currentPage = 1;
				}


				#pragma endregion
				break;
			case 3:
				#pragma region PageCars

				//button checking and drawing
				for (i = 0; i < buttonsNMBCarShop; i++) {
					buttonValCarShop[i] = checkButton(&buttonsCarShop[i], x, y, leftClick, buttonValCarShop[i]);
					drawButton(buttonsCarShop[i], font16, 16);
				}
				//car listings
				for (i = 0; i < 10; i++) {
					al_draw_textf(font16, colors[0], 10, 112 + i * 40, NULL, "%s  Price: %d || Power : %d", carsForSale[i].car.name, carsForSale[i].car.price, carsForSale[i].car.HorsePower);
				}
				//check which buy button was pressed
				for (i = 0; i < 10; i++) {
					if (buttonValCarShop[i] == 1) {
						//buying
						if (player1.money >= carsForSale[i].car.price) {
							//reduce money from account
							player1.money -= carsForSale[i].car.price;

							int temp2 = i;
							int temp = -1;
							//find free spot in car inventory
							for (i = 0; i < 10; i++) {
								if (player1.ownedCars[i].price == 0) {
									temp = i;
								}
							}
							player1.ownedCars[temp] = carsForSale[temp2].car;
							player1.currentCar = temp;

							//reset button so no multi purchase happens
							buttonValCarShop[temp2] = 0;

							//generate new car listing in place of old one
							carsForSale[temp2].car = car_generate();
						}
						//
					}
				}

				//text about selling your current car
				al_draw_text(font22, colors[0], SCREEN_WIDTH - 300, SCREEN_HEIGHT - 130, NULL, "Sell your current car?");
				//sell button been pressed
				if (buttonValCarShop[10] == 1) {
					if (player1.ownedCars[player1.currentCar].price != 0) {
						player1.money += player1.ownedCars[player1.currentCar].price;
						player1.ownedCars[player1.currentCar] = car_init();
					}
				}

				#pragma endregion
				break;
			case 4:
				#pragma region PageParts

				//button checking and drawing
				for (i = 0; i < buttonsNMBPartsShop; i++) {
					buttonValPartsShop[i] = checkButton(&buttonsPartsShop[i], x, y, leftClick, buttonValPartsShop[i]);
					drawButton(buttonsPartsShop[i], font16, 16);
				}

				//draw all possible parts from inventory LIST
				for (i = 0; i < 15; i++) {
					al_draw_textf(font16, colors[0], 20, 112 + i * 20, NULL, "%s || Price: %d", inventory_ToName(itemsForSale[i].itemNR), itemsForSale[i].price);
				}
				//buying parts logic
				for (i = 0; i < 15; i++) {
					if (buttonValPartsShop[i] == 1) {
						//buying
						if (player1.money >= itemsForSale[i].price && player1.inventory.size < 20) {
							//reduce money from account
							player1.money -= itemsForSale[i].price;
							player1.inventory.items[player1.inventory.size] = itemsForSale[i].itemNR;
							player1.inventory.size += 1;
						}
					}
				}

				#pragma endregion
				break;
			case 5:
				#pragma region PageRace

				//button checking and drawing
				for (i = 0; i < buttonsRaceNMB; i++) {
					buttonValRace[i] = checkButton(&buttonsRace[i], x, y, leftClick, buttonValRace[i]);
					drawButton(buttonsRace[i], font16, 16);
				}

				//all 4 button check for opponent and send it into new scene
				for (i = 0; i < 4; i++) {
					if (buttonValRace[i] == 1) {
						//Only let race if have a car
						if (player1.ownedCars[player1.currentCar].HorsePower != 0) {
							mng.currentScene = RACE;
							mng.currentOpponent = oppList[i];
							done = true;
						}
					}
				}		

				//card 1
				al_draw_textf(font22, colors[0], 300, SCREEN_HEIGHT / 2 - 200, NULL, "Name : %s", oppList[0].name);
				al_draw_textf(font22, colors[0], 300, SCREEN_HEIGHT / 2 - 170, NULL, "Car : %s", oppList[0].car.name);
				al_draw_textf(font22, colors[0], 300, SCREEN_HEIGHT / 2 - 140, NULL, "Map : Map1");
				//card 2
				al_draw_textf(font22, colors[0], 700, SCREEN_HEIGHT / 2 - 200, NULL, "Name : %s", oppList[1].name);
				al_draw_textf(font22, colors[0], 700, SCREEN_HEIGHT / 2 - 170, NULL, "Car : %s", oppList[1].car.name);
				al_draw_textf(font22, colors[0], 700, SCREEN_HEIGHT / 2 - 140, NULL, "Map : Map2");
				//card 3
				al_draw_textf(font22, colors[0], 300, SCREEN_HEIGHT / 2 + 100, NULL, "Name : %s", oppList[2].name);
				al_draw_textf(font22, colors[0], 300, SCREEN_HEIGHT / 2 + 130, NULL, "Car : %s", oppList[2].car.name);
				al_draw_textf(font22, colors[0], 300, SCREEN_HEIGHT / 2 + 160, NULL, "Map : Map3");
				//card 4
				al_draw_textf(font22, colors[0], 700, SCREEN_HEIGHT / 2 + 100, NULL, "Name : %s", oppList[3].name);
				al_draw_textf(font22, colors[0], 700, SCREEN_HEIGHT / 2 + 130, NULL, "Car : %s", oppList[3].car.name);
				al_draw_textf(font22, colors[0], 700, SCREEN_HEIGHT / 2 + 160, NULL, "Map : Map4");

				#pragma endregion
				break;
			case 6:
				#pragma region PageGarage

				#pragma region CarEquipping

				//owned cars container +text
				al_draw_rectangle(10, 100, 310, SCREEN_HEIGHT - 50, colors[0], 1);
				al_draw_text(font16, colors[0], 10, 100 - 30, NULL, "Owned Cars");
				for (i = 0; i < 10; i++) {
					al_draw_textf(font16, colors[0], 15, 110 + i * 20, NULL, "%s", player1.ownedCars[i].name);
				}
				//equip buttons check/draw
				for (i = 0; i < buttonsNMBGarage; i++) {
					buttonValGarage[i] = checkButton(&buttonsGarage[i], x, y, leftClick, buttonValGarage[i]);
					drawButton(buttonsGarage[i], font12, 12);
				}
				//equiping logic here
				for (i = 0; i < buttonsNMBGarage; i++) {
					if (buttonValGarage[i] == 1) {
						player1.currentCar = i;
					}
				}

				#pragma endregion
				#pragma region PartsEquipping

				//owned parts container +text
				al_draw_rectangle(310 + 20, 100, 310 + 20 + 300, SCREEN_HEIGHT - 50, colors[0], 1);
				al_draw_text(font16, colors[0], 310 + 20, 100 - 30, NULL, "Owned Parts");
				for (i = 0; i < 20; i++) {
					al_draw_textf(font16, colors[0], 310 + 20 + 5, 110 + i * 20, NULL, "%s", inventory_ToName(player1.inventory.items[i]));
				}
				//equip buttons check/draw
				for (i = 0; i < buttonsNMBGarage2; i++) {
					buttonValGarage2[i] = checkButton(&buttonsGarage2[i], x, y, leftClick, buttonValGarage2[i]);
					drawButton(buttonsGarage2[i], font12, 12);
				}
				//equiping logic for parts
				for (i = 0; i < buttonsNMBGarage2; i++) {
					if (buttonValGarage2[i] == 1) {
						int tempInv = NONE;
						//if car exists - equip logic
						if (player1.ownedCars[player1.currentCar].price != 0) {

							#pragma region Equipping logic

							//returns the item code corresponding to button pressed on inventory
							switch (player1.inventory.items[i]) {
							case 0:
							case 1:
							case 2:
								//one of the engine items is trying to be equipped
								if (player1.ownedCars[player1.currentCar].engineItem == NONE) {
									player1.ownedCars[player1.currentCar].engineItem = player1.inventory.items[i];
									//recalc with new part
									recalculate_car_stats_normal(player1.inventory.items[i]);
									player1.inventory.items[i] = NONE;
								}
								else {
									//already exists in that slot = exchange positions
									tempInv = player1.inventory.items[i];
									player1.inventory.items[i] = player1.ownedCars[player1.currentCar].engineItem;
									player1.ownedCars[player1.currentCar].engineItem = tempInv;
									//recalc with old and new part to do proper calculation
									recalculate_car_stats_exchange(player1.inventory.items[i], tempInv);
								}
								break;
							case 3:
							case 4:
							case 5:
								if (player1.ownedCars[player1.currentCar].turboItem == NONE) {
									player1.ownedCars[player1.currentCar].turboItem = player1.inventory.items[i];
									recalculate_car_stats_normal(player1.inventory.items[i]);
									player1.inventory.items[i] = NONE;
								}
								else {
									//already exists in that slot = exchange positions
									tempInv = player1.inventory.items[i];
									player1.inventory.items[i] = player1.ownedCars[player1.currentCar].turboItem;
									player1.ownedCars[player1.currentCar].turboItem = tempInv;
									recalculate_car_stats_exchange(player1.inventory.items[i], tempInv);
								}
								break;
							case 6:
							case 7:
							case 8:
								if (player1.ownedCars[player1.currentCar].tireItem == NONE) {
									player1.ownedCars[player1.currentCar].tireItem = player1.inventory.items[i];
									recalculate_car_stats_normal(player1.inventory.items[i]);
									player1.inventory.items[i] = NONE;
								}
								else {
									//already exists in that slot = exchange positions
									tempInv = player1.inventory.items[i];
									player1.inventory.items[i] = player1.ownedCars[player1.currentCar].tireItem;
									player1.ownedCars[player1.currentCar].tireItem = tempInv;
									recalculate_car_stats_exchange(player1.inventory.items[i], tempInv);
								}
								break;
							case 9:
							case 10:
							case 11:
								if (player1.ownedCars[player1.currentCar].exhaustItem == NONE) {
									player1.ownedCars[player1.currentCar].exhaustItem = player1.inventory.items[i];
									recalculate_car_stats_normal(player1.inventory.items[i]);
									player1.inventory.items[i] = NONE;
								}
								else {
									//already exists in that slot = exchange positions
									tempInv = player1.inventory.items[i];
									player1.inventory.items[i] = player1.ownedCars[player1.currentCar].exhaustItem;
									player1.ownedCars[player1.currentCar].exhaustItem = tempInv;
									recalculate_car_stats_exchange(player1.inventory.items[i], tempInv);
								}
								break;
							case 12:
							case 13:
							case 14:
								if (player1.ownedCars[player1.currentCar].aeroItem == NONE) {
									player1.ownedCars[player1.currentCar].aeroItem = player1.inventory.items[i];
									recalculate_car_stats_normal(player1.inventory.items[i]);
									player1.inventory.items[i] = NONE;
								}
								else {
									//already exists in that slot = exchange positions
									tempInv = player1.inventory.items[i];
									player1.inventory.items[i] = player1.ownedCars[player1.currentCar].aeroItem;
									player1.ownedCars[player1.currentCar].aeroItem = tempInv;
									recalculate_car_stats_exchange(player1.inventory.items[i], tempInv);
								}
								break;
							}

							#pragma endregion

								
						/*	player1.ownedCars[player1.currentCar].HorsePower = player1.ownedCars[player1.currentCar].baseHorsePower + 50;*/
		

						}
					}
				}

				#pragma endregion
				#pragma region CurrentCarDisplay

				//current car display
				al_draw_textf(font36, colors[0], 310 + 20 + 300 + 150, SCREEN_HEIGHT / 2 - 50, NULL, "%s", player1.ownedCars[player1.currentCar].name);
				al_draw_multiline_textf(font16, colors[0], 310+300+100, SCREEN_HEIGHT / 2 + 50, 300, 25, NULL, "Power : %d || BrakePower : %d || Engine : %s || Exhaust : %s || Tire : %s || Turbo : %s || Aero : %s ||", player1.ownedCars[player1.currentCar].HorsePower, player1.ownedCars[player1.currentCar].BrakePower, inventory_ToName(player1.ownedCars[player1.currentCar].engineItem), inventory_ToName(player1.ownedCars[player1.currentCar].exhaustItem), inventory_ToName(player1.ownedCars[player1.currentCar].tireItem), inventory_ToName(player1.ownedCars[player1.currentCar].turboItem), inventory_ToName(player1.ownedCars[player1.currentCar].aeroItem));
				
				#pragma endregion

				#pragma endregion
				break;
			case 8:
				#pragma region PageAchievements
				//column one
				for (i = 0; i < 15; i++) {
					al_draw_textf(font16, colors[0], 100, 200+i*20, NULL, "%s  || %s || Status : [ %d ]", achList[i].name, achList[i].description, achList[i].isFinished);
				}
				//column two
				for (i = 15; i < 30; i++) {
					al_draw_textf(font16, colors[0], 600, 200 + (i-15) * 20, NULL, "%s  || %s || Status : [ %d ]", achList[i].name, achList[i].description, achList[i].isFinished);
				}

				break;
				#pragma endregion

			}
		}
		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	#pragma endregion


	#pragma region Clean up / destroy

	//destroy everything local here

	#pragma endregion
	sceneLoad();
	return 0;

}
int Race_Scene(Opponent opp) {

#pragma region Variables
	//temps
	int i = 0;
	int j = 0;
	char temp[20];
	//mouse position
	int x = 0;
	int y = 0;
	//mouse left click hold detection
	bool leftClick = false;
	//function main loop end condition
	bool done = false;
	bool redraw = false;
	//navigation vars
	int currentPage = 1;
	//map 1
	Map map1;
	for (i = 0; i < 50; i++) {
		map1.points[i].availableLines = 3;
		map1.points[i].angle = rand() % 120;
		map1.points[i].LeftRight = rand() % 2 + 1;
	}
	int currentPoint = 0;
	RaceManager RaceMng = RaceManager_init();

	//max speeds for each line
	int maxSpeed[3] = { 0,0,0 };
	//sum of speeds per race
	int averageSpeed = 0;

	//enter key detection
	bool enterPressed = false;


#pragma endregion
#pragma region Buttons

	const int buttonsNMBR = 10;
	int buttonsVal[10] = { 0 };

	Button buttonsUI[10];
	for (i = 0; i < 10; i++) {
		buttonsUI[i] = buttonInit(0, 0, 200, 50, colors[0], colors[1], colors[2], colors[3], &ReturnOne, "Text");
	}

	//customize accel buttons name and placement
	for (i = 0; i < 3; i++) {
		buttonsUI[i].y = 618 + i*50;
		strcpy_s(buttonsUI[i].label, 20, "Accel ");
		_itoa_s(i + 1, temp, 20, 10);
		strcat_s(buttonsUI[i].label, 20, temp);
	}
	//customize brake buttons name and placement
	for (i = 0; i < 3; i++) {
		buttonsUI[i+3].x = 200;
		buttonsUI[i+3].y = 618 + i * 50;
		strcpy_s(buttonsUI[i+3].label, 20, "Brake ");
		_itoa_s(i + 1, temp, 20, 10);
		strcat_s(buttonsUI[i+3].label, 20, temp);
	}
	//custom line buttons name and placement
	for (i = 0; i < 3; i++) {
		buttonsUI[i+6].x = 400;
		buttonsUI[i+6].y = 618 + i * 50;
		strcpy_s(buttonsUI[i+6].label, 20, "Line ");
		_itoa_s(i + 1, temp, 20, 10);
		strcat_s(buttonsUI[i+6].label, 20, temp);
	}
	//custom confirm button name and placement
	strcpy_s(buttonsUI[9].label, 20, "Confirm");
	buttonsUI[9].x = 700;
	buttonsUI[9].y = 700;

	#pragma endregion

	//main loop
	while (!done) {

	#pragma region Events

		ALLEGRO_EVENT event;
		al_wait_for_event(event_queue, &event);
		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			fullyDone = true;
			done = true;
		}
		else if (event.type == ALLEGRO_EVENT_TIMER) {
			redraw = true;
			leftClick = false;
			//button value reset
			for (i = 0; i < buttonsNMBR; i++) {
				buttonsVal[i] = 0;
			}
			enterPressed = false;

		}
		else if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
			x = event.mouse.x;
			y = event.mouse.y;

		}
		else if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			// 1 is left click, 2 is right
			if (event.mouse.button & 1) {
				leftClick = true;

			}
		}
		else if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			if (event.mouse.button & 1) {
				leftClick = false;

			}
		}
		else if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
			if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
				//Return to main page
				currentPage = 1;
			}
			else if (event.keyboard.keycode == ALLEGRO_KEY_ENTER) {
				enterPressed = true;
			}
		}
	#pragma endregion
	#pragma region Drawing

		if (redraw && al_is_event_queue_empty(event_queue)) {

			switch (currentPage) {
			case 1:
				#pragma region Racing

			//button checking and drawing
			for (i = 0; i < buttonsNMBR; i++) {
				buttonsVal[i] = checkButton(&buttonsUI[i], x, y, leftClick, buttonsVal[i]);
				drawButton(buttonsUI[i], font16, 16);
			}

			//button functions
			for (i = 0; i < buttonsNMBR; i++) {
				if (buttonsVal[i] == 1) {
					//accel buttons
					if (i < 3) {
						switch (i) {
						case 0:
							RaceMng.chosenAccel = 1;
							break;
						case 1:
							RaceMng.chosenAccel = 2;
							break;
						case 2:
							RaceMng.chosenAccel = 3;
							break;
						}
					}
					//brake buttons
					else if (i >= 3 && i < 6) {
						switch (i) {
						case 3:
							RaceMng.chosenBrake = 1;
							break;
						case 4:
							RaceMng.chosenBrake = 2;
							break;
						case 5:
							RaceMng.chosenBrake = 3;
							break;
						}
					}
					//line change buttons
					else if (i >= 6 && i < 9) {
						switch (i) {
						case 6:
							RaceMng.chosenLine = 1;
							break;
						case 7:
							RaceMng.chosenLine = 2;
							break;
						case 8:
							RaceMng.chosenLine = 3;
							break;
						}
					}
					//confirm button
					else if (i == 9) {
						//do some race manager logic here to calculate everything and go to next turn
						turn_processing(RaceMng);
						//angles/speed pentalty lines etc processing
						//map1.points[currentPoint].angle;
						//map1.points[currentPoint].LeftRight;

						//LEFT
						if (map1.points[currentPoint].LeftRight == 1) {
							//line 1
							maxSpeed[0] = 200 - map1.points[currentPoint].angle * 3;
							//line 2
							maxSpeed[1] = 200 - map1.points[currentPoint].angle *1.5;
							//line 3
							maxSpeed[2] = 200 - map1.points[currentPoint].angle *1.1;
						}
						//RIGHT
						else if (map1.points[currentPoint].LeftRight == 2) {
							//line 1
							maxSpeed[0] = 200 - map1.points[currentPoint].angle *1.1;
							//line 2
							maxSpeed[1] = 200 - map1.points[currentPoint].angle *1.5;
							//line 3
							maxSpeed[2] = 200 - map1.points[currentPoint].angle * 3;
						}

						if (player1.ownedCars[player1.currentCar].currentSpeed > maxSpeed[player1.ownedCars[player1.currentCar].currentLine - 1]) {
							player1.ownedCars[player1.currentCar].currentSpeed = 0;
						}

						averageSpeed += player1.ownedCars[player1.currentCar].currentSpeed;

						//your final result, is amount of points + your speed per point added up and summed for average of time. If you crash, your speed is reduced to 0 or whatever penalty, so you get lower overall results.

						//advance forward or end the race 
						currentPoint += 1;
						if (currentPoint > 49) {
							//race is over
							player1.money += averageSpeed;
							currentPage = 2;
						}
						//calculate rewards once over
					}
				}
			}


			//map drawing
			draw_point(map1.points[currentPoint]);
			/*al_draw_textf(font16, colors[0], 0, 0, NULL, "angle : %d , left/right %d", map1.points[currentPoint].angle, map1.points[currentPoint].LeftRight);*/

			//player car drawing
			draw_car(player1.ownedCars[player1.currentCar]);

			//current speed display
			al_draw_textf(font16, colors[0], 700, 650, NULL, "current speed : %d", player1.ownedCars[player1.currentCar].currentSpeed);

			#pragma endregion
				break;
			case 2:
				#pragma region RaceFinished

				al_draw_textf(font22, colors[0], SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, NULL, "Congrats you finished and won %d $", averageSpeed);

				al_draw_text(font22, colors[0], SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 +200, NULL, "Press Enter to continue");

				if (enterPressed) {
					mng.currentScene = MAIN;
					mng.currentDay += 1;
					done = true;
				}
	

				#pragma endregion
				break;
			}
		}
		
		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	#pragma endregion


	#pragma region Clean up / destroy

	//destroy everything local here

	#pragma endregion
	sceneLoad();
	return 0;

}


#pragma endregion

//Scene loading and main initialization
int sceneLoad() {
	
	//close the game
	if (fullyDone) {
		return 0;
	}
	
	//load scenes
	switch (mng.currentScene) {
	case START:
		Start_Scene();
		break;
	case MAIN:
		Main_Scene();
		break;
	case RACE:
		Race_Scene(mng.currentOpponent);
		break;
	}
}
int main() {

	//default game variables init
	#pragma region INITS / INSTALLS
	time_t t;
	srand((unsigned)time(&t));

	al_init();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon();

	al_install_keyboard();
	al_install_mouse();

	#pragma endregion
	#pragma region DISPLAY

	display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);
	al_set_window_title(display, "Practical work game{PROTOTYPE}");
	if (!display) {
		al_show_native_message_box(NULL, NULL, NULL, "failed to init display", NULL, NULL);
		return -1;
	}

	#pragma endregion
	#pragma region FONTS

	font12 = al_load_font("Roboto-Regular.ttf", 12, NULL);
	font16 = al_load_font("Roboto-Regular.ttf", 16, NULL);
	font22 = al_load_font("Roboto-Regular.ttf", 22, NULL);
	font36 = al_load_font("Roboto-Regular.ttf", 36, NULL);

	#pragma endregion
	#pragma region TIMERS

	timer = al_create_timer(1.0 / FPS);
	al_start_timer(timer);

	#pragma endregion
	#pragma region COLORS

	colors[0] = al_map_rgb(255, 255, 255);
	colors[1] = al_map_rgb(255, 0, 0);
	colors[2] = al_map_rgb(0, 255, 0);
	colors[3] = al_map_rgb(0, 0, 255);

	#pragma endregion
	#pragma region EVENT_QUEUES

	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_mouse_event_source());

	#pragma endregion

	//default player init
	player1 = player_init();

	//default values set on game manager
	mng = GameManager_Init();
	//game start
	sceneLoad();

	#pragma region Clean up / destroy

	al_destroy_font(font12);
	al_destroy_font(font16);
	al_destroy_font(font22);
	al_destroy_font(font36);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	al_destroy_timer(timer);
	//destroy everything here

	#pragma endregion
	return 0;
}
