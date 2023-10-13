#include "MovingObstacle.h"
#include <SFML/Graphics.hpp>

MovingObstacle::MovingObstacle(int x, int y, int width, int height, sf::RenderWindow& window, float velocityXIn, float velocityYIn, float maxPosition, float minPosition)
    : Obstacle(x, y, width, height, window), velocityX(velocityXIn), velocityY(velocityYIn), maxPosition(maxPosition), minPosition(minPosition){
        moveUp = true;
    // Initialize moving obstacle-specific members here.
}

void MovingObstacle::update() {
    if (moveUp) {
        // Move up until a certain point is reached (e.g., y < 100). depends on game size
        if ((get_y_position() > maxPosition && velocityX == 0) || (get_x_position() > maxPosition && velocityY == 0)) {
            set_x_position(get_x_position() - velocityX); 
            set_y_position(get_y_position() - velocityY);
        } else {
            // Change direction when the upper limit is reached
            moveUp = false;
        }
    } else {
        // Move down until another point is reached (e.g., y > 800)
        if ((get_y_position() < minPosition && velocityX == 0) || (get_x_position() < minPosition && velocityY == 0)) {
            set_x_position(get_x_position() + velocityX); 
            set_y_position(get_y_position() + velocityY);
        } else {
            // Change direction when the lower limit is reached
            moveUp = true;
        }
    }

    getSprite().setPosition(get_x_position(), get_y_position());
}
