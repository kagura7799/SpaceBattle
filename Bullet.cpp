#include "Bullet.hpp"

Bullet::Bullet(float x, float y, sf::Color color)
{
    bullet_shape.setRadius(10.f);
    bullet_shape.setFillColor(color);
    bullet_shape.setPosition(x, y);
}

void Bullet::update(float y)
{
    bullet_shape.move(0.f, y);
}