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
