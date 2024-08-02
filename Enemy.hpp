#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <SFML/Graphics.hpp>
#include "Bullet.hpp"
#include "Player.hpp"

class Enemy
{
public:
    Enemy();

    void spawn();
    void movement();
    void shooting();
    void draw(sf::RenderWindow& window);
    void removeEnemy(size_t index);

    std::vector<Bullet> getEnemyBullets();
    std::vector<Enemy> getEnemies();
    std::vector<size_t> checkCollisionWithBullets(const std::vector<Bullet>& bullets) const;

    std::vector<Enemy> enemies;
    std::vector<Bullet> bullets;

    sf::FloatRect getBounds();
    sf::CircleShape enemyShape;

private:
    int getRandomNumber(int min, int max);

    int randSpawnPositionX;
    int randMovementX;
    int randMovementY;


    sf::Clock shootingEnemyClock;
    sf::Clock spawnClock;
    sf::Clock movementClock;
};

#endif // ENEMY_HPP