#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <SFML/Graphics.hpp>

class Enemy
{
public:
    Enemy();
    void move();
    void draw(sf::RenderWindow& window);
    sf::CircleShape enemyShape;

private:
    int getRandomNumber(int min, int max);

    // int randSpawnPositionX = getRandomNumber(200, 1100);
    // int randMovementX = getRandomNumber(10, 50);
    // int randMovementY = getRandomNumber(10, 50);
};

#endif // ENEMY_HPP