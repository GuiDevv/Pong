#include "Players.h"
#include <Windows.h>

using namespace std;

void Players::Down()
{
	if (team == 0 && pos.y < limitDown && playerEnable) // LimiteDownY (765)
	{
		pos.y += speed;
		dir.y = 1;
	}
		
	if (team == 1 && pos.y < limitDown && playerEnable)
	{
		pos.y += speed;
		dir.y = 1;
	}
}

void Players::Up()
{
	if (team == 0 && pos.y > limitUp && playerEnable) // LimiteUp (0)
	{
		pos.y -= speed;
		dir.y = -1;
	}
		
	if (team == 1 && pos.y > limitUp && playerEnable)
	{
		pos.y -= speed;
		dir.y = -1;
	}		
}

void Players::Left()
{
	if (team == 0 && pos.x > limitLeft && playerEnable)
	{
		pos.x -= speed;
		dir.x = -1;
	}
		
	if (team == 1 && pos.x > limitLeft && playerEnable)
	{
		pos.x -= speed;
		dir.x = -1;
	}		
}

void Players::Right()
{
	if (team == 0 && pos.x < limitRight && playerEnable) // LimiteRight(650)
	{
		pos.x += speed;
		dir.x = 1;
	}
		
	if (team == 1 && pos.x < limitRight && playerEnable)
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

void Players::BoostReset()
{	
	speed = speedInicial;
}

void Players::UseSkill1(int type)
{
	if (playerEnable && !activeSkill1)
	{
		activeSkill1 = true;
		skills->skill1->ActivePowerUp(type);
		if (type == 0)
		gm->sprites["skill1Icon1"].setTexture(gm->textures["iconDisableFrozen"]);
		if (type == 1)
			gm->sprites["skill1Icon2"].setTexture(gm->textures["iconDisableFrozen"]);
	}
}

void Players::UseSkill2(int type)
{
	if (playerEnable && !activeSkill2)
	{
		activeSkill2 = true;
		skills->skill2->ActivePowerUp(type);
		if (type == 0)
			gm->sprites["skill2Icon1"].setTexture(gm->textures["iconDisablePerfectShoot"]);
		if (type == 1)
			gm->sprites["skill2Icon2"].setTexture(gm->textures["iconDisablePerfectShoot"]);
	}
}

void Players::UseSkill3(int type)
{
	if (playerEnable && !activeSkill3)
	{
		activeSkill3 = true;
		skills->skill3->ActivePowerUp(type);
		if (type == 0)
			gm->sprites["skill3Icon1"].setTexture(gm->textures["iconDisableVortex"]);
		if (type == 1)
			gm->sprites["skill3Icon2"].setTexture(gm->textures["iconDisableVortex"]);
	}
}

void Players::setInfo(int tipo, int t, Gamemode& g)
{
	team = t;
	type = tipo;
	gm = &g;

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
		skills = new SkillSystem();
		skills->gamemode = gm;
		skills->setSkillsGamemode();
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
		skills = new SkillSystem();
		skills->gamemode = gm;
		skills->setSkillsGamemode();
	}
}

void Players::tickPlayer()
{
	skills->tickSkills();

	if (time.hasEnded() && activeBoost == true)
	{
		BoostReset();
		activeBoost = false;
	}
	dir.x = 0;
	dir.y = 0;

	if (!skills->skill1->getCooldown() && activeSkill1)
	{
		activeSkill1 = false;
		if (type == 0)
			gm->sprites["skill1Icon1"].setTexture(gm->textures["iconPlayer1Frozen"]);
		if (type == 1)
			gm->sprites["skill1Icon2"].setTexture(gm->textures["iconPlayer2Frozen"]);
	}		
	if (!skills->skill2->getCooldown() && activeSkill2)
	{
		activeSkill2 = false;
		if (type == 0)
			gm->sprites["skill2Icon1"].setTexture(gm->textures["iconPlayer1PerfectShoot"]);
		if (type == 1)
			gm->sprites["skill2Icon2"].setTexture(gm->textures["iconPlayer2PerfectShoot"]);
	}		
	if (!skills->skill3->getCooldown() && activeSkill3)
	{
		activeSkill3 = false;
		if (type == 0)
			gm->sprites["skill3Icon1"].setTexture(gm->textures["iconPlayer1Vortex"]);
		if (type == 1)
			gm->sprites["skill3Icon2"].setTexture(gm->textures["iconPlayer2Vortex"]);
	}
		
}

void Players::handleInput(Vector v)
{
	if (v.x != 0)
	{
		if (v.x > 0)
			Right();
		else
			Left();
		}
	if (v.y != 0)
	{
		if (v.y > 0)
			Up();
		else
			Down();
	}
}


