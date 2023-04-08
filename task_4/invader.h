#ifndef INVADER_H
#define INVADER_H

#include "bullet.h"

class Invader : public Entity {
public:
	Invader(Vector& pos, Vector& speed, Color color);
	void shoot(void);
	void changeSpeed(Direction dir);
	float getWidth(void) { return width; }
	float getLength(void) { return length; }
private:
	float width;
	float length;
};

#endif
