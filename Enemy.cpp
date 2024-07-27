#include <SFML/Graphics.hpp>
#include "Enemy.hpp"
#include <iostream>
#include <random>

int Enemy::getRandomNumber(int min, int max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);

    return dis(gen);
}

Enemy::Enemy()
{
    randSpawnPositionX = getRandomNumber(30, 800);

    enemyShape.setRadius(30.f);
    enemyShape.setFillColor(sf::Color::Red);
    enemyShape.setPosition(randSpawnPositionX, 10.f);
}

void Enemy::spawn()
{
    if (spawnClock.getElapsedTime().asSeconds() > 3.f)
    {
        enemies.emplace_back();
        spawnClock.restart();
    }
}

void Enemy::movement()
{
    if (movementClock.getElapsedTime().asSeconds() > 0.3f)
    {
        randMovementX = getRandomNumber(-10.f, 20.f);
        randMovementY = getRandomNumber(-10.f, 30.f);

        for (auto& enemy : enemies)
        {
            enemy.enemyShape.move(randMovementX, randMovementY);
        }
        movementClock.restart();
    }
}

void Enemy::shooting()
{
    if (shootingEnemyClock.getElapsedTime().asSeconds() > 0.8f)
    {
        for (auto& enemy : enemies)
        {
            bullets.emplace_back(enemy.enemyShape.getPosition().x + enemy.enemyShape.getRadius(), enemy.enemyShape.getPosition().y, sf::Color::Red);
        }
        shootingEnemyClock.restart();
    }

    for (auto& bullet : bullets)
    {
        bullet.update(10.f);
    }
}

void Enemy::draw(sf::RenderWindow& window)
{   
    for (auto& enemy : enemies)
    {
        window.draw(enemy.enemyShape);
    }

    for (auto& bullet : bullets)
    {
        window.draw(bullet.bullet_shape);
    }
}