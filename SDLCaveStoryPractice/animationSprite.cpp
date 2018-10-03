#include "animationSprite.h"
#include "graphics.h"
#include "sprite.h"

AnimationSprite::AnimationSprite(){}

AnimationSprite::AnimationSprite(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY,
	int width, int height, float posX, float posY, float timeToUpdate) :
	Sprite(graphics, filePath, sourceX, sourceY, width, height, posX, posY),
	_frameIndex(0),
	_timeToUpdate(timeToUpdate),
	_visible(true),
	_currentAnimationOnce(false),
	_currentAnimation("")
{ }

//Run the sprite sheet and cuts the animation i want to get
void AnimationSprite::addAnimation(int frames, int x, int y, std::string name, int width, int height, Vector2 offset)
{
	std::vector<SDL_Rect> rectangles;
	for (int i = 0; i < frames; i++)
	{
		SDL_Rect newRect = { (i + x) * width, y, width, height };
		rectangles.push_back(newRect);
	}
	this->_animations.insert(std::pair<std::string, std::vector<SDL_Rect>>(name, rectangles));
	this->_offsets.insert(std::pair<std::string, Vector2>(name, offset));
}

void AnimationSprite::resetAniamtion()
{
	this->_animations.clear();
	this->_offsets.clear();
}

void AnimationSprite::playAnimation(std::string animation, bool once)
{
	this->_currentAnimationOnce = once;
	if (this->_currentAnimation != animation)
	{
		this->_currentAnimation = animation;
		this->_frameIndex = 0;
	}
}

void AnimationSprite::setVisible(bool visible)
{
	this->_visible = visible;
}

void AnimationSprite::stopAnimation()
{
	this->_frameIndex = 0;
	this->animationDone(this->_currentAnimation);
}

void AnimationSprite::update(int elapseTime)
{
	Sprite::update();

	this->_timeElapsed += elapseTime;
	if (this->_timeElapsed > this->_timeToUpdate)
	{
		this->_timeElapsed -= this->_timeToUpdate;
		if (this->_frameIndex < this->_animations[this->_currentAnimation].size() - 1)
		{
			this->_frameIndex++;
		}
		else
		{
			if (this->_currentAnimationOnce == true)
			{
				this->setVisible(false);
			}
			this->_frameIndex = 0;
			this->animationDone(this->_currentAnimation);
		}
	}
}

void AnimationSprite::draw(Graphics &graphics, int x, int y)
{
	if (this->_visible)
	{
		SDL_Rect destination;
		destination.x = x + this->_offsets[this->_currentAnimation].x;
		destination.y = y + this->_offsets[this->_currentAnimation].y;
		destination.w = this->_sourceRect.w * globals::SpriteScale;
		destination.h = this->_sourceRect.h * globals::SpriteScale;

		SDL_Rect sourceRect = this->_animations[this->_currentAnimation][this->_frameIndex];
		graphics.blitSurface(this->_spriteSheet, &sourceRect, &destination);
	}
}

void AnimationSprite::animationDone(std::string currentAnimation)
{

}

void AnimationSprite::setupAnimation()
{
	this->addAnimation(3, 0, 0, "RunLeft", 16, 16, Vector2(0, 0));
	this->addAnimation(3, 0, 16, "RunRight", 16, 16, Vector2(0, 0));
}