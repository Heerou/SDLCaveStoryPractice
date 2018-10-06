#include "player.h"
#include "graphics.h"

namespace playerConstants
{
	const float walkSpeed = 0.2f;
}

Player::Player(){}

Player::Player(Graphics &graphics, float x, float y):
	AnimationSprite(graphics, "Content/Sprites/MyChar2.png", 0, 0, 16, 16, x, y, 100)
{
	graphics.loadImage("Content/Sprites/MyChar2.png");
	this->setupAnimation();
	this->playAnimation("RunRight");
}

void Player::setupAnimation()
{
	this->addAnimation(1, 0, 0, "IdleLeft", 16, 16, Vector2(0, 0));
	this->addAnimation(1, 0, 16, "IdleRight", 16, 16, Vector2(0, 0));
	this->addAnimation(3, 0, 0, "RunLeft", 16, 16, Vector2(0, 0));
	this->addAnimation(3, 0, 16, "RunRight", 16, 16, Vector2(0, 0));
}

void Player::animationDone(std::string currentAnimation){}

void Player::moveLeft()
{
	this->_dx = -playerConstants::walkSpeed;
	this->playAnimation("RunLeft");
	this->_facing = LEFT;
}
void Player::moveRight()
{
	this->_dx = playerConstants::walkSpeed;
	this->playAnimation("RunRight");
	this->_facing = RIGHT;
}

void Player::stopMoving()
{
	this->_dx = 0.0f;
	this->playAnimation(this->_facing == RIGHT ? "IdleRight" : "IdleLeft");
}

void Player::update(float elapsedTime)
{
	//Moving by _dx
	this->_x += this->_dx * elapsedTime;

	AnimationSprite::update(elapsedTime);
}

void Player::draw(Graphics &graphics)
{
	AnimationSprite::draw(graphics, this->_x, this->_y);
}