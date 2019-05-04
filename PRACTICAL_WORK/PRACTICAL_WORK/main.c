
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


struct button {
	int x;
	int y;
	int sizeH;
	int sizeV;
	ALLEGRO_COLOR color;
	char label[20];
	int state;
};
typedef struct button button;

button buttonInit(int x, int y, int sizeH, int sizeV, ALLEGRO_COLOR color, char text[]) {
	button btn;
	btn.x = x;
	btn.y = y;
	btn.color = color;
	btn.sizeH = sizeH;
	btn.sizeV = sizeV;
	strcpy_s(btn.label, 20, text);
	btn.state = DEFAULT;
	return btn;
}

void checkButton(button *btn, int mouse_x, int mouse_y) {
	if (btn->x <= mouse_x &&
		mouse_x <= btn->x + btn->sizeH &&
		btn->y <= mouse_y &&
		mouse_y <= btn->y + btn->sizeV) {

		btn->state = HOVER;
	}
	else {
		btn->state = DEFAULT;
	}


	//return 0;
}

void drawButton(button btn, ALLEGRO_FONT *font) {
	if (btn.state == DEFAULT) {
		al_draw_rectangle(btn.x, btn.y, btn.x + btn.sizeH, btn.y + btn.sizeV, btn.color, 1);
		al_draw_textf(font, btn.color, btn.x + btn.sizeH / 2, btn.y + btn.sizeV / 2, ALLEGRO_ALIGN_CENTER, "%s", btn.label);
	}
	else {
		al_draw_rectangle(btn.x, btn.y, btn.x + btn.sizeH, btn.y + btn.sizeV, btn.color, 5);
		al_draw_textf(font, btn.color, btn.x + btn.sizeH / 2, btn.y + btn.sizeV / 2, ALLEGRO_ALIGN_CENTER, "%s", btn.label);
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
			int number = 1;
			button testbtn = buttonInit(10, 10, 100, 50, color1, "testText");
			
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

			checkButton(&testbtn, x, y);
		}
		else if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
			x = event.mouse.x;
			y = event.mouse.y;
			
		}
		else if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			// 1 is left click, 2 is right
			if (event.mouse.button & 1) {
				//detecting whether test button is clicked or not
				if (SCREEN_WIDTH / 2 <= x &&
					x < SCREEN_WIDTH / 2 +100 &&
					SCREEN_HEIGHT /2 <= y &&
					y < SCREEN_HEIGHT /2 +50) {
					number += 1;
				}
			}
		}
	


		if (redraw && al_is_event_queue_empty(event_queue)) {
			//display mouse position for debugging
			al_draw_textf(font16, color1, SCREEN_WIDTH, SCREEN_HEIGHT-16, ALLEGRO_ALIGN_RIGHT, "x = %d ; y = %d", x, y);
			
			al_draw_rectangle(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, SCREEN_WIDTH / 2 + 100, SCREEN_HEIGHT / 2 + 50, color1, 1);
			al_draw_textf(font12, color1, SCREEN_WIDTH / 2+50, SCREEN_HEIGHT / 2 +17, ALLEGRO_ALIGN_CENTER, "%d", number);

			drawButton(testbtn, font12);
		
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
