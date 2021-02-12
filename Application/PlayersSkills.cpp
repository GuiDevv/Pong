#include "PlayersSkills.h"

void PlayersSkills::spritesSettings(int type, int skill, int option)
{
	if (type == 0)
	{
		if (option == 0) // Colocar Sprite
		{
			if (skill == 1)
				gm->sprites["spritePlayer2"] = gm->sprites["spritePlayer2Frozen"];
			if (skill == 2)
				gm->sprites["spritePlayer1"] = gm->sprites["spritePlayer1PerfectShoot"];
			if (skill == 3)
				gm->sprites["spritePlayer1"] = gm->sprites["spritePlayer1Vortex"];
		}
		if (option == 1) // Remover Sprite
		{
			if (skill == 1)
				gm->sprites["spritePlayer2"] = gm->sprites["spriteSkull2"];
			if (skill == 2)
				gm->sprites["spritePlayer1"] = gm->sprites["spriteSkull1"];
			if (skill == 3)
				gm->sprites["spritePlayer1"] = gm->sprites["spriteSkull1"];
		}
	}
	if (type == 1)
	{
		if (option == 0) // Colocar Sprite
		{
			if (skill == 1)
				gm->sprites["spritePlayer1"] = gm->sprites["spritePlayer1Frozen"];
			if (skill == 2)
				gm->sprites["spritePlayer2"] = gm->sprites["spritePlayer2PerfectShoot"];
			if (skill == 3)
				gm->sprites["spritePlayer2"] = gm->sprites["spritePlayer2Vortex"];
		}
		if (option == 1) // Remover Sprite
		{
			if (skill == 1)
				gm->sprites["spritePlayer1"] = gm->sprites["spriteSkull1"];
			if (skill == 2)
				gm->sprites["spritePlayer2"] = gm->sprites["spriteSkull2"];
			if (skill == 3)
				gm->sprites["spritePlayer2"] = gm->sprites["spriteSkull2"];
		}
	}
}

void PlayersSkills::ActivePowerUp(int who)
{
}
void PlayersSkills::RemovePowerUp()
{
}
void PlayersSkills::tickPower()
{
}
bool PlayersSkills::getCooldown()
{
	return false;
}

void Frozen::ActivePowerUp(int who)
{
	target = who;
	cooldown.start(30);	
	cooldownActive = true;
	activeSkill = true;
	if (target == 0)
	{
		gm->player2->playerEnable = false;
		spritesSettings(0, 1, 0);
		frozed.start(5);
		targetFrozed = true;
	}
	if (target == 1)
	{
		gm->player1->playerEnable = false;
		spritesSettings(1, 1, 0);
		frozed.start(5);
		targetFrozed = true;
	}
}
void Frozen::RemovePowerUp()
{
	targetFrozed = false;
	if (target == 0)
	{
		gm->player2->playerEnable = true;
		spritesSettings(0, 1, 1);
	}
		
	if (target == 1)
	{
		gm->player1->playerEnable = true;
		spritesSettings(1, 1, 1);
	}
}
void Frozen::tickPower()
{
	if (cooldown.hasEnded() && cooldownActive == true)
	{
		cooldownActive = false;
		activeSkill = false;
		if (target == 0)
			gm->sprites["skill1Icon1"].setTexture(gm->textures["iconPlayer1Frozen"]);
		if (target == 1)
			gm->sprites["skill1Icon2"].setTexture(gm->textures["iconPlayer2Frozen"]);
	}		
	if (frozed.hasEnded() && targetFrozed == true)
		RemovePowerUp();		
}
bool Frozen::getCooldown()
{
	return cooldownActive;
}

void PerfectShoot::ActivePowerUp(int who)
{
	cooldown.start(10);
	cooldownActive = true;
	usingPower = true;
	target = who;
	activeSkill = true;

	if (target == 0)
	{
		tradeSprite.start(0.5);
		if (gm->ball.color == 2)
		gm->ball.dir = Vector(1, 0);
		if (gm->ball.color == 3)
			gm->ball.dir = Vector(-1, 0);
		spritesSettings(0, 2, 0);
	}
	if (target == 1)
	{
		tradeSprite.start(0.5);
		if (gm->ball.color == 3)
			gm->ball.dir = Vector(-1, 0);
		if (gm->ball.color == 2)
			gm->ball.dir = Vector(1, 0);
		spritesSettings(1, 2, 0);
	}
}
void PerfectShoot::RemovePowerUp()
{
	cooldownActive = false;
	activeSkill = false;
}
void PerfectShoot::tickPower()
{
	if (cooldown.hasEnded() && cooldownActive == true)
	{
		RemovePowerUp();
		if (target == 0)
			gm->sprites["skill2Icon1"].setTexture(gm->textures["iconPlayer1PerfectShoot"]);
		if (target == 1)
			gm->sprites["skill2Icon2"].setTexture(gm->textures["iconPlayer2PerfectShoot"]);
	}
		
	if (tradeSprite.hasEnded() && usingPower == true)
		RemoveSprite();
}
bool PerfectShoot::getCooldown()
{
	return cooldownActive;
}
void PerfectShoot::RemoveSprite()
{
	usingPower = false;
	if (target == 0)
		spritesSettings(0, 2, 1);
	if (target == 1)
		spritesSettings(1, 2, 1);
}

void Vortex::ActivePowerUp(int who)
{
	cooldown.start(30);
	cooldownActive = true;
	usingPower = true;
	target = who;
	activeSkill = true;

	if (target == 0)
	{
		spectralShield.start(10);
		spritesSettings(0, 3, 0);
	}
	if (target == 1)
	{
		spectralShield.start(10);
		spritesSettings(1, 3, 0);
	}
}
void Vortex::RemovePowerUp()
{
	usingPower = false;
	if (target == 0)
		spritesSettings(0, 3, 1);
	if (target == 1)
		spritesSettings(1, 3, 1);
}
void Vortex::tickPower()
{
	if (cooldown.hasEnded() && cooldownActive == true)
	{
		cooldownActive = false;
		activeSkill = false;
		if (target == 0)
			gm->sprites["skill3Icon1"].setTexture(gm->textures["iconPlayer1Vortex"]);
		if (target == 1)
			gm->sprites["skill3Icon2"].setTexture(gm->textures["iconPlayer2Vortex"]);		
		
	}
	if (spectralShield.hasEnded() && usingPower == true)
		RemovePowerUp();
}
bool Vortex::getCooldown()
{
	return cooldownActive;
}