#include "Wall.h"

void Wall::setInfo(IntRect newArea, Ball& b)
{
	wallArea = &newArea;
	ball = &b;
	collision = new CollisionWall();
}
