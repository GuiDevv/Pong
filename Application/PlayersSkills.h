#pragma once
#ifndef _playerSkills
#define _playerSkills

#include "Gamemode.h"
#include "Timer.h"
#include <math.h>

class PlayersSkills//baseSkill, iSkill
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
//tem q subir
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



//public class BaseSkill {
//
//};
//public class Fogo :BaseSkill {
//
//};
//public class FogoMuitoDano :BaseSkill {
//
//};
//public class MuroFogo :BaseSkill {
//
//};
//public class Gelo :BaseSkill {
//
//};
//public class Raio :BaseSkill {
//
//};
//
//public class Player {
//	public List<BaseSkill> skills;
//	public Player() {
//		skills.add(new Fogo());
//		skills.add(new Gelo());
//		skills.add(new Raio());
//	}


#endif // !_playerSkills