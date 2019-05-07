//backup last 3 days left
//#pragma region Headers
//
////allegro imports
//#include <allegro5/allegro.h>
//#include <allegro5/allegro_native_dialog.h>
//#include <allegro5/allegro_font.h>
//#include <allegro5/allegro_ttf.h>
//#include <allegro5/allegro_primitives.h>
////standard imports
//#include <stdio.h>
//#include <string.h>
//#include <time.h>
////custom imports
//
//#pragma endregion
//#pragma region Globals
//
////defines
//#define SCREEN_WIDTH 1024
//#define SCREEN_HEIGHT 768
//
////global variables
//enum BUTTONSTATE {
//	DEFAULT,
//	HOVER,
//	CLICK
//};
//
//int closeButton() {
//	return 0;
//}
//
//int incrementNumber(int x) {
//	return x += 1;
//}
//
//
//
//
//struct button {
//	int x;
//	int y;
//	int sizeH;
//	int sizeV;
//	ALLEGRO_COLOR color1;
//	ALLEGRO_COLOR color2;
//	ALLEGRO_COLOR color3;
//	ALLEGRO_COLOR color4;
//	int(*function)(int);
//	char label[20];
//	int state;
//};
//typedef struct button button;
//
//button buttonInit(int x, int y, int sizeH, int sizeV, ALLEGRO_COLOR color1, ALLEGRO_COLOR color2, ALLEGRO_COLOR color3, ALLEGRO_COLOR color4, void *function, char text[]) {
//	button btn;
//	btn.x = x;
//	btn.y = y;
//	btn.color1 = color1;
//	btn.color2 = color2;
//	btn.color3 = color3;
//	btn.color4 = color4;
//	btn.sizeH = sizeH;
//	btn.sizeV = sizeV;
//	btn.function = function;
//	strcpy_s(btn.label, 20, text);
//	btn.state = DEFAULT;
//	return btn;
//}
//
//int checkButton(button *btn, int mouse_x, int mouse_y, bool clicked, int functionVal) {
//
//	if (btn->x <= mouse_x &&
//		mouse_x <= btn->x + btn->sizeH &&
//		btn->y <= mouse_y &&
//		mouse_y <= btn->y + btn->sizeV) {
//		if (clicked) {
//			btn->state = CLICK;
//			if (btn->function != NULL)
//				return btn->function(functionVal);
//		}
//		else {
//			btn->state = HOVER;
//			return functionVal;
//		}
//	}
//	else {
//		btn->state = DEFAULT;
//		return functionVal;
//	}
//
//
//	//return 0;
//}
//
//void drawButton(button btn, ALLEGRO_FONT *font, int fontSize) {
//	if (btn.state == CLICK) {
//		al_draw_rectangle(btn.x + 2, btn.y + 2, btn.x + btn.sizeH - 2, btn.y + btn.sizeV - 2, btn.color2, 5);
//		al_draw_textf(font, btn.color2, btn.x + btn.sizeH / 2, (btn.y + btn.sizeV / 2 - fontSize) + fontSize / 7 * 2.5, ALLEGRO_ALIGN_CENTER, "%s", btn.label);
//
//	}
//	else if (btn.state == HOVER) {
//		al_draw_rectangle(btn.x, btn.y, btn.x + btn.sizeH, btn.y + btn.sizeV, btn.color1, 5);
//		al_draw_textf(font, btn.color1, btn.x + btn.sizeH / 2, (btn.y + btn.sizeV / 2 - fontSize) + fontSize / 7 * 2.5, ALLEGRO_ALIGN_CENTER, "%s", btn.label);
//	}
//	else {
//		al_draw_rectangle(btn.x, btn.y, btn.x + btn.sizeH, btn.y + btn.sizeV, btn.color1, 1);
//		al_draw_textf(font, btn.color1, btn.x + btn.sizeH / 2, (btn.y + btn.sizeV / 2 - fontSize) + fontSize / 7 * 2.5, ALLEGRO_ALIGN_CENTER, "%s", btn.label);
//	}
//
//}
//
//#pragma endregion
//
//int main() {
//
//#pragma region Inits
//
//	al_init();
//	al_init_font_addon();
//	al_init_ttf_addon();
//	al_init_primitives_addon();
//
//#pragma endregion
//#pragma region Custom Variables
//
//	int FPS = 60;
//	bool done = false;
//	bool redraw = false;
//
//#pragma endregion
//#pragma region ALLEGRO Variables
//
//#pragma region Fonts
//
//	ALLEGRO_FONT *font12 = al_load_font("Roboto-Regular.ttf", 12, NULL);
//	ALLEGRO_FONT *font16 = al_load_font("Roboto-Regular.ttf", 16, NULL);
//	ALLEGRO_FONT *font22 = al_load_font("Roboto-Regular.ttf", 22, NULL);
//	ALLEGRO_FONT *font36 = al_load_font("Roboto-Regular.ttf", 36, NULL);
//
//#pragma endregion
//#pragma region Display
//
//	ALLEGRO_DISPLAY *display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);
//	al_set_window_title(display, "Practical work game");
//	if (!display) {
//		al_show_native_message_box(NULL, NULL, NULL, "failed to init display", NULL, NULL);
//		return -1;
//	}
//
//#pragma endregion
//#pragma region Timers
//
//	ALLEGRO_TIMER *timer = al_create_timer(1.0 / FPS);
//	al_start_timer(timer);
//
//#pragma endregion
//#pragma region Colors
//
//	ALLEGRO_COLOR color1 = al_map_rgb(255, 255, 255);
//	ALLEGRO_COLOR color2 = al_map_rgb(255, 0, 0);
//	ALLEGRO_COLOR color3 = al_map_rgb(0, 0, 255);
//	ALLEGRO_COLOR color4 = al_map_rgb(0, 255, 0);
//
//#pragma endregion
//
//
//#pragma endregion
//#pragma region Installs
//
//	al_install_keyboard();
//	al_install_mouse();
//
//#pragma endregion
//#pragma region Event sources and Queues
//
//	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
//	al_register_event_source(event_queue, al_get_keyboard_event_source());
//	al_register_event_source(event_queue, al_get_display_event_source(display));
//	al_register_event_source(event_queue, al_get_timer_event_source(timer));
//	al_register_event_source(event_queue, al_get_mouse_event_source());
//
//#pragma endregion
//#pragma region Test Variables
//
//	//mouse position
//	int x = 0;
//	int y = 0;
//	//button press
//	int number = 0;
//	bool leftClick = false;
//	button testbtn = buttonInit(10, 10, 100, 50, color1, color2, color3, color4, &closeButton, "testText");
//	//button oldBtn = buttonInit(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 100, 50, color1, color2, color3, color4, "some old text");
//	//button oldBtn2 = buttonInit(100, SCREEN_HEIGHT-200, 200, 100, color1, color2, color3, color4, "text");
//	button oldBtn2 = buttonInit(100, SCREEN_HEIGHT - 200, 200, 100, color1, color2, color3, color4, &incrementNumber, "text");
//
//
//
//#pragma endregion
//
//
//	//main loop
//	while (!done) {
//		ALLEGRO_EVENT event;
//		al_wait_for_event(event_queue, &event);
//		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
//			done = true;
//		}
//		else if (event.type == ALLEGRO_EVENT_TIMER) {
//			redraw = true;
//
//
//			//checkButton(&testbtn, x, y);
//		}
//		else if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
//			x = event.mouse.x;
//			y = event.mouse.y;
//
//		}
//		else if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
//			// 1 is left click, 2 is right
//			if (event.mouse.button & 1) {
//				leftClick = true;
//
//			}
//		}
//		else if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
//			if (event.mouse.button & 1) {
//				leftClick = false;
//
//			}
//		}
//
//
//
//		if (redraw && al_is_event_queue_empty(event_queue)) {
//			//display mouse position for debugging
//			al_draw_textf(font16, color1, SCREEN_WIDTH, SCREEN_HEIGHT - 16, ALLEGRO_ALIGN_RIGHT, "x = %d ; y = %d", x, y);
//			al_draw_textf(font16, color1, 300, 50, ALLEGRO_ALIGN_CENTER, "value %d", number);
//
//
//			//checkButton(&oldBtn, x, y, leftClick);
//
//			if (number) {
//				number = checkButton(&testbtn, x, y, leftClick, number);
//				drawButton(testbtn, font22, 22);
//			}
//			number = checkButton(&oldBtn2, x, y, leftClick, number);
//
//
//			//drawButton(oldBtn, font16, 16);
//			drawButton(oldBtn2, font36, 36);
//
//			al_flip_display();
//			al_clear_to_color(al_map_rgb(0, 0, 0));
//		}
//
//
//	}
//#pragma region Clean up / destroy
//
//	al_destroy_font(font12);
//	al_destroy_font(font16);
//	al_destroy_font(font22);
//	al_destroy_font(font36);
//	al_destroy_display(display);
//	//add event queues here later
//
//#pragma endregion
//	return 0;
//}
//



