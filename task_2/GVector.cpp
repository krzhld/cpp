#include "GVector.h"

GVector::GVector(void) {
	this->x = 0.0f;
	this->y = 0.0f;
}

GVector::GVector(float x, float y) {
	this->x = x;
	this->y = y;
}

GVector operator+ (GVector a, GVector b) {
	return GVector(a.getX() + b.getX(), a.getY() + b.getY());
}
