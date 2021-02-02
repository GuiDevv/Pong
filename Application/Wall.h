#pragma once
#include "Timer.h"

using namespace sf;

class Wall
{
public:
	Wall();
	Timer time;
	bool activeBoost;
	float x, y, speed, xInicial, yInicial, speedInicial, boostValue;

	void Down();
	void Up();
	void Boost();
	void BoostReset();
	void setInfo(int tipo); // Tipo (0) - Player | Tipo (1) - IA
	void tickWall();
	// Colocar o tick da wall e arrumar o timer

};