#include "Gamemode.h"

Gamemode::Gamemode()
{
	srand(time(0));
}

void Gamemode::loadInfo()
{
	player1.setInfo(0, 0);
	player2.setInfo(1, 1);
	ball.setInfo(675, 350);
	ball.color = 1;
	player1Area = IntRect(player1.pos.x, player1.pos.y, 100, 104);
	player2Area = IntRect(player2.pos.x, player2.pos.y, 100, 104);
	wall1Area = IntRect(0, 0, 80, 273);
	wall2Area = IntRect(0, 530, 80, 273);
	wall3Area = IntRect(1320, 0, 80, 273);
	wall4Area = IntRect(1320, 530, 80, 273);
	ballArea = IntRect(ball.pos.getVector().x, ball.pos.getVector().y, 30, 34);
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

	/*tradeMode("Singleplayer");*/
	tradeMode("Multiplayer");

	fonts["font1"].loadFromFile("Assets\\impact-1.ttf");	

	ball.BallReset();
	ball.RandomSpeeds(Random(), Random());
	text = Text("Pontuação: " + to_string(winsPlayer1) + " | " + to_string(winsPlayer2), fonts["font1"], 35);
	text.setPosition(250, 0);

	winsPlayer1 = 0;
	winsPlayer2 = 0;
	trava = 0;	
}

void Gamemode::drawAll(RenderWindow &window)
{	
	sprites["spritePlayer1"].setPosition(player1.pos.x, player1.pos.y);
	sprites["spritePlayer2"].setPosition(player2.pos.x, player2.pos.y);
	sprites["spriteWall1"].setPosition(0, 0);
	sprites["spriteWall2"].setPosition(0, 530);
	sprites["spriteWall3"].setPosition(1320, 0);
	sprites["spriteWall4"].setPosition(1320, 530);
	sprites["spriteBall"].setPosition(ball.pos.getVector().x, ball.pos.getVector().y);	

	//text.setString("Pontuação: " + to_string(winsPlayer1) + " | " + to_string(winsPlayer2));
	text.setString("Bola Speed: " + to_string(winsPlayer1) + " | " + to_string(controllers["Player1"]->enable));

	if (ball.color == 1)
		sprites["spriteBall"].setTexture(textures["ball1"]);
	if (ball.color == 2)
		sprites["spriteBall"].setTexture(textures["ball2"]);
	if (ball.color == 3)
		sprites["spriteBall"].setTexture(textures["ball3"]);

	window.draw(sprites["spritePlayer1"]);
	window.draw(sprites["spritePlayer2"]);
	window.draw(sprites["spriteWall1"]);
	window.draw(sprites["spriteWall2"]);
	window.draw(sprites["spriteWall3"]);
	window.draw(sprites["spriteWall4"]);
	window.draw(sprites["spriteBall"]);
	window.draw(text);
	
}


void Gamemode::controlGame()
{
	ticksControl();

	player1Area.left = player1.pos.x;
	player1Area.top = player1.pos.y;
	player2Area.left = player2.pos.x;
	player2Area.top = player2.pos.y;
	ballArea.left = ball.pos.getVector().x;
	ballArea.top = ball.pos.getVector().y;	

	if (ball.pos.getVector().x > 1320)
		givePoints(0);
	if (ball.pos.getVector().x < 20)
		givePoints(1);
	if (ball.pos.getVector().x > 780)
		trava = 1;

	if (skills["P1Skill1"]->getCooldown() == false)
		controllers["Player1"]->cooldown = false;
	if (skills["P2Skill1"]->getCooldown() == false)
		controllers["Player2"]->cooldown = false;

	if (P1lockSkill1 == false)
	{
		skills["P1Skill1"]->ActivePowerUp(0);
		P1lockSkill1 = true;
	}
	if (P2lockSkill1 == false)
	{
		skills["P2Skill1"]->ActivePowerUp(1);
		P2lockSkill1 = true;
	}


	if (winsPlayer1 % 5 == 0 && travaPower == false && winsPlayer1 != 0)
	{
		/*tradePowerUp(0);*/
		travaPower = true;
	}

	if (winsPlayer2 % 5 == 0 && travaPower2 == false && winsPlayer2 != 0)
	{
		/*tradePowerUp(1);*/
		travaPower2 = true;
	}

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
	
	/*wall1.BoostReset();*/
	ball.BallReset();
	/*ball.RandomSpeeds(Random(), Random());*/
	trava = 0;
	
}

bool Gamemode::Delay(int t)
{
	if (timer == 0)
	timer = clock();

	if (clock() - timer >= t)
	{
		timer = 0;
		return true;		
	}
	else
	return false;
}

float Gamemode::Random()
{
	float random;
	random = rand() % 10 + 1;
	random = random / 10;
	return random;
}

void Gamemode::tradeMode(string m)
{

	if (m == "Singleplayer")
	{
		controllers["Player"] = new ControllerPlayer(0);
		controllers["Player"]->gamemode = this;
		controllers["Player"]->setInfo(player1);
		skills["P1Skill1"] = new Frozen();
		skills["P1Skill1"]->gm = this;
		/*skills["P1Skill2"] = new Frozen();
		skills["P1Skill3"] = new Frozen();*/
		controllers["Player2"] = new ControllerIa;
		controllers["Player2"]->gamemode = this;
		controllers["Player2"]->setInfo(player2);
	}
	if (m == "Multiplayer")
	{
		controllers["Player1"] = new ControllerPlayer(0);
		controllers["Player1"]->gamemode = this;
		controllers["Player1"]->setInfo(player1);
		skills["P1Skill1"] = new Frozen();
		skills["P1Skill1"]->gm = this;
		controllers["Player2"] = new ControllerPlayer(1);
		controllers["Player2"]->gamemode = this;
		controllers["Player2"]->setInfo(player2);
		skills["P2Skill1"] = new Frozen();
		skills["P2Skill1"]->gm = this;
	}
}

void Gamemode::ticksControl()
{
	collisions->tickCollision();
	for (auto p : skills) {
		p.second->tickPower();
	}
	player1.tickWall();
	player2.tickWall();
	ball.tickBall();
	for (auto p : controllers) {
		p.second->tickController();
	}	
	
}
