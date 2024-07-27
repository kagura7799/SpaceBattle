#ifndef BULLET_HPP
#define BULLET_HPP

#include <SFML/Graphics.hpp>

class Bullet
{
public:
    Bullet(float x, float y, sf::Color color);
    void update(float y);
    sf::CircleShape bullet_shape;
};

#endif // BULLET_HPP