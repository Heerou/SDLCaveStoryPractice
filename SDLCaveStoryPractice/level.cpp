#include "level.h"
#include "graphics.h"

#include "SDL.h"

Level::Level(){}

Level::Level(std::string mapName, Vector2 spawnPoint, Graphics &graphics) :
	_mapName(mapName), _spawnPoint(spawnPoint), _size(Vector2(0,0))
{
	this->loadMap(mapName, graphics);
}

Level::~Level()
{
}

void Level::loadMap(std::string _mapName, Graphics &graphics)
{
	this->_backgroundTexture = SDL_CreateTextureFromSurface(graphics.getRenderer(), 
		graphics.loadImage("Content/Background/bkBlue.png"));
	this->_size = Vector2(1280, 960);
}

void Level::update(int elapsedTime)
{

}

void Level::draw(Graphics &graphics)
{
	SDL_Rect source = {0, 0, 64, 64};
	SDL_Rect destination;

	for (int x = 0; x < this->_size.x / 64; x++)
	{
		for (int y = 0; y < this->_size.x / 64; y++)
		{
			destination.x = x * 64;
			destination.y = y * 64;
			destination.w = 64;
			destination.h = 64;
			graphics.blitSurface(this->_backgroundTexture, &source, &destination);
		}
	}
}