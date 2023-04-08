#include "button.h"

using namespace std;

Button::Button() {
	this->color = 0;
	this->rect = Rectangle();
	this->text = "NONE";
	this->status = ButtonStatus::NORMAL;
	this->activity = NULL;
}

Button::Button(GLfloat* color, GLint pos_x, GLint pos_y,
	GLint size_x, GLint size_y, string text) {
	this->color = color;
	this->rect = Rectangle(pos_x, pos_y, size_x, size_y);
	this->text = text;
	this->status = ButtonStatus::NORMAL;
	this->activity = NULL;
}

void Button::changeState(void) {
	if (this->status == ButtonStatus::NORMAL)
		this->status = ButtonStatus::SELECTED;
	else
		this->status = ButtonStatus::NORMAL;
}

void Button::addActivity(void(*activity)(void)) {
	this->activity = activity;
}

void Button::runActivity(void) {
	if (this->activity == NULL) {
		cout << "nullable activity!" << endl;
		return;
	}
	activity();
}

void Button::draw(void) {
	GLfloat* colors = this->color;
	if (this->status == ButtonStatus::SELECTED) {
		colors[0] = 1 - colors[0];
		colors[1] = 1 - colors[1];
		colors[2] = 1 - colors[2];
	}
	Rectangle rect = this->rect;
	glColor3f(colors[0], colors[1], colors[2]);
	glRecti(rect.getX(), rect.getY(), rect.getX() + rect.getSizeX(), rect.getY() + rect.getSizeY());
}
