#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>

class Player
{
public:
    Player();

    void move(float dx, float dy);
    void draw(sf::RenderWindow& window);

    sf::Vector2f getPosition();
    sf::CircleShape player;
};

#endif // PLAYER_HPP