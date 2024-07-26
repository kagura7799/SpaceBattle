#include "Bullet.hpp"

Bullet::Bullet(float x, float y)
{
    bullet_shape.setRadius(10.f);
    bullet_shape.setFillColor(sf::Color::Blue);
    bullet_shape.setPosition(x, y);
}

void Bullet::update()
{
    bullet_shape.move(0.f, -12.f);
}

sf::CircleShape bullet_shape;