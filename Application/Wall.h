#pragma once
#include "Timer.h"

using namespace sf;

class Wall
{
public:
	Wall();
	int timer;
	float x, y, speed, xInicial, yInicial, speedInicial;

	void Down();
	void Up();
	void Boost();
	void enableTimer();
	void disableTimer();
	void BoostReset();
	void setInfo(int tipo); // Tipo (0) - Player | Tipo (1) - IA
	// Colocar o tick da wall e arrumar o timer

};