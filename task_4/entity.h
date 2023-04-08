#ifndef ENTITY_H
#define ENTITY_H

#include "vector.h"
#include "color.h"

enum class Direction {
	UP,
	DOWN,
	RIGHT,
	LEFT
};

class Entity {
public:
	virtual void draw(void) = 0;
	virtual void move(void) = 0;
	virtual void death(void) = 0;
	Vector getPos(void) { return pos; }
	Vector getSpeed(void) { return speed; }
	/*Color getColor(void) { return color; }*/
private:
	Vector pos;
	Vector speed;
	Color color;
};

#endif
