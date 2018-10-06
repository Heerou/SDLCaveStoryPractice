#ifndef PLAYER_H
#define PLAYER_H

#include "animationSprite.h"
#include "globals.h"

class Graphics;

class Player : public AnimationSprite
{
public:
	Player();
	Player(Graphics &graphics, float x, float y);
	void draw(Graphics &graphics);
	void update(float elapsedTime);

	void moveLeft();
	void moveRight();
	void stopMoving();

	virtual void animationDone(std::string currentAnimation);
	virtual void setupAnimation();
private:
	float _dx, _dy;

	Direction _facing;
};

#endif

