#include "Trace.h"

Trace::Trace(void) {
	float length = LENGTH;
	for (int i = 0; i < FREQ; i++) {
		this->list_lines.push_back(Line(length));
		length += DELTALENGTH;
	}
	this->state = MotionStates::WAITING;
	this->graphic_tools = Graphics();
}

void Trace::changeState(MotionStates state) {
	this->state = state;
}

void Trace::move(void) {
	this->list_lines.pop_back();
	Line add_line;
	switch (this->state) {
	case MotionStates::RIGHT:
		add_line = Line(this->list_lines.front().getMiddleP() + GVector(SPEED, 0), LENGTH);
		if (add_line.getMiddleP().getX() + add_line.getLength() * (float)cos(add_line.getAngle()) / 2 > WIDTH) {
			this->changeState(MotionStates::LEFT);
			add_line = Line(this->list_lines.front().getMiddleP() + GVector(-SPEED, 0), LENGTH);
		}
		break;
	case MotionStates::LEFT:
		add_line = Line(this->list_lines.front().getMiddleP() + GVector(-SPEED, 0), LENGTH);
		if (add_line.getMiddleP().getX() - add_line.getLength() * (float)cos(add_line.getAngle()) / 2 < 0) {
			this->changeState(MotionStates::RIGHT);
			add_line = Line(this->list_lines.front().getMiddleP() + GVector(SPEED, 0), LENGTH);
		}
		break;
	case MotionStates::UP:
		add_line = Line(this->list_lines.front().getMiddleP() + GVector(0, -SPEED), LENGTH);
		if (add_line.getMiddleP().getY() - add_line.getLength() * (float)sin(add_line.getAngle()) / 2 < 0) {
			this->changeState(MotionStates::DOWN);
			add_line = Line(this->list_lines.front().getMiddleP() + GVector(0, SPEED), LENGTH);
		}
		break;
	case MotionStates::DOWN:
		add_line = Line(this->list_lines.front().getMiddleP() + GVector(0, SPEED), LENGTH);
		if (add_line.getMiddleP().getY() + add_line.getLength() * (float)sin(add_line.getAngle()) / 2 > HEIGHT - MARGIN) {
			this->changeState(MotionStates::UP);
			add_line = Line(this->list_lines.front().getMiddleP() + GVector(0, -SPEED), LENGTH);
		}
		break;
	case MotionStates::WAITING:
		return;
		break;
	}
	this->list_lines.push_front(add_line);
	list<Line>::iterator pos;
	pos = this->list_lines.begin();
	for (advance(pos, 1); pos != this->list_lines.end(); pos++)
		(*pos).incrLength();
}

void Trace::draw(HDC hdc) {
	static HBRUSH hBackBrush = CreateSolidBrush(WHITE);
	SelectObject(hdc, hBackBrush);
	Rectangle(hdc, -1, -1, WIDTH, HEIGHT);

	auto pens = this->graphic_tools.getPens();

	GVector cur_middle_p = this->list_lines.front().getMiddleP();
	float cur_length = this->list_lines.front().getLength();
	float cur_angle = this->list_lines.front().getAngle();
	if (this->state == MotionStates::WAITING) {
		SelectObject(hdc, pens[0]);
		moveToGVector(hdc, cur_middle_p + GVector(cur_length * (float)cos(cur_angle) / 2.0f, -cur_length * (float)sin(cur_angle) / 2.0f));
		lineToGVector(hdc, cur_middle_p + GVector(-cur_length * (float)cos(cur_angle), cur_length * (float)sin(cur_angle)));
		return;
	}
	else {
		list<Line>::iterator iter = this->list_lines.begin();
		for (int i = 0; i < FREQ / 2; i++) {
			SelectObject(hdc, pens[i]);
			for (int j = 0; j < 2; j++) {
				cur_middle_p = (*iter).getMiddleP();
				cur_length = (*iter).getLength();
				cur_angle = (*iter).getAngle();
				moveToGVector(hdc, cur_middle_p + GVector(cur_length * (float)cos(cur_angle) / 2.0f, -cur_length * (float)sin(cur_angle) / 2.0f));
				lineToGVector(hdc, cur_middle_p + GVector(-cur_length * (float)cos(cur_angle), cur_length * (float)sin(cur_angle)));
				++iter;
			}
		}
	}
}

inline void Trace::moveToGVector(HDC hdc, GVector vec) {
	MoveToEx(hdc, (int)vec.getX(), (int)vec.getY(), NULL);
}

inline void Trace::lineToGVector(HDC hdc, GVector vec) {
	LineTo(hdc, (int)vec.getX(), (int)vec.getY());
}
