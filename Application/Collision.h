#pragma once
#ifndef _collision
#define _collision
#include "Gamemode.h"

using namespace sf;

class Collision
{
public:

	class Gamemode* gm;
	int LimitUp, LimitDown;
	Ball* ball;
	Players *play1, *play2;
	IntRect* play1Area, * play2Area, * ballArea;

	void setAll();
	void tickCollision();

};
#endif // !_collision

