#pragma once
#pragma once
#ifndef _player
#define _player
#include "Timer.h"
#include "Vector.h"
#include "PlayersSkills.h"

using namespace sf;

class Players
{
public:

	class Gamemode* gm;
	Timer time;
	int team = 0, type;
	bool activeBoost, activeSkill1 = false, activeSkill2 = false, activeSkill3 = false;
	Vector pos, posBackup, dir;
	float speed, speedInicial, boostValue, limitDown, limitUp, limitLeft, limitRight;
	map<string, class PlayersSkills*> skills;

	void Down();
	void Up();
	void Left();
	void Right();
	void Boost();
	void BoostReset();
	void UseSkill1(int type);
	void UseSkill2(int type);
	void UseSkill3(int type);
	void setInfo(int tipo, int t); // Tipo (0) - Player | Tipo (1) - IA
	void tickPlayer();


};

#endif // !_player