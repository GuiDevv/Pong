#include "Players.h"
#include <Windows.h>

using namespace std;

void Players::Down()
{
	if (team == 0 && pos.y < limitDown) // LimiteDownY (765)
	{
		pos.y += speed;
		dir.y = 1;
	}
		
	if (team == 1 && pos.y < limitDown)
	{
		pos.y += speed;
		dir.y = 1;
	}
}

void Players::Up()
{
	if (team == 0 && pos.y > limitUp) // LimiteUp (0)
	{
		pos.y -= speed;
		dir.y = -1;
	}
		
	if (team == 1 && pos.y > limitUp)
	{
		pos.y -= speed;
		dir.y = -1;
	}		
}

void Players::Left()
{
	if (team == 0 && pos.x > limitLeft)
	{
		pos.x -= speed;
		dir.x = -1;
	}
		
	if (team == 1 && pos.x > limitLeft)
	{
		pos.x -= speed;
		dir.x = -1;
	}		
}

void Players::Right()
{
	if (team == 0 && pos.x < limitRight) // LimiteRight(650)
	{
		pos.x += speed;
		dir.x = 1;
	}
		
	if (team == 1 && pos.x < limitRight)
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
//
void Players::BoostReset()
{	
	speed = speedInicial;
}

void Players::setInfo(int tipo, int t)
{
	team = t;

	if (tipo == 0) //Player
	{
		posBackup.getVector().x = 350;
		posBackup.getVector().y = 350;
		speedInicial = 0.1;
		pos.x = posBackup.x;
		pos.y = posBackup.y;
		speed = speedInicial;
		limitUp = 0;
		limitDown = 700;
		limitLeft = 0;
		limitRight = 600;
	}

	else if (tipo == 1 || t == 1) //IA
	{
		posBackup.getVector().x = 1050;
		posBackup.getVector().y = 350;
		speedInicial = 0.1;
		pos.x = posBackup.x;
		pos.y = posBackup.y;
		speed = speedInicial;
		limitUp = 0;
		limitDown = 700;
		limitLeft = 700;
		limitRight = 1300;
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


