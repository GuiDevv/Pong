#pragma once
#include "Players.h"
#include "Timer.h"

class PowerUp {
public:
	Players* wall;

	virtual void ActivePowerUp(Players& w);
	virtual void RemovePowerUp();
	virtual void tickPower();

};

class WallBoost : public PowerUp{
public:

	float speedBackup;
	Timer time;
	bool activePow;

	void ActivePowerUp(Players& w);
	void RemovePowerUp();
	void tickPower();

};