#pragma once
#ifndef _ball
#define _ball
#include "Vector.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "CollisionSystem.h"
#include <Windows.h>
class Ball : public Collision
{
public:
	Ball();

	Vector pos, dir, posIni;
	float speed;
	double ace = 1.0007;
	bool collision;
	int boost, color;
	sf::IntRect ballArea;

	void testCollision(Vector v);
	void tickBall();
	void setInfo(float xInicial, float yInicial);
	void BallReset();
	void RandomSpeeds(float velocityX, float velocityY);
	void beginCollision(Collision* other);
	void endCollision(Collision* other);
	void stabilize();

};
#endif // !_ball
