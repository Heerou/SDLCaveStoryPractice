#include "sprite.h"
#include "graphics.h"
#include "globals.h"

Sprite::Sprite(){}

Sprite::Sprite(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY, int width, int heigth, float posX, float posY) : _x(posX), _y(posY)
{
	this->_sourceRect.x = sourceX;
	this->_sourceRect.y = sourceY;
	this->_sourceRect.w = width;
	this->_sourceRect.h = heigth;

	this->_spriteSheet = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage(filePath));
	if (this->_spriteSheet == NULL)
	{
		printf("\nError: Unable to load image\n");
	}
}

Sprite::~Sprite(){}

void Sprite::draw(Graphics &graphics, int x, int y)
{
	SDL_Rect destRectangle = { x, y, this->_sourceRect.w * globals::SpriteScale, this->_sourceRect.h * globals::SpriteScale };
	graphics.blitSurface(this->_spriteSheet, &this->_sourceRect, &destRectangle);
}

void Sprite::update(){}