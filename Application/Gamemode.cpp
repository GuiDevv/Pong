#include "Gamemode.h"

Gamemode::Gamemode()
{
	srand(time(0));
}

void Gamemode::loadInfo()
{
	player1 = new Players();
	player1->setInfo(0, 0, *this);	
	player2 = new Players();
	player2->setInfo(1, 1, *this);
	ball.setInfo(675, 370);
	ball.color = 1;
	player1Area = IntRect(player1->pos.x, player1->pos.y, 100, 104);
	player2Area = IntRect(player2->pos.x, player2->pos.y, 100, 104);
	wall1Area = IntRect(0, 0, 80, 273);
	wall2Area = IntRect(0, 530, 80, 273);
	wall3Area = IntRect(1320, 0, 80, 273);
	wall4Area = IntRect(1320, 530, 80, 273);
	ballArea = IntRect(ball.pos.getVector().x, ball.pos.getVector().y, 30, 34);
	SpectralBone1 = IntRect(0, 277, 80, 250);
	SpectralBone2 = IntRect(1320, 277, 80, 250);
	collisions = new CollisionSystem;
	collisions->gm = this;

	collisions->setAll();
	textures["player1"].loadFromFile("Assets\\skull1.png");
	textures["player2"].loadFromFile("Assets\\skull2.png");
	textures["wall1"].loadFromFile("Assets\\wall1.png");
	textures["wall2"].loadFromFile("Assets\\wall2.png");
	textures["ball1"].loadFromFile("Assets\\ball1.png");
	textures["ball2"].loadFromFile("Assets\\ball2.png");
	textures["ball3"].loadFromFile("Assets\\ball3.png");
	textures["player1Frozen"].loadFromFile("Assets\\skull1Frozen.png");
	textures["player2Frozen"].loadFromFile("Assets\\skull2Frozen.png");
	textures["player1PerfectShoot"].loadFromFile("Assets\\skull1PerfectShoot.png");
	textures["player2PerfectShoot"].loadFromFile("Assets\\skull2PerfectShoot.png");
	textures["player1Vortex"].loadFromFile("Assets\\skull1Vortex.png");
	textures["player2Vortex"].loadFromFile("Assets\\skull2Vortex.png");
	textures["iconPlayer1Frozen"].loadFromFile("Assets\\skill1Blue.png");
	textures["iconPlayer2Frozen"].loadFromFile("Assets\\skill1Red.png");
	textures["iconDisableFrozen"].loadFromFile("Assets\\skill1Disable.png");
	textures["iconPlayer1PerfectShoot"].loadFromFile("Assets\\skill2Blue.png");
	textures["iconPlayer2PerfectShoot"].loadFromFile("Assets\\skill2Red.png");
	textures["iconDisablePerfectShoot"].loadFromFile("Assets\\skill2Disable.png");
	textures["iconPlayer1Vortex"].loadFromFile("Assets\\skill3Blue.png");
	textures["iconPlayer2Vortex"].loadFromFile("Assets\\skill3Red.png");
	textures["iconDisableVortex"].loadFromFile("Assets\\skill3Disable.png");
	textures["spectralBone1"].loadFromFile("Assets\\spectralBone1.png");
	textures["spectralBone2"].loadFromFile("Assets\\spectralBone2.png");
	textures["division1"].loadFromFile("Assets\\string1.png");
	textures["division2"].loadFromFile("Assets\\string2.png");
	textures["division3"].loadFromFile("Assets\\string3.png");

	sprites["spritePlayer1"].setTexture(textures["player1"]);
	sprites["spritePlayer2"].setTexture(textures["player2"]);
	sprites["spriteSkull1"].setTexture(textures["player1"]);
	sprites["spriteSkull2"].setTexture(textures["player2"]);
	sprites["spritePlayer1Frozen"].setTexture(textures["player1Frozen"]);
	sprites["spritePlayer2Frozen"].setTexture(textures["player2Frozen"]);
	sprites["spritePlayer1PerfectShoot"].setTexture(textures["player1PerfectShoot"]);
	sprites["spritePlayer2PerfectShoot"].setTexture(textures["player2PerfectShoot"]);
	sprites["spritePlayer1Vortex"].setTexture(textures["player1Vortex"]);
	sprites["spritePlayer2Vortex"].setTexture(textures["player2Vortex"]);
	sprites["spriteWall1"].setTexture(textures["wall1"]);
	sprites["spriteWall2"].setTexture(textures["wall1"]);
	sprites["spriteWall3"].setTexture(textures["wall2"]);
	sprites["spriteWall4"].setTexture(textures["wall2"]);
	sprites["spriteBall"].setTexture(textures["ball1"]);
	sprites["skill1Icon1"].setTexture(textures["iconPlayer1Frozen"]);
	sprites["skill1Icon2"].setTexture(textures["iconPlayer2Frozen"]);
	sprites["skill1Icon3"].setTexture(textures["iconDisableFrozen"]);
	sprites["skill2Icon1"].setTexture(textures["iconPlayer1PerfectShoot"]);
	sprites["skill2Icon2"].setTexture(textures["iconPlayer2PerfectShoot"]);
	sprites["skill2Icon3"].setTexture(textures["iconDisablePerfectShoot"]);
	sprites["skill3Icon1"].setTexture(textures["iconPlayer1Vortex"]);
	sprites["skill3Icon2"].setTexture(textures["iconPlayer2Vortex"]);
	sprites["skill3Icon3"].setTexture(textures["iconDisableVortex"]);
	sprites["spriteBone1"].setTexture(textures["spectralBone1"]);
	sprites["spriteBone2"].setTexture(textures["spectralBone2"]);
	sprites["spriteDivision"].setTexture(textures["division1"]);
	sprites["spriteDivision1"].setTexture(textures["division1"]);
	sprites["spriteDivision2"].setTexture(textures["division2"]);
	sprites["spriteDivision3"].setTexture(textures["division3"]);

	/*tradeMode("Singleplayer");*/
	tradeMode("Multiplayer");

	fonts["font1"].loadFromFile("Assets\\impact-1.ttf");	

	ball.BallReset();
	text = Text("Pontuação: " + to_string(winsPlayer1) + " | " + to_string(winsPlayer2), fonts["font1"], 35);
	text.setPosition(580, 0);

	winsPlayer1 = 0;
	winsPlayer2 = 0;
	trava = 0;	
}

