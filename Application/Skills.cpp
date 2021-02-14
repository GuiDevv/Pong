#include "Skills.h"

void Skills::ActivePowerUp()
{
}
void Skills::RemovePowerUp()
{
}
void Skills::tickPower()
{
}
bool Skills::getCooldown()
{
	return false;
}

void Frozen::ActivePowerUp()
{
	cooldown.start(30);	
	cooldownActive = true;
	activeSkill = true;
	player->playerInimigo->playerEnable = false;
	player->spriteAccess(1, 0, 0);
	frozed.start(5);
	targetFrozed = true;
}
void Frozen::RemovePowerUp()
{
	targetFrozed = false;
	player->playerInimigo->playerEnable = true;
	player->spriteAccess(1, 1, 0);
}
void Frozen::tickPower()
{
	if (cooldown.hasEnded() && cooldownActive == true)
	{
		cooldownActive = false;
		activeSkill = false;
		player->spriteAccess(1, -1, 1);
	}		
	if (frozed.hasEnded() && targetFrozed == true)
		RemovePowerUp();		
}
bool Frozen::getCooldown()
{
	return cooldownActive;
}

void PerfectShoot::ActivePowerUp()
{
	cooldown.start(10);
	cooldownActive = true;
	usingPower = true;
	activeSkill = true;
	tradeSprite.start(0.5);
	if (gm->ball.color == 2)
		gm->ball.dir = Vector(1, 0);
	if (gm->ball.color == 3)
		gm->ball.dir = Vector(-1, 0);
	player->spriteAccess(2, 0, 0);
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
		player->spriteAccess(2, -1, 1);
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
	player->spriteAccess(2, 1, 0);
}

void Vortex::ActivePowerUp()
{
	cooldown.start(30);
	cooldownActive = true;
	usingPower = true;
	activeSkill = true;
	player->spriteAccess(3, 0, 0);
	spectralShield.start(10);
}
void Vortex::RemovePowerUp()
{
	usingPower = false;
	player->spriteAccess(3, 1, 0);
}
void Vortex::tickPower()
{
	if (cooldown.hasEnded() && cooldownActive == true)
	{
		cooldownActive = false;
		activeSkill = false;
		player->spriteAccess(3, -1, 1);		
	}
	if (spectralShield.hasEnded() && usingPower == true)
		RemovePowerUp();
}
bool Vortex::getCooldown()
{
	return cooldownActive;
}