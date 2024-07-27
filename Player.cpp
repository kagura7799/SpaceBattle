#include "Player.hpp"
#include <iostream>

Player::Player() 
{
    player.setRadius(35.f);
    player.setFillColor(sf::Color::White);
    player.setPosition(570.f, 900.f);
}

void Player::movement() 
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) 
    {
        player.move(-8.f, 0.f);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) 
    {
        player.move(8.f, 0.f);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) 
    {
        player.move(0.f, -8.f);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) 
    {
        player.move(0.f, 8.f);
    }
}

void Player::shooting(sf::RenderWindow& window) 
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && shootClock.getElapsedTime().asSeconds() > 0.5f) {
        bullets.emplace_back(player.getPosition().x + player.getRadius(), player.getPosition().y, sf::Color::Blue);
        shootClock.restart();
    }

    for (auto& bullet : bullets) {
        bullet.update(-12.f);
    }
}

void Player::draw(sf::RenderWindow& window) 
{
    window.draw(player);

    for (auto& bullet : bullets) 
    {
        window.draw(bullet.bullet_shape);
    }
}