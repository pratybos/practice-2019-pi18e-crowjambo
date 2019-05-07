
#pragma region Headers

//allegro imports
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
//standard imports
#include <stdio.h>
#include <string.h>
#include <time.h>
//custom imports

#pragma endregion
#pragma region Globals

//defines
#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768

//global variables
enum BUTTONSTATE {
	DEFAULT,
	HOVER,
	CLICK
};

int closeButton() {
	return 0;
}

int incrementNumber(int x) {
	return x += 1;
}




struct button {
	int x;
	int y;
	int sizeH;
	int sizeV;
	ALLEGRO_COLOR color1;
	ALLEGRO_COLOR color2;
	ALLEGRO_COLOR color3;
	ALLEGRO_COLOR color4;
	int(*function)(int);
	char label[20];
	int state;
};
typedef struct button button;

button buttonInit(int x, int y, int sizeH, int sizeV, ALLEGRO_COLOR color1, ALLEGRO_COLOR color2, ALLEGRO_COLOR color3, ALLEGRO_COLOR color4, void *function ,char text[]) {
	button btn;
	btn.x = x;
	btn.y = y;
	btn.color1 = color1;
	btn.color2 = color2;
	btn.color3 = color3;
	btn.color4 = color4;
	btn.sizeH = sizeH;
	btn.sizeV = sizeV;
	btn.function = function;
	strcpy_s(btn.label, 20, text);
	btn.state = DEFAULT;
	return btn;
}

int checkButton(button *btn, int mouse_x, int mouse_y, bool clicked, int functionVal) {
	
	if (btn->x <= mouse_x &&
		mouse_x <= btn->x + btn->sizeH &&
		btn->y <= mouse_y &&
		mouse_y <= btn->y + btn->sizeV) {
		if (clicked) {
			btn->state = CLICK;
			if(btn->function != NULL)
			return btn->function(functionVal);
			}
		else {
			btn->state = HOVER;
			return functionVal;
			}	
		}
	else {
		btn->state = DEFAULT;
		return functionVal;
	}


	//return 0;
}

void drawButton(button btn, ALLEGRO_FONT *font, int fontSize) {
	if (btn.state == CLICK) {
		al_draw_rectangle(btn.x+2, btn.y+2, btn.x + btn.sizeH-2, btn.y + btn.sizeV-2, btn.color2, 5);
		al_draw_textf(font, btn.color2, btn.x + btn.sizeH / 2 , (btn.y + btn.sizeV / 2 - fontSize) + fontSize / 7 * 2.5, ALLEGRO_ALIGN_CENTER, "%s", btn.label);

	}
	else if (btn.state == HOVER) {
		al_draw_rectangle(btn.x, btn.y, btn.x + btn.sizeH, btn.y + btn.sizeV, btn.color1, 5);
		al_draw_textf(font, btn.color1, btn.x + btn.sizeH / 2, (btn.y + btn.sizeV / 2 - fontSize) + fontSize / 7 * 2.5, ALLEGRO_ALIGN_CENTER, "%s", btn.label);
	}
	else {
		al_draw_rectangle(btn.x, btn.y, btn.x + btn.sizeH, btn.y + btn.sizeV, btn.color1, 1);
		al_draw_textf(font, btn.color1, btn.x + btn.sizeH / 2, (btn.y + btn.sizeV / 2 - fontSize ) + fontSize/7*2.5, ALLEGRO_ALIGN_CENTER, "%s", btn.label);
	}

}

#pragma endregion

int main() {

	#pragma region Inits

	al_init();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon();

	#pragma endregion
	#pragma region Custom Variables

		int FPS = 60;
		bool done = false;
		bool redraw = false;

	#pragma endregion
	#pragma region ALLEGRO Variables

		#pragma region Fonts

			ALLEGRO_FONT *font12 = al_load_font("Roboto-Regular.ttf", 12, NULL);
			ALLEGRO_FONT *font16 = al_load_font("Roboto-Regular.ttf", 16, NULL);
			ALLEGRO_FONT *font22 = al_load_font("Roboto-Regular.ttf", 22, NULL);
			ALLEGRO_FONT *font36 = al_load_font("Roboto-Regular.ttf", 36, NULL);

		#pragma endregion
		#pragma region Display

			ALLEGRO_DISPLAY *display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);
			al_set_window_title(display, "Practical work game");
			if (!display) {
				al_show_native_message_box(NULL, NULL, NULL, "failed to init display", NULL, NULL);
				return -1;
			}

		#pragma endregion
		#pragma region Timers

			ALLEGRO_TIMER *timer = al_create_timer(1.0 / FPS);
			al_start_timer(timer);

		#pragma endregion
		#pragma region Colors

			ALLEGRO_COLOR color1 = al_map_rgb(255, 255, 255);
			ALLEGRO_COLOR color2 = al_map_rgb(255, 0, 0);
			ALLEGRO_COLOR color3 = al_map_rgb(0, 0, 255);
			ALLEGRO_COLOR color4 = al_map_rgb(0, 255, 0);

		#pragma endregion


	#pragma endregion
	#pragma region Installs

			al_install_keyboard();
			al_install_mouse();

	#pragma endregion
	#pragma region Event sources and Queues

			ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
			al_register_event_source(event_queue, al_get_keyboard_event_source());
			al_register_event_source(event_queue, al_get_display_event_source(display));
			al_register_event_source(event_queue, al_get_timer_event_source(timer));
			al_register_event_source(event_queue, al_get_mouse_event_source());

	#pragma endregion
	#pragma region Test Variables

			//mouse position
			int x = 0;
			int y = 0;
			//button press
			int number = 0;
			bool leftClick = false;
			button testbtn = buttonInit(10, 10, 100, 50, color1,color2,color3,color4,&closeButton, "testText");
			//button oldBtn = buttonInit(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 100, 50, color1, color2, color3, color4, "some old text");
			//button oldBtn2 = buttonInit(100, SCREEN_HEIGHT-200, 200, 100, color1, color2, color3, color4, "text");
			button oldBtn2 = buttonInit(100, SCREEN_HEIGHT - 200, 200, 100, color1, color2, color3, color4, &incrementNumber, "text");

	#pragma endregion


	//main loop
	while (!done) {
		ALLEGRO_EVENT event;
		al_wait_for_event(event_queue, &event);
		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			done = true;
		}
		else if (event.type == ALLEGRO_EVENT_TIMER) {
			redraw = true;


			//checkButton(&testbtn, x, y);
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
	


		if (redraw && al_is_event_queue_empty(event_queue)) {
			//display mouse position for debugging
			al_draw_textf(font16, color1, SCREEN_WIDTH, SCREEN_HEIGHT-16, ALLEGRO_ALIGN_RIGHT, "x = %d ; y = %d", x, y);
			al_draw_textf(font16, color1, 300, 50, ALLEGRO_ALIGN_CENTER, "value %d", number);

			
			//checkButton(&oldBtn, x, y, leftClick);

			if (number) {
				number = checkButton(&testbtn, x, y, leftClick, number);
				drawButton(testbtn, font22, 22);
			}
			number = checkButton(&oldBtn2, x, y, leftClick, number);

			
			//drawButton(oldBtn, font16, 16);
			drawButton(oldBtn2, font36, 36);
		
			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
		}


	}
	#pragma region Clean up / destroy

		al_destroy_font(font12);
		al_destroy_font(font16);
		al_destroy_font(font22);
		al_destroy_font(font36);
		al_destroy_display(display);
		//add event queues here later

	#pragma endregion
	return 0;
}
