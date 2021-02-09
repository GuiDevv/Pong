#pragma once
#ifndef _playerSkills
#define _playerSkills

#include "Gamemode.h"
#include "Timer.h"
#include <math.h>

class PlayersSkills
{
public:
	class Gamemode* gm;

	void spritesSettings(int type, int skill, int option);
	virtual void ActivePowerUp(int who);
	virtual void RemovePowerUp();
	virtual void tickPower();
	virtual bool getCooldown();

};

class Frozen : public PlayersSkills{
public:

	Timer cooldown, frozed;
	bool targetFrozed, cooldownActive;
	int target;

	void ActivePowerUp(int who);
	void RemovePowerUp();
	void tickPower();
	bool getCooldown();

};

class PerfectShoot : public PlayersSkills {
public:

	Timer cooldown, tradeSprite;
	bool usingPower, cooldownActive;
	int target;

	void ActivePowerUp(int who);
	void RemovePowerUp();
	void tickPower();
	bool getCooldown();
	void RemoveSprite();

};

class Vortex : public PlayersSkills {
public:

	Timer cooldown, spectralShield;
	bool usingPower, cooldownActive;
	int target;

	void ActivePowerUp(int who);
	void RemovePowerUp();
	void tickPower();
	bool getCooldown();

};

#endif // !_playerSkills