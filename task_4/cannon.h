#ifndef CANNON_H
#define CANNON_H

#include "bullet.h"

class Cannon : public Entity {
public:
	Cannon(Vector& point, float speed, float width, float length);
	void shoot(void);
	void changeSpeed(Direction dir);
	float getWidth(void) { return width; }
	float getLength(void) { return length; }
private:
	float width;
	float length;
};

#endif
