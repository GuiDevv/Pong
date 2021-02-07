#include "CollisionSystem.h"

void CollisionSystem::setAll()
{
	ball = &gm->ball;
	play1 = &gm->player1;
	play2 = &gm->player2;
	play1Area = &gm->player1Area;
	play2Area = &gm->player2Area;
	wall1Area = &gm->wall1Area;
	wall2Area = &gm->wall2Area;
	wall3Area = &gm->wall3Area;
	wall4Area = &gm->wall4Area;
	spectralBone1 = &gm->SpectralBone1;
	spectralBone2 = &gm->SpectralBone2;
	ballArea = &gm->ballArea;
	LimitUp = 0;
	LimitDown = 800;
}

void CollisionSystem::tickCollision()
{
	if (play1Area->intersects(*ballArea))
	{
		ball->dir.getVector() = play1->dir.getVector() + ball->dir.getVector();
		stabilizeBall();
		ball->color = 2;
		if (play1->activeBoost)
			ball->ace = 1.0004;
		else
			ball->ace = 1.0007;
	}
	if (play2Area->intersects(*ballArea))
	{
		ball->dir.getVector() = play2->dir.getVector() + ball->dir.getVector();
		stabilizeBall();
		ball->color = 3;
		if (play2->activeBoost)
			ball->ace = 1.0004;
		else
			ball->ace = 1.0007;
	}
	if (wall1Area->intersects(*ballArea) || wall2Area->intersects(*ballArea) || wall3Area->intersects(*ballArea) || wall4Area->intersects(*ballArea))
	{
		if (ball->dir. x < 0)
		ball->pos.x = ball->pos.x + 30;
		if (ball->dir.x > 0)
			ball->pos.x = ball->pos.x - 30;
		ball->dir.x = ball->dir.x * -1; // <---------------
	}
	if (spectralBone1->intersects(*ballArea) && gm->Player1Skill3)
	{
		if (ball->dir.x < 0)
			ball->pos.x = ball->pos.x + 30;
		if (ball->dir.x > 0)
			ball->pos.x = ball->pos.x - 30;
		ball->dir.x = ball->dir.x * -1;
	}
	if (spectralBone2->intersects(*ballArea) && gm->Player2Skill3)
	{
		if (ball->dir.x < 0)
			ball->pos.x = ball->pos.x + 30;
		if (ball->dir.x > 0)
			ball->pos.x = ball->pos.x - 30;
		ball->dir.x = ball->dir.x * -1;
	}
		

	if (ball->pos.getVector().y <= 0 || ball->pos.getVector().y >= 750)
		ball->dir.getVector().y *= -1;
}

void CollisionSystem::stabilizeBall()
{
	if (ball->dir.y > 1)
		ball->dir.y = 1;
	if (ball->dir.y < -1)
		ball->dir.y = -1;
	if (ball->dir.x > 1)
		ball->dir.x = 1;
	if (ball->dir.x < -1)
		ball->dir.x = -1;
}
