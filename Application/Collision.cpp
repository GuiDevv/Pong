#include "Collision.h"

void Collision::onCollision()
{
}

CollisionBall::CollisionBall(Ball& b)
{
	ball = &b;
	LimitUp = 0;
	LimitDown = 800;
}

void CollisionBall::onCollision()
{
	if (ball->pos.getVector().y <= 0 || ball->pos.getVector().y >= 750)
		ball->dir.getVector().y *= -1;
}

CollisionPlayer::CollisionPlayer(Players& p, Ball& b)
{
	player = &p;
	ball = &b;
}

void CollisionPlayer::onCollision()
{
	if (player->playerArea.intersects(ball->ballArea))
	{		
		ball->dir.getVector() = player->dir.getVector() + ball->dir.getVector();
		stabilizeBall();
		ball->color = player->color;
		if (player->activeBoost)
			ball->ace = 1.0004;
		else
			ball->ace = 1.0007;
	}
}

void CollisionPlayer::stabilizeBall()
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

CollisionWall::CollisionWall(Wall& w, Ball& b)
{
	wall = &w;
	ball = &b;
}

void CollisionWall::onCollision()
{
	if (wall->wallArea->intersects(ball->ballArea))
	{
		if (ball->dir.x < 0)
			ball->pos.x = ball->pos.x + 30;
		if (ball->dir.x > 0)
			ball->pos.x = ball->pos.x - 30;
		ball->dir.x = ball->dir.x * -1; // <---------------
	}
}

CollisionSpectralWall::CollisionSpectralWall(Wall& w, Ball& b, Players& p)
{
	wall = &w;
	ball = &b;
	player = &p;
}

void CollisionSpectralWall::onCollision()
{
	if (wall->wallArea->intersects(ball->ballArea) && player->skills->skill3->usingPower)
	{
		if (ball->dir.x < 0)
			ball->pos.x = ball->pos.x + 30;
		if (ball->dir.x > 0)
			ball->pos.x = ball->pos.x - 30;
		ball->dir.x = ball->dir.x * -1;
	}
}
