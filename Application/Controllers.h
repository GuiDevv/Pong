#pragma once
#ifndef _controller
#define _controller

#include "Players.h"
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
	Players* controlledPlayer;
	Ball* ball;

	virtual void setInfo(Players& w);
	virtual void tickController();
};

struct DataHolder {
	sf::Keyboard::Key up, down, left, right, boost;
};

class ControllerPlayer : public Controllers{
public:

	ControllerPlayer(int i);

	DataHolder inputs;

	void setInfo(Players& w);
	void tickController();
};

class ControllerIa : public Controllers
{
public:

	void setInfo(Players& w);
	void tickController();
};


#endif // !_controller