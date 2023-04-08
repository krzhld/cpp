#pragma once

class GVector {
public:
	GVector(void);
	GVector(float x, float y);
	float getX(void) { return this->x; }
	float getY(void) { return this->y; }
private:
	float x;
	float y;
};

GVector operator+ (GVector a, GVector b);
