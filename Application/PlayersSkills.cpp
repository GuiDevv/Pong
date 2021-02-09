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
	cooldown.start(45);	
	cooldownActive = true;
	if (target == 0)
	{
		gm->controllers["Player2"]->enable = false;
		spritesSettings(0, 1, 0);
		frozed.start(15);
		targetFrozed = true;
	}
	if (target == 1)
	{
		gm->controllers["Player1"]->enable = false;
		spritesSettings(1, 1, 0);
		frozed.start(15);
		targetFrozed = true;
	}
}
void Frozen::RemovePowerUp()
{
	targetFrozed = false;
	if (target == 0)
	{
		gm->controllers["Player2"]->enable = true;
		spritesSettings(0, 1, 1);
		gm->player2->activeSkill1 = false;
	}
		
	if (target == 1)
	{
		gm->controllers["Player1"]->enable = true;
		spritesSettings(1, 1, 1);
		gm->player1->activeSkill1 = false;
	}
}
void Frozen::tickPower()
{
	if (cooldown.hasEnded() && cooldownActive == true)
		cooldownActive = false;
	if (frozed.hasEnded() && targetFrozed == true)
		RemovePowerUp();		
}
bool Frozen::getCooldown()
{
	return cooldownActive;
}

void PerfectShoot::ActivePowerUp(int who)
{
	cooldown.start(15);
	cooldownActive = true;
	usingPower = true;
	target = who;

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
	if (target == 0)
		gm->player1->activeSkill2 = false;
	if (target == 1)
		gm->player2->activeSkill2 = false;
}
void PerfectShoot::tickPower()
{
	if (cooldown.hasEnded() && cooldownActive == true)
		RemovePowerUp();
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
	cooldown.start(45);
	cooldownActive = true;
	usingPower = true;
	target = who;

	if (target == 0)
	{
		spectralShield.start(10);
		gm->Player1Skill3 = true;
		spritesSettings(0, 3, 0);
	}
	if (target == 1)
	{
		spectralShield.start(10);
		gm->Player2Skill3 = true;
		spritesSettings(1, 3, 0);
	}
}
void Vortex::RemovePowerUp()
{
	usingPower = false;
	if (target == 0)
	{
		gm->Player1Skill3 = false;
		spritesSettings(0, 3, 1);
	}		
	if (target == 1)
	{
		gm->Player2Skill3 = false;
		spritesSettings(1, 3, 1);
	}	
}
void Vortex::tickPower()
{
	if (cooldown.hasEnded() && cooldownActive == true)
		cooldownActive = false;
	if (spectralShield.hasEnded() && usingPower == true)
		RemovePowerUp();
}
bool Vortex::getCooldown()
{
	return cooldownActive;
}