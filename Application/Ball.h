#pragma once
#include "Vector.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class Ball
{
public:
	Ball();

	Vector pos, dir, posIni;
	IntRect ballArea;
	float speed;
	double ace = 1.0007;
	bool collision;
	int boost, color;
	IntRect ballArea;


	void testCollision(Vector v);
	void tickBall();
	void setInfo(float xInicial, float yInicial);
	void BallReset();
	void RandomSpeeds(float velocityX, float velocityY);

};

