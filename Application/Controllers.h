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

	virtual void setInfo(Wall& w);
	virtual void tickController();
};

struct DataHolder {
	sf::Keyboard::Key up, down, boost;
};

class ControllerPlayer : public Controllers{
public:

	ControllerPlayer(int i);

	DataHolder inputs;

	void setInfo(Wall& w);
	void tickController();
};

class ControllerIa : public Controllers
{
public:

	void setInfo(Wall& w);
	void tickController();
};


#endif // !_controller