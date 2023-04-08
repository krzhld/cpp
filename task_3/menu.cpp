#include "menu.h"

using namespace std;

static int cur_id = 1;

/*Menu::Menu() {
	this->color = 0;
	this->rect = Rectangle();
	this->id = cur_id;
	++cur_id;
}*/

Menu::Menu(GLfloat* color, GLint pos_x, GLint pos_y, GLint size_x, GLint size_y) {
	this->color = color;
	this->rect = Rectangle(pos_x, pos_y, size_x, size_y);
	this->id = cur_id;
	++cur_id;
}

void Menu::draw(void) {
	GLfloat* colors = this->color;
	glColor3f(colors[0], colors[1], colors[2]);
	Rectangle rect = this->rect;
	glRecti(rect.getX(), rect.getY(), rect.getX() + rect.getSizeX(), rect.getY() + rect.getSizeY());
}

/*bool Menu::clickHandler(int x, int y) {
	for (int i = 0; i < this->buttons.size(); i++) {
		Rectangle cur_rect = this->buttons[i].getRect();
		// click inside button?
		if (
			(x > cur_rect.getX()) &&
			(x < (cur_rect.getX() + cur_rect.getSizeX())) &&
			(y > cur_rect.getY()) &&
			(y < (cur_rect.getY() + cur_rect.getSizeY()))
			) {
			this->buttons[i].changeState();
			return true;
		}
	}
	return false;
	/*
	for (auto cur_button : this->buttons) {
		Rectangle cur_rect = cur_button.getRect();
		// click inside button?
		if (
			(x > cur_rect.getX()) &&
			(x < (cur_rect.getX() + cur_rect.getSizeX())) &&
			(y > cur_rect.getY()) &&
			(y < (cur_rect.getY() + cur_rect.getSizeY()))
			) {
			cur_button.changeState();
			return true;
		}
	}
	return false;
	
}*/
