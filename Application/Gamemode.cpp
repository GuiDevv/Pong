#include "Gamemode.h"

Gamemode::Gamemode()
{
	srand(time(0));
}

void Gamemode::loadInfo()
{
	textures["wall1"].loadFromFile("Assets\\wall1.png");
	textures["wall2"].loadFromFile("Assets\\wall2.png");
	textures["ball"].loadFromFile("Assets\\ball.png");

	sprites["spriteWall1"].setTexture(textures["wall1"]);
	sprites["spriteWall2"].setTexture(textures["wall2"]);
	sprites["spriteBall"].setTexture(textures["ball"]);

	fonts["font1"].loadFromFile("Assets\\impact-1.ttf");

	wallPlayer.setInfo(0);
	wallIa.setInfo(1);
	ball.setInfo(400, 300);
	wall1Area = IntRect(wallPlayer.x, wallPlayer.y, 54, 167);
	wall2Area = IntRect(wallIa.x, wallIa.y, 54, 167);
	ballArea = IntRect(ball.pos.getVector().x, ball.pos.getVector().y, 30, 34);

	player1->setType(0);
	player1->setWall(wallPlayer);
	
	player2->setType(1);
	player2->setWall(wallIa);
	player2->setBall(ball);

	text = Text("Pontuação: " + to_string(winsPlayer) + " | " + to_string(winsIa), fonts["font1"], 35);
	text.setPosition(250, 0);

	winsPlayer = 0;
	winsIa = 0;
	trava = 0;	
}

void Gamemode::drawAll(RenderWindow &window)
{
	
	sprites["spriteWall1"].setPosition(wallPlayer.x, wallPlayer.y);
	sprites["spriteWall2"].setPosition(wallIa.x, wallIa.y);
	sprites["spriteBall"].setPosition(ball.pos.getVector().x, ball.pos.getVector().y);	

	text.setString("Pontuação: " + to_string(winsPlayer) + " | " + to_string(winsIa));

	window.draw(sprites["spriteWall1"]);
	window.draw(sprites["spriteWall2"]);
	window.draw(sprites["spriteBall"]);
	window.draw(text);
	
}

void Gamemode::controlGame()
{
	//isso tem q ir para a Wall, o controller da o Input;
	if (player2->timer > 0)
	{
		if (Delay(player2->timer))
			player2->disableTimer();
	}
	//

	wall1Area.left = wallPlayer.x;
	wall1Area.top = wallPlayer.y;
	wall2Area.left = wallIa.x;
	wall2Area.top = wallIa.y;
	ballArea.left = ball.pos.getVector().x;
	ballArea.top = ball.pos.getVector().y;


	//this need to be called tick, because it ticks
	for (auto p : controllers) {
		p.second->enableControllers();//THIS NEED TO BE CALLED TICK
	}
	//
	
	ball.Bounce();	//THIS NEED TO BE CALLED TICK

	if (ball.pos.getVector().x > 800)
		givePoints(0);
	if (ball.pos.getVector().x < 0)
		givePoints(1);
	if (ball.pos.getVector().x > 780)
		trava = 1;
	if (wall1Area.intersects(ballArea) && wallPlayer.x == 50 && trava == 0)
	{
		ball.testCollision(2);
		trava = 1;
	}
	if (wall1Area.intersects(ballArea) && trava == 0)
	{
		ball.testCollision(0);
		trava = 1;
	}
	if (wall2Area.intersects(ballArea) && trava == 0)
	{
		ball.testCollision(1);
		trava = 1;
	}
	if (ball.pos.getVector().x > 200 && ball.pos.getVector().x < 600 && trava == 1)
	{
		trava = 0;
	}
	
	//isso ta no controller
	if pressedButton
		wall.boost();


	//if (winsPlayer > 0 && travaPower == false)
	//{
	//	power = new WallBoost;
	//	power->ActivePowerUp(wallPlayer);
	//	travaPower = true;
	//}
}

void Gamemode::givePoints(int who)
{
	if (who == 0)
		winsPlayer++;
	if (who == 1)
		winsIa++;
	
	wallPlayer.BoostReset();
	//controllerPlayer.disableTimer(); VAI PARA A WALL
	ball.BallReset();
	ball.RandomSpeeds(Random(), Random());
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
