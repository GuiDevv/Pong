#include "Collision.h"

void Collision::setAll()
{
	ball = &gm->ball;
	play1 = &gm->wall1;
	play2 = &gm->wall2;
	play1Area = &gm->wall1Area;
	play2Area = &gm->wall2Area;
	ballArea = &gm->ballArea;
	LimitUp = 0;
	LimitDown = 800;
}

void Collision::tickCollision()
{
	if (ball->pos.y > LimitUp || ball->pos.y < LimitDown)
	{
		ball->dir.getVector().y *= -1;
		ball->collision = true;
	}
	if (play1Area->intersects(*ballArea))
	{
		if (play1->dir.x != 0 || play1->dir.y != 0)
		{
			ball->testCollision(play1->dir * (play1->speed + 0.3));
			ball->collision = false;
		}
	}
	if (play2Area->intersects(*ballArea))
	{
		if (play2->dir.x != 0 || play2->dir.y != 0)
		{
			ball->testCollision(play2->dir * (play2->speed + 0.3));
			ball->collision = false;
		}
	}
}
