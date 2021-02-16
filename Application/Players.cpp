#include "Players.h"
#include <Windows.h>

using namespace std;

void Players::Down()
{
	if (pos.y < limitDown && playerEnable)
	{
		pos.y += speed;
		dir.y = 1;
	}
}
void Players::Up()
{
	if (pos.y > limitUp && playerEnable)
	{
		pos.y -= speed;
		dir.y = -1;
	}		
}
void Players::Left()
{
	if (pos.x > limitLeft && playerEnable)
	{
		pos.x -= speed;
		dir.x = -1;
	}
}
void Players::Right()
{
	if (pos.x < limitRight && playerEnable)
	{
		pos.x += speed;
		dir.x = 1;
	}		
}
void Players::Boost()
{	
	time.start(0.5);
	activeBoost = true;
	speed = speedInicial * 2;
}
void Players::BoostReset()
{	
	speed = speedInicial;
}
void Players::UseSkill1()
{
	if (playerEnable && !skills->skill1->activeSkill)
		skills->skill1->ActivePowerUp();
}
void Players::UseSkill2()
{	
	if (playerEnable && !skills->skill2->activeSkill)
		skills->skill2->ActivePowerUp();
}
void Players::UseSkill3()
{	
	if (playerEnable && !skills->skill3->activeSkill)
		skills->skill3->ActivePowerUp();
}
void Players::setInfo(Gamemode& g)
{
}
void Players::spriteAccess(int skill, int typeAccess, int icon)
{
}
void Players::tickPlayer()
{			
	if (time.hasEnded() && activeBoost == true)
	{
		BoostReset();
		activeBoost = false;
	}
	skills->tickSkills();
	dir.x = 0;
	dir.y = 0;
	playerArea.left = pos.x;
	playerArea.top = pos.y;
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

void PlayerBlue::setInfo(Gamemode& g)
{
	gm = &g;
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
	skills->controlledPlayer = this;
	skills->setSkillsGamemode();
	playerArea = IntRect(pos.x, pos.y, 100, 104);
}
void PlayerBlue::spriteAccess(int skill, int typeAccess, int icon)
{
	if (skill == 1)
	{
		if (typeAccess == 0) // Trocar para a nova
			gm->sprites["spritePlayer2"] = gm->sprites["spritePlayer2Frozen"];
		if (typeAccess == 1) // Voltar para a original
			gm->sprites["spritePlayer2"] = gm->sprites["spriteSkull2"];
		if (icon == 0) // Muda o Icon da skill para disable
			gm->sprites["skill1Icon1"].setTexture(gm->textures["iconDisableFrozen"]);
		if (icon == 1) // Muda o Icon da skill para enable
			gm->sprites["skill1Icon1"].setTexture(gm->textures["iconPlayer1Frozen"]);
	}
	if (skill == 2)
	{
		if (typeAccess == 0) // Trocar para a nova
			gm->sprites["spritePlayer1"] = gm->sprites["spritePlayer1PerfectShoot"];
		if (typeAccess == 1) // Voltar para a original
			gm->sprites["spritePlayer1"] = gm->sprites["spriteSkull1"];
		if (icon == 0) // Muda o Icon da skill para disable
			gm->sprites["skill2Icon1"].setTexture(gm->textures["iconDisablePerfectShoot"]);
		if (icon == 1) // Muda o Icon da skill para enable
			gm->sprites["skill2Icon1"].setTexture(gm->textures["iconPlayer1PerfectShoot"]);
	}
	if (skill == 3)
	{
		if (typeAccess == 0) // Trocar para a nova
			gm->sprites["spritePlayer1"] = gm->sprites["spritePlayer1Vortex"];
		if (typeAccess == 1) // Voltar para a original
			gm->sprites["spritePlayer1"] = gm->sprites["spriteSkull1"];
		if (icon == 0) // Muda o Icon da skill para disable
			gm->sprites["skill3Icon1"].setTexture(gm->textures["iconDisableVortex"]);
		if (icon == 1) // Muda o Icon da skill para enable
			gm->sprites["skill3Icon1"].setTexture(gm->textures["iconPlayer1Vortex"]);			
	}		
}

void PlayerRed::setInfo(Gamemode& g)
{
	gm = &g;
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
	skills->controlledPlayer = this;
	skills->setSkillsGamemode();
	playerArea = IntRect(pos.x, pos.y, 100, 104);

}
void PlayerRed::spriteAccess(int skill, int typeAccess, int icon)
{
	if (skill == 1)
	{
		if (typeAccess == 0) // Trocar para a nova
			gm->sprites["spritePlayer1"] = gm->sprites["spritePlayer1Frozen"];
		if (typeAccess == 1) // Voltar para a original
			gm->sprites["spritePlayer1"] = gm->sprites["spriteSkull1"];
		if (icon == 0) // Muda o Icon da skill para disable
			gm->sprites["skill1Icon2"].setTexture(gm->textures["iconDisableFrozen"]);
		if (icon == 1) // Muda o Icon da skill para enable
			gm->sprites["skill1Icon2"].setTexture(gm->textures["iconPlayer2Frozen"]);
	}
	if (skill == 2)
	{
		if (typeAccess == 0) // Trocar para a nova
			gm->sprites["spritePlayer2"] = gm->sprites["spritePlayer2PerfectShoot"];
		if (typeAccess == 1) // Voltar para a original
			gm->sprites["spritePlayer2"] = gm->sprites["spriteSkull2"];
		if (icon == 0) // Muda o Icon da skill para disable
			gm->sprites["skill2Icon2"].setTexture(gm->textures["iconDisablePerfectShoot"]);
		if (icon == 1) // Muda o Icon da skill para enable
			gm->sprites["skill2Icon2"].setTexture(gm->textures["iconPlayer2PerfectShoot"]);
	}
	if (skill == 3)
	{
		if (typeAccess == 0) // Trocar para a nova
			gm->sprites["spritePlayer2"] = gm->sprites["spritePlayer2Vortex"];
		if (typeAccess == 1) // Voltar para a original
			gm->sprites["spritePlayer2"] = gm->sprites["spriteSkull2"];
		if (icon == 0) // Muda o Icon da skill para disable
			gm->sprites["skill3Icon2"].setTexture(gm->textures["iconDisableVortex"]);
		if (icon == 1) // Muda o Icon da skill para enable
			gm->sprites["skill3Icon2"].setTexture(gm->textures["iconPlayer2Vortex"]);
	}	
	
}
