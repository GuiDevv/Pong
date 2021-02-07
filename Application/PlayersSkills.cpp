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
		gm->sprites["spritePlayer1"] = gm->sprites["spritePlayer1PerfectShoot"];
	}
	if (target == 1)
	{
		tradeSprite.start(0.5);
		if (gm->ball.color == 3)
			gm->ball.dir = Vector(-1, 0);
		if (gm->ball.color == 2)
			gm->ball.dir = Vector(1, 0);
		gm->sprites["spritePlayer2"] = gm->sprites["spritePlayer2PerfectShoot"];
	}
}

void PerfectShoot::RemovePowerUp()
{
	cooldownActive = false;
	if (target == 0)
		gm->player1.activeSkill2 = false;
	if (target == 1)
		gm->player2.activeSkill2 = false;
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
		gm->sprites["spritePlayer1"] = gm->sprites["spriteSkull1"];
	if (target == 1)
		gm->sprites["spritePlayer2"] = gm->sprites["spriteSkull2"];
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
		gm->sprites["spritePlayer1"] = gm->sprites["spritePlayer1Vortex"];
	}
	if (target == 1)
	{
		spectralShield.start(10);
		gm->Player2Skill3 = true;
		gm->sprites["spritePlayer2"] = gm->sprites["spritePlayer2Vortex"];
	}
}

void Vortex::RemovePowerUp()
{
	usingPower = false;
	if (target == 0)
	{
		gm->Player1Skill3 = false;
		gm->sprites["spritePlayer1"] = gm->sprites["spriteSkull1"];
	}		
	if (target == 1)
	{
		gm->Player2Skill3 = false;
		gm->sprites["spritePlayer2"] = gm->sprites["spriteSkull2"];
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

//Antigo: PerfectShoot
/*gm->ball.dir = Vector(0, 0);
		following.start(10);
		pos = new Vector(1330, 400);
		distance = sqrt(pow(gm->ball.pos.x - pos->x, 2) + pow(gm->ball.pos.y - pos->x, 2));
		x = gm->ball.pos.x / distance;
		y = gm->ball.pos.y / distance;
		gm->sprites["spritePlayer1"] = gm->sprites["spritePlayer1PerfectShoot"];
		targetFollowed = true;*/

		/*if (targetFollowed)
			{
				if (gm->ball.pos.x < pos->x)
					gm->ball.pos.x = gm->ball.pos.x + x;
				if (gm->ball.pos.x > pos->x)
					gm->ball.pos.x = gm->ball.pos.x - x;
				if (gm->ball.pos.y < pos->y)
					gm->ball.pos.y = gm->ball.pos.y + y;
				if (gm->ball.pos.y > pos->y)
					gm->ball.pos.y = gm->ball.pos.y - y;
			}*/
			/*if (gm->ball.pos.y == y && gm->ball.pos.x == x)
				RemovePowerUp();*/