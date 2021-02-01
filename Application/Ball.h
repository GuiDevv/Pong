#pragma once
#include "Vector.h"

class Ball
{
public:
	Ball();

	Vector pos, dir, posIni;
	double aceY, aceX;
	bool collision;
	int boost;

	void testCollision(int i);
	void Bounce();
	void setInfo(float xInicial, float yInicial);
	void BallReset();
	void RandomSpeeds(float velocityX, float velocityY);
    void Boost();

};

