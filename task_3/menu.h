#pragma once

#include "button.h"

class Menu {
public:
	//Menu();
	Menu(GLfloat* color, GLint pos_x, GLint pos_y, GLint size_x, GLint size_y);
	void draw(void);
	Rectangle getRect(void) { return this->rect; }
private:
	int id;
	GLfloat* color;
	Rectangle rect;
};
