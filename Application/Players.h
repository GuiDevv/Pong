#pragma once
#pragma once
#ifndef _player
#define _player
#include "Timer.h"
#include "Vector.h"
#include "SkillSystem.h"

using namespace sf;

class Players
{
public:
	
	class Gamemode* gm;
	Timer time;
	int team = 0, type;
	bool activeBoost, playerEnable = true;
	Vector pos, posBackup, dir;
	float speed, speedInicial, boostValue, limitDown, limitUp, limitLeft, limitRight;
	class SkillSystem *skills;	

	void Down();
	void Up();
	void Left();
	void Right();
	void Boost();
	void BoostReset();
	void UseSkill1(int type);
	void UseSkill2(int type);
	void UseSkill3(int type);
	void setInfo(int tipo, int t, Gamemode& g); // Tipo (0) - Player | Tipo (1) - IA
	void tickPlayer();
	void handleInput(Vector v);


};

#endif // !_player