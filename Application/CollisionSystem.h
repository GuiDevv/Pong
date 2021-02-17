#pragma once
#ifndef _collisionSystem
#define _collisionSystem
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <Windows.h>

class Collision
{
public:

	sf::IntRect bounds;
	std::set<Collision*> collisions;
	Collision();
	virtual void beginCollision(Collision* other);
	virtual void endCollision(Collision* other);
};
class CollisionSystem{
public:

	std::vector<Collision*> colliders;

	static CollisionSystem& getIntance();
	void tick();

};
#endif // !_collisionSystem

