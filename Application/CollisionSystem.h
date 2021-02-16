#pragma once
#ifndef _collisionSystem
#define _collisionSystem
#include "Gamemode.h"

using namespace sf;

class Players;

class CollisionSystem
{
public:

	class Gamemode* gm;
	int LimitUp, LimitDown;

	void setAll();
	void tickCollision();
	void stabilizeBall();

};
#endif // !_collisionSystem

