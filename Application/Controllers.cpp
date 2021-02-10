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
	float t = gamemode->Random();
	controlledPlayer = &w;
	
	if (type == 0)
		controlledPlayer->boostValue = 50;
	else
		controlledPlayer->boostValue = -50;
}

void ControllerPlayer::tickController()
{
	/*
	Vector input;
	if (Keyboard::isKeyPressed(inputs.up))
		input.y = 1;
	else if (Keyboard::isKeyPressed(inputs.down))
		input.y = -1;
	if (Keyboard::isKeyPressed(inputs.left))
		input.x = -1;
	else if (Keyboard::isKeyPressed(inputs.right))
		input.x = 1;
	controlledPlayer->handleInput(input);


	if (Keyboard::isKeyPressed(inputs.ability1))
		controlledPlayer->skillSystem->useAbility(1);
	else if (Keyboard::isKeyPressed(inputs.ability2))
		controlledPlayer->skillSystem->useAbility(1);
	*/

	if (enable)
	{
		if (Keyboard::isKeyPressed(inputs.up))
			controlledPlayer->Up();
		if (Keyboard::isKeyPressed(inputs.down))
			controlledPlayer->Down();
		if (Keyboard::isKeyPressed(inputs.left))
			controlledPlayer->Left();
		if (Keyboard::isKeyPressed(inputs.right))
			controlledPlayer->Right();
		if (Keyboard::isKeyPressed(inputs.boost) && controlledPlayer->activeBoost == false)
		{
			controlledPlayer->Boost();
		}
		if (Keyboard::isKeyPressed(inputs.skill1) && controlledPlayer->activeSkill1 == false)
		{						
			if (type == 0)
			{
				controlledPlayer->UseSkill1(0);
				gamemode->sprites["skill1Icon1"].setTexture(gamemode->textures["iconDisableFrozen"]);
			}				
			if (type == 1)
			{
				controlledPlayer->UseSkill1(1);
				gamemode->sprites["skill1Icon2"].setTexture(gamemode->textures["iconDisableFrozen"]);
			}				
		}
		if (Keyboard::isKeyPressed(inputs.skill2) && controlledPlayer->activeSkill2 == false && gamemode->ball.color != 1)
		{
			if (type == 0)
			{
				controlledPlayer->UseSkill2(0);
				gamemode->sprites["skill2Icon1"].setTexture(gamemode->textures["iconDisablePerfectShoot"]);
			}				
			if (type == 1)
			{
				controlledPlayer->UseSkill2(1);
				gamemode->sprites["skill2Icon2"].setTexture(gamemode->textures["iconDisablePerfectShoot"]);
			}				
		}
		if (Keyboard::isKeyPressed(inputs.skill3) && controlledPlayer->activeSkill3 == false)
		{
			if (type == 0)
			{
				controlledPlayer->UseSkill3(0);
				gamemode->sprites["skill3Icon1"].setTexture(gamemode->textures["iconDisableVortex"]);
			}				
			if (type == 1)
			{
				controlledPlayer->UseSkill3(1);
				gamemode->sprites["skill3Icon2"].setTexture(gamemode->textures["iconDisableVortex"]);
			}				
		}

	}
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

	if (enable)
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
	}
	if (!block)
	{
		timer.start(15);
		block = true;
		
		if (!controlledPlayer->activeSkill1)
			controlledPlayer->skill1->ActivePowerUp(1);
		else if (!controlledPlayer->activeSkill2)
			controlledPlayer->skill2->ActivePowerUp(1);
		else if (!controlledPlayer->activeSkill3)
			controlledPlayer->skill3->ActivePowerUp(1);

	}
	if (block && timer.hasEnded())
		block = false;
	
}