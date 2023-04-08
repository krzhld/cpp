#pragma once
#include "GVector.h"

#define DELTALENGTH 1.0f
#define PI 3.14159265f
#define LENGTH 20.0f

class Line {
public:
	Line(void);
	Line(float length);
	Line(GVector middle_p, float length);
	GVector getMiddleP(void) { return this->middle_p; }
	float getLength(void) { return this->length; }
	float getAngle(void) { return this->angle; }
	void incrLength(void) { this->length += DELTALENGTH; }
private:
	GVector middle_p;
	float length;
	float angle = PI / 4.0f;
};
