#pragma once
#include "Gamemode.h"

enum ScreenEnum { Game, Menu, End, GameSelection };

class Screens
{
public:

	Gamemode* gm;
	Sprite menuBackground, endBackground, bPlay, bSingleplayer, bMultiplayer;
	Texture menuTexture, endTexture, playTexture, singleTexture, multiTexture;
	ScreenEnum screen = Menu;
	IntRect *b1, *b2;
	Vector2i pos;
	Clock wait;

	void loadAssets(Gamemode& g);
    void screenDraw(RenderWindow& window);
	void changeScreen(string s);  
	void changeGamemode(string type);
    
};

