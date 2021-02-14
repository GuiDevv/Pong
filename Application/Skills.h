#pragma once
#ifndef _playerSkills
#define _playerSkills

#include "Gamemode.h"
#include "Timer.h"
#include <math.h>

class Skills // Classe abstrata 
{
public:
	class Gamemode* gm;
	Timer cooldown;
	bool usingPower, cooldownActive;
	int target;
	bool activeSkill = false;
	class Players* player;

	virtual void ActivePowerUp();
	virtual void RemovePowerUp();
	virtual void tickPower();
	virtual bool getCooldown();

};

class Frozen : public Skills{
public:

	Timer  frozed;
	bool targetFrozed;

	void ActivePowerUp();
	void RemovePowerUp();
	void tickPower();
	bool getCooldown();

};

class PerfectShoot : public Skills {
public:

	Timer tradeSprite;

	void ActivePowerUp();
	void RemovePowerUp();
	void tickPower();
	bool getCooldown();
	void RemoveSprite();

};

class Vortex : public Skills {
public:

	Timer spectralShield;	

	void ActivePowerUp();
	void RemovePowerUp();
	void tickPower();
	bool getCooldown();

};

#endif // !_playerSkills