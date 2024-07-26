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

    int randSpawnPositionX;
    int randMovementX;
    int randMovementY;
};

#endif // ENEMY_HPP