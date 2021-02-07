#pragma once
#ifndef _collisionSystem
#define _collisionSystem
#include "Gamemode.h"

using namespace sf;

class CollisionSystem
{
public:

	class Gamemode* gm;
	int LimitUp, LimitDown;
	Ball* ball;
	Players *play1, *play2;
	IntRect* play1Area, * play2Area, * ballArea, * wall1Area, * wall2Area, * wall3Area, * wall4Area;

	void setAll();
	void tickCollision();
	void stabilizeBall();

};
#endif // !_collisionSystem

