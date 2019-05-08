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

int QuitGame() {
	return 1;
}

int TestFun() {
	return 1;
}

int TestFun2() {
	return 1;
};

int(*buttonFuncArray[3]) = { TestFun, TestFun2, QuitGame};

#pragma endregion
#pragma region SCENES

int Start_Scene() {

#pragma region Variables
	int i = 0;
	//mouse position
	int x = 0;
	int y = 0;
	//mouse left click hold detection
	bool leftClick = false;
	//function main loop end condition
	bool done = false;
	bool redraw = false;
	//menu button detection variable
	int buttonVal[3] = { 0,0,0 };

	#pragma region Buttons

	Button buttonsMain[3];
	for (i = 0; i < 3; i++) {
		buttonsMain[i] = buttonInit(SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 3+i*100, 200, 50, colors[0], colors[1], colors[2], colors[3], buttonFuncArray[i], "Empty");
	}
	strcpy_s(buttonsMain[0].label, 20, "Start Game");

	strcpy_s(buttonsMain[1].label, 20, "Rankings");

	strcpy_s(buttonsMain[2].label, 20, "Quit Game");


	#pragma endregion


	#pragma endregion

	//main loop
	while (!done) {
		//reset button press values
		for (i = 0; i < 3; i++) {
			buttonVal[i] = 0;
		}

	#pragma region Events

		ALLEGRO_EVENT event;
		al_wait_for_event(event_queue, &event);
		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			fullyDone = true;
			done = true;
		}
		else if (event.type == ALLEGRO_EVENT_TIMER) {
			redraw = true;

			//could add+1 to some variable here and have an IF statement at certain value to create an even that triggers every X amount of frames, rather than using seperate timer ( for example a slower animation than 60fps etc.)

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

	#pragma endregion
	#pragma region Drawing

		if (redraw && al_is_event_queue_empty(event_queue)) {
			//display mouse position for debugging
			al_draw_textf(font16, colors[0], SCREEN_WIDTH, SCREEN_HEIGHT - 16, ALLEGRO_ALIGN_RIGHT, "x = %d ; y = %d", x, y);

			//button checks		
			for (i = 0; i < 3; i++) {
				buttonVal[i] = checkButton(&buttonsMain[i], x, y, leftClick, buttonVal[i]);
			}

			//button drawing
			for (i = 0; i < 3; i++) {
				drawButton(buttonsMain[i], font16, 16);
			}
				
			//button results check
			if (buttonVal[0] == 1) {
				printf("start was pressed");
			}
			else if (buttonVal[1] == 1) {
				printf("ranking was pressed");
			}
			else if (buttonVal[2] == 1) {
				fullyDone = true;
				done = true;
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
