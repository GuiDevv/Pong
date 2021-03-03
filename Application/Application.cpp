#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Gamemode.h"
#include "Screens.h"
#include <iostream>
#include <list>

using namespace std;
using namespace sf;

int main(){

    RenderWindow window(VideoMode(1400, 800), "Air Hockey");
    Screens screen;
    Gamemode gamemode;
    screen.loadAssets(gamemode);

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
        
        screen.screenDraw(window); 
     
        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}



