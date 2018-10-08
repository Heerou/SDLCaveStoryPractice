#include <SDL.h>

#include "game.h"
#include "graphics.h"
#include "input.h"
#include <algorithm>﻿

namespace
{
	const int FPS = 50;
	const int MaxFrameTime = 5 * 1000 / FPS;
}

Game::Game()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	this->gameLoop();
}

Game::~Game()
{

}

void Game::gameLoop()
{
	Graphics graphics;
	Input input;
	SDL_Event event;

	this->_player = Player(graphics, 100, 100);
	this->_level = Level("Map 1", Vector2(100, 100), graphics);

	int  LastUpdateTime = SDL_GetTicks();
	while (true)
	{
		input.beginNewFrame();
		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_KEYDOWN)
			{
				if (event.key.repeat == 0)
				{
					input.keyDownEvent(event);
				}
			}
			else if (event.type == SDL_KEYUP)
			{
				input.keyUpEvent(event);
			}
			else if (event.type == SDL_QUIT)
			{
				return;
			}
		}
		if (input.wasKeyPressed(SDL_SCANCODE_ESCAPE) == true)
		{
			return;
		}
		else if (input.isKeyHeld(SDL_SCANCODE_LEFT) == true)
		{
			this->_player.moveLeft();
		}
		else if (input.isKeyHeld(SDL_SCANCODE_RIGHT) == true)
		{
			this->_player.moveRight();
		}

		if (!input.isKeyHeld(SDL_SCANCODE_LEFT) && !input.isKeyHeld(SDL_SCANCODE_RIGHT))
		{
			this->_player.stopMoving();
		}

		//Limit fps to 50 frames
		const int CurrentTimeMS = SDL_GetTicks();
		int ElapseTime = CurrentTimeMS - LastUpdateTime;
		this->update(std::min(ElapseTime, MaxFrameTime));
		LastUpdateTime = CurrentTimeMS;

		this->draw(graphics);
	}
}

void Game::draw(Graphics &graphics)
{
	graphics.clear();
	this->_level.draw(graphics);
	this->_player.draw(graphics);
	graphics.flip();
}

void Game::update(float elapsedTime)
{
	this->_player.update(elapsedTime);
	this->_level.update(elapsedTime);
}