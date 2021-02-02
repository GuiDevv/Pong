#include "Wall.h"

using namespace std;

Wall::Wall()
{
}

void Wall::Down()
{
	if (y < 430)
	y += speed;
}

void Wall::Up()
{
	if (y > 0)
	y -= speed;
}

void Wall::Boost()
{	
	time.start(0.5);
	activeBoost = true;
	if (x < xInicial + boostValue)
		x = xInicial + boostValue;
	else if (x > xInicial + boostValue)
		x = xInicial + boostValue;
}

void Wall::BoostReset()
{	
	x = xInicial;
}

void Wall::setInfo(int tipo)
{
	if (tipo == 0) //Player
	{
		xInicial = 0;
		yInicial = 200;
		speedInicial = 0.1;
		x = xInicial;
		y = yInicial;
		speed = speedInicial;
	}

	else if (tipo == 1) //IA
	{
		xInicial = 745;
		yInicial = 200;
		speedInicial = 0.1/*0.07*/;
		x = xInicial;
		y = yInicial;
		speed = speedInicial;
	}
}

void Wall::tickWall()
{
	if (time.hasEnded() && activeBoost == true)
	{
		BoostReset();
		activeBoost = false;
	}
}


