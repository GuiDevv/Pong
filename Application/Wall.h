#pragma once
#include "Vector.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class Wall
{
public:

	IntRect wall;
	Sprite* sprite;

	void setInfo(Sprite& spr, Vector p, IntRect w);
	void beginCollision();
	void endCollision();
};

