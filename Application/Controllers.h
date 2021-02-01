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
	class Gamemode* gm;
	int type, timer = 0;
	Wall* controlledWall;
	Ball* ball;

	/*Controllers() {
		ball = &gm->ball;
	}
	void setup(Gamemode *gm) {

	}*/
	void setType(int t);
	void setWall(Wall& wall);
	void setBall(Ball& b);
	void controllerPlayer();
	void controllerIa();
	void enableControllers();
	void enableTimer();
	void disableTimer();
};

#endif // !_controller