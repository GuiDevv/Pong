#pragma once
#ifndef _gamemode
#define _gamemode

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <ctime>
#include "Wall.h"
#include "Ball.h"
#include "PowerUp.h"
#include "Controllers.h"

using namespace std;
using namespace sf;

class Controllers;

class Gamemode
{
public:
	Gamemode();

	map<string, Texture> textures;
	map<string, Sprite> sprites;
	map<string, Font> fonts;
	map<string, Controllers*> controllers;	
	Wall wall1, wall2;
	Ball ball;
	IntRect wall1Area, wall2Area, ballArea;
	int winsPlayer1, winsPlayer2;
	Text text;
	bool trava;	
	clock_t timer;
	PowerUp *power, *power2;
	bool travaPower = false, travaPower2 = false;

	void loadInfo();
	void drawAll(RenderWindow &window);
	void controlGame();
	void givePoints(int who);
	bool Delay(int timer);
	void tradePowerUp(int i);
	float Random();
	void tradeMode(string m);
	void ticksControl();

};

#endif // !_gamemode