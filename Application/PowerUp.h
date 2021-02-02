#pragma once
#include "Wall.h"
#include "Timer.h"

class PowerUp {
public:
	Wall* wall;

	virtual void ActivePowerUp(Wall& w);
	virtual void RemovePowerUp();
	virtual void tickPower();

};

class WallBoost : public PowerUp{
public:

	int speedBackup;
	Timer time;
	bool activePow;

	void ActivePowerUp(Wall& w);
	void RemovePowerUp();
	void tickPower();

};