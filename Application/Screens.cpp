#include "Screens.h"

void Screens::loadAssets(Gamemode& g)
{
    gm = &g;
    menuTexture.loadFromFile("Assets\\menuBackground.png");
    endTexture.loadFromFile("Assets\\endBackground.png");
    playTexture.loadFromFile("Assets\\bJogar.png");
    singleTexture.loadFromFile("Assets\\bSinglePlayer.png");
    multiTexture.loadFromFile("Assets\\bMultiplayer.png");
    menuBackground.setTexture(menuTexture);
    endBackground.setTexture(endTexture);
    bPlay.setTexture(playTexture);
    bSingleplayer.setTexture(singleTexture);
    bMultiplayer.setTexture(multiTexture);    
    bPlay.setPosition(612, 356);
    bSingleplayer.setPosition(612, 200);
    bMultiplayer.setPosition(612, 400);
    changeScreen("Menu");
    
}

void Screens::screenDraw(RenderWindow& window){
    
    if (screen == Menu)
    {        
        window.draw(menuBackground);
        window.draw(bPlay);

        if (Mouse::isButtonPressed(sf::Mouse::Left))
        {
            pos = Mouse::getPosition(window);

            if (b1->contains(pos))
            {
                wait.restart();
                changeScreen("GameSelection");
            }               
        }
    }
    if (screen == Game)
    {
        gm->drawAll(window);
        gm->controlGame();
    }
    if (screen == End)
    {
        window.draw(endBackground);
    }
    if (screen == GameSelection)
    {
        window.draw(menuBackground);
        window.draw(bSingleplayer);
        window.draw(bMultiplayer);

        if (Mouse::isButtonPressed(sf::Mouse::Left) && wait.getElapsedTime().asSeconds() > 0.5)
        {
            pos = Mouse::getPosition(window);

            if (b1->contains(pos))
            {
                changeGamemode("Singleplayer");
                changeScreen("Game");
            }               
            if (b2->contains(pos))
            {
                changeGamemode("Multiplayer");
                changeScreen("Game");
            }               
        }
    }
}

void Screens::changeScreen(string s)
{
    if (s == "Menu")
    {        
        b1 = new IntRect(bPlay.getPosition().x, bPlay.getPosition().y, 256, 88);
        screen = Menu;
    }       
    if (s == "GameSelection")
    {
        b1 = new IntRect(bSingleplayer.getPosition().x, bSingleplayer.getPosition().y, 612, 200);
        b2 = new IntRect(bMultiplayer.getPosition().x, bMultiplayer.getPosition().y, 612, 400);
        screen = GameSelection;
    }
    if (s == "Game")
    {
        gm->loadInfo();
        screen = Game;
    }
       
    if (s == "End")
        screen = End;
   
}

void Screens::changeGamemode(string type)
{
    if (type == "Singleplayer")
        gm->multiplayer = false;
    if (type == "Multiplayer")
        gm->multiplayer = true;
}
