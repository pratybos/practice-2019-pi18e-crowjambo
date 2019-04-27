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