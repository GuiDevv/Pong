#include "Controllers.h"

void Controllers::setInfo(Players& w)
{
}

void Controllers::tickController()
{
}

ControllerPlayer::ControllerPlayer(int i)
{
	type = i;
	if (i == 0)
	inputs = { sf::Keyboard::Key::W, sf::Keyboard::Key::S, sf::Keyboard::Key::A, sf::Keyboard::Key::D, sf::Keyboard::Key::Space };
	if (i == 1)
		inputs = { sf::Keyboard::Key::Up, sf::Keyboard::Key::Down, sf::Keyboard::Key::Left, sf::Keyboard::Key::Right, sf::Keyboard::Key::Left };

}

void ControllerPlayer::setInfo(Players& w)
{
	float t = gamemode->Random();
	controlledPlayer = &w;
	if (type == 0)
		controlledPlayer->boostValue = 50;
	else
		controlledPlayer->boostValue = -50;
}

void ControllerPlayer::tickController()
{
	if (Keyboard::isKeyPressed(inputs.up))
		controlledPlayer->Up();
	if (Keyboard::isKeyPressed(inputs.down))
		controlledPlayer->Down();
	if (Keyboard::isKeyPressed(inputs.left))
		controlledPlayer->Left();
	if (Keyboard::isKeyPressed(inputs.right))
		controlledPlayer->Right();
	if (Keyboard::isKeyPressed(inputs.boost) && controlledPlayer->activeBoost == false) // Devolve a bola na mesma posição de Y
	{
		controlledPlayer->Boost();
	}
	//if (Keyboard::isKeyPressed(Keyboard::Q))
	//{
	//	gamemode->tradePowerUp(0);
	//}
}

void ControllerIa::setInfo(Players& w)
{
	controlledPlayer = &w;
	ball = &gamemode->ball;
}

void ControllerIa::tickController()
{
	if (ball->pos.getVector().y < controlledPlayer->y)
		controlledPlayer->Up();
	if (ball->pos.getVector().y > controlledPlayer->y)
		controlledPlayer->Down();
}