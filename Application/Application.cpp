#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Gamemode.h"
#include <iostream>
#include <list>

using namespace std;
using namespace sf;




class ColSystem{
public:
    static list<class ColInstance*> instances;
    void tick(){
        //check
        instances
    }
};


class ColInstance {
public:
    IntRect rec;
    ColInstance() {
        ColSystem::instances.push_back(this);
    }
    ~ColInstance() {
        ColSystem::instances.erase(this);
    }
    virtual void onCollision() {}
};

class Ball : 
    public ColInstance {
public:
    
    void onCollision() {
    }
};

int main(){






    RenderWindow window(VideoMode(1400, 800), "SFML window");
    
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
