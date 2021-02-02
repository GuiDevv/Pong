#include "Controllers.h"

void Controllers::setInfo()
{
}

void Controllers::tickController()
{
}

void ControllerPlayer::setInfo()
{
	float t = gamemode->Random();
	controlledWall = &gamemode->wallPlayer;
}

void ControllerPlayer::tickController()
{
	if (Keyboard::isKeyPressed(Keyboard::W))
		controlledWall->Up();
	if (Keyboard::isKeyPressed(Keyboard::S))
		controlledWall->Down();
	if (Keyboard::isKeyPressed(Keyboard::Space) && controlledWall->timer == 0) // Devolve a bola na mesma posição de Y
	{
		controlledWall->Boost();
	}
	if (Keyboard::isKeyPressed(Keyboard::Q))
	{
		gamemode->tradePowerUp(0);
	}
}

void ControllerIa::setInfo()
{
	controlledWall = &gamemode->wallIa;
	ball = &gamemode->ball;
}

void ControllerIa::tickController()
{
	if (ball->pos.getVector().y < controlledWall->y)
		controlledWall->Up();
	if (ball->pos.getVector().y > controlledWall->y)
		controlledWall->Down();
}


