#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Gamemode.h"
#include <iostream>

using namespace std;
using namespace sf;

int main(){

    RenderWindow window(VideoMode(800, 600), "SFML window");
    
    Gamemode gamemode;
    gamemode.loadInfo();

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Clear screen
        window.clear();
        // Draw the sprite
        gamemode.drawAll(window);
        gamemode.controlGame();        
     
        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}
