#include <SFML/Graphics.hpp>
#include "Player.hpp"

Player::Player()
{
    player.setRadius(30.f);
    player.setFillColor(sf::Color::Green);
    player.setPosition(570.f, 900.f);
}

void Player::move(float dx, float dy)
{
    player.move(dx, dy);
}

void Player::draw(sf::RenderWindow& window)
{
    window.draw(player);
}

sf::Vector2f Player::getPosition()
{
    return player.getPosition();
}

sf::CircleShape player;
