#ifndef GAME_H
#define GAME_H

#include "animationSprite.h"

class Graphics;

class Game
{
public:
	Game();
	~Game();
private:
	void gameLoop();
	void draw(Graphics &graphics);
	void update(float elapsedTime);

	AnimationSprite _player;
};

#endif
