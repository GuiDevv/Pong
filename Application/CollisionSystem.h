#pragma once
#ifndef _collisionSystem
#define _collisionSystem
#include "Gamemode.h"
#include "Collision.h"

class CollisionSystem
{
public:

	vector <Collision> collisions;

	void pushVector(Collision &c);
	void tickCollision();

};
#endif // !_collisionSystem

