#pragma once
#include "Line.h"
#include "Graphics.h"
#include <list>

#define MARGIN 50
#define HEIGHT 800
#define WIDTH 800
#define SPEED 5.0f
#define WHITE (RGB(255, 255, 255))

using namespace std;

enum class MotionStates {
	WAITING,
	LEFT,
	RIGHT,
	UP,
	DOWN
};

class Trace {
public:
	Trace(void);
	void changeState(MotionStates state);
	void move(void);
	void draw(HDC hdc);
	MotionStates getState(void) { return this->state; }
private:
	void moveToGVector(HDC hdc, GVector vec);
	void lineToGVector(HDC hdc, GVector vec);
	list<Line> list_lines;
	MotionStates state;
	Graphics graphic_tools;
};
