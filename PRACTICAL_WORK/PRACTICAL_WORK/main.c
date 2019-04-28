/*

PRACTICAL WORK - EVALDAS PAULAUSKAS PI18E

adventure game;


idea = ASCII touge racing game!, use real images and convert to ascii, load with queue ADT! 

*/


#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include <allegro5/allegro_primitives.h>

#include <stdio.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main() {

	int key;

	printf("enter number");
	key = _getch();

	//required inits
	al_init();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon();
	
	//simple error check for Init
	if (!al_init()) {
		al_show_native_message_box(NULL, NULL, NULL, "failed to init", NULL, NULL);
		return -1;
	}

	ALLEGRO_FONT *font = al_load_font("Roboto-Regular.ttf", 36, NULL);
	ALLEGRO_FONT *fontSmall = al_load_font("Roboto-Regular.ttf", 12, NULL);
	ALLEGRO_DISPLAY *display = NULL;
	
	//change window mode, must be before create_display to work!
	//al_set_new_display_flags(ALLEGRO_FULLSCREEN);
	display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!display) {
		al_show_native_message_box(NULL, NULL, NULL, "failed to init display", NULL, NULL);
		return -1;
	}
	al_set_window_title(display, "Practical work game");
	
	// COLORS
	ALLEGRO_COLOR testColor = al_map_rgb(255,255,255);



	//change background color
	al_clear_to_color(al_map_rgb(0, 0, 0));
	//draw text, centered in the middle of the screen + taking into considerationg font size!!
	al_draw_text(font, al_map_rgb(255, 255, 255), SCREEN_WIDTH/2, SCREEN_HEIGHT/2-36, ALLEGRO_ALIGN_CENTER, "Hello world");
	//draw text, but with variable
	al_draw_textf(font, al_map_rgb(255, 255, 255), SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, ALLEGRO_ALIGN_CENTER, "my number = %c", key);

	//al_draw_pixel(100, 100, testColor);
	//al_draw_line(100, 100, 750, 100, testColor, 5);
	/* Button, if combine drawing can pull this off!
	al_draw_rectangle(5, 5, 100, 50, testColor, 3);
	al_draw_text(fontSmall, testColor, 45, 20, ALLEGRO_ALIGN_CENTER ,"Button");
	*/
	//al_draw_rounded_rectangle(400, 300, 500, 350, 20, 20, testColor, 1);
	//al_draw_filled_rectangle(100, 100, 150, 125, testColor);

	//load backbuffer (prevents flickering)
	al_flip_display();

	//wait 5 seconds
	al_rest(5);
	
	//required clean up!
	al_destroy_font(font);
	al_destroy_display(display);

	//system("pause");
	return 0;

}




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