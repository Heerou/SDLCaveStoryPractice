#ifndef GLOBALS_H
#define GLOBALS_H

namespace globals
{
	const int ScreenWidth = 640;
	const int ScreenHeight = 480;

	const float SpriteScale = 2.0f;
}

struct Vector2
{
	int x, y;
	Vector2() :
		x(0), y(0)
	{ }
	Vector2(int x, int y) :
		x(x), y(y)
	{ }
	Vector2 zero()
	{
		return Vector2(0, 0);
	}
};

#endif