void Gamemode::drawAll(RenderWindow &window)
{	
	sprites["spriteDivision0"].setPosition(650, 0);
	sprites["spriteDivision1"].setPosition(650, 0);
	sprites["spriteDivision2"].setPosition(650, 0);
	sprites["spriteDivision3"].setPosition(650, 0);
	sprites["spritePlayer1"].setPosition(player1->pos.x, player1->pos.y);
	sprites["spritePlayer2"].setPosition(player2->pos.x, player2->pos.y);
	sprites["spriteWall1"].setPosition(0, 0);
	sprites["spriteWall2"].setPosition(0, 530);
	sprites["spriteWall3"].setPosition(1320, 0);
	sprites["spriteWall4"].setPosition(1320, 530);
	sprites["spriteBall"].setPosition(ball.pos.getVector().x, ball.pos.getVector().y);
	sprites["spriteBone1"].setPosition(0, 277);
	sprites["spriteBone2"].setPosition(1320, 277);

	sprites["skill1Icon1"].setPosition(200, 20);
	sprites["skill2Icon1"].setPosition(250, 20);
	sprites["skill3Icon1"].setPosition(300, 20);
	sprites["skill1Icon2"].setPosition(1060, 20);
	sprites["skill2Icon2"].setPosition(1110, 20);
	sprites["skill3Icon2"].setPosition(1160, 20);

	text.setString("Pontuação: " + to_string(winsPlayer1) + " | " + to_string(winsPlayer2));

	if (ball.color == 1)
		sprites["spriteBall"].setTexture(textures["ball1"]);
	if (ball.color == 2)
		sprites["spriteBall"].setTexture(textures["ball2"]);
	if (ball.color == 3)
		sprites["spriteBall"].setTexture(textures["ball3"]);
	if (ball.color == 1)
		sprites["spriteDivision"] = sprites["spriteDivision1"];
	if (ball.pos.x > 680 && ball.color != 1)
		sprites["spriteDivision"] = sprites["spriteDivision3"];
	if (ball.pos.x < 670 && ball.color != 1)
		sprites["spriteDivision"] = sprites["spriteDivision2"];

	window.draw(sprites["spriteDivision"]);
	window.draw(sprites["spritePlayer1"]);
	window.draw(sprites["spritePlayer2"]);
	window.draw(sprites["spriteWall1"]);
	window.draw(sprites["spriteWall2"]);
	window.draw(sprites["spriteWall3"]);
	window.draw(sprites["spriteWall4"]);
	window.draw(sprites["spriteBall"]);
	window.draw(sprites["skill1Icon1"]);
	window.draw(sprites["skill2Icon1"]);
	window.draw(sprites["skill3Icon1"]);
	window.draw(sprites["skill1Icon2"]);
	window.draw(sprites["skill2Icon2"]);
	window.draw(sprites["skill3Icon2"]);
	if(player1->skills->skill3->usingPower)
	window.draw(sprites["spriteBone1"]);
	if (player2->skills->skill3->usingPower)
	window.draw(sprites["spriteBone2"]);
	window.draw(text);
	
}


