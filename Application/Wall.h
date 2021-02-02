#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>

using namespace sf;

class Wall
{
public:
	Wall();
	/*Clock time;
	Time timer = time.restart();*/
	int timer;
	float x, y, speed, xInicial, yInicial, speedInicial;

	void Down();
	void Up();
	void Boost();
	void enableTimer();
	void disableTimer();
	void BoostReset();
	void setInfo(int tipo); // Tipo (0) - Player | Tipo (1) - IA

};