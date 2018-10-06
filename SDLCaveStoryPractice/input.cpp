#include "input.h"

//At the begining of each frame, resets the keys
void Input::beginNewFrame()
{
	this->_pressedKeys.clear();
	this->_releasedKeys.clear();
}

//When key is pressed
void Input::keyDownEvent(const SDL_Event& event)
{
	this->_pressedKeys[event.key.keysym.scancode] = true;
	this->_releasedKeys[event.key.keysym.scancode] = true;
}

//When the key released
void Input::keyUpEvent(const SDL_Event& event)
{
	this->_releasedKeys[event.key.keysym.scancode] = true;
	this->_releasedKeys[event.key.keysym.scancode] = false;
}

//Checks if the keys was pressed in the current frame
bool Input::wasKeyPressed(SDL_Scancode key)
{
	return this->_pressedKeys[key];
}

bool Input::wasKeyReleased(SDL_Scancode key)
{
	return this->_releasedKeys[key];
}

bool Input::isKeyHeld(SDL_Scancode key)
{
	return this->_heldKeys[key];
}