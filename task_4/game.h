#ifndef GAME_H
#define GAME_H

#include "level.h"

enum class GameStatus {
	START,
	GAME,
	PAUSE,
	END
};

class Game {
public:
	Game(void);
	void draw(void);
	void process(void);
	void death(void) { --lifes; }
private:
	GameStatus status;
	int lifes;
	int score;
	Level cur_level;
};

#endif
