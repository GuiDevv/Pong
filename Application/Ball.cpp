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

	ballArea.left = pos.getVector().x;
	ballArea.top = pos.getVector().y;

}

void Ball::setInfo(float xInicial, float yInicial)
{
	posIni = { xInicial, yInicial };
	ballArea = IntRect(pos.getVector().x, pos.getVector().y, 30, 34);
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


//struct A {
//	int a;
//	float b;
//};
//
//A* find(vector<A*> vec, bool(*fnx)(A*)) {
//	for (auto& a : vec) {
//		if (fnx(a))
//			return a;
//	}
//}


//void Ball::beginCollision(Collision* other)
//{
//	if (dir.x < 0)
//		pos.x = pos.x + 30;
//	if (dir.x > 0)
//		pos.x = pos.x - 30;
//		dir.x = dir.x * -1; 
//	/*vector<A*> vec;
//	find(vec, [](A* w)->bool {
//		return w->a == 1;
//		}
//	);
//	find(vec, [](A* w)->bool {
//		return w->b == 1;
//		}
//	);
//
//	cast 
//	reinterpret_cast<>();
//	const_cast<>();
//	cast*/
//}
//
//void Ball::endCollision(Collision* other)
//{
//}
