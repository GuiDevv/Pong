#pragma once
#pragma once
#ifndef _player
#define _player
#include "Timer.h"
#include "Vector.h"
#include "SkillSystem.h"
#include "Collision.h"

using namespace sf;

class Players
{
public:
	
	class Gamemode* gm;
	Timer time;
	bool activeBoost, playerEnable = true;
	Vector pos, posBackup, dir;
	float speed, speedInicial, boostValue, limitDown, limitUp, limitLeft, limitRight, color;
	class SkillSystem *skills;	
	class Collision* collision;
	class Players* playerInimigo;
	IntRect playerArea;

	void Down();
	void Up();
	void Left();
	void Right();
	void Boost();
	void BoostReset();
	void tickPlayer();
	void handleInput(Vector v);
	void UseSkill1();
	void UseSkill2();
	void UseSkill3();
	virtual void setInfo(Gamemode& g);
	virtual void spriteAccess(int skill, int typeAccess, int icon);
};

class PlayerBlue : public Players
{
public:

	void setInfo(Gamemode& g);
	void spriteAccess(int skill, int typeAccess, int icon);
};

class PlayerRed : public Players
{
public:

	void setInfo(Gamemode& g);
	void spriteAccess(int skill, int typeAccess, int icon);
};

#endif // !_player