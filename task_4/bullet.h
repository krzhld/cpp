#ifndef BULLET_H
#define BULLET_H

#include "entity.h"

class Bullet : public Entity {
public:
	Bullet(Vector& point, Vector& speed, float radius);
	void process(void);
	float getRadius(void) { return radius; }
private:
	float radius;
};

#endif
