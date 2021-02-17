#include "Wall.h"

void Wall::setInfo(Sprite& spr, Vector p, IntRect w)
{
	sprite = &spr;
	sprite->setPosition(p.x, p.y);
	wall = w;
}

void Wall::beginCollision()
{
}

void Wall::endCollision()
{
}
