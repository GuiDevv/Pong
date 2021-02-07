#pragma once
#ifndef _playerSkills
#define _playerSkills

#include "Gamemode.h"
#include "Timer.h"

class PlayersSkills
{
public:
	class Gamemode* gm;

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

//class PerfectShoot : public PlayersSkills {
//public:
//
//	Ball* ball;
//	Vector* pos;
//	Timer time;
//	bool activePow;
//
//	void ActivePowerUp(Gamemode& g);
//	void RemovePowerUp();
//	void tickPower();
//
//};
//
//class Vortex : public PlayersSkills {
//public:
//
//	Ball* ball;
//	float speedBackup;
//	Timer time;
//	bool activePow;
//
//	void ActivePowerUp(Gamemode& g);
//	void RemovePowerUp();
//	void tickPower();
//
//};

#endif // !_playerSkills