#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Obstacle.h"
#include "DamagingObstacle.h"
#include "MovingObstacle.h"
#include "BoundingBox.h"
#include "Levels.h"

class Game {
private:
    sf::RenderWindow& window;
    sf::View view;
    sf::Font font;
    sf::Text text1;

    Player mario;
    BoundingBox boundingBoxMario;

    MovingObstacle move1;
    BoundingBox boundingBoxMove1; 

    std::vector<sf::FloatRect> obstacleBounds;

    Levels& levels;

public:
    Game(sf::RenderWindow& window, Levels& levels);

    void run(); // Run game
    void handleInput(); // Handle user input.
    void update(); // Update game logic.
    void render(); // Render game objects.

    void handleCollisions(); //  A separate function for collision handling


};


#endif
