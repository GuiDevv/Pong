#include "CollisionSystem.h"

CollisionSystem& CollisionSystem::getIntance()
{
	static CollisionSystem colSyst;
	return colSyst;
}

void CollisionSystem::tick()
{
	for (size_t x = 0; x < colliders.size(); x++)
	{
		for (size_t y = x + 1; y < colliders.size(); y++)
		{
			Collision* a = colliders[x];
			Collision* b = colliders[y];

			if (a->collisions.count(b) == 0)
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
	}
}

Collision::Collision()
{
	auto& c = CollisionSystem::getIntance();
	c.colliders.push_back(this);
}

void Collision::beginCollision(Collision* other)
{
}

void Collision::endCollision(Collision* other)
{
}
