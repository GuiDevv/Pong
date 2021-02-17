#include "CollisionSystem.h"

//void CollisionSystem::setAll()
//{	
//	LimitUp = 0;
//	LimitDown = 800;
//}
//
//void CollisionSystem::tickCollision()
//{
//	if (gm->player1->playerArea.intersects(gm->ball.ballArea))
//	{
//		gm->ball.dir.getVector() = gm->player1->dir.getVector() + gm->ball.dir.getVector();
//		stabilizeBall();
//		gm->ball.color = 2;
//		if (gm->player1->activeBoost)
//			gm->ball.ace = 1.0004;
//		else
//			gm->ball.ace = 1.0007;
//	}
//	if (gm->player2->playerArea.intersects(gm->ball.ballArea))
//	{
//		gm->ball.dir.getVector() = gm->player2->dir.getVector() + gm->ball.dir.getVector();
//		stabilizeBall();
//		gm->ball.color = 2;
//		if (gm->player2->activeBoost)
//			gm->ball.ace = 1.0004;
//		else
//			gm->ball.ace = 1.0007;
//	}
//	if (gm->wall1.wall.intersects(gm->ball.ballArea) || gm->wall2.wall.intersects(gm->ball.ballArea) || gm->wall3.wall.intersects(gm->ball.ballArea) || gm->wall4.wall.intersects(gm->ball.ballArea))
//	{
//		if (gm->ball.dir. x < 0)
//			gm->ball.pos.x = gm->ball.pos.x + 30;
//		if (gm->ball.dir.x > 0)
//			gm->ball.pos.x = gm->ball.pos.x - 30;
//			gm->ball.dir.x = gm->ball.dir.x * -1; // <---------------
//	}
//	/*if (spectralBone1->intersects(gm->ball.ballArea) && gm->player1->skills->skill3->usingPower)
//	{
//		if (gm->ball.dir.x < 0)
//			gm->ball.pos.x = gm->ball.pos.x + 30;
//		if (gm->ball.dir.x > 0)
//			gm->ball.pos.x = gm->ball.pos.x - 30;
//
//		gm->ball.dir.x = gm->ball.dir.x * -1;
//	}
//	if (spectralBone2->intersects(gm->ball.ballArea) && gm->player2->skills->skill3->usingPower)
//	{
//		if (gm->ball.dir.x < 0)
//			gm->ball.pos.x = gm->ball.pos.x + 30;
//		if (gm->ball.dir.x > 0)
//			gm->ball.pos.x = gm->ball.pos.x - 30;
//		gm->ball.dir.x = gm->ball.dir.x * -1;
//	}*/
//		
//
//	if (gm->ball.pos.getVector().y <= 0 || gm->ball.pos.getVector().y >= 750)
//		gm->ball.dir.getVector().y *= -1;
//}
//
//void CollisionSystem::stabilizeBall()
//{
//	if (gm->ball.dir.y > 1)
//		gm->ball.dir.y = 1;
//	if (gm->ball.dir.y < -1)
//		gm->ball.dir.y = -1;
//	if (gm->ball.dir.x > 1)
//		gm->ball.dir.x = 1;
//	if (gm->ball.dir.x < -1)
//		gm->ball.dir.x = -1;
//}

CollisionSystem& CollisionSystem::getIntance()
{
	static CollisionSystem colSyst;
	return colSyst;
}

void CollisionSystem::tick()
{
	/*for (size_t x = 0; x < colliders.size(); x++)
	{
		for (size_t y = x + 1; y < colliders.size(); y++)
		{
			Collision* a = colliders[x];
			Collision* b = colliders[y];

			if (a->collisions.count(b))
			{
				if (a->bounds.intersects(b->bounds))
				{
					a->collisions.insert(b);
					b->collisions.insert(a);
					a->beginCollision(b);
					b->beginCollision(a);
				}
			}
			else
			{
				if (!a->bounds.intersects(b->bounds))
				{
					a->collisions.erase(b);
					b->collisions.erase(a);
					a->endCollision(b);
					b->endCollision(a);
				}
			}
		}
	}*/
}

Collision::Collision()
{
	auto c = CollisionSystem::getIntance();
	c.colliders.push_back(this);
}

void Collision::beginCollision(Collision* other)
{
}

void Collision::endCollision(Collision* other)
{
}
