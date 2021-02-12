#include "Ball.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <vector>
#include "Players.h"
#include "Ball.h"
#include <math.h>

Ball::Ball()
{
	dir.getVector().y = dir.getVector().x = 0;
	pos.getVector().x = pos.getVector().y = 300;
	collision = false;
}

void Ball::testCollision(Vector v)
{
	dir = v;
}

void Ball::tickBall()
{
	pos = pos + dir;	

	if (dir.y < 0)
	{
		if (dir.y > -0.2)
			dir.y = -0.2;
		else
			dir.y = dir.y / ace;
	}
	if (dir.y > 0)
	{
		if (dir.y < 0.2)
			dir.y = 0.2;
		else
			dir.y = dir.y / ace;
	}
	if (dir.x < 0)
	{
		if (dir.x > -0.2)
			dir.x = -0.2;
		else
			dir.x = dir.x / ace;
	}
	if (dir.x > 0)
	{
		if (dir.x < 0.2)
			dir.x = 0.2;
		else
			dir.x = dir.x / ace;
	}

}

void Ball::setInfo(float xInicial, float yInicial)
{
	posIni = { xInicial, yInicial };
}

void Ball::BallReset()
{
	pos.getVector().x = posIni.getVector().x;
	pos.getVector().y = posIni.getVector().y;
	color = 1;
	dir.x = 0;
	dir.y = 0;
	collision = true;
}

void Ball::RandomSpeeds(float velocityX, float velocityY)
{
	dir.getVector().x = velocityX * 0.2;
	dir.getVector().y = velocityY * 0.2;

	if (dir.getVector().x < 0.05)
	{
		dir.getVector().x = 0.1;
	}
	if (dir.getVector().y < 0.05)
	{
		dir.getVector().y = 0.1;
	}
}

void Ball::Boost()
{
	/*if (boost == 0)
	{
		dir.getVector().y -= (aceY / 3);
		dir.getVector().x -= (aceX / 3);
		boost = 4;
	}
	if (boost == 1)
	{
		dir.getVector().y += (aceY / 3);
		dir.getVector().x += (aceX / 3);
		boost = 4;
	}
	if (boost == 2)
	{
		dir.getVector().y -= aceY;
		dir.getVector().y *= -1;
		dir.getVector().x -= aceX;
		boost = 4;
	}
	if (boost == 3)
	{
		dir.getVector().y += aceY;
		dir.getVector().y *= -1;
		dir.getVector().x += aceX;
		boost = 4;
	}*/
}
