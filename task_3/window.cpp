#include "window.h"

Window::Window() {
	this->rect = Rectangle(0, 0, 0, 0);
	this->name = "System menu";
}

Window::Window(ifstream& stream) {
	this->rect = Rectangle(80, 80, 800, 600);
	this->name = "System menu";

	this->init(stream);
}

void Window::init(ifstream& stream) {
	string cur_string;
	int menu_indicator = 0;
	int button_indicator = 0;

	string menu_color = "", menu_rect = "";
	string button_color = "", button_rect = "", button_text = "";

	while (getline(stream, cur_string)) {
		if (cur_string == "MenuBegin") {
			menu_color = "";
			menu_rect = "";
			++menu_indicator;
			continue;
		}
		// "menuColor=" has length 10
		if (cur_string.substr(0, 10) == "menuColor=") {
			menu_color = cur_string.substr(10);
			continue;
		}
		// "menuRect=" has length 9
		if (cur_string.substr(0, 9) == "menuRect=") {
			menu_rect = cur_string.substr(9);
			continue;
		}
		if (cur_string == "MenuEnd") {
			this->addMenu(menu_color, menu_rect);
			--menu_indicator;
			continue;
		}
		if (cur_string == "ButtonBegin") {
			++button_indicator;
			button_color = "";
			button_rect = "";
			continue;
		}
		// "buttonColor=" has length 12
		if (cur_string.substr(0, 12) == "buttonColor=") {
			button_color = cur_string.substr(12);
			continue;
		}
		// "buttonRect=" has length 11
		if (cur_string.substr(0, 11) == "buttonRect=") {
			button_rect = cur_string.substr(11);
			continue;
		}
		// "buttonText=" has length 11
		if (cur_string.substr(0, 11) == "buttonText=") {
			button_text = cur_string.substr(11);
			continue;
		}
		if (cur_string == "ButtonEnd") {
			this->addButton(button_color, button_rect, button_text);
			--button_indicator;
			continue;
		}
	}
	if (!button_indicator && !menu_indicator)
		cout << "Success!" << endl;
	else
		cout << "Something not right..." << endl;
}

void Window::addMenu(string color, string rect) {
	const char number_delim = ',';
	stringstream ss_color(color);
	string item;
	GLfloat* elems_color = (GLfloat*)calloc(3, sizeof(GLfloat));
	if (elems_color == NULL)
		return;
	int i = 0;
	while (getline(ss_color, item, number_delim) && i <= 2) {
		elems_color[i] = (GLfloat)stoi(item) / 255.0f;
		++i;
	}	
	ss_color.clear();
	stringstream ss_rect(rect);
	vector<int> elems_rect;
	while (getline(ss_rect, item, number_delim))
		elems_rect.push_back(stoi(item));
	ss_rect.clear();

	auto menu = Menu(elems_color, elems_rect[0], elems_rect[1], elems_rect[2], elems_rect[3]);
	Rectangle main_rect = this->rect;
	Rectangle add_rect = menu.getRect();
	// is add_rect inside main_rect
	if ((add_rect.getX() >= 0) &&
		(add_rect.getX() < main_rect.getSizeX()) &&
		(add_rect.getY() >= 0) &&
		(add_rect.getY() < main_rect.getSizeY())
		) {
		this->array_menu.push_back(menu);
	}
	elems_rect.clear();
}

void Window::addButton(string color, string rect, string text) {
	const char number_delim = ',';
	const char string_delim = '"';
	stringstream ss_color(color);
	string item;
	GLfloat* elems_color = (GLfloat*)calloc(3, sizeof(GLfloat));
	if (elems_color == NULL)
		return;
	int i = 0;
	while (getline(ss_color, item, number_delim) && i <= 2) {
		elems_color[i] = (GLfloat)stoi(item) / 255.0f;
		++i;
	}
	ss_color.clear();
	stringstream ss_rect(rect);
	vector<int> elems_rect;
	while (getline(ss_rect, item, number_delim))
		elems_rect.push_back(stoi(item));
	ss_rect.clear();

	auto button = Button(elems_color, elems_rect[0], elems_rect[1], elems_rect[2], elems_rect[3], text);

	Rectangle add_rect = button.getRect();
	for (auto cur_button : this->array_buttons) {
		static Rectangle cur_rect = cur_button.getRect();
		// is there an intersection
		if (
			(add_rect.getX() > (cur_rect.getX() + cur_rect.getSizeX())) ||
			((add_rect.getX() + add_rect.getSizeX()) < cur_rect.getX()) ||
			(add_rect.getY() > (cur_rect.getY() + cur_rect.getSizeY())) ||
			((add_rect.getY() + add_rect.getSizeY()) < cur_rect.getY())
			) {

		}
		else {
			return;
		}
	}
	this->array_buttons.push_back(button);
	elems_rect.clear();
}

bool Window::clickHandler(int x, int y) {
	for (int i = 0; i < this->array_buttons.size(); i++) {
		Rectangle cur_rect = array_buttons[i].getRect();
		// click inside button?
		if (
			(x > cur_rect.getX()) &&
			(x < (cur_rect.getX() + cur_rect.getSizeX())) &&
			(y > cur_rect.getY()) &&
			(y < (cur_rect.getY() + cur_rect.getSizeY()))
			) {
			array_buttons[i].changeState();
			return true;
		}
	}
	return false;
}

void Window::draw(void) {
	for (auto cur_menu : this->array_menu)
		cur_menu.draw();
	for (auto cur_button : this->array_buttons)
		cur_button.draw();
}
