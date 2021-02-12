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
	inputs = { sf::Keyboard::Key::W, sf::Keyboard::Key::S, sf::Keyboard::Key::A, sf::Keyboard::Key::D, sf::Keyboard::Key::Space, sf::Keyboard::Key::Num1, sf::Keyboard::Key::Num2, sf::Keyboard::Key::Num3 };
	if (i == 1)
		inputs = { sf::Keyboard::Key::Up, sf::Keyboard::Key::Down, sf::Keyboard::Key::Left, sf::Keyboard::Key::Right, sf::Keyboard::Key::Numpad0, sf::Keyboard::Key::Numpad1, sf::Keyboard::Key::Numpad2, sf::Keyboard::Key::Numpad3 };

}

void ControllerPlayer::setInfo(Players& w)
{
	float t = gamemode->Random(10);
	controlledPlayer = &w;
	
	if (type == 0) // Não é mais necessário
		controlledPlayer->boostValue = 50;
	else
		controlledPlayer->boostValue = -50;
}

void ControllerPlayer::tickController()
{	
	if (Keyboard::isKeyPressed(inputs.up))
		input.y = 1;
	else if (Keyboard::isKeyPressed(inputs.down))
		input.y = -1;
	else
		input.y = 0;
	if (Keyboard::isKeyPressed(inputs.left))
		input.x = -1;
	else if (Keyboard::isKeyPressed(inputs.right))
		input.x = 1;
	else
		input.x = 0;
	controlledPlayer->handleInput(input);

	if (Keyboard::isKeyPressed(inputs.boost))
		controlledPlayer->Boost();

	if (Keyboard::isKeyPressed(inputs.skill1))
		controlledPlayer->UseSkill1(type);
	else if (Keyboard::isKeyPressed(inputs.skill2))
		controlledPlayer->UseSkill2(type);
	else if (Keyboard::isKeyPressed(inputs.skill3))
		controlledPlayer->UseSkill3(type);
}

void ControllerIa::setInfo(Players& w)
{
	controlledPlayer = &w;
	ball = &gamemode->ball;
	timer.start(10);
	block = true;
}

void ControllerIa::tickController()
{
	if (ball->pos.x < 670)
	{
		if (controlledPlayer->pos.x < 1000)
			controlledPlayer->Right();
	}
	if (ball->pos.x > 680)
	{
		if (ball->pos.x < controlledPlayer->pos.x)
			controlledPlayer->Left();
		if (ball->pos.x > controlledPlayer->pos.x)
			controlledPlayer->Right();
	}
	if (ball->pos.getVector().y < controlledPlayer->pos.y)
		controlledPlayer->Up();
	if (ball->pos.getVector().y > controlledPlayer->pos.y)
		controlledPlayer->Down();

	if (!block)
	{
		timer.start(15);
		block = true;

		if (!controlledPlayer->skills->skill1->activeSkill && random == 1)
			controlledPlayer->skills->skill1->ActivePowerUp(1);
		else if (!controlledPlayer->skills->skill2->activeSkill && random == 2)
			controlledPlayer->skills->skill2->ActivePowerUp(1);
		else if (!controlledPlayer->skills->skill3->activeSkill && random == 3)
			controlledPlayer->skills->skill3->ActivePowerUp(1);

	}
	if (block && timer.hasEnded())
		block = false;

}