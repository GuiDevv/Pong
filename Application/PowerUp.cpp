#include "PowerUp.h"
#include <Windows.h>

void PowerUp::ActivePowerUp(Wall& w)
{
}
void PowerUp::RemovePowerUp()
{
}

void PowerUp::tickPower()
{
}


void WallBoost::ActivePowerUp(Wall& w)
{
	time.start(5);	
	activePow = true;
	wall = &w;
	speedBackup = wall->speedInicial;
	wall->speed = 0.3;
}
void WallBoost::RemovePowerUp()
{
	wall->speedInicial = speedBackup;
}

void WallBoost::tickPower()
{
	if (time.hasEnded() && activePow == true)
	{
		RemovePowerUp();
		activePow = false;
	}
		
}
