#pragma once
#ifndef _playerSkills
#define _playerSkills

#include "Gamemode.h"
#include "Timer.h"
#include <math.h>

class PlayersSkills // Classe abstrata 
{
public:
	class Gamemode* gm;
	class Players* controlledPlayer;
	Timer cooldown;
	bool usingPower, cooldownActive;
	int target;
	bool activeSkill = false;

	void spritesSettings(int type, int skill, int option);
	virtual void ActivePowerUp(int who);
	virtual void RemovePowerUp();
	virtual void tickPower();
	virtual bool getCooldown();

};

class Frozen : public PlayersSkills{
public:

	Timer  frozed;
	bool targetFrozed;

	void ActivePowerUp(int who);
	void RemovePowerUp();
	void tickPower();
	bool getCooldown();

};

class PerfectShoot : public PlayersSkills {
public:

	Timer tradeSprite;
	bool usingPower, cooldownActive;

	void ActivePowerUp(int who);
	void RemovePowerUp();
	void tickPower();
	bool getCooldown();
	void RemoveSprite();

};

class Vortex : public PlayersSkills {
public:

	Timer spectralShield;	

	void ActivePowerUp(int who);
	void RemovePowerUp();
	void tickPower();
	bool getCooldown();

};

#endif // !_playerSkills