#include "Controllers.h"

void Controllers::setInfo()
{
}

void Controllers::tickController()
{
}
//void Controllers::setType(int t)
//{
//	type = t;
//}
//
//void Controllers::controllerPlayer()
//{
//	if (Keyboard::isKeyPressed(Keyboard::W))		
//		controlledWall->Up();
//	if (Keyboard::isKeyPressed(Keyboard::S))
//		controlledWall->Down();
//	if (Keyboard::isKeyPressed(Keyboard::Space) && controlledWall->timer == 0) // Devolve a bola na mesma posição de Y
//	{
//		controlledWall->Boost();
//	}
//	//if (Keyboard::isKeyPressed(Keyboard::Q)) // Teste PowerUp
//	//{		
//	//	gamemode->powerActivePowerUp(*controlledWall);
//	//}
//		
//}
//
//void Controllers::controllerIa()
//{
//	if (ball->pos.getVector().y < controlledWall->y)
//		controlledWall->Up();
//	if (ball->pos.getVector().y > controlledWall->y)
//		controlledWall->Down();
//}
//
//void Controllers::enableControllers()
//{
//}
//
//void Controllers::setWall(Wall& wall)
//{
//	controlledWall = &wall;
//}
//
//void Controllers::tickControllers()
//{
//	if (type == 0)
//		controllerPlayer();
//	else if (type == 1)
//		controllerIa();
//}
//
//void Controllers::setBall(Ball& b)
//{
//	ball = &b;
//}

void ControllerPlayer::setInfo()
{
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