//first button functions and regions
//#pragma region Headers
//
////allegro imports
//#include <allegro5/allegro.h>
//#include <allegro5/allegro_native_dialog.h>
//#include <allegro5/allegro_font.h>
//#include <allegro5/allegro_ttf.h>
//#include <allegro5/allegro_primitives.h>
////standard imports
//#include <stdio.h>
//#include <string.h>
////custom imports
//
//#pragma endregion
//#pragma region Globals
//
////defines
//#define SCREEN_WIDTH 1024
//#define SCREEN_HEIGHT 768
//
////global variables
//enum BUTTONSTATE {
//	DEFAULT,
//	HOVER,
//	CLICK
//};
//
//
//struct button {
//	int x;
//	int y;
//	int sizeH;
//	int sizeV;
//	ALLEGRO_COLOR color;
//	char label[20];
//	int state;
//};
//typedef struct button button;
//
//button buttonInit(int x, int y, int sizeH, int sizeV, ALLEGRO_COLOR color, char text[]) {
//	button btn;
//	btn.x = x;
//	btn.y = y;
//	btn.color = color;
//	btn.sizeH = sizeH;
//	btn.sizeV = sizeV;
//	strcpy_s(btn.label, 20, text);
//	btn.state = DEFAULT;
//	return btn;
//}
//
//void checkButton(button *btn, int mouse_x, int mouse_y) {
//	if (btn->x <= mouse_x &&
//		mouse_x <= btn->x + btn->sizeH &&
//		btn->y <= mouse_y &&
//		mouse_y <= btn->y + btn->sizeV) {
//
//		btn->state = HOVER;
//	}
//	else {
//		btn->state = DEFAULT;
//	}
//
//
//	//return 0;
//}
//
//void drawButton(button btn, ALLEGRO_FONT *font) {
//	if (btn.state == DEFAULT) {
//		al_draw_rectangle(btn.x, btn.y, btn.x + btn.sizeH, btn.y + btn.sizeV, btn.color, 1);
//		al_draw_textf(font, btn.color, btn.x + btn.sizeH / 2, btn.y + btn.sizeV / 2, ALLEGRO_ALIGN_CENTER, "%s", btn.label);
//	}
//	else {
//		al_draw_rectangle(btn.x, btn.y, btn.x + btn.sizeH, btn.y + btn.sizeV, btn.color, 5);
//		al_draw_textf(font, btn.color, btn.x + btn.sizeH / 2, btn.y + btn.sizeV / 2, ALLEGRO_ALIGN_CENTER, "%s", btn.label);
//	}
//
//}
//
//#pragma endregion
//
//int main() {
//
//#pragma region Inits
//
//	al_init();
//	al_init_font_addon();
//	al_init_ttf_addon();
//	al_init_primitives_addon();
//
//#pragma endregion
//#pragma region Custom Variables
//
//	int FPS = 60;
//	bool done = false;
//	bool redraw = false;
//
//#pragma endregion
//#pragma region ALLEGRO Variables
//
//#pragma region Fonts
//
//	ALLEGRO_FONT *font12 = al_load_font("Roboto-Regular.ttf", 12, NULL);
//	ALLEGRO_FONT *font16 = al_load_font("Roboto-Regular.ttf", 16, NULL);
//	ALLEGRO_FONT *font22 = al_load_font("Roboto-Regular.ttf", 22, NULL);
//	ALLEGRO_FONT *font36 = al_load_font("Roboto-Regular.ttf", 36, NULL);
//
//#pragma endregion
//#pragma region Display
//
//	ALLEGRO_DISPLAY *display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);
//	al_set_window_title(display, "Practical work game");
//	if (!display) {
//		al_show_native_message_box(NULL, NULL, NULL, "failed to init display", NULL, NULL);
//		return -1;
//	}
//
//#pragma endregion
//#pragma region Timers
//
//	ALLEGRO_TIMER *timer = al_create_timer(1.0 / FPS);
//	al_start_timer(timer);
//
//#pragma endregion
//#pragma region Colors
//
//	ALLEGRO_COLOR color1 = al_map_rgb(255, 255, 255);
//
//#pragma endregion
//
//
//#pragma endregion
//#pragma region Installs
//
//	al_install_keyboard();
//	al_install_mouse();
//
//#pragma endregion
//#pragma region Event sources and Queues
//
//	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
//	al_register_event_source(event_queue, al_get_keyboard_event_source());
//	al_register_event_source(event_queue, al_get_display_event_source(display));
//	al_register_event_source(event_queue, al_get_timer_event_source(timer));
//	al_register_event_source(event_queue, al_get_mouse_event_source());
//
//#pragma endregion
//#pragma region Test Variables
//
//	//mouse position
//	int x = 0;
//	int y = 0;
//	//button press
//	int number = 1;
//	button testbtn = buttonInit(10, 10, 100, 50, color1, "testText");
//
//#pragma endregion
//
//
//	//main loop
//	while (!done) {
//		ALLEGRO_EVENT event;
//		al_wait_for_event(event_queue, &event);
//		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
//			done = true;
//		}
//		else if (event.type == ALLEGRO_EVENT_TIMER) {
//			redraw = true;
//
//			checkButton(&testbtn, x, y);
//		}
//		else if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
//			x = event.mouse.x;
//			y = event.mouse.y;
//
//		}
//		else if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
//			// 1 is left click, 2 is right
//			if (event.mouse.button & 1) {
//				//detecting whether test button is clicked or not
//				if (SCREEN_WIDTH / 2 <= x &&
//					x < SCREEN_WIDTH / 2 + 100 &&
//					SCREEN_HEIGHT / 2 <= y &&
//					y < SCREEN_HEIGHT / 2 + 50) {
//					number += 1;
//				}
//			}
//		}
//
//
//
//		if (redraw && al_is_event_queue_empty(event_queue)) {
//			//display mouse position for debugging
//			al_draw_textf(font16, color1, SCREEN_WIDTH, SCREEN_HEIGHT - 16, ALLEGRO_ALIGN_RIGHT, "x = %d ; y = %d", x, y);
//
//			al_draw_rectangle(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, SCREEN_WIDTH / 2 + 100, SCREEN_HEIGHT / 2 + 50, color1, 1);
//			al_draw_textf(font12, color1, SCREEN_WIDTH / 2 + 50, SCREEN_HEIGHT / 2 + 17, ALLEGRO_ALIGN_CENTER, "%d", number);
//
//			drawButton(testbtn, font12);
//
//			al_flip_display();
//			al_clear_to_color(al_map_rgb(0, 0, 0));
//		}
//
//
//	}
//#pragma region Clean up / destroy
//
//	al_destroy_font(font12);
//	al_destroy_font(font16);
//	al_destroy_font(font22);
//	al_destroy_font(font36);
//	al_destroy_display(display);
//	//add event queues here later
//
//#pragma endregion
//	return 0;
//}




