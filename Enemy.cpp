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
    int randSpawnPositionX = getRandomNumber(30, 800);

    enemyShape.setRadius(30.f);
    enemyShape.setFillColor(sf::Color::Magenta);
    enemyShape.setPosition(randSpawnPositionX, 10);
}

void Enemy::move()
{
    int randMovementX = getRandomNumber(-10.f, 20.f);
    int randMovementY = getRandomNumber(-10.f, 30.f);

    enemyShape.move(randMovementX, randMovementY);
}

void Enemy::draw(sf::RenderWindow& window)
{
    window.draw(enemyShape);
}

sf::CircleShape enemyShape;