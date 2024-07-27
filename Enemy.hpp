#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <SFML/Graphics.hpp>
#include "Bullet.hpp"

class Enemy
{
public:
    Enemy();

    void movement();
    void spawn();
    void shooting();
    void draw(sf::RenderWindow& window);

private:
    int getRandomNumber(int min, int max);

    int randSpawnPositionX;
    int randMovementX;
    int randMovementY;

    sf::CircleShape enemyShape;

    std::vector<Enemy> enemies;
    std::vector<Bullet> bullets;

    sf::Clock shootingEnemyClock;
    sf::Clock spawnClock;
    sf::Clock movementClock;
};

#endif // ENEMY_HPP