//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//#include <string.h>
//
//#include <allegro5/allegro.h>
//#include <allegro5/allegro_font.h>
//#include <allegro5/allegro_ttf.h>
//
//#include <Windows.h>
//#define MAXCHAR 10000
//int main(){
//
//	FILE *fp;
//	//int num;
//
//	////fopen_s(&fp,"\index2.html", "w+");
//	//fp = fopen("\index2.html", "w+");
//	//fprintf(fp, "<h1>66</h1>");
//	//fprintf(fp, "<div class=\"nice\"><h3>more testing\n</h1></div>");
//
//
//	//fclose(fp);
//
//	////open a file with default program
//	//ShellExecute(NULL, "open", "\index2.html", NULL, NULL, 0);
//
//	//FILE *fptr;
//	//fptr = fopen("\index2.html", "r");
//	//fscanf(fptr, "%d", &num);
//
//	//printf("Value of n=%d", num);
//	//fclose(fptr);
//
//	char str2[80] = "This is - www.tutorialspoint.com - website";
//	const char s[2] = "-";
//	char *token;
//
//	/* get the first token */
//	token = strtok(str2, s);
//	//printf("first token = %s\n\n\n\n\ ", token); returns This is
//
//	/* walk through other tokens */
//	while (token != NULL) {
//		printf(" %s\n", token);
//
//		token = strtok(NULL, s);
//	}
//
//	char str[MAXCHAR];
//	char* filename = "\index2.html";
//
//	fp = fopen(filename, "r");
//
//	token = strtok(str, s);
//	while (fgets(str, MAXCHAR, fp) != NULL) {
//		
//		printf("%s", token);
//		token = strtok(NULL, s);
//	}
//	fclose(fp);
//
//	//al_init();
//	//al_init_font_addon();
//	//al_init_ttf_addon();
//
//	//ALLEGRO_DISPLAY *display = al_create_display(640, 480);
//	//ALLEGRO_FONT *font = al_load_ttf_font("Roboto-Regular.ttf", 13, 0);
//	//while (true) {
//	//	al_clear_to_color(al_map_rgb(0, 0, 0));
//	//	al_draw_text(font, al_map_rgb(255, 255, 255), 0, 0, 0, "HELLO GAME!");
//	//	al_flip_display();
//	//}
//	//al_destroy_display(display);
//	//al_destroy_font(font);
//	system("pause");
//	return 0;
//}


