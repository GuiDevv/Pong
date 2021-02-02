#pragma once
#ifndef _controller
#define _controller

#include "Wall.h"
#include "Ball.h"
#include "PowerUp.h"
#include "Gamemode.h"
#include <ctime>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class Controllers
{
public:
	class Gamemode* gamemode;
	int type;
	Wall* controlledWall;
	Ball* ball;

	virtual void setInfo();
	virtual void tickController();
};

class ControllerPlayer : public Controllers{
public:

	void setInfo();
	void tickController();
};

class ControllerIa : public Controllers
{
public:

	void setInfo();
	void tickController();
};
#endif // !_controller