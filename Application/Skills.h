#pragma once
#ifndef _playerSkills
#define _playerSkills

#include "Gamemode.h"
#include "Timer.h"
#include <math.h>
// 
class Skills
{
public:
	class Gamemode* gm;
	class Players* controlledPlayer;
	Timer cooldown;
	bool usingPower, cooldownActive;
	int target;
	bool activeSkill = false;
	class Players* player;

	virtual void ActivePowerUp();
	virtual void RemovePowerUp();
	virtual void tickPower();
	bool getCooldown();

};

class Frozen : public Skills{
public:

	Timer  frozed;
	bool targetFrozed;

	Frozen(Players &p, Gamemode &gm);
	void ActivePowerUp();
	void RemovePowerUp();
	void tickPower();

};

class PerfectShoot : public Skills {
public:

	Timer tradeSprite;

	PerfectShoot(Players& p, Gamemode& gm);
	void ActivePowerUp();
	void RemovePowerUp();
	void tickPower();
	void RemoveSprite();

};

class Vortex : public Skills {
public:

	Timer spectralShield;	

	Vortex(Players& p, Gamemode& gm);
	void ActivePowerUp();
	void RemovePowerUp();
	void tickPower();

};

#endif // !_playerSkills