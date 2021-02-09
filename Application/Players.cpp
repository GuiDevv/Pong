#include "Players.h"
#include <Windows.h>

using namespace std;

void Players::Down()
{
	if (team == 0 && pos.y < limitDown) // LimiteDownY (765)
	{
		pos.y += speed;
		dir.y = 1;
	}
		
	if (team == 1 && pos.y < limitDown)
	{
		pos.y += speed;
		dir.y = 1;
	}
}

void Players::Up()
{
	if (team == 0 && pos.y > limitUp) // LimiteUp (0)
	{
		pos.y -= speed;
		dir.y = -1;
	}
		
	if (team == 1 && pos.y > limitUp)
	{
		pos.y -= speed;
		dir.y = -1;
	}		
}

void Players::Left()
{
	if (team == 0 && pos.x > limitLeft)
	{
		pos.x -= speed;
		dir.x = -1;
	}
		
	if (team == 1 && pos.x > limitLeft)
	{
		pos.x -= speed;
		dir.x = -1;
	}		
}

void Players::Right()
{
	if (team == 0 && pos.x < limitRight) // LimiteRight(650)
	{
		pos.x += speed;
		dir.x = 1;
	}
		
	if (team == 1 && pos.x < limitRight)
	{
		pos.x += speed;
		dir.x = 1;
	}
		
}

void Players::Boost()
{	
	time.start(1);
	activeBoost = true;
	speed = speedInicial * 2;
	/*activeBoost = true;
	if (x < xInicial + boostValue)
		x = xInicial + boostValue;
	else if (x > xInicial + boostValue)
		x = xInicial + boostValue;*/
}
//
void Players::BoostReset()
{	
	speed = speedInicial;
}

void Players::UseSkill1(int type)
{
	activeSkill1 = true;
	skills["Skill1"]->ActivePowerUp(type);
}

void Players::UseSkill2(int type)
{
	activeSkill2 = true;
	skills["Skill2"]->ActivePowerUp(type);
}

void Players::UseSkill3(int type)
{
	activeSkill3 = true;
	skills["Skill3"]->ActivePowerUp(type);
}

void Players::setInfo(int tipo, int t)
{
	team = t;
	type = tipo;

	if (tipo == 0) //Player
	{
		posBackup.getVector().x = 350;
		posBackup.getVector().y = 350;
		speedInicial = 0.25;
		pos.x = posBackup.x;
		pos.y = posBackup.y;
		speed = speedInicial;
		limitUp = 0;
		limitDown = 700;
		limitLeft = 75;
		limitRight = 600;
		skills["Skill1"] = new Frozen();
		skills["Skill1"]->gm = gm;
		skills["Skill2"] = new PerfectShoot();
		skills["Skill2"]->gm = gm;
		skills["Skill3"] = new Vortex();
		skills["Skill3"]->gm = gm;
	}

	else if (tipo == 1 || t == 1) //IA
	{
		posBackup.getVector().x = 1050;
		posBackup.getVector().y = 350;
		speedInicial = 0.25;
		pos.x = posBackup.x;
		pos.y = posBackup.y;
		speed = speedInicial;
		limitUp = 0;
		limitDown = 700;
		limitLeft = 700;
		limitRight = 1225;
		skills["Skill1"] = new Frozen();
		skills["Skill1"]->gm = gm;
		skills["Skill2"] = new PerfectShoot();
		skills["Skill2"]->gm = gm;
		skills["Skill3"] = new Vortex();
		skills["Skill3"]->gm = gm;
	}
}

void Players::tickPlayer()
{
	for (auto p : skills) {
		p.second->tickPower();
	}

	if (time.hasEnded() && activeBoost == true)
	{
		BoostReset();
		activeBoost = false;
	}
	dir.x = 0;
	dir.y = 0;

	if (!skills["Skill1"]->getCooldown() && activeSkill1)
	{
		activeSkill1 = false;
		if (type == 0)
			gm->sprites["skill1Icon1"].setTexture(gm->textures["iconPlayer1Frozen"]);
		if (type == 1)
			gm->sprites["skill1Icon2"].setTexture(gm->textures["iconPlayer2Frozen"]);
	}		
	if (!skills["Skill2"]->getCooldown() && activeSkill2)
	{
		activeSkill2 = false;
		if (type == 0)
			gm->sprites["skill2Icon1"].setTexture(gm->textures["iconPlayer1PerfectShoot"]);
		if (type == 1)
			gm->sprites["skill2Icon2"].setTexture(gm->textures["iconPlayer2PerfectShoot"]);
	}		
	if (!skills["Skill3"]->getCooldown() && activeSkill3)
	{
		activeSkill3 = false;
		if (type == 0)
			gm->sprites["skill3Icon1"].setTexture(gm->textures["iconPlayer1Vortex"]);
		if (type == 1)
			gm->sprites["skill3Icon2"].setTexture(gm->textures["iconPlayer2Vortex"]);
	}
		
}


