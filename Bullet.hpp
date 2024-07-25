#ifndef BULLET_HPP
#define BULLET_HPP

#include <SFML/Graphics.hpp>

class Bullet
{
public:
    Bullet(float x, float y);
    void update();
    sf::CircleShape bullet_shape;
};

#endif // BULLET_HPP
