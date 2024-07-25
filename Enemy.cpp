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

// TODO: fix error
//int randSpawnPositionX = getRandomNumber(200, 1100);
//int randMovementX = getRandomNumber(10, 50);
//int randMovementY = getRandomNumber(10, 50);

Enemy::Enemy()
{
    enemyShape.setRadius(30.f);
    enemyShape.setFillColor(sf::Color::Magenta);
    enemyShape.setPosition(randSpawnPositionX, -20.f);

    std::cout << "spawn pos: " << randSpawnPositionX << std::endl;
    std::cout << "X: " << randMovementX << "Y: " << randMovementY << std::endl;
}

void Enemy::move()
{
    enemyShape.move(randMovementX, randMovementY);
}

void Enemy::draw(sf::RenderWindow& window)
{
    window.draw(enemyShape);
}

sf::CircleShape enemyShape;
