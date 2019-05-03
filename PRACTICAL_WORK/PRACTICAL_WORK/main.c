//allegro imports
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
//standard imports
#include <stdio.h>
//custom imports


//defines
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

//globals


int main() {

	//inits
	al_init();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon();

	//custom variables
	int FPS = 60;
	bool done = false;
	bool redraw = false;

	//allegro variables
	ALLEGRO_FONT *font = al_load_font("Roboto-Regular.ttf", 36, NULL);
	ALLEGRO_FONT *fontSmall = al_load_font("Roboto-Regular.ttf", 12, NULL);

	ALLEGRO_DISPLAY *display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);
	al_set_window_title(display, "Practical work game");
	if (!display) {
		al_show_native_message_box(NULL, NULL, NULL, "failed to init display", NULL, NULL);
		return -1;
	}

	ALLEGRO_TIMER *timer = al_create_timer(1.0 / FPS);
	al_start_timer(timer);


	//installs
	al_install_keyboard();

	//event sources and queues
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));


	//main loop
	while (!done) {

		ALLEGRO_EVENT event;
		al_wait_for_event(event_queue, &event);
		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			done = true;
		}


		else if (event.type == ALLEGRO_EVENT_TIMER) {
			redraw = true;

		}
	


		if (redraw && al_is_event_queue_empty(event_queue)) {

		
		
			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
		}


	}





	//required clean up!
	al_destroy_font(font);
	al_destroy_font(fontSmall);
	al_destroy_display(display);

	return 0;
}
