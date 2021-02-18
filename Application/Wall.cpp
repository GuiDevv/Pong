#include "Wall.h"

void Wall::setInfo(sf::Sprite& spr, Vector p, sf::IntRect w)
{
	sprite = &spr;
	sprite->setPosition(p.x, p.y);
	wall = w;
	bounds = wall;
}

void Wall::beginCollision(Collision* other)
{
}

void Wall::endCollision(Collision* other)
{
}

void SpectralWall::setInfo(sf::Sprite& spr, Vector p, sf::IntRect w)
{
	sprite = &spr;
	sprite->setPosition(p.x, p.y);
	wall = w;
	bounds = wall;
}

void SpectralWall::beginCollision(Collision* other)
{
}

void SpectralWall::endCollision(Collision* other)
{
}