void Gamemode::controlGame()
{
	ticksControl();

	player1Area.left = player1->pos.x;
	player1Area.top = player1->pos.y;
	player2Area.left = player2->pos.x;
	player2Area.top = player2->pos.y;
	ballArea.left = ball.pos.getVector().x;
	ballArea.top = ball.pos.getVector().y;	

	if (ball.pos.getVector().x > 1320)
		givePoints(0);
	if (ball.pos.getVector().x < 20)
		givePoints(1);
	if (ball.pos.getVector().x > 780)
		trava = 1;	

	if (winsPlayer1 % 5 != 0 && travaPower == true)
	{
		travaPower = false;
	}
	if (winsPlayer2 % 5 != 0 && travaPower2 == true)
	{
		travaPower2 = false;
	}

}

void Gamemode::givePoints(int who)
{
	if (who == 0)
		winsPlayer1++;
	if (who == 1)
		winsPlayer2++;
	
	ball.BallReset();
	trava = 0;
	
}

int Gamemode::Random(int t)
{
	int random;
	random = rand() % t + 1;
	random = random / t;
	return random;
}

void Gamemode::tradeMode(string m)
{

	if (m == "Singleplayer")
	{
		controllers["Player"] = new ControllerPlayer(0);
		controllers["Player"]->gamemode = this;
		controllers["Player"]->setInfo(*player1);
		controllers["Player2"] = new ControllerIa;
		controllers["Player2"]->gamemode = this;
		controllers["Player2"]->setInfo(*player2);
	}
	if (m == "Multiplayer")
	{
		controllers["Player1"] = new ControllerPlayer(0);
		controllers["Player1"]->gamemode = this;
		controllers["Player1"]->setInfo(*player1);
		controllers["Player2"] = new ControllerPlayer(1);
		controllers["Player2"]->gamemode = this;
		controllers["Player2"]->setInfo(*player2);
	}
}

void Gamemode::ticksControl()
{
	collisions->tickCollision();	
	player1->tickPlayer();
	player2->tickPlayer();
	ball.tickBall();
	for (auto p : controllers) {
		p.second->tickController();
	}	
	
}
