#pragma once
#include "Timer.h"
#include "Vector.h"

using namespace sf;

class Players
{
public:

	Timer time;
	int team = 0;
	bool activeBoost, activeSkill1 = false, activeSkill2 = false, activeSkill3 = false;
	Vector pos, posBackup, dir;
	float speed, speedInicial, boostValue, limitDown, limitUp, limitLeft, limitRight;

	void Down();
	void Up();
	void Left();
	void Right();
	void Boost();
	void BoostReset();
	void UseSkill1();
	void UseSkill2();
	void UseSkill3();
	void setInfo(int tipo, int t); // Tipo (0) - Player | Tipo (1) - IA
	void tickWall();


};