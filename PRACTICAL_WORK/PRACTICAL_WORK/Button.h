#pragma once
#include "MainLibs.h"

//structs
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
typedef struct button Button;

enum BUTTONSTATE {
	DEFAULT,
	HOVER,
	CLICK
};

//functions
Button buttonInit(int x, int y, int sizeH, int sizeV, ALLEGRO_COLOR color1, ALLEGRO_COLOR color2, ALLEGRO_COLOR color3, ALLEGRO_COLOR color4, void *function, char text[]);
int checkButton(Button *btn, int mouse_x, int mouse_y, bool isClicked, int functionVal);
void drawButton(Button btn, ALLEGRO_FONT *font, int fontSize);