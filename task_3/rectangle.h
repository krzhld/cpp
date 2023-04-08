#pragma once
#include <GL/glut.h>

class Rectangle {
public:
	Rectangle();
	Rectangle(GLint pos_x, GLint pos_y, GLint size_x, GLint size_y);
	GLint getX(void) { return this->pos_x; };
	GLint getY(void) { return this->pos_y; };
	GLint getSizeX(void) { return this->size_x; };
	GLint getSizeY(void) { return this->size_y; };
private:
	GLint pos_x;
	GLint pos_y;
	GLint size_x;
	GLint size_y;
};
