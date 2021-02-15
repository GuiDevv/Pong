#pragma once
#include "CollisionSystem.h"

class Collision
{
public:

	virtual void onCollision();
};

class CollisionBall : public Collision
{
public:

	Ball *ball;
	int LimitUp, LimitDown;

	CollisionBall(Ball& b);
	void onCollision();

};

class CollisionPlayer : public Collision
{
public:

	Players* player;
	Ball* ball;

	CollisionPlayer(Players& p, Ball& b);
	void onCollision();
	void stabilizeBall();
};

class CollisionWall : public Collision
{
public:

	Wall* wall;
	Ball* ball;

	CollisionWall(Wall& w, Ball& b);
	void onCollision();
	
};

class CollisionSpectralWall : public Collision
{
public:

	Wall* wall;
	Ball* ball;
	Players* player;

	CollisionSpectralWall(Wall& w, Ball& b, Players& p);
	void onCollision();
};
