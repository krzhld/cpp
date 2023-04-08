#pragma once

#include "menu.h"
#include <cmath>
#include <sstream>

using namespace std;

class Window {
public:
	Window();
	Window(ifstream& stream);
	void addMenu(string color, string rect);
	void addButton(string color, string rect, string text);
	bool clickHandler(int x, int y);
	void draw(void);
	Rectangle getRect(void) { return this->rect; }
	string getName(void) { return this->name; }
	//vector<Menu> getArrayMenu(void) { return this->array_menu; }
	//vector<Button> getArrayButtons(void) { return this->array_buttons; }
private:
	void init(ifstream& stream);
	Rectangle rect;
	vector<Menu> array_menu;
	vector<Button> array_buttons;
	string name;
};
