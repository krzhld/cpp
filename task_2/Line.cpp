#include "Line.h"

Line::Line(void) {
	this->middle_p = GVector(20.0f, 20.0f);
	this->length = LENGTH;
}

Line::Line(float length) {
	this->middle_p = GVector(20.0f, 20.0f);
	this->length = length;
}

Line::Line(GVector middle_p, float length) {
	this->middle_p = middle_p;
	this->length = length;
}
