#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include "Bullet.hpp"

class Player
{
public:
    Player();

    std::vector<Bullet> bullets;

    void movement();
    void shooting(sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);

private:
    sf::CircleShape player;
    sf::Clock shootClock;
};

#endif // PLAYER_HPP