#pragma region Headers

//allegro and custom imports
#include "MainLibs.h"
//standard imports
#include <stdio.h>
#include <string.h>
#include <time.h>

#pragma endregion
#pragma region Globals

//defines
#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768

//variables
bool fullyDone = false;
GameManager mng;
int FPS = 60;
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

int ReturnOne() {
	return 1;
}

int TestFun2() {
	return 1;
};
//useful for multi-init of buttons, in case they all need very different functionality
int(*buttonFuncArray[3]) = { ReturnOne, TestFun2, NULL};

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
			//display mouse position for debugging
			al_draw_textf(font16, colors[0], SCREEN_WIDTH, SCREEN_HEIGHT - 16, ALLEGRO_ALIGN_RIGHT, "x = %d ; y = %d", x, y);

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
					//printf("ranking was pressed");
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
int Main_Scene(){}
int Home_Scene(){}
int CarShop_Scene(){}
int PartsShop_Scene(){}
int Race_Scene(){}

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

		break;
	case HOME:

		break;
	case CAR_SHOP:

		break;
	case PARTS_SHOP:

		break;
	case RACE:

		break;
	}
}
int main() {

	//default game variables init
	#pragma region INITS / INSTALLS

	al_init();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon();

	al_install_keyboard();
	al_install_mouse();

	#pragma endregion
	#pragma region DISPLAY

	display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);
	al_set_window_title(display, "Practical work game");
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
