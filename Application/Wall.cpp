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
	enableTimer();
	if (x < xInicial + 50)
		x = xInicial + 50;
}

void Wall::enableTimer()
{
	timer = 500;
}

void Wall::disableTimer()
{
	BoostReset();
	timer = 0;
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
		speedInicial = 0.07;
		x = xInicial;
		y = yInicial;
		speed = speedInicial;
	}
}


