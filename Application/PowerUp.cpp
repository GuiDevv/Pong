#include "PowerUp.h"
#include <Windows.h>

void PowerUp::ActivePowerUp(Wall& wall)
{
}
void PowerUp::RemovePowerUp()
{
}


void WallBoost::ActivePowerUp(Wall& wall)
{
	Sleep(3000);
	//speedBackup = wall->speedInicial;
	//wall->speedInicial = 1;
}
void WallBoost::RemovePowerUp()
{
	wall->speedInicial = speedBackup;
}
