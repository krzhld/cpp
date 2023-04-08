#include "rectangle.h"

Rectangle::Rectangle(GLint pos_x, GLint pos_y, GLint size_x, GLint size_y) {
	this->pos_x = pos_x;
	this->pos_y = pos_y;
	this->size_x = size_x;
	this->size_y = size_y;
}

Rectangle::Rectangle() {
	Rectangle(0, 0, 0, 0);
}
