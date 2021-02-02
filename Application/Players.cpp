#include "Players.h"

using namespace std;

void Players::Down()
{
	if (team == 0 && y > 400)
		y += speed;
	if (team == 1 && y > 400)
		y += speed;
}

void Players::Up()
{
	if (team == 0 && y > 400)
		y -= speed;
	if (team == 1 && y > 400)
		y -= speed;
}

void Players::Left()
{
	if (team == 0 && x < 700)
		x -= speed;
	if (team == 1 && x > 700)
		x -= speed;
}

void Players::Right()
{
	if (team == 0 && x < 700)
		x += speed;
	if (team == 1 && x > 700)
		x += speed;
}

void Players::Boost()
{	
	time.start(0.5);
	activeBoost = true;
	if (x < xInicial + boostValue)
		x = xInicial + boostValue;
	else if (x > xInicial + boostValue)
		x = xInicial + boostValue;
}

void Players::BoostReset()
{	
	x = xInicial;
}

void Players::setInfo(int tipo)
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

void Players::tickWall()
{
	if (time.hasEnded() && activeBoost == true)
	{
		BoostReset();
		activeBoost = false;
	}
}


