#include "Gamemode.h"

Gamemode::Gamemode()
{
	srand(time(0));
}

void Gamemode::loadInfo()
{
	wall1.setInfo(0, 0);
	wall2.setInfo(1, 1);
	ball.setInfo(400, 300);
	wall1Area = IntRect(wall1.pos.x, wall1.pos.y, 100, 104); // Trocar Aqui
	wall2Area = IntRect(wall2.pos.x, wall2.pos.y, 100, 104);
	ballArea = IntRect(ball.pos.getVector().x, ball.pos.getVector().y, 30, 34);
	//collisions = new Collision;
	//collisions->gm = this;

	textures["wall1"].loadFromFile("Assets\\skull1.png");
	textures["wall2"].loadFromFile("Assets\\skull2.png");
	textures["ball"].loadFromFile("Assets\\ball.png");

	sprites["spriteWall1"].setTexture(textures["wall1"]);
	sprites["spriteWall2"].setTexture(textures["wall2"]);
	sprites["spriteBall"].setTexture(textures["ball"]);

	/*tradeMode("Singleplayer");*/
	tradeMode("Multiplayer");

	fonts["font1"].loadFromFile("Assets\\impact-1.ttf");	

	ball.BallReset();
	ball.RandomSpeeds(Random(), Random());
	power = new PowerUp;
	power2 = new PowerUp;
	text = Text("Pontuação: " + to_string(winsPlayer1) + " | " + to_string(winsPlayer2), fonts["font1"], 35);
	text.setPosition(250, 0);

	winsPlayer1 = 0;
	winsPlayer2 = 0;
	trava = 0;	
}

void Gamemode::drawAll(RenderWindow &window)
{	
	sprites["spriteWall1"].setPosition(wall1.pos.x, wall1.pos.y);
	sprites["spriteWall2"].setPosition(wall2.pos.x, wall2.pos.y);
	sprites["spriteBall"].setPosition(ball.pos.getVector().x, ball.pos.getVector().y);	

	//text.setString("Pontuação: " + to_string(winsPlayer1) + " | " + to_string(winsPlayer2));
	text.setString("Bola Speed: " + to_string(ball.dir.x) + " | " + to_string(ball.dir.y));

	window.draw(sprites["spriteWall1"]);
	window.draw(sprites["spriteWall2"]);
	window.draw(sprites["spriteBall"]);
	window.draw(text);
	
}


void Gamemode::controlGame()
{
	ticksControl();

	wall1Area.left = wall1.pos.x;
	wall1Area.top = wall1.pos.y;
	wall2Area.left = wall2.pos.x;
	wall2Area.top = wall2.pos.y;
	ballArea.left = ball.pos.getVector().x;
	ballArea.top = ball.pos.getVector().y;	

	if (ball.pos.getVector().x > 1400)
		givePoints(0);
	if (ball.pos.getVector().x < 0)
		givePoints(1);
	if (ball.pos.getVector().x > 780)
		trava = 1;

	if (wall1Area.intersects(ballArea))
	{		
		ball.dir.getVector() = wall1.dir.getVector() + ball.dir.getVector();

		if (ball.dir.y > 1)
			ball.dir.y = 1;
		if( ball.dir.y < -1)
			ball.dir.y = -1;
		if (ball.dir.x > 1)
			ball.dir.x = 1;
		if (ball.dir.x < -1)
			ball.dir.x = -1;

		if (wall2.activeBoost)
			ball.ace = 1.0004;
		else
			ball.ace = 1.0007;

				
	}
	if (wall2Area.intersects(ballArea))
	{
		ball.dir.getVector() = wall2.dir.getVector() + ball.dir.getVector();

		if (ball.dir.y > 1)
			ball.dir.y = 1;
		if (ball.dir.y < -1)
			ball.dir.y = -1;
		if (ball.dir.x > 1)
			ball.dir.x = 1;
		if (ball.dir.x < -1)
			ball.dir.x = -1;

		if (wall2.activeBoost)
			ball.ace = 1.0004;
		else
			ball.ace = 1.0007;	

	}

	if (winsPlayer1 % 5 == 0 && travaPower == false && winsPlayer1 != 0)
	{
		tradePowerUp(0);
		travaPower = true;
	}

	if (winsPlayer2 % 5 == 0 && travaPower2 == false && winsPlayer2 != 0)
	{
		tradePowerUp(1);
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

void Gamemode::tradePowerUp(int i)
{
	if (i == 0)
	{
		power = new WallBoost;
		power->ActivePowerUp(wall1);		
	}
	if (i == 1)
	{
		power2 = new WallBoost;
		power2->ActivePowerUp(wall2);
	}

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
		controllers["Player"]->setInfo(wall1);
		controllers["Player2"] = new ControllerIa;
		controllers["Player2"]->gamemode = this;
		controllers["Player2"]->setInfo(wall2);
	}
	if (m == "Multiplayer")
	{
		controllers["Player"] = new ControllerPlayer(0);
		controllers["Player"]->gamemode = this;
		controllers["Player"]->setInfo(wall1);
		controllers["Player2"] = new ControllerPlayer(1);
		controllers["Player2"]->gamemode = this;
		controllers["Player2"]->setInfo(wall2);
	}
}

void Gamemode::ticksControl()
{
	power->tickPower();
	power2->tickPower();
	wall1.tickWall();
	wall2.tickWall();
	ball.tickBall();
	for (auto p : controllers) {
		p.second->tickController();
	}	
}