/*

PRACTICAL WORK - EVALDAS PAULAUSKAS PI18E

adventure game;


idea = ASCII touge racing game!, use real images and convert to ascii, load with queue ADT!

*/

//
//#include <allegro5/allegro.h>
//#include <allegro5/allegro_native_dialog.h>
//#include <allegro5/allegro_font.h>
//#include <allegro5/allegro_ttf.h>
//
//#include <allegro5/allegro_primitives.h>
//
//#include <stdio.h>
//
//#define SCREEN_WIDTH 800
//#define SCREEN_HEIGHT 600
//
//enum KEYS { DOWN, UP, RIGHT, LEFT };
//
//int main() {
//
//	//required inits
//	al_init();
//	al_init_font_addon();
//	al_init_ttf_addon();
//	al_init_primitives_addon();
//
//	//simple error check for Init
//	if (!al_init()) {
//		al_show_native_message_box(NULL, NULL, NULL, "failed to init", NULL, NULL);
//		return -1;
//	}
//
//	//variables
//	int FPS = 60;
//
//
//	ALLEGRO_FONT *font = al_load_font("Roboto-Regular.ttf", 36, NULL);
//	ALLEGRO_FONT *fontSmall = al_load_font("Roboto-Regular.ttf", 12, NULL);
//	ALLEGRO_DISPLAY *display = NULL;
//	ALLEGRO_TIMER *timer = NULL;
//
//	//change window mode, must be before create_display to work!
//	//al_set_new_display_flags(ALLEGRO_FULLSCREEN);
//	display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);
//	if (!display) {
//		al_show_native_message_box(NULL, NULL, NULL, "failed to init display", NULL, NULL);
//		return -1;
//	}
//	al_set_window_title(display, "Practical work game");
//
//
//	//keyboard, allows to use it
//	al_install_keyboard();
//
//	//init a timer
//	timer = al_create_timer(1.0 / FPS);
//
//	//create event queue
//	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
//	//register the event into the created queue
//	al_register_event_source(event_queue, al_get_keyboard_event_source());
//	//catch {display} window events (like X icon etc.)
//	al_register_event_source(event_queue, al_get_display_event_source(display));
//	//capture timer events
//	al_register_event_source(event_queue, al_get_timer_event_source(timer));
//
//	al_start_timer(timer);
//
//
//	int state = NULL;
//	bool done = false;
//	bool redraw = false;
//
//	int count = 0;
//
//	int x = 10;
//	int y = 10;
//	int moveSpeed = 3;
//
//	bool keys[4] = { false,false,false,false };
//
//	//gameloop
//	while (!done) {
//		//whenever event is fired, this variable will store its information
//		ALLEGRO_EVENT event;
//		//waiting for key to be pressed, and react to event
//		al_wait_for_event(event_queue, &event);
//		if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
//			switch (event.keyboard.keycode) {
//			case ALLEGRO_KEY_DOWN:
//				keys[DOWN] = true;
//				break;
//			case ALLEGRO_KEY_UP:
//				keys[UP] = true;
//				break;
//			case ALLEGRO_KEY_RIGHT:
//				keys[RIGHT] = true;
//				break;
//			case ALLEGRO_KEY_LEFT:
//				keys[LEFT] = true;
//				break;
//			case ALLEGRO_KEY_ESCAPE:
//				done = true;
//				break;
//			}
//		}
//		else if (event.type == ALLEGRO_EVENT_KEY_UP) {
//			switch (event.keyboard.keycode) {
//			case ALLEGRO_KEY_DOWN:
//				keys[DOWN] = false;
//				break;
//			case ALLEGRO_KEY_UP:
//				keys[UP] = false;
//				break;
//			case ALLEGRO_KEY_RIGHT:
//				keys[RIGHT] = false;
//				break;
//			case ALLEGRO_KEY_LEFT:
//				keys[LEFT] = false;
//				break;
//			case ALLEGRO_KEY_ESCAPE:
//				done = false;
//				break;
//			}
//		}
//
//		// makes X button work!
//		else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
//			done = true;
//		}
//		//activated each time timer procs. This way graphics are only updated 60times a sec, guaranteed
//		else if (event.type == ALLEGRO_EVENT_TIMER) {
//			// this + true/false statements above allow for continuous movement, and moving diagonally
//			y -= keys[UP] * 10;
//			y += keys[DOWN] * 10;
//			x -= keys[LEFT] * 10;
//			x += keys[RIGHT] * 10;
//
//			//frame counter, now it works, cuz it procs only when timer event procs!
//			count++;
//			al_draw_textf(fontSmall, al_map_rgb(255, 255, 255), 200, 200, NULL, "frames? : %d", count);
//
//			//set redraw to true, so it draws in function below. Useful to keep it seperate from event handler function, to make sure everything is clean and maintained, as events interrupt everything else.
//			redraw = true;
//
//		}
//		//will only draw if redrawing is true(60 times a sec) and if all other events have finished, redrawing takes least prioritiy!!! 
//		if (redraw && al_is_event_queue_empty(event_queue)) {
//
//			//do all of the drawing during timers 60frames a sec event as well!
//			//draw player rectangle
//			al_draw_rectangle(x, y, x + 20, y + 20, al_map_rgb(255, 255, 255), 2);
//			//load backbuffer (prevents flickering)
//			al_flip_display();
//			//draw background
//			al_clear_to_color(al_map_rgb(0, 0, 0));
//		}
//
//
//	}
//
//
//
//	//wait 5 seconds
//	//al_rest(5);
//
//	//required clean up!
//	al_destroy_font(font);
//	al_destroy_font(fontSmall);
//	al_destroy_display(display);
//	al_destroy_event_queue(event_queue);
//
//	//system("pause");
//	return 0;
//
//}

