#include "Ball.h"
#include "Players.h"

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

	ballArea.left = pos.getVector().x;
	ballArea.top = pos.getVector().y;
	if (pos.y < 0 || pos.y > 800)
		dir.y *= -1;
	bounds = ballArea;

}

void Ball::setInfo(float xInicial, float yInicial)
{
	posIni = { xInicial, yInicial };
	ballArea = sf::IntRect(pos.getVector().x, pos.getVector().y, 30, 34);	
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

void Ball::beginCollision(Collision* other) // Arrumar o disable do spectral
{
	Players* p = dynamic_cast<Players*>(other);
	Wall* w = dynamic_cast<Wall*>(other);
	SpectralWall* sw = dynamic_cast<SpectralWall*>(other);

	if (p) 
	{
		if (p->dir.y != 0 || p->dir.x != 0)
		{
			dir.getVector() = dir.getVector() + p->dir.getVector();
			stabilize();
			if (p->activeBoost)
				ace = 1.0004;
			else
				ace = 1.0007;
		}
	}
	if (w)
	{
		if (dir.x < 0)
			pos.x = pos.x + 20;
		if (dir.x > 0)
			pos.x = pos.x - 20;
		dir.x = dir.x * -1;
	}
	if (sw && sw->isEnable)
	{
		if (dir.x < 0)
			pos.x = pos.x + 20;
		if (dir.x > 0)
			pos.x = pos.x - 20;
		dir.x = dir.x * -1;
	}

}

void Ball::endCollision(Collision* other)
{
}

void Ball::stabilize()
{
	if (dir.y > 1)
		dir.y = 1;
	if (dir.y < -1)
		dir.y = -1;
	if (dir.x > 1)
		dir.x = 1;
	if (dir.x < -1)
		dir.x = -1;
}
