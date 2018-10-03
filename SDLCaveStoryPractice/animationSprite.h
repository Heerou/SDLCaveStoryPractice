#ifndef ANIMATION_SPRITE_H
#define ANIMATION_SPRITE_H

#include <map>
#include <string>
#include <vector>
#include "sprite.h"
#include "globals.h"

class Graphics;

class AnimationSprite : public Sprite
{
public:
	AnimationSprite();
	AnimationSprite(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY, 
		int width, int height, float posX, float posY, float timeToUpdate);

	//Plays the animation if it not being played
	void playAnimation(std::string animation, bool once = false);

	void update(int elapseTime);

	//Draws the sprite in the screen
	void draw(Graphics &graphics, int x, int y);

	//Setups all the animations for a sprite
	virtual void setupAnimation();

protected:
	double _timeToUpdate;
	bool _currentAnimationOnce;
	std::string _currentAnimation;

	//Adds an animation to the map of animations fot the sprite
	void addAnimation(int frames, int x, int y, std::string name, int width, int height, Vector2 offset);
	void resetAniamtion();
	void stopAnimation();
	void setVisible(bool visible);

	virtual void animationDone(std::string currentAnimation);

private:
	std::map<std::string, std::vector<SDL_Rect>> _animations;
	std::map<std::string, Vector2> _offsets;

	int _frameIndex;
	double _timeElapsed = 0;
	bool _visible;
};

#endif // !ANIMATION_SPRITE_H