/*



*/



//#include <stdio.h>
//#include <string.h>
//
//#include <allegro5/allegro.h>
//#include <allegro5/allegro_font.h>
//#include <allegro5/allegro_ttf.h>
//
//
//int main(){
//
//	al_init();
//	al_init_font_addon();
//	al_init_ttf_addon();
//
//	ALLEGRO_DISPLAY *display = al_create_display(640, 480);
//	ALLEGRO_FONT *font = al_load_ttf_font("Roboto-Regular.ttf", 13, 0);
//	while (true) {
//		al_clear_to_color(al_map_rgb(0, 0, 0));
//		al_draw_text(font, al_map_rgb(255, 255, 255), 0, 0, 0, "HELLO GAME!");
//		al_flip_display();
//	}
//	al_destroy_display(display);
//	al_destroy_font(font);
//	
//	return 0;
//}


//keyboard input testing backup
//#include <allegro5/allegro.h>
//#include <allegro5/allegro_native_dialog.h>
//#include <allegro5/allegro_font.h>
//#include <allegro5/allegro_ttf.h>
//
//#include <allegro5/allegro_primitives.h>
//
//#include <stdio.h>
//
//#define SCREEN_WIDTH 800
//#define SCREEN_HEIGHT 600
//
//enum KEYS { DOWN, UP, RIGHT, LEFT };
//
//int main() {
//
//	//console input shown in allegro testing
//	//int key;
//	//printf("enter number");
//	//key = _getch();
//
//	//required inits
//	al_init();
//	al_init_font_addon();
//	al_init_ttf_addon();
//	al_init_primitives_addon();
//
//	//simple error check for Init
//	if (!al_init()) {
//		al_show_native_message_box(NULL, NULL, NULL, "failed to init", NULL, NULL);
//		return -1;
//	}
//
//	ALLEGRO_FONT *font = al_load_font("Roboto-Regular.ttf", 36, NULL);
//	ALLEGRO_FONT *fontSmall = al_load_font("Roboto-Regular.ttf", 12, NULL);
//	ALLEGRO_DISPLAY *display = NULL;
//
//	//change window mode, must be before create_display to work!
//	//al_set_new_display_flags(ALLEGRO_FULLSCREEN);
//	display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);
//	if (!display) {
//		al_show_native_message_box(NULL, NULL, NULL, "failed to init display", NULL, NULL);
//		return -1;
//	}
//	al_set_window_title(display, "Practical work game");
//
//	// COLORS
//	//ALLEGRO_COLOR testColor = al_map_rgb(255,255,255);
//
//	//keyboard, allows to use it
//	al_install_keyboard();
//
//	//create event queue
//	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
//	//register the event into the created queue
//	al_register_event_source(event_queue, al_get_keyboard_event_source());
//	//catch {display} window events (like X icon etc.)
//	al_register_event_source(event_queue, al_get_display_event_source(display));
//
//	//change background color
//	//al_clear_to_color(al_map_rgb(0, 0, 0));
//	//draw text, centered in the middle of the screen + taking into considerationg font size!!
//	//al_draw_text(font, al_map_rgb(255, 255, 255), SCREEN_WIDTH/2, SCREEN_HEIGHT/2-36, ALLEGRO_ALIGN_CENTER, "Hello world");
//	//draw text, but with variable
//	//al_draw_textf(font, al_map_rgb(255, 255, 255), SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, ALLEGRO_ALIGN_CENTER, "my number = %c", key);
//
//	//al_draw_pixel(100, 100, testColor);
//	//al_draw_line(100, 100, 750, 100, testColor, 5);
//	/* Button, if combine drawing can pull this off!
//	al_draw_rectangle(5, 5, 100, 50, testColor, 3);
//	al_draw_text(fontSmall, testColor, 45, 20, ALLEGRO_ALIGN_CENTER ,"Button");
//	*/
//	//al_draw_rounded_rectangle(400, 300, 500, 350, 20, 20, testColor, 1);
//	//al_draw_filled_rectangle(100, 100, 150, 125, testColor);
//
//	int state = NULL;
//	bool done = false;
//
//	int x = 10;
//	int y = 10;
//	int moveSpeed = 3;
//
//	bool keys[4] = { false,false,false,false };
//
//	//gameloop
//	while (!done) {
//		//whenever event is fired, this variable will store its information
//		ALLEGRO_EVENT event;
//		//waiting for key to be pressed, and react to event
//		al_wait_for_event(event_queue, &event);
//		if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
//			switch (event.keyboard.keycode) {
//			case ALLEGRO_KEY_DOWN:
//				keys[DOWN] = true;
//				break;
//			case ALLEGRO_KEY_UP:
//				keys[UP] = true;
//				break;
//			case ALLEGRO_KEY_RIGHT:
//				keys[RIGHT] = true;
//				break;
//			case ALLEGRO_KEY_LEFT:
//				keys[LEFT] = true;
//				break;
//			case ALLEGRO_KEY_ESCAPE:
//				done = true;
//				break;
//			}
//		}
//		else if (event.type == ALLEGRO_EVENT_KEY_UP) {
//			switch (event.keyboard.keycode) {
//			case ALLEGRO_KEY_DOWN:
//				keys[DOWN] = false;
//				break;
//			case ALLEGRO_KEY_UP:
//				keys[UP] = false;
//				break;
//			case ALLEGRO_KEY_RIGHT:
//				keys[RIGHT] = false;
//				break;
//			case ALLEGRO_KEY_LEFT:
//				keys[LEFT] = false;
//				break;
//			case ALLEGRO_KEY_ESCAPE:
//				done = false;
//				break;
//			}
//		}
//
//		// makes X button work!
//		else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
//			done = true;
//		}
//
//		// this + true/false statements above allow for continuous movement, and moving diagonally
//		y -= keys[UP] * 10;
//		y += keys[DOWN] * 10;
//		x -= keys[LEFT] * 10;
//		x += keys[RIGHT] * 10;
//
//
//		//draw player rectangle
//		al_draw_rectangle(x, y, x + 20, y + 20, al_map_rgb(255, 255, 255), 2);
//		//load backbuffer (prevents flickering)
//		al_flip_display();
//		//draw background
//		al_clear_to_color(al_map_rgb(0, 0, 0));
//
//	}
//
//
//
//	//wait 5 seconds
//	//al_rest(5);
//
//	//required clean up!
//	al_destroy_font(font);
//	al_destroy_font(fontSmall);
//	al_destroy_display(display);
//	al_destroy_event_queue(event_queue);
//
//	//system("pause");
//	return 0;
//
//}


