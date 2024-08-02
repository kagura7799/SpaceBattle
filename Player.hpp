#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include "Bullet.hpp"

class Player
{
public:
    Player();

    std::vector<Bullet> bullets;
    std::vector<Bullet>& getBullets();
    void movement();
    void shooting(sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);
    sf::FloatRect getBounds() const;
    sf::CircleShape playerShape;

private:
    sf::Clock shootClock;
};

#endif // PLAYER_HPP