#pragma once
#include "Wall.h"

class PowerUp {
public:
	Wall* wall;

	virtual void ActivePowerUp(Wall& wall);
	virtual void RemovePowerUp();

};

class WallBoost : public PowerUp{
public:

	int speedBackup;

	void ActivePowerUp(Wall& wall);
	void RemovePowerUp();

};
//
//class PowerUp{
//public:
//
//	virtual void ActivePowerUp();
//	virtual void RemovePowerUp();
//};
//
//
//PowerUp *activePower = new WallBoost
//
//class WallBoost : public PowerUp
//{
//public:
//
//	void ActivePowerUp();
//
//};