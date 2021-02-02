#include "Controllers.h"

void Controllers::setInfo(Wall& w)
{
}

void Controllers::tickController()
{
}

ControllerPlayer::ControllerPlayer(int i)
{
	type = i;
	if (i == 0)
	inputs = { sf::Keyboard::Key::W, sf::Keyboard::Key::S, sf::Keyboard::Key::Space };
	if (i == 1)
		inputs = { sf::Keyboard::Key::Up, sf::Keyboard::Key::Down, sf::Keyboard::Key::Left };

}

void ControllerPlayer::setInfo(Wall& w)
{
	float t = gamemode->Random();
	controlledWall = &w;
	if (type == 0)
		controlledWall->boostValue = 50;
	else
		controlledWall->boostValue = -50;
}

void ControllerPlayer::tickController()
{
	if (Keyboard::isKeyPressed(inputs.up))
		controlledWall->Up();
	if (Keyboard::isKeyPressed(inputs.down))
		controlledWall->Down();
	if (Keyboard::isKeyPressed(inputs.boost) && controlledWall->activeBoost == false) // Devolve a bola na mesma posição de Y
	{
		controlledWall->Boost();
	}
	//if (Keyboard::isKeyPressed(Keyboard::Q))
	//{
	//	gamemode->tradePowerUp(0);
	//}
}

void ControllerIa::setInfo(Wall& w)
{
	controlledWall = &w;
	ball = &gamemode->ball;
}

void ControllerIa::tickController()
{
	if (ball->pos.getVector().y < controlledWall->y)
		controlledWall->Up();
	if (ball->pos.getVector().y > controlledWall->y)
		controlledWall->Down();
}