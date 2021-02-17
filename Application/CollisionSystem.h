#pragma once
#ifndef _collisionSystem
#define _collisionSystem
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;
using namespace sf;
class Collision
{
public:

	FloatRect bounds;
	set<Collision*> collisions;
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

