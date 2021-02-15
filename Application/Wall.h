#pragma once
#include "Gamemode.h"

class Wall
{
public:

	IntRect* wallArea;
	class CollisionSystem* collision;
	Ball* ball;

	void setInfo(IntRect newArea, Ball& b);
};

class SpectralWall : public Wall
{
public:


};
