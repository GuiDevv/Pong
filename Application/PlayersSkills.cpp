#include "PlayersSkills.h"

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
	Sleep(500);
	target = who;
	cooldown.start(45);	
	cooldownActive = true;
	if (target == 0)
	{
		gm->controllers["Player2"]->enable = false;
		gm->sprites["spritePlayer2"] = gm->sprites["spritePlayer2Frozen"];
		frozed.start(15);
		targetFrozed = true;
	}
	if (target == 1)
	{
		gm->controllers["Player1"]->enable = false;
		gm->sprites["spritePlayer1"] = gm->sprites["spritePlayer1Frozen"];
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
		gm->sprites["spritePlayer2"] = gm->sprites["spriteSkull2"];
		gm->player2.activeSkill1 = false;
	}
		
	if (target == 1)
	{
		gm->controllers["Player1"]->enable = true;
		gm->sprites["spritePlayer1"] = gm->sprites["spriteSkull1"];
		gm->player1.activeSkill1 = false;
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
