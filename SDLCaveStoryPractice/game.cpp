#include "SDL.h"
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

		//Limit fps to 50 frames
		const int CurrentTimeMS = SDL_GetTicks();
		int ElapseTime = CurrentTimeMS - LastUpdateTime;
		this->update(std::min(ElapseTime, MaxFrameTime));
		LastUpdateTime = CurrentTimeMS;
	}
}

void Game::draw(Graphics &graphics)
{

}

void Game::update(float elapsedTime)
{

}