//mouse input + frame counter + timer testing
//#include <allegro5/allegro.h>
//#include <allegro5/allegro_native_dialog.h>
//#include <allegro5/allegro_font.h>
//#include <allegro5/allegro_ttf.h>
//#include <allegro5/allegro_primitives.h>
//#include <stdio.h>
//
//#define SCREEN_WIDTH 800
//#define SCREEN_HEIGHT 600
//
//int main() {
//
//	//required inits
//	al_init();
//	al_init_font_addon();
//	al_init_ttf_addon();
//	al_init_primitives_addon();
//
//	//simple error check for Init
//	if (!al_init()) {
//		al_show_native_message_box(NULL, NULL, NULL, "failed to init", NULL, NULL);
//		return -1;
//	}
//
//	//variables
//	int FPS = 60;
//
//	ALLEGRO_FONT *font = al_load_font("Roboto-Regular.ttf", 36, NULL);
//	ALLEGRO_FONT *fontSmall = al_load_font("Roboto-Regular.ttf", 12, NULL);
//	ALLEGRO_DISPLAY *display = NULL;
//	ALLEGRO_TIMER *timer = NULL;
//
//	//change window mode, must be before create_display to work!
//	//al_set_new_display_flags(ALLEGRO_FULLSCREEN);
//	display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);
//	if (!display) {
//		al_show_native_message_box(NULL, NULL, NULL, "failed to init display", NULL, NULL);
//		return -1;
//	}
//	al_set_window_title(display, "Practical work game");
//
//	//to use  mouse
//	al_install_mouse();
//
//	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
//
//
//	//catch {display} window events (like X icon etc.)
//	al_register_event_source(event_queue, al_get_display_event_source(display));
//	//register mouse events
//	al_register_event_source(event_queue, al_get_mouse_event_source());
//
//	int state = NULL;
//	bool done = false;
//
//	int x = 10;
//	int y = 10;
//	int moveSpeed = 3;
//	int count = 0;
//
//
//	//hide mouse cursor on selected window
//	al_hide_mouse_cursor(display);
//
//
//	//use timer to frame lock. 1 second divide by how many frames per second you want
//	//will proc and event once every certain amount of time
//	timer = al_create_timer(1.0 / FPS);
//	//make sure we catch the events procced by timer in already created event_queue
//	al_register_event_source(event_queue, al_get_timer_event_source(timer));
//	//start timer
//	al_start_timer(timer);
//
//	//gameloop
//	while (!done) {
//		ALLEGRO_EVENT event;
//		al_wait_for_event(event_queue, &event);
//
//
//
//		count++;
//		al_draw_textf(fontSmall, al_map_rgb(255, 255, 255), 2, 2, NULL, "frame count : %d", count);
//
//		// makes X button work!
//		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
//			done = true;
//		}
//		// catch mouse events INSIDE THE WINDOW only, and register its position
//		else if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
//			//draw a rectangle to where the mouse is at
//			x = event.mouse.x;
//			y = event.mouse.y;
//		}
//		//mouse buttons events
//		else if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
//			//right mouse button is 2 ( bitwise check ) (left is 1)
//			if (event.mouse.button & 2) {
//				done = true;
//			}
//		}
//
//
//
//		//draw player rectangle
//		al_draw_rectangle(x, y, x + 20, y + 20, al_map_rgb(255, 255, 255), 2);
//
//		al_flip_display();
//		al_clear_to_color(al_map_rgb(0, 0, 0));
//
//	}
//
//
//
//
//
//	//required clean up!
//	al_destroy_font(font);
//	al_destroy_font(fontSmall);
//	al_destroy_display(display);
//	al_destroy_event_queue(event_queue);
//
//	//system("pause");
//	return 0;
//
//}
