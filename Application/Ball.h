#pragma once
#include "Vector.h"

class Ball
{
public:
	Ball();

	Vector pos, dir, posIni;
	float speed;
	double ace = 1.0007;
	bool collision;
	int boost;

	void testCollision(Vector v);
	void tickBall();
	void setInfo(float xInicial, float yInicial);
	void BallReset();
	void RandomSpeeds(float velocityX, float velocityY);
    void Boost();

};

