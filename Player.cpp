#include "Player.hpp"
#include <iostream>

Player::Player() 
{
    playerShape.setRadius(35.f);
    playerShape.setFillColor(sf::Color::White);
    playerShape.setPosition(570.f, 900.f);
}

void Player::movement() 
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) 
    {
        playerShape.move(-8.f, 0.f);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) 
    {
        playerShape.move(8.f, 0.f);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) 
    {
        playerShape.move(0.f, -8.f);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) 
    {
        playerShape.move(0.f, 8.f);
    }
}

void Player::shooting(sf::RenderWindow& window) 
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && shootClock.getElapsedTime().asSeconds() > 0.5f) 
    {
        bullets.emplace_back(playerShape.getPosition().x + playerShape.getRadius(), playerShape.getPosition().y, sf::Color::Blue);
        shootClock.restart();
    }

    for (auto& bullet : bullets) 
    {
        bullet.update(-12.f);
    }
}

void Player::draw(sf::RenderWindow& window) 
{
    window.draw(playerShape);

    for (auto& bullet : bullets) 
    {
        window.draw(bullet.bullet_shape);
    }
}

sf::FloatRect Player::getBounds() const
{
    return playerShape.getGlobalBounds();
}

std::vector<Bullet>& Player::getBullets()
{
    return bullets;
}
