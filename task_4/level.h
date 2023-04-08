#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include <vector>
#include "invader.h"
#include "cannon.h"

class Level {
public:
	Level(int number_level);
	void process(void);
	void draw(void);
	/*std::vector<Invader> getInvaders(void);
	Cannon getCannon(void);
	int getNumberLevel(void) { return number_level; }*/
private:
	std::vector<Invader> invaders;
	std::vector<Bullet> bullets;
	Cannon cannon;
	int number_level;
};

#endif
