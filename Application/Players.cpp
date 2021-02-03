#include "Players.h"
#include <Windows.h>

using namespace std;

void Players::Down()
{
	if (team == 0 && pos.y < 765)
	{
		pos.y += speed;
		dir.y = 1;
	}
		
	if (team == 1 && pos.y < 765)
		pos.y += speed;
}

void Players::Up()
{
	if (team == 0 && pos.y > 0)
	{
		pos.y -= speed;
		dir.y = -1;
	}
		
	if (team == 1 && pos.y > 0)
		pos.y -= speed;
}

void Players::Left()
{
	if (team == 0 && pos.x < 655 && pos.x > 0)
	{
		pos.x -= speed;
		dir.x = -1;
	}
		
	if (team == 1 && pos.x > 655)
		pos.x -= speed;
}

void Players::Right()
{
	if (team == 0 && pos.x < 650)
	{
		pos.x += speed;
		dir.x = 1;
	}
		
	if (team == 1 && pos.x > 650)
		pos.x += speed;
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

void Players::setInfo(int tipo)
{
	if (tipo == 0) //Player
	{
		posBackup.getVector().x = 500;
		posBackup.getVector().y = 300;
		speedInicial = 0.1;
		pos.x = posBackup.x;
		pos.y = posBackup.y;
		speed = speedInicial;
	}

	else if (tipo == 1) //IA
	{
		posBackup.getVector().x = 745;
		posBackup.getVector().y = 200;
		speedInicial = 0.1/*0.07*/;
		pos.x = posBackup.x;
		pos.y = posBackup.y;
		speed = speedInicial;
	}
}

void Players::tickWall()
{
	if (time.hasEnded() && activeBoost == true)
	{
		BoostReset();
		activeBoost = false;
	}

	dir.x = 0;
	dir.y = 0;
}


