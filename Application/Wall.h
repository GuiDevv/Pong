#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Wall
{
public:
	Wall();
	
	int timer = 0;
	float x, y, speed, xInicial, yInicial, speedInicial;

	void Down();
	void Up();
	void Boost();
	void enableTimer();
	void disableTimer();
	void BoostReset();
	void setInfo(int tipo); // Tipo (0) - Player | Tipo (1) - IA

};