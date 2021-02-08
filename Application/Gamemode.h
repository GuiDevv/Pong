#pragma once
#ifndef _gamemode
#define _gamemode

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <ctime>
#include "Players.h"
#include "Ball.h"
#include "PlayersSkills.h"
#include "Controllers.h"
#include "CollisionSystem.h"
#include "Vector.h"
#include <Windows.h>

using namespace std;
using namespace sf;

//class Players;

class Controllers;

class Gamemode
{
public:
	Gamemode();
	class CollisionSystem* collisions;
	map<string, Texture> textures;
	map<string, Sprite> sprites;
	map<string, Font> fonts;
	map<string, Controllers*> controllers;	
	map<string, class PlayersSkills*> skills;
	Players player1, player2;
	Ball ball;
	IntRect player1Area, player2Area, ballArea, wall1Area, wall2Area, wall3Area, wall4Area, SpectralBone1, SpectralBone2;
	int winsPlayer1, winsPlayer2;
	Text text;
	bool trava;	
	clock_t timer;
	bool travaPower = false, travaPower2 = false, P1lockSkill1 = true, P2lockSkill1 = true, P1lockSkill2 = true, P2lockSkill2 = true, P1lockSkill3 = true, P2lockSkill3 = true;
	bool Player1Skill3 = false, Player2Skill3 = false;

	void loadInfo();
	void drawAll(RenderWindow &window);
	void controlGame();
	void givePoints(int who);
	bool Delay(int timer);
	float Random();
	void tradeMode(string m);
	void ticksControl();

};

#endif // !_gamemode