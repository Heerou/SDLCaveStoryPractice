#include <SDL.h>
#include <SDL_image.h>
#include "graphics.h"
#include "globals.h"

Graphics::Graphics()
{
	SDL_CreateWindowAndRenderer(globals::ScreenWidth, globals::ScreenHeight, 0, &this->_window, &this->_renderer);
	SDL_SetWindowTitle(this->_window, "CaveStory");
}

Graphics::~Graphics()
{
	SDL_DestroyWindow(this->_window);
}

SDL_Surface* Graphics::loadImage(const std::string &filepath)
{
	if (this->_spritesSheets.count(filepath) == 0)
	{
		this->_spritesSheets[filepath] = IMG_Load(filepath.c_str());
	}
	return this->_spritesSheets[filepath];
}

void Graphics::blitSurface(SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destRectangle)
{
	SDL_RenderCopy(this->_renderer, texture, sourceRectangle, destRectangle);
}

void Graphics::flip()
{
	SDL_RenderPresent(this->_renderer);
}

void Graphics::clear()
{
	SDL_RenderClear(this->_renderer);
}

SDL_Renderer* Graphics::getRenderer() const
{
	return this->_renderer;
}