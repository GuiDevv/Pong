#include "Controllers.h"


void Controllers::setType(int t)
{
	type = t;
}

void Controllers::controllerPlayer()
{
	if (Keyboard::isKeyPressed(Keyboard::W))
		controlledWall->Up();
	if (Keyboard::isKeyPressed(Keyboard::S))
		controlledWall->Down();
	if (Keyboard::isKeyPressed(Keyboard::Space) && timer == 0) // Devolve a bola na mesma posição de Y
	{
		controlledWall->Boost();
		enableTimer();
	}

	if (Keyboard::isKeyPressed(Keyboard::Q)) // Teste PowerUp
	{
		
		gm->power->ActivePowerUp(*controlledWall);
	}
		
}

void Controllers::controllerIa()
{
	if (ball->pos.getVector().y < controlledWall->y)
		controlledWall->Up();
	if (ball->pos.getVector().y > controlledWall->y)
		controlledWall->Down();
}

void Controllers::setWall(Wall& wall)
{
	controlledWall = &wall;
}

void Controllers::enableControllers()
{
	if (type == 0)
		controllerPlayer();
	else if (type == 1)
		controllerIa();
}

void Controllers::enableTimer()
{
	timer = 500;
}

void Controllers::disableTimer()
{
	controlledWall->BoostReset();
	timer = 0;
}

void Controllers::setBall(Ball& b)
{
	ball = &b;
}
