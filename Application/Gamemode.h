#pragma once
#ifndef _gamemode
#define _gamemode

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <ctime>
#include "Players.h"
#include "Ball.h"
#include "Skills.h"
#include "Controllers.h"
#include "CollisionSystem.h"
#include "Vector.h"
#include <Windows.h>

using namespace std;
using namespace sf;

class Players;
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
	Players *player1, *player2;
	Ball ball;
	IntRect player1Area, player2Area, ballArea, wall1Area, wall2Area, wall3Area, wall4Area, SpectralBone1, SpectralBone2;
	int winsPlayer1, winsPlayer2;
	Text text;
	bool trava;	
	bool travaPower = false, travaPower2 = false;

	void loadInfo();
	void drawAll(RenderWindow &window);
	void controlGame();
	void givePoints(int who);
	int Random(int t);
	void tradeMode(string m);
	void ticksControl();

};

#endif // !_gamemode