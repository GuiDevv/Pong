#pragma once
#include "Vector.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "CollisionSystem.h"

class Wall : public Collision
{
public:

	sf::IntRect wall;
	sf::Sprite* sprite;

	void setInfo(sf::Sprite& spr, Vector p, sf::IntRect w);
	void beginCollision();
	void endCollision();
};

