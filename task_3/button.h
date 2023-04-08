#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "rectangle.h"

using namespace std;

enum class ButtonStatus {
	NORMAL,
	SELECTED
};

class Button {
public:
	Button();
	Button(GLfloat* color, GLint pos_x, GLint pos_y,
		GLint size_x, GLint size_y, std::string text);
	void changeState(void);
	void addActivity(void(*activity)(void));
	void runActivity(void);
	void draw(void);
	Rectangle getRect(void) { return this->rect; }
private:
	GLfloat* color;
	Rectangle rect;
	string text;
	ButtonStatus status;
	void(*activity)(void);
};
