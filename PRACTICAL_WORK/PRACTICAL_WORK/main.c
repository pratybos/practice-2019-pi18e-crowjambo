#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include <stdio.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGTH 600

int main() {

	int key;

	printf("enter number");
	key = _getch();

	//required inits
	al_init();
	al_init_font_addon();
	al_init_ttf_addon();
	
	//simple error check for Init
	if (!al_init()) {
		al_show_native_message_box(NULL, NULL, NULL, "failed to init", NULL, NULL);
		return -1;
	}


	ALLEGRO_FONT *font = al_load_font("Roboto-Regular.ttf", 36, NULL);
	ALLEGRO_DISPLAY *display = NULL;
	

	display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGTH);
	if (!display) {
		al_show_native_message_box(NULL, NULL, NULL, "failed to init display", NULL, NULL);
		return -1;
	}
	al_set_window_title(display, "Practical work game");

	//change background color
	al_clear_to_color(al_map_rgb(0, 0, 0));
	//draw text, centered in the middle of the screen + taking into considerationg font size!!
	al_draw_text(font, al_map_rgb(255, 255, 255), SCREEN_WIDTH/2, SCREEN_HEIGTH/2-36, ALLEGRO_ALIGN_CENTER, "Hello world");
	//draw text, but with variable
	al_draw_textf(font, al_map_rgb(255, 255, 255), SCREEN_WIDTH / 2, SCREEN_HEIGTH / 2, ALLEGRO_ALIGN_CENTER, "my number = %c", key);

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