#include "Button.h"


Button buttonInit(int x, int y, int sizeH, int sizeV, ALLEGRO_COLOR color1, ALLEGRO_COLOR color2, ALLEGRO_COLOR color3, ALLEGRO_COLOR color4, void *function, char text[]) {
	Button btn;
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

int checkButton(Button *btn, int mouse_x, int mouse_y, bool isClicked, int functionVal) {
	if (btn->x <= mouse_x &&
		mouse_x <= btn->x + btn->sizeH &&
		btn->y <= mouse_y &&
		mouse_y <= btn->y + btn->sizeV) {
		if (isClicked) {
			btn->state = CLICK;
			if (btn->function != NULL)
				al_rest(0.1);
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
}

void drawButton(Button btn, ALLEGRO_FONT *font, int fontSize) {
	//click state
	if (btn.state == CLICK) {
		al_draw_rectangle(btn.x + 2, btn.y + 2, btn.x + btn.sizeH - 2, btn.y + btn.sizeV - 2, btn.color2, 5);
		al_draw_textf(font, btn.color2, btn.x + btn.sizeH / 2, (btn.y + btn.sizeV / 2 - fontSize) + fontSize / 7 * 2.5, ALLEGRO_ALIGN_CENTER, "%s", btn.label);

	}//hover state
	else if (btn.state == HOVER) {
		al_draw_rectangle(btn.x, btn.y, btn.x + btn.sizeH, btn.y + btn.sizeV, btn.color1, 5);
		al_draw_textf(font, btn.color1, btn.x + btn.sizeH / 2, (btn.y + btn.sizeV / 2 - fontSize) + fontSize / 7 * 2.5, ALLEGRO_ALIGN_CENTER, "%s", btn.label);
	}//default state
	else {
		al_draw_rectangle(btn.x, btn.y, btn.x + btn.sizeH, btn.y + btn.sizeV, btn.color1, 1);
		al_draw_textf(font, btn.color1, btn.x + btn.sizeH / 2, (btn.y + btn.sizeV / 2 - fontSize) + fontSize / 7 * 2.5, ALLEGRO_ALIGN_CENTER, "%s", btn.label);
	}
}

